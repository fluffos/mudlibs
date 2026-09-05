// Room: /city/lichunyuan.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "丽春院");
	set("long", @LONG
你一走进来，一眼就看到大厅的墙上挂着一幅幅春宫图（ｔｕ），一下子就
明白了这是什么地方。厅内到处张灯结彩，香气扑鼻。几名打扮得妖里妖气的女
人分站两旁对你发出媚笑。主人韦春芳上上下下、前前后后招呼着客人。从楼上
传来了阵阵打情骂俏的声音。
LONG);
	
	set("objects", ([
                "/kungfu/class/gaibang/kongkong"      :       1,
                "/d/city/npc/wei"                       :       1,
                __DIR__"npc/guinu" : 1,
	]));
	set("item_desc", ([
        	"tu" : "一块破布挡住了你想要看到的地方，把它揭开(uncover)吗？\n"
	]));
	set("exits", ([
		"west" : "/d/city/nandajie2",
	]));	
	setup();
}

void init()
{
	add_action("do_uncover", "uncover");
}

int do_uncover(string arg)
{
	object me;
	string msg;
	me = this_player();
	if( !arg || arg=="" )
		return notify_fail("你要揭开什么？\n");
	if( arg=="破布" )
	{
		msg="$N看着看着忽然觉得面红耳赤，呼哧呼哧喘起粗气。\n"
			"$N觉得图上的破布挡住了$N的视线，伸手就把破布给扯下来了。\n";
		message_vision(msg,me);
		call_out("water",3,me);
		return 1;
	}
}
void water(object me)
{
	string msg;
	msg="突然楼上掉下一只脸盆，正好扣在$N的头上。\n"
		"$N一闻，好臭啊！！！！\n"
		"原来是韦春芳的洗脚水，哈哈～～\n";
	message_vision(msg,me);
}