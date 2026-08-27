/* identd - Hamlet
   Completely reworked Jun 1997.  Log of modifications purged.
   Notes:  VAXen as well as unix machines should answer properly.
           Error logging hopefully intelligent.  Ignores known
           errors.  Allows multiple simultaneous queries without
           cloning.  Logs interesting (unknown) responses to
           ERROR_LOG.  Hopefully is fully forgiving about the
           format a host replies with.  Now uses inquired for
           actual socket crap.  It calls receive_ident_data()
           in the querier to respond. 
*/

#include <socket.h>
#include <socket_errors.h>
#include <inquire_err.h>

#define LORD_ONLY
#define IDENT_CMD "/net/ident_cmd"
#define ERROR_LOG "ident.errors"

#define TRY_AGAIN       5   /* Try again in random(TRY_AGAIN) + 1 */
#define MAX_TRIES       5
#define IGN_LOCAL_ERR   1   /* Socket errors on localhost ignored? */

/* Errors specific to identd.  */
#define SECURITY_FAIL    -301
#define BROKEN_INQUIRED  -302
#define LOST_SUBJECT     -303

/* Aliases for the fds mapping */
#define OB      0
#define CALLER  1

mapping fds;
int arbitrary_fd;

/* for logging of retries on socket failure */
int retried;
int failed;

private void ident_cb(int fd, int success, mixed response);
private void tell_querier(int fd, string userid, string hosttype);
private void log_msg(int fd, string begin, string msg);

varargs int do_ident(object ob, object querier, int tries) {
  int fd;
  string stxt;
  string *sockaddr;

  if (!querier)
    return 0;

  if (!ob) {
    if(!tries)
      return LOST_SUBJECT;
    else { /* We kept trying.  Querier needs informed. */
      fds[arbitrary_fd] = ({ ob, querier });
      ident_cb(arbitrary_fd, LOST_SUBJECT, "The target player left "
                                           "the mud.");
      arbitrary_fd++;
      return 0;
    }
  }

#ifdef LORD_ONLY
  if( (querier != ob) && !"/secure/master"->query_lord(geteuid(querier)) &&
      (file_name(querier)[0..strlen(IDENT_CMD)-1] != IDENT_CMD) ) 
    return SECURITY_FAIL;
#endif

  if(catch(load_object(INQUIRED)))
    return BROKEN_INQUIRED;

  sockaddr = explode(socket_address(ob), " ");

  stxt = sockaddr[1] + "," + query_ip_port(ob);

  fd = INQUIRED->inquire(sockaddr[0], 113, STREAM, stxt, 
                         (: ident_cb :), 1, 1);

  if(fd < -100)  /* Broken code.  just return 0 */
    return fd;

  if(fd < 0) { /* It's a socket failure.  Try again in a few shakes. */
    int GIVE_UP;
    if((++tries) == MAX_TRIES) {
      failed++;  /* for logging. */
      GIVE_UP = 1;
    }
#ifdef IGN_LOCAL_ERR
    else if( (query_ip_name(ob) == query_host_name()) || 
             (query_ip_name(ob) == "localhost") )
           GIVE_UP = 1;
#endif
    if(GIVE_UP) {
      fds[arbitrary_fd] = ({ ob, querier });
      ident_cb(arbitrary_fd, fd, socket_error(fd));
      arbitrary_fd++;
      return fd;
    }

    if(tries == 1)
      retried++;  /* for logging */
    call_out("do_ident", random(TRY_AGAIN) + 1 , ob, querier, tries);
    return fd;
  }

  /* Store stuff for later use */
  fds[fd] = ({ ob, querier });

  return fd;
} /* do_ident() */

private void ident_cb(int fd, int success, mixed response) {
  string userid, hosttype;
  string junk, junk2;
  string *in_mess;

  if(!fds[fd])
    return;

  if(!fds[fd][OB]) {
    tell_querier(fd, "!error!", "The target player left the mud.");
    return;
  }

  if(success <= 0) {
    tell_querier(fd, "!error!", response);
    return;
  }

  if( !strlen(response) || 
      !strlen(response = replace_string(response, "\n", "")) ) {
    tell_querier(fd, "!error!", "The host did not respond.");
    return;
  }

  /* Unfortunately, each machine seems to respond in its own way
     to an auth/ident request.  Known formats are:
       1234 , 5678 : USERID : unix : potato 
       1234, 5678: unix: potato
       1234 , 5678 : USERID : unix :potato
       1234,5678:USERID:vax:potato

     And various error formats of the general form:
       1234 , 5678 : ERROR : NO-USER
       1234 , 5678 : ERROR : UNKNOWN-ERROR

     And then there are authd's that are obviously misinstalled:
       IPAD blah [blah]
       Sorry, there are already 10 users on.

     We'll obviously have to cook our incoming data some.
  */

  in_mess = explode(response, ":");

  /* Avoid logging uninteresting errors. */
  if(sizeof(in_mess) < 4) {
    if((sizeof(in_mess) > 1) && 
       (replace_string(in_mess[1], " ", "") == "ERROR")); /* do nothing */
    else if(in_mess[0][0..3] == "IPAD"); /* do nothing */
    else if(in_mess[0][0..5] == "Sorry,"); /* do nothing */
    else /* This is an unknown response.  Let's log it. */
      log_msg(fd, "!ident: ", response);
    tell_querier(fd, "!error!", "Host did not respond with a useful "
                                "response:\n " + response);
    return;
  }
  if(sizeof(in_mess) > 4)
    in_mess[3] = implode(in_mess[3..], ",");

  hosttype = replace_string(in_mess[2], " ", "");
 
  userid = implode(explode(in_mess[3], " ") - ({ "" }), " ");

  /* Okay, some machines are far far too helpful, and the above stuff ends
     up catching data in userid that we really didn't want.  Maybe some day
     that stuff might be of some value.  Right now, let's just log it so
     we can see what we got and return it as part of host-type.
  */
  if( (sscanf(userid,"%s,%s",junk,junk2) == 2) ||
      (sscanf(userid,"%s %s",junk,junk2) == 2) ) {
    userid = junk;
    hosttype += " : "+junk2;
    /* Let's only log ones we've never seen, come to think of it */
    if(junk2[0..7] == "#VMS_PID"); /* do nothing */
    else if(junk2[0..2] == "CLI"); /* do nothing */
    else
      log_msg(fd, "$nifty: ", response);
  }

  tell_querier(fd, userid, hosttype);
} /* read_cb() */

private void tell_querier(int fd, string userid, string hosttype) {
  if(!fds[fd][CALLER])
    return;

  fds[fd][CALLER]->receive_ident_data(userid, hosttype);

  map_delete(fds, fd);
}

private void log_msg(int fd, string begin, string msg) {
  log_file(ERROR_LOG, begin + fds[fd][OB]->query_name() +
           ", " + query_ip_number(fds[fd][OB]) + ": " + msg + "\n");
}

private void create() {
  fds = ([ ]);
  arbitrary_fd = 1000;
  seteuid("Network stuff");
}

string get_stats() {
  return "Retries: " + retried + ",  Failures: " + failed;
}
