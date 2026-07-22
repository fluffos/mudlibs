#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", CYN"须弥殿"NOR);
        set("long", @LONG
一间宽敞的佛殿四壁空荡荡的，正中是一张青石屏风，绘有一座高耸
入云的险峰，白云缭绕，峰脚下则是一枚芥子。想是取佛家须弥芥子之典
故，佛法修为可将须弥之巨容入芥子之中。屏风前摆着几个蒲团，几位僧
人正自对着屏风反睛内视，勤修内功。
LONG
 );
        set("exits", ([
            "east" :__DIR__ "dabeidia",
        ]));

        set("objects",([
		__DIR__"obj/muchui" : 1,
	]));
 
        setup();

}

void init()
{
	add_action("do_neishi", "neishi");
}

int do_neishi()
{
        object me;

        me = this_player();
        message_vision("$N盘膝坐下闭目垂帘意守丹田修炼内功。\n", me);
        if ((int)me->query("jing")<20)
     {
	write(RED"你太累了，精力无法集中。\n"NOR);
       return 1;
      } 
      
    if ((int)me->query_skill("force", 1) >= 30 
    && (int)me->query_skill("force", 1) <= 100 
    && present("xisui jing", me) )
        {
           me->receive_damage("jing", 20);
           me->improve_skill("force", me->query("int"));
         //  if ( random(5) == 0 )
           tell_object(me, RED"你内视静想一股内息自曲骨，中极，关元，石门直通而上。
经过一个小周天运行贮于气海膻中。\n"NOR);
       }
    else
       tell_object(me,RED"你越想越糊涂，内息乱窜，只好站起身来。\n"NOR);
       return 1;
}
