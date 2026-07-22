
inherit ROOM;

void create()
{
        set("short", "太湖");
        set("long", @LONG
太湖周长六百余里，为长江和钱塘江下游的海湾内湖，又称震
泽、五湖，为江南水网中心。湖中有大小岛屿四十八个，以洞庭西
山和马迹山为最大。湖中烟波浩渺，岛屿浮沉；湖滨丘陵起伏，园
林点缀，构成一幅山外有山，湖中有湖的天然图画。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
	"east" : __DIR__"taihuzhai",
	"northwest" : __DIR__"jiangdao4",
]));
        set("outdoors", "jinling");

        setup();
        replace_program(ROOM);
}
