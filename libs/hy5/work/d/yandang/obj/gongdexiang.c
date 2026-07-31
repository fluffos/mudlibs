// box.c 功德箱

#include <ansi.h>

inherit ITEM;

void create()
{
	object money;
	set_name("善缘箱", ({ "shanyuan xiang", "xiang"}));
	set_weight(3000);
	set_max_encumbrance(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
                set("long", "这是一个庙里常见的功德箱，专门用来接受善男信女们的捐款。\n");
		set("material", "wood");
		set("no_get",1);
		set("no_drop",1);
	}
	setup();
	money=new("/clone/money/gold.c");
	money->set_amount(random(3));
	money->move(this_object());
}

int is_container() { return 1; }

void init()
{
	add_action("do_put","put");
}

int do_put(string arg)
{
	object me, obj;
	string item, target; 
	int amount;

	me = this_player();

	if(!arg) return notify_fail("你要将什么东西放进哪里？\n");

	if( sscanf(arg, "%s in %s", item, target)!=2) return 0;
	if( target!="xiang"&&target!="gongde xiang") return 0;
	if (sscanf(item,"%d %s",amount,item)!=2)	{
		if(!objectp(obj=present(item,me)))	return 0;
		if(!obj->query("money_id"))	{
			tell_object(me,"本寺不收这些东西！\n");
			return 1;
		}
		else	{
			tell_object(me,"请问您要捐多少啊？\n");
			return 1;
			}
	}
	if (!objectp(obj = present(item, me)) ) return 0;

	if(!obj->query("money_id"))	{
		tell_object(me,"本寺不收这种东西！\n");
		return 1;
	}
	if(amount>obj->query_amount())	return 0;
	if(amount*obj->query("base_value")>=1000)
	{
		me->set_temp("oldsix_flag/money",1);
			return 0;
		}
	if(amount*obj->query("base_value")<1000)
	{
		tell_object(me,"您的诚意不够！\n");
		message_vision(HIY"$N被善缘箱气的昏了过去！\n"NOR,me);
		return 1;
	}
	return 1;
}
