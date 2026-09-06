/*
  The center of the Archwizard Building
*/

inherit "/std/room";

#include "path.h"
#include <config.h>
#include <nightday.h>
#include <rooms.h>
#include <properties.h>

string maptext, tabletext;

string query_job_text() { return tabletext;} /* Pumuckel, Sep 11 94 */
string topdisk() { return(read_file("/etc/TOPDISK")); }

string clock() {
  string rc, cdate;
  mixed * uptime;

  rc = "The clock shows:\n";
  cdate = ctime(time());
  rc += "  -- "+cdate[0..2]+" "+cdate[8..9]+"-"+cdate[4..6]+
    "-"+cdate[22..23]+" "+cdate[11..18];
  cdate = (string)GAMECLOCK->QueryDaytime();
  if (cdate) 
    rc += " ("+cdate+")";
  rc += " --\n";
  uptime = (mixed *)GAMECLOCK->QueryUptime();
  rc += "  Time since genesis: ";
  if (!pointerp(uptime))
    rc += "unknown";
  else
    rc += implode(map(uptime, #'to_string), " ");
  rc += "\n";
  return rc;
}


varargs int read(string str) {
  if(!str) return(0);
  if(lower_case(str) == "map") {
    write(maptext);
    return(1);
  }
  if(lower_case(str) == "table" || lower_case(str) == "table of charges") {
    write(tabletext);
    return(1);
  }
  if(lower_case(str) == "list" || lower_case(str) == "topdisk") {
    write(topdisk());
    return(1);
  }
  return(0);
}        
	       
void create() {
  string *strs;

  (::create());
  SetIntShort("Center of Tower of Administration");
  SetIntLong(
"You are at the center of the Tower of Administration. "
"The main board of the Wizards stands here. Corridors lead to the north, "
"south, east and west. The offices of the Archwizards are on this floor. "
"Further to the west lies the entrance to the tower. Marble stairs "
"lead up to the second level. The room is glowing in a warm light. "
"A topdisk list and a map of the building are pinned on the wall beside "
"a small clock. The table of charges seems to be relatively new.\n");
  AddExit("west",TOWER("first/west_corr"));
  AddExit("north",TOWER("first/north_corr"));
  AddExit("east",TOWER("first/east_corr"));
  AddExit("south",TOWER("first/south_corr"));
  AddExit("up",TOWER("second/center"));
  AddItem("/std/board",REFRESH_HOME,
    ([P_SHORT:"The Central Wizard Board",
      P_LONG:"It carries 'general' (default) and all subgroups.\n",
      "Groups":(({"general","ideas.\\.*"}))]));
  maptext =
"                          The Tower of Administration\n"
"                       ---------------------------------\n"
"\n"
"  The first floor contains   The second floor contains  On the third floor\n"
"  the player board, the      the administration and     is the big meeting\n"
"  wizard board and the       planning rooms of the      hall, the voting\n"
"  Archwizard Offices.        Domain Lords.              room and so on.\n"
"\n"
"          D/W/M                      +---+\n"
"          +- -+                      |   |                +-----------\n"
"          Q   |                      |   |                |   Hall    |\n"
"  +---+-C-+   +-M-+            +-----+   +-----+          +---+- -+---+\n"
"  = pb      wb    |            |               |          |           |\n"
"  +---+-B-+   +-F-+            +-----+   +-----+          +---+- -+---+\n"
"          H   G                      |   |                |   | V |   |\n"
"          +-P-+                      |   |                +---+---+---+\n"
"                                     +---\n"
"\n"
"  Below the first level some wizard training dungeons can be found.\n"
"\n";
  tabletext =
"\t\t\tTable of Charges\n"
"\t\t\t----------------\n"
"God:\t\tWessex\n"
"God's Deputies:\tLarry\t\tCurly\t\tMo\n"
"\n"
"Archwizards:\n"
"Woo woo woo\n";
  AddDetail("map", maptext);
  AddDetail(({"list", "topdisk"}),#'topdisk);
  AddDetail("clock",#'clock);
  AddDetail(({"table", "table of charges"}), tabletext);
  AddRoomCmd("read",#'read);
  strs = explode(ctime(), " ") - ({ "" });
  // if (   (strs[1] == "Dec" && to_int(strs[2]) <= 25))	// 1st .. 25th of Dec
  //   AddItem("/p/christmas/puck/santa", REFRESH_DESTRUCT);
}


void init() { 
  string mes1, mes2;
  ::init(); 
#if 0  /* Since Wizards may SetHome()... */
/* P_HOME does not affect the players homedir ! it's the entrypoint ! */

#define REP_DIR  "/log/rep/"
#define REP_FILE REP_DIR + lower_case((string)this_player()->QueryName()) 
#define SIZE     file_size(REP_FILE)

  if(this_player() && interactive(this_player()) && (string)this_player()->QueryName() && (SIZE > 0)) {
    switch((SIZE + 99) / 100) {
      case 0 : mes1 = ""; mes2 = ""; break;
      case 1 : mes1 = " A little goblin appears in front of you and says:\n"; 
              mes2 = "You should read it.\n The little goblin disappears...\n";
               break;
      case 2 :
      case 3 : mes1 = " A strong troll appears in front of you and yells:\n";
               mes2 = "Read it immediatly!\n"+
                      " The troll stomps away into a dark void...\n";
               break;
      case 4 :
      case 5 :
      case 6 : mes1 = " A big dragon rises in front of you and growls:\n";
               mes2 = "Read it immediatly!!!\n" +
	         " The dragon finally breathes fire and dissolves slowly...\n";
               break;
      default : mes1 = " A powerful demon with red glowing eyes appears in front of you and grins:\n";
                mes2 = "Read it immediatly or get lost!\n" +
	" The demon disappears, but you remember his horrible laughter...\n";
                break;
    }	
    if(mes1 != "") {
      write("\n" + mes1);		
      write(" The file '" + REP_FILE + "' has " + SIZE + " Bytes. ");
      write(mes2 + "\n");
    }			
  }

#endif
}

int clean_up(int arg)
{
  if (sizeof(users()))
    return 1;
  return ::clean_up();
}
