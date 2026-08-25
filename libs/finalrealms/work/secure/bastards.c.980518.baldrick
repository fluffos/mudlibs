/* Bastards.c takes care of suspension, banished sites and now also banished
 * playernames.
 * Baldrick, oct '95
 */
/* Tweaked Sept 1995 -- Hamlet
   Trying to fix NO_NEW and add NO_GUEST
*/

#include "access.h"
#include "mail.h"
#define POSTAL_D "/obj/handlers/postal_d"

static string *names;
static string def;

mapping access;  /* Site access control */
string *preferred;
mapping suspended, banished;

int query_access(string *address, string ident);
mapping query_access_mapping() { return access; }
string get_nomulti_string(string site, string userid);

void create() {
    names = ({ "root", "/global/player",
      "failsafe", "/global/failsafe", });
    def = "/global/player";
    seteuid("Root");
    access = ([ ]);
    suspended = ([ ]);
    banished = ([ ]);
    restore_object(file_name(this_object()),1);
    move_object("/room/void");  /* Make it unclonable... */
    preferred = ({ });
} /* create() */

int check_access(object ob, int existing)
{
    string *tmp = explode(query_ip_name(ob),".");
    switch (query_access(explode(query_ip_number(ob), "."), 
	ob->query_ident())) {
    case NO_NEW :
	if (!existing) {
	    write("Site banned for new players.\n");
	    return NO_NEW;
	}
	else
	    return ACCESS;
    case NO_ACCESS :
	write("Site banned for all players.\n");
	return NO_ACCESS;
    case NO_GUEST :
	if(ob->query_name() == "guest") {
	    write("Site banned for guests.\n");
	    return NO_GUEST;
	}
	else
	    return ACCESS;
    case NO_IMMORTS :
	if(ob->query_creator()) {
	    write("Site banned for immortals.\n");
	    return NO_IMMORTS;
	}
	else
	    return ACCESS;
    case NO_PLAYERS :
	if(!ob->query_creator()) {
	    write("Site banned for players.\n");
	    return NO_PLAYERS;
	}
	else
	    return ACCESS;
    case ACCESS :
	return ACCESS;
    case NO_MULTIPLAY:
      ob->add_static_property("NOMULTI",
                              get_nomulti_string(query_ip_number(ob),
                                                 ob->query_ident()));
	return DEFAULT;
    default :
	return DEFAULT;
    }
} /* check_access() */

/* The flag skips the initial check for query_creator().  This is
   needed for the first call to the fcn, when restore_object() hasn't
   been called yet.  Only purpose of this first call is to determine
   whether the person is banished, so security isn't really an issue.
   Check for query_creator() needs skipped so I can install immortal
   slots, which have to decide whether let person in according to whether
   this fcn returns "global/player" or not.  flag should not be passed in
   any subsequent calls to the function. -- Hamlet
*/
varargs string query_player_ob(string name, int flag)
{
    int i;
    int existing;
    int reason;

    if (POSTAL_D->query_mailing_list(name))
    {
	write("Name is a mailing list.\n");
	return 0;
    }

    if(member_array(name,get_dir("/d/")) != -1) {
	write("Name is a domain.\n");
	return 0;
    }

    i = member_array(name, names);
    if (i != -1) 
    {
	return names[i+1];
    }
    if (banished[name])
    {
	write("This name is banished, pick a different one.\n");
	return 0;
    }
    if (suspended[name] > time()) 
    {
	write("You have been suspended until "+ctime(suspended[name])+".\n");
	return 0;
    }
    suspended = m_delete(suspended, name);
    /*
    if ("secure/master"->query_lord(name)) 
      {
      return "global/lord";
      }
    */
    if(file_size("/players/" + name[0..0] + "/" + name + ".o") < 1)
	existing = 0;
    else
	existing = 1;
    reason = check_access(previous_object(), existing);
    if(reason != ACCESS)
	return "";
    /* I hope this is the right place to put this code in.
     * Baldrick, sept '93 
     * Added more files, oct '95. 
     * First, a check if the player is a creator..
     * to be sure it isn't a new player using a non-existing .o
     */
    if(previous_object()->query_creator() ||flag)
    {
	if ("/secure/gods"->query_boo(name))
	    return "global/god";
	if ("/secure/lords"->query_boo(name))
	    return "global/lord";
	if ("/secure/mudlibber"->query_boo(name))
	    return "global/lord";
	if ("/secure/thanes"->query_of(name))
	    return "global/thane";
	if ("/secure/patrons"->query_patronage(name))
	    return "global/patron";
	if(previous_object()->query_creator()) /* Will actually need this now. */
	    return "global/creator";
    }
    return def;
} /* query_player_ob() */

