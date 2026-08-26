/**
 * New player banning changed by Pinkfish June 1996.
 * Changed to make the site access stuff timeout. Pinkfish July 1997.
 */

#include <access.h>
#include <mail.h>
#include <login.h>
#include <playerinfo.h>

#define BASTARDS_SAVE SECURE_DIR SAVE_DIR HANDLER_DIR "/bastards"

nosave string *names, def;
mapping site_access, suspended;

int query_access( string *address, string ident );
protected mapping timeout_access( mapping bing );
private void save_me();

/** @ignore yes */
void create() {
    names = ({ "shaydz", "/global/creator", "root", "/global/player",
               "failsafe", "/global/failsafe", "old", "/global/player.old"});
    def = "/global/player";
    seteuid("Root");
    site_access = ([ ]);
    suspended = ([ ]);
    unguarded((: restore_object, BASTARDS_SAVE :));
    if( !site_access )
        site_access = ([ ]);
    site_access = timeout_access(site_access);
#ifdef NEW_DRIVER
    if( find_object("/room/void") )
        move_object( find_object("/room/void") );
#else
    move_object( TO, "/room/void");
#endif
} /* create() */

int no_new_players( object ob ) {
  return ( query_access( explode( query_ip_number(ob), "."),
           ob->query_name() ) == NO_NEW );
} /* no_new_players() */

int no_players( object ob ) {
  return ( query_access( explode( query_ip_number(ob), "."),
           ob->query_name() ) == NO_ACCESS );
} /* no_players() */

int check_access( object ob, int newish ) {
  switch ( query_access( explode( query_ip_number(ob), "."),
           ob->query_name() ) ) {
    case NO_NEW :
      if( !newish ) {
          write("Site banned for new players.\n");
          return 0;
      }
      return 1;
    case NO_ACCESS :
      write("Site banned for all players.\n");
      return 0;
    case ACCESS :
      return 1;
    default :
      return 1;
  }
} /* check_access() */

string query_player_ob( string name, int tell_suspend ) {
   int i;

   if( file_size("/banish/"+name[0..0]+"/"+name+".o") > 0 ) {
       write("Sorry, the name ["+name+"] has been banished.\n");
       return 0;
   }

   if( DOMAIN_H->query_domain(name) ) {
       write("Sorry, ["+name+"] appears to be a domain name.\n");
       return 0;
   }

   if( PROJECT_H->query_project(name) ) {
       write("Sorry, ["+name+"] appears to be a project name.\n");
       return 0;
   }


   if( MAIL_TRACK->query_list(name) ) {
       write("Sorry, the name ["+name+"] is a mailing list.\n");
       return 0;
   }

   i = member_array( name, names );
   if( i != -1 )
       return names[i+1];

   if( suspended[name] ) {
       if( suspended[name][SUSPEND_TIME] > time() ) {
           if( tell_suspend ) {
               write("You have been suspended until "+
                   ctime(suspended[name][SUSPEND_TIME])+" because "+
                   suspended[name][SUSPEND_REASON]+".\n");
               return 0;
           }
           // If they are not being told, then we just return 1...
           return def;
       }
       // remove them if they are over time.
       map_delete( suspended, name );
       save_me();
   }

   if( query_ip_number(PO) &&
       !check_access( PO, (int)PLAYER_H->test_user(name) ) )
       return 0;

   // make sure there is a save-file.
   if( file_size( LOGIN_OB->query_player_file_name(name) + ".o") < 1 )
       return def;

   if( creatorp(name) )
       return "/global/creator";

   return def;

} /* query_player_ob() */

int query_prevent_shadow() { return 1; }

/*
 * Ok, acces checking stuff...
 */
mapping query_all_access() { return copy(site_access); }

/*
 * Look up the address and find out if it is nice and floppy
 * Adress is of the format ({ "130", "95", "100", "2" })
 */
int query_access(string *address, string ident) {
  mixed rest;

  if (!pointerp(address) || sizeof(address) != 4)
    return ERROR;
  rest = site_access[address[0]];
  if (!rest) {
    return DEFAULT;
  }
  address = address[1..];
  while (sizeof(address)) {
    if (!rest[address[0]]) {
      if (!rest["*"]) {
        return DEFAULT;
      } else {
        rest = rest["*"];
      }
    } else {
      rest = rest[address[0]];
    }
    address = address[1..];
  }
  if (rest[ident]) {
    return rest[ident][ACCESS_LEVEL];
  }
  if (rest["*"]) {
    return rest["*"][ACCESS_LEVEL];
  }
  return DEFAULT;
} /* query_access() */

