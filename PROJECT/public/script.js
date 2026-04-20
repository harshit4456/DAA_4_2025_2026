async function addTask() {
    const id = document.getElementById("id").value;
    const name = document.getElementById("name").value;
    const priority = document.getElementById("priority").value;
    const deadline = document.getElementById("deadline").value;

    const res = await fetch("/add", {
        method: "POST",
        headers: {"Content-Type": "application/json"},
        body: JSON.stringify({ id, name, priority, deadline })
    });

    document.getElementById("output").innerText = await res.text();
}

async function executeTask() {
    const res = await fetch("/execute");
    const text = await res.text();

    document.getElementById("output").innerText = "Executed: " + text;
}

async function viewTasks() {
    const res = await fetch("/view");
    const text = await res.text();

    document.getElementById("output").innerText = text;
}