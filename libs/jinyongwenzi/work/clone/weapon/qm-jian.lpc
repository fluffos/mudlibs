// qingming-jian.c by caiji@SJ 8/24/2000
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name(CYN"青冥剑"NOR, ({"qingming jian", "sword", "jian","qingming"}));
        set_weight(15000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "此剑牵扯无数江湖恩怨，有四百年的来历，剑鞘十分精美。\n"+
"长二尺九，宽一寸一，护手一寸，宽二寸六，厚七寸，两耳各一寸五。\n"+
"剑柄很重，镶有七星，从剑的旋纹看，是先秦吴国的铸剑法，到汉朝就失传了。\n");
                set("value", 1);
                set("unique", 2);
                set("rigidity", 6);
                set("sharpness", 6);
                set("material", "steel");
                set("weapon_prop/parry", 2);
                set("weapon_prop/dodge", 2);
                set("treasure",1);       
                set("wield_neili", 500);
                set("wield_maxneili", 700);
                set("wield_str", 20);
                set("wield_msg",HIC"\n只听「唰」的一声，$N手里多了一把青光四射的宝剑，发出嗡嗡的声音！\n"NOR);
                set("unwield_msg",HIC"$N把手中的青冥剑放了下来。"+
                "此剑刚柔相济，才得治道。似乎从中还能领悟出一些做人的道理。\n"NOR);
        }
        init_sword(50);
        setup();
}
void init()
{
    add_action("do_add", "插");
    add_action("do_add", "cha");
}

int do_add(string arg)
{
     object me,ob, obj, zhang;
     me = this_player();
     ob = this_object();
     obj = present("jian qiao", me);
     if(arg!="jian" && arg!="剑")
           return notify_fail("你想插什么东西啊！\n");
     if(!objectp(obj))
           return notify_fail("你没有剑鞘，想把剑插到哪里去啊！\n");
     if((int)me->query("neili") < 150)
                return notify_fail("你感觉全身气血翻腾，原来你真气不够，无法将剑插入剑鞘！\n");
     me->add("neili", -100);
     message_vision(HIY"\n只听唰楞一声，$N把青冥剑插入剑鞘中，成为一根很粗的钢杖。\n"NOR, me);
     destruct(obj);   
     zhang = new(BINGQI_D("gangzhang-sp"))->move(me, 1);     
     destruct(ob);
     return 1;
}
     