inherit ROOM;
void create()
{
          set("short", "密室");
        set("long", @LONG
密室，据说这里藏着一本武功秘籍。
LONG
        );
        set("exits", ([
                   "down" : __DIR__"yishi",
        ]));
        set("objects", ([
       __DIR__"obj/jing" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
