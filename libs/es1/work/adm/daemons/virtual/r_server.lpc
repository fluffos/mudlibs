/*
 * r.c [virtual object compiler]
 * description: a room description language (rdl) compiler
 * history:
 *    05/01/92 [truilkan] - created original file
 *    12/08/92 [wayfarer] - rewritten to use huthar's generic compiler
 *    02/01/93 [truilkan] - modified to work on tmi-2
 * todo:
 *    - add new language features: aliased commands,
 *          messages to other users via automatic commands
 */

#include <config.h>
inherit "/std/virtual/compiler";

#define ROOM_TEMPLATE "/adm/daemons/virtual/template/room"

/*
 * global statics used as state variables
 */
nosave string state;
nosave string current_item;

string extension() { return ".r"; }
string default_base_object()
{
    return ROOM_TEMPLATE;
}

int base_object(string value, object nothing)
{
    int val;

    val = (int)this_object()->make_target(value);
    if (!val) {
        write ("Error loading template object "+value + "\n");
        return 0;
    }
    return 1;
}

int description(string value, object ob)
{
    ob->set_description(value);
    return 1;
}

int name(string value, object ob)
{
    ob->set_name(value);
    return 1;
}

void add_aliased_exit(string *cmds, string room, object ob)
{
    int i;
    mapping exits;

    exits = ([]);
    for (i = 0; i < sizeof(cmds); i++)
    exits[cmds[i]] = room;
    ob->add_exits(exits);
    return;
}

int exit(string value, object ob)
{
    string cmd, room, *cmds;
    mapping e;
    int i;

    if (sscanf(value,"%s %s",cmd,room) != 2)
        return 2;
    if (cmds = explode(cmd,","))
        add_aliased_exit(cmds,room,ob);
    else {
        e = ([]);
        e[cmd] = room;
        ob->add_exits(e);
    }
    return 1;
}

// note: should this cause the compile to fail when the object doesn't load?
int obj(string value, object ob)
{
  object thing;
  string *pf;

    pf = path_file(filename);
    value = replace_string(value,"./",pf[0] + "/");
    thing = new(value);
    if (thing)
    thing->move(ob);
    return 1;
}

int load(string value, object ob)
{
  object thing;
  string *pf;

    pf = path_file(filename);
    value = replace_string(value,"./",pf[0] + "/");
    thing = call_other(value, "???");
    return 1;
}

int light(string value, object ob)
{
    int val;

    sscanf(value, "%d", val);
    ob->set_light(val);
    return 1;
}

int action(string value, object ob)
{
    return 1;
}

int item(string value, object ob)
{
    string *items;

    if (current_item) {
        write
        ("*Compile error:  didn't finish defining item "+current_item+"\n");
        return 2;
    }
    items = explode(value,",");
    if (items && sizeof(items)) {
        current_item = items[0];
        ob->add_room_item_with_aliases(items[0],items[1..(sizeof(items)-1)]);
    } else {
        current_item = value;
        ob->add_room_item(value);
    }
    return 1;
}

int item_description(string value, object ob)
{
    if (!current_item) {
        write ("*Compile error: no item to describe.\n");
        return 2;
    }
    ob->describe_item(current_item,value);
    return 1;
}

void item_done()
{
    current_item = 0;
}
