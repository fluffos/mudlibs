#include <std.h>
#include "../../serakii.h"


inherit VAULT;

void create(){
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_name("guest room");
   set_short("%^C059%^guest room%^CRST%^");
 set_long("This good sized room is dominated by the large canopied %^C058%^four poster bed%^CRST%^ immediately next to the door, flanked by a pair of %^C094%^side tables%^CRST%^. The ceiling slopes in part of the space, with %^C094%^thick wooden beams%^CRST%^ bracing the roof above. A %^C240%^fireplace %^CRST%^shares a wall with the room next door, its %^C059%^rough wooden mantel%^CRST%^ echoing the solidness of the roof braces above. Nearby, a %^C094%^turned chair%^CRST%^ with %^C064%^rush woven seat%^CRST%^ stands ready for guests to relax and enjoy the warmth of the %^C124%^fire%^CRST%^. At the far end two large %^C247%^leaded glass windows%^CRST%^ flank a %^C094%^tall dresser%^CRST%^ and the %^C031%^painting %^CRST%^hung above; a %^C094%^wooden divider%^CRST%^ offers privacy for those changing or washing up in the corner nearby. The walls are plastered in a %^C254%^crisp white%^CRST%^, while the floors consist of broad, hand-hewn %^C094%^planks%^CRST%^, covered by a %^C187%^cream woolen rug%^CRST%^ with woven designs of %^C074%^steel blue%^CRST%^.\n");

set_items(([
    ({"bed"}) : "%^C094%^A solid oak bed with four heavy posts that support thick tapestry drapes and a canopy in hues of blue and white. It could easily hold three human-sized individuals, and is long to accomodate taller folks. Smaller guests may appreciate the stepladder pushed up against one side to climb onto the tall mattress. The linens are crisp and fresh, with the faintest scent of lavendar clinging to the fabric. A multitude of pillows rests overtop a blue quilt of wholecloth linen, its stitched and raised motiefs depicting ocean waves%^CRST%^.",
	({"fireplace"}) : "%^C243%^A small fireplace is built into the interior wall, a small wooden chair of turned spindles and woven rush seat nearby. Its mantel and facing consists of unadorned, rough-hewn beams that support the plastered brickwork of the chimney. A rustic stoneware vase with white and blue glaze sits atop the mantle with a pair of plain brass candlesticks, and holds a bouquet of seasonal flowers or greenery.%^CRST%^",
	({"divider"}) : "%^C058%^A plain wooden divider stands in one corner, screening a wash stand with pitcher, bowl, and a small mirror. Towels and wash cloths are folded neatly on a shelf below the tabletop, and a simple stool rests against one wall.%^CRST%^",
	({"window"}) : "%^C159%^Diamond shaped panes of beveled and leaded glass fill a pair of double casement windows along the outside wall. The decorative spring latch is cast in brass, with an elegant lily motief. The windows can be opened outwards to enjoy fresh air and, seasonally, the flowerbox hung outside. Alternatively, thick wooden shutters can be closed at night to offer privacy and keep the chill at bay. A tall wooden dresser sits between them, with a painting hanging overhead.%^CRST%^",
	({"painting"}) : "%^C066%^This painting portrays a singular individual at the moment of his death. Brighter colours are used to subtly highlight the central figure's heroism, while the rest of the painting is rendered in muted, earthy pigments. The tableau vivant is set at the nearby crossroads; an army of Oni, black-clad humans, and demons approach from one side, while a white tower and shining city can be seen in the distance. What should be a very solid stone building at the crossroads has a ghost-like appearance, trees vaguely visible through it with edges blurred and ill-defined. The man in question hangs in the air, slender body arched and impaled on a long polearm wielded by an Oni, its vicious grin unnaturally wide. Great care has been taken with the details of the hero's expression to convey the depth and feeling of his pain and determination. One hand clutches at the blade of the partizan as it emerges from his chest, the etched metal of it gleaming with silverleaf under the vibrant vermillion of his blood; the other reaches back towards the inn as if warding it somehow. If one looks very carefully, one can spot the hint of terrified faces watching on from the windows. One of the invaders stands near this incorporeal building, a look of suspicion and confusion on her face as she seeks something she cannot find. A plaque written in common reads 'Marcello's Last Stand'.%^CRST%^",
]));


set_smell("default","%^C059%^The room smells of an odd combination of woodsmoke and rose water.%^CRST%^");
set_listen("default","%^C059%^The fire crackles and pops, while muted sounds of laughter and conversation drift up from the tavern below.%^CRST%^");



    set_exits(([
                   "hall" : INN"landing",

        ]));

    set_door("red door", INN"landing", "hall",0);
	set_door_description("red door","%^C160%^This door has been painted red%^CRST%^");
	
}