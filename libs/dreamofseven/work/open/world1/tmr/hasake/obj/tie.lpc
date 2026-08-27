#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIC"快雪時晴帖"NOR, ({ "kuaixueshiqing tie", "tie"})); 
       
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("unit", "張");
                set("weight", 300);
		set("long", "這是晉王羲之所寫之帖，紙冊本，縱二三寸，橫一四寸。\n");
		set("material", "paper");
		}
	setup();
}