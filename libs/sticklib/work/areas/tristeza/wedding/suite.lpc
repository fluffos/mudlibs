
#include <room.h>
#include "weddings.h"
#define TP this_player()
inherit "basic/misc/emote";   


void
create_room(){

    set_light_level(LT_LIGHTS);
    set(ROOM_WD,WD_INDOORS);
    set_short("The infamous honeymoon suite");
    set_long("This is the infamous honeymoon suite. The centerpiece \
of the room is an antique canopy bed. The white sheer curtains draped \
over and around the four carved bed posts, give the bed a romantic \
appeal. On either side of the bed a table sits and setting upon each \
of the tables there must be at least a dozen white candles of various \
sizes and shapes. In the back of the room there is a bay window and a \
sitting area, with a loveseat. In front of the loveseat a coffee table is \
set with a light snack for two. Next to the bay window French \
doors open out onto a cement balcony.  One side of the room is dominated \
by an extra large white marble fireplace. A plush bear skin rug is \
spread out before the fire.\n\
Try <helpsuite>.");
    set_items(([
	"snack":"There is a bottle champagne, chilling in an \
ice bucket, and a food basket with an array of cheeses, crackers, and \
fruits.",
	({"view","balcony"}):"The view from the \
balcony resembles what it must have looked like to see the garden of \
Eden from above. There are numerous budding trees and blossoming \
flowers. You can see a rose garden that must have a rose bush of every \
color possible. If your not mistake, there is even a slight hint \
of a splendid rainbow appearing and then disappearing into the blue ocean \
behind the garden.",
	"bed":"This bed was specially created to be magnificently \
comfortable and more than large enough for a king and his newly \
betrothed queen.",
	({"sitting area","loveseat","coffee table","window"}):
	"The overstuffed emerald green crushed velvet lovseat and glass coffee \
table create a quaint sitting area beneath a set of huge bay windows."
      ]));

    set_exits((["town":"/room/church"]));
    set_commands(([
	"helpsuite":"helpsuite",
	"emote":"emote_cmd"
      ]));
}


helpsuite(){
    TP->tell_me("This suite was coded for honeymooning couples. \
At this time there are no extra feeling commands in the room. The \
mood created here is merely based on each couples inventive emote \
style. Maybe in the future I'll add a couple of extra feelings to \
merely set the mood.\n\
NOTE: THESE DO NOT WORK YET!\n\
dim = dims the lights\n\
candles = lights the candles\n\
music = plays music\n\
menu = gives you a list of available foods\n\
feed = feeds food to your partner\n\
over = when the honeymoon is over and you would like to return to town\n\
\n\
That's all I can think of as of now. Guess, I'll have to do a bit \
of research.\n\
Best Wishes,\n\
Minx");
    return 1;
}
