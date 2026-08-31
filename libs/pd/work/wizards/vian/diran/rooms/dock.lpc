#include <std.h>
#include <diran.h>
#include <daemons.h>
#define OCEAN_X        0
#define OCEAN_Y        0
#define OCEAN_Z        "Diran"
#define APPLY_LIST     "/domains/Atheria/Whitestorm/apply"->query_owners()
inherit PIER;

string count_ships() {
    object *docked_ships;
    int i;
    string str;
    docked_ships=WORLD_D->find_docked_ships(OCEAN_X, OCEAN_Y);
    if(!docked_ships) return "There are currently no seaworthy boats docked here.";
    if(!sizeof(docked_ships)) return "There are currently no seaworthy boats docked here.";
    str="";
    for(i=0;i<sizeof(docked_ships);i++)
        str+=capitalize(docked_ships[i]->query_owner())+"'s ship is docked here.\n";
    return str;
}

string *query_docked() {
    object *docked_ships;
    int i;
    string *str;
    docked_ships=WORLD_D->find_docked_ships(OCEAN_X, OCEAN_Y);
    if(!docked_ships) return ({});
    if(!sizeof(docked_ships)) return ({});
    str=({});
    for(i=0;i<sizeof(docked_ships);i++)
        str+=({docked_ships[i]->query_owner()});
    return str;
}

void create() {
    ::create();
    set_fish((["mackeral":5, "blue fish":5, "flounder":5]));
    set_max_catch(999);
    set_max_fishing(20);
    set_chance(5);
set_short("the Diran docks");
    set_long("%^BOLD%^The salty air mixed with freezing cold makes the dock nearly unbearable.  There is nothing to see but snow to the north, and ocean to the south.");
    set_properties(([
        "light":2,
        "night light":2,
        "docks":1,
      ]));
    add_item("ships", (: count_ships() :));
    add_item("ship", (: count_ships() :));
    add_item("boats", (: count_ships() :));
    add_item("boat", (: count_ships() :));
    set_exits(([
        "north": ROOMS "tundra/1",
      ]));
}

void init() {
    ::init();
    add_action("cmd_board", "board");
    add_action("cmd_recall", "recall");
}


int cmd_board(string str) {
    string *docked;
    object ship;
    object *fols;
    if(this_player()->is_player())
        if(this_player()->query_level() < 15) return notify_fail("Na, the ocean is not a place for an adventurer like you.\n");
    docked=query_docked();
    if(!str) return notify_fail("Board what?\n");
    str=lower_case(str);
    if(!docked && str!=(string)this_player()->query_name()) return notify_fail("There are no ships here.\n");
    if(!sizeof(docked) && str!=(string)this_player()->query_name()) return notify_fail("There are no ships here.\n");
    if(member_array(str, docked)==-1) {
        if(str!=(string)this_player()->query_name()) return notify_fail("That ship is not here.\n");
        if(member_array(this_player()->query_CapName(), APPLY_LIST)==-1) return notify_fail("You do not own a ship.\n");
        call_other("/domains/Ocean/"+str[0..0]+"/"+str+"_ship", "set_owner", this_player()->query_name());
        ship=find_object("/domains/Ocean/"+str[0..0]+"/"+str+"_ship");
        if(!WORLD_D->add_ship(ship, OCEAN_X, OCEAN_Y, OCEAN_Z)) return notify_fail("Your ship is elsewhere, it may be recalled however.\n");
    }
    call_other("/domains/Ocean/"+str[0..0]+"/"+str+"_ship", "???");
    ship=find_object("/domains/Ocean/"+str[0..0]+"/"+str+"_ship");
    ship->set_on_ocean(OCEAN_Z, file_name(this_object()));
    fols=this_player()->query_followers(); 
   
this_player()->move_player("/domains/Ocean/"+str[0..0]+"/"+str+"_ship","ship");  
    if(sizeof(fols)) fols->force_me("board "+str); 
    this_player()->set_followers(fols);
    ship=find_object("/domains/Ocean/"+str[0..0]+"/"+str+"_ship");
    return 1;
}

int cmd_recall() {
    object ship;
    if(member_array(this_player()->query_CapName(), APPLY_LIST)==-1) return
notify_fail("You do not own a ship.\n");
   
call_other("/domains/Ocean/"+this_player()->query_name()[0..0]+"/"+this_player()->query_name()+"_ship", "set_owner", this_player()->query_name());
   
ship=find_object("/domains/Ocean/"+this_player()->query_name()[0..0]+"/"+this_player()->query_name()+"_ship");
    WORLD_D->add_ship(ship, OCEAN_X, OCEAN_Y, OCEAN_Z);
    if(!ship) return notify_fail("Your ship is not out there.\n");
    WORLD_D->set_position(ship, OCEAN_X, OCEAN_Y, OCEAN_Z);
    ship->set_on_ocean(OCEAN_Z, base_name(this_object()));
    message("ocean", "Your ship pulls into the port.", this_player());
    message("ocean", "The ship is magically transported.", ship);
    return 1;
}



void reset() {
::reset();
}
