#include <std.h>
#include <daemons.h>
#include <security.h>
inherit ROOM;

mapping people;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no castle", 1);
    set("short", "Locker Room");
    set("long",
        "This is a locker room where you can store your junk.  Yes, "
        "this description sucks.  It's just temporary.  Use <store> and <reclaim>");
    set_items( ([ "locker" : "It holds stuff.  yaya." ]) );
    set_exits(([
      "house" : "/wizards/nightshade/workroom"
    ]));
    seteuid(UID_VOTESAVE);
    restore_object("/adm/save/votes/storage");
    seteuid(geteuid());
    if(!people)
      people = ([]);
}

int save_thing(string str) {
    object ob;

    if(!(ob = present(str, this_player()))) {
        write("You do not have that!");
        return 1;
    }
    if(people[this_player()->query_name()] &&
       people[this_player()->query_name()] != "") {
        write("You already have something stored.");
        return 1;
    }
    people[this_player()->query_name()] = base_name(ob);
    seteuid(UID_VOTESAVE);
    save_object("/adm/save/votes/storage");
    seteuid(geteuid());
    write("You put your "+ob->query_short()+" in your locker.");
    ob->remove();
    return 1;
}

int get_thing(string str) {
    object ob;

    if(!people[this_player()->query_name()] ||
       people[this_player()->query_name()] == "") {
        write("You have nothing in your locker.");
        return 1;
    }
    if(this_player()->query_level() > 5) {
        if(this_player()->query_money("gold") < this_player()->query_level() * 4) {
            write("You need "+(string)(this_player()->query_level()*4)+" gold"
                  " to pay for your storage!");
            return 1;
        }
    }
    this_player()->add_money("gold",this_player()->query_level()*4);
    ob = new(people[this_player()->query_name()]);
    people[this_player()->query_name()] = "";
    seteuid(UID_VOTESAVE);
    save_object("/adm/save/votes/storage");
    seteuid(geteuid());
    write("You get your "+ob->query_short()+" from your locker.");
    ob->move(this_player());
    return 1;
}

void init() {
 ::init();
   add_action("save_thing", "store");
   add_action("get_thing", "reclaim");
}
