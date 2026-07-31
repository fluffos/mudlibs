#include <weapon.h>
#include <ansi.h>

inherit AXE;

void create()
{
          set_name(HIC"子母鸳鸯钺"NOR,({ "yuanyang yue", "yue", "axe" }) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {

                set("unit", "把");
                set("value", 80);
                set("treasure",1);
                set("unique", 1);
                set("rigidity", 3);
                set("sharpness", 1); 
                set("material", "steal");
                set("wield_neili", 50);
                set("wield_maxneili", 500);
                set("wield_msg",HIC"$N伸手一抄，自腰间抽出柄子母鸳鸯钺，却像是有电光一闪，森冷的寒气，砭骨生寒。\n"NOR);
                set("long", HIC"\n这把鸳鸯钺形状古朴，黝黑中带着墨绿并无耀眼\n的光芒，但指尖一触斧身，便觉寒气直透心腑。\n"NOR);
                set("unwield_msg", HIC "$N把手中的子母鸳鸯钺收入腰间。\n"NOR);     
        }
        init_axe(600);
        setup();
}

void init()
{
    add_action("do_sub",({"fenjie", "分解"}));
}

int do_sub()
{
     object me,ob, ob1, obj;
     me = this_player();
     obj = this_object();
     if((int)me->query("neili") < 100)
               return notify_fail("你感觉全身气血翻腾，原来你真气不够，分解不了子母鸳鸯钺！\n");
     if((int)me->query_str() < 20)
               return notify_fail("你感觉全身气血翻腾，原来你力量不够，分解不了子母鸳鸯钺！\n");

     message_vision(HIW"\n$N将子母鸳鸯钺分解为离魂子母环和万字梅花夺！\n"NOR, me);
     me->add("neili", -30);
     new(__DIR__"zimu-huan")->move(me, 1);
     new(__DIR__"wanzi-duo")->move(me, 1);
     destruct(obj); 
     return 1;

}

