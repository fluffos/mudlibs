// Room: /d/shaolin/shulin1.c

inherit ROOM;

void create()
{
	set("short", "杨树林");
	set("long", @LONG
这里是一片杨树林中开辟的一空地。大驿道上的一排杨树挡住了一路尘埃
和噪杂, 显得格外平静。北面是“铁面判官”单正的大宅院, 他的五个儿子守
在这儿。
LONG
	);

	set("exits", ([
		"north" : __DIR__"sjzhuang",
		"southeast" : __DIR__"yidao2",
	]));

	set("objects",([
		__DIR__"npc/boshan" : 1,
	        __DIR__"npc/zhongshan" : 1,
	        __DIR__"npc/shushan" : 1,
	        __DIR__"npc/jishan" : 1,
	        __DIR__"npc/xiaoshan" : 1,
	]));

 	set("outdoors", "泰山");
	setup();
}
