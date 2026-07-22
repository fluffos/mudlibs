// qqll.c 七窍玲珑
// kxkxkx 2004年3月
//【仙人】刺猬(Ciwei)：程式：/d/gumu/qqll/qqll.c 第 410 行

// 七窍玲珑有如下属性，分别在程序不同的地方设置：
//    "pal"            <--   team member object
//    "ok"             <--   任务ok
//    "killer"         <--   当前的killer object
//    "killers"        <--   已出现的蒙面杀手数
//    "max_killers"    <--   最多出现的蒙面杀手数
//    "d_area_n"       <--   目的地区域名
//    "d_room"         <--   目的地object

#include <ansi.h>
#include <command.h>

inherit ITEM;

private nomask int check_team_hook(string arg);
private nomask int qqll_valid_team();
private nomask void check_team_hook_completion(object user);

private nomask int ask_hook(string arg);
private nomask mixed do_ask(string arg);

private nomask int go_hook(string arg);
private nomask int move_with_killer();
//private nomask 
int encounter_killer();
private nomask int encounter_cyl();

void give_hook_completion(object user);

void create()
{
	set_name(HIG"七眼石"NOR, ({"qiyan shi","qiyan stone"}));
	set_weight(25000);
	if(clonep())
	set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "一块毫无奇特之处的顽石。\n"
		"竟不知道为何被人称为“七窍玲珑”。\n"
		"上面坑坑洼洼有七个小石眼。\n"
		"隐约布成北斗七星的形状。\n"
		"这样一方普通得不能再普通的石头，\n"
		"江河湖海，名山大川中应该多的是，\n"
		"竟不知道为何被人称为[七窍玲珑]。\n"
		);
		set("value", 800000);
		set("no_sell", 1);
		set("no_drop", 1);
		set("no_get", 1);
		set("no_steal", 1);
		set("no_give",1);
	}
	setup();   
}

void init()
{
	add_action("check_team_hook", "", 1);
	add_action("ask_hook", "ask ", 2);
	add_action("go_hook", "go ", 2);	
	
	call_out("dest", random(200)+1200);	
}

void debug(string msg)
{
	return;
	message("wizard:ciwei",msg+"\n",users() );
}

void debug_start()
{
	object ob;
	
	ob = new(__DIR__"cyl");
	ob->move(environment(this_player()));
	set("cyl",ob);
	ob = find_player("shadao@ln");
	set("pal",ob);	
}

int can_cmds()
{
	object pal = query("pal",1);
	object user = this_player();
	
	if(wizardp(user) && user->query("env/test")) return 1;
		
	if(!pal) return 0;
	if(!user) return 0;
	if(!environment(user)) return 0;
		
	if(!present(pal,environment(user)))
	{
		tell_object(user,HIY"你的搭档去哪里了？\n"NOR);
		return 0;
	}
	return 1;
}

void dest()
{
	message_vision("$N忽然掉落在路上，你再也不见了。\n", this_object());
	destruct(this_object());
}

// 检查team是否符合要求，总是返回0（让command能被正常处理）。
private nomask int check_team_hook(string arg)
{
	object user;
	
	user = this_user();
	if(qqll_valid_team() || (wizardp(user) && user->query("env/test")) )
	return 0;
	// team不合要求了，任务失败
	call_out("check_team_hook_completion", 1, user);
	return 0;
}

// 判断（得到任务后的）team是否有效
private nomask int qqll_valid_team()
{
	object user, *team;
	
	user = this_user();
	team = user->query_team();
	
	debug( sprintf("Me:%O \nPal:%O\n T:%O \n",user,query("pal", 1),team) );
	
	if(user->is_team_leader() &&
	sizeof(team) == 2 &&
	team[1] == query("pal", 1)) {
		return 1;
	}
	
	debug("error\n");	
	return 0;
}

