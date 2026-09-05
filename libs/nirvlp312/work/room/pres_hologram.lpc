/******************************************************************************
 * Program: pres_hologram.c
 * Path: /room
 * Type: Object
 * Created: 2014 by Dragnar
 *
 * Purpose: Keeps a list of players that have done prestige. 100% copied from
 *          the exlv_guild tablet and modified a bit. Added sorting by
 *          prestige level and date.

 * History:
 *          04/28/2014 - Dragnar
 *            Created.
 ******************************************************************************/

#include <ansi.h>

#define SAVEPATH "room/pres_hologram"

#define ENTRY_POWER 100

mixed *hologram;

status
id(string str)
{
    return (str == "hologram" || str == "nirvana hologram" ||
            str == "the nirvana hologram of prestige" ||
            str == "hologram of prestige");
}


string get_color( int plevel ) {
  switch(plevel) {
    case 1..3:
      return HIW;
      break;
    case 4..6:
      return HIG;
      break;
    case 7..9:
      return HIY;
      break;
    case 10..13:
      return RED;
      break;
    case 14..20:
      return HIR;
      break;
    default:
      return HIM;
      break;
  }
      
}
        
void
long(string str)
{
    int i, s;
    string c, m;

    write("\
A futuristic hologram display that shows the players of Nirvana\n\
who have achieved the highest honor of prestige. These players\n\
are forever glorified here for their sacrifices and bravery.\n\n");
    say((string)this_player()->query_name() + " \
examines the hologram.\n");

    if(!(s = sizeof(hologram))) {
      write("\t\tThe hologram is blank.\n\n");
      return;
    }

    write(HIBLK + "\tTHE PRESTIGED OF NIRVANA\n\n" + NORM);

    for(i = 0; i < s; i += 1) {
      c = ctime(hologram[i][2]);

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
      write("  " + get_color(hologram[i][1])+
                   pad(hologram[i][0], 16) + " " + 
                   pad(hologram[i][1],4) + 
                   (m + " " + c[8..9] + ", " + c[20..23]) + NORM+ "\n");
    }

    if((int)this_player()->query_level() >= ENTRY_POWER) {
      write("\n\
Your level entitles you to be able to 'add' an entry to the\n\
hologram, or 'delete' a bad entry.\n");
    }
              
    write("\n");
}

void
reset(status arg)
{
    if(arg) return;

    hologram = ({ });
    restore_object(SAVEPATH);
}


int is_member( mixed *myarr, string str ) {
  int i, idx;
  
  idx = -1;
  
  if(!myarr)
    return idx;
  
  for( i=0; i < sizeof(myarr); i++ ) {
    idx = member( myarr[i], str );
    if(idx >= 0 )
      return i;
  }
  return idx;
}

int do_save() {
  hologram = sort_array(hologram, "pres_sort", this_object());
  save_object(SAVEPATH);
}

int
delete_entry(string who)
{
    int idx, val;
    string a;
    object b;

    if(!(b = this_player()) || (int)b->query_level() < ENTRY_POWER)
      return 0;

    idx = is_member( hologram, who );
    
    if( idx >= 0 ) {
      hologram -= ({ hologram[idx] });
      do_save();
    }

    return idx >= 0;
}    

status
encode_hologram(object who)
{
    string pname;
    int plevel, idx, cur_time;
    
    if( !who ) /**|| who->is_testchar() )**/
      return 0;
      
    plevel = (int) who->query_prestige_level();
    
    if( plevel < 1 )
      return 0;
    
    pname = (string) who->query_name();

    cur_time = time();

    idx = is_member(hologram, pname);
    if(idx >= 0) {
      hologram[idx] = ({ pname, plevel, cur_time });
    }
    else
      hologram += ({ ({ pname, plevel, cur_time }) });
      
    do_save();

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
      command("look at hologram", this_player());
      return 1;
    }
    notify_fail("You may read the hologram.\n");
    return 0;
}

string
short()
{
    return (BOLD + "The Nirvana "+HIG+"Hologram of Prestige" + NORM);
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

int pres_sort(mixed *a, mixed *b) {
  /****************************************
   * Sort by date if levels are the same
   ****************************************/
  if( a[1] == b[1] )
    return a[2] > b[2];
  else
    return  a[1] < b[1];
}

status
cmd_add(string arg)
{
    object ob;
    object who;

    if(!(ob = this_player()) || ((int)ob->query_level() < ENTRY_POWER))
      return 0;

    if(!stringp(arg)) {
      write("Type: 'add <name>' please.\n");
      return 1;
    }
    
    who = find_player( arg );
    
    if(!who) {
      write("Unable to find "+arg+"\n");
      return 1;
    }
    
    if(encode_hologram(who)) {
      write("You add " + arg + " to the Hologram.\n");
      return 1;
    }
    else {
      write("You fail to add " + arg + " to the Hologram.\n");
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
