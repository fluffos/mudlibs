// Room: /d/dali/shuyuan.c
// Data: 哈迪斯(hades)
// Time: 公元：1999年4月21日，北京时间：17时34分50秒。

inherit ROOM;

void create()
{
	set("short", "摆夷字馆");
	set("long", @LONG
摆夷文字有悠久的历史。撒尼叙事长诗『阿诗玛』，武定石刻『
风诏碑』，禄劝石刻『镌字崖』都是著名的摆夷文献。摆夷文一般是
由左向右竖行书写，用毛笔或竹签写在纸或白布上。这儿就有一摆夷
学者为人代写书信，告文，契约等等。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"nandajie2",
  "west" : __DIR__"shuyuan2",
]));

        set("objects", ([
//                __DIR__"npc/zhu" : 1,
        ]));

	setup();
}
