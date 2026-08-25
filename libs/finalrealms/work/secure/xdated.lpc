/* xdated -- Hamlet, Feb 1996 */
/* This one asks the machine what time it is... both as a string and as
   an integer.  It'll be the basis of a 'localtime' command for players,
   which tells them what time it is in their part of the world.  Probably
   won't be overwhelmingly reliable, but, hey, automation rules.  Some of
   this code is still Dyraen's identd.
  
   If you improve this, I'd ask that you mail a copy to icharles@opup.org.
*/

#include <socket.h>

#define ERROR_LOG "/log/xdate.errors"

#define END { call_out("dest_me",0); return 0; }
#define V_END { call_out("dest_me",0);  return; }

object tp;
string timeresp;
string host;

void log_error(string str);
int cook_time_diff();

/* data is the ipnumber */
int do_xdate(string data, object me) {
  int fd, err;
  string *junk;

  if (!data) END;
  if (!me) END;

  tp = me;
  host = data;

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
  err = socket_connect(fd, data+" 13", "read_cb", "write_cb");
  if (err < 0) {
    log_error("** Socket Connect Error: "+socket_error(err)+".\n");
    END;
  }

  timeresp = "";
  call_out("dest_me",40);
  return 1;
} /* do_xdate() */

void read_cb(int fd, string mess) {
  mess = replace_string(mess,"\r","");
  
  timeresp += mess;
} /* read_cb() */

void write_cb(int fd) {
  int err;

  if (!tp) {
    socket_close(fd);
    V_END;
  }

  err = socket_write(fd, "\r\n");
  if (err <0) {
    log_error("** Socket Write Error: "+socket_error(err)+".\n");
    V_END;
  }
} /* write_cb() */

void close_cb(int fd) {
  if(strlen(timeresp))
    tp->receive_xdate_data(cook_time_diff(),timeresp);
  else
    tp->receive_xdate_data(-1,"");
  V_END;
} /* close_cb() */

/* Of course VAXen have their own nasty language. */
/* format is:  Thursday, February 22, 1996 10:13:08PM-CST */
string *vax2unix(string *inp) {
  string *tmp;
  int tmphr;
  
  /* skip inp[0..1], we don't look at them anyway. */
  
  /* get rid of that comma */
  inp[2] = inp[2][0..strlen(inp[2])-1];
  
  /* Fix up time */
  tmp = explode(inp[4],":");
  
  if(sizeof(tmp) < 3)
    return ({ });
  
  tmphr = atoi(tmp[0]);
  
  if(lower_case(tmp[2][2..3]) == "pm")
    tmphr += 12;
    
  tmp[0] = sprintf("%d",tmphr);
  
  /* Now swap them... */
  inp[4] = inp[3];
  inp[3] = implode(tmp,":");
  
  /* Now we have: Thursday, February 22 22:13:08PM-CST 1996 */
  /* close enough, huh? */
  return inp;
}

/* The whole point of this next one is that we shouldn't pass along
   results from a clock that's off by a few minutes to the player.
   We assume the mud's machine is accurate and just calculate the
   offset of the player's machine in terms of half-hours.  If their
   machine is heinously wrong, that's not our problem.  But close
   will do.
*/
int cook_time_diff() {
  string *datejunk;
  string *timejunk;
  int timedif;
  string *ourjunk = explode(ctime(time())," ") - ({ "" });  
                    /* Mud machine's timestr */
  string *ourtmjunk = explode(ourjunk[3],":");
  int tmp;
  
  datejunk = explode(timeresp," ") - ({ "" });

  if(sizeof(datejunk) < 5) {
    write_file(ERROR_LOG,"!xdate "+host+": "+timeresp+"\n");
    return 0;
  }

  if(strlen(datejunk[0]) > 3)  /* It's probably a vax, clean that crap up */
    datejunk = vax2unix(datejunk);
  
  if(sizeof(datejunk) < 5) {
    write_file(ERROR_LOG,"!xdate "+host+": "+timeresp+"\n");
    return 0;
  }
  
  /* Now we have:  ({ "Sun", "Jan", "31", "08:10:35", "1996" })  */
  timejunk = explode(datejunk[3],":");
  /* That's ({ "08", "10", "35" }) */
  
  if(sizeof(timejunk) < 3) { /* error.  */
    write_file(ERROR_LOG,"!xdate "+host+": "+timeresp+"\n");
    return 0;
  }

  if(sizeof(datejunk) > 5)
    write_file(ERROR_LOG,"$nifty, "+host+": "+timeresp+"\n");
    
  /* hours */
  timedif = (atoi(timejunk[0]) - atoi(ourtmjunk[0])) * 3600;
  
  /* Some funky places keep time that's 1/2 hour off an official time...
     probably isn't relevant, but let's cover it anyway.
  */
  tmp = atoi(timejunk[1]) - atoi(ourtmjunk[1]);
  if(tmp > 15) {  /* We need to add either 1/2 hr or 1 hr */
    if(tmp < 45)
      timedif += 1800;
    else
      timedif += 3600;
  }
  else if(tmp < -15) {
    if(tmp > -45)
      timedif -= 1800;
    else
      timedif -= 3600;
  }
  
  /* What about being off part of a day? */
  tmp = atoi(datejunk[2]) - atoi(ourjunk[2]);
  if((tmp == 1) || (tmp < -1)) /* they're a day ahead... let's add... */
    timedif += 86400;
  else if((tmp == -1) || (tmp > 1)) /* a day behind */
    timedif -= 86400;
    
  return timedif;
}

void dest_me() {
  if (clonep(this_object())) {
    remove_call_out("dest_me");
    destruct(this_object());
  }
} /* dest_me() */

void log_error(string str) {
  write_file(ERROR_LOG,"** "+ctime(time())+" "+host+": "+str);
}
