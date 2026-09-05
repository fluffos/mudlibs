// sheshen.c

inherit ROOM;
#include <localtime.h>
#include <command.h>
#include <ansi.h>
void create()
{
        set("short", "舍身崖");
        set("long", @LONG
这是一段极窄极险的山崖，四周云雾飞绕，下面渊深无底。如不小心
，一失足掉下去，只怕连骨头都找不到。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
           "eastdown" : __DIR__"canglong",
        ]));
        
        set("objects",([
                __DIR__"npc/referee" : 1,
        ]));

        set("no_clean_up", 0);
        set("outdoors", "xx" );
        set("room","room10");
        setup();
//        replace_program(ROOM);
}
void init()
{
        object me;
        mixed *local;
        me=this_player();
        local = localtime(time());

//        if( local[LT_HOUR] == 12 && random(20)==1) //中午12点才有效
        if(NATURE_D->outdoor_room_event() == "event_noon" && random(20)==1)
                {
//             this_object()->set("exits/westup", "/d/jinshe/ziqitai");
             tell_object(me, HIY"正值正午时分，阳光猛烈，借着阳光，你隐隐从迷雾中看到了一条小路！似乎是通向西边（westup）的！！\n"NOR);
             me->set_temp("jinshe/road",1);
          }
        else
//             this_object()->delete("exits/westup");
        remove_call_out("close");
        call_out("close", 5, this_object());
        add_action("do_west", "westup");
        return;
}
void close(object room)
{
//        this_object()->delete("exits/westup");
        object me=this_player();
        
        if (!me) return;
        if (me->query_temp("jinshe/road")==1) {
        tell_object(me, HIY"你揉了揉眼睛，哪里有什么小路，怕是眼花了吧？\n"NOR);
        me->delete_temp("jinshe/road");
        }
        return;
}
int do_west()
{
                object me;
        me = this_player();
        if( me->query_temp("jinshe/road")==1 ) {
                message("vision",me->name() + "消失在迷雾中！\n", environment(me), ({me}) );
                me->move("/d/jinshe/ziqitai");
                message("vision",me->name() + "从迷雾中走了过来！\n",
                environment(me), ({me}) );
                return 1;
                }
        else {
                return 0;
                }
}
 

