// 乾坤剑
// created by zine 25 Aug 2010
#include <weapon.h>
#include <ansi.h>
inherit SPEAR;
void dest();
void check();
void create()
{
        set_name(HIR"神兵天威"NOR,({ "shen bing", "bing", "spear" }) );
        set_weight(1200);
		if( clonep() )
			set_default_object(__FILE__);
        else 
			{
				set("unit", "束");
				set("value", 0);
				set("material", "steel");
				set("long", "这是一束枪影。\n");
				init_spear(150+random(50));
			}
        setup();
        call_out("check",1);
        call_out("dest",100);
}

void dest()
{
    object ob=this_object();
    if (ob)
    {
        ob->unequip();
        destruct(ob);
    }
    return;
}

void check() 
{ 
    object me;
    object ob=this_object();
    me=environment(ob);
	if(!me
    || !userp(me)
	|| !living(me)
	|| !me->is_fighting())
	{
	  ob->unequip();
		destruct(ob);
		return;
	}
    call_out("check", 1); 
} 