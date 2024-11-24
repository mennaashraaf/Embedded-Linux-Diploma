all: tcp_server tcp_client udp_server udp_client

tcp_server: src/main_tcp_server.cpp src/ServerChannel.cpp src/TCPSocket.cpp
	g++ ./src/main_tcp_server.cpp src/ServerChannel.cpp src/TCPSocket.cpp -o build/tcp_server

tcp_client: src/main_tcp_client.cpp src/ClientChannel.cpp src/TCPSocket.cpp
	g++ ./src/main_tcp_client.cpp src/ClientChannel.cpp src/TCPSocket.cpp -o build/tcp_client

udp_server: src/main_udp_server.cpp src/ServerChannel.cpp src/UDPSocket.cpp src/TCPSocket.cpp
	g++ src/main_udp_server.cpp src/ServerChannel.cpp src/UDPSocket.cpp src/TCPSocket.cpp -o build/udp_server

udp_client: src/main_udp_client.cpp src/ClientChannel.cpp src/UDPSocket.cpp
	g++ src/main_udp_client.cpp src/ClientChannel.cpp src/UDPSocket.cpp -o build/udp_client

clean:
	rm -f build/tcp_server build/tcp_client build/udp_server build/udp_client
