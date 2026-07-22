inherit ROOM;
void create()
{
          set("short", "酒怪居");
        set("long", @LONG
酒怪居，也就是六怪之一宇天仇的居所，酒怪平生最爱酒，一天没
酒就像要了他的命，屋子四周摆放的都是一个个酒坛子。
LONG
        );
        set("exits", ([
                 "north" : __DIR__"toujv",
                 "east" : __DIR__"yishi",
        ]));
        set("objects", ([
        "/d/tongchi/npc/jiuguai":1,
        ]));
        setup();
        replace_program(ROOM);
}
