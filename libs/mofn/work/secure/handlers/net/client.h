#ifndef __CLIENT_H__
#define __CLIENT_H__

// from dw-wibble-r8.88

class client {
    int descriptor;
    int blocking;
    mixed *bufferp;
    int closed;
}
 
int event_create_socket(string host, int port);
protected void event_abort_callback(int fd);
protected void event_read_callback(int fd, mixed val);
protected void event_read(int fd, mixed val);
protected void event_write_callback(int fd);
void event_write(int fd, mixed val);
protected void event_close(class client sock);
protected void event_socket_close(int fd);
int event_destruct();
protected void event_socket_error(string str, int x);
function set_read(function f);
int set_socket_type(int x);
int set_destruct_on_close(int x);

#endif /* __CLIENT_H__ */

