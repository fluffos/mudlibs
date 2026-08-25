// Asmodean  4-13-97
// Count Object Types
// Taken from Lima Lib object as a test
//  


#include <cmd.h>
inherit CMD_BASE;

int cmd(string args, object me)
 {
     int min;
 
 	mapping counts = ([ ]);
 	
 	objects((: $(counts)[base_name($1)]++ :));
        if (!args)
             min = 2;
               else 
               sprintf(min, "%i", args);
         counts = filter(counts, (: $2 > $(min) :));
   write(sprintf("%O\n", counts));
  return 1;
 }
