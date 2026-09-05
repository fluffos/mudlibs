//rukou.c	小村入口
//by bing

#include <room.h>
inherit ROOM;
string look_pai();
void create()
{
	set("short","小村庄");
	set("long",@LONG 
这是位于半山腰平坦之地的一个小村庄。据说日月神教的总堂－－
黑木崖就在这座山上。这个村庄是日月教众日常活动的地方。虽然他们
在江湖上名声不太好，村子里却是一片鸡犬相闻，生机勃勃的世外桃源
景象。看来江湖上的传言也不甚准确。东面是一大片竹林。村口有善人
捐了一个牌坊(paifang)。
LONG
	);
    set("item_desc",([
  	"paifang" : (:look_pai:),
        ]));
	set("exits", ([
		"southdown" : __DIR__"shanlu",
		"west" : __DIR__"zhuquetang",
		"north"	: __DIR__"cunlu1",
        "east" : __DIR__"zhulin",
		"southeast" : __DIR__"machehang",
	]));
	set("objects",([
               CLASS_D("riyuejiao") + "/tong" : 1,
		__DIR__"npc/jiaozhong1"	: 4,
		]));
	set("outdoors", "riyuejiao");
	setup();

}

string look_pai()
{
    object me=this_player();
    if (me->query("family/family_name")!="日月神教")
    {
        return "这是村民为纪念一位铺路修桥的善人而修建的牌坊。\n";
    }
    else
    {
        return "这是村民为纪念一位铺路修桥的善人而修建的牌坊。顶上似乎有些东西，你可以爬上去看看。\n";
    }
}

void init()
{
    add_action("do_pa",({"pa","climb","pan"}));
}

int do_pa()
{
    object me=this_player();
    object room=load_object(__DIR__"paifang");
    if (me->query("family/family_name")!="日月神教")
    {
        return 0;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    tell_room(this_object(),me->name()+"像猿猴一般灵活地爬上了牌坊。\n");
    me->add_busy(2);
    tell_room(room,me->name()+"从底下爬了上来。\n");
    me->move(room);
    return 1;
}
int valid_leave(object me, string dir)
{
    if (me->query("special_skill/sociability")) 
        return ::valid_leave(me, dir);  
        if (dir == "north" && me->query("family/family_name") != "日月神教" 
        && objectp(present("tong baixiong",environment(me)))
        && living(present("tong baixiong",environment(me))))
			return notify_fail("童百熊说道：「你不是我日月神教弟子，来我教干什么？速速离开！」\n");
        return ::valid_leave(me, dir);
}






