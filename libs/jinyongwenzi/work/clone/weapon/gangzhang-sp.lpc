// gangzhang.c by caiji@SJ 8/24/2000
#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
        set_name("钢杖", ({ "gangzhang","gang zhang","zhang" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一柄钢杖。\n");
                set("value", 1);
                set("unique", 2);
                set("rigidity", 6);
                set("sharpness", 6);
                set("material", "steel");
                set("weapon_prop/parry", 2);
                set("weapon_prop/dodge", 2);
                set("treasure",1);  
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n背到背后。\n");
        }
        init_staff(70);
        setup();
}
void init()
{
    add_action("do_sub",({"ba", "拔"}));
}

int do_sub(string arg)
{
     object me, obj;
     me = this_player();
     obj = this_object();
     if(arg!="jian" && arg!="剑")
           return 0;
     if((int)me->query("neili") < 150)
                return notify_fail("你感觉全身气血翻腾，原来你真气不够，拔不出青冥剑！\n");
     message_vision(HIY"\n只听唰楞一声，$N从钢杖中拔出一把青色宝剑，原来杖内暗藏玄机。\n"NOR, me);
     me->add("neili", -100);
     new(BINGQI_D("qm-jian"))->move(me, 1);
     new(BINGQI_D("qm-qiao"))->move(me, 1);  
     destruct(obj);
     return 1;
}
