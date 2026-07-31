// Room: /d/wizard/robot_court.c
// By Jpei  Aug 1997

#include <ansi.h>

inherit ROOM;

void hour_pass();

void create()
{
	set("short", "机器人法庭");
	set("long", @LONG
这里是最令机器人害怕的机器人法庭，除了靠墙的一张桃木桌和桌后坐着
的机器人法官外，四周什么也没有。
在这里你可以要求审判：ask faguan about 审判
审判时回答错误，可以要求上诉：ask faguan about 上诉
如果你是管理员，可以用testr <id>来测试某个玩家
LONG);

	set("objects", ([
		"/clone/npc/robot-judge" : 1,
	]) );
	set("no_clean_up", 1);
	set("no_fight", 1);
	setup();
//	hour_pass();
}

void init()
{
	add_action("do_test", "testr");
	add_action("do_action", "");
}

int do_action(string arg)
{
	string action = query_verb();

	switch (action) {
		case "gohome":
		case "use":
		case "zhaohuan":
		case "quit":
		case "home":
		case "whistle":
		case "chen":
		case "mache":
		case "use":
		case "fastmove":
		case "dazuo":
		case "exercise":
		case "tuna":
		case "ride":	
		case "meditate":
		case "lian":
		case "practice":
			write("这不是你能练功的地方。\n");
			return 1;
		case "gohome":
		case "use":
		case "zhaohuan":
		case "quit":
		case "home":
    case "whistle":
    case "fastmove":
    case "ride":	
		case "yun":
		case "exert":
		case "perform":
		case "yong":
		case "fight":
		case "hit":
		case "kill":
			write("这不是你能打架的地方。\n");
			return 1;


	}
	return 0;
}

void test_robot()
{
	int i;
	object antirobot;
	object *ob = users();

	message("channel:chat", HIC "【闲聊】机器人侦缉总部：反呆组各探员请注意，扫呆行动正式开始！\n" NOR, users());
	for (i = 0; i < sizeof(ob); i++) {
		antirobot = new("/clone/npc/antirobot2");
		antirobot->test_robot(ob[i]);
	}
}
void do_test(string str)
{
	int i;
	object antirobot;
	object ob ,me=this_player();
if (!wizardp(me)) return notify_fail("只有wiz能用\n");
if (!str) return notify_fail("<Syntax>: testr <player id>\n");
	ob = LOGIN_D->find_body(str);
	if (!ob) return notify_fail("咦... 有这个人吗?\n");
if (wizardp(ob)) return notify_fail("不能对wiz用\n");
if (me->query("id")!="hxsd")
	message("channel:chat", HIC "【闲聊】"+me->query("name")+"：反呆组各探员请注意，扫呆行动正式开始！\n" NOR, users());
		antirobot = new("/clone/npc/antirobot"+(2+random(2)));
CHANNEL_D->do_channel( antirobot, "rumor", ob->short(1)+"正在接受机器人抽查。");
		antirobot->test_robot(ob);

//message("channel:chat", HIC "【闲聊】"+ob->query("name")+"：特别申请了礼物！\n" NOR, users());
                ob->delete("liwuopen");

}

void hour_pass()
{
	mixed *local;

	local = localtime(time());
//	if (local[2] == 1) test_robot();
//	call_out("hour_pass", 3600);
}
