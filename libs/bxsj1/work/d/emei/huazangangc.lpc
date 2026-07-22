// huazangangc.c
// 广场 
inherit ROOM;
void create()
{
	set("short","华藏庵广场");
	set("long",@long
这里是峨嵋华藏庵的广场，地上铺着青砖。正前方有一道台阶，通往大
雄宝殿。殿前有个丈许高的大香炉，香炉前的香台上，红烛高烧，香烟飘绕。
广场上有几个小师太正在练功。自此左右各有一条走廊通向后殿。
long);
	set("exits",([
	    "east" : __DIR__"dcelang",
	    "west" : __DIR__"xcelang",
	    "north" : __DIR__"huazanganzd",
	    "southup" : __DIR__"daxiong",
]));
        set("objects",([
		CLASS_D("emei") + "/jing-xu" : 1,
          ]));
	set("outdoors", "峨嵋山");
	setup();
        "/clone/board/emei_b"->foo();
}
