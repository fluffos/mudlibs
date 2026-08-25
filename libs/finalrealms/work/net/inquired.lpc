/* inquired - Hamlet, June 1997
   This handles quick queries to remote machines.
   inquire() is currently the only thing that one would call.
   Possibly sustained connections could be done in here too,
   but that's too big of a project for the moment.

   note:  funky call_out() handling needs fixed when v22 drivers
          become universal.
*/

#include <socket.h>
#include <function.h>
#include <inquire_err.h>
#include "inquired.h"
 
/* Needed to support multiple simultaneous queries.  The fd of the
   connection is the key.  The values are of the form:
     ({ mixed port, mixed sendtext, mixed callback, int fast, int hangup,
        int timeout_h, string wordip, string numericip, int *timestats, 
        mixed returntext })
   Callback may be ({ int type, function pointer }) or 
   ({ int type, string func, mixed ob }), where ob may be an object pointer
   or a string.  Because of the possible need to resolve() the 
   host's address, we can pass that address, but not the port number,
   so we store it here. 

   timeout_h will be the handle returned by call_out() so we can
   remove the callout later when it needs removed.  Only relevant
   with v22 drivers and above.
*/
mapping fds;

/* The resolve() handle is the key, the value is the fd. */
mapping handles;

/* To hold some historical information. */
#ifdef HISTORICAL_STATS
mapping hist;
#endif

private varargs int make_socket(string wordaddr, string numaddr, 
                                int handle, int fd);
private int check_callback(int fd);
private int call_callback(int fd, int err);
string fd_owner(int fd, int len, int strip);

#ifdef ERROR_LOG
private void log_error(int fd, string str);
#endif

#ifdef HISTORICAL_STATS
private void store_stats(int fd, int err);
#endif

