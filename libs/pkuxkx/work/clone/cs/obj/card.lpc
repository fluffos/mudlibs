//card.c
//cs 参赛资格牌

#include <ansi.h>
inherit ITEM;


int destroy_card(object ob);
int die();

mapping block_commands = 
([
	"kill" : 1,
	"steal" : 1,
	"hit" : 1,
	"killall" : 1,
	"hitall" : 1,
	"beg" : 1,
	"follow" : 1,
	"put" : 1,
//	"get" : 1,
	"exert" : 1,
	"perform" : 1,
//	"drop" : 1,
]);
	

void create()
{       
	seteuid(getuid());
	set_name(HIW"参赛卡"NOR, ({ "card" }));
	set_weight(1);
	set("no_get", 1);
	set("no_put", 1);
	set("no_drop",1);
	set_max_encumbrance(0);
	set("value", 0);
	set("unit", "张");
	set("long", "这是一张cs参赛资格卡\n");
}

void init()
{
	add_action("do_quit","quit");
	add_action("do_quit","exit");
	add_action("do_listen","listen");
	add_action("do_shoot","shoot");
	add_action("do_check","check");
	add_action("do_join","join");
	add_action("do_knife","knife");
	add_action("do_hp","hp");
	add_action("do_msg","msg");
	add_action("do_msgall","msgall");
	add_action("do_reload","reload");				//换弹夹
	add_action("block_cmd","", 1);
}

int do_msg(string args)
{
	object referee = query("referee");
	object me = this_player();
	if(!args)
		return notify_fail("请使用msg + 你想说的话。\n");
	referee->Declair(me->query_temp("cs/team"), HIC + me->query("name") + "说："HIG + args);
	return 1;
}
int do_msgall(string args)
{
	object referee = query("referee");
	object me = this_player();
	if(!args)
		return notify_fail("请使用msgall + 你想说的话。\n");
	referee->Declair("all", HIC+ me->query("name") + "说："HIW + args);
	return 1;
}
int block_cmd(string args)
{
	object me = this_player();
	string verb = query_verb();
	
	if(query("owner") != me)	
		return 0;
	if(block_commands[verb])
	{
		tell_object(me, "你还是专心玩cs吧。\n");
		return 1;
	}
	return 0;
}

int do_join(string args)
{
	if(args != "t" && args != "ct")
		return notify_fail("你想进入哪个队伍(join t 或者 join ct )？\n");
	query("referee")->SelectTeamForPlayer(this_player(),args);
	return 1;	
}

int do_quit()
{
	tell_object(this_player(), "你退出了cs大赛。欢迎下次再来！\n");
	query("referee")->quit(this_player());
	call_out("destroy_card",0,this_object());
	return 1;
}

int do_reload()
{
	object me = this_player();
	object weapon = me->query_temp("weapon");
	int cnt;
	if(weapon->query("cs/type") <= 1)
		return notify_fail("你要给" + weapon->query("name") + "换弹夹？\n");	
	if(me->is_busy())
		return notify_fail("你正忙着呢！\n");
	if(weapon->query("buttles") >= weapon->query("max_bullets"))
		return notify_fail(weapon->query("name") + "的子弹是满的你也换弹夹？\n");
	if(me->query_temp("cs/bullets") <= 0)
		return notify_fail("你已经没有子弹可以换了！\n");
	me->start_busy(3);
	message_vision("$N掏出弹夹，忙不迭的开始给" + weapon->query("name") + "上子弹。\n", me);
	cnt = weapon->query("max_bullets") - weapon->query("bullets");
	if(cnt >= me->query_temp("cs/bullets"))
		cnt = me->query_temp("cs/bullets");
	me->add_temp("cs/bullets", -cnt);
	weapon->add("bullets", cnt);
	return 1;
}

int do_shoot(string args)
{
	object me = this_player();
	object weapon = me->query_temp("weapon");
	if(!objectp(weapon))
		return notify_fail("你想空手对付敌人？\n");
	if(!weapon->query("cs/type"))
		return notify_fail("你没有装备杀人武器！\n");
	if(weapon->query("cs/type") != 2 && weapon->query("cs/type") != 3)
		return notify_fail("你没有拿枪！\n");

	if(me->query_temp("cs/defusing"))
		return notify_fail("拆雷要紧！\n");	
	if(me->query_temp("cs/planting"))
		return notify_fail("埋雷要紧！\n");	
	if(args)
		return weapon->shoot(args);
	return notify_fail("放空枪？\n");
}
int do_knife(string args)
{
	object me = this_player();
	object weapon = me->query_temp("weapon");
	if(!objectp(weapon))
		return notify_fail("你想空手对付敌人？\n");
	if(!weapon->query("cs/type"))
		return notify_fail("你没有装备杀人武器！\n");
	if(weapon->query("cs/type") != 1)
		return notify_fail("你没有拿刀！\n");
	if(me->query_temp("cs/defusing"))
		return notify_fail("拆雷要紧！\n");	
	if(me->query_temp("cs/planting"))
		return notify_fail("埋雷要紧！\n");	
		
	me->set_temp("cs/shoot_flag_for_bomb", 1);	//用于埋雷/拆雷中的标志
	if(args)
		return weapon->knife(args);
	message_vision("$N闲得无聊，掏出" + weapon->query("name") + "四处乱捅。\n", me);
	return 1;

}

