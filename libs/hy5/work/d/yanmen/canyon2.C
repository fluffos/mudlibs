// ROOM:__DIR__"canyon2"

inherit ROOM;
void create()
{
        set("coor",({-300,4350,0}));
	set("short","隘口小路");
	set("long",
"来到这里，脚下的黄土仍是厚厚的一层，可见得来往这条道路的人必不多，向北即是隘口尾\n"
"，往南一直通达雁门关口，两侧依旧是荒冷的山壁，但似乎更为严峻。\n"
); // eof(long)
	
	set("exits",([ /* sizeof()==2 */
        	"north" : __DIR__"shibi",
        	"northeast" : __DIR__"canyon1",
        	"south" : __DIR__"canyon3",
	]) ); //eof(exits)
	
        set("outdoors","yanmen");
	setup();
	
	replace_program(ROOM);
} //EOF
