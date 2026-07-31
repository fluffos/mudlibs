// wanwutang.c 万物堂
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "万物堂");
        set("long", @LONG
这里是全真七子之五王处一的居所。房间不大，收拾的素雅整
洁，墙上挂着一萧一琴和一些字画，小几上摆放着宣纸和徽墨狼毫，
不知道主人是要练字还是绘画。
LONG
        );
        set("exits", ([
                "south" : __DIR__"huizhentang",
        ]));
        set("objects",([
                __DIR__"npc/wangchuyi" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
