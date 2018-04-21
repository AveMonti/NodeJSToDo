const express = require('express');
const app = express();
const morgan = require('morgan');
const bodyParser = require('body-parser');


const tasksRoutes = require('./api/routes/tasks');
const mongoose = require('mongoose');


mongoose.connect(
    "mongodb://localhost:27021",
    {
        useMongoClient: true
    }
);

app.use(morgan('dev'));
app.use(bodyParser.urlencoded({extended: false}));
app.use(bodyParser.json());

app.use((req,res,next) => {
    res.header('Access-Control-Allow-Origin','*');
res.header('Access-Control-Allow-Headers',
    'Origin, X-Requested-With, Content-type,Accept');
if (req.method === 'OPTIONS'){
    req.header('Access-Control-Allow-Methods',
        'PUT,POST,PATCH,DELETE,GET');
    return res.status(200).json({});
}
next();
});

app.use('/tasks', tasksRoutes);

app.use((req,res,next) => {
    const error = new Error('Not Found');
error.status = 404;
next(error);
});

app.use((error, req, res, next) => {
    res.status(error.status || 500);
res.json({
    message : error.message
});
});

module.exports = app;
