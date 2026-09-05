
// baihehua.c百合花

#include <ansi.h>
inherit ITEM;
void setup()
{}

void create()
{
//           set("no_give",1);
//          set("no_drop",1);
         set_name("百合花", ({ "baihe hua","hua" }));
         set_weight(100);
         if (clonep())
                set_default_object(__FILE__);
         else {
                set("unit", "枝");
                set("long", "一枝娇艳的百合花。\n");
                set("value", 100);
                }
        
        setup();
}
void init()
{
     if(this_player()==environment())
     add_action("apply_medicine","smell");

}

int apply_medicine(string arg)
{
  object me ,ob;
  me = this_player();
  if (!id(arg))
        return notify_fail("你要干什么？\n");
        return notify_fail("百合花闻起来还挺香。\n");
  if ( (int)me->query_condition("hua_smell" ) > 0 )
        {
                me->add("max_jingli", -30);
                message_vision(RED "$N又嗅了一下百合花，顿时天悬地转，原来服食太急,反而伤了身体" NOR, me);
                me->unconcious();
return 1;

        }
                                                                                     
me->apply_condition("hua_smell", 8000);
 
 message_vision(YEL "$N嗅了一下百合花，只觉的一股暖暖的感觉遍及全身....." NOR, me);
 me->unconcious();
return 1;
} 






