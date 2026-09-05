// /d/taohuadao/shanbi.c 山壁

inherit ROOM;

void create()
{
        set("short", "山壁");
       set("long", @LONG
这是一个不起眼的地方。此处花树繁密，天上虽有明月，
但月光都被枝叶密密地挡挡住了。边上隐约可以看到一个
山洞(hole)。
LONG);
        set("exits", ([ /* sizeof() == 1 */
        "south" : __DIR__"mudi",
        ]));
	set("item_desc",([
	"hole" : "里面黑乎乎的，有一对眼睛碧莹莹的闪闪发光，不知能否进去。\n",
	]));
        set("outdoors","taohuadao");
        set("no_task",1);
	setup();
}
void init()
{
	add_action("do_enter","enter");
}
int do_enter(string arg)
{
	object me, room;
	string name;
	room = find_object(__DIR__"hole1");
	if(!room) room = load_object(__DIR__"hole1");
	me = this_player();
	name = me->query("name");
        if(!arg || arg!="hole")
	return notify_fail("你想往哪里钻?\n");
	if( me->query_temp("zyhb/mudi") )
	{
		message_vision("$N走进了山洞。\n",me);
		me->move(__DIR__"hole1");
		me->delete_temp("zyhb/mudi");
		tell_room(room, name + "从外面走了进来。\n", me);
		return 1;
	}
	else
	{
		tell_object(me, "洞里面阴森恐怖，看得你心惊肉跳，还是先去墓地祭拜一下寻求点心理安慰吧。\n");
		return 1;
	}
}
