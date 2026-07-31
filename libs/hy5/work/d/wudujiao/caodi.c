// by mayue

inherit ROOM;

void create()
{
        set("short", "草地");
	set("long", @LONG
这里是林中的一片空地，四周被参天的古松环抱着，当中是一片绿
油油的草地。草地中央地上有一个拳头大小的小洞，旁边丈许方圆寸草
不生，露出红褐色的土壤。四周一片寂静，草地上阳光明媚，但你的心
情却一也不轻松，这里该不会有什么危险吧？
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
//              "east" : __DIR__"sl8",
//              "northwest" : __DIR__"sl4",
//              "west" : __DIR__"sl6",
//              "northeast" : __DIR__"sl5",
                "south" : __DIR__"sl7",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));
    

	setup();
	replace_program(ROOM);
}

