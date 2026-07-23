// xiongdan.c
inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_eat", "eat");
        }

/*void destdan()
{
        object ob;
        message_vision("$N慢慢被风吹着，一会就不再新鲜了。\n",this_object());
        ob = new(__DIR__"xiongdan1");
        ob->move(environment(this_object()));
        destruct(this_object());
}*/

void create()
{
        set_name(HIG"熊胆"NOR, ({"dan", "xiong dan"}));
        set("unit", "副");
        set("long", GRN"这是一副熊胆，已经不太新鲜了，但仍然十分诱人,好象善良之辈不宜如此荤腥。\n"NOR);
        setup();
}

int do_eat(string arg)
{
        mapping fam;    
        object me=this_player();
        if (!id(arg))  return notify_fail("你要吃什么？\n");
        if(arg=="dan")
        {
         if((int)me->query_condition("medicine"))
         return notify_fail("你闻到一股血腥的味道，无论如何无法入口！\n");              
        if ( mapp(fam = me->query("family")) 
            && ( me->query("family/family_name") == "丐帮"
            || me->query("family/family_name")=="星宿派" 
            || me->query("family/family_name")=="神龙教" 
            || me->query("family/family_name")=="少林派") )
        {
            me->add("max_neili",2);
        //me->set("neili",me->query("max_neili"));
        //      me->set("qi",me->query("eff_qi"));
                message_vision("$N吃下一副熊胆，只觉得精神健旺，体内真力源源滋生，气血充盈。\n",me);
                me->apply_condition("medicine",60);
                me->apply_condition("medicine",60); 
                destruct(this_object());
                return 1;    
        }
        else {
           message_vision("$N不顾多年吃药练气和行善积德的德行，强行茹毛饮血，当场得报。\n",me); 
           me->unconcious();               
           me->add("max_neili",-10);
           me->apply_condition("medicine",60);
           destruct(this_object()); 
            return 1;
            }
          }
        return 1;
}
