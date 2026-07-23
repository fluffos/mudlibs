#include <weapon.h>
#include <ansi.h>

inherit BLADE;
inherit F_UNIQUE;
void create()
{
        set_name(HIY"伏魔金铙"NOR,({ "fumo nao", "nao","fumo" }) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("treasure", 1);
                set("unit", "副");
                set("value", 500000);
                set("unique", 1);
                set("rigidity", 3);
                set("sharpness", 1);
                set("weapon_prop/dodge", -5);
                set("weapon_prop/parry", 5);        
                set("material", "gold");
                set("wield_neili", 100);
                set("wield_maxneili", 700);
                set("wield_str", 22);
                set("wield_msg",HIY"只听见「唰」地一声，伏魔金铙飞出$N手中，闪出道道金光，威声震天！\n"NOR);
                set("long", HIY"\n这是用纯金打造的一副金铙的右半副，直径二尺有三，上面刻满伏魔真言。
如果找到左半副，应该可以将两副金铙合(合)起来。\n"NOR);               
                set("unwield_msg", HIY "伏魔金铙向半空飞出，又飞回了$N的手中。\n"NOR);               
        }
        init_blade(80);
        setup();
}

void init()
{
	if (environment()==this_player()) {
		add_action("do_add", "合");
		add_action("do_add", "he");
	}
}

int do_add()
{
     object me,ob, obj, nao;
     me = this_player();
     ob = this_object();
     obj = present("zhanyao nao", me);
     if(!objectp(obj))
           return notify_fail("你手中只有一只伏魔金铙，先找到另一只再说吧。\n");
     if((int)me->query("neili") < 500)
		return notify_fail("你感觉全身气血翻腾，原来你真气不够，无法将双铙合并！\n");
     if((int)me->query_str() < 28)
		return notify_fail("你感觉全身气血翻腾，原来你力量不够，无法将双铙合并！\n");
     me->add("neili", -300);
     message_vision(HIY"\n只听霹雳一声巨响，两只金铙向半空飞出，然后合二为一，又飞回了$N的手中。\n"NOR, me);
     destruct(obj);   
     nao = new("/clone/weapon/jinnao")->move(me, 1);     
     destruct(ob);
     return 1;
}
