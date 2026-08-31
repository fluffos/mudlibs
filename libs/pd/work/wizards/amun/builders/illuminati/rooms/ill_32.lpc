#include <std.h>
#include <guild.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_properties(([  "no attack" : 1, "no magic" : 1, "no bump" : 1, "light" : 2, "no scry" : 1, "indoors" : 1, "no steal" : 1 ]));
    set_short("Peaceful Bliss");
    set_long("%^BOLD%^%^WHITE%^This is the bedroom of %^YELLOW%^Goldenberry%^WHITE%^. Many things can be seen around this room; a pair of wings lay upon a bed, some spare %^YELLOW%^h%^RESET%^%^ORANGE%^a%^BOLD%^%^YELLOW%^lo's%^WHITE%^ hang floating in mid air, as well as many other strange things this %^YELLOW%^Angel %^WHITE%^has accumulated throughout the years. There is a bear skin rug laid at the foot of the bed, which was a gift to %^YELLOW%^Goldenberry %^WHITE%^from her ranger friend. This is a beautiful room, with vaulted ceilings and open windows allowing the %^CYAN%^fresh air%^WHITE%^ to flow through. Even though the %^CYAN%^wind%^WHITE%^ blows through at a brisk pace, the %^RESET%^%^RED%^f%^ORANGE%^i%^BOLD%^%^BLACK%^r%^RED%^e %^WHITE%^seems to be roaring nicely. %^YELLOW%^Goldenberry %^WHITE%^loves the earth and protecting those under the name of God.%^RESET%^");
    set_items( (["ceiling" : "The ceiling, which is being held up by large columns, is something you would see in a Cathedral.  With %^MAGENTA%^pa%^CYAN%^in%^RESET%^%^MAGENTA%^ti%^BOLD%^GREEN%^ng%^YELLOW%^s%^WHITE%^ reaching from one wall to the other, this bedroom seems huge.",
	"walls" : "%^BOLD%^%^WHITE%^The walls are made of marble.",
	"sash" : "%^BOLD%^%^WHITE%^This sash was made for the %^YELLOW%^Lady%^WHITE%^ of the %^RESET%^%^GREEN%^F%^BOLD%^%^GREEN%^o%^RESET%^%^GREEN%^r%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^st%^BOLD%^%^WHITE%^.",
	"tunic" : "%^BOLD%^%^BLACK%^This Tunic was formed from the skin of a demon.",
	"spheres" : "%^BOLD%^%^WHITE%^A perfect sphere of glass. The inside is flawless and so clear as to be almost invisible.",
	"diamonds" : "%^BOLD%^%^WHITE%^This is a black diamond of immense size.  You could easily sell it for a hefty price.",
	"belts" : "%^BOLD%^%^WHITE%^You see a %^RED%^Ruby Red Belt%^WHITE%^ and a %^BLACK%^Sk%^WHITE%^u%^BLACK%^ll b%^WHITE%^e%^BLACK%^lt%^WHITE%^.  The %^RED%^Ruby Red Belt%^WHITE%^ is a large %^RED%^red %^WHITE%^belt with a %^RED%^ruby %^WHITE%^where the buckle is, the %^RED%^ruby %^WHITE%^is deep %^RESET%^%^RED%^red%^BOLD%^%^WHITE%^ in color, and rather large; and the %^BLACK%^Sk%^WHITE%^u%^BLACK%^ll b%^WHITE%^e%^BLACK%^lt%^WHITE%^ is lined with crystal %^BLACK%^Sk%^WHITE%^u%^BLACK%^lls%^WHITE%^ that seem to "
	"be moving.",
	"skulls" : "%^BOLD%^%^WHITE%^You notice the moving heads on this %^BLACK%^b%^WHITE%^e%^BLACK%^lt%^WHITE%^ are actually the heads of those whom Carina has %^BLACK%^k%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^ll%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^d%^WHITE%^, they are: %^RED%^Tauran%^WHITE%^, %^RED%^Descartes%^WHITE%^, %^RED%^Ryudo%^WHITE%^, %^RED%^Cenn%^WHITE%^, %^RED%^Rueznor%^WHITE%^,%^RED%^ Marek %^WHITE%^and %^RED%^Dubbya%^WHITE%^.",
	"armour" : "%^BOLD%^%^WHITE%^There are too many blankets of armour here for you to see straight.",
	"crest" : "%^BOLD%^%^WHITE%^This is the %^YELLOW%^Golden Crest %^WHITE%^for the guild of the Illuminati; which is the true guild that fights for the %^YELLOW%^L%^WHITE%^i%^YELLOW%^ght%^WHITE%^.",
	"fireplace" : "%^BOLD%^%^WHITE%^This cobblestone %^BLACK%^f%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^pl%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^e%^BOLD%^%^WHITE%^ is placed at the foot of the king-sized bed.  It stretches 8 feet wide and about 20 feet high the wall allowing the %^RESET%^%^RED%^fl%^BOLD%^%^RED%^a%^RESET%^%^RED%^m%^BOLD%^%^RED%^e%^RESET%^%^RED%^s%^BOLD%^%^WHITE%^ to stretch far and wide.  Laid in front of the %^BLACK%^f%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^pl%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^e%^BOLD%^%^WHITE%^  is a white bear skin rug that was made by Carina. The crackling %^RESET%^%^RED%^f%^BOLD%^%^RED%^i%^RESET%^%^RED%^r%^BOLD%^%^RED%^e%^WHITE%^ looks romantic as it dances across the walls.  You should warm yourself beside it.",
	"rug" : "%^BOLD%^%^WHITE%^This white bear skin rug was foraged from the White Bears in Roston and is big enough for everyone in this realm to sleep on.  The soft fur makes it hard for you to resist laying on it.",
	"bed" : "%^BOLD%^%^WHITE%^This king-size canopy bed adds to the %^CYAN%^atmosphere%^WHITE%^ of the room.  There are lacy drapes flowing down each of the corners providing the perfect accent."]) );
    set_exits( (["south" : GUILDROOM+"bedroom_main", "tirun" : "/d/nopk/tirun/square"]) );
    set_smell("default", "%^WHITE%^You smell a mixture of %^MAGENTA%^sweet %^WHITE%^perfume mixed with that of the %^RESET%^%^RED%^f%^BOLD%^%^RED%^i%^RESET%^%^RED%^r%^BOLD%^%^RED%^e%^WHITE%^.");
    set_exits( (["west" : ILLROOM "ill_31", "furiae" : ILLROOM "ill_35"]) );
    set_smell("default", "%^WHITE%^You smell a mixture of %^MAGENTA%^sweet %^WHITE%^perfume mixed with that of the %^RESET%^%^RED%^f%^BOLD%^%^RED%^i%^RESET%^%^RED%^r%^BOLD%^%^RED%^e%^WHITE%^.");
    set_properties((["light": 3, "night light": 3]));
    set_listen("default", "%^CYAN%^The room echoes.");
}
void reset() {
    if (!present("fire")) {
	new(ILLOBJ "fireplace")->move(this_object());
    }
}
