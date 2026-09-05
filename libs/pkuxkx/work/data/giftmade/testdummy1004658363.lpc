// clothing2	衣服(not autoload)
// by bing

#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
	set_name(NOR +"长剑"+ NOR, ({ "changjian" }));
	set("long","goodarmor。\n");;set("unit",\n");
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit","个");
		set("value",50000);
//in case that player may use it to do quest, set no_drop, so cannot give,drop,can sell
		set("no_drop",1);
        set("no_store",1);
      set("no_give",1);
		set("owner", "testdummy");
		set("material", "cloth");
		set("armor_prop/armor",1);
	}
	setup();
}	



