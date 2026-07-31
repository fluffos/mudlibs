//room: /d/tangmen/tianjing.c
//  by HEM
inherit ROOM;

void create()
{
	set("outdoors", "tangmen");
	set("short","天井");
	set("long",
          "这里是天井，一大片开阔的空旷地，有几个练功用的竹人。往北走是\n"
"留剑堂，往南是心意堂。\n"
       );

	set("exits",([
                   "north" : __DIR__"liujiantang",
                   "south" : __DIR__"xinyitang",
    ]));
	 set("objects", ([
        __DIR__"npc/zhuren" : 4,
    ]) );


 setup();
 replace_program(ROOM);
}




