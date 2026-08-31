#include "/players/goldsun/stand.h"

listen(){
 if (random(5)<=1){
  write("You can hear an animal sound at this moment.\n");
  say((this_player()->query_name())+" listens.\n");
  }
   else {
    write("You can hear a slight breeze in the branches above.\n");
    say((this_player()->query_name())+" listens.\n");
    }
 return 1;
}

