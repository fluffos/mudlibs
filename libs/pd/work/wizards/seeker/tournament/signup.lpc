#include <std.h>

#define TOURN_D "/wizards/seeker/tournament/tourn_d"
inherit ROOM;


void create()
{
 ::create();
 set_short("Tournament sign-up area");
 set_long("Many people from around the world line up waiting to sign up "
	  "for the Sindarii tournament. There is three boards behind the "
          "counter with the current list of competitors for this weeks "
          "tournament. There is a list of entry fees on the counter for "
          "the different divisions.");
}

void init()
{
 ::init();
 add_action("fRead", "read");
}

int fRead(string str)
{
 int i,f;

 if (!str || str == "") return 0;
 switch(str) {
   case "boards": case "board": {
	write("/------------------\\ /------------------\\ /-------------------\\\n"
	      "|    Division 1    | |    Division 2    | |    Division 3     |\n"
	      "\\------------------/ \\------------------/ \\-------------------/");
        return 1;
        break;
  }
   case "list": {
	write("Current entry fees:\n");
        for (i=0;i<3;i++) {   
           f = TOURN_D->query_fees("division "+(i+1));
           write("Division "+(i+1)+" - "+f+" gold");
     }
   return 1;
   break;
  }
 }

                
}
