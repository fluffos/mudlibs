// clothing2	衣服(not autoload)
// by bing

#include <armor.h>
#include <ansi.h>

inherit WRISTS;

void create()
{
	set_name(HIR +"名字"+ NOR, ({ "ＩＤ" }));
	set("long","LONG\n");
	set_weight( 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit","个");
		set("value",50000);
//in case that player may use it to do quest, set no_drop, so cannot give,drop,can sell
		set("no_drop",1);
        set("no_store",1);
      set("no_give",1);
		set("owner", "OWNER");
		set("material", "cloth");
		set("armor_prop/armor",ARMOR);
	}
	setup();
}	



