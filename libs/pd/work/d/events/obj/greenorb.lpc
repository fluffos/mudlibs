//  Whit

#include <std.h>

inherit OBJECT;

string COLOR, *all;

string query_color_orb() { return COLOR; }

void get_orb_color() {
    string f, co;

    f = file_name(this_object());
    sscanf(f, "/d/events/obj/%sorb", co);
    COLOR = co;
}

void create() {
    get_orb_color();
    ::create();
    all = ({"red","green","blue","yellow"});
    set_name(COLOR+" orb");
    set_short("a "+COLOR+" orb");
    set_long("The orb is a bright "+COLOR+" color.");
    set_id( ({"orb",COLOR+" orb"}) );
    call_out("check_status", 4);
}


