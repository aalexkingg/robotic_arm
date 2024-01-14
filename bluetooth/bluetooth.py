from ignore import BT_ADDR
import socket

port = 3

s = socket.socket(
    socket.AF_BLUETOOTH,
    socket.SOCK_STREAM,
    socket.BTPROTO_RFCOMM,
)
s.connect((BT_ADDR, port))

try:
    while True:
        text = "testing"
        s.send(bytes(text, 'UTF-8'))
except KeyboardInterrupt:
    s.close()


