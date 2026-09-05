// 扫把 saoba.c
//create by zine 27 aug 2010

#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void create()
{
	set_name("扫把", ({ "sao ba" }));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄大扫把。\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插到背后。\n");
		}
	init_staff(1);
	setup();
}

void init()
{
	add_action("do_break", ({ "break", "zhe"}));
}



int break2()
{
	object me = this_player();
	object saoba,ob = new("/biwu/xy/obj/saobaba"),ob2=new("/biwu/xy/obj/saobatou");
	if (ob && ob2) 
		{
			if(me->is_busy() || me->is_fighting())
				{
					return notify_fail("你正忙着哪！\n");
				}
			else 
				{
					ob->move(me);
					ob2->move(me);
					
					destruct(this_object());
				}
		}
	return 1;
}

int do_break()
{ 
    
	message_vision("$N把扫把用力折断，变成扫把把子和一个扫把头。\n", this_player());
	break2();
	return 1;
}