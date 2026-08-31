#include <std.h>
#include <guild.h>

inherit ROOM;
void init() {
    ::init();
    add_action("read", "read");
    add_action("pray", "pray");
}
void create() {
    ::create();
     set_name("prayer");
     set_short("AoD prayer room");
     set_long("%^BOLD%^%^BLACK%^Thousands of r%^RED%^e%^BLACK%^d tinted candles line the walls and alcoves of "
"%^BOLD%^%^BLACK%^this room. A soft hu%^WHITE%^mm%^BLACK%^ing noise can be heard, seeming to "
"%^BOLD%^%^BLACK%^em%^WHITE%^i%^RED%^n%^BLACK%^ate from the statue at the far end of the room. The "
"%^BOLD%^%^BLACK%^monument depicts a gr%^RED%^ue%^BLACK%^some scene wherein a knight holds the "
"%^BOLD%^%^BLACK%^h%^RED%^ea%^BLACK%^d of his enemy in one ou%^RED%^tst%^WHITE%^re%^RED%^tc%^BLACK%^hed hand, and in the other "
"%^BOLD%^%^BLACK%^his s%^WHITE%^w%^RED%^o%^WHITE%^r%^BLACK%^d dri%^RED%^pp%^BLACK%^ing with b%^RED%^loo%^BLACK%^d. A plaque "
"%^BOLD%^%^BLACK%^has been placed at the foot of the statue. ");
 set_properties( ([ "no attack"   : 1,
                    "no magic"    : 1,
                    "no bump"     : 1,
                    "light"       : 2,
                    "night light" : 2,
		    "no teleport" : 1,
		    "no scry" : 1,
		    "indoors" : 1,
                    "no steal"    : 1 ]) );


 set_exits( (["east" : ROOMS"AoD/lockeraod",
              "down" : ROOMS"AoD/portal" ]) );

}

int read(string str) {
    if(!str) {

        notify_fail("Read what?\n");
        return 0;
    }
    if(str != "plaque" && str != "Plaque") {
        notify_fail("That is not here.\n");
        return 0;
    }
    write("%^BOLD%^%^BLACK%^Here stands Br%^RED%^u%^BLACK%^ce %^RED%^I%^BLACK%^, the original D%^WHITE%^a%^RED%^r%^BLACK%^k Kn%^WHITE%^ig%^BLACK%^ht of the R%^RED%^os%^BLACK%^e. We pledge "
"%^BOLD%^%^BLACK%^to never forget his courage and b%^WHITE%^ra%^RED%^v%^WHITE%^er%^BLACK%^y in battle. Remember the face of your "
"%^BOLD%^%^BLACK%^father, pray to him if you are worthy and the rew%^RED%^ar%^BLACK%^ds shall be great indeed.");
     return 1;
}
int pray() {
    int x;
    x = this_player()->query_max_hp() - this_player()->query_hp();
    this_player()->add_hp(x);
    x = this_player()->query_max_sp() - this_player()->query_sp();
    this_player()->add_sp(x);
    x = this_player()->query_max_mp() - this_player()->query_mp();
    this_player()->add_mp(x);
    this_player()->set_paralyzed(10);
    write("You are held in prayer.");
    return 1;
}
