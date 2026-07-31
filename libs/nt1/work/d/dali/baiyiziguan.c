//Room: /d/dali/baiyiziguan.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","摆夷字馆");
	set("long", @LONG
摆夷文字有悠久的历史。撒尼叙事长诗『阿诗玛』，武定石刻『风诏
碑』，禄劝石刻『镌字崖』都是著名的摆夷文献。摆夷文一般是由左向右
竖行书写，用毛笔或竹签写在纸或白布上。这儿就有一摆夷学者为人代写
书信，告文，契约等等。
LONG );
	set("exits",([ /* sizeof() == 1 */
	    "south"  : __DIR__"dahejieeast",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

