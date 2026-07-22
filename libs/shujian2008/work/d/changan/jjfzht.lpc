// Write By Yanyang@SJ 2001.10.1
// Room: /d/changan/jjfzht.c

inherit ROOM;

void create()
{
        set("short", "正厅");
        set("long", @LONG
这里是将军府的正厅。厅门口挂着一块横匾，上书「铁面无私」四个大字
，看来还是御笔亲书，气氛很是严肃。正面墙上挂着一幅巨大的工笔画，画中
一座大城，山环水绕，还点缀有亭台楼阁、园林人物，看来是江南的一处名城。
将军不在家，大概去城内巡视了。府内的管家一人在厅里打点着事务。
LONG
        );
        set("exits", ([
                "east"  : __DIR__"jjfyt",
                "south" : __DIR__"jjfhm",
                "west"  : __DIR__"jjfws",
                "north" : __DIR__"jiangjunfu",
        ]));

        set("objects", ([
                __DIR__"npc/guanjia" : 1,
        ]));

        set("incity",1);
	setup();
}

int valid_leave(object me, string dir)
{
        if (!wizardp(me) && objectp(present("guan jia", environment(me))) && (dir == "east" || dir== "west" ||dir=="south"))
                return notify_fail("管家拦住你说道：这里是将军府，可不要乱闯啊。\n");
        return ::valid_leave(me, dir);
}