
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("储物箱", ({ "chuwu xiang", "box", "xiang"}));
	set_weight(1);
	set_max_encumbrance(1000000);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一个红木储物箱，可以装很多很多的东西。\n");
			set("material", "steel");
			set("unit", "个");
			set("value", 1);
			set("no_get","这个大箱子太沉了，恐怕你抬不起来。\n");
		}
		setup();
}

void init()
{
	add_action("do_write", ({ "write", "xie" }));
	add_action("do_get", ({ "get", "qu" }));
}

int do_write()
{
	if(this_object()->query("owner"))
		{
			tell_object(this_player(),"这个箱子已经有主人了，你去领自己的箱子。\n"NOR);
		}
	else
		{
			this_object()->set("owner",this_player()->query("id"));
			this_object()->set("name", this_player()->query("name")+"的储物箱");
			this_object()->set("id", this_player()->query("id")+"'s box");
			tell_object(this_player(),HIW"你在储物箱上写上了自己的名字。\n"NOR);
		}
	return 1;
}

int do_get(string arg)
{
	int i; 
	object* allobject;
	if ( !arg ) 
		{
		return notify_fail("你要拿什么？\n");
		}
	else
	{
		if ((this_player()->query("id"))!=(this_object()->query("owner")))
			{
				tell_object(this_player(),HIG"不要拿别人的东西。\n"NOR);
				return 1;
			}
		else
			{
				allobject = all_inventory(this_object());
				for(i=0;i<sizeof(allobject);i++)
					{	
						allobject[i]->move(this_player());
					}
				tell_object(this_player(),HIY"你取回了自己保管的东西。\n"NOR);
				tell_object(this_player(),HIW"箱子上一道流光闪了闪，就消失不见了。\n"NOR);
				destruct(this_object());
				return 1;
			}
	}
}