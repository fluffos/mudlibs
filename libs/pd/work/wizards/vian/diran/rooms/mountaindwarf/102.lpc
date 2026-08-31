#include <std.h>
#include <diran.h>

inherit ROOM;
void create() {
    ::create();
    set_properties( (["light" : 2, "no attack" : 1, "indoors":1, "no magic" : 1, "no bump" : 1, "no steal" : 1, "night light" : 1, ]) );
    set_short( "the Mountain Dwarf city" );
set_long("The huge glorious church is a great tribute to the wealth of the community that supports it. A large circular stone is at its center. Every sound resonates harmoniously throughout the temple.");
set_exits(([
"east" : ROOMS"mountaindwarf/95",
"north" : ROOMS"mountaindwarf/97",
"south" : ROOMS"mountaindwarf/101",
"west" : ROOMS"mountaindwarf/99",
]));
    set_items( ([
"stones":"The stones that make up the church are white and polished.",
"windows":"The windows surrounding the church are of stained glass, creating a prism of color in the church.",
"stained glass windows":"The windows surrounding the church are of stained glass, creating a prism of color in the church.",
"candles":"The candles are floating in midair, by some sort of magic.",
"stone":"The stone in the center of the church seems to be a focal point.",
]) );
    set_smell("default",  "The church has a flowery fragrance to it.");
    set_listen("default", "An unpleasant voice seems to be coming from the center of the church.");
}
void init() {
    ::init();
    add_action("insert", "insert");
}

int insert(string str) {
    object ob;
    string *args;
    if(!str) return notify_fail("Insert what in where?\n");
    args=explode(str, " ");
    if(!ob=present(args[0], this_player())) return notify_fail("You do not have that.\n");
    if(ob->query_prevent_drop()) return notify_fail("You cannot let that go.\n");
if(ob->id("diran_quest_ob")) {
if(
            this_player()->set_quest("diran")) {
this_player()->set_stats("intelligence",
this_player()->query_base_stats("intelligence")+1);
this_player()->add_exp(500000);
    message("info", "You place "+ob->query_name()+" into the stone and it begins to glow.  You have solved Kinau's Quest.", this_player());
    message("info", this_player()->query_cap_name()+" places "+ob->query_name()+" into the stone and it begins to glow.",
this_object(), this_player());
            ob->remove();
            return 1;
        }
    }
    message("info", "You place "+ob->query_name()+" into the stone and it vanishes.\nNothing happens.", this_player());
    message("info", this_player()->query_cap_name()+" places "+ob->query_name()+" into the stone and it vanishes.\nNothing happens.",
this_object(), this_player());
    ob->remove();
    return 1;
}
void reset() {
    ::reset();

        if(!present("mdcleric")){
              if( random(100) > 75){ new(MOB "mdcleric")->move(this_object()); }
              if( random(100) > 75){ new(MOB "mdcleric")->move(this_object()); }
}
        if(!present("mdpriest")){
              if( random(100) > 75){ new(MOB "mdpriest")->move(this_object()); }
              if( random(100) > 75){ new(MOB "mdpriest")->move(this_object()); }
}
        if(!present("kinau"))
              new(MOB "kinau")->move(this_object()); 
        if(!present("cstone"))
              new(OBJ "cstone")->move(this_object()); 
}
