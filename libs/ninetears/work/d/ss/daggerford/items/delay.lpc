inherit "/std/object";
 
int DLAY = 300;
 
void init()
   {::init();
    add_action("NO_TRY", "ambush");
    add_action("NO_TRY", "backstab");  
   }
 
void setup()
   {set_name("DELAY");
    set_short("");
    set_long("This is the delay that prevents backstabs and ambushes "+
             "following use of a gourd.\n\n");
    set_weight(0);
    set_heart_beat(1);
    set_value(0);
    reset_drop();
   }
 
int NO_TRY()
   {tell_object(this_player(), "Unfortunately, you must wait before you "+
         "can use this command after breaking open a gourd.\n\n");
    return 1;
   }
 
heart_beat()
   {DLAY--;
    if(DLAY < 1)
       this_object()->dest_me();
   }
 
