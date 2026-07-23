
inherit ROOM;

void create()
{
        set("short", "青石官道");
        set("long", @LONG
这是一条宽敞坚实的青石大道。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
	"north" : __DIR__"guanroad3",  
	"south" : __DIR__"guanroad2",  
]));
        set("outdoors", "changan");
        setup();
//        replace_program(ROOM);
}
int do_go()
{
if(random(3)){
this_player()->move(this_object());
return 1;
}
}
