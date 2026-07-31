// caoyuan3.c 草原
inherit ROOM;

#include <ansi.h>

void create()
{
        set("short", "草原");
        set("long", @LONG
你走进了这遍绵绵不绝的大草原，脚下是寸厚的青草，软绵绵的还
真不好走，看来买匹马来代步到是的好主意。西边可以看见燕原集，往
东去就是沙漠了。这里耸立着一些古代的石像，不知道用枪刺一下会怎
么样。
LONG);
        set("exits", ([
            "southwest" : __DIR__"caoyuan3",
           
        ]));
set("objects",(["/clone/npc/man":1,]));	
        set("outdoors", "dingxiang");
        setup();
        
}

void init()
{
   add_action("do_ci","ci");
}

int do_ci(string arg)
{
   object me,weapon;
   me=this_player();
   if(!arg||arg!="石像")
   return notify_fail("你要刺什么？\n");
   if(!objectp(weapon=me->query_temp("weapon")))
   return notify_fail("没有武器，你要用手刺吗？\n");
   if(weapon->query("skill_type")!="spear")
   return notify_fail("你挥动"+weapon->name()+"晃了几下，发现毫无用处！\n");
   if(weapon->query("flag")==1)
   return notify_fail("你沮丧的发现手中的兵刃已经断掉了！\n");
   if(me->query("sen")<20)
   return notify_fail("你精神太差了！\n");
   if(me->query_skill("spear",1)>=101)
   return notify_fail("一个牧人跑了过来：保护文物，不准乱刺！\n");
   if(me->is_busy())
   return notify_fail("你正忙着呢！\n");
   
   message_vision(YEL"$N低喝一声，一挥手中的"+weapon->name()+"，朝石像刺去！\n"NOR,me);
   me->improve_skill("spear",me->query_int()/2+20+random(5));
   me->add("sen",-20);
   if(me->query_skill("spear",1)<50)
   message_vision("$N腕力不足，伤不到石像分毫。\n",me);
   else if(me->query_skill("spear",1)<100)
   message_vision("只听哧地一声，石像上被$N刺出了一个浅坑。\n",me);
   else if(me->query_skill("spear",1)<150)
   message_vision("只听哧的一声，$N的"+weapon->name()+"劲透石像！\n",me);
  
   return 1;
}
