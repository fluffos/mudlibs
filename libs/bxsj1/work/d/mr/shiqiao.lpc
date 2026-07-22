#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short",HIW"小石桥"NOR);
	set("long",@long
这是一座小小的白石拱桥。桥下碧绿的湖水正荡着微波。远处的湖面上传
来阵阵歌声，不远处两只鸳鸯在一起戏水，岸边的柳树随着湖面上吹来的微风
时不时地摇摆着。
long);
// will add a npc to ask chuan
	set("outdoors","慕容");
	set("exits", ([
		"south" : __DIR__"testmatou1",
		"northwest" : __DIR__"hubian2",
	]));
	setup();
}

void init()
{
	add_action("do_push", "push");        
}

int do_push(string arg)
{
	if (arg != "桥栏" || query("exits/down")) return notify_fail("你要按什么？\n");
	
	message_vision("桥头突然陷下去了一块，露出一个地洞。\n",this_player());
	
	set("exits/down", __DIR__"didao");
	
	remove_call_out("close");
	call_out("close", 4);

	return 1;
}

void close()
{
	tell_room(this_object(), "地面缓缓的升起来，洞口也消失不见了。\n");
	delete("exits/down");
}

int valid_leave(object me, string dir)
{
	if (me->query("family/family_name") != "姑苏慕容" && dir=="down")
		return notify_fail("一位慕容家丁忽然从阴暗处跳了出来，拦住了你说道：擅闯慕容密道者死！！\n说完，那位家丁身形一晃，又退回暗处。\n");

	return ::valid_leave(me, dir);
}
