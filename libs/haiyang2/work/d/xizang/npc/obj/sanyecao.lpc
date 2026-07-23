 // medicine.c
inherit ITEM;
#include <ansi.h> 
void create()
{
    set_name(GRN"三叶凤尾草"NOR,({"sanyecao"}));
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long",
                "一棵已经晾干的三叶凤尾草，淡淡散发着草香，可以用来（yong）疗伤。\n");
        set("unit","棵");
        set("value", 20000);
        }
} 
void init()
{
  if(this_player()==environment())
        add_action("apply_medicine","yong");
} 
int apply_medicine()
{
    int value = 250;
        int diff; 
        if(this_player()->is_fighting())
            return notify_fail("战斗中不能用药！！\n");
        diff = this_player()->query("max_qi")-this_player()->query("eff_kee");
        if(!(diff))    return notify_fail("你没有受伤！\n");
        if(value > diff) value = diff;
            
    message_vision("$N缓缓把三叶凤尾草嚼下，伤势慢慢愈合起来。。\n",this_player());
        this_player()->add("eff_kee",value);
        destruct(this_object());
        return 1;
}  
