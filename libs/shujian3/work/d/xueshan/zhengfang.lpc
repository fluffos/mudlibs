// Room: zhengfang.c

inherit ROOM;

void create()
{
	set("short", "正房");
	set("long", @LONG
房内灯火通明，靠墙一面一张好大的通炕，挤挤睡四、五十个人不成问题。
现在上面横七竖八的已经躺着不少人。喧闹声此起彼伏，东头有堆人大呼小叫
的好象在赌博。西边一个老头正嘣嘣的弹着把不知名的琴，边上围了几个小孩。
不远处一个孩子哭闹不休，抱着他的妇女背转了身子要哄他喂奶。空气中飘荡
着饭香、汗臭、脂粉、牛马粪混合而成的一股怪味。看来只好将就将就了。
LONG
	);
	set("sleep_room", "1");
	set("no_fight", "1");
        set("hotel",1);

	set("exits", ([
		"out" : __DIR__"dachedian",
	]));
        set("objects", ([__DIR__"npc/woman" : 1,
  			__DIR__"npc/duke" : 3,  
  			__DIR__"npc/oldman" : 1 
        ]));              
	setup();
}
