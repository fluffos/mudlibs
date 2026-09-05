// Room: /city/fangchan.c
// 云台街：房产公司
inherit ROOM;

void create()
{
	set("short", "房产公司");
	set("long", @LONG
这是扬州房产公司，经营扬州地区的房地产，既对外出售新房，也回收旧房。
由于只此一家，故而生意十分火爆，奸商们也趁机抬高地价，搞得城里的房屋售
价居高不下。房间里正有几个小姐在向顾客游说，劝说顾客买房，同时也办理旧
房的回收业务。
LONG);
        set("outdoors", "city");
	set("exits", ([
		"west" : __DIR__"ytjie3",
//  "east" : __DIR__"dating", //欧洲杯结束，暂时封闭
	]));
        set("objects",([
        	__DIR__"npc/roomgirl":3,
        ]));
	setup();
}
