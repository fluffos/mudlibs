// box.c 功德箱

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(RED "功德箱" NOR, ({ "gongde xiang", "xiang", "box" }) );
	set_weight(3000);
	set_max_encumbrance(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
                set("long", "这是一个小庙里常见的功德箱，专门用来接受善男信女们的捐款。\n");
		set("value", 1000);
		set("material", "wood");
		set("no_get",1);
		set("no_drop",1);
		set("amount",30);
	}
	setup();
}

int is_container() { return 1; }

void init()
{
/*
	if( me->query("combat_exp") <= 5 
	&&  this_object()->query("amount") >=10 
	&&  random(2) == 1 )
	{
		ob=new("/clone/money/silver");
		ob->set_amount(10);
		ob->move(this_object());
		tell_object(me, HIW "\n你忽然看到功德箱里有什么东西在闪闪发光！\n\n" NOR);
		me->add("combat_exp", 1);
	}
*/

	add_action("do_put", "put");
}

int do_put(string arg)
{
	object me, obj;
	string item, target; 
	int amount;

	me = this_player();

	if( !arg || sscanf(arg, "%s in %s", item, target)!=2 
	||  sscanf(item, "%d %s", amount, item)!=2
	||  !objectp(obj = present(item, me)) )
		return 0;

	if( obj->query("money_id") == "silver" 
	&&  obj->query_amount() >= 5 && amount >= 5 ) 
	{
		if( me->query("begger") > 0) {
			message_vision( sprintf(HIY "$N将一%s%s放进%s。\n" NOR,
				obj->query("unit"), obj->name(), 
				this_object()->name()),me );
			obj->set_amount(obj->query_amount() - amount);;
			me->add("begger", (-1)*(amount/5));
			if( me->query("begger") < 0) me->set("begger", 0);
			this_object()->add("amount", amount);
			return 1;
		}
	}
	return 0;
}
