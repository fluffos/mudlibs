// guiquan.c 龟泉
// by llin

inherit ROOM;

void create()
{
	set("short", "龟泉");
	set("long", 
"院东侧生有一龟泉，又叫太乙真庆泉。泉水自一断头石龟\n"
"颈中潺潺流出。传说此水是仙水，可却疾延寿，虽不可尽信。\n"
"但泉水却也是清冽可口，院内弟子练功口渴时，常来这里汲\n"
"水饮用。\n"
	);

	set("exits", ([
		"west" : __DIR__"qianyuan",
	]));
	setup();
}
void init()
{
add_action("do_drink","drink"); 
}

int do_drink()
{	object me=this_player();
	if ((int)me->query("water")>((int)me->query("str")+10)*10)
	return notify_fail("灌了一肚子水，你也不难受呀？\n");
	
	me->set("water",450);
	message_vision("$N蹲下身掬起一捧泉水喝了下去，清爽之极。\n",me);
	return 1;
}
