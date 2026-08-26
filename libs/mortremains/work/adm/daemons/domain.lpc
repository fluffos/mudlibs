//domain.c
// This is the domain daemon for the TMI-2 mudlib.
// It's loosely based on some earlier code written by Sulam (April 12, 1992) and later
// modified by Jubal for multiguilding (Apr12/92).
// The present incarnation, as a daemon, was done by Buddha@TMI-2 on 1/14/93
// 93-08-04 Grendel@tmi-2 Cleaned up a bit, and added separate wizard default
// 19-Dec 94 Leto added some copy()'s


#include <uid.h>
#include <domains.h>
#include <daemons.h>
#include <mudlib.h>

inherit DAEMON;

// the default levels for players and wizards
string player, wizard;

// okay, this can be called with several intentions:
// 1. pass just an object to it, and it will assume the object is a link, and tell you the 
// primary domain of that object.
// 2. add a second string arguement to either method 1 or 2, and it will tell you if the
// player is a member of the domain specified by the second arguement.
// The return value, will be either 0, or the name of the domain the user is a 
// member of.
 
varargs string
query_domain(object link, string domain)
{
	mapping domains, entry;
	string level;

	if(!link || !objectp(link))  return 0;
 
	domains = link->query("domains");
	if (!domains || !keys(domains)) return 0;  // default case, for a player
	if(!domain)  domain = domains["primary"];
	if(domain) entry = domains[domain];
	if(entry) level = entry["level"];
 	if(!level)  return 0;
    return copy(domain);
}

varargs string
query_domain_sponsor(object link, string domain)
{
	mapping domains, entry;

	domains = link->query("domains");
	if( !domains || !keys(domains)) return 0;
	if(!domain) domain = domains["primary"];
	if( member_array( domain, DOMAIN_LIST ) < 0) return 0;
	entry = domains[domain];
      return copy( ( entry ? entry["sponsor"] : 0 ) );
}

 varargs string
query_domain_level(object link, string domain)
{
	mapping domains, entry;

	if(!link)  return player;
 
	domains = (mapping)link->query("domains");
	if (!domains || !keys(domains))
	    return (int)link->query("wizard") ? wizard : player;
	if (!domain) domain = domains["primary"];
	entry = domains[domain];
	// assume if they have a domain entry they are a wizard
      return copy ((entry ? entry["level"] : wizard));
}

nomask int
set_domain(object link, string domain, string lev, string sponsor )
{
	mapping domains, rec;

	if (getuid(previous_object() ) != ROOT_UID) return 0;
	domains = link->query("domains");
	if (nullp(domains) || !keys(domains)) domains = ([ ]);
	if (member_array(domain, DOMAIN_LIST ) < 0) return 0;
	if (member_array( lev, LEVEL_LIST ) < 0) return 0;

// This is cargo-cult programming and I know it, but I think the
// daemon is losing its EUID and that's causing a Heisenbug that
// makes promotion/demotion fail. So, I'm setting the EUID by hand. If
// I'm wrong, it should not cost anything.

	seteuid(getuid()) ;

	/* remove from domain? */
	if( member_array(lev,LEVEL_LIST) < ENTRY_LEVEL && domain != 0 )
	{
		map_delete(domains, domain);
                if(!undefinedp(domains["primary"])
                   && domains["primary"] == domain)
                    map_delete(domains,"primary");
                link->set("domains", domains);
		return 1;
	}

	/* promote or add user to domain */
	rec = ([ "level" : lev, "sponsor" : sponsor ]);
	domains[domain] = rec;
	if( member_array(lev,LEVEL_LIST) >= ENTRY_LEVEL &&
	    ! domains[ "primary" ] )
		domains[ "primary" ] = domain;
	link->set("domains", domains);
	return 1;
}

nomask int
set_primary_domain(object link, string d)
{
	mapping domains;

	if (geteuid(previous_object()) != ROOT_UID) return 0;
	domains = (mapping)link->query("domains");
	if (!domains || !keys(domains) || !domains[d]) return 0;
	if ( member_array(d, DOMAIN_LIST ) < 0) return 0;
	if ( member_array(domains[d]["level"],LEVEL_LIST) < ENTRY_LEVEL)
		return 0;
	domains["primary"] = d;
	return 1;
}

nomask string
query_primary_domain(object link)
{
	mapping domains;
	domains = (mapping)link->query("domains");
	if (!domains || !mapp(domains)) return 0;
        return copy(domains["primary"]);
}

void create()
{
    switch(sizeof(LEVEL_LIST))
    {
      case 0:
	player="";
	wizard="";
	break;
      case 1:
	player=wizard=LEVEL_LIST[0];
	break;
      default:
	player=LEVEL_LIST[0];
	wizard=LEVEL_LIST[1];
    }
}

/* EOF */
