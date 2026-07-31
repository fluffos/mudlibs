//#include <obj.h>
inherit ROOM;
void create()
{
        set("short", "城隍庙");
        set("long", @LONG
这是一间十分老旧的城隍庙，在你面前的神桌上供奉著一尊红
脸的城隍。庙虽老旧，但是神案四周已被香火薰成乌黑的颜色，想
来这里必定相当受到信徒的敬仰。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
       //         "south" : __DIR__"eroad1",
                "west" : __DIR__"sstreet1",
        ]));
        set("no_fight", 1);
        set("no_magic", 1);
        set("objects", ([ /* sizeof() == 2 */
              //  OBJ_PAPER_SEAL : 10,
                __DIR__"npc/keeper" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
