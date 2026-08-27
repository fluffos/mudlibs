inherit "/std/storeroom";
#include "path.h"

object board;
void reset()
{
 if(!board) {
     board = clone_object("/obj/misc/board");
     board->move(this_object());
     board->set_datafile("Wizard");
}

}

void dest_me()
{
 if(board) board->dest_me();
::dest_me();
}

void setup() {

  set_light(150);
  set_short("Council Room");
  set_long("High Council of Mages, council room.  Only wizards may enter this "+
           "room.  This place seems to be made of magics beyond your wildest "+
           "dreams.  The walls, floor and ceiling appear to be made of stars."+
           "  The tree that the incredible oaken table in the center of "+
           "the room was made from, never graced a forest on this planet.  "+
           "The Weave feels incredibly powerful here.  You get the feeling "+
           "that any spells cast here would be doubly potent.\n");
  add_item("table","This incredible table was crafted by dwarves who were "+
                   "given the wood by Midnight herself.  On it surface you "+
                   "see a mural of Daggerford and the surronding areas.  As "+
                   "you watch the mural changes, perfectly mimicking the real"+
                   " Daggerford.\n");
  add_item("wall","Staring at the walls you realize that they are made of "+
                  "stars!  The symbol of Midnight is hanging on one of the "+
                  "walls.\n");
  add_item("stars","You recognize none of the constelations. They are "+
                   "probably not real, but rather magical illusions.\n");
  add_item("ceiling","The ceiling seems to be made of stars.\n");
  add_item("weave","The weave is very strong here.  Using your wizards sight "+
                   "you see an almost blinding, writhing pattern of magic "+
                   "surronding this room\n");
  add_item("symbol","This is the symbol of Midnight, beautifully carved from "+
                    "a substance you do not recognize.\n");
  add_item("floor","The floor is made of stars as well.  There appears to be "+
                   "some kind of force holding your feet mere inches from "+
                   "the void surrounding the stars.\n");
  add_item("mural","It's an exact replica of the city. It's almost alive.\n");
  add_alias("roof","ceiling");
  add_alias("star","stars");
  add_exit("down",ROOM +"mu","door");
}


