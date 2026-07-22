// ximen.c 西门
// By csy 1999.03

inherit ROOM;

void create()
{
        set("short", "西门");
        set("long", @LONG
这里是武功镇的西门，眼前城墙高耸，墙上的箭垛里好象还有人走
来走去。阳光照来，城墙上闪过几道白光，似乎是兵器反射出的光。城
门上题着‘西门’两个大字，门口站着一些官兵，正手持兵刃盘问着来
往的行人们。从这里折而向北，就是终南山脚了。
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "east" : __DIR__"xijie",
                "west" : "/d/changan/ca32",
                "northeast" : __DIR__"shanlu1",
        ]));

        set("objects", ([
                __DIR__"npc/wujiang" : 1,
                __DIR__"npc/bing" : 2,
        ]));
        setup();
        replace_program(ROOM);
}

