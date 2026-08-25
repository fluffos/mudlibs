/*  Text alterations and additions by Grimbrand 2-11-96                 */

#include "path.h"
inherit "/std/underground";

object *npcs;

nosave int islocked = 1;

void reset() {
    int i;
    for(i=0;i<sizeof(npcs);i++) {
        if(!npcs[i]) {
            npcs[i]=clone_object(DNPC+"dgoblin");
            npcs[i]->move(this_object());
        }
    }
}

void init() {
    ::init();
    add_action("unlockit","unlock");
}

void setup() {
    add_property("no_undead",1); set_light(10);
    npcs = allocate(1);

    set_short("Realm of the Duergar:  Racial Proving Grounds");

    set_long("\n   Realm of the Duergar:  Racial Proving Grounds.\n\n"
      "     The room here is completely bare and unadorned.  The "
      "only things of note are the stains on the floor and the "
      "various chip marks upon the walls.  There is also however, "
      "a pool of blood upon the floor."
      "\n\n");

    add_item(({"floor", "stain", "stains"}),
      "   Looking at the floor you can see that the stone has been "
      "stained from the blood of battles long past.  This room must "
      "see a lot of traffic!  You also notice a fresh pool of blood "
      "on the floor as well."
      "\n\n");

    add_item(({"blood", "pool", "pool of blood"}),
      "   Looking at the blood, you can tell the battle was not too "
      "long ago, even now it is just barely starting to coagulate on "
      "the cool stone floor."
      "\n\n");

    add_item(({"wall", "walls"}),
      "   Looking at the wall, you can see where various weapons "
      "have left chip marks from wild swings and glancing blows."
      "\n\n");

    add_exit("north",NEWBIE+"dlev5_12","door");
    modify_exit("north", ({"function", "do_door"}));
    add_exit("south",NEWBIE+"dlev5_04","path");
    add_exit("east",NEWBIE+"dlev5_06","path");
    add_exit("west",NEWBIE+"dlev5_09","path");
    add_exit("northeast", NEWBIE+"dlev5_18", "path");
    add_exit("northwest", NEWBIE+"dlev5_17", "path");
}
void dest_me() {
    int i;
    for(i=0;i<sizeof(npcs);i++)
        if(npcs[i]) npcs[i]->dest_me();

    ::dest_me();
}

int do_door() {
    if(islocked==1) 
    {
        notify_fail("   Attempting to open the door you discover it is "
          "locked.\n\n");
        return 0;
    }
    islocked = 1;
    return 1;
}

int unlockit(string str) {
    object it;

    if(str=="door") 
    {
        if(present("newbie_key",this_player())) 
        {
            write("   Surprisingly, you find that the key fits "
              "into the lock!  With a quick turn of the key you "
              "hear the door unlock."
              "\n\n");
            tell_room(environment(this_player()), 
              this_player()->query_cap_name() +
              " slides a key into the door lock, and with a quick "
              "twist, you hear a clicking sound.\n\n"
              "CLICK!\n\n", ( this_player()));
            it=find_match("newbie_key", this_player());
            it->dest_me();
            islocked = 0;
            return 1;
        }
        else
        { 
            write("   You need a key to do that!\n\n");
            return 1;
        }
    }
    return 0;
}
