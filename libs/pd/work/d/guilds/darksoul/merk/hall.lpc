#include <std.h>
#include <guild.h>
#include <mjungle.h>

inherit ROOM;
void create() {
    ::create();

    set_properties(([ "light":1, "night light":1, "no steal":1,
	"no bump":1, "no scry":1, "no gate":1, "no castle":1, "no attack":1,
	"no teleport":1 ]));
    set_name("Darksouls Hall");
    set_short("darksouls on merk");
    set_long("%^BOLD%^%^BLACK%^This is the meeting spot of the "
      "D%^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^r%^BOLD%^%^WHITE%^k%^BOLD%^%^BLACK%^ "
      "S%^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^u%^BOLD%^%^WHITE%^l%^BOLD%^%^BLACK%^s. "
      "%^BOLD%^%^BLACK%^This is where %^BOLD%^%^BLACK%^they come to go over the kills of the day, "
      "%^BOLD%^%^BLACK%^or problems that %^BOLD%^%^BLACK%^have arisen in the guild. Tons of "
      "%^BOLD%^%^BLACK%^corpses are strewn %^BOLD%^%^BLACK%^haphazardly on the floor. Pools of "
      "%^RESET%^%^RED%^blood%^BOLD%^%^BLACK%^ are all over the %^BOLD%^%^BLACK%^ground. The message "
      "%^BOLD%^%^BLACK%^for all people who are not part of this %^BOLD%^%^BLACK%^group that happen "
      "%^BOLD%^%^BLACK%^to set foot in here is %^BOLD%^%^WHITE%^You Do Not Have To "
      "%^BOLD%^%^WHITE%^Fear Us Unless You Are Alive.");
    set_exits(([ "west" : MJUNGLE"mjungle12" ]));
}
