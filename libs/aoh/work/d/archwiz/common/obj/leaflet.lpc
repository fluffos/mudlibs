inherit "/std/thing";
#include <properties.h>



create() {
  ::create();
  SetIds(({"leaflet", "letter"}));
  SetShort("a leaflet");
  SetLong("This is the leaflet from the mailbox.  Maybe you should read it.\n");
   SetWeight(50);
   SetValue(5);
}


init() {
  ::init();
    add_action("read_it", "read");
}

read_it(str) {
   if (!id(str)) return 0;
   write("WELCOME TO NIGHTFALL!\n\n"
"NIGHTFALL is a game of adventure, danger, and low cunning.  In it you will "
"explore some of the most amazing territory ever seen by mortals.  No network "
"should be without one!\n");
   return 1;
}


