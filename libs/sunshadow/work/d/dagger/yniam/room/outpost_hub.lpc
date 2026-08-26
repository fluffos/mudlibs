// Chernobog (3/15/22)
// Yniam Waystation - Hub

#include <std.h>
#include "../defs.h"
inherit VAULT;

int bonfire;

void create(){
    ::create();
    set_terrain(GRASSLANDS);
    set_travel(DIRT_ROAD);
    set_property("indoors", 0);
    set_property("light", 2);
    set_name("A waystation in the Yniam Plains");
    set_short("%^RESET%^%^CRST%^%^C046%^The %^C130%^hub %^C046%^of the %^C144%^Yniam waystation%^CRST%^");
    set_long((:this_object(), "long_fun":));
    set_smell("default", "%^RESET%^%^CRST%^%^C156%^The scents of the plains are carried in the breeze.%^CRST%^");
    set_listen("default", "%^RESET%^%^CRST%^%^C125%^The susurrus of people working and trading breaks the quiet of the plains.%^CRST%^");
    set_items(([
        ({"walls", "palisade"}) : "%^RESET%^%^CRST%^%^C058%^The palisade is a %^C136%^wooden wall %^C058%^comprised of logs sunk end-first into the earth and lashed together with strips of %^C130%^leather%^C058%^. It is a simple defense meant more to buy time than to actually keep someone out.%^CRST%^",
        "greenhouse" : "%^RESET%^%^CRST%^%^C250%^C%^C253%^l%^C255%^o%^C253%^u%^C250%^d%^C253%^e%^C250%^d %^C253%^g%^C255%^l%^C253%^a%^C250%^s%^C253%^s panes %^RESET%^%^C101%^make up the greenhouse, though it's possible to see the shadows of worktables covered with %^C064%^potted plants %^C101%^within.%^CRST%^",
        ({"fire pit", "pit"}) : (:this_object(), "firepit_fun":),
        ({"bonfire", "fire"}) : (:this_object(), "bonfire_fun":),
        ]));
    set_exits(([
        "southwest" : ROOMS"palisade1",
        "northeast" : ROOMS"palisade2",
        "southeast" : ROOMS"palisade3",
        "northwest" : ROOMS"meetinghall",
        "north" : ROOMS"forge",
        "east" : ROOMS"lab",
        "south" : "/d/magic/temples/cacia/cacia",
        ]));
    set_door("wooden door", ROOMS"lab", "east", 0);
	set_door_description("wooden door","%^RESET%^%^CRST%^%^C058%^This is a simple wooden door with a %^C214%^b%^C220%^ras%^C214%^s d%^C220%^oo%^C214%^r h%^C220%^andl%^C214%^e%^RESET%^%^C058%^. Thick planks give it some heft, making it quite solid.%^CRST%^");
    bonfire = 0;
}

void init(){
    ::init();
    add_action("light_fun", "light");
    add_action("douse_fun", "douse");
}

void reset(){
    ::reset();
    
    if(!present("ambiance device")) new(OBJ"ambiance")->move(this_object());
}

int douse_fun(string str){
    object player, room;
    player = this_player();
    room = this_object();
    
    if(!str) return 0;
    if(str != "bonfire" && str != "fire") return 0;
    
    if(!bonfire) tell_object(player, "%^RESET%^%^CRST%^%^C059%^The fire pit is cold and inert already.%^CRST%^");
    else{
        tell_object(player, "%^RESET%^%^CRST%^%^C059%^You start dumping bucket after bucket of water at the base of the fire, quickly snuffing it out.%^CRST%^");
        tell_room(room, "%^RESET%^%^CRST%^%^C059%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C059%^ starts dumping bucket after bucket of water at the base of the fire, quickly snuffing it out.%^CRST%^", player);
        bonfire = 0;
    }
    return 1;
}

int light_fun(string str){
    object player, room;
    player = this_player();
    room = this_object();
    
    if(!str) return 0;
    if(str != "bonfire" && str != "fire") return 0;
    
    if(bonfire) tell_object(player, "%^RESET%^%^CRST%^%^C144%^The bonfire has already been started!%^CRST%^");
    else{
        tell_object(player, "%^RESET%^%^CRST%^%^C144%^You set to lighting the wood piled in the stone ring, and it quickly catches! Before long, it is a %^C202%^r%^C196%^o%^C202%^a%^C208%^r%^C202%^i%^C196%^n%^C202%^g %^C208%^b%^C202%^o%^C196%^n%^C202%^f%^C208%^i%^C202%^r%^C196%^e%^RESET%^%^C144%^.%^CRST%^");
        tell_room(room, "%^RESET%^%^CRST%^%^C144%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C144%^ sets to lighting the wood piled in the stone ring, and it quickly catches! Before long, it is a %^C202%^r%^C196%^o%^C202%^a%^C208%^r%^C202%^i%^C196%^n%^C202%^g %^C208%^b%^C202%^o%^C196%^n%^C202%^f%^C208%^i%^C202%^r%^C196%^e%^RESET%^%^C144%^.%^CRST%^", player);
        bonfire = 1;
    }
    return 1;
}

