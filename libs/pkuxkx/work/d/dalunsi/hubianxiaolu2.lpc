// 大轮寺
//by kiden

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "湖边小路");
        set("long", @LONG
这里是一片广阔的淡水湖，天空一望无垠，湖水清澈湛蓝，呈现出一幅独特
的高原风光。
真是：
    长风怒卷高浪，飞洒日光寒，
    无风水面琉璃滑，不觉船移，微动涟漪，惊起沙禽掠岸飞。
    一千五百年间事，只有滩声似旧时。
LONG NOR
        );

        set("exits", ([

                "southeast"     : __DIR__"hubianxiaolu1",
                "northeast" : __DIR__"tianhu",

        ]));
        set("objects", ([
//                __DIR__"npc/randomnpc2" : 1,
        ]));
        set("outdoors", "dalunsi");
        setup();
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

