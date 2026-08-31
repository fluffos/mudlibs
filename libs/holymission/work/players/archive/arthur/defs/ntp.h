init() {
      string name;
      
      add_action("ech", "echo");
      add_action("all", "allow");
      name=TPN;
      if (allo != 0 && name != "Arthur" && name != "Barf" && name != "Sammy" && name != "Blade" &&TP()->query_level()<31)
        {tell_object(TP(),"Sorry, you cant enter Arthur's workroom without his knowledge\n");
        CO(TP(),"move_player","church#/room/church");}
       ::init();
        
        }
all() {
      if(TPN != "Arthur") return 0;
      if(allo != 1) {
         allo = 1;}
      else {
      allo = 0;
      }

        

