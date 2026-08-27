#define WHO find_player( "insp")
#define TELL(x) if(WHO) tell_object(WHO, x + "\n" );

/* File    : mudlist_a.c
 * Creator : Pinkfish@Discworld
 *         : Grendel@Tmi-2
 * When    : 93-08-15
 *
 * This file is part of the tmi mudlib.  Please keep this header intact.
 *
 * This protocol is used to send a mudlist in response to mudlist_q.
 */
#include <uid.h>
#include <mudlib.h>
#include <net/dns.h>
#include <net/macros.h>

inherit DAEMON;

int have_mudlist = 0;

// Someone replyed to our query and has sent us their mudlist.
void
incoming_request(mapping info)
{
  string *junk, *inf, name, value;
  int i, j;
  mapping new, old;

  if(!ACCESS_CHECK(previous_object())) return;

  // the keys to info are number identifying each mud
  junk = keys(info);
  if(sizeof(junk))
    have_mudlist = 1;
  filter_array(junk, "process_list", this_object(), info);
}

int
process_list(string idx, mapping info)
{
  string *inf, name, value;
  int j;
  mapping new, old;

  if(previous_object() != this_object())
    return 0;
  // each entry consists of '|' separated fields
  inf = explode(info[idx], "|");
  // build up the mapping for the individual muds
  new = ([ ]);
  j = sizeof(inf);
  while (j--)
    if (sscanf(inf[j], "%s:%s", name, value) == 2)
      new[name] = value;

  if(!new["NAME"])
    return 0;

  new["ALIAS"] = nntoh( new["NAME"] );
  // make sure the name is in the proper form
  name = htonn( new[ "NAME" ] );

  // already know about ourselves
  if (new["NAME"] == Mud_name())
    return 0;

  if( new["OFFSET"] ) new["OFFSET"] = to_int( new["OFFSET"] );

  // if we have an entry, we update it, otherwise we add the new entry
  old = (mapping) DNS_MASTER->query_mud_info(name);

  if (!old)
    DNS_MASTER->set_mud_info(name, new);
  else    {
      inf = keys(new);
      j = sizeof(inf);
      while (j--)
	    old[inf[j]] = new[inf[j]];
      DNS_MASTER->set_mud_info(name, old);
    }
  return 0;
}

void
create()
{
  seteuid(ROOT_UID);
}

// these is used by the dns master to find out if we have a mudlist
int
clear_db_flag()
{
  if(ACCESS_CHECK(previous_object()))
    have_mudlist = 0;
}

int
query_db_flag()
{
  return have_mudlist;
}

