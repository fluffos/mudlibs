// Room: /d/huashan/square.c

inherit ROOM;

void create()
{
        set("short", "练武场");
        set("long", @LONG
这里是华山派的练武场，通常有许多华山派弟子在此习武练剑，所以
不欢迎外人。南边的房屋门上挂着一块匾，上书「有所不为轩」，西北方
似乎有条小路通往山上。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
            "south" : __DIR__"buwei1",
            "north" : __DIR__"yunu",
        ]));
        set("objects", ([
	    "/kungfu/class/huashan/lao" : 1,
                __DIR__"npc/dizi" : 5 ]));

        set("item_desc", ([
                "小路": "那是一条通向山里的小路，似乎没有尽头。\n"
        ]) );
        set("no_clean_up", 0);
        set("room","room1");
        setup();
}
void init()
{
        add_action("do_northwest", "northwest");
}
int do_northwest()
{
        object me;
        me = this_player();
        if( me->query_temp("marks/思1") ) {
                message("vision",
me->name() + "向西北的小路走去。\n",
                environment(me), ({me}) );
                me->move("/d/huashan/xiaolu1");
                message("vision",
me->name() + "走向西北的小路。\n",
                environment(me), ({me}) );
                return 1;
                }
        else {
                write("那条小路似乎没有尽头。\n");
                return 1;
                }

}