// check_team_hook的compeltion函数
// 注意：任务因为team出错而失败，如果因为team的成员quit而dismiss时，
// 那个成员的job_busy不会减少，否则必须load那个成员，有安全隐患
private nomask void check_team_hook_completion(object user)
{
	object pal, killer;
	
	if(!user->is_ghost())
	user->apply_condition("job_busy", 10); // 如果没死
	pal = query("pal", 1);
	// 如果同伴quit了，就无法减少他的job_busy了。
	if(pal && !pal->is_ghost()) {
		pal->apply_condition("job_busy", 10);  // 如果没quit，没死
	}
	killer = query("killer", 1);
	if(!killer) {
		tell_room(environment(user), query("name") + "突然从" +
		user->query("name") + "的身上掉下来不见了！\n", ({user}));
		tell_object(user, query("name") +
		"突然从你的身上掉下来不见了！\n");
	}
	else {
		if(user->is_ghost()) {
			killer->force_me("yeah");
			tell_room(environment(killer), killer->query("name") + "从" +
			user->query("name") + "的尸体上搜出一" + query("unit") +
			query("name") + "，转身几个起落就不见了。\n");
		}
		else {
			killer->force_me("say 哼，这次算你走运。\n");
			tell_room(environment(killer), killer->query("name") +
			"急急忙忙地离开了。\n");
		}
		destruct(killer);
	}
	destruct(this_object());
}


int check(object ob,string place)
{
	if(!objectp(ob)
	|| !environment(ob)
	|| environment(ob)->query("no_fight")
	|| environment(ob)->query("quest")
	|| strsrch(base_name(environment(ob)),place) != 0 ) return 0;
	return 1;
}
// 在初始区域内向npc打听淳于蓝的下落
private nomask int ask_hook(string arg)
{
	object user, npc , target;
	string str;
	object* living;
	int i,j;   	 
	
	if(!(npc = do_ask(arg)))
	return 0;   // 不符合条件
	
	user = this_user();
	message_vision("$N向$n打听有关『" + HIG +"淳于蓝" + NOR + "』的消息。\n", user, npc);
	npc->force_me("say 哦，上次确实有这么一个人来过。");
	living = livings();
	for (i=0;i < sizeof(living);i++){
		j = random(sizeof(living));
		if (j <= 1 || j == sizeof(living) -1) continue;
		if(check(living[j],query("target_place")) ){
			target = living[j];
			str = environment(target)->query("short");
			if( str == "武僧堂" 
			|| str == HIR"心禅堂"NOR
			|| str == "金刚伏魔圈" ) continue;
		}
	}
	
	if(!target)
	{
		npc->force_me("whisper "+user->query("id")+" 不过我没看清楚他去哪里了。");
		return 1;
	}
	
	set("real_place",base_name(environment(target)));
	
	// 这里用whisper，对玩家来说稍微安全些
	npc->force_me("whisper " + user->query("id") +
	" 不过他现在已经去" + str + "了。");   
	set("start", 1);  // 从此以后，开始有蒙面杀手/淳于蓝出现
	return 1;
}

// 判断是否能够向npc打听淳于蓝的下落，
// 如果可以则返回npc object，否则返回0
private nomask mixed do_ask(string arg)
{
	object user, room, obj;
	string askee, topic;
	
	user = this_user();
	room = environment(user);
	//room_f = base_name(room);
	
	//if(!present(query("pal"),room)) //Partner不在边上
	//return 0;	
	if(!can_cmds()) return 0;
	
	if(user->is_busy())
	return 0;   // team leader忙
	if(sscanf(arg, "%s about %s", askee, topic) != 2)
	return 0;   // ask命令不对
	if(topic != "淳于蓝")
	return 0;   // 问的不是淳于蓝
	
	obj = present(askee, room);
	if(!objectp(obj))
	return 0;   // 没这个人
	if(!living(obj))
	return 0;   // 不是活物
	if(!obj->query("can_speak"))
	return 0;   // 不会说话
	if(obj->query("mute"))
	return 0;   // 哑巴
	if(!userp(obj))
	return 0;   // 非玩家
	if(!living(obj))
	return 0;
	if(random(2) < 1)
	return 0;   // 1/2的概率不知道
	if(obj->query("id") != query("target_player"))
	return 0;
	
	return obj;
}

