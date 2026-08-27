inherit "/std/container";
 
int INC = 2;
 
void init()
   {::init();
    add_action("no_look", "look");
    add_action("no_look", "l");
    add_action("no_look", "cast");
    add_action("no_look", "kill");
    add_action("no_look", "attack");
    add_action("no_look", "slice");
    add_action("no_look", "ambush");
    add_action("no_look", "backstab");
    add_action("no_look", "examine");
    add_action("no_look", "steal");
    add_action("no_look", "peek");
   }
 
void setup()
   {set_name("smoke");
    set_short("");
    set_long("The smoke, while not unpleasant to your lungs, makes it "+
	     "extremely difficult to see.\n\n");
    set_value(0);
    set_weight(8000);
    set_heart_beat(1);
   }
 
int no_look()
   {tell_object(this_player(), "The smoke that fills this area "+
	 "prevents you from seeing enough to do much of anything.\n\n");
    return 1;
   }
 
heart_beat()
   {INC--;
    if(INC < 1)
      {tell_room(environment(this_object()), "The smoke dissapates.\n\n");
       this_object()->dest_me();
      }
   }
