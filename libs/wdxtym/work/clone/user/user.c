// user.c

#include <origin.h>
#include <user.h>
#include <ansi.h>
#include <command.h>

inherit CHARACTER;
inherit F_AUTOLOAD;
inherit F_SAVE;

// 死亡保护
private int die_protect(object ob);
private void cancle_die_protect(object ob);

// 分站使用
static int admin_flag = 0;	      // 是否是特殊的管理员？

// 数据是否完整？
static int user_cracked = 0;	    // RESTORE 时检查数据并设置该标志

static int net_dead;		    // 标志：是否断开了连接
static int last_age_set = 0;	    // 上一次更新AGE的时间
static int user_say = 0;		// 一定时间以内玩家做的say-action
static int user_command = 0;	    // 一定时间以内玩家发送的命令
static int attach_flag = 0;	     // 是否正在和系统联络
int	at_time = 0;		 // 在什么时间计算的
int	ban_to = 0;		  // 在什么时间解禁玩家
string     ban_say_msg = "";	    // 禁止说话的消息

static string my_defeater_id;	   // 上一次打晕你的人ID
static string my_killer_id;	     // 上一次杀你的人的ID
static int    craze = 0;		// 愤怒

#define DEFAULT_PRISON	  "/d/register/prison"

// globals variables
string  prison = 0;
int     time_to_leave = 0;

int	is_stay_in_room()	{ return 1; }
int     is_player()		{ return clonep(); }
string  query_prison()	  { return prison; }
int     query_time_to_leave()   { return time_to_leave; }
int     is_in_prison()	  { return stringp(prison); }
int     is_net_dead()	   { return net_dead || ! interactive(this_object()); }

varargs string calc_sec_id(int raw);

#define MAX_COMMAND_ONE_SECTION	 30
#define MAX_SAY_ONE_SECTION	     4
#define BAN_SAY_PERIOD		  60

int query_current_neili_limit();
int query_neili_limit();
int query_current_jingli_limit();
int query_jingli_limit();
int query_potential_limit();
int query_experience_limit();

int is_user() { return 1; }

// 判断是否具有管理权限：如果是版本发布站点或是通过 PASSWD
// 命令设置过，则具有管理权限。具有该权限的巫师可是使用诸如
// clone、call、log、smash、copyskill等命令。
int is_admin()  { return admin_flag == 1222; }
int set_admin() { if (previous_object() == find_object("/cmds/usr/passwd")) admin_flag = 1222; }

void create()
{
	::create();
	set_name("使用者物件", ({ "user object", "user", "object" }) );
}

void terminal_type(string term_type)
{
	set_temp("terminal_type", term_type);
	message("system", "终端机型态设定为 " + term_type + "。\n", this_object());
}

void reset()
{
	int lv;

	if ((int)query("potential") - (int)query("learned_points") < 100)
		add("potential", 1);

	if ((int)query("thief") > 0)
		add("thief", -1);

	if ((int)query("total_hatred") > 0)
		add("total_hatred", -1);

	if ((lv = query_skill("xiantian-gong", 1)) >= 60 ||
	    (lv = query_skill("quanzhen-xinfa", 1)) >= 60)
	{
		if (can_improve_skill("force"))
			improve_skill("force", lv * 20);

		if (query_skill("quanzhen-xinfa", 1) >= 60 &&
		    can_improve_skill("quanzhen-xinfa"))
			improve_skill("quanzhen-xinfa", lv * 10);

		if (query_skill("xiantian-gong", 1) >= 60 &&
		    can_improve_skill("xiantian-gong") &&
		    SKILL_D("xiantian-gong")->valid_learn(this_object()))
			improve_skill("xiantian-gong", lv * 10);
	}
}

// This is used by F_SAVE to determine the filename to save our data.
string query_save_file()
{
	string id;

	id = geteuid();
	if (! id) id = getuid();
	if (! stringp(id)) return 0;
	return sprintf(DATA_DIR "user/%c/%s", id[0], id);
}

// override set function
mixed set(string idx, mixed para)
{
	if (idx == "name" && clonep(this_object()) &&
	    geteuid(this_object()))
	{
		NAME_D->change_name(this_object(), para, 1);
		return para;
	} else
		return ::set(idx, para);
}

