From:    Demodian
Cc:      
Subject: user auth code fragment
Date:    Sat Oct 21 19:07:32 1995

this will call a function in the player object to do the logging as i could
not get the closure to use the log_file() sefun.  We call this at login, but
could be done upon reconnection too.

------
void log_user_name(object player)
{
 int *ip;
 mixed m;

 if(!interactive(player))
  return;
 m = player;
 query_ip_number(&m);
 ip = m + ({ 0,0, query_host_port()>>8, query_host_port()&255 });
 efun::send_erq(ERQ_AUTH,ip,lambda(({'a}),({#'call_other,player,
  "set_user_name",({#'to_string,'a})})));
}
------

one thing that is needed to make this work is to set the master.c to allow
"erq" to have ERQ_AUTH to return 1 in privelege_violation().  The target
function in the player object can call the log_file() sefun or whatever.  There
are possibly 3 results:

empty string ""
error string "number , number : ERROR : errormessage"
id string "number , number : USERID : machineOS : username"

hope you can get to use it.  took me a while to get it to work.
one note:  most universities and private machines typically fail on the
identd service, but most commercial providers (where the idiots come from)
DO provide it.  Good luck!
