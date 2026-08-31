#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_short("Open Room");
    set_long("%^BOLD%^%^WHITE%^It is dimly%^RESET%^ %^BOLD%^%^YELLOW%^l"
      "%^WHITE%^i%^YELLOW%^t%^WHITE%^RESET%^.\n"
      "%^BOLD%^%^WHITE%^As you come into the room, you notice a basin "
      "laid in front of you, stairs all around you, %^BLACK%^c%^YELLOW%^"
      "a%^BLACK%^ndl%^YELLOW%^e%^BLACK%^s%^RESET%^ %^BOLD%^WHITE%^%^floating and a "
      "waterfall trickling down behind the basin.  Gazing through this waterfall, "
      "you see a %^RESET%^%^ORANGE%^w%^RED%^o%^RESET%^%^ORANGE%^oded b%^RED%^r"
      "%^RESET%^%^ORANGE%^idge %^BOLD%^%^WHITE%^curved over a %^%^BLUE%^r%^CYAN%^i"
      "%^BLUE%^v%^CYAN%^e%^BLUE%^r %^WHITE%^to the other side of land.  You walk "
      "through the %^BLUE%^wat%^CYAN%^erf%^BLUE%^all%^WHITE%^ and notice that even "
      "though water is running over you, you are not dampened.  Stopping in "
      "awe, your eyes fall upon a house laid within a tree.  Feeling that your eyes "
      "are cheated by some spell, you begin to climb marble stairs that glow "
      "white.  Climbing further and further, you notice the marble columns and the "
      "tree branches coming together to make this house beautiful.  Looking to the "
      "left, you see a gazebo, which looks as if it is floating in the air; and to "
      "the right, you notice a massive %^RESET%^%^GREEN%^tree %^ORANGE%^branch "
      "%^BOLD%^%^WHITE%^holding up what looks like a small nook for animals to "
      "sleep.  You reach the top of the stairs and you notice two doors standing in "
      "front of you.");
    set_items( (["basin" : "%^BOLD%^%^WHITE%^This %^BLACK%^b%^RESET%^%^WHITE%^a"
	"%^BOLD%^%^BLACK%^s%^RESET%^%^WHITE%^i%^BOLD%^%^BLACK%^n%^WHITE%^, which is "
	"filled with %^BLUE%^w%^CYAN%^a%^BLUE%^t%^CYAN%^e%^BLUE%^r%^WHITE%^, is held "
	"up by a short co%^RESET%^%^WHITE%^lu%^BOLD%^%^WHITE%^mn made of %^RESET%^"
	"%^WHITE%^st%^BOLD%^%^WHITE%^o%^RESET%^%^WHITE%^ne%^BOLD%^%^WHITE%^, and is "
	"positioned within a dip in the %^RESET%^%^WHITE%^st%^BOLD%^%^WHITE%^o%^RESET%^"
	"%^WHITE%^ne%^BOLD%^%^WHITE%^.  The %^BLACK%^b%^RESET%^%^WHITE%^a%^BOLD%^"
	"%^BLACK%^s%^RESET%^%^WHITE%^i%^BOLD%^%^BLACK%^n%^WHITE%^ is made with pure "
	"%^BLACK%^silver %^WHITE%^and %^BLACK%^g%^WHITE%^l%^BLACK%^i%^YELLOW%^st"
	"%^BLACK%^e%^WHITE%^n%^BLACK%^%^s %^WHITE%^in the %^BLUE%^mo%^WHITE%^on"
	"%^YELLOW%^li%^BLUE%^gh%^WHITE%^t from the %^BLUE%^s%^RESET%^%^BLUE%^k%^BOLD%^"
	"%^BLUE%^y%^WHITE%^.  Maybe you could find other people through this %^BLACK%^"
	"%^RESET%^%^WHITE%^a%^BOLD%^%^BLACK%^s%^RESET%^%^WHITE%^i%^BOLD%^%^BLACK%^n "
	"%^WHITE%^by find [player]",
	"stairs" :  "%^BOLD%^%^WHITE%^The stairs, made of %^RESET%^%^WHITE%^mar%^BOLD%^"
	"%^WHITE%^ble sto%^RESET%^%^WHITE%^nes%^BOLD%^%^WHITE%^, curve around the "
	"%^RESET%^%^ORANGE%^t%^RED%^r%^ORANGE%^u%^RED%^n%^ORANGE%^k %^BOLD%^%^WHITE%^of "
	"the %^RESET%^%^ORANGE%^t%^RED%^r%^ORANGE%^ee%^BOLD%^%^WHITE%^.  With Each "
	"step, the stair %^YELLOW%^glows bright %^WHITE%^white to guide your way.",
	"candles" : "%^BOLD%^%^WHITE%^White and %^YELLOW%^lit%^WHITE%^, the %^BLACK%^c"
	"%^YELLOW%^a%^BLACK%^ndl%^YELLOW%^e%^BLACK%^s %^WHITE%^are floating by %^CYAN%^ "
	"magic %^WHITE%^every 10 steps you take.  No %^RESET%^%^WHITE%^wax %^BOLD%^"
	"%^WHITE%^is falling, showing you these %^BLACK%^c%^YELLOW%^a%^BLACK%^ndl%^"
	"YELLOW%^e%^BLACK%^s %^WHITE%^are %^YELLOW%^e%^WHITE%^v%^YELLOW%^e%^WHITE%^r"
	"%^YELLOW%^l%^WHITE%^a%^YELLOW%^s%^WHITE%^t%^YELLOW%^i%^WHITE%^n%^YELLOW%^g"
	"%^WHITE%^.",
	"waterfall" : "%^BOLD%^%^WHITE%^The %^BLUE%^wat%^CYAN%^erf%^BLUE%^all %^WHITE%^ "
	"is flowing from the top of a %^RESET%^%^ORANGE%^c%^GREEN%^lif%^ORANGE%^f "
	"%^BOLD%^%^WHITE%^just above the cove you are walking through.  The only way "
	"to get to the %^RESET%^%^ORANGE%^b%^RED%^r%^RESET%^%^ORANGE%^idge %^BOLD%^"
	"%^WHITE%^is through this falling of %^BLUE%^w%^CYAN%^a%^BLUE%^t%^CYAN%^e%^BLUE"
	"%^r%^WHITE%^.",
	"bridge" : "%^BOLD%^%^WHITE%^This %^RESET%^%^ORANGE%^b%^RED%^r%^ORANGE%^idge"
	"%^BOLD%^%^WHITE%^ is here to help people and animals cross the %^BLUE%^r%^CYAN"
	"%^i%^BLUE%^v%^CYAN%^e%^BLUE%^r %^WHITE%^without having to swim.",
	"house" : "%^BOLD%^%^WHITE%^Although this house was build centuries ago, it "
	"looks as if it is newly crafted.  This is no ordinary %^RESET%^%^ORANGE%^t"
	"%^RED%^r%^ORANGE%^ee h%^RED%^o%^ORANGE%^use%^BOLD%^%^WHITE%^, but one that "
	"exuberates the use of fine %^BLACK%^craf%^YELLOW%^tsman%^BLACK%^ship and "
	"%^CYAN%^magic%^WHITE%^'%^CYAN%^s%^WHITE%^.",
	"tree" : "%^BOLD%^%^WHITE%^This gigantic %^RESET%^%^GREEN%^r%^ORANGE%^e%^RED%^"
	"d%^GREEN%^w%^RED%^o%^ORANGE%^o%^GREEN%^d %^BOLD%^%^WHITE%^stretches over 200 "
	"feet in the air and is holding a %^YELLOW%^b%^WHITE%^e%^YELLOW%^a%^WHITE%^u"
	"%^YELLOW%^t%^WHITE%^i%^YELLOW%^f%^WHITE%^u%^YELLOW%^l %^WHITE%^home.",
	"gazebo" : "%^BOLD%^%^WHITE%^This Gazebo, which has two separate br%^RESET%^"
	"%^WHITE%^i%^BOLD%^%^WHITE%^dg%^RESET%^%^WHITE%^e%^BOLD%^%^WHITE%^s attached "
	"to it, is suspended in the air and has flowing l%^RESET%^%^WHITE%^a%^BOLD%^"
	"%^WHITE%^c%^RESET%^%^WHITE%^e %^BOLD%^%^WHITE%^coverings and %^MAGENTA%^p"
	"%^CYAN%^i%^MAGENTA%^l%^CYAN%^l%^MAGENTA%^o%^CYAN%^w%^MAGENTA%^s %^WHITE%^laid "
	"in the middle.  %^BLACK%^C%^YELLOW%^a%^BLACK%^ndl%^YELLOW%^e%^BLACK%^s "
	"%^WHITE%^are placed on each pillar and the top is domed to a large opening "
	"allowing the %^BLUE%^s%^RESET%^%^BLUE%^k%^BOLD%^%^BLUE%^y %^WHITE%^to peek "
	"through.",
	"nook" : "%^BOLD%^%^WHITE%^This nook is a housing area for the animals of this "
	"homes owner's: Furiae and Carina.  There is a small %^RESET%^ORANGE%^t%^RED%^"
	"r%^ORANGE%^ee %^BOLD%^%^WHITE%^with a perch for the %^YELLOW%^Ph%^MAGENTA%^oe"
	"%^RED%^ni%^RESET%^%^MAGENTA%^x%^BOLD%^%^WHITE%^, %^GREEN%^Fawkes%^WHITE%^; "
	"and a small %^RESET%^%^GREEN%^g%^BOLD%^%^GREEN%^r%^RESET%^%^ORANGE%^as%^BOLD"
	"%^%^GREEN%^s%^RESET%^%^GREEN%^y %^BOLD%^%^WHITE%^looking area for the "
	"%^BLACK%^t%^WHITE%^i%^BLACK%^g%^WHITE%^e%^BLACK%^r%^WHITE%^, %^BLACK%^O"
	"%^WHITE%^t%^BLACK%^i%^WHITE%^s.  These two animals sleep %^YELLOW%^"
	"peacefully %^WHITE%^with one another every %^BLACK%^n%^RESET%^%^BLUE%^i"
	"%^BOLD%^%^BLACK%^g%^RESET%^%^BLUE%^h%^BOLD%^%^BLACK%^t%^WHITE%^.",
	"doors" : "%^BOLD%^%^WHITE%^There are two doors present, the one to the right "
	"reads '%^MAGENTA%^Carina%^WHITE%^', and the one to the left reads '%^GREEN%^"
	"Furiae%^WHITE%^'.  These doors take you to each owner's bedroom.",
	"sky" : "%^BOLD%^%^WHITE%^The %^YELLOW%^moon %^WHITE%^and st%^YELLOW%^a"
	"%^WHITE%^rs are the only %^YELLOW%^light %^WHITE%^the %^BLACK%^da%^RESET%^"
	"%^BLUE%^rk%^BOLD%^%^BLACK%^ene%^RESET%^%^BLUE%^d s%^BOLD%^%^BLACK%^ky "
	"%^BOLD%^%^WHITE%^sees.  Even when it is %^YELLOW%^day%^WHITE%^li%^YELLOW%^"
	"ght %^WHITE%^in the mortal realm, it is always %^BLACK%^n%^RESET%^%^BLUE%^i"
	"%^BOLD%^%^BLACK%^g%^RESET%^%^BLUE%^h%^BOLD%^%^BLACK%^t %^WHITE%^here; as the "
	"owner's of this house love the %^BLACK%^n%^RESET%^%^BLUE%^i%^BOLD%^%^BLACK%^"
	"g%^RESET%^%^BLUE%^h%^BOLD%^%^BLACK%^t %^WHITE%^life."]) );
    set_smell("default", "%^BOLD%^%^WHITE%^You smell the %^RESET%^%^ORANGE%^t%^RED%^"
      "r%^ORANGE%^ees %^BOLD%^%^WHITE%^of the %^GREEN%^fo%^RESET%^%^GREEN%^re%^BOLD%^"
      "%^GREEN%^st %^WHITE%^all around you.");
    set_listen("default", "%^BOLD%^%^WHITE%^The room echoes with the sound of the "
      "%^BLUE%^r%^CYAN%^i%^BLUE%^v%^CYAN%^e%^BLUE%^r %^WHITE%^below.");
    set_exits( (["carina" : "/d/guilds/illuminati/rooms/goldenberry",
	"furiae" : "/d/guilds/illuminati/rooms/furiae"]) );
}
