/* A temple for raising..
 * Needs money to work...
 * Inherits /std/raiseroom.c that uses the bank-handler to handle accounts.
 * Baldrick.
 */

inherit "/std/raiseroom";
#include "path.h";

object helper;

void setup()
{
    add_property("no_undead",1); set_short("Realm of the Elf:  Miracle Max's");
    set_save_file(ROOM +"collect");
    set_helper_name("Miracle Max");
    set_long("\n   Realm of the Elf:  Miracle Max's\n\n"
      "     You have entered Miracle Max's. He performs miracles "
      "for hire. This place is creepy. It's kinda funny that "
      "someone would come here to get raised instead of killed. "
      "If you want to get raised, you might want to "
      "look at the sign first. \n\n");
    set_percentage(100);
    set_light(60);

    add_item("shrine", "A small altar to Tymora sits in the corner.  There"
      " are several lit candles around the shrine, but it"
      " really doesn't attract your attention when you first"
      " enter the room. \n");
    add_item(({"cot", "cots"}), "Uncomfortable looking wooden tables where the"
      " bodies are placed for examination and treatment. \n");
    add_item(({"healer", "healers"}), "Stern looking individuals who spend their"
      " days raising people from the dead.  They move about the"
      " room, their movements fluid and purposeful.  They are busy"
      " people, and don't look like they smile often. \n");
    add_sign("/---------------------------------------------\\\n" 
      "|                                             |\n" 
      "|          Miracle Max's Raising              |\n" 
      "|                                             |\n" 
      "|     Type raise <ghost> to raise someone.     |"
      " +|     Type raise <ghost> to raise someone.     |\n" +
     "+----------------------------------------------+\n" +
"\n\n");

      add_exit("north",ROOM + "center", "door");
  }

    void reset()
    {
        if (!helper)
        {
            helper = clone_object(CHAR + "moria");
            helper->move(this_object());
        }
    } /* void reset */ 

    void dest_me()
    {
        if (helper)
            helper->dest_me();
    } /* void dest me */
    void init() {
        ::init();
        add_action("do_raising","raise");
    }
