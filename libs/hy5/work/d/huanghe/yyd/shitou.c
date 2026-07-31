// shitou.c 石头
// zly 1999.07.27
 
inherit ROOM;

#include <ansi.h>
#include <room.h>

int do_jump(string arg);
int do_tao(string arg);
 
void create() 
{ 
        set("short", "石头");
        set("long", @LONG
这是一块窄小的落脚处，仅容得几个人落脚。右上方好象有个小
洞(dong)，看起来可以伸手进去。
LONG
        );
        set("exits", ([ 
]));

        setup();
}

void init()
{
        
        add_action("do_jump", "jump");
        add_action("do_jump", "tiao");
        add_action("do_tao", "tao");
        add_action("do_tao", "draw");
}

int do_jump(string arg)
{
        object me = this_player();
        if (arg == "chi") {
                if (me->query_skill("dodge", 1) >= 120) {
                        message("vision", me->name() + "吸了口气，纵身向对面跃去。\n",
                                environment(me), ({me}) );
                        write("你吸了口气，纵身向对面跃去。\n");
                        me->move(__DIR__"houyuan");
                        message("vision", "只见人影一闪，" + me->name() +  "纵身跃了过来。\n",
                                environment(me), ({me}) );
                        
                        return 1;
                }
                else {
                        message("vision", me->name() + "纵身向对面跃去，只听“扑通”一声，" + me->name() + "摔入池中，狼狈的爬了回来。\n",
                                environment(me), ({me}) );
                        write("你纵身向对面跃去，只听“扑通”一声，你摔入池中，狼狈的爬了回来。\n");
                        me->receive_damage("qi",80);
                        return 1;
                }
        }
        return 0;
}

int do_tao(string arg)
{
        object me = this_player();
        object ob;
        if (arg == "dong") {
                if ( me->query_temp("tao_times") < 15 )
        {
                message_vision("$N身子一滑差一点从石头上跌了下来。\n", me);
                me->set_temp("tao_times", random(35));
                me->unconcious();
                return 1;
        }
                if ( !me->query_temp("tao") )
        {
                message_vision("$N在洞里摸了半天，什么也没有摸到。\n", me);
                return 1;
        }
        else {
                message_vision("$N在洞里仔细地摸索着。\n", me);
                ob=new(__DIR__"obj/yaoshi");
                ob->move(this_player());
                tell_object(me, RED"你只觉手尖一凉，摸到一块冰冷的东西，你赶紧把它拿了出来。\n"NOR);
                me->set_temp("tao_times", 1);
                me->delete_temp("tao");
                return 1;
            }
      }
     return 0;
}
