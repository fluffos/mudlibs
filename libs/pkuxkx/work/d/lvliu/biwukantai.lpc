#include <ansi.h>
#include <room.h>
#include "nodie.h"
inherit ROOM;
void create()
{
	set("short", "比武看台");
	set("long",	"这是比武场旁边的一座阁楼，被用来作为比武看台。阁楼地处高位，四面通风，
极宜登高望远。坐在这里，你可以把周边四个比武场中的一切纳入眼底。可以一边欣
赏(sight)武林高手对决，一边惬意地烹茶品茗。若是技痒，还可下楼入场一展身手。\n"NOR);
	set("no_fight", 1);
	set("no_perform", 1);
	set("no_steal", 1);
	set("exits", ([
		"down" : __DIR__"biwulouxia",
	]));
	setup();
}

void init()
{
	add_action("do_sight", "sight");
}

string show_sight(object me)
{
	int *directions;
	string msg = "";
	directions = me->query_temp("lvliu/biwukantai/directions");
	if (sizeof(directions)>=4)
	{
		if (directions[0]) msg += "甲";
		if (directions[1]) msg += "乙";
		if (directions[2]) msg += "丙";
		if (directions[3]) msg += "丁";	
	}
	return msg;
}

int sight_count(object me)
{
	int *directions;
	int c = 0;
	directions = me->query_temp("lvliu/biwukantai");
	if (sizeof(directions)>=4)
	{
		if (directions[0]) c++;
		if (directions[1]) c++;
		if (directions[2]) c++;
		if (directions[3]) c++;	
	}
	return c;
}

int do_sight(string arg)
{
	int num, *directions;
	string *actions = ({ "挖着鼻孔","打着呵欠","伸着懒腰","挠着头皮","数着手指","抹着眼屎","画着圈圈", });
	object room, pl;
	object me = this_player();
	if (!arg)
	{
		num = sight_count(me);
		if (num>1) tell_object(me, HIG"你现在正在关注" HIM +show_sight(me) + HIG + chinese_number(num)+"个比武场中的动静。\n"NOR);
		else if (num==1) tell_object(me, HIG"你现在正在关注" HIM +show_sight(me)+ HIG "字比武场中的动静。\n"NOR);
		else tell_object(me, HIG"你现在没有关注比武场中的动静。\n" +
			HIY "你可以用 sight 甲/乙/丙/丁 来关注各个比武场中的比试，或者用 sight none 取消关注。\n" NOR);
		return 1;
	}
	if (arg == "none")
	{
		me->delete_temp("lvliu/biwukantai");
		tell_object(me, HIG"你收回目光，不再关注比武场中的动静。\n"NOR);
		return 1;
	}
	if (arg == "甲" || arg == "乙" || arg == "丙" || arg == "丁")
	{
		directions = me->query_temp("lvliu/biwukantai");
		if (sizeof(directions)<4) directions = ({0,0,0,0});
		switch (arg)
		{
			case "甲": directions[0] = 1; num = 1; break;
			case "乙": directions[1] = 1; num = 2; break;
			case "丙": directions[2] = 1; num = 3; break;
			case "丁": directions[3] = 1; num = 4; break;
		}
		me->set_temp("lvliu/biwukantai", directions);
		room = load_object(__DIR__"biwuchang" + num);
		num = sight_count(me);
		if (num>1) tell_object(me, HIG"你现在正在关注" HIM +show_sight(me) + HIG +chinese_number(num)+"个比武场中的动静。\n"NOR);
		else tell_object(me, HIG"你在窗边坐下，开始关注" HIM +show_sight(me)+ HIG "字比武场中的动静。\n"NOR);
		if (objectp(room))
		{
			pl = room->player_in_use();
			if (objectp(pl))
			{
				tell_object(me, HIY "这会儿" + pl->query("name") + HIY "正在「" + room->query("short") + HIY "」中接受挑战。\n" NOR);
			}
			else
			{
				tell_object(me, HIY "「"+ room->query("short") + HIY "」中空荡荡的，只有裁判在无聊地"+actions[random(sizeof(actions))]+"。\n" NOR);
			}
		}
		return 1;
	}
	tell_object(me,	HIY "你可以用 sight 甲/乙/丙/丁 来关注各个比武场中的比试，或者用 sight none 取消关注。\n" NOR);
	return 1;
}

int valid_leave(object me, string dir)
{
    if (userp(me) && sight_count(me)>0)
	{
		tell_object(me, HIG"你收回目光，不再关心比武场中的动静。\n"NOR);
		me->delete_temp("lvliu/biwukantai");
	}
    return ::valid_leave(me, dir);
}

// 比武场中的裁判通过调用该函数来向看台上的观众传递信息

int listening_biwuchang(object me, int direction)
{
	int *directions;
	directions = me->query_temp("lvliu/biwukantai");
	if (direction < 1 || sizeof(directions) < direction)  return 0;
	return directions[direction-1];
}

void show_biwuchang_msg(string msg, int direction) 
{
	object *obs = all_inventory(this_object());
	for (int i=0; i<sizeof(obs); i++)
	{
		if (!userp(obs[i])) continue;
		if (listening_biwuchang(obs[i], direction))
			tell_object(obs[i], msg);
	}
}

