#include <std.h>
#include "../defs.h"
inherit INH+"tunnel1";

int secret_passage;

void create() {
    ::create();

    set_exits(([
      "southwest" : TUNNEL"tormdock03",
      "northeast" : TUNNEL"tunnel02",
    ]));
    secret_passage = 0;
}

void init(){
    ::init();
    add_action("search_fun", "search");
    add_action("pull_fun", "pull");
    add_action("push_fun", "push");
}

void reset(){
    if(secret_passage == 1){
        tell_room("/d/player_houses/lizabelle/den", "%^RESET%^%^CRST%^%^C144%^Something shifts within the crawl space, blocking it off.%^CRST%^");
        secret_passage = 0;
    }
}

void push_fun(string str){
    if((str == "barrel") || (str == "the barrel")){
        if(secret_passage == 1){
            tell_object(TP, "%^RESET%^%^CRST%^%^C144%^The crawl space has already been cleared.%^CRST%^");
            return 1;
        }
        tell_object(TP, "%^RESET%^%^CRST%^%^C144%^You push the %^C058%^b%^C100%^ar%^C058%^re%^C100%^l %^C144%^aside, revealing a low %^C059%^crawl space %^C144%^behind it.%^CRST%^");
        tell_room(ETP, "%^RESET%^%^CRST%^%^C144%^"+TP->QCN+"%^RESET%^%^CRST%^%^C144%^ pushes a %^C058%^b%^C100%^ar%^C058%^re%^C100%^l %^C144%^aside, revealing a low %^C059%^crawl space %^C144%^behind it.%^CRST%^", TP);
        tell_room("/d/player_houses/lizabelle/cellar", "%^RESET%^%^CRST%^%^C248%^With a rough grinding noise, a %^C059%^crawl space %^C248%^opens up in the northern wall.%^CRST%^");
        add_exit("/d/player_houses/lizabelle/cellar","north");
        "/d/player_houses/lizabelle/cellar"->add_exit("/d/underdark/upper/tonovitunnel/tunnel01","south");
        secret_passage = 1;
        return 1;
    }
    return 0;
}

void pull_fun(string str){
    if((str == "barrel") || (str == "the barrel")){
        if(secret_passage == 0){
            tell_object(TP, "The barrel is already where it belongs.");
            return 1;
        }
        tell_object(TP, "%^RESET%^%^CRST%^%^C144%^You pull the %^C058%^b%^C100%^ar%^C058%^re%^C100%^l %^C144%^back into place, hiding the %^C059%^crawl space%^C144%^.%^CRST%^");
        tell_room(ETP, "%^RESET%^%^CRST%^%^C144%^"+TP->QCN+"%^RESET%^%^CRST%^%^C144%^ pulls a %^C058%^b%^C100%^ar%^C058%^re%^C100%^l %^C144%^over, hiding the %^C059%^crawl space%^C144%^.%^CRST%^", TP);
        tell_room("/d/player_houses/lizabelle/cellar", "%^RESET%^%^CRST%^%^C248%^With a rough grinding noise, a %^C059%^crawl space %^C248%^closes up in the northern wall.%^CRST%^");
        remove_exit("north");
        "/d/player_houses/lizabelle/cellar"->remove_exit("south");
        secret_passage = 0;
        return 1;
    }
    return 0;
}

void search_fun(string str){
    if((str == "hole") || (str == "crawl space")){
        tell_object(TP, "%^RESET%^%^CRST%^%^C244%^There appears to be a %^C058%^b%^C100%^ar%^C058%^re%^C100%^l%^C244%^ on the other side of the hole, blocking it. You could try to %^C248%^push %^C244%^the barrel out of the way.%^CRST%^");
        return 1;
    }
    return 0;
}

