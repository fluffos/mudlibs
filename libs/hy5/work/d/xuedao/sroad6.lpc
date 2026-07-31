// sroad6.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
        set("short","大雪山口");
        set("long",@LONG
冰天雪地，寒风刺骨。不是内力高深的人，已然经受不住了。
LONG );
        set("exits",([
                "northdown" : __DIR__"sroad5",
                "westup"    : __DIR__"sroad7",
        ]));
        set("outdoors", "xueshan");
        set("no_clean_up", 0);
    set_temp("wayao2",2);
        setup();
	replace_program(ROOM);
}
