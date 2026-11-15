// item.c

#include <dbase.h>
#include <move.h>
#include <name.h>

inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_MOVE;
inherit F_NAME;

nosave string s_name;
nosave string s_id;

void setup()
{
	seteuid(getuid());
}

void set_name(string name, string *id)
{
	::set_name(name, id);
	s_name = ::query("name");
	s_id = ::query("id");
}

string short()
{
	return s_name + "(" + this_object()->real_id() + ")";
}

void clean_me()
{
 
	object env;

	env = environment();

	if (env->is_character())
	{
		remove_call_out("clean_me");
		return;
	}

	destruct(this_object());
	return;
}

int fire(object me, object ob)
{
	string msg;

	if (this_object()->is_item_make())
		return notify_fail("你累得满头大汗，怎么点也点不着。\n");

	if (stringp(msg = query("no_light")))
		return notify_fail(msg);

	switch (query("material"))
	{
	case "wood":
		msg = "$N把$n放在$f下面点燃了，火光闪动，渐渐只剩下了一团碳粉碎渣。\n";
		break;
	case "leather":
	case "feather":
	case "silk":
		msg = "$N用$f把$n点着了，结果散发出一阵令人难闻的臭味。\n";
		break;
	case "paper":
	case "cloth":
		msg = "$N点着了$n，火苗闪了几闪，很快就烧了个干干净净，什么都没有剩下来。\n";
		break;
	default:
		return notify_fail("这东西看上去没法点，还是省省力气吧。\n");
	}

	msg = replace_string(msg, "$n", name());
	msg = replace_string(msg, "$f", ob->name());
	message_vision(msg, me);
	destruct(this_object());
	return 1;
}

int query_autoload() { return 1; }