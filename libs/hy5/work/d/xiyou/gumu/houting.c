// hubian.c
// by shilling 97.2

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIC "古墓后堂"NOR);
        set("long", @LONG
堂上也是空荡荡的没什么摆设，只东西两壁都挂着一幅画。
(pic)据说是先祖轩辕公的画像，一阵阴风吹过，画像一角
微微卷起，画像的后面好像有什么机密......

LONG );
        set ("item_desc", ([
                "pic" : "轩辕公的画像，只见他一派神人气度，仙风道骨，举止出尘
\n"
        ])  ) ;
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"girlbed.c",
  "east" : __DIR__"boybed.c",
  "south" : __DIR__"zhongting.c",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xiaoyao" );
        setup();
}

void init()
{
        add_action("do_push","push");
        add_action("do_zuan",({"zuan","enter"}));
}

int do_push(string arg)
{
        object me;
        me = this_player();
        if (!arg||arg!="pic") return 0;
        write("你将画像慢慢的掀起来......\n");
       if(random((int)me->query("kar")) < 10 )
              if(random((int)me->query("str")) < 10 )
                {
                write("突然你好像被什么都西咬了一口，你急忙将手缩回。\n");
                return 1;
                };
        write("画像后渐渐露出一个三尺来高的洞穴(hole)。\n");
        me->set_temp("marks/push",1);
        return 1;
}

int do_zuan(string arg)
{
        object me;
        me = this_player();
        if (!me->query_temp("marks/push")) return 0;
        if ( arg != "hole") return 0;
        message_vision("$N小心的钻进画像后的洞穴中......。\n", me);
        me->move(__DIR__"bingyu.c");
        return 1;
}

int valid_leave(object me, string dir)
{
        if (me->query_temp("marks/push") ) me->delete_temp("marks/push");
        return ::valid_leave();
}

