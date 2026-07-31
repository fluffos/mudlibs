#include <weapon.h>
#include <ansi.h>

inherit AXE;

void create()
{
        set_name(HIY"离魂子母环"NOR,({ "zimu huan", "huan","axe" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {

                set("unit", "把");
               set("treasure",1);
               set("value", 80);
               set("unique", 1);
                set("rigidity", 1);
                set("sharpness", 1);    
                set("material", "steal");
                set("wield_msg",HIW"只听“呛啷啷”一阵乱响，$N将离魂子母环握在手中。\n"NOR);
                set("long", WHT"\n这是件极凶狠的外门兵刃，上有暗扣，似乎可以和另一兵刃组合（zuhe）成一件。\n"NOR);               
                set("unwield_msg", HIW "$N小心地把离魂子母环收入怀中。\n"NOR);               
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
     obj = present("wanzi duo", me);
     if(!objectp(obj))
           return notify_fail("你要把离魂子母环和什么东西组合？\n");
     me->add("neili", -10);
     message_vision(BLU"\n只听“喀”地一声轻响，万字梅花夺和离魂子母环组合成了一把子母鸳鸯钺。\n"NOR, me);
     destruct(obj);   
     new(__DIR__"yuanyang-yue")->move(me, 1);     
     destruct(ob);
     return 1;
}

