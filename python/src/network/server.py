#!/usr/bin/python3
import socket
import threading


# python简单多线程echo服务器
class ThreadedServer(object):
    def __init__(self, host, port):
        self.host = host
        self.port = port

    def run(self):
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.bind((self.host, self.port))
        sock.listen(20)
        print(f"服务端启动成功，监听端口{self.port}")
        while True:
            client, address = sock.accept()
            print(f"客户端{address}已连接")
            client_handler = threading.Thread(
                target=self.handle_client, args=(client, address)
            )
            client_handler.start()

    def handle_client(self, client_socket, client_address):
        while True:
            data = client_socket.recv(1024)
            print(f"接收到客户端的数据: {data}")
            if not data:
                break
            print("将数据原封不动发送回客户端")
            client_socket.sendall(data)
        print(f"客户端{client_address}已断开连接")


server = ThreadedServer("localhost", 8000)
server.run()
