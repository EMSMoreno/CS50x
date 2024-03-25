/* I'm importing the express web framework and the path module
for working with the file and the directory paths in node.js */
const express = require("express");
const path = require("path");

/*Create a path to the public directory in the same directory where the
script is being executed */
let initial_path = path.join(__dirname, "public");

/*Create an instance and use the express.static to serve static
files from the public*/
let app = express();
app.use(express.static(initial_path));

/*Defining routes, first one to the GET requests at the root by
sending the index.html file and the second one to the GET request as well, 
but only this time is with an id parameter by senind the about.html file */
app.get("/", (req, res) => {
  res.sendFile(path.join(initial_path, "index.html"));
});

app.get("/:id", (req, res) => {
  res.sendFile(path.join(initial_path, "about.html"));
});

/*Create a response route incase the handbling doesnt find the 
page you are looking for */
app.use((req, res) => {
  res.json("404 Not Found");
});

/*Create a function to start the server and to be configurated on port 3000
A message is logged to the consoler when the server is started*/
app.listen(3000, () => {
  console.log("listening on port 3000......");
});
