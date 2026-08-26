// Petrarch
// Merentha Lib 1.0
// setter.c

#include <daemons.h>
#include <rooms.h>
#include <std.h>
inherit ROOM;

string *races=({"human", "giant", "gnome", "elf", "dwarf", "fairy"});
void create() {
    ::create();
    set_short("This is the character creation room.");
    set_long("This is a large circular room.  There are compartments along the walls of the room.  Within each compartment are two beings of the same race, one male and one female.  There is a different race in each compartment.  The people appear frozen in time.\n\nThis is the race selection room, you will now choose a race and gender to be.");
    set_items(([
        "room":"The room appears to have no exits or entrances.  It is carved from stone.  Compartments containing bodies line the walls.",
        "compartments":"There are several dozen compartments.  There are two bodies in each one, one male and one female.",
        "bodies":"The bodies all appear to be frozen in time with no expressions on their faces.",
      ]));

}

void reset() {
    object ob;
    ::reset();
    if(!present("sign")) {
        ob=new(SIGN);
        ob->set_name("sign");
        ob->set_short("a large sign");
        ob->set_long("The sign is made from oak and appears quite old.  It is nailed into the ground here.");
        ob->set_id(({"sign", "newbie sign", "oak sign", "race sign"}));
        ob->set_message(copy(border("%^RED%^You must now choose a gender and race.  These will help determine how you live your life in this imaginary world.  There are advantages and disadvantages to each race and gender.  You can choose from these races:\n\n%^GREEN%^"+format_page(races, 3)+"\n%^ORANGE%^You can read the <help races> file for more information on each race."+
            "\n\nOnce you have decided on a race type <become [gender] [race]>\nFor example to become a male human type <become male human>"
            , "Race Selection")));
        ob->move(this_object());
    }
}

void init() {
    ::init();
    add_action("cmd_become", "become");
}

int cmd_become(string str) {
    string gender, race;
    if(!str || sscanf(str, "%s %s", gender, race)!=2) return notify_fail("Syntax: become [gender] [race]\n");
    gender=lower_case(gender);
    race=lower_case(race);
    if(gender!="male" && gender!="female") return notify_fail("Syntax: become [gender] [race]\nGender must be either male or female.\n");
    if(member_array(race, races)==-1) return notify_fail("Syntax: become [gender] [race]\nRace must be one of:\n"+format_page(races,3));
    this_player()->set_gender(gender);
    this_player()->set_race(race);
    this_player()->set_level(1);
    SKILL_D->init_skills(this_player());
    this_player()->set_money("gold",100);
    this_player()->move_player(SETTER_ROOM_2);
    return 1;
}


