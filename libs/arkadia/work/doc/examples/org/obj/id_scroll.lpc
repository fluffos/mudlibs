/* An example of an identify scroll
 *
 * Made by Nick
 */

inherit "/std/scroll";

#include <stdproperties.h>
#include <macros.h>
#include <cmdparse.h>
#include <ss_types.h>

#define ID_STRENGTH	40

void
create_scroll()
{
    set_name("scroll");
    set_adj("identify");
    set_long("Some readable text is written on an old parchment.\n");

    add_prop(OBJ_I_VALUE, 678);
    add_prop(OBJ_I_WEIGHT, 40);
    add_prop(OBJ_I_VOLUME, 254);

    add_prop(OBJ_S_WIZINFO, "An idscroll you can read and recite.\n");
    add_prop(MAGIC_AM_MAGIC, ({ID_STRENGTH, "enchantment"}) );

    set_file("/d/Genesis/doc/examples/obj/book");
}

void
init()
{
    ::init();

    add_action("recite", "recite");
}

int
recite(string str)
{
    string name, *tmp, text;
    object ob, *obj;
    int i, skill;
    mixed info;

    notify_fail("Recite scroll <what>?\n");
    if (!str)
	return 0;

    tmp = explode(str, " ");
    if (!str || (tmp[0] != "scroll" && tmp[0] != "identify"))
	return 0;

    name = "";
    for (i = 1; i < sizeof(tmp); i++)
	if (strlen(name))
	    name += " " + tmp[i];
	else
	    name += tmp[i];

    notify_fail("Couldn't find '" + name + "'\n");
    if (!strlen(name))
	return 0;

    obj = FIND_STR_IN_OBJECT(name, this_player());
    if (!sizeof(obj))
	obj = FIND_STR_IN_OBJECT(name, environment(this_player()));

    if (!sizeof(obj))
	return 0;

    ob = obj[0];

    skill = ID_STRENGTH; /* Base value of this id scroll */
    skill += this_player()->query_skill(SS_LANGUAGE) / 5 + 
	this_player()->query_stat(SS_WIS) / 10;
    skill -= ob->query_prop(MAGIC_I_RES_IDENTIFY);
    if (skill < 0)
	skill = 0;

write("Skill: " + skill + "\n");
skill = 0;

    info = ob->query_prop(MAGIC_AM_ID_INFO);
    for (i = 0; i < sizeof(info) / 2; i++)
	if (skill >= info[i * 2 + 1])
	    text = info[i * 2];

    say(QCTNAME(this_player()) + " recites an identify scroll.\n");
    write("You recite the scroll on the " + ob->short() + ".\n");
    if (text)
	write("\t" + text);
    else
	write("You don't discover any special information.\n");

    write("\nThe scroll helps you appraise the object better:\n");
    ob->appraise_object(skill + 100);

    call_out("remove_object", 1); /* This scroll id 1 time */

    return 1;
}

/*
 * Someone tries to dispel the magic in the scroll
 */
int
dispel_magic(int num)
{
    object ob; 

    if (num > ID_STRENGTH)
    {
  	ob = environment(this_object());
	if (ob && living(ob))
	{
	    tell_object(ob, "Your scroll glows black and crumbles to dust.\n");
	    say("The scroll " + QTNAME(ob) + " is holding glows black " +
		"and crumbles to dust.\n", ob);
        } else
	    say("The scroll glows black and crumbles to dust.\n");

	call_out("remove_object", 1);
	return 1;
    }

    return 0;
}

