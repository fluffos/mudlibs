// feng.c
inherit ROOM;
void create()
{
        set("short", "风清扬藏身处");
        set("long", @LONG
这里在华山内部，常年没人到此，可是洞里有一人，对着洞
壁发呆。洞里只有一桌一椅和一张竹床。
LONG
        );
     set("sleep_room", 1);
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"siguoyahoudong",
]));
        set("objects", ([
                CLASS_D("huashan") + "/feng" : 1]));

        set("no_clean_up", 0);
        set("no_task",1);
        setup();
        replace_program(ROOM);
}
