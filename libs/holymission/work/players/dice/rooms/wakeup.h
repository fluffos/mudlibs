init(){::init();
   add_action("wake_up","wake up");
   add_action("wake_up","wakeup");
   add_action("wake_up","wake");}
wake_up(){
 this_player()->move_player("through a hole#/players/dice/rooms/tree1");
  return 1;
  }
