/* Hamlet, Jan 1996.  -- This gets cloned to do the ident command.  The
                         Command is now more complex so integration can be
                         truly simple.
*/

#include <inquire_err.h>

#define LORD_ONLY
#define IDENTD "/net/identd"

#define SECURITY_FAIL     -301
#define BROKEN_INQUIRED   -302
#define LOST_SUBJECT      -303

object toident, querier;
string pname;
string ipname;

void dest_me();
string error_msg(int err);

void do_ident(string name, object me) {
  int ret;

#ifdef LORD_ONLY
  if(!"/secure/master"->query_lord(geteuid(me))) {
    tell_object(me, "You do not have the authority to do an ident.\n");
    dest_me();
    return;
  }
#endif

  toident = find_player(name);
  querier = me;
  pname = name;
  
  ipname = query_ip_name(toident);
  if(!ipname)
    ipname = query_ip_number(toident);
  
  if(catch(load_object(IDENTD))) {
    tell_object(me, "ident: " + IDENTD + " will not load.\n");
    dest_me();
    return;
  }
    
  if( (ret = IDENTD->do_ident(toident, this_object())) <= 0 ) {
    tell_object(me, "ident: Query failed for " + capitalize(name) + ".\n"
                    "       " + error_msg(ret) + "\n");
    dest_me();
  }
  else
    tell_object(me, "Please wait...\n");
}

void receive_ident_data(string userid, string hosttype) {
  if(!querier) {
    dest_me();
    return;
  }
  
  if( userid == "!error!" )
    tell_object(querier , "\nident: Query failed for " + 
                          capitalize(pname) + ".\n"
                          "       " + hosttype + "\n");

  else
    tell_object(querier,"\nident: "+capitalize(pname) + " is " +
                   userid + "@" + ipname + " (" + hosttype + ")\n");
                   
  dest_me();
}         

string error_msg(int err) {
  if(err < -300)
    switch(err) {
      case SECURITY_FAIL    : return "You are not authorized to "
                                     "use identd.";
      case BROKEN_INQUIRED  : return "inquired is broken.";
      case LOST_SUBJECT     : return "The target player logged out.";
    }
  else
    return inquire_error(err);
}

void dest_me() {
  destruct(this_object());
}

void create() {
  seteuid("Network stuff");
}
