// Chernobog & Titania (3/11/22)
// Wailing Isle - Residential

#include <std.h>
#include "../defs.h"
inherit INH+"residential";

int boards;

void create(){
    ::create();
    set_exits(([
        "southwest" : ROOMS"residential3",
        ]));
        
    add_item("windows", "%^CRST%^%^RESET%^%^C245%^Boards have been hammered into place where the glass panes have been long gone. The work is shoddy, and one could likely pry the boards loose with little effort.%^CRST%^");
    
    boards = 1;
}

void set_boards(int toggle){
    boards = toggle;
    return;
}

void reset(){
    ::reset();
    boards = 1;
}

void init(){
    ::init();
    add_action("pry_fun", "pry");
    add_action("squeeze_fun", "squeeze");
}

int pry_fun(string str){
    object player, room, inside;
    
    if(!str) return 0;
    if(str != "boards" && str != "board") return 0;
    
    player = this_player();
    if(!boards){
        message("info", "%^CRST%^%^RESET%^%^C058%^Loose boards have already been pried away, revealing an %^C100%^opening %^C058%^that someone could %^C100%^squeeze through%^C058%^.%^CRST%^", player);
        return 1;
    }
    room = environment(player);
    inside = find_object_or_load(ROOMS"house1");
    message("environment", "%^CRST%^%^RESET%^%^C058%^You manage to pry a few loose boards away, revealing an %^C100%^opening %^C058%^that someone could %^C100%^squeeze through%^C058%^.%^CRST%^", player);
    message("environment", "%^CRST%^%^RESET%^%^C058%^"+player->query_cap_name()+"%^CRST%^%^RESET%^%^C058%^ manages to pry a few loose boards away, revealing an %^C100%^opening %^C058%^that someone could %^C100%^squeeze through%^C058%^.%^CRST%^", room, player);
    message("environment", "%^CRST%^%^RESET%^%^C058%^A few loose planks are pried away from the other side of a boarded up window, revealing an %^C100%^opening %^C058%^that someone could %^C100%^squeeze through%^C058%^.%^CRST%^", inside);
    boards = 0;
    inside->set_boards(0);
    return 1;
}

int squeeze_fun(string str){
    object player, room, inside;
    
    if(!str) return 0;
    if(str != "through opening") return 0;
    
    player = this_player();
    if(boards){
        message("info", "%^CRST%^%^RESET%^%^C058%^You don't see any opening. Maybe you can pry a few boards loose.", player);
        return 1;
    }
    room = environment(player);
    inside = find_object_or_load(ROOMS"house1");
    message("environment", "\n%^CRST%^%^RESET%^%^C058%^Squeezing through the opening between the boards, you make your way into the abandoned house.%^CRST%^", player);
    message("environment", "%^CRST%^%^RESET%^%^C058%^Squeezing through the opening between the boards, "+player->query_cap_name()+"%^CRST%^%^RESET%^%^C058%^ makes their way into the abandoned house.%^CRST%^", room, player);
    message("environment", "%^CRST%^%^RESET%^%^C058%^Squeezing through the opening between the boards, "+player->query_cap_name()+"%^CRST%^%^RESET%^%^C058%^ makes their way into the room.%^CRST%^", inside);
    player->move(inside);
    player->force_me("look");
    return 1;
}

