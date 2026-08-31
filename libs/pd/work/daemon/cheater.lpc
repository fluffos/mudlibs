//Cheater daemon written by NS
// Updated by Nesoo to log suspect kills

#include <security.h>
#include <std.h>
#include <daemons.h>

inherit DAEMON;

mapping users;

void create() {
  users = ([]);
}

void add_exp(string who, int exp) {
  int *arr;

  if(!users[who]) {
    arr = ({exp,time()});
    users[who] = arr;
    }
  else
    users[who][0] = exp + users[who][0];
}

void do_log(string who) {
  int exp, oldtime, totaltime;
  float exptemp;

  seteuid(UID_LOG);

  if(!users[who])
    return;

  exp = users[who][0];
  oldtime = users[who][1];
  map_delete(users,who);
  totaltime = time() - oldtime;
  exptemp = exp / totaltime;
  exp = exptemp * 3600;
  message("info"," "+exp+" ",find_player("nightshade"));
  if(exp > 1000)
      log_file("xphour", sprintf("%s has made %d exp per hour at level %d.\n",
            find_player(who)->query_cap_name(), exp,
            find_player(who)->query_level()));
  seteuid(getuid());
}

void log_suspect_kill(object mon, int xp)
{
    object atk = mon->query_attackers()[0];
    object* suspect = mon->query_hunted();
    string* guilty = ({});
    string party = PARTY_D->party_member(atk);
    int i;
    
    if( sizeof(party) )
        suspect -= PARTY_D->query_party_members(party);
    else
        suspect -= ({ atk });
    
    if( !(i = sizeof(suspect)) )
        return;
    
    while(i--)
    {
        if( suspect[i]->is_player() )
        {
            guilty += ({ capitalize(suspect[i]->query_name()) + " at level " +
                    suspect[i]->query_level() });
        }
    }
    
    if( !sizeof(guilty) )
        return;
    else
    {
        seteuid(UID_LOG);
        log_file("suspect_kill", "[ " + ctime(time()) + " ]\n" +
                mon->query_name() + " (" + base_name(mon) + ")\n" +
                "Level: " + mon->query_level() + "\tExp:" + xp + "\n"
                "Was killed by " + capitalize(atk->query_name()) +
                " at level " + atk->query_level() + " with help from: " +
                implode(guilty, "\n") + "\n");
        seteuid(getuid());
    }
}