int save()
{
	int res;

	if (user_cracked)
		// 数据不完整，不能保存
		return 1;

	if (query_temp("user_setup"))
	{
		save_autoload();
		set("sec_id", calc_sec_id());   // save sec_id
		res = ::save();
		clean_up_autoload();		// To save memory
	} else
	{
		set("sec_id", calc_sec_id());   // save sec_id
		res = ::save();
	}

#if INSTALL_EXAMINE
	EXAMINE_D->examine_player(me);
#endif
	return res;
}

int restore()
{
	int res;
	string sec_id;

	res = ::restore();
	if (res)
	{
/*
		if (stringp(sec_id = query("sec_id")))
		{
			if (crypt(calc_sec_id(1), sec_id) != sec_id)
			{
				// 数据不完整
				log_file("static/user",
					 sprintf("%s %s's data my be corrupt.\n",
						 log_time(), getuid()));
				user_cracked = 1;
				return 0;
			}
		} else
		{
			log_file("static/user",
				 sprintf("%s %s lost assure key.\n",
					 log_time(), getuid()));
			user_cracked = 1;
			return 0;
		}
*/
		// 数据完整
		user_cracked = 0;

		set("id", getuid(this_object()));
	}

	return res;
}

// This function updates player's age, called by heart_beat()
void update_age()
{
	int lastset;
	int age,month;
	int all,*lvs,delta,i;

	lvs = ({ 100, 400, 900, 1600, 2500, 3800, 5500, 8000, 12000, 30000, 999999999, });
	if( !(lastset=query("zjvip/last_vip_set"))) lastset=time();
	if(query("zjvip/times")>0)
	{
		all = query("zjvip/all_pay")+query("zjvip/sign_exp");
		for(i=0;i<sizeof(lvs);i++)
		{
			if(all < lvs[i])
			{
				set("zjvip/level",1+i);
				break;
			}
		}
		
		
		if(query("zjvip/level")>10) 
		set("zjvip/level",10);
		add("zjvip/times", lastset - time());

		if(query("zjvip/times")<=0)
		{
			set("zjvip/times", 0);
			tell_object(this_object(),RED"你的VIP会员时间已到期！"NOR"\n");
		}
		
		
	}
	else
	{
		set("zjvip/level",0);
		set("zjvip/times", 0);
		
	}
	
	if(query("qnvip/times")>0)
	{
		all = query("qnvip/all_pay")+query("qnvip/sign_exp");
		for(i=0;i<sizeof(lvs);i++)
		{
			if(all < lvs[i])
			{
				set("qnvip/level",1+i);
				break;
			}
		}
		
		
		if(query("qnvip/level")>10) 
		set("qnvip/level",10);
		add("qnvip/times", lastset - time());

		if(query("qnvip/times")<=0)
		{
			set("qnvip/times", 0);
			tell_object(this_object(),RED"你的三倍潜能时间已到期！"NOR"\n");
		}
		
		
	}
	else
	{
		set("qnvip/level",0);
		set("qnvip/times", 0);
		
	}
	
	if(query("ybvip/times")>0)
	{
		all = query("ybvip/all_pay")+query("ybvip/sign_exp");
		for(i=0;i<sizeof(lvs);i++)
		{
			if(all < lvs[i])
			{
				set("ybvip/level",1+i);
				break;
			}
		}
		
		
		if(query("ybvip/level")>10) 
		set("ybvip/level",10);
		add("ybvip/times", lastset - time());

		if(query("ybvip/times")<=0)
		{
			set("ybvip/times", 0);
			tell_object(this_object(),RED"你的三倍潜能时间已到期！"NOR"\n");
		}
		
		
	}
	else
	{
		set("ybvip/level",0);
		set("ybvip/times", 0);
		
	}
	
	
	
	
	
	if(query("tingyvge")>0)
	{
		
		
		
		add("tingyvge", lastset - time());

		if(query("tingyvge")<=0)
		{
			set("tingyvge", 0);
			tell_object(this_object(),RED"你的听雨阁会员时间已到期！"NOR"\n");
		}
		
		
	}
	else
	{
	
		set("tingyvge", 0);
	}
	
	
	
	if(query("lenque")>0)
	{
		
		
		
		add("lenque", lastset - time());

		if(query("lenque")<=0)
		{
			set("lenque", 0);
		//	tell_object(this_object(),RED"你的听雨阁会员时间已到期！"NOR"\n");
		}
		
		
	}
	else
	{
	
		set("lenque", 0);
	}
	
	
	
	
	
	if(query("yanzhen")>0)
	{
		
		
		
		add("yanzhen", lastset - time());

		if(query("yanzhen")<=0)
		{
			set("yanzhen", 0);
		//	tell_object(this_object(),RED"你的听雨阁会员时间已到期！"NOR"\n");
		}
		
		
	}
	else
	{
	
		set("yanzhen", 0);
	}
	
	
	
	set("zjvip/last_vip_set",time());

	if (! last_age_set)
	{
		last_age_set = time();
		add("mud_age", 0);
	}

	if ((delta = (time() - last_age_set)) > 100)
		// time too long
		delta = 100;

	if (! environment() || ! environment()->is_chat_room() || ! query("env/halt_age"))		
	{
		// Update age
		add("mud_age", delta);
		if (time_to_leave)
			time_to_leave -= delta;
	}

	last_age_set = time();
	age = query("age_modify") + query("mud_age") / 259200;
	age += 14;
	month = (query("mud_age")%259200)/21600;
	set("month",month);
        if (query("age") != age) {
		set("age", age);
		set("kar", 10+random(21));
		tell_object(this_object(), "时间过得真快，不知不觉你已经" + chinese_number(age) + "岁了，今年的运气不知道怎么样。\n");
	}
}

