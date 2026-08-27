/* Hamlet, Feb 1996.  -- This gets called to do the xfinger command.
   Hamlet, Jun 1997.  -- reworked to use inquired.  Doesn't need cloned
                         any more.  Simplified, cleaned the code, etc.
*/

#include <inquire_err.h>
#include <socket.h>

mapping fds;

varargs void xfinger_cb(int fd, int success, mixed response, 
                        string wordip, string numericip);

void do_xfinger(string hostip, string userid, object me, string pname, 
                string hostname, int wide) {
  int ret, fast;
  string msg;

  if(catch(load_object(INQUIRED))) {
    tell_object(me, "Inquired seems to be broken.  Have someone fix it.\n");
    return;
  }  

  if(!userid)  userid = "";
  if(!strlen(pname))  pname = 0;
  
  if(wide)
    msg = "/W "+ userid;
  else
    msg = userid;

  if(hostname)
    fast = 1;
 
  ret = INQUIRED->inquire(hostip, 79, STREAM, msg, (: xfinger_cb :), fast);

  if(ret <= 0)
    tell_object(me, "xfinger:  "+ inquire_error(ret) + "\n");
  else {
    tell_object(me, "Please wait...\n");
    fds[ret] = ({ me, userid, pname, hostip, hostname });
  }
}

varargs void xfinger_cb(int fd, int success, mixed response, 
                        string wordip, string numericip) {
  string header = "\n[";

  if(!fds[fd])
    return;

  if( !strlen(wordip) )
    wordip = fds[fd][4];

  if( !strlen(numericip) )
    numericip = fds[fd][3];

  if(fds[fd][2]) /* pname */
    header += capitalize(fds[fd][2]) + " -- ";

  if(strlen(fds[fd][1])) /* userid */
    header += fds[fd][1] + "@";

  if(wordip && (wordip != numericip))
    header += wordip + " (" + numericip + ")";
  else
    header += numericip;

  header += "]\n";

  if(success <= 0)
    tell_object(fds[fd][0], header + "xfinger: " + response + "\n"); 
  else
    tell_object(fds[fd][0], header + response + "\n");
                   
  map_delete(fds, fd);
}         

private void create() {
  seteuid("Network stuff");
  fds = ([ ]);
}
