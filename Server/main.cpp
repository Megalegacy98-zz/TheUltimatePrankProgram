#include <iostream>
#include <exception>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;
using namespace std;

int main(int argc, char **argv) {
	try {
		boost::asio::io_service io;
		
		tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 9999));
		tcp::socket sock(io);
		acceptor.accept(sock);
		
		cout << "Connected!" << endl;
		
		string Q = "";
		
		while(true){
			
			getline(cin, Q);
			
			boost::system::error_code ignore;
			boost::asio::write(sock, boost::asio::buffer(Q), ignore);
			
			if(Q == "exit"){
				break;
			}
		}
		
	} catch(exception &e){
		cout << e.what() << endl;
	}
	
	return 0;
}
