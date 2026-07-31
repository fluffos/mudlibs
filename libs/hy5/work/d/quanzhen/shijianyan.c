// shijianyan.c 试剑岩
// By Lgg,1998.10

inherit ROOM;

void create()
{
        set("short", "试剑岩");
        set("long", @LONG
石阶旁立着一块大岩石，上面斑斑驳驳的尽是砍伤。这块大岩
石便是全真教的试剑岩，天下的英雄来到这里，望着先辈们练剑时
在岩石上的砍痕，无不肃然起敬。
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "northdown" : __DIR__"shijie4",
                "southup" : __DIR__"shijie8",
                "east" : __DIR__"jiaobei",
        ]));
        set("objects",([
                __DIR__"npc/yin" : 1,
                __DIR__"npc/daotong" : 2,
        ]));

        setup();
        replace_program(ROOM);
}
