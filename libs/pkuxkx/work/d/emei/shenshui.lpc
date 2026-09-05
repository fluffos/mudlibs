// Room: /d/emei/shenshui.c 峨嵋派 神水阁
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "神水阁");
set("outdoors","emei");
        set("long",
"这里是峨眉派封山断道的所在，左面的岩石上刻着几个大字\n"
"“"HIW"大峨"NOR"”比划深入岩壁，好象是绝顶高手以内家指力书就，令人\n"
"不由峤舌，路旁有一个禅院，门前站着几个尼姑，手持长剑，似\n"
"乎在盘查着经过的人，此地不宜久留，还是快走吧。\n"
        );

        set("exits", ([
                "southdown" : __DIR__"shijie2",
		"northup" : __DIR__"qingyin",        
               ]));
        setup();
        replace_program(ROOM);
}
