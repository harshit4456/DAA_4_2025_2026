const express = require("express");
const { exec } = require("child_process");

const app = express();
app.use(express.json());
app.use(express.static("public"));

// Add Task
app.post("/add", (req, res) => {
    const { id, name, priority, deadline } = req.body;

    exec(`scheduler add ${id} ${name} ${priority} ${deadline}`, (err, stdout) => {
        res.send(stdout);
    });
});

// Execute Task
app.get("/execute", (req, res) => {
    exec(`scheduler execute`, (err, stdout) => {
        res.send(stdout);
    });
});

// View Tasks
app.get("/view", (req, res) => {
    exec(`scheduler view`, (err, stdout) => {
        res.send(stdout);
    });
});

app.listen(3000, () => console.log("Server running on port 3000"));