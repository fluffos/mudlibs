// clothing	衣服
// by bing

#include <armor.h>
#include <ansi.h>

inherit SURCOAT;

void create()
{
	set_name(HIG +"黑暗信徒"+ NOR, ({ "shroud" }));
	set("long","\n+305-415点防御力\n\n防火+24%\n\n25%概率在受到攻击时释放出3级的Nova\n\n加入24-34点毒攻击,效果持续2秒\n\n");
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit","个");
		set("no_get", 1);
		set("no_drop", "这东西不能扔。\n");
		set("no_steal", 1);
		set("value",1000000);
		set("owner", "slyg");
		set("auto_load", 1);
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	setup();
}	

void init()
{
	if (this_player()->query("id")!=query("owner"))
	{
		message_vision(query("name")+"委屈地叫到：「你不是我的主人！」\n",this_player());
		message_vision(query("name")+"从$N的身上掉了下来，在地上滚了滚，不见了。\n",this_player());
		destruct(this_object());
		return;
	}
}

