import socket
s=socket.socket()
s.bind(('0.0.0.0',7000))
s.listen(5)
cs,address = s.accept()
print 'got connected from',address
cs.send('byebye')
ra=cs.recv(512)
print ra
cs.close()
