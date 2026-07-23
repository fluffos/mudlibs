// /d/taiyuan/road5.c
// Room in 太原
// modify by yang

inherit ROOM;

void create()
{
	set("short", "龙山石窟");
	set("long", @LONG
太原两南26公里的南郊区西镇村西的龙山东峰顶，是我国现存规模最大，也是
最珍奇的道教石窟。主窟开凿于元太宗六年至十一年(公元1234至1239年)，由道士
宋德芳(道号披云子)主持兴建。在峰顶峭壁上共凿有8个洞窟。龙山石窟有道教石
雕像66尊、浮雕云龙8条和双凤藻井、仙鹤等许多浮雕。石雕风格朴实、凝练、庄
重、衣饰简洁素静、褶皱分明，与佛教石窟雕像风格迥异。
LONG );
	set("exits", ([
                "south" : __DIR__"road7-1",
		"northeast" : __DIR__"road6",
		"southwest" : __DIR__"road4",
		
	]));
	set("outdoors", "taiyuan");
	setup();
	replace_program(ROOM);
}