/* See inquired.doc for information on the arguments and returns. */
varargs int inquire(string host, mixed port, int socketmode, 
                    mixed sendtext, mixed func, mixed callto, 
                    int fast, int hangup, int timeout) {
  int fd, err, VALID, cbtype;
  string FNPO;

  /* Check to see if the object even has permission to use this fcn */
  FNPO = file_name(previous_object());
  for(err = 0; err < sizeof(SAFE_DIRS); err++)
     if(FNPO[0..strlen(SAFE_DIRS[err]) - 1] == SAFE_DIRS[err]) {
       VALID = 1;
       break;
     }

  if(!VALID)
    return BAD_CALLER;

  /* Check incoming data for basic validity */
  if( !host )                     return BAD_HOST;
  if( socketmode < 0 )            return BAD_SOCKETMODE;
  if( !func )                     return BAD_CALLBACK;

  if( functionp(func) ) {
    if( functionp(func) & FP_OWNER_DESTED )
      return BAD_CALLBACK;
    else
      cbtype = FUNC_PTR;

    if( !intp(callto) ) /* It's really 'fast' */
      return BAD_FASTVALUE;
    else {
      timeout = hangup;
      hangup = fast;
      fast = callto;
    }
  }
  else if( stringp(func) ) {
    if( !callto || intp(callto) )
      return BAD_CALLBACK;

    if( objectp(callto) )
      cbtype = OBJ_OB;
    else if(stringp(callto)) {
        if(catch(load_object(callto)))
          return BAD_CALLBACK;
        else
          cbtype = STR_OB;
    }
    else
      return BAD_CALLBACK;
  }
  else
    return BAD_CALLBACK;

  if(intp(port))
    err = port;
  else if(stringp(port))
    sscanf(port, "%d", err);
  else
    return BAD_PORT;

  if(err <= 0) /* Invalid port */
    return BAD_PORT;
  
  /* Okay, we have to create a socket now so that inquire() can
     return the fd.  The rest of the socket ops will happen in
     make_socket() either after resolve() has run (assuming
     'host' is alphabetic) or immediately.
   */
  err = socket_create(socketmode, "read_cb", "close_cb");
  if (err < 0) {
#ifdef ERROR_LOG
    log_error(0, "** Socket Create Error: " + socket_error(err)+".\n");
#endif
#ifdef HISTORICAL_STATS
    store_stats(0, FAILURE);
#endif
    return err;
  }
  fd = err;

  /* Store relevant data for later retrieval.  The last sub-array
     will only get more values added if EXTENSIVE_STATS is 
     defined, but we need the starttime for timeout processing.
  */
  if(cbtype == FUNC_PTR)
    fds[fd] = ({ port, sendtext, ({ cbtype, func }), fast, hangup, 0, 
                 "", "", ({ time(), 0, 0, 0, 0, 0 }) });
  else
    fds[fd] = ({ port, sendtext, ({ cbtype, func, callto }), fast, 
                 hangup, 0, "", "", ({ time(), 0, 0, 0, 0, 0 }) });

  /* Call make_socket() in one way or another */
  if( fast ) {
    err = make_socket("", host, 0, fd);
    if(err <= 0) {
#ifdef HISTORICAL_STATS
      store_stats(fd, err);
#endif
      map_delete(fds, fd);
      socket_close(fd);
      return err;
    }
  }
  else { /* fast == 0 */
    err = resolve(host, "make_socket");
    if(err <= 0) { /* The addr_server is probably down.  We can try
                      anyway if it's a numeric IP */
      string *bits;
      int i, junk;
      int FAIL;

      bits = explode(host, ".");
      for(i=0; i < sizeof(bits); i++)
        if(!sscanf(bits[i], "%d", junk)) {
          FAIL = 1;
          break;
        }

      if(FAIL) {
        socket_close(fd);
        map_delete(fds, fd);
        return BAD_RESOLVE;
      }
      else
        call_out("make_socket", 0, "", host, 0, fd);
    }
    else /* (err > 0) */
      handles[err] = fd;
  }
#ifdef v22
  fds[fd][TIMEOUT_H] = call_out("timed_out", 
                                (timeout ? timeout : TIMEOUT), fd);
#else
  if(!timeout)  timeout = TIMEOUT;
  fds[fd][TIMEOUT_H] = timeout;
  call_out("timed_out", timeout, fd);
#endif

  return fd;
} /* inquire() */

private varargs int make_socket(string wordaddr, string numaddr, 
                                int handle, int fd) {
  int err;

  if( !fd ) {
    fd = handles[handle];
    map_delete(handles, handle);
  }

  if( !fds[fd][FAST] && !check_callback(fd))
    return 0; /* callback is invalid, just give up. */

  if(!numaddr) {
    if(fds[fd][FAST])
      return BAD_ADDRESS;
    else
      return call_callback(fd, BAD_ADDRESS);
  }

  fds[fd][WORDIP] = wordaddr;
  fds[fd][NUMERICIP] = numaddr;

  err = socket_bind(fd, 0);
  if (err < 0) {
#ifdef ERROR_LOG
    log_error(fd, "** Socket Bind Error: "+socket_error(err)+".\n");
#endif
    if(fds[fd][FAST])
      return err;
    else
      return call_callback(fd, err);
  }
  err = socket_connect(fd, numaddr + " " + fds[fd][PORT], "read_cb", 
                       "write_cb");
  if (err < 0) {
#ifdef ERROR_LOG
    if( (wordaddr != query_host_name()) && (wordaddr != "localhost") )
      log_error(fd, "** Socket Connect Error: "+socket_error(err)+".\n");
#endif
    if(fds[fd][FAST])
      return err;
    else
      return call_callback(fd, err);
  }

#ifdef EXTENSIVE_STATS
  fds[fd][TIMESTATS][BOUND] = time();
#endif

  return 1;
} /* make_socket() */

