//cwbdao.c
#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;

void create()
{
	set_name(HIR"闯王宝刀"NOR, ({ "chuangwang baodao", "blade","baodao" }) );
	set_weight(8000);
	set("no_sell",1);
	set("no_pawn",1);
	set("no_store",1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "柄");
        	set("value", 180000);
        	set("material", "iron");
        	set("long", "这是闯王所使用过的刀，上面刻有几行小字。\n" );
        	set("wield_msg","一道白光，$n已在$N手中，只觉青光四射，寒气透骨，不禁机伶伶的打个冷战。\n");
        	set("unwield_msg", "$N将$n插回腰间，华光顿敛。\n");
                set("unique",1);
                set("preorder",0);
                set("robinterval",3600);  

	}
	init_blade(180);
	setup();
}
