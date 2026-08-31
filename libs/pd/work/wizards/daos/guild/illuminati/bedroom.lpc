#include <std.h>

inherit ROOM;

void create() {
    ::create();

    set_short("Peaceful Bliss");
    set_long("%^BOLD%^%^WHITE%^As you enter this room, you notice the cathedral ceiling.  The marble walls give the perfect accent to the canopy bed, which is draped with a lacy covering.  Although this room is beautiful to the site, there seems to be something very out of the ordinary; a framed %^GREEN%^S%^RESET%^%^GREEN%^a%^BOLD%^%^GREEN%^sh %^RESET%^%^GREEN%^o%^BOLD%^%^GREEN%^f th%^RESET%^%^GREEN%^e %^BOLD%^%^GREEN%^F%^RESET%^%^GREEN%^o%^BOLD%^%^GREEN%^r%^RESET%^%^GREEN%^e%^BOLD%^%^GREEN%^st%^WHITE%^, which is mounted along the far end of the room.  Moving closer to it, you realize that this is not the only strange thing around.  A tunic made from the skin of a demon, glass spheres, diamonds, belts, armour, crests, anything imaginable can be seen in this room.  It is clear that Carina has fought many battles and accumulated many %^CYAN%^treasures %^WHITE%^throughout her journeys in this realm.");
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
    set_exits( (["down" : "/d/guilds/illuminati/rooms/fighterh",
	"tirun" : "/d/nopk/tirun/square"]) );
    set_smell("default", "%^WHITE%^You smell a mixture of %^MAGENTA%^sweet %^WHITE%^perfume mixed with that of the %^RESET%^%^RED%^f%^BOLD%^%^RED%^i%^RESET%^%^RED%^r%^BOLD%^%^RED%^e%^WHITE%^.");
    set_listen("default", "%^CYAN%^The room echoes.");
}

void reset() {
    if (!present("fireplace")) {
	new("/wizards/daos/guild/illuminati/fireplace")->move(this_object());
    }
}
