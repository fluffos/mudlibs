// Room: /d/city/guangchangbei.c

inherit ROOM;

void create()
{
	set("short", "广场北");
	set("long", @LONG
这是广场的北侧。北边是衙门所在，以前去衙门的人很少，静悄悄地很是
冷清。现在百姓自从程要发卸任以后，常常到北面的百姓鸣冤板去留言，向新
任知府大人申述自己的冤情，盼望大人能够为自己做主。西边是西大街，著名
的瘦西湖就再那边。
LONG
	);
        set("outdoors", "扬州");

	set("exits", ([
	        "east" : __DIR__"beidajie3",
	        "west" : __DIR__"xidajie3",
         	"north" : __DIR__"yamen",
//          	"northwest" : __DIR__"leitai",
		"south" : __DIR__"guangchang",
               "northeast" : __DIR__"kongchang",
	]));
   	set("objects",([
   		__DIR__"npc/butou" : 1,
   	]));
   	set("incity",1);
	setup();
}

