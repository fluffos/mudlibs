//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "玉霞山");
	set("long", @LONG
玉霞山东镇星云湖，山清林秀，许多游人来此欣赏湖光山色，无
不为之倾倒。古人有诗曰：
      玉霞凄清秋气凉，
      星云湖水澄明光，
      近屿含烟凝紫翠，
      远山峭壁摩青苍，
      水光山色相辉映，
      万里无云碧天净。
LONG
        );

	set("exits", ([
		"westdown" : __DIR__"minov36",
		]));

	set("objects", ([
		__DIR__"npc/youke1.c" : 1,
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
