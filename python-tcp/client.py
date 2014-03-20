import socket
s=socket.socket()
s.connect(('166.111.138.107',7000))
data=s.recv(512)
s.send('hihi')
s.close()
print 'the data received is',data
