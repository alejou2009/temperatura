const express = require("express");
const app = express();
const cors = require("cors");
app.use(cors());

const bodyParser = require('body-parser');
app.use(bodyParser.json()); // support json encoded bodies
app.use(bodyParser.urlencoded({ extended: true })); // support encoded bodies
const temperaturas = {temperatura:0};

app.get("/",(req,res)=>{
    res.send(temperaturas).status(200);
});

app.post("/",(req,res)=>{
    console.log(req.body);  
    temperaturas.temperatura = (req.body.temperatura);
    res.status(200).send();
});

app.listen(3000,()=>{console.log("servidor en puerto 3000")});
