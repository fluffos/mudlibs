// huazanganzd.c
// 华藏庵正殿

inherit ROOM;

void create()
{
	set("short", "华藏庵正殿");
	set("long",@long
这里是峨嵋山金顶华藏庵的正殿。华藏庵规模宏大，殿内青砖铺地，中间
有普贤菩萨像，两旁列有万佛。正前方放一红木供桌，陈列香烛，以供叩拜。
自此左右各有一间侧殿，是接待香客的地方。南面是通往一个大广场，只有峨
嵋弟子才能过去。
long);

	set("exits",([
	    "east" : __DIR__"dcedian",
	    "west" : __DIR__"xcedian",
	    "south" : __DIR__"huazangangc",
	    "out" : __DIR__"huazangan",
]));
        set("objects",([
		CLASS_D("emei") + "/jing-xin" : 1,	      
          ]));
	setup();	
}
