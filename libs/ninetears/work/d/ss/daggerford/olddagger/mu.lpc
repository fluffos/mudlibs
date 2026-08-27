inherit "/std/guildroom";
#include "path.h"

int learn_spell(string name, string file, int min, string type);

object board, delfen;
void reset() {
   if (!delfen) {
      delfen = clone_object(CHAR+"delfen");
      delfen->move(this_object());
   }
   if (!board) {
      board = clone_object("/obj/misc/board");
      board->move(this_object());
      board->set_datafile("Wizard");
   }
}

void setup() {
   set_short("Delfen's tower");
   set_long(
      "You have entered a small, comfortable chamber high in Delfen's "+
      "Tower.  This, apparently, is where Master Delfen instructs his "+
      "pupils in the mysterious art of Weave-tapping commonly known as "+
      "Magic.  Perhaps if you ask nicely, Delfen would let you \"join\" "+
      "his school of Magic and study under him.  Of course, if you are "+
      "already one of Delfen's chosen apprentices, you may \"learn\" a "+
      "new spell from him (if in his opinion you are ready for such "+
      "advanced power).\n");
   set_light(40);
   add_exit("down", ROOM + "delfen", "stairs");
   add_exit("up",ROOM+"council","stairs");
   modify_exit("up",({"message", "N$N flies up the stairs towards the top of "+
    "the tower.", "function","go_up"}) );
   set_teaching_person(delfen);
   set_guild("mage");
   set_co_ord( ({ 0, -8, 1 }) );
}

int go_up() {
  if((string)this_player()->query_guild_ob() == "/std/guilds/mage")
    return 1;
  notify_fail("You can't seem to be able to figure how to fly up there.\n");
  return 0;
}
