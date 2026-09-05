// Room: /d/shaolin/shijie9.c
// Date: YZC 96/01/19
//change by skywolf 2009-2-13 for bingcan-cloth
#include <ansi.h> 
inherit ROOM;
int do_hide();
void create()
{
	set("short", "石阶");
	set("long", @LONG
眼前遽然出现一大片松林。松林长得极密，石阶上铺满了厚
厚的朽黄的松针。踩在脚下，发出察察的响声。一只小松鼠吱地
在眼前闪过，消失在林海里。
LONG
	);

	set("exits", ([
		"southdown" : __DIR__"shijie8",
		"northup" : __DIR__"shijie10",
		"east"    : __DIR__"caidi",
	]));

	set("outdoors", "shaolin");
	setup();
}

void init()
{
	object me=this_player();
	object room,npc;
	if(!( room = find_object(__DIR__"caidi")) )
		room = load_object(__DIR__"caidi");
    
	if(present("shenmu wangding",me) && me->query_temp("bingcan/findcan")  )
	{
		npc=new("/d/shaolin/npc/hui-jing");
		npc->move(room);
		if (objectp(present("hui jing", room)))
		{
			write(RED"你追到这里，似乎冰蚕跑到了前面的菜地里。
你刚要急奔过去，忽听得园中有人在大声叱骂，立即停步。
看来你要藏（hide）起来，免得把蚕惊走。\n"NOR);
			
			add_action("do_hide","hide"); 
		}
		else
		{
			write(RED"你追到这里，再也没有冰蚕的线索。。\n"NOR);
		}
		
	}
	
}

int do_hide()
{
	object me=this_player();
	me->set_temp("bingcan/hide_busy",1);                   //玩家hide，触发剧情，不能移动。
	write("你急忙躲在树后，偷偷往菜地张望。\n");
	call_out("show_huijing",5,this_player());
	return 1;
}

int show_huijing()
{
	write(HIC"只听那人骂道：“你怎地如此不守规矩，一个人偷偷出去玩耍？
害得老子担心了半天，生怕你从此不回来了。老子从昆仑山巅
万里迢迢的将你带来，你也太不知好歹，不懂老子对待你一片
苦心。这样下去，你还有什么出息，将来自毁前途，谁也不会
来可怜你。”那人语音中虽甚恼怒，却颇有期望怜惜之意，似是
父兄教诲顽劣的子弟。\n"NOR);
	call_out("huijing_leave",5,this_player());
	return 1;
}

int huijing_leave()
{
	object room,ob,can;
	if(!( room = find_object(__DIR__"caidi")) )
		room = load_object(__DIR__"caidi");
    ob=present("hui jing",room);
	can=new("/d/shaolin/npc/bingcan");
	can->move(room);
	destruct(ob);
	this_player()->delete_temp("bingcan/hide_busy");        //慧净走后玩家可以移动
	write(HIW"忽听得菜园彼端有人叫道：“慧净，慧净！”那矮胖和尚一听，吃一惊，忙将酒葫芦在稻草堆中一塞，
只听那人叫：“慧净，慧净，你不去做课，躲那里去啦？”那矮胖和尚忙道：“我这就来。”那人
走了过来，是个中年和尚，冷冰冰的道：“晨课晚课，人人要做！快去，快去！”那名叫慧净的
矮胖和尚应道：“是！”跟着他去了，不敢回头瞧那蚕儿，似是生怕给那中年和尚发觉。 "NOR);
}

int valid_leave(object me, string dir)
{
	if(me->query_temp("bingcan/hide_busy"))
		return notify_fail(HIY"你现在藏着呢，小心乱走惊走了冰蚕。\n"NOR);
	return ::valid_leave(me, dir);
}