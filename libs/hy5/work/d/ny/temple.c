

inherit ROOM;

void create()
{
        set("coor",({50,4750,10}));
	set("short", "城隍庙");
        set("long",
"这是一间十分老旧的城隍庙，在你面前的神桌上供奉著一尊红脸的城隍，庙虽老旧，但是神\n"
"案四周已被香火薰成乌黑的颜色，显示这里必定相当受到信徒的敬仰。突然你发现庙后墙处\n"
"有个不太明显的暗门，\n"
);
        set("exits", ([ /* sizeof() == 2 */
                "southeast" : __DIR__"work",
                "west" : __DIR__"square",
        ]));
            set("no_fight", 1);
    set("no_spells",1);
    set("no_magic","1"); 
    set("objects", ([ /* sizeof() == 3 */

                __DIR__"npc/keeper" : 1, 
        ]));
        set("valid_startroom", 1);
        set_temp("light",1);
        setup();
}
