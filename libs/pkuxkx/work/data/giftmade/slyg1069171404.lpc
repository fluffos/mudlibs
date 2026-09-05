// necklace	项链
// by bing

#include <armor.h>
#include <ansi.h>

inherit NECK;

void create()
{
	set_name(HIG +"述说之珠"+ NOR, ({ "amulet" }));
	set("long","+1级所有技能,\n防毒+35-50%,\n\n防冰+18%,\n\n攻击者受到反伤害8-10.\n");
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "只");
		set("no_get", 1);
		set("no_drop", "这东西不能扔。\n");
		set("no_steal", 1);
		set("value",1000000);
		set("owner", "slyg");
		set("no_store",1);
		set("auto_load", 1);
		set("material", "gold");
		set("wear_msg",HIG "$N高高兴兴地将"+query("name")+HIG "戴了起来。\n" NOR);
		set("armor_prop/armor", 1);
	}
	setup();
}	

void init()
{
	if (this_player()->query("id")!=query("owner"))
	{
		message_vision(query("name")+"委屈地叫到：「你不是我的主人！」\n",this_player());
		message_vision(query("name")+"从$N的手指上掉了下来，在地上滚了滚，不见了。\n",this_player());
		destruct(this_object());
		return;
	}
}