// 领七窍玲珑任务后，处理team leader的移动可能出现的
// 情况（蒙面杀手，淳于蓝）
// 注意，只有team leader主动移动才会可能出现这些情况，
// 因为follow别人而移动，则不会出现这种情况。
// 每次最多只出现一个蒙面杀手，被系统force而follow
// team leader，即使follow到nofight room也不放弃follow
// 所以玩家仍然有可能把蒙面杀手带出去杀死。杀死一个蒙面
// 杀手后，才会有下一个出现，杀死所有3-5个蒙面杀手后，
// 走到指定位置才会有淳于蓝出现，淳于蓝只存在2分钟，如
// 果没有及时give chunyu lan linglong, 任务实际上就失败了。
private nomask int go_hook(string arg)
{
	object user, *team;
	user = this_user();
	team = user->query_team();
	if(!GO_CMD->main(user, arg))
	return 0;   // 这个方向没有出路
	if(query("iamover")) return 1;//Cyl已经出现
	if(!query("start"))
	return 1;   // 还没开始出现蒙面杀手
	add("steps", 1);  // 增加移动的步数
	if(move_with_killer())
	return 1;   // 和蒙面杀手战斗中移动
	if(!present(query("pal"), environment(user))) return 1;
	if(encounter_killer())
	return 1;   // 遇到新的蒙面杀手
	if(encounter_cyl())
	return 1;   // 遇到淳于蓝
	return 1;
}
// 判断是否在和蒙面杀手战斗中移动
private nomask int move_with_killer()
{
	object killer;
	killer = this_object()->query("killer", 1);
	if(!killer)
	return 0;
	this_user()->start_busy(2);
	return 1;
}

// 遇到新蒙面杀手？
//private nomask 
int encounter_killer()
{
	object user, room, killer,pal;
	
	pal = query("pal", 1);	
	if(!pal) return 0;
	if(!can_cmds()) return 0;
	
	if(query("killers") == query("max_killers"))
	return 0;   // 没有更多的蒙面杀手	
	if(query("steps") < 10)
	return 0;   // 还没再走到10步 
	if(random(4) < 3)
	return 0;   // 3/4的概率没蒙面杀手	
	user = this_user();
	room = environment(user);
	if(room->query("no_fight"))
	return 0;   // 在非战斗房间	
	set("steps", 0);  // 重设步数	
	killer = new(__DIR__"killer");
	killer->set("target", this_object());
	set("killer", killer);
	tell_object(user,
	YEL"你觉得行囊中的顽石越来越沉，令你举步维艰……。\n"NOR);
	tell_room(room, RED"一个蒙面杀手从路边跳了出来。大声喝道："
	"「把王重阳的宝物留下，不然取你的性命。」\n"NOR);
	
	killer->setparty(1+random(10),pal->query("max_pot")-80,pal->query("combat_exp")*12/10 );
		
	killer->add_temp("apply/damage",- pal->query("max_pot") / 5 );
	killer->add_temp("apply/attack",-  pal->query("max_pot") / 5 );
			
	killer->do_kill(user);
	killer->move(room);
	killer->force_me("follow " + user->query("id"));      
	killer->kill_ob(user);
	
	killer->no_die_ppl(user,this_object());
	
	user->start_busy(2);   
	return 1;
}

// 遇到淳于蓝？
private nomask int encounter_cyl()
{
	object room, cyl;
	
	room = environment(this_user());
	
	if(!can_cmds()) return 0;
	
	if(query("killer")) return 0;
	
	if(query("killers") < query("max_killers"))
	return 0;   // 还有蒙面杀手出现	
	if(query("real_place") != base_name(room))
	return 0;	
	set("start", 0);  // 避免对一个玩家，重复出现多个淳于蓝
	set("iamover",1);
	cyl = new(__DIR__"cyl");
	set("cyl", cyl);
	tell_room(room, cyl->query("name") + "急急走了过来。\n");
	cyl->move(room);
	return 1;
}

void give_hook_completion(object user)
{
	object cyl, room;

	cyl = query("cyl", 1);
	room = environment(user);
	message_vision("$N微微一笑，叹道：「那马钰也是痴人，竟然不解王真人的真意。」\n",cyl);   
	cyl->force_me("say " HIY"顽石一方，妄言玲珑，何来七窍，"
	"人世纷扰。王真人是要指点弟子，\n"
	"贪恋人世七情，就是顽石；勘破道德无为，便证玲珑。"
	"你可将此言告知那牛鼻子吧。"NOR);
	message_vision("$n给$N一"+query("unit")+query("name") + "。\n",user,cyl);
	message_vision("$N一眨眼，又不知到哪里去了。\n",cyl);
	destruct(cyl);
}