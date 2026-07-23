// fae_ling.c
// Created by snowman@SJ 08/05/2001

#include <weapon.h>
#include <ansi.h>

inherit DAGGER;
inherit F_UNIQUE;
void create()
{
        set_name(WHT"罚恶令"NOR,({ "fae ling", "fae", "ling", "dagger" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("treasure", 1);
                set("unit", "块");
                set("value", 500000);
                set("unique", 1);
                set("rigidity", 2);
                set("weapon_prop/dodge", 1);
                set("weapon_prop/parry", 1);   
                set("dagger_count", 1);     
                set("material", "bonze");
                set("wield_neili", 30);
                set("wield_maxneili", 500);
                set("wield_str", 15);
                set("wield_msg", WHT"$N摸出一把罚恶令，忍不住奸笑了几声！\n"NOR);
                set("long", WHT"\n一块闪闪发光的白铜牌子，约有巴掌大小，刻的是一张狰狞的煞神凶脸，显得十分诡异！
看来如果有两把，应该能合并(hebing)起来！\n"NOR);
                set("unwield_msg", WHT"$N"WHT"将$n"WHT"收回到口袋里。\n" NOR);               
        }
        init_dagger(60);
        setup();
}

void init()
{
    	add_action("do_add", "合并");
    	add_action("do_add", "hebing");
}

int do_add()
{
     	object me,ob, obj, ling;
     	me = this_player();
     	ob = this_object();
     	obj = present("shangshan ling", me);
     	
     	if(!objectp(obj))
           	return notify_fail("你手中只有一只罚恶令，先找到另一只再说吧。\n");
     	if((int)me->query("neili") < 200)
		return notify_fail("你感觉全身气血翻腾，原来你真气不够，无法将双令合并！\n");
     	if((int)me->query_str() < 25)
		return notify_fail("你感觉全身气血翻腾，原来你力量不够，无法将双令合并！\n");
     	me->add("neili", -150);
     	message_vision(HIW"\n只见$N将两把令牌在手中相互摩擦，一瞬间竟然拉出一道闪电，将两令连在一起！\n"NOR, me);
     	destruct(obj);   
     	ling = new(BINGQI_D("sf_ling"))->move(me, 1);     
     	destruct(ob);
     	return 1;
}
