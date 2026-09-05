//mjth 2003/10/7

inherit ROOM;

void create()
{
	set("short","千峰崖");
	set("long", @LONG
这就是享誉中外的千峰崖，喀斯特地貌的优势使得华山之
险、衡山之奇、泰山之雄浑、黄山之瑰丽全被它溶于一体。
处处嶙峋的怪石剑拔弩张，声声失足跌落山谷无可奈何的
惨叫，使你在对大自然的鬼斧神工鼎礼膜拜时竟也不由地
产生了一丝的心惊胆战。西边，依稀可见一群人一边神游
天外一边大流口水。
LONG
	);
	set("no_sleep_room",1);
 	set("outdoor","city");
	set("exits",([
		"west" : __DIR__"center",
	]));
	setup();
	replace_program(ROOM);
}