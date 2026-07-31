#include <weapon.h>
#include <ansi.h>

inherit AXE;
void create()
{
        set_name(HIY"万字梅花夺"NOR,({ "wanzi duo", "duo","axe" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {

                set("unit", "把");
                 set("treasure",1);
                 set("value", 70);
                 set("unique", 1);
                set("rigidity", 1);
                set("sharpness", 1);    
                set("material", "steal");
                set("wield_msg",YEL"$N把万字梅花夺握在手中。\n"NOR);
                set("long", YEL"\n这是件极凶狠的外门兵刃，上有暗扣，似乎可以和另一兵刃组合（zuhe）成一件。\n"NOR);                
                set("unwield_msg", YEL "$N把手中的万字梅花夺收了起来。\n"NOR);               
        }
        init_axe(300);
        setup();
}

void init()
{
    add_action("do_add",({"zuhe", "组合"}));
}


int do_add()
{
     object me,ob, obj;
     me = this_player();
     ob = this_object();
     obj = present("zimu huan", me);
     if(!objectp(obj))
           return notify_fail("你要把万字梅花夺和什么东西组合？\n");
     me->add("neili", -10);
     message_vision(BLU"\n只听“喀”地一声轻响，万字梅花夺和离魂子母环组合成了一把子母鸳鸯钺。\n"NOR, me);
     destruct(obj);
     new(__DIR__"yuanyang-yue")->move(me, 1);     
     destruct(ob);
     return 1;
}

