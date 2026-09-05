// 乾坤剑
// created by zine 25 Aug 2010
#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void dest();
void check();
void create()
{
        set_name(HIR"神兵天威"NOR,({ "shen bing", "bing", "sword" }) );
        set_weight(1200);
		if( clonep() )
			set_default_object(__FILE__);
        else 
			{
				set("unit", "团");
				set("value", 0);
				set("material", "steel");
				set("long", "这是一团剑气。\n");
				init_sword(150+random(50));
			}
        setup();
        call_out("check",1);
        call_out("dest",100);
}

