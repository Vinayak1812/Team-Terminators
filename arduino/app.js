const {SerialPort, ByteLengthParser} = require('serialport');
// const Readline = SerialPort.parsers.Readline;
const port = new SerialPort({path:'com15', baudRate: 9600 });
const parser = port.pipe(new ByteLengthParser({ length:8 }));
const utf8 = require('utf8')
// Read the port data
port.on("open", function () {
  console.log("open");
  port.on("data", function(data) {
    console.log("data received: " + data);
  });  
  port.push('H');  
})

parser.on('data', data =>{
  console.log('got word from arduino:', data);
});


// // serial port initialization:
// var {SerialPort} = require('serialport'); // include the serialport library
// var portName = process.argv[2]; // get the port name from the command line
// var myPort = new SerialPort({path:'com15', baudRate: 9600 });// open the port
 
// // these are the definitions for the serial events:
// myPort.on('open', openPort); // called when the serial port opens
 
// function openPort() {
//   var brightness = 0; // the brightness to send for the LED
// //   console.log('port open');
// //   console.log('baud rate: ' + myPort.options.baudRate);
 
//   // since you only send data when the port is open, this function
//   // is local to the openPort() function:
//   function sendData() {
//     // convert the value to an ASCII string before sending it:
//     myPort.write(brightness.toString());
//     console.log('Sending ' + brightness + ' out the serial port');
//     // increment brightness by 10 points. Rollover if < 255:
//     if (brightness < 255) {
//       brightness+= 10;
//     } else {
//       brightness = 0;
//   }
// }
 
// // set an interval to update the brightness 2 times per second:
// setInterval(sendData, 500);
// }