// /d/yuehou/house2.c

inherit ROOM;

void create()
{
        set("short", "杂货店");
        set("long", @LONG
这里是岳候镇的杂货店，镇子里的人大多都道这里买东西。
店里的老板正在不停的忙碌着，似乎在等待着什么。从这里向北
是小镇的市集。
LONG
        );

       set("exits", ([
                "north"             : __DIR__"troad4",
]) );
        set("objects", ([
                __DIR__"npc/yang" : 1,
                "/clone/npc/man" : 1,
        ]));
       set("light_up",1);

       setup();
       replace_program(ROOM);
}
