// Room: /hangzhou/damo1.c
// hubo 2008/4/19

#include <ansi.h>
inherit ROOM;
#include <localtime.h>
#include <command.h>
int do_climb(string);

void create()
{
        set("short", YEL"大漠"NOR);
        set("long", YEL@LONG
一片大漠黄沙，一走进来感觉迷失了方向。
LONG
NOR);
        set("outdoors", "hangzhou");
        set("exits", ([
                "southwest" : __DIR__"shanlu1",
                "north" : __DIR__"damo1",
                "south" : __DIR__"damo1",
                "east" : __DIR__"damo1",
                "west" : __DIR__"damo1",   
]));
          
   setup();
}

void init()
{
        object me;
        mixed *local;
        me=this_player();
        local = localtime(time());

        if(NATURE_D->outdoor_room_event() == "event_noon" && random(20)==1)
            {
             tell_object(me, HIY"正值正午时分，阳光猛烈，借着阳光，你突然发现原来远处的黑点是只鹰，而鹰之所以不动是因为站在了山上！！\n"NOR);
             me->set_temp("hhh_zhuangzi",1);
            }
        else
                
        remove_call_out("close");
        call_out("close", 5, this_object());
        add_action("do_climb", "climb");
        return;
}
void close(object room)
{
        object me=this_player();
        if (me->query_temp("hhh_zhuangzi")==1) {
        tell_object(me, HIY"你仔细看看，好象什么都没有，怕是眼花了吧？\n"NOR);
        me->delete_temp("hhh_zhuangzi");
        }
        return;
}
int do_climb(string arg)
{
        object me;
        me = this_player();
                
       if( !arg || arg!="mountain" )
                 {
              write("你要往哪爬呀？\n");
              return 1;
           }
           
       if(( me->query_temp("hhh_zhuangzi")==1 ) && (arg == "mountain" ))
           {
                
                message("vision",me->name() + "往山上爬了去！\n", environment(me), ({me}) );
                me->move(__DIR__"gongdian1");
                message("vision",me->name() + "从山下爬了上来！\n",
                environment(me), ({me}) );
                return 1;
            }
        else {
                return 0;
             }
}

