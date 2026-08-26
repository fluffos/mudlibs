#include <std.h>

inherit ROOM;

void create()
{
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_light(2);
    set_indoors(1);
    set_name("An OOC Training Room");
    set_short("%^RESET%^CYAN%^An OOC Training Room%^RESET%^");
    set_long("%^RESET%^%^CYAN%^This is an OOC Training Room for use by players wanting to figure out around how much damage they do.  You can %^BOLD%^%^WHITE%^<retrieve dummy> %^RESET%^%^CYAN%^ or %^BOLD%^%^WHITE%^<retrieve undead dummy> %^RESET%^%^CYAN%^to have something to practice on, but make sure you %^BOLD%^%^WHITE%^<return dummy> %^RESET%^%^CYAN%^when finished.\n\n%^BOLD%^%^RED%^Do not use mercenaries against the dummy, it will murder them.%^RESET%^");
    set_listen("default", "You hear people calculating their DPS.");
    set_exits(([
                   "south" : "/d/shadow/room/forest/road3"
                   ]));
}

void init()
{
    ::init();
    add_action("retrieve_em", "retrieve");
    add_action("return_em", "return");
}

int retrieve_em(string str)
{
    if (!str) {
        return 0;
    }
    if (str == "dummy" || str == "testdummy" || str == "test dummy" || str == "practice dummy" || str == "rune") {
        if (present("testdummy")) {
            tell_object(TP, "There is already a testdummy present!");
            return 1;
        }
        tell_object(TP, "You whistle and a test dummy shimmers into being.");
        tell_room(TO, "" + TPQCN + " whistles and a test dummy shimmers into being.", TP);
        new("/d/shadow/mon/testdummy")->move(TO);
        return 1;
    }
    if(str == "undead dummy"){
        if (present("testdummy")) {
            tell_object(TP, "There is already a testdummy present!");
            return 1;
        }
        tell_object(TP, "You whistle and a test dummy shimmers into being.");
        tell_room(TO, "" + TPQCN + " whistles and a test dummy shimmers into being.", TP);
        new("/d/common/mons/testdummy_undead")->move(TO);
        return 1;
    }
    return 0;
}

int return_em(string str){
    object room, *everything;
    int i;
    if(!str) return 0;
    if(str == "dummy" || str == "testdummy" || str == "test dummy" || str == "practice dummy"){
        object dummyobj;
        if (!present("test dummy")) {
            tell_object(TP, "There is no practice dummy to return!");
            return 1;
        }
        tell_object(TP, "You kick the test dummy in the junk and it fades out of existence.");
        tell_room(TO, "" + TPQCN + " kicks the test dummy in the junk and it fades out of existence.", TP);
        dummyobj = present("test dummy");
        if (objectp(dummyobj)) {
            dummyobj->move("/d/shadowgate/void");
            dummyobj->remove();
        }
        room = this_object();
        everything = all_living(room);
        for(i = 0; i < sizeof(everything); i++){
            if(!userp(everything[i])){
                message("environment", "Lightning crashes down from on high, obliterating "+everything[i]->query_cap_name()+"!", room);
                everything[i]->move("/d/shadowgate/void");
                everything[i]->remove();
            }
            continue;
        }
        return 1;
    }
    return 0;
}

