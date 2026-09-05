#include "/players/cosmo/closed/ansi.h"
#include "/players/cosmo/jb/jsongs.h"
#include "/players/cosmo/jb/jtitles.h"
#define BANNER "~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~"
#define ROM emit_channel("jukebox", "(jukebox) "+
#define CAPNAME capitalize(player->query_name())


cmd_jukebox_list (str) {
int num, n;
string *titles, *CDs;
  CDs = ARTISTS;
  n = 1;
  if(!str) {
    write(HIR+"\n"+BANNER+NORM+"\n");
    write("Number   Artist -- Title\n");
    while (CDs[n] != "END")  {
      if(n>9) { write("  "+n+".    "+CDs[n]+"\n"); }
      if(n<10) { write("  "+n+".     "+CDs[n]+"\n"); }
      n++;  }
    write(HIR+BANNER+NORM+"\n");
    write(HIR+BANNER+NORM+"\n");
  return 1;  }
  sscanf(str, "%d",num);
  switch(num) {
    case 1: titles = CD1; break;
    case 2: titles = CD2; break;
    case 3: titles = CD3; break;
    case 4: titles = CD4; break;
    case 5: titles = CD5; break;
    case 6: titles = CD6; break;
    case 7: titles = CD7; break;
    case 8: titles = CD8; break;
    case 9: titles = CD9; break;
    case 10: titles = CD10; break;
    case 11: titles = CD11; break;
    case 12: titles = CD12; break;
    case 13: titles = CD13; break;
    case 14: titles = CD14; break;
    case 15: titles = CD15; break;
    default:
      write("That is not a valid selection.  Please select again.\n");
      return 1;
    break;
  }
  write(HIR+"\n"+BANNER+NORM+"\n");
  write(HIY+titles[0]+NORM+"\n");
  n = 1;
  while(titles[n] != "END") {
    write(titles[n]+"\n");
    n++;
  }
  write(HIR+BANNER+NORM+"\n");
return 1;  }
