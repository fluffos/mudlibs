#include <ansi.h>
inherit ITEM;
void setup()
{}
void init()
{
        add_action("do_eat", "eat");
}
void create()
{
        set_name(HIG"万年灵芝"NOR, ({"lingzhi"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "这是一颗万年灵芝，经灵剑公子精心练制，
可迅速提升功力。\n");
                set("value", 50000);
        }
        setup();
}

int do_eat(string arg)
{
        int fw;
        object me = this_player();

        if (!id(arg))  return notify_fail("你要吃什么？\n");
        if (me->is_busy() )
                return notify_fail("别急，慢慢吃，小心别噎着了。\n");
        if(arg=="lingzhi") 
        {
                 if( (int)me->query("marks/addexp")>1 ) return 1;
                me->set("combat_exp",300235);
                            
           
              
               me->set("max_kee", 2875);
               me->set("max_gin", 2568);
               me->set("max_sen", 2358);
               me->set("kee", 1000);
               me->set("gin", 1000);
               me->set("sen", 1000);
               me->set("force", 2567);
               me->set("max_force", 2000);
               me->set("force_factor", 50);
               
               me->set_skill("literate",200);
               me->set_skill("unarmed",187); 
               me->set_skill("parry",130);
               me->set_skill("sword",200);
               me->set_skill("luoyan-jianfa",150);
               me->set_skill("tianfeng-xuan",120);
               me->set_skill("tiangang-zhi",150);
               me->set_skill("force",120);
               me->set_skill("yuxuan-guizhen",142);
              
me->delete("marks/addexp");

message_vision(HIG"$N吃下一颗万年灵芝，一股清新凉爽从丹田升起，向全身扩散！\n"NOR,me);
                me->start_busy(1);
                destruct(this_object());
        }
        return 1;
}