string long_fun(){
    string longdesc;
    object player;
    player = this_player();
    
    if(!bonfire) longdesc = "%^RESET%^%^CRST%^%^C101%^The tall pointed walls of the %^C058%^palisade %^C101%^encircle this small outpost, offering some manner of protection. %^C059%^Smoke %^RESET%^%^C101%^and the sharp %^C255%^ri%^C252%^n%^C255%^gi%^C252%^n%^C255%^g %^C101%^of %^C243%^m%^C245%^e%^C247%^t%^C245%^a%^C243%^l %^RESET%^%^C101%^encroach from the north, next to a wooden building serving as a %^C136%^meeting hall%^C101%^. On the opposite end of the outpost there is another %^C130%^structure%^C101%^, though it appears to be windowless, and is flanked by a %^C195%^gl%^C231%^as%^C195%^s gre%^C231%^enh%^C195%^o%^C231%^u%^C195%^se %^RESET%^%^C101%^on the side.  A large %^C245%^r%^C248%^i%^C245%^n%^C248%^g %^C245%^of %^C248%^s%^C245%^t%^C248%^o%^C245%^n%^C248%^e%^C245%^s %^RESET%^%^C101%^rests in the middle of the clearing, a grand fire pit stocked and ready for a bonfire.%^CRST%^\n";
    else longdesc = "%^RESET%^%^CRST%^%^C101%^The tall pointed walls of the %^C058%^palisade %^C101%^encircle this small outpost, offering some manner of protection. %^C059%^Smoke %^RESET%^%^C101%^and the sharp %^C255%^ri%^C252%^n%^C255%^gi%^C252%^n%^C255%^g %^C101%^of %^C243%^m%^C245%^e%^C247%^t%^C245%^a%^C243%^l %^RESET%^%^C101%^encroach from the north, next to a wooden building serving as a %^C136%^meeting hall%^C101%^. On the opposite end of the outpost there is another %^C130%^structure%^C101%^, though it appears to be windowless, and is flanked by a %^C195%^gl%^C231%^as%^C195%^s gre%^C231%^enh%^C195%^o%^C231%^u%^C195%^se %^RESET%^%^C101%^on the side.  A large %^C245%^r%^C248%^i%^C245%^n%^C248%^g %^C245%^of %^C248%^s%^C245%^t%^C248%^o%^C245%^n%^C248%^e%^C245%^s %^RESET%^%^C101%^rests in the middle of the clearing, home to a %^C202%^r%^C196%^o%^C202%^a%^C208%^r%^C202%^i%^C196%^n%^C202%^g %^C208%^b%^C202%^o%^C196%^n%^C202%^f%^C208%^i%^C202%^r%^C196%^e%^RESET%^%^C101%^ that floods the clearing with warmth and light.%^CRST%^\n";
    return longdesc;
}

void firepit_fun(){
    object player, room;
    player = this_player();
    room = this_object();
    
    if(!bonfire){
        tell_object(player, "%^RESET%^%^CRST%^%^C101%^Large uneven %^C243%^s%^C245%^t%^C243%^o%^C248%^n%^C244%^e%^C059%^s %^RESET%^%^C101%^have been set in an expansive ring in the center of the clearing. A stack of %^C058%^firewood %^C101%^has been placed within, ready to be set a%^C144%^light %^C101%^into a raging bonfire.%^CRST%^");
        tell_room(room, ""+player->query_cap_name()+" looks over the firepit.", player);
    }
    else{
        tell_object(player, "%^RESET%^%^CRST%^%^C101%^Large uneven %^C243%^s%^C245%^t%^C243%^o%^C248%^n%^C244%^e%^C059%^s %^RESET%^%^C101%^have been set in an expansive ring in the center of the clearing. A large pile of %^C058%^firewood %^C101%^has been set alight in a %^C202%^r%^C196%^o%^C202%^a%^C208%^r%^C202%^i%^C196%^n%^C202%^g %^C208%^b%^C202%^o%^C196%^n%^C202%^f%^C208%^i%^C202%^r%^C196%^e%^RESET%^%^C101%^, though there appear to be several buckets of water nearby to %^C144%^douse %^C101%^it.%^CRST%^");
        tell_room(room, ""+player->query_cap_name()+" looks over the firepit.", player);
    }
    return;
}

void bonfire_fun(){
    object player, room;
    player = this_player();
    room = this_object();
    
    if(!bonfire){
        tell_object(player, "%^RESET%^%^CRST%^You do not notice that here.%^CRST%^");
    }
    else{
        tell_object(player, "%^RESET%^%^CRST%^%^C101%^Large uneven %^C243%^s%^C245%^t%^C243%^o%^C248%^n%^C244%^e%^C059%^s %^RESET%^%^C101%^have been set in an expansive ring in the center of the clearing. A large pile of %^C058%^firewood %^C101%^has been set alight in a %^C202%^r%^C196%^o%^C202%^a%^C208%^r%^C202%^i%^C196%^n%^C202%^g %^C208%^b%^C202%^o%^C196%^n%^C202%^f%^C208%^i%^C202%^r%^C196%^e%^RESET%^%^C101%^, though there appears to be several buckets of water nearby to %^C144%^douse %^C101%^it.%^CRST%^");
        tell_room(room, ""+player->query_cap_name()+" looks over the bonfire.", player);
    }
    return;
}

