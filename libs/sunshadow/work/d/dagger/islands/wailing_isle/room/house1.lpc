// Chernobog & Titania (8/16/22)
// Wailing Isle - Abandoned House

#include <std.h>
#include "../defs.h"
inherit ROOM;

int boards;

void create(){
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DECAYED_FLOOR);
    set_property("light", 2);
    set_property("indoors", 1);
    set_name("an abandoned house");
    set_short("%^RESET%^%^CRST%^%^C059%^an abandoned house%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C059%^This is a long and narrow room that probably served as a living area. A heavy darkness pervades the space, the only %^C245%^light%^C059%^ is that which manages to seep through the cracks in the boarded up windows. The %^C243%^large fireplace%^C059%^ is refuge to cold ashes and cobwebs. An %^C243%^empty table%^C059%^ takes up much of the area, with some %^C243%^old chairs%^C059%^ still situated around it. A set of %^C243%^shelves%^C059%^ along one wall holds only dust now. An archway leads you deeper into the desolate house.%^CRST%^\n");
    set_smell("default","%^RESET%^%^CRST%^%^C245%^It smells of %^C058%^m%^C064%^o%^C058%^ld%^RESET%^%^C245%^ and %^C059%^stagnation%^C245%^.%^CRST%^");
    set_listen("default","%^RESET%^%^CRST%^%^C065%^You hear the occasional bustle of activity from outside.%^CRST%^");
    set_items(([
        ({"table", "chairs"}) : "%^CRST%^%^RESET%^%^C102%^The %^C101%^simple furniture%^C102%^ has managed to navigate the passage of time and neglect with its dignity in tact. Some dust has settled on the surface, and no doubt %^C243%^spiders%^C102%^ have found homes in the nooks, but it looks sturdy enough to use.%^CRST%^",
        ({"fireplace"}) : "%^CRST%^%^RESET%^%^C245%^The fireplace is made from stones mined from the surrounding cliffs of the isle, their %^C251%^pale surfaces%^C245%^ standing out like old bones against the dark.%^CRST%^",
        ({"shelf"}) : "%^CRST%^%^RESET%^%^C245%^A few simple shelves are built into the walls and seem wholly insignificant. Whomever once resided here seemed to live an austere life.%^CRST%^",
        "windows" : "%^CRST%^%^RESET%^%^C245%^ Boards have been hammered into place where the glass panes have been long gone. The work is shoddy, and one could likely pry the boards loose with little effort.%^CRST%^",
        ]));
    set_exits(([
        "bedroom" : ROOMS"house2",
        ]));
    
    boards = 1;
}

void init(){
    ::init();
    add_action("pry_fun", "pry");
    add_action("squeeze_fun", "squeeze");
}

void reset(){
    ::reset();
    boards = 1;
}

void set_boards(int toggle){
    boards = toggle;
    return;
}

int pry_fun(string str){
    object player, room, outside;
    
    if(!str) return 0;
    if(str != "boards" && str != "board") return 0;
    
    player = this_player();
    if(!boards){
        message("info", "%^CRST%^%^RESET%^%^C058%^Loose boards have already been pried away, revealing an %^C100%^opening %^C058%^that someone could %^C100%^squeeze through%^C058%^.%^CRST%^", player);
        return 1;
    }
    room = environment(player);
    outside = find_object_or_load(ROOMS"residential4");
    message("environment", "%^CRST%^%^RESET%^%^C058%^You manage to pry a few loose boards away, revealing an %^C100%^opening %^C058%^that someone could %^C100%^squeeze through%^C058%^.", player);
    message("environment", "%^CRST%^%^RESET%^%^C058%^"+player->query_cap_name()+"%^CRST%^%^RESET%^%^C058%^ manages to pry a few loose boards away, revealing an %^C100%^opening %^C058%^that someone could %^C100%^squeeze through%^C058%^.", room, player);
    message("environment", "%^CRST%^%^RESET%^%^C058%^A few loose planks are pried away from the other side of a boarded up window, revealing an %^C100%^opening %^C058%^that someone could %^C100%^squeeze through%^C058%^.", outside);
    boards = 0;
    outside->set_boards(0);
    return 1;
}

int squeeze_fun(string str){
    object player, room, outside;
    
    if(!str) return 0;
    if(str != "through opening") return 0;
    
    player = this_player();
    if(boards){
        message("info", "%^CRST%^%^RESET%^%^C058%^You don't see any opening. Maybe you can pry a few boards loose.", player);
        return 1;
    }
    room = environment(player);
    outside = find_object_or_load(ROOMS"residential4");
    message("environment", "\n%^CRST%^%^RESET%^%^C058%^Squeezing through the opening between the boards, you make your way out of the abandoned house.%^CRST%^", player);
    message("environment", "%^CRST%^%^RESET%^%^C058%^Squeezing through the opening between the boards, "+player->query_cap_name()+"%^CRST%^%^RESET%^%^C058%^ makes their way out of the abandoned house.%^CRST%^", room, player);
    message("environment", "%^CRST%^%^RESET%^%^C058%^Squeezing through the opening between the boards, "+player->query_cap_name()+"%^CRST%^%^RESET%^%^C058%^ makes their way out of an abandoned house and onto the street.%^CRST%^", outside);
    player->move(outside);
    player->force_me("look");
    return 1;
}

