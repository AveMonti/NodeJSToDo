const mongoose = require('mongoose');

const taskSchema = mongoose.Schema({
   _id: mongoose.Schema.Types.ObjectId,
   name : String,
   isDone: Number
});

module.exports = mongoose.model('Task',taskSchema);