void setup()
{
	// We want set age first before new player got initialized with
	// random age.
	last_age_set = 0;
	update_age();

	::setup();

	// set the enable flag to enable save
	set_temp("user_setup", 1);

	restore_autoload();

	if (query("doing"))
		CLOSE_D->continue_doing(this_object());
}

void user_dump(int type)
{
	if(this_object()->query("pending/afk")&&this_object()->query("zjvip/times")) return;
	if(this_object()->query("afk")&&this_object()->query("zjvip/times")) return;
	if (environment()&&environment()->query("close_room")) return;
	switch(type)
	{
	case DUMP_NET_DEAD:
		if (environment())
		{
			tell_room(environment(), query("name") + "断线超过 " + NET_DEAD_TIMEOUT / 86400000000 + " 分钟，自动退出这个世界。\n");
		}
		catch(command("halt"));
		catch(command("quit"));
		if (this_object())
		{
			QUIT_CMD->force_quit(this_object());
		}
		break;

	case DUMP_IDLE:
		if (query_temp("learned_idle_force"))
		{
			message_vision("$N狂笑三声，道：我终于明白了！\n",this_object());
			tell_object(this_object(), "你经过长时间的发呆，终于对发呆神功的理解又深了一层！\n");
			improve_skill("idle-force", 3600000000);
			delete_temp("learned_idle_force");
		} else
			tell_object(this_object(), "对不起，您已经发呆超过 " + IDLE_TIMEOUT / 864000000 + " 分钟了，请下次再来。\n");
		if (environment())
		{
			tell_room(environment(), "一阵风吹来，将发呆中的" + query("name") + "化为一堆飞灰，消失了。\n", ({this_object()}));
		}
		command("quit");
		if (this_object() && ! query("doing"))
		{
			QUIT_CMD->force_quit(this_object());
		}
		break;
	default:
		return;
	}
}

