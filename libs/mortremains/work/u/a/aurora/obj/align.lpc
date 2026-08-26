//Created by Gideon, revised by Tobin aka Chris Dailey 2-95

#include <std.h>
#define ENV(str)	environment(str)
#define TO		this_object()
#define TP		this_player()

inherit OBJECT;

void create ()
{
    ::create();
    set_name("white box");
    set_id( ({"box","checker"}) );
    set_short("A small white box");
    set_long("A small white cube that fits into the palm of your hand.\n"
       "There's an inscription on the bottom.");
    set_weight(20);
    set_value(500);
    set("read","This small alignment checker can be used by typing \n"
       "align <monster> \n");
}

void init()
{
    ::init();
    add_action("align","align");
}

int align(string str)
{
    int num;
    object ob;

    if(!str)
    {
	notify_fail("What should I check, master?");
	return 0;
     }

    ob = present(str, ENV(TP));
    if(!ob)
    {
	notify_fail("That is not here.\n");
	return 0;
    }
    num = ob->query_alignment();
    write(ob->query_name()+" is aligned at <"+num+">.\n");
    return 1;
}
