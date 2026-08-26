#include <std.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("projector");
    set("id",({"projector","overhead"}));
    set_short("An overhead projector");
    set_long(
     "A very expensive overhead projector\n"+
     "  Type <project filename> to show a slide\n"+
     "  Type <unload> to remove a slide\n"
    );
}

void init() {
    ::init();
    add_action("project","project");
    add_action("unload","unload");
}

int project(string file) {
    write("projecting "+file+"\n");
    file=resolv_path(this_player()->get_path(),file);
    say(read_file(file,1,$));
    return 1;
}

int unload() {
    write("slide removed\n");
    return 1;
}
