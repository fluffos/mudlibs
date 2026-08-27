inherit "std/room";
#include "path.h"
int test1;
void init()
{
::init();
add_action("sit","sit");
}

void setup() {
   set_short("The Guildmaster's room");
   set_long(
      "This is the Guildmaster's room for the Cleric's guild.  "+
"A large desk sits in the center of the room and on the "+
"far west wall "+
"there is a large window and "+
"a large bookcase is set against the east wall.  On the north wall is "+
"a large comfortable couch.\n");
   set_light(100);
add_exit("down", ROOM+"tymcounci", "door");
add_alias("books","book");
add_item ("desk","This is an old oak desk.  "+

"On the far left corner "+
"there is a small candle burning.  There is quite a bit of paperwork "+
"that clutter the desk.  On the right side of the desk is a picture "+
"in a frame.\n");
add_item ("paperwork",
"The pile of paperwork is very big, so you just glance at the top couple "+
"layers.  "+
"There are applications to the guild, "+
"guild member reviews and various other "+
"documents.\n");
add_item("candle","The candle creates willowy shadows move about this "+
"room.\n");
add_item ("window","You look out the window and see a beautiful view of "+
"the garden below.\n");
add_item ("bookcase","It is filled with tons of books.\n");
add_item ("couch","This couch is really a comfortable couch to sit on.  "+
"A cute lovable teddy bear sits on the corner of the couch.\n");
add_item ("book","As you glance at the titles of the various books lying "+
"on the shelf.  You don't see any books that you have read before.\nBut "+
"wait!!!  Where did that come from?\n"+
"Your favorite book that you have ever read is lying on the shelf, now.\n");
add_item ("bear","This is a cute loveable teddy bear.  It stares at you "+
"with puppy dog like eyes.\n");
add_item ("picture","It is a nice picture of a puppy.  *sigh*  But it isn't "+
"like the real thing.\n");
add_item ("frame","This is a nice wooden frame with ornately carved "+
"roses on it\n");
   set_co_ord( ({ -2, -1, 1 }) );
}
sit(arg)
{
if(!arg=="couch"){
return;}
write("You sit in the comfortable couch.\n"+
"You relax and think of that special person in your life.\n"+
"You stand up feeling refreshed and ready for the new day.\n");
say (this_player()->query_cap_name()+" sits on the couch.\n");
return 1;
}

