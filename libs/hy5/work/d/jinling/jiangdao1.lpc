
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
	"east" : __DIR__"jiangdao3",
	"west" : __DIR__"jiangdao2",
	"south" : __DIR__"yuhuatai",
]));
        set("outdoors", "jinling");
        set("objects", 
        ([
              "/d/hainan/npc/man1" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
