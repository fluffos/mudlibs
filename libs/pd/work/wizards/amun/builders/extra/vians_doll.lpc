#include <std.h>
inherit OBJECT;
void create() {
    ::create();
    set_name("doll");
    set_short("A voodoo doll of Vian");
    set_long("A voodoo doll that was carved out of soap, shaped to look like the gremlin Vian.  If you <squeeze> it, something may happen.");
    set_weight(1);
    set_curr_value("gold", 100);
    set_id(({ "doll", "voodoo doll", "doll of vian" }));
    set_property("magic item", ({"squeeze"}) );
}
void init() {
    ::init();
    add_action("cmd_squeeze", "squeeze");
}
int cmd_squeeze(string str) {
    object tp;
    tp = this_player();
    if (str != "doll") return 0;
    write("As you break the doll in half, hands come out of the sky and grab you!\n");
    tell_room(environment(tp), "Hands come out of the sky and grab "+this_player()->query_cap_name()+"!\n", ({ this_player() }));
    call_out("goingalready", 6, tp);
    return 1;
}
int goingalready(object tp) {
    int sps;
    write("\nThe hands drop you in Vian's workroom, and the doll is again in one peice!\n");
    message("info", ""+tp->query_cap_name()+" soars through the sky!", environment(tp), tp);
    if((sps = this_player()->query_sp()) < 0)
	this_player()->set_sp(20);
    this_player()->move_player("/wizards/vian/workroom", "through the sky!");
    this_player()->set_sp(sps);
    return 1;
}
int query_auto_load() {return 1;}
