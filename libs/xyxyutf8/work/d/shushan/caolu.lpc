inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "草庐");
        set("long",@LONG
一间简单的草庐，却也布置得很是不凡。四壁上挂满了飞白墨宝，一角则是一些珍贵乐谱。
    房中点着檀香，闻了叫人心神宁静。一位白衣老者正盘坐在古琴前，凝神调弦，一声声
悦耳的古琴声不时传来。
LONG
        );
        set("exits", ([
                "south" : __DIR__"yaxia",
        ]));
	set("objects",([
		__DIR__"npc/qingyin" : 1,
	]));	
        setup();
}