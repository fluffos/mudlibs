// shandong1.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
        set("short","山洞");
        set("long",@LONG
空空荡荡一个山洞，倒也还算干净，尽头摆了一张石床。
LONG );
        set("sleep_room",1);
          set("no_quit",1);
        set("exits",([
                  "out" : __DIR__"sroad8",
        ]));
        set("objects", ([
                __DIR__"obj/dachang" :1,
        ]));
        setup();
        replace_program(ROOM);
}

