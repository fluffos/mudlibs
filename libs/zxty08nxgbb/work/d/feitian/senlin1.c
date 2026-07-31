// senlin.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
       set("short","原始森林");
       set("long", @LONG
这是京都通往东京的一快森林，森林中地下布满了一层厚厚的树叶踩上去
卡卡做响，透过森林的一些阳光洒落下，很是美丽。不过你发现自己已经
迷失了方向，你开始有点后悔走进来了。
LONG);
        set("exits", ([
             "east"  : __DIR__"senlin"+(1+random(4)),
             "west"  : __DIR__"senlin"+(1+random(4)),
             "south" : __DIR__"senlin"+(1+random(4)),
             "north" : __DIR__"senlin"+(1+random(4)),               
        ]));
        
        set("outdoors", "feitian");
        setup();            
}

void init()
{
        object me = this_player();
        if(userp(me) && me->query("jingli") < 10){
           switch(random(2)) {
            case 0 : me->move(__DIR__"zhongxiandao"); break;
            case 1 : me->move(__DIR__"linzi"); break;
            }
           message_vision("$N惊慌失措地走了过来。\n",me);
           me->unconcious();
           }
        if(!me->query_temp("corredt_dir") && userp(me))
         me->set_temp("correct_dir", keys(query("exits"))[random(sizeof(query("exits")))]);
}

int valid_leave(object me, string dir)
{
        if( dir != me->query_temp("correct_dir"))
                me->set_temp("ft_sl", 0);
        else    me->add_temp("ft_sl", 1);

        if( me->query_temp("ft_sl") > 5 + random(5) ) {
                me->move(__DIR__"senlin");
                me->delete_temp("ft_sl");
                me->delete_temp("correct_dir");
                return notify_fail("你红着双眼乱走一通，终于找到了方向。\n");
        }
        return ::valid_leave(me,dir);
}

