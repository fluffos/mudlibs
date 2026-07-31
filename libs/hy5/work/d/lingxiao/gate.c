//LUCAS 2000-6-18
// gate.c

inherit ROOM;

void init(); 
void close_bridge();
int do_close(string arg);
string look_bridge();
int do_open(string arg);
#include <ansi.h>;

void create()
{
        set("short", "凌霄内门");
        set("long", 
"这里是凌霄城的城门。本来凌霄城少有外敌入侵，但由于地
处西域，隆冬之际常有饿狼前来侵袭，故修筑此大城以做抵挡。
向城内望去，只见人头攘攘，很是繁华，想不到在这西域雪山绝
顶，却有着一个如此去处。\n"
 );
        set("outdoors", "lingxiao");

        set("exits", ([
                "eastup"  : __DIR__"walle1",
                "westup"  : __DIR__"wallw1",
                "north"  : __DIR__"iceroad1",
        ]));
        set("objects", ([
                __DIR__"npc/dizi" : 3,
        ]));
        setup();
} 

void init()
{
        add_action("do_open", "open"); 
        add_action("do_close", "close");
} 
void close_bridge()
{
        object room;

        if(!( room = find_object(__DIR__"shanya")) )
                room = load_object(__DIR__"shanya");
        if(objectp(room))
        {
                delete("exits/south");
                        message("vision", "凌霄弟子把吊桥关了起来。\n", this_object());
                room->delete("exits/north");
                message("vision", "只听'嘎嘎'几声,吊桥又被关了起来。\n", room);
        }
}
int do_close(string arg)
{
        if (!query("exits/south"))
                return notify_fail("吊桥已经是关着的了。\n");

        if (!arg || (arg != "bridge" && arg != "south"))
                return notify_fail("你要关什么？\n");

        message_vision("$N朝凌霄弟子招了一下手,他们点了点头,把吊桥吊了上去。\n", this_player());

        remove_call_out("close_bridge");
        call_out("close_bridge", 2);

        return 1;
}

int do_open(string arg)
{
        object room;

        if (query("exits/south"))
                return notify_fail("吊桥已经放下来了。\n");

        if (!arg || (arg != "bridge" && arg != "south"))
                return notify_fail("你要开什么？\n");

        if(!( room = find_object(__DIR__"shanya")) )
                room = load_object(__DIR__"shanya");
        if(objectp(room))
        {
                set("exits/south", __DIR__"shanya");
                message_vision("$N让凌霄弟子把吊桥放了下来。\n", this_player());
                room->set("exits/north", __FILE__);
                message("vision", "嘎嘎几声,吊桥放了下来。\n", room);
                remove_call_out("close_bridge");
                call_out("close_bridge", 10);
        }

        return 1;
}

string look_bridge()
{
        return "一张极大的吊桥,是凌霄城的一道防线。\n";
}

/*
int valid_leave(object me, string dir)
{
        if (dir == "north" )
        {
                if(me->query("family/family_name") !="凌霄城")
                {
                        if(me->query("combat_exp") >= 100)
                        {
                                if(present("wen wanfu", environment(me)) && living(present("wen wanfu", environment(me))))
                                {
                                        return notify_fail(
"闻万夫拔剑拦道：何方高人驾凌敝城，里面乃本派重地。这位" + RANK_D->query_respect(me) + "请止步。\n");
                                }
                                else
                                        return ::valid_leave(me, dir);
                        }
                        else
                                return ::valid_leave(me, dir);
                }
                else
                        return ::valid_leave(me, dir);
        }
        else
                return ::valid_leave(me, dir);

}

*/