// ash-cloth.c

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
	string* color = ({ HIR, RED, HIY, YEL, HIB, BLU, HIG, HIC, CYN, MAG, HIM, HIW, WHT });
	set_name(color[random(sizeof(color))] + "灰烬破烂衣" + NOR, ({ "ash cloth", "cloth", "ash" }) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一件被火焰焚烧过的衣服，已经看不出原先是什么布料，因为大部分已被火焰化为灰烬，\n只剩下几块灰不溜秋的破布挂在上面，看上去随时都可能被风吹成碎片。\n");
		set("unit", "件");
		set("value", 0);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 3);
		set("fire_burned", 1);
	}
	setup();
	call_out("destroy_it", 41+random(20));
}

void destroy_it()
{
	object ob=this_object();
	object me;
	string msg;
	if (!ob)
		return;
	me=environment(ob);
	if( me->is_character() )
	{
		msg= HIY"一阵风吹过，把$N身上的"+ob->query("name")+HIY"吹成了一堆碎布，打着旋随风飘远了……\n"NOR;		
		if (ob->query("equipped"))
		{
		  msg += HIY"你似乎听到有人在尖叫：\n"+HIW"\n    啊！快来看啊，这里有人光屁股了！\n\n"NOR;
		}
		message_vision(msg, me, ob);		
	}
	ob->unequip();
    destruct(ob);
}

