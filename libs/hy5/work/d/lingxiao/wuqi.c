//LUCAS 2000-6-18
// Room: wuqi.c

inherit ROOM;

void create()
{
        set("short", "刀剑铺");
        set("long", @LONG
这就是凌霄城的刀剑铺。走进这里，寒气侵体，好象比外面
还要冷。仔细一看，墙上挂满了大大小小、形形色色的刀剑，一
柄柄寒光闪闪，全是上品。店主轩辕苍翼看到有人进来，立刻殷
勤地迎上前来。
LONG );
        set("exits", ([
                "east" : __DIR__"iceroad2",
        ]));
        set("objects", ([
                __DIR__"npc/xuanyuan": 1,
        ]));
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        setup();
        set("no_clean_up", 0);
        replace_program(ROOM);
}

