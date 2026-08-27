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
      "This is the Guildmaster's room for the Priest's guild.  "+
"A large desk and chair sits in the center of the room and on the "+
"far west wall "+
"there is a large mirror.  A skylight dome is on the ceiling and "+
"a large bookcase is set against the east wall.  On the north wall is "+
"a glowing orb which keeps the room well lit.\n");
   set_light(100);
add_exit("down", ROOM+"director", "door");
add_alias("books","book");
add_item ("desk","This is an old mahogany desk.  "+
"On the far left corner "+
"there is a beeswax candle burning.  There is quite a bit of paperwork "+
"that clutter the desk.\n");
add_item ("paperwork",
"The pile of paperwork is very big, so you just glance at the top couple "+
"layers.  "+
"There are applications to the guild, "+
"guild member reviews and various other "+
"documents.\n");
add_item("candle","You can smell the honey fragrance coming from the beeswax "+
"candle.  You begin to wonder if that is where they get the phrase "+
"'Sweetness and Light'.\n");
add_item ("mirror","Looking at yourself again?  What a narcissist!\n"+
"It doesn't look like you have aged at all since the last time you looked "+
"in the mirror.  So you finally pull yourself away from the mirror.\n");
add_item ("bookcase","It is filled with tons of books.\n");
add_item ("chair","This chair is really a comfortable chair to sit on.\n");
add_item ("book","As you glance at the titles of the various books lying "+
"on the shelf.  You don't see any books that you have read before.\nBut "+
"wait!!!  Where did that come from?\n"+
"Your favorite book that you have ever read is lying on the shelf, now.\n");
add_item ("dome","You see a beautiful view of the sky.  You see several "+
"birds flying overhead. *splat*  Oh, well, looks like we have to send "+
"someone out there to clean it.  *grin*\n");
add_item ("orb","This orb keeps the room at a constant light intensity.  "+
"*hopes you don't decide to take it apart to see how it works, because they "+
"don't make these anymore* *grin*\n");
   set_co_ord( ({ -2, -1, 1 }) );
}
sit(arg)
{
if(!arg=="chair"){
return;}
write("You sit in the comfy chair and start to doze off.\n"+
"You dream of battles to come and of that special person in your life.\n"+
"You wake feeling refreshed and ready for the new day.\n");
say (this_player()->query_cap_name()+" crashes in the guildmaster's chair.\n");
return 1;
}

