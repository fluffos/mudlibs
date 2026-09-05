// bagua.c 铁八卦

inherit ITEM;
#include <ansi.h>

void setup()    {}
void init()
{
        add_action("do_strike", "pai");
}

void create()
{
        set_name(HIG"铁八卦"NOR, ({ "tie bagua","bagua"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "枚");
                set("long","这是一枚桃花岛弟子用的铁八卦。\n");
                set("value", 7000);
                set("unique", 3);
                set("material", "iron");
        }
        setup();
}

int do_strike(string arg)
{
        object me = this_player();

        if (!id(arg))
                return notify_fail("你要拍什么?\n");

        if( me->query_skill("qimen-bagua",1)<30 )
               return notify_fail("你的奇门八卦修为不够，不能使用铁八卦练功。\n");
      
        if ( me->query("family/family_name") == "桃花岛" ){
               if (random(2) == 1){
                       if (me->query_skill("strike", 1) < 100) {                                                   
                              if (me->query("qi")<=30)
                                      return notify_fail("你太累了，休息一会吧。\n");   
                              message_vision("$N用力击向铁八卦，自觉掌法有所进益。\n", me);
                              me->add("qi", -(10+random(me->query_skill("strike",1))/6));
                              me->improve_skill("strike", random(me->query_int()/2)+me->query_int()/2);
                              return 1;
                       }
                       else{                   
                              if( me->query("thd/lyz") == 2 
                                && me->query("jiali") > 100
                                && !(int)me->query_skill("luoying-zhang", 1)
                                && random(me->query_kar()) > 20){
                                       this_player()->set("thd/lyz", 3);
                                       me->set_skill("luoying-zhang", 3);
                                       message_vision("$N用力击向铁八卦，$N的落英神剑掌进步了。\n", me);
                                       return 1;
                                }                                                      
                        }                                                       
                } 
        }      
        return notify_fail("你用力拍向铁八卦，只听得'啪'的一声，你虎口震裂，痛得你几乎弯下腰去。\n");
}

