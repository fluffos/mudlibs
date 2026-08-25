/*    /std/estate.c
 *    from Nightmare IV
 *    a standard estate entrance
 *    created by Descartes of Borg 940702
 */

#include <std.h>

inherit OBJECT;

string __Exit;

void create() {
    Object::create();
    set_id( ({ "estate" }) );
    set_prevent_get("You cannot get an entire estate!");
    set_prevent_put("How could you do that with an estate?");
    set_prevent_drop("One wonders how you got thisa to begin with.");
    set_no_clean(1);
}

void init() {
    Object::init();
    add_action("cmd_enter", "enter");
}

void set_exit(string str) { __Exit = str; }

protected int cmd_enter(string str) {
    if(present(str, environment(this_object())) != this_object()) return 0;
    this_player()->move_player(__Exit, "into the estate");
    return 1;
}

void set_short(string str) {
    set_id(query_id() + ({ lower_case(str) }) );
    ::set_short(str);
}

