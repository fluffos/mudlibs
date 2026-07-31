// Room: /d/suzhou/woshi.c

inherit ROOM;
string* sleep=({
	"睡得正香。",
	"呼噜打得震天响。",
	"咯吱咯吱的磨着大牙。",
	"睡梦中还笑个不停。",
	"头歪枕着，嘴角边溜了一地的~o~。",
	});
void create()
{
	set("short", "卧室");
	set("long", @LONG
这儿是个休息的好地方。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"down" :__DIR__"kezhan",
]));
	set("no_fight",1);
	set("no_magic",1);
	set("no_steal",1);

	setup();
}
void init()
{
	add_action("do_sleep","sleep");
	add_action("do_command","");
}
int do_command()
{
	object me;
	me=this_player();
	if(me->query_temp("block_msg/all")==1)	{
	me->set_temp("block_msg/all",0);
	tell_object(me,"你正睡着呢！\n");
	me->set_temp("block_msg/all",1);
	message_vision("$N翻了个身，又憨睡过去了。\n",me);
	return 1;
	}
	return 0;
}
int valid_leave(object me,string dir)
{
	if(me->query_temp("block_msg/all")==1)	return 0;
	return 1;
}
int do_sleep()
{
	object me;
	me=this_player();
	message_vision("$N打了个哈欠，睡到了床上。\n",me);
	me->set_temp("block_msg/all", 1);
	me->set_temp("apply/short",({me->name()+sleep[random(sizeof(sleep))]}));
	call_out("do_wake",100-random(me->query("con")),me);
	me->set("eff_kee",me->query("max_kee"));
	me->set("kee",me->query("max_kee"));
	me->set("eff_sen",me->query("max_sen"));
	me->set("sen",me->query("max_sen"));
	me->set("eff_gin",me->query("max_gin"));
	me->set("gin",me->query("max_gin"));
	return 1;
}
int do_wake(object me)
{
	me->delete_temp("apply/short");
	me->set_temp("block_msg/all", 0);
	message_vision("$N伸了个懒腰，从床上爬了起来。\n",me);
	return 1;
}
