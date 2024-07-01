const express = require("express");

const app = express();

app.use((req, res, next) => {
    res.setHeader("Access-Control-Allow-Origin", "*"); // DANGER DANGER! GET HACKED BITCH
    res.setHeader("Access-Control-Allow-Methods", "GET, POST");
    res.setHeader("Access-Control-Allow-Headers", "Content-Type");
    res.setHeader("Access-Control-Allow-Credentials", "true");
    next();
});

app.use(express.urlencoded());

const port = 4000;
let currentString =
    '{"playerlist":{"PlayerNumber0":{"x":"0","y":"0","yaw":"0","pitch":"0","teamID":"0"}}}';

app.listen(port, () => {
    console.log(`Example app listening on port ${port}`);
});

app.get("/get", (req, res) => {
    res.send(currentString);
});

let TotalPostRequestCount = 0;

app.post("/set", (req, res) => {
    res.send("Received")
    TotalPostRequestCount += 1
    console.log(`${TotalPostRequestCount}`)
   currentString =  Object.entries(req.body)[0][0]
})
