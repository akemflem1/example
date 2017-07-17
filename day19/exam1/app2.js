const http = require("http");

const server = http.createServer(function (req, res) {

	res.statusCode = 200;
	res.setHeader("Content-Type", "text/plain");
	res.end("Hello nodejs");

});

server.listen(10080, '127.0.0.1', function () {
	console.log("server running....")

});