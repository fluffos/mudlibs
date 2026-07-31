// Room: /d/wizhome/incahome/changcheng18.c
// Date: inca 98/08/13

#include <ansi.h>
inherit ROOM;

void create()
{

        set("short", WHT "长城");
        set("long", WHT @LONG
你已经绕过了倒塌的城墙，又回到了长城上。站在坚实的城砖上，你高兴
的唱起歌来“万里长城永不倒。。。。。。”，歌声在空旷的山上传了很远，
很远。
LONG
NOR        );

        set("outdoors", "changcheng");

        set("exits", ([
                "southwest"  :__DIR__"changcheng19.c",
                "eastdown"   :__DIR__"changcheng17.c",
        ]));

        setup();
        replace_program(ROOM);
}