// net_dead: called by the gamedriver when an interactive player loses
// hir network connection to the mud.
private void net_dead()
{
	object link_ob;

	this_object()->remove_interactive();

	if (!query("doing")&&!(environment(this_object())&&environment(this_object())->query("close_room")||query("afk")))
		set_heart_beat(0);

	if (objectp(link_ob = query_temp("link_ob")))
	{
		if (link_ob->query_temp("ip_number"))
		{
			link_ob->set("last_on", time());
			link_ob->set("last_from",link_ob->query_temp("ip_number"));
			link_ob->save();
		}
		destruct(link_ob);
	}

	net_dead = 1;
	if (userp(this_object()) && ! query("doing")&&!(environment(this_object())&&environment(this_object())->query("close_room")))
	{
		call_out("user_dump", NET_DEAD_TIMEOUT, DUMP_NET_DEAD);
		tell_room(environment(), query("name") + "断线了。\n", this_object());
		CHANNEL_D->do_channel(this_object(), "sys", "断线了。");
		remove_all_enemy(1);
	} else
	{
		if (environment())
			message("vision", name() + "离线了。\n",
				environment(), ({ this_object() }));
	}
}

// reconnect: called by the LOGIN_D when a netdead player reconnects.
void reconnect()
{
	set_heart_beat(1);
	net_dead = 0;
	remove_call_out("user_dump");
	tell_object(this_object(), "重新连接成功。\n");
}

// skill variable & function
#define MAX_NEILI_IMPROVE       query("con")
#define MAX_JINGLI_IMPROVE      query("con")

int query_neili_limit()
{
	string *skill_names;
	mapping skills;
	int neili_limit;
	int base_lvl, lvl;
	int tmp;
	int i;
	string fam;

	skills = this_object()->query_skills();
	if (! mapp(skills))
		return 0;

	skill_names = keys(skills);

	base_lvl = ((int) skills["force"]) / 2; 
	neili_limit = base_lvl * 10;
	for (i = 0; i < sizeof(skill_names); i++)
	{
		if (file_size(SKILL_D(skill_names[i]) + ".c") == -1)
			continue;

		if (! SKILL_D(skill_names[i])->valid_enable("force"))
			continue;

		lvl = (int) skills[skill_names[i]];
		tmp = (base_lvl + lvl) * 10;
		tmp += (int) SKILL_D(skill_names[i])->query_neili_improve(this_object());
		if (tmp > neili_limit) neili_limit = tmp;
	}

	neili_limit += neili_limit * query("improve/neili") / 100;
	if (query("breakup"))
		neili_limit += neili_limit * 3 / 10;

	if (query("special_skill/mystery"))
		neili_limit += query("con") * 15;
		
	if (query("titlea/max_neili"))	
		neili_limit += query("titlea/max_neili");
			
	fam = query("family/family_name");
	if (query("class") == "bonze" &&
	    (fam == "雪山寺" || fam == "少林派" || fam == "峨嵋派" || fam == "血刀门"))
		neili_limit += 500;	

	return neili_limit;
}

int query_gain_jing()
{
	int gain_qi;
	gain_qi = query("gain/max_jing") + query("titlea/max_qi");

	return gain_qi;
}

int query_gain_qi()
{
	int gain_qi,x;
	string xinfa;

	gain_qi = query("gain/max_qi");
	if(query("family/family_name")=="武当派"||query("family/family_name")=="全真教")
		gain_qi += gain_qi/10;

	if(xinfa = query_skill_mapped("xinfa"))
	{
		if ((x = query_skill(xinfa,1)) > 180)
		{
			gain_qi += gain_qi*((x-180)/5) / 100;
		}
	}

	if (query("special_skill/ghost"))
		gain_qi = gain_qi*7/10;

	return gain_qi;
}

int query_gain_damage()
{
	int gain_damage;
	gain_damage= query("gain/damage");
	return gain_damage;
}

int query_gain_break()
{
	int gain_break;
	gain_break= query("gain/break");
	return gain_break;
}

int query_gain_armor()
{
	int gain_armor;
	gain_armor= query("gain/armor");
	return gain_armor;
}

int query_current_neili_limit()
{
	int neili;
	string force;
	string fam;

	force = query_skill_mapped("force");
	neili = (int)query_skill("force", 1) / 2 * 10;
	if (stringp(force) && force != "")
	{
		neili += (int)query_skill(force, 1) * 10;
		neili += SKILL_D(force)->query_neili_improve(this_object());
	}    

	neili += neili * query("improve/neili") / 100;
	if (query("breakup"))
		neili += neili * 3 / 10;

	if (query("special_skill/mystery"))
		neili += query("con") * 15;

	fam = query("family/family_name");
	if (query("class") == "bonze" &&  (fam == "雪山寺" || fam == "少林派" || fam == "峨嵋派" || fam == "血刀门"))
		neili += 500;

	return neili;
}

