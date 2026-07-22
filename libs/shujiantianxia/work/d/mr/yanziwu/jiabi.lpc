// /u/beyond/mr/jiabi.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short",HIW"夹壁"NOR);
	set("long",@long
这是书架后面的一道夹壁，要用力推开书架的后面。才有可能出去。
long);
	set("exits",([
             "north" : __DIR__"hssg",
	]));
	setup();
}

void init()
{
	add_action("do_push", "push");

}

int do_push(string arg)
{
	object me;
	me = this_player();

	if (arg !="shujia") 
		return notify_fail("你要干什么？\n");
	if( arg=="shujia"){
		write("你推了一下书架，书架向两边一移。\n");
		message("vision", me->name() + "身行一闪突然不见了。\n", environment(me), ({me}) );
		me->move(__DIR__"shufang");
		message("vision", me->name() + "走了过来。\n", environment(me), ({me}) );
	}
	return 1;
}

int get_object(object ob)
{
        if(userp(ob))
        return 1;
        return 0;
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	object *obj;
     
	myfam = (mapping)me->query("family");
     
	if ( myfam && myfam["family_name"] != "姑苏慕容" &&dir=="north") {
		return notify_fail("一位慕容家丁忽然从阴暗处跳了出来，拦住了你说道：擅闯还施水阁者死！！\n说完，那位家丁身形一晃，又退回暗处。\n");
	}
     
	obj = filter_array(deep_inventory(me),(:get_object:));
	if( sizeof(obj) && dir=="north" ){
		tell_object(me,"你一不小心，被门槛绊倒了。\n");
		obj[0]->move(environment(me));
		me->unconcious();
		return 0;
	}
	return ::valid_leave(me, dir);
}
