// Chernobog & Titania (2/7/22)
// The Wailing Isle - Outside the Watermill

#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){
    ::create();
    set_terrain(LIGHT_FOREST);
    set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_property("indoors", 0);
    set_name("outside a watermill");
    set_short("%^RESET%^%^CRST%^%^C037%^outside a watermill%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C037%^Fed by a %^C039%^qu%^C045%^ic%^C051%^kl%^C039%^y f%^C045%^lo%^C051%^wi%^C039%^ng %^C045%^ri%^C051%^ve%^C039%^r%^RESET%^%^C037%^, a %^C101%^w%^C102%^o%^C101%^od%^C102%^e%^C101%^n %^C102%^w%^C103%^a%^C102%^t%^C101%^erwh%^C102%^e%^C103%^e%^C102%^l%^RESET%^%^C037%^ churns about in these %^C030%^tu%^C023%^mu%^C030%^lt%^C023%^uo%^C030%^us %^C023%^wa%^C030%^te%^C023%^rs%^RESET%^%^C037%^, supplying power to an otherwise abandoned %^C059%^s%^C243%^ma%^C059%^ll s%^C243%^to%^C059%^ne m%^C243%^i%^C059%^ll%^RESET%^%^C037%^. The splashing of the distant %^C038%^waterfall%^C037%^ echoes through the %^C035%^ve%^C034%^ge%^C040%^ta%^C041%^ti%^C035%^on%^RESET%^%^C037%^, accompanied by the groaning of the %^C101%^old wheel%^C037%^ as it paddles the %^C045%^c%^C039%^o%^C045%^ld%^RESET%^%^C037%^, %^C045%^cl%^C039%^ea%^C045%^r w%^C039%^at%^C045%^er%^RESET%^%^C037%^. The %^C255%^w%^C250%^h%^C255%^it%^C250%^e w%^C255%^al%^C250%^ls%^RESET%^%^C037%^ of the %^C255%^cl%^C250%^if%^C255%^fs%^RESET%^%^C037%^ fall away to a %^C040%^l%^C046%^u%^C082%^s%^C076%^h %^C070%^f%^C071%^o%^C077%^r%^C083%^e%^C047%^s%^C041%^t%^RESET%^%^C037%^ to the south, the %^C118%^fo%^C119%^li%^C120%^ag%^C121%^e%^RESET%^%^C037%^ so thick as to be impenetrable to all but those who know her secrets.\n%^CRST%^");
    set_smell("default","%^RESET%^%^CRST%^%^C101%^The %^C102%^wheel%^C101%^ creaks and groans as the %^C103%^river%^C101%^ rushes by.%^CRST%^");
    set_listen("default","%^RESET%^%^CRST%^%^C153%^Intoxicating %^C147%^scents%^C153%^ from the forest are carried on a %^C152%^mild breeze%^C153%^.%^CRST%^");
    set_items(([
        "waterfall" : "%^RESET%^%^CRST%^%^C045%^The waterfall tumbles down the craggy cliffs from far overhead. It breaks into several rivulets as it cascades down and catches the rocky surface, and stunning %^C051%^ra%^C153%^in%^C135%^bo%^C063%^ws%^RESET%^%^C045%^ arc from stream to stream along its furious descent.%^CRST%^",
        "cliffs" : "%^RESET%^%^CRST%^%^C255%^White cliffs rise up behind the %^C250%^small village%^C255%^, their craggy, steep surface making climbing a very dangerous prospect. The cliffs are riddled with %^C244%^hidden caves%^C255%^ and %^C244%^caverns%^C255%^, so that when the %^C250%^wind%^C255%^ whips through them they let out a %^C059%^mournful cry%^C255%^ that can be heard across the entire island, hence the island's namesake.%^CRST%^",
        "mill" : "%^RESET%^%^CRST%^%^C243%^An old mill stands here, which it appears to have done so for quite some time. It is built from %^C058%^mo%^C064%^ss%^C065%^-c%^C059%^ov%^C058%^er%^C064%^ed%^RESET%^%^C243%^ %^C059%^sto%^C243%^ne%^C059%^s%^RESET%^%^C243%^ and reinforced with %^C058%^timber%^C243%^, though the latter has begun to rot and degrade.%^CRST%^",
        "forest" : "%^RESET%^%^CRST%^%^C040%^The lush beauty of this %^C046%^forest%^C040%^ stands in contrast to the stark bleakness of the %^C250%^cliffs%^C040%^ and its crumbling %^C243%^village%^C040%^. Even from this distance you can see %^C047%^verdant fauna%^C040%^ and %^C160%^fr%^C088%^ui%^C094%^t b%^C100%^ea%^C172%^ri%^C166%^ng %^C160%^tr%^C088%^e%^C089%^es%^RESET%^%^C040%^. The forest is very much alive and thriving, and so overgrown as to be almost impassable except to someone who knows its secrets well.%^CRST%^",
        "waterwheel" : "%^RESET%^%^CRST%^%^C101%^The large %^C102%^wooden wheel%^C101%^ eternally churns the %^C103%^water%^C101%^, powered by the %^C103%^flowing river%^C101%^.%^CRST%^",
        ]));
    set_exits(([
        "northeast" : ROOMS"path3",
        "northwest" : ROOMS"waterfalls",
        ]));
}

void reset(){
    if(!present("ambiance device")) new(MON"ambiance_watermill")->move(this_object());
}