private void write_cb(int fd) {
  int err;

  if(!check_callback(fd))  /* check_callback() handles removal of the fd */
    return;

  if(fds[fd][SENDTEXT]) {
    err = socket_write(fd, fds[fd][SENDTEXT] + "\r\n");
 
    if (err < 0) {
#ifdef ERROR_LOG
      log_error(fd, "** Socket Write Error: "+socket_error(err)+".\n");
#endif
      call_callback(fd, err);
    }
  }

  /* To decide between CONN_REFUSED and HOST_NOT_RESPOND */
  fds[fd][SENDTEXT] = -1;

#ifdef EXTENSIVE_STATS
  fds[fd][TIMESTATS][CONNECTED] = time();
#endif
} /* write_cb() */

private void read_cb(int fd, mixed mess) {
  if(!check_callback(fd))
    return;

  if(stringp(mess)) { /* Let's make it unix text, at least */
    mess = replace_string(mess,"\r\n","\n");
    mess = replace_string(mess,"\r","\n");
  }

  if( sizeof(fds[fd]) == ELTS_IN_FDS ) /* This is *more* data */
    fds[fd][RETURNTEXT] += mess;
  else { /* This is the first data */
    fds[fd] += ({ mess });
#ifdef EXTENSIVE_STATS
    fds[fd][TIMESTATS][FIRSTREAD] = time();
#endif
  }

#ifdef EXTENSIVE_STATS
  fds[fd][TIMESTATS][CURREAD] = time();
  fds[fd][TIMESTATS][NUMPACKET] ++;
#endif

  if( fds[fd][HANGUP] )
    call_callback(fd, SUCCESS);
} /* read_cb() */

private void close_cb(int fd) {
  if(!fds[fd])
    return;

  if(!check_callback(fd))
    return;

  if( sizeof(fds[fd]) == ELTS_IN_FDS )
    call_callback(fd, SUCCESS);
  else if(fds[fd][SENDTEXT] == -1)
    call_callback(fd, HOST_NOT_RESPOND);
  else
    call_callback(fd, CONN_REFUSED);
} /* close_cb() */

private void timed_out(int fd) {
  if(!fds[fd])
    return;

  if(!check_callback(fd))
    return;

#ifndef v22
  /* This may be a false call to timed_out()... */
  if( (time() - fds[fd][TIMESTATS][CREATED]) < (fds[fd][TIMEOUT_H] - 1) )
    return;
#endif

  if(sizeof(fds[fd]) == ELTS_IN_FDS)
    call_callback(fd, SUCCESS);
  else
    call_callback(fd, TIMED_OUT);
}

#ifdef ERROR_LOG
private void log_error(int fd, string str) {
  if(!fd || !check_callback(fd))
    log_file(ERROR_LOG, ctime(time()) + ": " + str);
  else
    log_file(ERROR_LOG, ctime(time()) + "  " + fd_owner(fd, 0, 0) + 
                        ": " + str);
} /* log_error() */
#endif

private int check_callback(int fd) {
  int invalid = 0;

  switch(fds[fd][CALLBACK][0]) { /* cbtype */
    case FUNC_PTR :  if(functionp(fds[fd][CALLBACK]) & FP_OWNER_DESTED)
                       invalid = 1;
                     break;
    case OBJ_OB   :  if(!fds[fd][CALLBACK][2])
                       invalid = 1;
                     break;
    case STR_OB   :  if(catch(load_object(fds[fd][CALLBACK][2])))
                       invalid = 1;
                     break;
  }

  if(invalid) {
#ifdef v22
    remove_call_out(fds[fd][TIMEOUT_H]);
#endif
#ifdef HISTORICAL_STATS
    store_stats(fd, BAD_CALLBACK);
#endif
    map_delete(fds, fd);
    socket_close(fd);
  }

  return !invalid;
} /* check_callback() */

