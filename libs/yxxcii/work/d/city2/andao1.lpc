//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "天地会暗道");
	set("long", @LONG
这是一条黑漆漆的地道，曲曲折折地通向前方。两边都是土墙，隐约
可以听到上面脚底落地的声音。空气中弥漫着潮湿的泥土气息，令人感到
十分凉爽。一个道人站在这里，守卫着上面的两个出口。
LONG
);
	set("exits", ([
		"north" : __DIR__"andao2",
		"south" : __DIR__"andao3",
		"eastup" : __DIR__"neishi",
		"westup" : __DIR__"guancai2",
	]));
	set("objects", ([
		CLASS_D("yunlong") + "/xuanzhen" : 1
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if (objectp(present("xuan", environment(me))) && 
		(dir == "east"||dir == "west")&& living(present("xuan", environment(me))))
	message("vision","玄真把门关上了。\n","/d/city2/andao1");
	if(dir=="east")
	message("vision","一眨眼，屋里忽然多了一个人。\n","/d/city2/neishi");
	if(dir=="west")
	message("vision","一眨眼，屋里忽然多了一个人。\n","/d/city2/guancai2");
	return ::valid_leave(me, dir);
}
