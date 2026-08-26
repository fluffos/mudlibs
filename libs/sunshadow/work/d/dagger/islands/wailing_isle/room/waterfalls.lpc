// Chernobog & Titania (2/7/22)
// The Wailing Isle -  Below the Waterfalls

#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){
    ::create();
    set_terrain(LIGHT_FOREST);
    set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_property("indoors", 0);
    set_name("a pool below the waterfall");
    set_short("%^RESET%^%^CRST%^%^C079%^a pool below the waterfall%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C111%^S%^C117%^i%^C123%^l%^C159%^v%^C153%^e%^C081%^r%^C087%^y %^C051%^r%^C045%^i%^C039%^v%^C111%^u%^C117%^l%^C123%^e%^C159%^t%^C153%^s%^RESET%^%^C080%^ of %^C111%^c%^C117%^o%^C123%^o%^C159%^l %^C153%^w%^C081%^a%^C087%^t%^C051%^e%^C045%^r%^RESET%^%^C080%^ cascade hundreds of feet down the %^C253%^c%^C251%^l%^C249%^i%^C251%^f%^C253%^f%^C251%^s%^C249%^i%^C251%^d%^C253%^e%^RESET%^%^C080%^, spilling into a %^C045%^cr%^C051%^ys%^C087%^ta%^C081%^ll%^C075%^in%^C045%^e %^C051%^p%^C087%^o%^C081%^o%^C075%^l%^RESET%^%^C080%^ before flowing into a %^C081%^r%^C087%^i%^C051%^v%^C045%^e%^C039%^r%^RESET%^%^C080%^ winding off to the southeast. Although deep and tumultuous near the falls, the water becomes %^C153%^pl%^C147%^ac%^C153%^id%^RESET%^%^C080%^ as it reaches the shallows where %^C245%^s%^C248%^m%^C250%^all fi%^C248%^s%^C245%^h%^RESET%^%^C080%^ float serenely, undisturbed by your presence. Here, the water is as clear as glass, revealing a bed of %^C230%^s%^C229%^o%^C230%^f%^C229%^t %^C230%^s%^C229%^a%^C230%^n%^C229%^d%^C230%^s%^RESET%^%^C080%^, %^C253%^b%^C250%^o%^C253%^ne-w%^C250%^h%^C253%^ite r%^C250%^o%^C253%^cks%^RESET%^%^C080%^, and %^C178%^g%^C184%^l%^C190%^e%^C226%^a%^C220%^m%^C214%^i%^C220%^n%^C226%^g %^C190%^c%^C184%^o%^C178%^i%^C184%^n%^C190%^s%^RESET%^%^C080%^ tossed into the pool by travelers wanting a wish to come true. Along the rocky shore, %^C048%^l%^C047%^e%^C046%^a%^C082%^f%^C083%^y %^C084%^p%^C048%^l%^C047%^a%^C046%^n%^C082%^t%^C083%^s%^RESET%^%^C080%^ grow amongst %^C048%^e%^C047%^m%^C046%^e%^C082%^r%^C083%^a%^C084%^l%^C048%^d %^C047%^m%^C046%^o%^C082%^s%^C083%^s%^C084%^e%^C048%^s%^RESET%^%^C080%^ to complete this %^C153%^p%^C147%^ea%^C153%^ce%^C147%^fu%^C153%^l%^C080%^, %^C040%^v%^C041%^e%^C040%^rda%^C041%^n%^C040%^t %^C080%^oasis.%^CRST%^\n");
    set_smell("default","%^RESET%^%^CRST%^%^C153%^Intoxicating %^C147%^scents%^C153%^ from the forest are carried on a %^C152%^mild breeze%^C153%^.%^CRST%^");
    set_listen("default","%^RESET%^%^CRST%^%^C081%^The %^C087%^splashing%^C081%^ of the powerful falls is %^C087%^revitalizing%^C081%^.%^CRST%^");
    set_items(([
        "waterfall" : "%^RESET%^%^CRST%^%^C045%^The waterfall tumbles down the craggy cliffs from far overhead. It breaks into several rivulets as it cascades down and catches the rocky surface, and stunning %^C051%^ra%^C153%^in%^C135%^bo%^C063%^ws%^RESET%^%^C045%^ arc from stream to stream along its thunderous descent.%^CRST%^",
        ({"pool", "water", "bottom"}) : "%^RESET%^%^CRST%^%^C255%^The water here is so clear you can see the bottom. %^C148%^Coins%^C255%^ cover the %^C250%^white sands%^C255%^ and %^C250%^stones%^C255%^ of the floor, tempting you to retrieve one... %^C245%^or all%^C255%^.%^CRST%^",
        ({"rocks", "stones"}) : "%^RESET%^%^CRST%^%^C255%^The white stones match the towering cliffs.%^CRST%^",
        "cliffs" : "%^RESET%^%^CRST%^%^C255%^White cliffs rise up behind the %^C250%^small village%^C255%^, their craggy, steep surface making climbing a very dangerous prospect. The cliffs are riddled with %^C244%^hidden caves%^C255%^ and %^C244%^caverns%^C255%^, so that when the %^C250%^wind%^C255%^ whips through them they let out a %^C059%^mournful cry%^C255%^ that can be heard across the entire island... hence the island's namesake.%^CRST%^",
        "coins" : "%^RESET%^%^CRST%^%^C153%^The %^C148%^coins%^C153%^ are somebody's wishes and dreams. They glitter %^C159%^temptingly%^C153%^ beneath the clear, %^C081%^calm waters%^C153%^. You recall hearing a rumor that those who try to steal the wishes of others pay dearly for their avarice...%^CRST%^",
        "fish" : "%^RESET%^%^CRST%^%^C255%^The white scaled fish are dappled with %^C160%^red%^C255%^ and %^C059%^black %^C247%^m%^C160%^a%^C088%^r%^C244%^ki%^C243%^n%^C059%^g%^RESET%^%^C247%^s.%^CRST%^",
        ({"moss", "plants"}) : "%^RESET%^%^CRST%^%^C040%^The slick rocks are home to a number of %^C082%^small plants%^C040%^ and %^C082%^mosses%^C040%^, adding a pretty touch of color to the already picturesque pool.%^CRST%^",
        "river" : "%^RESET%^%^CRST%^%^C075%^The falls feed into the pool, which in turn feed the river winding away towards a %^C101%^structure%^C075%^ to the southeast.%^CRST%^",
		"structure" : "%^RESET%^%^CRST%^%^C101%^The river powers an old watermill downstream from here.%^CRST%^",
        ]));
    set_exits(([
        "southeast" : ROOMS"watermill",
        ]));
}

