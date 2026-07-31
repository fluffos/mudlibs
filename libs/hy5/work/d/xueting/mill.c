// Room: /d/snow/mill.c
inherit ROOM;
void create()
{
        set("short", "磨坊");
        set("long", @LONG
这里是一间以磨面粉为业的磨坊，屋子里一大半的空间被一架
水车占据，水车转动横过屋梁上的木轴，木轴推动几个绞盘转动屋
子中央的石磨，房子的另一角堆放著一些空的麻袋。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "out" : __DIR__"lane2",
]));
        setup();
        replace_program(ROOM);
}
