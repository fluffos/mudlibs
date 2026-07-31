// Room: /d/dali/huanggong17.c
// Data: 哈迪斯(hades)
// Time: 公元：1999年4月18日，北京时间：21时27分26秒。

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
这里是练武场与嘉明殿之间的一条长廊，两旁玉柱雕栏衬得这条
白石铺成的小廊格外清净、雅致。长廊外是一个小池，池里游鱼晶莹
剔透，池中央一座假山上一条涓涓细流注入池中，好一幅山水田园图。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"huanggong16",
  "east" : __DIR__"huanggong3",
]));

	setup();
}

