//
// Created by Mateusz Chojnacki on 22.04.2018.
//

#include "../includes/TaskReq.h"

TaskReq::TaskReq() {
    curl = curl_easy_init();
}

void TaskReq::getTasks() {

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, staticUrl);
        /* example.com is redirected, so we tell libcurl to follow redirection */
        std::cout<<"Tutaj :"<<(res)<<std::endl;
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);
        /* Check for errors */
        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        /* always cleanup */
        curl_easy_cleanup(curl);
    }
}