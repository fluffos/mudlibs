// Made by goodtaste
//1999.6.3

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

    int return_normal(object ppl);


void create()
{
	set_name(HIR"归魂剑"NOR, ({ "guihun sword", "sword" }));
	set_weight(10000);
        set("value",1000000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把散发着奇异力量的剑，任何拿起它的人心中都会涌起无穷的仇恨和绝望!\n");
                set("value", 500000);
		set("material", "steel");
                set("weapon_prop/strength", 3);
		set("wield_msg", HIY"一片阴森的气霭从$N身后缓缓升起，只见一道白光从剑鞘之中锵然飞出，"NOR
+HIR"\n这就是武林传说中的\n.........\n..............\n...................\n.............................\n"NOR+HIR"归魂剑，            归魂剑!!!\n" NOR);
		set("unwield_msg", HIY "$N小心的将归魂剑收入鞘中\n" NOR);
	}
	init_sword(250);
	setup();
}

void init()
{
	if(environment()->query("family/pk_master")!="楚 云 飞")
	{
		message_vision("$N"HIY+"猛然发出一声尖利的哀鸣，剑身一颤，顿时寸寸折断！\n"+
		"原来这世上不独人有情，剑亦有义。。。\n"NOR,this_object());
		destruct(this_object());
	}	
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
     if(me->query("shaqi")>280 && me->query("family/pk_master")=="楚 云 飞"
                 && ! me->query_temp("guihun")  )
        {
        me->add_temp("apply/attack",30);
        me->add_temp("apply/dodge", 30);
	me->add("bellicosity",20);
         me->set_temp("guihun",1);
          call_out("return_normal", 10, me);
        return HIR "$N感到杀气上涌,顿时失去心神,与【归魂剑】的邪恶力量合为一体!!" NOR;
 //          remove_call_out("return_normal");
     //        call_out("return_normal",10,me,this_object());
        }

return HIR ">\n" NOR;
}

  int return_normal(object ppl)
{
             ppl->add_temp("apply/attack",-30);
             ppl->add_temp("apply/dodge", -30);
             ppl->add("bellicosity",-20);
       ppl->delete_temp("guihun");
	message("vision",HIW"归魂剑发出低沉的呼啸，"+ppl->name()+"感到身体渐渐放松下来。\n",
	environment(ppl));
	return 1;
}
