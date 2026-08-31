init(){::init();
   add_action("sleep","sleep");
   }
sleep(){
 this_player()->move_player("falls asleep, and vanishes#/players/dice/2light/2l1");
  return 1;
  }
