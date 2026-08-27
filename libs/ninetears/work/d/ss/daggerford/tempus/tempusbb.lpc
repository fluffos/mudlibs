#include "path.h"
inherit "/std/room";
object board;

void setup() {
  set_short("Bulletin Board Room for Tempus\n");
  set_light(100);
  set_long(
"You are in a large room with a cathedral ceiling and a marble floor.  On "+ 
"one wall is a large bulletin board in an ornate golden frame.  It is "+
"surrounded by a thousand red candles.  The altar is to the north and the "+
"steps are to the south.  There is a side exit leading to the battle"+
"grounds.\n");
  add_alias("candles","candle");
  add_item("candle",
"The candles look like minature swords.  The melting red candle wax gives "+ 
"the swords a bloodied look.\n");
  add_item("frame",
"The frame depicts the many glorious things that the Priest's of Tempus "+ 
"do.\n");
  add_item("ceiling", 
"The ceiling is so high up that you are not sure you can see the top.\n");
  add_item("floor", 
"The floor is black and white and has a checkerboard pattern to it.\n");
  add_exit("north", ROOM+"temaltar", "door");
  add_exit("west", ROOM+"tembattl", "door");
  add_exit("south", ROOM+"temsteps", "door");
  add_exit("east", ROOM+"raiseroom", "door");
}
void reset() {
  if (!board) {
    board = clone_object("/obj/misc/board");
    board->move(this_object()); 
    board->set_datafile("tempus");
  }
}

void dest_me() {

  if (board)
    board->dest_me();
  ::dest_me();
}

