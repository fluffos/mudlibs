#include "path.h"
inherit "/std/room";

void setup()
{
        set_short("Realm of the Duergar:  Living Room");

   set_long("\n   Realm of the Duergar:  Living Room.\n\n"
            "     This is a well lived living room which you know well "
            "because this was your home when you were younger.  There "
            "is a large bench covering the whole of one side of the "
            "room, and an assortment of various other stools etc..  "
            "There is only one exit, and it leads to the dangerous "
            "world known as Final Realms."
            "\n\n");

        add_property("no_undead",1); set_light(50); 

        add_item("bench", "This is a pretty boring bench, old and worn. "
                "You recognise it as the one you nearly broke when you "
                "younger.\n");

        add_item("stool", "This 3 legged stool is a basic stool...you see "
                "the drow trademanships mark on one of the legs.\n");

   add_clone("/baseobs/armours/cloak",1);
   add_clone("/baseobs/weapons/hand_axe",1);
   add_clone(BOOK,1);
  add_exit("leave","/d/newbie/duergar/rooms/main01","door"); 
   modify_exit("leave",({"function","do_leave"}));

}

int do_leave()
{
   if(this_player()->query_property("guest"))
   {
      notify_fail("\nAs a welcome guest to the Final Realms you are "
         "being sent to our special guest area. "
         "Enjoy your visit with us.\n\n");
      this_player()->move(NEW_NEWBIE+"guests/rooms/intersection");
      this_player()->look_me();
      return 0;
   }
   return 1;
}