int query_jingli_limit()
{
	int limit;

	limit = ((int)query("magic_points") / 30) + query("int") * 20 +100;
	limit += limit * query("improve/jingli") / 100;
	if (query("animaout"))
		limit += limit * 3 / 10;
	return limit;
}

int query_current_jingli_limit()
{
	return query_jingli_limit();
}
//悟性提高可以增加潜能极限
int query_potential_limit()
{
	int p;

	if (ultrap(this_object()))//宗师
		p = 20000+query_int() * 300 *3;
	else
		p = query_int() * 300 *3;
	if(environment(this_object())&&environment(this_object())->query("close_room"))
		p *=2;
		
	if(environment(this_object())&&environment(this_object())->query("chaocai"))
		p +=300000;		
		
	if(environment(this_object())&&environment(this_object())->query("lx_chaocai"))
		p +=200000;		
				
	return (int)query("learned_points") + p;
}
//实战体会极限-阅历提高可以增加实战体会极限
int query_experience_limit()
{
	int p;

	if (ultrap(this_object()))
		p = 10000;
	else
	{
		p = query("score");
		if (p < 100)
			p = p / 2;
		else
		if (p < 300)
			p = p / 4 + 25;
		else
		if (p < 1100)
			p = (p - 300) / 8 + 100;
		else
			p = (p - 1100) / 16 + 200;
		if (p > 8000)
			p = 8000;
	}
	return (int)query("learned_experience") + p;
}

int improve_potential(int n)
{
	int max;

	max = query_potential_limit() - query("potential");
	if (max <= 0)
	{
		tell_object(this_object(),"潜能已达上限，暂时无法继续提升！\n");
		return 0;
	}
	if (n > max) n = max;
	add("potential", n);
	return n;
}

int improve_experience(int n)
{
	int max;

	max = query_potential_limit() - query("experience");
	if (max <= 0) return 0;
	if (n > max) n = max;
	add("experience", n);
	return n;
}

int can_improve_neili()
{
	return query("improve/neili") < MAX_NEILI_IMPROVE;
}

int can_improve_jingli()
{
	return query("improve/jingli") < MAX_NEILI_IMPROVE;
}

int improve_neili(int n)
{
	int delta;

	if ((delta = query_neili_limit() - query("max_neili")) <= 0)
		return 0;

	if (n > delta) n = delta;
	add("max_neili", n);
	 setup();
	return n;
}

int improve_jingli(int n)
{
	int delta;

	if ((delta = query_jingli_limit() - query("max_jingli")) <= 0)
		return 0;

	if (n > delta) n = delta;
	add("max_jingli", n);
	 setup();
	return n;
}

int accept_fight(object ob)
{
	if (query_temp("pending/fight") == ob)
		return 1;

	tell_object(this_object(), YEL "如果你愿意和对方进行比试，请你也对" +
		    ob->name() + "("+ (string)ob->query("id")+")"+
		    "下一次 fight 指令。"NOR"\n");

	tell_object(ob, YEL "由于对方是由玩家控制的人物，你必须等对方同意才" +
	      "能进行比试。"NOR"\n");

	return 0;
}

int accept_hit(object ob)
{
	if (! die_protect(ob))
		return 0;

	message_vision("$N大喝道：" + ob->name() + "，你要干什么？\n",this_object(), ob);
	return 1;
}

int accept_kill(object ob)
{
	if (is_killing(ob->query("id")))
		return 1;

	if (! die_protect(ob))
		return -1;

	tell_object(this_object(), HIR "如果你要和" + ob->name() +
		"性命相搏，请你也对这个人(" + (string)ob->query("id") +
		")下一次 kill 指令。"NOR"\n");
	return 1;
}

int accept_ansuan(object who)
{
	if (! die_protect(who))
		return 0;

	command(random(2) ? "say 嗯！怎么..." : "say 啊！不好！");
	return 1;
}

