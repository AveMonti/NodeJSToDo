//
// Created by Mateusz Chojnacki on 22.04.2018.
//

#include "../includes/TaskReq.h"

namespace
{
    std::size_t callback(
            const char* in,
            std::size_t size,
            std::size_t num,
            std::string* out)
    {
        const std::size_t totalBytes(size * num);
        out->append(in, totalBytes);
        return totalBytes;
    }
}


TaskReq::TaskReq() {
    curl = curl_easy_init();
}

Task TaskReq::getTask(std::string key) {
    Task *newTask;
    std::string askUrl = staticUrl + key;
    if(curl) {
        // Set remote URL.
        curl_easy_setopt(curl, CURLOPT_URL, askUrl.c_str());

        // Don't bother trying IPv6, which would increase DNS resolution time.
        curl_easy_setopt(curl, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);

        // Don't wait forever, time out after 10 seconds.
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

        // Follow HTTP redirects if necessary.
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        // Response information.
        int httpCode(0);
        std::unique_ptr<std::string> httpData(new std::string());

        // Hook up data handling function.
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);

        // Hook up data container (will be passed as the last parameter to the
        // callback handling function).  Can be any pointer type, since it will
        // internally be passed as a void pointer.
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());

        // Run our HTTP GET command, capture the HTTP response code, and clean up.
        curl_easy_perform(curl);
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
        curl_easy_cleanup(curl);

        if (httpCode == 200) {
            std::cout << "\nGot successful response from: " << staticUrl;
            std::cout << "\nGot successful json: " << *httpData.get() <<std::endl;
            rapidjson::Document document;
            auto json = httpData.get()->c_str();
            document.Parse(json);


            assert(document.HasMember("_id"));
            assert(document["_id"].IsString());
            assert(document.HasMember("name"));
            assert(document["name"].IsString());
            assert(document.HasMember("isDone"));
            assert(document["isDone"].IsInt());

            *newTask = Task(document["_id"].GetString(),
                           document["name"].GetString(),
                           document["isDone"].GetInt());



        }else{
            std::cout << "\nNo conection with " << staticUrl << std::endl;
        }
    }
    return *newTask;
}

Tasks TaskReq::getTasks() {
    Tasks newTasks = Tasks();

    if(curl) {
        // Set remote URL.
        curl_easy_setopt(curl, CURLOPT_URL, staticUrl);

        // Don't bother trying IPv6, which would increase DNS resolution time.
        curl_easy_setopt(curl, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);

        // Don't wait forever, time out after 10 seconds.
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

        // Follow HTTP redirects if necessary.
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        // Response information.
        int httpCode(0);
        std::unique_ptr<std::string> httpData(new std::string());

        // Hook up data handling function.
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);

        // Hook up data container (will be passed as the last parameter to the
        // callback handling function).  Can be any pointer type, since it will
        // internally be passed as a void pointer.
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());

        // Run our HTTP GET command, capture the HTTP response code, and clean up.
        curl_easy_perform(curl);
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
        curl_easy_cleanup(curl);

        if (httpCode == 200) {
            std::cout << "\nGot successful response from: " << staticUrl;
            std::cout << "\nGot successful json: " << *httpData.get() <<std::endl;
            rapidjson::Document document;
            auto json = httpData.get()->c_str();
            document.Parse(json);


            for(auto& valueIt : document.GetArray()){
                assert(valueIt.HasMember("_id"));
                assert(valueIt["_id"].IsString());
                assert(valueIt.HasMember("name"));
                assert(valueIt["name"].IsString());
                assert(valueIt.HasMember("isDone"));
                assert(valueIt["isDone"].IsInt());

                Task newTask = Task(valueIt["_id"].GetString(),
                                    valueIt["name"].GetString(),
                                    valueIt["isDone"].GetInt());

                newTasks.addTask(newTask);
            }

        }else{
            std::cout << "\nNo conection with " << staticUrl << std::endl;
        }
    }

    return newTasks;
}