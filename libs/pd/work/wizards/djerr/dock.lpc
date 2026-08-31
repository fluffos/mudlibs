#include <std.h>
inherit ROOM;

void create(){
 ::create();
   set_short("Faerie Village Dock");

   set_day_long("There is a long wooden dock where several boats are moored.  "
      "The dock seems to be perfectly constructed, as though not by hands.  "
      "There is a large portcullis to the east behind the fishermans' warf, "
      "it is currently open.  The portcullis and the gatehouses are made of "
      "what looks like white marble and gold, in fact, the whole city appears "
      "to shimmer as though made of this white marble and gold.");

   set_night_long("There is a glow emminating from the walls of the city, as "
      "if it had residual sunlight stored within the very marble.  The gold "
      "reflects the glow, beckening as a lighthouse to all who come near.  "
      "You can see a closed portcullis past the fisherman's warf that shines "
      "as if of the same gold");

   set_items((["stone":"The stone is a soft white marble that seems to store and "
      "the suns rays and glow with the energy.",

      "dock":"The dock is flawless in construction, it would not be unwise to "
      "assume that it was made using magic.",

      "gold":"The marble has gold runes inscribed in it and carvings within the marble "
      "are inlaid with gold.  The very portcullis appears to be made of gold.",

      "gatehouse":"The gatehouse contains the portcullis.  As with the portcullis, "
      "the door trimmings, handles and knobs are all made of gold.  There are several "
      "guards milling about the gatehouse.",

      "glow":"The glow seems to be reflected rays of the sun, incredible to behold.",

      "portcullis":"The portcullis seems to be made of gold, but at this distance, "
      "it is unlikely that you can tell for certain."]));

   set_properties((["light":3,"night_light":1]));

   set_exits((["northeast":ROOMS"nets","east":ROOMS"fish","southest":trade"]));
}

