// Room: /d/gb/pomiao.c
// update by Looklove at 2000/8/25

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "土地庙");
	set("long", @LONG
这是一间破破烂烂的土地庙，庙里破败不堪，土地神像推在一旁，梁上地
下也布满了灰尘。一看就知道已经很久没有人来清理过了。正中放着个大香案，
上面零乱地扔着几根吃剩下来的鸡骨头。也许正是因为隐蔽的原因吧，据说丐
帮江南据点就被设在此处。北面墙上开着一个小门。
LONG
	);
	set("valid_startroom", 1);
	set("outdoors","苏州");
	set("exits", ([
		"south" : __DIR__"xinglin9",
		"north" : __DIR__"houyuan",
	]));
	set("objects", ([
		CLASS_D("gaibang") + "/lu" : 1,
	]));
	setup();
	create_door("north", "竹门", "south", DOOR_CLOSED);
}

void reset()
{
	object ob=present("lu youjiao",this_object());
	::reset();
	if(ob){
		ob->delete_temp("gb_job2");
		ob->delete_temp("gb_job3");
		ob->delete_temp("smy_job");
	}
}

void init()
{
        object me = this_player();
	int i;
        if ( userp(me) && me->query("gb_bags") && !me->query_temp("change_bags")){
		i = me->query("gb_bags");
                me->set("gb/bags", i);
                me->delete("gb_bags");
                me->set_temp("change_bags", 1);
		log_file("change_gb", sprintf("%8s%-10s 袋数标记修改完毕，此人当前为%3d袋。",
			me->query("name"), "("+me->query("id")+")", me->query("gb/bags")), me);
        }
}
int valid_leave(object me, string dir)
{
        if (!wizardp(me) && dir == "north" && objectp(present("lu youjiao", environment(me)))){
        	if ( me->query_temp("noget_wugou")>10)
			return notify_fail("鲁有脚拦在你的身前道：“帮主现在不想见你。”\n");
	}
        return ::valid_leave(me, dir);
}