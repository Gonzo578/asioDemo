#include <iostream>
#include <string>
#include <asio.hpp>

#define MAXLEN 512 // maximum buffer size

int main() {

	asio::io_service io;

	try {
		// create a serial port object
		asio::serial_port serial(io);

		serial.open("/dev/ttyUSB0");

		for (;;) {
			// get a string from the user, sentiel is exit
			std::string input;
			std::cout << "Enter Message: ";
			std::cin >> input;

			if (input == "exit") break;

			// write to the port
			// asio::write guarantees that the entire buffer is written to the serial port
			asio::write(serial, asio::buffer(input));

			char data[MAXLEN];

			// read bytes from the serial port
			// asio::read will read bytes until the buffer is filled
			size_t nread = asio::read(serial, asio::buffer(data, input.length()));

			std::string message(data, nread);

			std::cout << "Recieved: ";
			std::cout << message << std::endl;
		}
		
		serial.close();
	}
	catch (asio::system_error& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
