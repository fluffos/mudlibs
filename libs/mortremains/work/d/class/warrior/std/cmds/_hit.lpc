// DOne by Ilzarion

inherit DAEMON;

#include <daemons.h>
#include <mudlib.h>


int cmd_hit(string targ) {
   object ob, weapon, bksb;
   int *dmj, dmin, dmax, damage;
   int multiplier;
   int level;   //Forgot this, too.
   string type;

  
 
   ob = present(targ, environment(this_player()));
 
 if (!ob) {
  write("There's nothing by that name to hit.\n") ;
                return 1;
        }    

     level = this_player()->query_hit(ob);

     if (!level){
     write ("you missed\n");
     return 1;
     }else{
     write ("you hit.\n");
     return 1;
     }
  }