int accept_touxi(object who)
{
	if (! die_protect(who))
		return -1;

	switch (random(2))
	{
	case 0:
		message_vision("$N大吃一惊，叫道：“好你个" +
			       RANK_D->query_rude(who) + "！真不要脸！”\n",
			       this_object(), who);
		break;

	default:
		message_vision("$N仓皇之间，不及说话，只得接下$n"
			       "这一招。\n", this_object(), who);
		break;
	}

	return 1;
}

int die_protect(object ob)
{
	object me = this_object();

	// 只有玩家之间才有死亡保护
	if (! userp(me) || ! userp(ob))
		return 1;

	// 在屠人场里不考虑死亡保护
	if (me->query_temp("in_pkd"))
		return 1;

	// 去除攻击者的死亡保护信息
	if (userp(me))
		cancle_die_protect(ob);

	// 被攻击者处于保护时期，本攻击失败
	if (me->query("die_protect/last_dead") + me->query("die_protect/duration") > time()+7200)
	{
		message_vision("$N处于被保护时期，$n不能进行攻击。\n",me, ob);
		return 0;
	}

	return 1;
}

void cancle_die_protect(object ob)
{
	ob->delete("die_protect");
}

int auto_cmd()
{
	string *sss,str;
	object me;
	int i,max;
	me = this_object();

	if(!me->query("env/sign1")||!stringp(str = me->query("env/sign5"))) return 1;
	sss = explode(str,";");
	max = sizeof(sss);
	if(max>5) max = 5;
	for(i=0;i<max;i++)
	{
		me->force_me(sss[i]);
	}
	return 1;
}

int reject_command()
{
	int t;

	if (wizardp(this_object()))
		return 0;

	t = time() & 0xFFFFFFFE;
	if (at_time != t)
	{
		at_time = t;
		user_command = 1;
		user_say = 0;
	} else
		user_command++;

	if (user_command > MAX_COMMAND_ONE_SECTION)
	{
		user_command = 0;
		if (! query("born"))
			// not born yet
			return 0;
		return 1;
	}

	return 0;
}

void ban_say_until(int ban_period, string msg)
{
	int t;

	t = time();
	if (ban_to > t)
		ban_to += ban_period;
	else
		ban_to = t + ban_period;
	ban_say_msg = msg;
}

int ban_say(int raw)
{
	int t;

	if (wizardp(this_object()))
		return 0;

	if (is_in_prison())
	{
		notify_fail("你省省吧，好好做你的牢，少折腾。\n");
		return 1;
	}

	t = time() & 0xFFFFFFFE;
	if (ban_to > t)
	{
		notify_fail(ban_say_msg + "，请于" +
			    appromix_time(ban_to - t) + "以后再尝试。\n");
		return 1;
	}

	if (! raw)
		return 0;

	if (at_time != t)
	{
		at_time = t;
		user_say = 1;
		user_command  = 0;
	} else
		user_say++;

	if (user_say > MAX_SAY_ONE_SECTION)
	{
		ban_say_until(BAN_SAY_PERIOD, "系统禁止你送出信息");
		notify_fail(HIR "由于你发布的信息太多，因此系统暂时"
			    "禁止你发出信息。"NOR"\n");
		return 1;
	}

	return 0;
}

void permit_say(int n)
{
	if (ban_to <= time())
		return;

	if (! n)
		ban_to = 0;
	else
		ban_to -= n;

	if (ban_to <= time())
		tell_object(this_object(), "你可以继续发布信息了！\n");
}

