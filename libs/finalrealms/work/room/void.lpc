inherit "/std/room";

// Radix - fixes from new driver .. void was an unfriendly place
// after we moved to Aurora...
// Sept 28, 1995
// This got COMPLICATED .. argh
void do_update(string str)
{
   int i;
   object *all = all_inventory(this_object());
   if(!stringp(str) || str == "here")
   {
      //load destinations
      "/w/common"->BAH();
      "/room/entryroom"->BAH();
      for(i=0; i<sizeof(all); i++)
         if(interactive(all[i])) 
         {
            if(!all[i]->query_creator())
            {
               tell_object(all[i],"Moving you from Hell.\n");
               all[i]->move("/room/entryroom");
            }
            if(all[i]->query_creator())
            {
               tell_object(all[i],"Moving you to the Common.\n");
               all[i]->move("/w/common");
               tell_room(find_object("/w/common"),all[i]->query_short()+
                  " arrives with soup on their face.\n",all[i]);
            }
         }
         else
            all[i]->dest_me();     // dest those NPCs and weapons
   }
}


void setup() {
     set_light(40);
     set_short("Convention in the void");
     set_long("This is where you come when you fall out a room and have " 
           "nowhere to go. You are inside a large igloo. Penguin " 
           "waiters (in tuxedos of course) are serving drinks to the " 
           "assembled crowd. A large wombat sits at the end of a " 
           "banquet table, his head resting peacefully in a bowl of " 
           "soup.\n");
     add_alias("bowl", "soup");
     add_alias("igloo", "around");
     add_alias("void", "igloo");
     add_alias("penguins", "penguin");
     add_alias("crowd", "penguin");
     add_alias("waiter", "penguin");
     add_item("soup", "It is pink and comfortable-looking\n");
     add_item("wombat", "Perhaps you should tell him to use his spoon.\n");
     add_item("igloo", "It is nice and warm despite the icy decor.\n");
     add_item("penguin", "The penguins are all rather formally dressed.\n");
     add_exit("entryroom", "/room/entryroom", "door");
}
void init()
{
   add_action("do_update","update");
   room::init();
}

