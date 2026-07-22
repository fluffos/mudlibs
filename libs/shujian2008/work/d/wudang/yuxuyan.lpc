// /area/jiangbei/wudang/yuxuyan.c 玉虚岩
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "玉虚岩");
        set("long", @LONG
玉虚岩穴洞分上下两层，进入岩洞，随处可见当年庙房的遗址、摩崖石刻
和泥塑彩绘的神像。北宋著名文学家李方叔在《武当山赋并序》中记载，唐玄
装七世佛子之徒“越蓊岭，逾崆峒，来驻于兹……”意思是说，曾上西天取经
的唐僧的七世弟子们带着佛经，翻山越岭，来到玉虚岩，并住在这里收徒弟传
授佛经。
LONG
        );

        set("exits", ([
                "westdown" : __DIR__"mozhen",
        ]));

        set("objects",([
                __DIR__"npc/youke" : 1+ random(2),
        ]));

        set("no_clean_up", 0);
        set("outdoors", "武当");

        setup();
}
