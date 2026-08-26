// TCP base client with multiple socket support; Galileo, 11-30-98

#include <network.h>

#define OPEN        1
#define BLOCKED     2

class socket {
  int desc;     // Identification for the socket
  int mode;     // Mode the port was opened for 
  int state;    // Port state, OPEN/BLOCKED
  mixed *buff;  // Pending port data
} /* class client */

class server {
  int desc;                // Identification for the server
  class socket accept;     // Accepting socket
  class socket *sockets;   // Connected sockets  
} /* class server */


int close_sockets();
int close_socket(int);

private nosave class socket *sockets;

protected void mudlib_setup() {
  sockets = ({ });
} /* mudlib_setup() */

protected void dest_me() {
  close_sockets();
} /* dest_me() */

int valid_index(mixed *array, int index) {
  
  if ((index < 0) || (index >= sizeof(array)))
    return 0;

  return 1;
} /* valid_index() */

int socket_index(int fd) {
  
  for (int i = 0; i < sizeof(sockets); i++)
    if (sockets[i] -> desc == fd)
      return i;

  return -1;
} /* socket_index() */

class socket *query_sockets() { return sockets; }

class socket query_socket(int index) {

  if (!valid_index(sockets, index))
    return 0;

  return sockets[index];
} /* query_socket() */

int query_state(int index) {

  if (!valid_index(sockets, index))
    return 0;

  return sockets[index] -> mode;
} /* query_state() */

protected int set_state(int index, int mode) {

  if (!valid_index(sockets, index))
    return 0;

  return (sockets[index] -> mode = mode);
} /* set_state() */

mixed *query_buffer(int index) {

  if (!valid_index(sockets, index))
    return 0;

  return sockets[index] -> buff;
} /* query_buffer() */

protected int set_buffer(int index, mixed *buff) {

  if (!valid_index(sockets, index))
    return 0;

  sockets[index] -> buff = buff;
  return 1;
} /* set_buffer() */

protected int add_buffer(int index, mixed elem) {

  if (!valid_index(sockets, index))
    return 0;

  sockets[index] -> buff += ({ elem });
  return 1;
} /* add_buffer() */

protected int remove_buffer(int index, int elem) {

  if (!valid_index(sockets, index))
    return 0;

  if (!valid_index(sockets[index] -> buff, elem))
    return 0;

  sockets[index] -> buff = delete(sockets[index] -> buff, elem, 1);
  return 1;
} /* remove_buffer() */

protected int send_buffer(int index) {

  if (!valid_index(sockets, index))
    return 0;  

  TO -> client_write_callback(sockets[index] -> desc);
  return 1;
} /* send_buffer() */   

protected int open_socket(string host, int port, int mode) {
  class socket sock = new(class socket);
  int err;

  if ((err = socket_create(mode, "client_read_callback", 
                           "client_close_callback")) < 0)
    error("Error creating socket.\n");

  sock -> desc = err;
 
  if ((err = socket_bind(sock -> desc, 0)) != EESUCCESS) {
    socket_close(sock -> desc);
    error("Error binding socket.\n");
  }

  if ((err = socket_connect(sock -> desc, host + " " + port,
      "client_read_callback", "client_write_callback")) != EESUCCESS) {
    socket_close(sock -> desc);
    error("Error connecting socket.\n");
  }

  sock -> mode = mode;
  sock -> state = OPEN;
  sock -> buff = ({ });
  sockets += ({ sock });
  return (sizeof(sockets) - 1);
} /* open_socket() */

protected int close_sockets() {

  while (sizeof(sockets))
    if (!close_socket(0));
      return 0;

  return 1;
} /* reset_sockets() */

protected int close_socket(int index) {

  if (!valid_index(sockets, index))
    return 0;

  if (socket_close(sockets[index] -> desc) != EESUCCESS)
    return 0;

  sockets = delete(sockets, index, 1);
  return 1;
} /* close_socket() */

protected void client_close_callback(int fd) {
  socket_close(fd);
  sockets = delete(sockets, socket_index(fd), 1);
  return;
} /* close_callback() */

protected void client_read_callback(int /* fd */, mixed /* val */) {
  return;
} /* read_callback() */

protected void client_write_callback(int fd) {
  int index, err = EESUCCESS;

  if (!sizeof(sockets))
    return;

  for (index = 0; index < sizeof(sockets); index++)
    if ((sockets[index] -> desc) == fd)
      break;

  if (!sizeof(sockets[index] -> buff))
    return;

  switch (err = socket_write(sockets[index] -> desc, 
                             sockets[index] -> buff[0])) {
    case EESUCCESS:
      sockets[index] -> buff = delete(sockets[index] -> buff, 0, 1);
      sockets[index] -> state = OPEN;
      break;
    case EECALLBACK:
    case EEALREADY:
      sockets[index] -> state = BLOCKED;
      return;
    case EEWOULDBLOCK:
      sockets[index] -> state = BLOCKED;
      call_out((: client_write_callback($(fd)) :), 1);
      return;
    default:
      error("Error writing to socket.\n");
      return;
  }

  if (sizeof(sockets[index] -> buff))
    call_out((: client_write_callback($(fd)) :), 1);

  return;
} /* write_callback() */
