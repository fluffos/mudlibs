//Room:/d/lingshedao/xiaowuout.c
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "空地");
        set("long",@LONG
你来到了一片空地,前面是一间小茅屋,屋里没有一点光亮,
不知道住了谁.
LONG );
        set("exits", ([
                "enter"    : __DIR__"xiaowu",
                "southdown"  : __DIR__"migong1",
        ]));

        set("objects",([
                //__DIR__"npc/han" : 1,
        ]));

       set("no_clean_up",0);
        set("outdoors","lingshedao");
        setup();

}

int valid_leave(object me,string dir)
{
        if( ( dir=="enter" )
             &&objectp(present("jin hua",environment(me)))
             &&((int)me->query("shen")>100000) )
             return notify_fail
                    ("金花婆婆冷冷的说道:大侠光临灵蛇岛想干甚么?有事找我老婆子说话，
却不要去骚扰灵蛇岛的贵宾.\n");
       else if(  (dir=="enter")
             &&objectp(present("jin hua",environment(me)))
             &&(me->query("party/party_name")== HIG "明教" NOR)) 
             return notify_fail
             ("金花婆婆大叫一声:大胆小贼,鬼鬼祟祟到这来干嘛?要不是看在
你是明教弟子的份上,我便将你杀了,快给我滚!\n");
      else  if( (dir == "enter") && objectp(present("jin hua",environment(me))) )
            {
             me->set_temp("nk",1);
             return notify_fail
                    ("金花婆婆哼的一声说道:敢到灵蛇岛来撒野,活得不耐烦了!快滚,别让我看到第二次\n");
            }
       return ::valid_leave(me,dir);
}
