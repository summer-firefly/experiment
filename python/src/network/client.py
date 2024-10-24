#!/usr/bin/python3
import socket


class Client(object):
    def __init__(self, host, port):
        self.host = host
        self.port = port

    def run(self):
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.connect((self.host, self.port))
        while True:
            data = input("输入要给服务器发送的数据(输入exit退出) : ")
            if data == "exit":
                break
            sock.sendall(data.encode())
            data = sock.recv(1024)
            print(f"收到服务端回的消息: {data}")
        sock.close()


Client("localhost", 8000).run()
