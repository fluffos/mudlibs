// d/yanziwu/npc/chuanfu.c

inherit KNOWER;

void create()
{
	set_name("船夫", ({ "chuanfu", "chuan fu" }));
	set("gender", "男性" );
	set("age", 22 + random(5));
	set("long",
	  "这是一个年轻的船夫，闪动着狡黠的目光望着周围。\n");
	set("attitude", "friendly");
	setup();
}
