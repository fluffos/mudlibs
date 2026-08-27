/* source file for room -- Temple of Vhaeraun */
#include "path.h"

inherit "/std/room";

void setup()
{
  set_short("Temple");
  set_long("The room is black and silent.  The only source of light is a "+
    "serene and inspiring statue approximately sixteen feet tall and "+
    "outlined in the dim rainbow colored radiance of faerie fire.  It stands "+
    "over an altar at the opposite end of the nave in the apse of the "+
    "temple.  The central aisle is flanked by two rows of columns and the "+
    "walls have "+
    "been meticulously sculpted into flowing waves of ebony designed to "+
    "radiate from the statue.  The ceiling is lit with the glittering "+
    "starshine of a cloudless, clear night sky.  Still, your eyes are drawn "+
    "to the vigilant figure of the Masked Lord...\n");
          /* items */
  add_item("statue", "The shimmering statue is of a youthful and handsome "+
    "male dark elf.  The leering expression upon his face is hidden by a "+
    "small mask and his muscular body is concealed by a flowing black "+
    "cloak.  His eyes glow brightly with his disposition as the "+
    "hue of his hair wavers with emotion.\n");
  add_item(({"black cloak", "cloak"}),
    "The flowing black cloak has a remarkable camoflauge effect.  As you "+
    "look towards it, the cloak either becomes transparent or it melds into "+
    "a visage of its background.  Behind it you see the stars of the night "+
    "sky.\n");
  add_item(({"black mask", "half mask", "mask"}),
    "The black velvet mask is embroidered with gold.  It covers the eyes "+
    "and curves down over the cheecks being fashioned somewhat like wings.\n");
  add_item(({"floor", "aisle"}),
    "The floor is fashioned from black marble and is scattered with mosaics "+
    "and holy runes.  It is shot throughout with red and purple bolts of "+
    "lightning.\n");
  add_item(({"runes", "mosaics"}),
    "The intricate and delicate runes are inscribed around the mosaics.  "+
    "Each one of the mosaics depicts worshipers following the customs of "+
    "the Masked Lord.\n");
  add_item("altar", "The altar is used for the sacrifice of stolen magical "+
    "items and other treasures.  Occasionally, a priestess of the Spider "+
    "Goddess is sacrificed on this altar long before she actually "+
    "dies.\n");
  add_item(({"ceiling", "roof", "stars", "sky", "night"}),
    "Overhead, the stars twinkle brightly as they slowly cross the night "+
    "sky.  The moon eternally cycles through its phases to rise once more "+
    "each night.  Every hour or so, an unnatural rippling dark tide douses "+
    "the night lights only to reemerge as if nothing happened.\n");
  add_item(({"column", "columns"}),
    "The spiral-fluted columns are over ten feet tall and capped with "+
    "golden capitals.  They seemingly support nothing but the heavens.\n");
  set_light(20);
          /* exits */
  add_exit("out", ROOM + "hall4", "door");
/* removed cos it's a pain in the ass, Taniwha 1995 */
  //call_out("do_event", 0, 0);
}

int do_event() {
  switch (random(10))
  {
    case 0:
      say("A shooting star streaks across the heavenly ceiling.\n");
      break;
    case 1:
      say("A surge of glowing magical energy pours forth from "+
        "the altar and alights the floor and walls with streaks "+
        "of lightning.\n");
      break;
    case 2:
      say("The eyes and hair of the serene statue suddenly flare "+
        "into a brilliant gold hue.\n");
      break;
    case 3:
      say("A wave of darkness ripples forth from the statue "+
        "dousing the stars and plunging the room in darkness, "+
        "then slowly, the room brightens again.\n");
      break;
    case 4:
      say("You hear an unnerving voice and rapidly turn to find "+
        "nothing.\n");
      break;
    default:
  }
  call_out("do_event", random(60), 0);
  return 1;
}

