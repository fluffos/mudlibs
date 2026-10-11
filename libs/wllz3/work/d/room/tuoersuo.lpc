// tuoersuo.c 托儿所

inherit ROOM;

void create()
{
        set("short", "托儿所");
        set("long", @LONG
这里是桃源山庄的托儿所，是给武林列传的夫妇们托放孩子的地方。
只见托儿所内收拾的十分别致，几个孩童正在戏耍，嬉笑声，玩乐声参杂
一起，一片乐融融的气息。门口站着一位妇人，她是负责照看孩子的。
LONG
);
        set("exits", ([
                "east" : "/d/center/shanzhuang",
        ]));
        set("no_fight",1);
        set("no_steal",1);
        set("objects",([
                __DIR__"npc/mengru": 1,
        ]));
        setup();
	replace_program(ROOM);
}
