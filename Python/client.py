#简单客户端

import socket 

s = socket.socket()

host = socket.gethostname()

host = '192.168.0.103'
port = 1234

s.connect((host,port))
print s.recv(1024)
