// cetang.c 侧堂
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "侧堂");
        set("long", @LONG
这里是大堂旁边的一个侧厅，也是接待重要客人的地方。厅不
大，只摆放着一张桌子和几把椅子(chair)。桌上摆放着一盆青松
山石的盆景，墙壁上挂着一些字画。一个十来岁的小道士正在忙前
忙后招待客人。
LONG
        );
        set("exits", ([
                "east" : __DIR__"guozhendian",
                "west" : __DIR__"huizhentang",
                "north" : __DIR__"shiweishi",
                "south" : __DIR__"datang2",
        ]));
        set("objects", ([
                __DIR__"npc/li" : 1,
                __DIR__"npc/daotong2" : 1,
        ]));

        setup();
//        replace_program(ROOM);
}
void init()
{
        add_action("do_sit", "sit");
}

int do_sit(string arg)
{

        object me;
        object daotong;

        me = this_player();
        if ( !arg || (arg != "chair") )
                return notify_fail("你席地而坐，引来几个惊愕的目光。\n");

		  if( !objectp(daotong = present("daotong", environment(me))) )
                return notify_fail("你坐下来休息，没有人来打搅你。\n");

        if( me->query_temp("marks/served") )
        {
                message_vision("小道士笑着对$N说：我还忙着呐，您先再休息休息吧。\n", me);
                return notify_fail("");
        }

        message_vision("$N坐到桌前，小道士笑着过来招待。\n", me);
        daotong->serve_tea(me) ;
        
        me->set_temp("marks/served", 1);
        call_out("delete_served", 10, me);
        return 1;
}



void delete_served(object me)
{
        if ( objectp(me) ) me->delete_temp("marks/served");
}

int valid_leave(object me, string dir)
{
        if (( present("xiang cha", this_player())
                || present("dian xin", this_player()) ) 
			  && objectp(present("daotong", environment(me))) ) {
        message_vision("小道士见$N还没吃完，说道：这位客人用完茶点再走吧。", me);
        return notify_fail("\n");
        }

        return ::valid_leave(me, dir);
}


