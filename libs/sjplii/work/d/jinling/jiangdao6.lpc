
inherit ROOM;

void create()
{
        set("short", "江边大道");
        set("long", @LONG
这是一条沿长江南岸向东延伸的官道，北面便是波浪起伏的长
江，阵阵江风吹来令人心旷神怡。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
	"northeast" : __DIR__"chibi",
	"west" : __DIR__"jiangdao5",
]));
        set("outdoors", "jinling");

        setup();
        replace_program(ROOM);
}
