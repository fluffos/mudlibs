// Room: /d/dzd/matou.c
#include <ansi.h>
inherit __DIR__"dzd_room";

int do_leave(string arg);

void create()
{
	set("short","码头");
	set("long",@LONG
这里是大智岛的码头，却没有任何船只停泊，显得冷冷清清。极目远眺，
只见海天一色,波涛汹涌.旁边兀立一块岩石(rock)，海淘汹涌，岩石却屹然不动。
边上有只小船，你你可以查看(chakan)岛内情况也可以随时离开(leave)。
LONG
	);
	set("item_desc",([
	"rock" : HIC"线做长江扇做天，靸鞋抛向海东边。\n"
	         HIC"蓬莱此去无多路，只在潭生拄杖前。\n"NOR,
	]));
	set("no_fight",1);
	set("outdoors","大智岛");
	set("exits",([
		"northeast" : __DIR__"haitan3",
		"northwest" : __DIR__"haitan1",
		"north" : __DIR__"haitan2",
		]));
	set("objects",([
		__DIR__"npc/npc_dzd" : 1,
		MISC_D("dzd_flag"):1,
		]));
	setup();
}
void init()
{
	object me = this_player();
	::init();
	add_action("do_leave",({"leave","likai"}) );
	if (me && environment(me) == this_object() && userp(me) )
		call_out("do_push",30+random(30),me);
}
void do_push(object me)
{
	if(!me) return;
	if (environment(me) == this_object() ) {
		message_vision("一个人不耐烦地哼叽，那是谁，怎么比猪还慢啊？要么大伙拱$N算了。\n",me);
		"/cmds/std/go"->main(me,"north");
		//me->move("/d/dzd/haitan2");
	}
	return;
}
int valid_leave(object me,string dir)
{
	if(me->query_temp("job_xkd/dead"))
		return notify_fail("还敢去啊？\n");
	return 1;
}

int do_leave(string arg)
{
	if(!this_player()) return 0;
	if(!this_player()->query_temp("job_xkd/dead")) return notify_fail("还没上去就打退堂鼓了啊。\n");
	write("既然如此。。。。。。。\n");
	this_object()->backhome(this_player());
	return 1;
}
/*
避免挨骂 ^_^		
int valid_leave(object me,string dir)
{
	int i,j;
	string *oblist1,*oblist2;
	object *obj;
	oblist1 = ({"jiedu wan","huoxue dan","chantui yao","chuanbei wan","danggui dan","fuling wan","yannian dan","liaojing dan",
			"jinchuang yao","xujing dan","jinchuang yao","xujing dan","buqi wan","yangjing dan","yuling san","yuzhen san",
			"heishi dan","baicao dan","wulong gao","qingxin san","huxin dan","baola wan","renshen guo","xue lian"});
	oblist2 = ({"wujin beixin","bishou","ziwei jian","wangnangu dujing"});

	obj = all_inventory(me);
	j = sizeof(obj);
	for(i=0;i<j;i++) {
		if(member_array(obj[i]->query("id"),oblist1) != -1 && (dir == "north" || dir == "northeast" || dir == "northwest")) {
			
			message_vision("有个人从旁边过来，把$N身上的" + obj[i]->name() + "搜走了！\n",me);
			destruct(obj[i]);
			return notify_fail("你不能带疗伤圣药参与冒险！\n");
		}
		if(obj[i]->query("unique") && member_array(obj[i]->query("id"),oblist2) == -1 && (dir == "north" || 
				dir == "northeast" || dir == "northwest")) {
			
			message_vision("有个人从旁边过来，把$N身上的" + obj[i]->name() + "搜走了！\n",me);
			destruct(obj[i]);
			return notify_fail("你不能带宝物参与冒险！\n");
		}
	}
	return ::valid_leave(me, dir);
}
*/