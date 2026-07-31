// xiangcha.c 酸梅汤

inherit ITEM;
#include <ansi.h>
void init();
void do_eat();

void create()
{
        set_name("酸梅汤",({"suanmei tang", "tang"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一杯热热的酸梅汤，看见就令人流口水～～～\n");
                set("unit", "杯");
                set("value", 10);
                set("remaining", 3);
                set("drink_supply", 30);
        }
        setup();
}

void init()
{
        add_action("do_drink", "drink");
}

int do_drink(string arg)
{

        int recover, jing, e_jing, m_jing;
        
        recover = 5;
        
        if( !this_object()->id(arg) ) return 0;
        if( this_player()->is_busy() )
            return notify_fail("你上一个动作还没有完成。\n");
        if((int)this_player()->query("water")>= (int)this_player()->max_water_capacity() )
            return notify_fail("你已经喝太多了，再也灌不下一滴水了。\n");
        set("value", 0);
        this_player()->add("water", (int)query("drink_supply"));
        jing = (int)this_player()->query("jing");
        e_jing = (int)this_player()->query("eff_jing");
        m_jing = (int)this_player()->query("max_jing");

        if (jing < e_jing ){
          if ( (jing + recover) >= e_jing ){
            this_player()->set("jing", e_jing);
          }
          else {   
            this_player()->set("jing", jing+recover);
          }   
        }
        if( this_player()->is_fighting() ) this_player()->start_busy(2);
        add("remaining", -1);

        if ( query("remaining")){
           message_vision("$N端起杯酸梅汤，有滋有味地品了几口。\n"+
                          "一股酸甜之味直入心头，$N觉得精神好多了。\n", this_player());
        }
        else { 
           message_vision("$N端起小杯，把剩下的酸梅汤一饮而尽。\n"+
                          "一股酸甜之味直入心头，$N觉得精神好多了。\n", this_player());
           destruct(this_object());
        }
        return 1;
}

