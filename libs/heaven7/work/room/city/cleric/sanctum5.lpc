/* High Clerists Tower - sanctum5.c
 * Angel October 1993
 */

inherit "inherit/room2";
reset(arg) {


  if(arg) return;

  set_short("a small quiet sanctum");
  set_long(
  "This is a small room, quiet and peaceful. On the ground is a small \n"+
  "velvet cushions before a small altar. Beside it are small white  \n");

  set_items(({
     "candle#candles",
	"A few small white candles stand lit beside the altar",

	"cushion",
	"A small velvet cushion. It looks like you wound kneel on it",

	"altar",
	"A small altar, similar to the one in the large chamber to the "+
	"east",

     "floor#marble#reflection",
          "You can see yourself in the reflection in the higly polished "+
          "marble floor",

     "light#lights#magical lights#magical light#globe of light#globe",
          "A small orb of light atop a silver stand sits in the corner",

     "woolen rug#woven rug#rug",
          "A fine blue and silver rug sits in the middle of the floor",

     "pedestal#small pedestal",
          "A silver pedestal which supports a small globe of light"
  }));

  set_weather(1, 1, 0);

  set_exits(({
     "room/city/cleric/hall5", "west"
  }));
}     
