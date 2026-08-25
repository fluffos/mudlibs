

#include <socket.h>
#include <socket_errors.h>

string *received, *to_send;
int cs, rs, reset, local_port, remote_port;
 
void do_cre_socket();
void do_remote_socket();
string *query_to_send() { return to_send; }
string *query_received() { return received; }

void do_sockets() {
             
  received = ({ });
  to_send = ({ });
 
  if (mud_name() == "FR") {
    local_port = 3010;
    remote_port = 4010;
  } else {
    local_port = 4010;
    remote_port = 3010;
  }
  log_file("CONNECT","--- "+ctime(time())+" ---\n");
  do_cre_socket();
  do_remote_socket();
} /* do_sockets() */
 
void do_cre_socket() {
int error;
 
  cs = socket_create(DATAGRAM, "read_callback");
  if (cs < 0) {
    log_file("CONNECT","**socket_create: " + socket_error(cs) + "\n");
    return;
  }
  log_file("CONNECT","Created Socket " + cs + "\n");
  error = socket_bind(cs, local_port);
  if (error != EESUCCESS) {
    log_file("CONNECT","**socket_bind: " + socket_error(error) + "\n");
    socket_close(cs);
    return;
  }
} /* do_cre_socket() */
 
void do_remote_socket() {
int error;
 
  rs = socket_create(DATAGRAM, "read_callback");
  if (rs < 0) {
    log_file("CONNECT","**socket_create: " + socket_error(rs) + "\n");
    return;
  }
  log_file("CONNECT","Created Socket " + rs + "\n");
  error = socket_bind(rs, 0);
  if (error != EESUCCESS) {
    log_file("CONNECT","**socket_bind: " + socket_error(error) + "\n");
    socket_close(rs);
    return;
  }
} /* do_remote_socket() */

void read_callback(int fd, string data) {
  received += ({ data });
   this_object()->received_cre();
} /* read_callback() */
 
void transmit() {
int error, i;
 
  if (sizeof(to_send))
    while (sizeof(to_send)) {
      error = socket_write(rs, to_send[i], "127.0.0.1 "+remote_port);
      to_send = delete(to_send,0,1);
      if (error == EEBADF) {  /* its disappeared! lets get it back.. */
        socket_close(rs);
        do_remote_socket();
      }
      if (error < 0) {
        log_file("CONNECT","**socket_write: " + socket_error(error) + "\n");
        return;
      }
    }
} /* transmit() */
 
void add_send_mess(string mess) {
   if(!to_send) to_send = ({ });
  to_send += ({ mess });
} /* add_send_mess() */

void received_cre() { }