int destroy_card(object ob)
{
	destruct(ob);
}
int receive_damage(object from, int damage, object weapon, int hs_flag)
{
	int is_knife = 0;
	object me = query("owner");
	if(weapon->query("cs/type") == 1) //#define CS_KNIFE	1
		is_knife = 1;
	me->add_temp("cs/hp", -damage);
	tell_object(me, "你被" + from->query("name") + (is_knife ? "刺":"打") + "中了，受到"+damage+"点伤害。\n");
	if(me->query_temp("cs/hp") <= 0)
	{
                message( "channel:" + "hslj",HIM+ "【谣言】某人："+me->query("name")+"被"+from->query("name")+"用"+weapon->query("name")
			+ (hs_flag == 1 ? HIW"爆头" : HIM"干掉") + HIM"了。\n"NOR,users());
		tell_object(me, "你死了。\n");
		me->set_temp("cs/killedby", from);
		me->set_temp("cs/killedbyheadshot",hs_flag);
		if(is_knife)
			me->set_temp("cs/killedbyknife", 1);
		query("referee")->die(me);
	}	
}
int receive_bomb_damage(int damage)
{
	object me = query("owner");
	me->add_temp("cs/hp", -damage);
	tell_object(me, "你被飞来的弹片打中了，受到"+damage+"点伤害。\n");
	if(me->query_temp("cs/hp") <= 0)
	{
                message( "channel:" + "hslj",HIM+ "【谣言】某人："+me->query("name")+"被炸死了。\n"NOR,users());
		tell_object(me, "你死了。\n");
		query("referee")->die(me);
	}	
	return 1;
}

int do_listen()
{
	object referee = query("referee");
	object me = this_player();
	int pos, distance;
	if(me->query_temp("cs/team") == "t")
		return notify_fail("用check命令会更方便一些！\n");
	
	pos = referee->RoomIndex(base_name(environment(me)));
	if(pos < 0)
		return notify_fail("你没有听到任何声音！\n");
	if(referee && referee->query_temp("cs/c4_position"))
		return notify_fail("你没有听到任何声音！\n");
	distance = referee->Distance(pos, referee->query_temp("bomb_position"));
	if(distance < 0)
		return notify_fail("你没有听到任何声音！\n");
	if(distance == 0)
		tell_object(me, HIW"嘀嘀嘀嘀~~~~~，雷就在你脚下要爆炸了，赶紧逃命吧！！！\n"NOR);
	else if(distance < 3)
		tell_object(me, HIW"嘀~~~~~，雷就在这附近了，仔细找找吧！\n"NOR);
	else if(distance < 5)
		tell_object(me, HIW"你停下脚步侧耳倾听，似乎听到不远处传来 嘀~的声音。\n"NOR);
	else if(distance < 7)
		tell_object(me, HIW"你停下脚步仔细听了半天，似乎听到远处传来 嘀~的声音。\n"NOR);
	else 
		tell_object(me, HIW"你趴在地上听了一会，似乎听到不知从哪传来的 嘀~的声音。\n"NOR);
	return 1;
}

int do_hp()
{
	object me = this_player();
	object weapon = me->query_temp("weapon");
	string msg;
	if(me->query_temp("cs/hp") < 0)
		msg = "你已经死了。\n";
	else
		msg = "你还有" + chinese_number(me->query_temp("cs/hp")) + "点生命值。\n";
	msg += "你身上还有" + chinese_number(me->query_temp("cs/bullets")) + "颗备用子弹。\n";
	
	if(weapon && weapon->query("cs/type") > 1)
		msg += weapon->query("name") + "还剩下" + chinese_number(weapon->query("bullets")) + "颗子弹，最多能装备" 
							 + chinese_number(weapon->query("max_bullets")) + "颗子弹。\n" ;
	msg += "你还剩下" + chinese_number(me->query_temp("cs/money")) + "CS币。\n";
	tell_object(me, msg);
	return 1;
}

int do_check()
{
	object me = this_player();
	object referee = query("referee");
	object* cards = children(__DIR__"card");
	object target,c4;
	int i;
	string team = me->query_temp("cs/team");
	string msg = "雷达显示cs游戏成员分布如下：\n";

//	if(!referee->IsValidBombRoom(base_name(environment(me))))
//	{
//		tell_object(me, "在战场上才能使用雷达！\n");
//		return 1;
//	}
//		return notify_fail("这个命令只能在战场上使用！\n");	


	write(msg);

	
	for(i = 0; i < sizeof(cards); i++)
	{
		target = cards[i]->query("owner");
		if(!target || !target->query_temp("cs"))
			continue;
		if(target->query_temp("cs/team") == team)
			msg = target->query("name") + "(" + HIB + target->query("id") + NOR ")  在  " + environment(target)->query("short");
		else if(target->query_temp("cs/team"))
		{
			msg = target->query("name") + "(" + HIR + target->query("id") + NOR ")  ";
			if(!referee->IsValidBombRoom(base_name(environment(target))))
				msg += "在  " + environment(target)->query("short");
		}
		msg += "  杀" + target->query_temp("cs/kills") + "人次，被杀" + target->query_temp("cs/killeds") + "次";
		if(target->query_temp("cs/die"))
			msg += HIW"   已死亡"NOR;
		msg += "\n";
		write(msg);
	}
	if(me->query_temp("cs/team") == "t")
	{
		c4 = referee->query_temp("c4");
		if(c4)
		{
			msg = c4->query("name") + "目前在" + (userp(environment(c4)) ? environment(c4)->query("name") + "身上。\n" : environment(c4)->query("short") + "。\n");
			
			write(msg);
		}
	}
	return 1;
}

