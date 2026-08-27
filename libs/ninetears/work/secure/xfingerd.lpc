/* xfingerd -- Hamlet, Feb 1996 */
/* This one implements the standard (give or take) unix finger command.
   The part dealing with sockets, at least.  Some of the code is scavenged
   from Dyraen's identd (why recode the wheel?).
   It doesn't respond to the user directly because of the vague notion
     that somebody may want to integrate this into the playerob 
     (*weak smile*).... well, maybe I just didn't feel like changing it.
   If you improve this, I'd ask that you mail a copy to icharles@opup.org
*/

#include <socket.h>

#define ERROR_LOG "xfinger.errors"

#define END { call_out("dest_me",0); return 0; }
#define V_END { call_out("dest_me",0);  return; }

object tp;
string response;
string host, user;

void log_error(string str);

int do_xfinger(string data, object me) {
  int fd, err;
  string *junk;

  if (!data) END;
  if (!me) END;

  junk = explode(data,"@");
  
  if(!sizeof(junk)) END;
  if(sizeof(junk) == 1) {
    host = junk[0];
    user = "";
  }
  else if(sizeof(junk) == 2) {
    host = junk[1];
    user = junk[0];
  }
  else
    END;

  tp = me;

  err = socket_create(STREAM, "read_cb", "close_cb");
  if (err < 0) {
    log_error("** Socket Create Error: "+socket_error(err)+".\n");
    END;
  }
  fd = err;
  err = socket_bind(fd, 0);
  if (err < 0) {
    log_error("** Socket Bind Error: "+socket_error(err)+".\n");
    END;
  }
  err = socket_connect(fd, host+" 79", "read_cb", "write_cb");
  if (err < 0) {
    log_error("** Socket Connect Error: "+socket_error(err)+".\n");
    END;
  }
  
  response = "";
  call_out("dest_me",40);
  return 1;
} /* do_ident() */

void read_cb(int fd, string mess) {
  mess = replace_string(mess,"\r","");
  
  response += mess;
} /* read_cb() */

void write_cb(int fd) {
  int err;

  if (!tp) {
    socket_close(fd);
    V_END;
  }

  err = socket_write(fd, sprintf("%s\r\n",user));
  if (err <0) {
    log_error("** Socket Write Error: "+socket_error(err)+".\n");
    V_END;
  }
} /* write_cb() */

void close_cb(int fd) {
  if (tp) {
    if(strlen(response))
      tp->receive_xfinger_data(response);
    else
      tp->receive_xfinger_data("No data.\n");
    V_END;
  }
} /* close_cb() */

void dest_me() {
  if (clonep(this_object())) {
    remove_call_out("dest_me");
    destruct(this_object());
  }
} /* dest_me() */

void log_error(string str) {
  log_file(ERROR_LOG,"** "+ctime(time())+" "+user+"@"+host+": "+str);
}
