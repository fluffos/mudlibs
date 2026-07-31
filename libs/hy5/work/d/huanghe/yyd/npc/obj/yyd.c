// yyd.c 鸳鸯宝刀
// zly 99.6.22

#include <weapon.h>
#include <ansi.h>

inherit BLADE;
inherit F_UNIQUE;
void create()
{
        set_name(HIC"鸳鸯宝刀"NOR,({ "yuanyang dao", "dao","yuanyang","blade" }) );
        set("long", HIC"\n这就是天下闻名的鸳鸯宝刀，据说里面藏着无敌于天下的大秘密。\n"NOR);
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("treasure", 1);
                set("unit", "把");
                set("value", 20000);
                set("unique", 1);
                set("rigidity", 6);
                set("sharpness", 2);
                set("weapon_prop/parry", 10);        
                set("weapon_prop/dodge", 10);
                set("wield_neili", 300);
                set("wield_maxneili", 1500);
                set("wield_str", 25);
                set("wield_msg", HIC"只听见一声轻响，$N抽出鸳鸯宝刀握在手里！\n"NOR);
                set("unwield_msg", HIC"$N将手中的鸳鸯宝刀轻轻地插入刀鞘。\n" NOR);               
        }
          init_blade(880);
        setup();
}

void init()
{
    add_action("do_sub",({"fen", "分"}));
}

int do_sub()
{
     object me,ob, ob1, obj;
     me = this_player();
//     obj = this_object();
     ob = this_object();
     obj = present("yuanyang dao", me);
     if((int)me->query("neili") < 500)
                return notify_fail("你感觉全身气血翻腾，头晕目眩，原来你真气不够，分不开鸳鸯宝刀！\n");
     if((int)me->query_str() < 28)
                return notify_fail("你感觉使尽了全身的力气，也分不开鸳鸯宝刀！\n");
     message_vision(HIY"\n只听一声轻响，$N将鸳鸯宝刀刀柄一按一分，鸳鸯宝刀登时一分为二，分插在$N的两个刀鞘中！\n"NOR, me);
     me->add("neili", -300);
     new(__DIR__"yuan")->move(me, 1);
     new(__DIR__"yang")->move(me, 1);  
     destruct(obj); 
     return 1;

}