// thow the person into prison
void get_into_prison(object ob, string p, int time)
{
	object me;

	me = this_object();
	if (! p) p = prison;
	if (! p) p = DEFAULT_PRISON;

	if (prison && base_name(environment()) == p)
	{
		time_to_leave += time * 60;
		if (ob && time)
			CHANNEL_D->do_channel(find_object(MASTER_OB), "rumor",
				"听说" + query("name") + "的刑期被" +
				ob->query("name") + "加长了" +
				appromix_time(time * 60) + "。");
		return;
	}

	if (prison && prison == p && base_name(environment()) != prison)
	{
		p->catch_back(me);
		me->set("startroom", prison);
		me->move(prison);
		message_vision("“啪”的一声，$N狠狠的摔倒了地上。\n", me);
		if (living(me))
			me->enable_player();

		CHANNEL_D->do_channel(find_object(MASTER_OB), "rumor",
			"听说" + query("name") + "越狱潜逃，结果被抓"
			"回去了。");

		save();
		return;
	}

	p->catch_ob(me);

	if (ob)
	{
		CHANNEL_D->do_channel(find_object(MASTER_OB), "rumor",
			"听说" + query("name") + "被" + ob->query("name") +
			"送进了" + p->short() + HIM "，禁闭" +
			appromix_time(time * 60) + "。");
	}

	me->set("startroom", prison);
	me->move(p);
	prison = p;
	time_to_leave += time * 60;
	save();

	message_vision("“啪”的一声，$N重重的摔倒了地上。\n", me);
	me->set("jing", 1);
	me->set("eff_jing", 1);
	me->set("qi", 1);
	me->set("eff_qi", 1);
	me->set("jingli", 0);
	me->set("neili", 0);
	me->receive_damage("jing", 0);
	if (living(me))
		me->enable_player();
}

// out of prison
void leave_prison(object ob, int time)
{
	object me;

	me = this_object();
	if (time)
	{
		time_to_leave -= time * 60;
		if (time_to_leave > 0)
		{
			if(ob)
				CHANNEL_D->do_channel(find_object(MASTER_OB), "rumor","听说" + query("name") + "的刑期被" +
					ob->query("name") + "缩短了" + appromix_time(time * 60) + "。");
			else
				CHANNEL_D->do_channel(find_object(MASTER_OB), "rumor","听说" + query("name") + "的刑期被缩短了" + appromix_time(time * 60) + "。");
			return;
		}
	}

	time_to_leave = 0;

	if (! prison->free_ob(me))
		return;

	prison = 0;

	if (living(me))
		me->enable_player();
	else
		me->revive();
	save();

	if (ob)
		CHANNEL_D->do_channel(find_object(MASTER_OB), "rumor",
			"听说" + query("name") + "被" + ob->name() +
			"提前释放了。");
	else
		CHANNEL_D->do_channel(find_object(MASTER_OB), "rumor",
			"听说" + query("name") + "已经刑满释放了。");
}

varargs void die(object killer)
{
	if (prison)
	{
		set_temp("die_reason", "惨死在监狱中");
		clear_condition(0);
		receive_damage("qi", 0);
		if (living(this_object()))
			enable_player();
	}
	
	::die(killer);
	save();
}

void update_in_prison()
{
	object me;

	me = this_object();
	me->set("qi", 0);
	me->set("jing", 0);
	me->set("neili", 0);

	if (! living(me))
		return;

	if (time_to_leave > 0)
	{
		if (environment() && base_name(environment()) != prison)
		{
			// escape from prison?
			get_into_prison(0, 0, 0);
		}
		return;
	}

	leave_prison(0, 0);
}

int is_attach_system()
{
	return attach_flag;
}

// start attaching
int attach_system()
{
	attach_flag = 1;
}

// stop, deatched
int detach_system()
{
	attach_flag = 0;
}

string command_verb()
{
	return query_verb();
}

#define CRAZE_LIMIT_1   7000    // for 光明磊落
#define CRAZE_LIMIT_2   5000    // for 心狠手辣

// 愤怒气息
int query_craze() { return craze; }

// 最大的愤怒气息
int query_max_craze()
{
	switch (query("character"))
	{
	case "光明磊落" :
		return CRAZE_LIMIT_1;

	case "心狠手辣" :
		return CRAZE_LIMIT_2;
	default:
		return 0;
	}
}

// 现在是否处于最愤怒的状态
int is_most_craze()
{
	return (craze > 0) && (craze >= query_max_craze());
}

// 因为被打倒而震怒
void craze_of_defeated(string defeater_id)
{
	my_defeater_id = defeater_id;
}

// 因为被击毙而震怒
void craze_of_die(string killer_id)
{
	my_killer_id = killer_id;
	craze = query_max_craze();
}

