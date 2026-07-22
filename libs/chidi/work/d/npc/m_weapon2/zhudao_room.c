//ROOM lianjianshi.c
inherit ROOM;
void create()
{
        set("short", "铸刀车间");
        set("long",
        "这里是冶炼厂的铸刀车间。四处充满了金属的气味，炙热的气浪冲的人\n"
        "不由打了个趔趄。一个皮肤黝黑的小伙正坐在一块石头上休息，手中一个\n"
        "巨大的锤头正不停的来回摆动着。看来这小伙快要睡着了。\n"
        );
        set("exits", ([
                "north" : __DIR__"zhujian_room",
                "south":__DIR__"zhuzhang_room",
        ]));
    set("objects",([__DIR__"npc/zhudao" :1,]));
set("no_fight",1);
    set("no_clean_up", 0);
        setup();
    replace_program(ROOM);
}
