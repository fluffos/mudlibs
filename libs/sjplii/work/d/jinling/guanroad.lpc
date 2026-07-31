
inherit ROOM;

void create()
{
        set("short", "青石官道");
        set("long", @LONG
这是一条宽敞坚实的青石大道，向东延伸。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
	"east" : __DIR__"guanroad2",  
	"westup" : __DIR__"zijinshan",
]));
        set("outdoors", "changan");

        setup();
        replace_program(ROOM);
}