int query_prevent_shadow() { return 1; }

/*
 * Ok, acces checking stuff...
 */
mapping query_all_access() { return access + ([ ]); }

/*
 * Look up the address and find out if it is nice and floppy
 * Adress is of the format ({ "130", "95", "100", "2" })
 */
int query_access(string *address, string ident) {
    mixed rest;

    if (!pointerp(address) || sizeof(address) != 4)
	return ERROR;
    if (!(rest = access[address[0]]))
	return DEFAULT;
    address = address[1..4];
    while (sizeof(address)) {
	if (!rest[address[0]])
	    if (!rest["*"])
		return DEFAULT;
	    else
		rest = rest["*"];
	else
	    rest = rest[address[0]];
	address = address[1..4];
    }
    if (rest[ident])
	return rest[ident];
    if (rest["*"])
	return rest["*"];
    return DEFAULT;
} /* query_access() */

static mixed add_access(mixed bing, string *address, string ident,
  int level) {
    if (!mappingp(bing))
	bing = ([ ]);
    if (!sizeof(address)) {
	if (!level)
	    bing = m_delete(bing, ident);
	else
	    bing[ident] = level;
	if (!m_sizeof(bing))
	    return 0;
	return bing;
    }
    bing[address[0]] = add_access(bing[address[0]], address[1..4], ident, level);
    if (!bing[address[0]])
	bing = m_delete(bing, address[0]);
    if (!m_sizeof(bing))
	return 0;
    return bing;
} /* add_access() */

int change_access(string *address, string ident, int level, string reason) {
    if (!"/secure/master"->high_programmer(geteuid(previous_object())) ||
      this_player() != this_player(1)) {
	notify_fail("Wrong euid.\n");
	return 0;
    }
    if (!pointerp(address) || sizeof(address) != 4 || !reason) {
	notify_fail("Invalid paramters.\n");
	return 0;
    }
    access = add_access(access, address, ident, level);
    if (!access)
	access = ([ ]);
    save_object(file_name(this_object()),1);
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
    write_file("/log/ACCESS",
      ident+"@"+implode(address, ".")+" set to "+reason+" by "+
      this_player()->query_name()+".\n");
    return 1;
} /* check_access() */

int suspend_person(string str, int tim) 
{
    if (!"/secure/master"->query_lord(geteuid(previous_object())))
	return 0;
    if (file_size("/players/"+str[0..0]+"/"+str+".o") < 0)
	return 0;
    suspended[str] = time()+tim;
    save_object(file_name(this_object()),1);
    write_file("/log/SUSPEND", str+" suspended until "+ctime(time()+tim)+
      " by "+this_player()->query_name()+".\n");
    return 1;
} /* suspend_person() */

int unsuspend_person(string str) 
{
    if (!"/secure/master"->query_lord(geteuid(previous_object())))
	return 0;
    suspended = m_delete(suspended, str);
    save_object(file_name(this_object()),1);
    // Radix...
    write_file("/log/SUSPEND", str+" unsuspended by "+
      this_player()->query_name()+".\n");
    // write_file("/log/SUSPEND", str+" unsuspended.\n");
    return 1;
} /* unsuspend_person() */

/* Banish code: 
 * Added by Baldrick for simplifying banishing.. 
 */

int banish_playername(string str, string reason)
{
    if (!"/secure/master"->query_lord(geteuid(previous_object())))
	return 0;
    /*
    if (file_size("/players/"+str[0..0]+"/"+str+".o") < 0)
      return 0;
    */
    banished[str] = reason;
    save_object(file_name(this_object()),1);
    write_file("/log/BANISHED", str+" banished because of " + reason + 
      " by "+this_player()->query_name()+".\n");
    return 1;
} /* banish player name */

int unbanish_playername(string str)
{
    if (!"/secure/master"->query_lord(geteuid(previous_object())))
	return 0;
    banished = m_delete(banished, str);
    save_object(file_name(this_object()),1);
    write_file("/log/BANISHED", str+" unbanished.\n");
    return 1;
} /* unbanish playername */

string get_nomulti_string(string site, string userid) {
  string *ret;
  string *thesite;
  int i;
  mapping acc;

  acc = copy(access);

  thesite = explode(site, ".");
  ret = ({ thesite[0] });

  acc = acc[thesite[0]];

  for(i=1; i < sizeof(thesite); i++) {
    if(acc["*"]) {
      acc = acc["*"];
      ret += ({ "*" });
    }
    else {
      acc = acc[thesite[i]];
      ret += ({ thesite[i] });
    }
  }

  if(acc["*"])
    userid = "*";

  return userid + "@" + implode(ret, ".");    
}
