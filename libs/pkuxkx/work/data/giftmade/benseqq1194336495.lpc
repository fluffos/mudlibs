// necklace	项链
// by bing

#include <armor.h>
#include <ansi.h>

inherit NECK;

void create()
{
	set_name(HIW +"七窍玲珑心"+ NOR, ({ "necklace" }));
	set("long","由七种绝世奇晶经妙手组合而成的美丽项链，举世无双，\n由qianr亲自挂在benseqq的发髻上，绽放出七彩的光芒。\n\n");
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "只");
		set("no_get", 1);
		set("no_drop", "这东西不能扔。\n");
		set("no_steal", 1);
		set("value",1000000);
		set("owner", "benseqq");
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