void init(){
    ::init();
    add_action("drink_fun", "drink");
    add_action("retrieve_fun", "retrieve");
}

void reset(){
    if(!present("ambiance device")) new(MON"ambiance_waterfalls")->move(this_object());
}

int retrieve_fun(string str){
    object player, room;
    
    if(!str) return 0;
    if(str != "coin" && str != "coins" && str != "all coins") return 0;
    
    player = this_player();
    room = this_object();
    tell_object(player, "%^RESET%^%^CRST%^%^C068%^As your fingertips brush against the submerged %^C214%^c%^C220%^oin%^C214%^s%^C068%^, %^C062%^something takes hold of your wrist and %^C056%^drags you below the surface!%^CRST%^\n");
    tell_room(room, "%^RESET%^%^CRST%^%^C068%^As "+player->query_cap_name()+"%^RESET%^%^CRST%^%^C068%^ reaches below the surface of the pool, %^C062%^something seems to take hold of them and %^C056%^drags them below the surface!%^CRST%^\n", player);
    player->set_paralyzed(40, "%^RESET%^%^CRST%^%^C020%^Something unseen is constricting your body...%^CRST%^");
    player->move(ROOMS"pool");
    
    return 1;
}

int drink_fun(string str){
    object player, room;
    
    if(!str) return 0;
    if(str != "water from pool" && str != "water" && str != "from the pool") return 0;

    player = this_player();
    room = this_object();
    player->add_quenched(50);
	tell_object(player, "%^RESET%^%^CRST%^%^C033%^The water is %^C045%^cool %^C033%^and %^C051%^refreshing %^C033%^as you drink deeply.%^RESET%^");
    tell_room(room, "%^RESET%^%^CRST%^%^C033%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C033%^ takes a long drink from the pool.%^CRST%^", player);
    return 1;
}

