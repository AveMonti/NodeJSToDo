const express = require('express');
const router = express.Router();
const mongoose = require('mongoose');
const Task = require('../models/task');

router.get('/', (req,res,next) => {
    Task.find()
    .exec()
    .then(docs => {
    console.log(docs);
res.status(200).json(docs);
})
.catch(err =>{
    console.log(err);
    res.status(500).json({error: err});
    });
});

router.post('/',(req,res,next) => {
    const task = new Task({
        _id: new mongoose.Types.ObjectId(),
        name: req.body.name,
        isDone: req.body.isDone
    });
    task
        .save()
        .then(result => {
            console.log(result);
            res.status(201).json({
               message: "Handling Post requests to /tasks",
               createdTask: result
            });
        })
        .catch(err =>{
            console.log(err);
            res.status(500).json({
                error: err
            });
    });
});

router.get('/:taskID',(req,res,next) =>{
    const id = req.params.taskID;
    Task.findById(id)
        .exec()
        .then(doc => {
            console.log("From database", doc);
            if(doc){
                res.status(200).json(doc);
            }else{
                res.status(400).json({message: "No valid entry found"});
            }
        })
        .catch(err => {
            console.log(err);
            res.status(500).json({error: err});
        });
});

router.patch('/:taskID',(req,res,next) =>{
    const id = req.params.taskID;
    const updateOps = {};
    for (const ops of req.body){
     updateOps[ops.propName] = ops.value;
    }
    Task.update({_id:id},{$set : updateOps})
        .exec()
        .then(resoult =>{
            console.log(resoult);
            res.status(200).json(resoult);
        })
        .catch(err =>{
            console.log(err);
            res.status(500).json({error: err});
        });
});

router.delete('/:taskID',(req,res,next) => {
    const id = req.params.taskID;
    Task.remove({_id: id})
        .exec()
        .then(resoult => {
            res.status(200).json(resoult);
        })
        .catch(err =>{
            console.log(err);
            res.status(500).json(err);
        });
});

module.exports = router;