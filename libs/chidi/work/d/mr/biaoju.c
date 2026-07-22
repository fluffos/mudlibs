inherit ROOM;
void create()
{
        set("short", "车行");
       set("long",@LONG
这里是马车行的分行。
LONG
        );

        set("exits", ([
                "east": __DIR__"qianzhuang",
                ]));

        set("objects", ([
                ]) );

        setup();
        set("valid_startroom", 1);
        replace_program(ROOM);
}