string query_reason(string *address, string ident) {
  mixed rest;

  if (!pointerp(address) || sizeof(address) != 4) {
    return 0;
  }
  if (!(rest = site_access[address[0]])) {
    return 0;
  }
  address = address[1..4];
  while (sizeof(address)) {
    if (!rest[address[0]]) {
      if (!rest["*"]) {
        return 0;
      } else {
        rest = rest["*"][ACCESS_REASON];
      }
    } else {
      rest = rest[address[0]];
    }
    address = address[1..4];
  }
  if (rest[ident]) {
    return rest[ident][ACCESS_REASON];
  }
  if (rest["*"]) {
    return rest["*"][ACCESS_REASON];
  }
  return 0;
} /* query_reason() */

protected mixed add_access(mixed bing, string *address, string ident,
                           int level, string reason, int timeout) {
  if (!timeout) {
    /* Default, 100 days */
    timeout = 100 * 24 * 60 * 60;
  }

  if (!mappingp(bing)) {
    bing = ([ ]);
  }
  if (!sizeof(address)) {
    if (!level) {
      map_delete(bing, ident);
    } else {
      bing[ident] = ({ level, reason, time() + timeout });
    }
    if (!sizeof(bing)) {
      return 0;
    }
    return bing;
  }

  bing[address[0]] = add_access(bing[address[0]], address[1..4], ident,
                                level, reason, timeout);

  if (!bing[address[0]]) {
    map_delete(bing, address[0]);
  }
  if (!sizeof(bing)) {
    return 0;
  }
  return bing;
} /* add_access() */

/*
 * Runs through the array nibbling all the timed out bits...
 */
protected mapping timeout_access(mapping bing) {
  string *bits;
  int i;

  bits = keys(bing);
  for (i = 0; i < sizeof(bits); i++) {
    if (mappingp(bing[bits[i]])) {
      bing[bits[i]] = timeout_access(bing[bits[i]]);
      if (!sizeof(bing[bits[i]])) {
        map_delete(bing, bits[i]);
      }
    } else {
      if (bing[bits[i]][ACCESS_TIMEOUT] < time() ||
          bing[bits[i]][ACCESS_LEVEL] == ACCESS ||
          bing[bits[i]][ACCESS_LEVEL] > 3) {
        map_delete(bing, bits[i]);
      }
    }
  }
  return bing;
} /* timeout_access() */

private void save_me() {
  unguarded((: save_object, BASTARDS_SAVE :));
} /* save_me() */

int change_access(string *address, string ident, int level, string reason,
                  int timeout) {
  if (!sizeof(filter(previous_object(-1),(:lordp($1):))) &&
      base_name(previous_object()) != "/cmds/creator/suspend")
    return 0;

  if (!pointerp(address) || sizeof(address) != 4 || !reason) {
    notify_fail("Invalid parameters.\n");
    return 0;
  }
  site_access = add_access(site_access, address, ident, level, reason,
                           timeout);
  if (!site_access) {
    site_access = ([ ]);
  }
  save_me();
  switch (level) {
    case NO_NEW :
      reason = "no new for "+reason;
      break;
    case NO_ACCESS :
      reason = "no access for "+reason;
      break;
    case ACCESS :
      reason = "access for "+reason;
      break;
    case 0 :
      reason = "deleted for "+reason;
      break;
  }
  unguarded((: write_file, "/log/ACCESS",
             ident+"@"+implode(address, ".")+" set to "+reason+" until " +
             ctime(timeout) + " by "+
             this_player()->query_name()+".\n" :));
  return 1;
}

int suspend_person(string str, int tim, string reason) {
  if (!sizeof(filter(previous_object(-1),(:lordp($1):))) &&
      base_name(previous_object()) != "/cmds/creator/suspend") {
    return 0;
  }
  if (!LOGIN_OB->test_user(str)) {
    return 0;
  }

  if (!reason) {
    reason = "you have been bad";
  }

  suspended[str] = ({ time() + tim, reason });
  save_me();
  unguarded((: write_file, "/log/SUSPEND", str+" suspended until "+
             ctime(time()+tim)+" by "+this_player()->query_name()+" because "+
             reason + ".\n" :));
  PLAYERINFO_HANDLER->add_entry(this_player(), str, "suspend",
                                "Suspended until " + ctime(time() + tim) +
                                " for " + reason);
  return 1;
} /* suspend_person() */

int unsuspend_person(string str) {
  if (!sizeof(filter(previous_object(-1),(:lordp($1):)))){
    return 0;
  }
  map_delete(suspended, str);
  unguarded((: save_object, BASTARDS_SAVE :));
  unguarded((: write_file, "/log/SUSPEND", str+" unsuspended.\n" :));
  PLAYERINFO_HANDLER->add_entry(this_player(), str, "suspend", "Unsuspended.");
  return 1;
} /* unsuspend_person() */

mixed *query_suspended(string name) {
   if (suspended[name]) {
      if (suspended[name][SUSPEND_TIME] > time()) {
         return copy(suspended[name]);
      }
      map_delete(suspended, name);
      save_me();
   }
   return suspended[name];
} /* query_suspended() */
