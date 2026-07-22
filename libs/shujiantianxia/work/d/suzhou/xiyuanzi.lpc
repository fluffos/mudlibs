inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIC"戏园子"NOR);
        set("long", @LONG
这是一座苏州城里鼎鼎有名的戏园，戏园中生，旦，净，墨，丑一应具
全，场中一个大戏台，台上正在唱着《遇长春》，台下不时地传来票友们的
叫跃，喝彩声。你也忍不住想坐下来看看戏，放松一下筋骨。
LONG
);
	set("exits", ([
		"northeast" : __DIR__"beidajie1",
		"north" : __DIR__"majiu",
	]));
	set("objects",([
		__DIR__"npc/piaoyou" : 2,
	]));
	set("incity",1);
	setup();
}
