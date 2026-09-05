// bieyuan.c

inherit ROOM;

void create()
{
        set("short", "华山别院");
        set("long", @LONG
这里就是华山别院所在。华山剑气二宗想争后，剑宗一败涂地，让出
掌门之位后在此苦练。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
		"southdown" : __DIR__"laojun",
]));

        set("objects", ([
                CLASS_D("huashan") + "/fengbuping" : 1,
                CLASS_D("huashan") + "/chengbuyou" : 1]));
        setup();

        set("no_clean_up", 0);
        set("outdoors", "xx" );
        set("room","room13");
        setup();
        replace_program(ROOM);
}

