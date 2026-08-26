// Chernobog & Titania (4/29/22)
// The Wailing Isle -  Within the Pool

#include <std.h>
#include <daemons.h>
#include "../defs.h"
inherit WATER;

void create(){
    ::create();
    set_terrain(DEEP_WATER);
    set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_property("indoors", 0);
    set_property("no teleport",1);
    set_name("deep within a pool");
    set_short("%^RESET%^%^CRST%^%^C056%^deep within a pool%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C056%^It is calm here, deep below the surface of the pool. The water is cool, growing %^C068%^colder %^C056%^and %^C068%^colder %^C056%^the longer you lay here, trapped in the grip of something unseen...%^CRST%^\n");
    set_listen("default","%^RESET%^%^CRST%^%^C081%^The %^C087%^crash%^C081%^ of the falls is muted down here.%^CRST%^");
    set_items(([
        ({"pool", "water", "bottom"}) : "%^RESET%^%^CRST%^%^C255%^The water here is so clear you can see the bottom. %^C148%^Coins%^C255%^ cover the %^C250%^white sands%^C255%^ and %^C250%^stones%^C255%^ of the floor.%^CRST%^",
        ({"rocks", "stones"}) : "%^RESET%^%^CRST%^%^C255%^The white stones match the towering cliffs.%^CRST%^",
        "coins" : "%^RESET%^%^CRST%^%^C153%^The %^C148%^coins%^C153%^ are somebody's wishes and dreams. They glitter %^C159%^temptingly%^C153%^ beneath the clear, %^C081%^calm waters%^C153%^. You recall hearing a rumor that those who try to steal the wishes of others pay dearly for their avarice...%^CRST%^",
        "fish" : "%^RESET%^%^CRST%^%^C255%^The white scaled fish are dappled with %^C160%^red%^C255%^ and %^C059%^black %^C247%^m%^C160%^a%^C088%^r%^C244%^ki%^C243%^n%^C059%^g%^RESET%^%^C247%^s.%^CRST%^",
        ]));
}

void init(){
    ::init();
    call_out("spirit_attack", 1, this_player(), 0, 0);
    
}

void spirit_attack(object player, int step, int damage){
    if(!objectp(player)) return;
    
    switch(step){
        case 0 :
            damage = player->query_max_hp() / 5;
            tell_object(player, "\n%^RESET%^%^CRST%^%^C056%^The surface quickly vanishes, and the water appears to grow %^C061%^pr%^C067%^ete%^C061%^rn%^C067%^atu%^C061%^ra%^C067%^lly %^C059%^dark %^RESET%^%^C056%^down here.%^CRST%^\n");
            break;
        case 1 :
            tell_object(player, "\n%^RESET%^%^CRST%^%^C056%^Whatever has hold of you has ensnared your entire body, wrapping you %^C196%^t%^C124%^i%^C196%^g%^C124%^h%^C196%^t %^C056%^and %^C059%^squeezing %^C056%^the air from your lungs...%^CRST%^\n");
            player->cause_typed_damage(player, "torso", damage, "untyped");
            player->add_money("gold",-2000000);
            player->add_money("platinum",-2000000);
            player->add_money("electrum",-2000000);
            player->add_money("silver",-2000000);
            player->add_money("copper",-2000000);
            break;
        case 2 :
            tell_object(player, "\n%^RESET%^%^CRST%^%^C056%^Things appear to be growing even darker, and %^C243%^d%^C244%^i%^C245%^s%^C246%^t%^C247%^o%^C248%^r%^C249%^t%^C250%^e%^C249%^d %^C248%^w%^C247%^h%^C245%^i%^C246%^s%^C245%^p%^C244%^e%^C243%^r%^C244%^s %^RESET%^%^C056%^seem to echo through the water as you come to rest at the %^C020%^bottom %^C056%^of the pool.%^CRST%^\n");
            player->cause_typed_damage(player, "torso", damage, "untyped");
            break;
        case 3 :
            tell_object(player, "\n%^RESET%^%^CRST%^%^C255%^...thief... trespasser... these are not %^C196%^Y%^C124%^O%^C196%^U%^C124%^R %^C255%^wishes...%^CRST%^\n");
            player->cause_typed_damage(player, "torso", damage, "untyped");
            break;
        case 4 :
            tell_object(player, "\n%^RESET%^%^CRST%^%^C056%^Whatever force is holding you tightens even more, coiling about you... %^C074%^and then forcefully expels you from the pool, %^C086%^flying %^C074%^through the air in an impressive arc before landing %^C196%^painfully %^C074%^on the %^C230%^ro%^C255%^c%^C230%^ky s%^C255%^h%^C230%^or%^C255%^e%^RESET%^%^C074%^.%^CRST%^\n");
            tell_room(find_object_or_load(ROOMS"waterfalls"), "\n%^RESET%^%^CRST%^%^C074%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C074%^ is forcefully expelled from the pool, %^C086%^flying %^C074%^through the air in an impressive arc before landing %^C196%^painfully %^C074%^on the %^C230%^ro%^C255%^c%^C230%^ky s%^C255%^h%^C230%^or%^C255%^e%^RESET%^%^C074%^.\n", player);
            player->cause_typed_damage(player, "torso", damage, "untyped");
            player->move(ROOMS"waterfalls");
            break;
        case 5 :
            tell_object(player, "\n%^RESET%^%^CRST%^%^C066%^...it feels like your pockets are a bit lighter. And there seem to be even more %^C214%^c%^C220%^oin%^C214%^s %^C066%^glittering at the bottom of the pool now.%^CRST%^\n");
        default :
            break;
    }
    
    if(step == 6){
        tell_room(environment(player), "\n%^RESET%^%^CRST%^%^C059%^The %^C243%^w%^C244%^a%^C246%^i%^C247%^l%^C248%^i%^C249%^n%^C250%^g %^RESET%^%^C059%^of the %^C255%^cl%^C250%^i%^C255%^f%^C250%^f%^C255%^s %^RESET%^%^C059%^seems to grow %^C245%^louder%^C059%^, more %^C250%^distinct%^C059%^, until you swear you can hear the words: %^C255%^...these are MY wishes...%^CRST%^\n");
        return;
    }
    
    step++;
    call_out("spirit_attack", 5, player, step, damage);
    
    return;
}

