const dgram = require("dgram");
const udp_socket = dgram.createSocket("udp4");

udp_socket.on("message", function (msg, rinfo) {
	console.log(rinfo.address + ":" + rinfo.port + ":" + msg);
	process.exit();
});

strMsg = " Oh Bonhwan";
udp_socket.send(Buffer(strMsg), 0, strMsg.length, 3333, '192.168.100.152');