// 愤怒的攻击对手后调用这个函数清除对象
void craze_defeated(string enemy_id)
{
	if (enemy_id == my_defeater_id)
		my_defeater_id = 0;

	if (enemy_id == my_killer_id)
		my_killer_id = 0;
}

// 是否憎恨某人
int is_hating(string enemy_id)
{
	if (enemy_id == my_defeater_id ||
	    enemy_id == my_killer_id)
		return 1;

	return 0;
}

// 提升愤怒，返回提升的有效值
int improve_craze(int amount)
{
	int limit;

	if (amount < 0)
		error("error: improve_craze amount to be less than 0\n");

	limit = query_max_craze();
	craze += amount;
	if (craze > limit)
	{
		amount += limit - craze;
		craze = limit;
	}
	return amount;
}

// 消耗愤怒，返回消耗的有效值
int cost_craze(int n)
{
	if (n < 0)
		error("error: improve_craze amount to be less than 0\n");

	if (n > craze)
	{
		n = craze;
		craze = 0;
	} else
		craze -= n;
	return n;
}

// 编辑文件
void edit_file(string file)
{
	ed(file);
}

int is_vip()
{
	return query("zjvip/times")>0 && query("qnvip/times")>0 && query("ybvip/times")>0;
}

// 是否是结拜兄弟？
int is_brother(mixed ob)
{
	string id;

	if (stringp(ob))
		id = ob;
	else
	if (objectp(ob))
		id = ob->query("id");
	else
		return 0;

	// 是否是普通结拜兄弟
	if (query("brothers/" + id))
		return 1;

	// 是否是结盟的兄弟
	return 0;
}

// 计算完整性数据和
string calc_sec_id(int raw)
{
	mapping my;
	string *list;
	string key;
	int sum;
	string str;
	int i;

	sum = 0;

	// 累计所有的数据
	if (mapp(my = query_entire_dbase()))
	{
		foreach (key in keys(my) - ({ "sec_id" }))
		{
			sum += sizeof(key);
			if (intp(my[key]))
				sum += my[key];
			else
				sum += sizeof(my[key]);
		}
	}
	
	// 累计所有的武功技能
	
	if (mapp(my = query_skills()))
	{
		foreach (key in keys(my))
		{
			sum += sizeof(key);
			if (intp(my[key]))
				sum += my[key];
			else
				sum += sizeof(my[key]);
		}
	}
	// 累计所有携带的物品
	if (arrayp(list = query_autoload_info()))
	{
		foreach (key in list)
		{
			sum += sizeof(key);
			if (stringp(key))
				for (i = 0; i < strlen(key); i++) sum += key[i];
		}
	}

	// 转化成字符串
	str = sprintf("%d", sum);
	str[0] = (sum % 26) + 'a';

	if (! raw) str = crypt(str, 0);
	return str;
}

string query_info()
{
	string msg;
	int dexp, dpot, dmar, dage, dquest, dt;

	if (wiz_level(this_object()) > 0)
		return 0;

	msg = "";
	if (query("chblk_on"))
	{
		if (stringp(query("chblk_by")))
			msg += "频道已经被 " + query("chblk_by") + " 关闭。\n";
		else
			msg += "频道被关闭中。\n";
	}

	dexp = query("combat_exp") - query("last_examine/combat_exp");
	dpot = query("potential") - query("last_examine/potential");
	dmar = query("experience") - query("last_examine/experience");
	dage = query("mud_age") - query("last_examine/mud_age");
	dquest = query("all_quest") - query("last_examine/all_quest");
	dt = time() - query("last_examine/time");
	if (dquest < 0) dquest += 1000;

	if (dt > 60)
	{
		msg += sprintf("自上次检查 %s 以来：\n"
			       "连线时间增加了 %s。\n"
			       "师门任务完成了 %d 个。\n"
			       "平均每分钟获得修为速度：%d\n"
			       "平均每分钟获得潜能速度：%d\n"
			       "平均每分钟获得体会速度：%d\n",
			       appromix_time(dt),
			       appromix_time(dage),
			       dquest,
			       dexp * 60 / dt, dpot * 60 / dt, dmar * 60 /dt);
	}

	return msg;
}

