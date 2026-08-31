#include <swamp.h>
#include <std.h>
// seeker
inherit ROOM;
object board;
int ghast;
int cmd_start(string str);
void init()
{
 ::init();
 add_action("cmd_start", "start"); 
add_action("pray_asmodeus" , "pray");
}
void create() {
    ::create();
    set_properties( ([ "light":2,
                       "night light":2, 
                       "no steal":1,
                       "no bump":1, 
                       "no castle":1,
]) );
set_items(([
"statue": "The statue of the lord of demons, %^BOLD%^BLACK%^Asmodeus%^RESET%^.",
]));
set_listen("default", "The town square is noisy from the sounds of busy Merkkirri going about their business.");
set_short("%^YELLOW%^Quixxiol Square%^RESET%^");
set_long("%^YELLOW%^You stand in the city square of Quixxiol, the Lost city of Gold.  Here the four major roads of the city converge.  The Merkkirri have kept this city hidden from outsiders for ages.  Shops and houses line the streets and to the far west you see a golden palace.%^RESET%^"); 
    set_exits( 
([
]));
}
void reset() {
 ::reset();
/*if (!find_living("ghast40") || !environment(find_living("ghast40")))


     {
       new(MOB "ghast")->move(this_object());
     ghast=1;
    }
*/
 
}
int cmd_start(string str)
{
 if (!str || str=="") 
   {
    notify_fail("Start where?\n");
    return 0;
   }

 if (str!="here")
   {
    notify_fail("You cant start there.\n");
    return 0;
   }

 write("You are now set to start here.");
 return 1;
}

int pray_asmodeus(string what) {
if (what!= "to asmodeus")  return 1;

write("You feel a cold chill down your spine.");
this_player()->add_alignment(-10);
if (this_player()->query_level() > 49 &&
   this_player()->query_subclass() != "light" &&
   this_player()->query_subclass()!="paladin" &&
   this_player()->query_class()!="cleric"  &&
  this_player()->query_alignment() < -1000) {
    return 1;
}
}
