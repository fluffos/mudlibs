 // medicine.c
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIC"天山雪莲"NOR,({"snow lotus"}));
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long",
                "一株奇寒无比的，百年一现的天山雪莲！\n");
            set("unit","株");
            set("value", 2000);
        }
       	setup();
} 
void init()
{
  if(this_player()==environment())
        add_action("apply_medicine","yong");
} 
int apply_medicine()
{

        this_player()->set("m_success/天山雪莲");
        this_player()->add("score",200);
this_player()->add("qi",800);
this_player()->add("eff_qi",800);
this_player()->add("jing",800);
this_player()->add("eff_jing",800);
        message_vision("$N一张口，将一株奇寒无比的天山雪莲服入体内！\n",this_player()); 
        destruct(this_object());
        return 1;
}  
