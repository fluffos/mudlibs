//Room: /d/dali/heisenlin.c
inherit ROOM;
void create()
{
	set("short","黑森林");
	set("long",@LONG
迎面一大片黑压压的森林，高大的古松参天而立。左首一排
九株大松树，看起来有些特别。
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "south"      : __DIR__"dasenlin",
	]));
	set("no_clean_up", 0);
	setup();
}

