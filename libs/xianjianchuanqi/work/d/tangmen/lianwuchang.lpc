//room: /d/tangmen/lianwuchang.c
//  xws 1998/11/05
inherit ROOM;

void create()
{
	set("short","练武场");
	set("long",@LONG
	这里是唐门的练武场。放着些唐门的能工巧匠编制出的机关竹人,几个唐门
弟子正在打竹人勤练武功。
LONG    );
	set("outdoors", "tangmen");
	set("exits",([
       
		"north" : __DIR__"xiouxishi",
		"south" : __DIR__"changlang18",
	
	]));
	 set("objects", ([
        	__DIR__"npc/zhuren" : 4,
    ]) );

 setup();
 replace_program(ROOM);
}