private int call_callback(int fd, int err) {
  mixed msg;

  if(err <= 0)
    msg = inquire_error(err);
  else /* SUCCESS */
    msg = fds[fd][RETURNTEXT];

  if(fds[fd][CALLBACK][0] == FUNC_PTR) { /* function pointer */
    if(fds[fd][FAST])
      evaluate( fds[fd][CALLBACK][1], fd, err, msg );
    else
      evaluate( fds[fd][CALLBACK][1], fd, err, msg,
                fds[fd][WORDIP], fds[fd][NUMERICIP] );
  }
  else {
    if(fds[fd][FAST])
      call_other( fds[fd][CALLBACK][2], fds[fd][CALLBACK][1], fd, err,
                  msg );
    else
      call_other( fds[fd][CALLBACK][2], fds[fd][CALLBACK][1], fd, err,
                  msg, fds[fd][WORDIP], fds[fd][NUMERICIP] );
  }

#ifdef v22
  remove_call_out(fds[fd][TIMEOUT_H]);
#endif
#ifdef HISTORICAL_STATS
  store_stats(fd, err);
#endif
  map_delete(fds, fd);
  socket_close(fd);

  return err;
} /* call_callback() */

#ifdef HISTORICAL_STATS
private void store_stats(int fd, int err) {
  string caller;

  if(fd == 0)
    hist["GLOBALS:"][CREATED]++;  /* This is really ones NOT created */
  else {
    caller = fd_owner(fd,0,1);
    if(!hist[caller])
      hist[caller] = ({ 0, 0, 0, 0, 0, 0 });

    hist[caller][CALLS]++;
    if(err > 0)
      hist[caller][ANSWERS]++;
    else if(err == TIMED_OUT)
      hist[caller][TIMEOUTS]++;

#ifdef EXTENSIVE_STATS
    hist[caller][QTIME] += (time() - fds[fd][TIMESTATS][CREATED]);
    if(err > 0) {
      hist[caller][READTIME] += (time() - fds[fd][TIMESTATS][FIRSTREAD]);
      hist[caller][NUMPACKETS] += fds[fd][TIMESTATS][NUMPACKET];

      hist["GLOBALS:"][BOUND] += (fds[fd][TIMESTATS][BOUND] - 
                                  fds[fd][TIMESTATS][CREATED]);
      hist["GLOBALS:"][CONNECTED] += (fds[fd][TIMESTATS][CONNECTED] -
                                      fds[fd][TIMESTATS][BOUND]);
      hist["GLOBALS:"][FIRSTREAD] += (fds[fd][TIMESTATS][FIRSTREAD] -
                                      fds[fd][TIMESTATS][CONNECTED]);
    }
#endif
  } 
}
#endif

/* If (len > 0), characters will be stripped from the left until
   strlen() matches len.  If (strip), Any #2323 (clone number)
   will be removed before return.
*/
string fd_owner(int fd, int len, int strip) {
  string obname;

  switch(fds[fd][CALLBACK][0]) { /* cbtype */
    case FUNC_PTR :  
#ifdef v22
                     obname = file_name(
                                function_owner(fds[fd][CALLBACK][1]) );
#else
                     obname = sprintf("%O", fds[fd][CALLBACK][1]);
                     obname = replace_string(obname, "(: ", "");
                     obname = replace_string(obname, " :)", ""); 
#endif
                     break;
    case OBJ_OB   :  obname = file_name(fds[fd][CALLBACK][2]);
                     break;
    case STR_OB   :  obname = fds[fd][CALLBACK][2];
                     break;
  }

  if(strip) {
    obname = explode(obname,"#")[0];
    obname = explode(obname,"/")[<1];
  }

  if(len)
    obname = obname[<len..];

  return obname;
} /* fd_owner() */

private void create() {
  fds = ([ ]);
  handles = ([ ]);
#ifdef HISTORICAL_STATS
  hist = ([ "GLOBALS:" : ({ 0, 0, 0, 0 }) ]);
#endif
  seteuid("Network stuff");
}

mapping get_current_stats() {  return copy(fds);  }

#ifdef HISTORICAL_STATS
mapping get_historical_stats() {  return copy(hist);  }
#endif
