 // zhonglou.c 钟楼

#include <ansi.h>

inherit ROOM;
string zhong(object);
string chu(object);
void create()
{
        set("short",NOR "钟楼");
        set("long",@LONG
这里是大轮寺钟楼，每逢早、中、晚，或者要召集众喇嘛的时候，都要和
鼓楼同时敲响。钟楼内挂一口千斤大钟( zhong)，厚约有一寸，钟旁悬有一个
巨大的钟槌(chui)，看来也有上百斤。如果没有一定的外功修为和相当的内功
是无法敲响的。
LONG);
        set("exits",([
                "east": __DIR__ "huilang1",
        ]));

        setup();
 
}
string gu(object me)
{
     return "这是一口用生铜铸造成的大钟。\n";
 }
string chui(object me)
{
     return "这是一个巨大的包铁木槌，长约六尺，碗口粗细。\n";
 }
void init()
{
     add_action("do_strike", "ji"); 
}
int do_strike(string arg)
{
            object me = this_player();

                if (!living(me)) return 0;
                if (arg != "zhong" && arg != "dazhong")
           return notify_fail("你要敲击什麽？\n");

                if ( (int)me->query_str() < 30 )
	  return notify_fail("你使出吃奶的力气推动鼓槌，大钟颤了几下，没什么动静。\n");

	  if ( (int)me->query_skill("longxiang-boruo", 1) < 81 )
	  return notify_fail("大钟发出咣的一声巨响，震得你头晕耳鸣，你内功修为尚浅，还是快走吧。\n");
                
                if ( (int)me->query_skill("hammer", 1) > 101 )
	  return notify_fail("你轻松地推动鼓槌敲击大钟，大钟发出阵阵巨响。\n");
               
                if ( ((int)me->query("jingli") < 40 ) ||  ((int)me->query("qi") < 40 ) )
	  return notify_fail("你感觉已经无力再去敲击敲钟了。\n");

	        me->add("qi", -20);
               me->add("jingli", -20);
              message_vision("$N推动钟槌，向大钟敲去，顿时钟声震撼着整个大轮寺。\n", me);
              me->improve_skill("hammer",me->query_int());
	  return 1;
}