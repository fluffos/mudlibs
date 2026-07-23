
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
	"east" : __DIR__"jiangdao4",
	"west" : __DIR__"jiangdao1",
]));
        set("outdoors", "jinling");

        setup();
//        replace_program(ROOM);
}
void init()
{
        add_action("do_go","go");

}

int do_go()
{
if(random(3)){
this_player()->move(this_object());
return 1;
}
}
