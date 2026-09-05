/* coded by Verte & Softly [c]2001 */

#include "/players/vertebraker/ansi.h"

#define SAVEPATH "room/exlv_tablet"

#define ENTRY_POWER 100

string *tablet;

status
id(string str)
{
    return (str == "tablet" || str == "nirvana tablet" ||
            str == "the nirvana tablet of legends" ||
            str == "tablet of legends");
}

status
wiz_check(string n)  /* not foolproof but hey */
{
    object *us, ob, user;
    int s;
    string n_ip;

    if(this_player() && this_player()->query_level() >= ENTRY_POWER)
      return 0;

    if(!n) return 1;  /* this should never happen */

    if(!(ob = find_player(lower_case(n))))
      return 1;

    if(!(n_ip = query_ip_number(ob)))
      return 1;

    s = sizeof(us = users());

    while(s --)
      if((user = us[s]) && (query_ip_number(user) == n_ip) &&
          ((int)user->query_level() > 21) && (user != ob) &&
          ((int)user->query_level() < ENTRY_POWER))
        return 1;
  return 0; /* Rumplemintz */
}
        
void
long(string str)
{
    int i, s;

    write("\
A magical, ancient stone tablet upon which those Legends of\n\
Nirvana who have achieved the highest level in the realm have\n\
left their mark for the ages.\n\n");
    say((string)this_player()->query_name() + " \
examines the tablet.\n");

    if(!(s = sizeof(tablet))) {
      write("\t\tThe tablet is blank.\n\n");
      return;
    }

    write(BOLD + "\tLEGENDS OF NIRVANA\n\n" + NORM);

    for(i = 0; i < s; i += 2)
      write("  " + pad(tablet[i], 16) + " " + tablet[i + 1] + "\n");

    if((int)this_player()->query_level() >= ENTRY_POWER) {
      write("\n\
Your level entitles you to be able to 'add' an entry to the\n\
tablet, or 'delete' a bad entry.\n");
    }
              
    write("\n");
}

void
reset(status arg)
{
    if(arg) return;

    tablet = ({ });
    restore_object(SAVEPATH);
}

int
delete_entry(string who)
{
    int s, val;
    string a;
    object b;

    if(!(b = this_player()) || (int)b->query_level() < ENTRY_POWER)
      return 0;

    s = sizeof(tablet);

    while(s --)
      if(((a = tablet[s]) == who) && ((s + 1) < sizeof(tablet))) {
        tablet -= ({ tablet[s], tablet[s + 1] });
        val ++;
      }

    if(val) 
      save_object(SAVEPATH);

    return val;
}    

status
encode_tablet(string hoo)
{
    string c, m, entry;
    int s;

    if(wiz_check(hoo))  /* if ip matches a wiz on, i.e. test char */
      return 0;

    if(member_array(hoo, tablet) != -1) /* if name already encoded */
      return 0;

    c = ctime();

    switch(m = c[4..6]) {  /* un-truncate the month */
      case "Jan": m = "January";    break;
      case "Feb": m = "February";   break;
      case "Mar": m = "March";      break;
      case "Apr": m = "April";      break;
      case "Jun": m = "June";       break;
      case "Jul": m = "July";       break;
      case "Aug": m = "August";     break;
      case "Sep": m = "September";  break;
      case "Oct": m = "October";    break;
      case "Nov": m = "November";   break;
      case "Dec": m = "December";   break;
    }

    tablet += ({ hoo, (m + " " + c[8..9] + ", " + c[20..23]) });
    save_object(SAVEPATH);

    return 1;
}

void
init()
{
    add_action("cmd_read", "read");
    add_action("cmd_delete", "delete");
    add_action("cmd_add", "add");
}

status
cmd_read(string str)
{
    if(!str) {
      notify_fail("Read what?\n");
      return 0;
    }
    if(id(str)) {
      command("look at tablet", this_player());
      return 1;
    }
    notify_fail("You may read the tablet.\n");
    return 0;
}

string
short()
{
    return (BOLD + "The Nirvana Tablet of Legends" + NORM);
}

status
get()
{
    return 0;
}

int
query_weight()
{
    return 69696969;
}

status
cmd_add(string arg)
{
    object ob;

    if(!(ob = this_player()) || ((int)ob->query_level() < ENTRY_POWER))
      return 0;

    if(!stringp(arg)) {
      write("Type: 'add <name>' please.\n");
      return 1;
    }
    
    if(encode_tablet(arg = capitalize(arg))) {
      write("You add " + arg + " to the Tablet.\n");
      return 1;
    }

    else {
      write("You fail to add " + arg + " to the Tablet.\n");
      return 1;
    }
}

status
cmd_delete(string arg)
{
    object ob;

    if(!(ob = this_player()) || ((int)ob->query_level() < ENTRY_POWER))
      return 0;

    if(!stringp(arg))
    {
      write("Type: 'delete <name>' please.\n");
      return 1;
    }

    write("Deleted " + delete_entry(capitalize(arg)) + " instances of " + 
      arg + ".\n");

    return 1;
}
