// examined.c

#pragma optimize
#pragma save_binary

#include <localtime.h>

inherit F_DBASE;
inherit F_SAVE;

static int auto_examine = 0;

void create()
{
	seteuid(getuid());
	::restore();
	set("channel_id", "检查精灵");
	auto_examine = CONFIG_D->query_int("enable auto examine");
}

string query_save_file()
{
	return DATA_DIR "examined";
}

void remove()
{
	save();
}

void examine_player(object ob)
{
	int exp;
	object cash, gold, silver, coin;
	string log_msg;
	int tval;

	if (! auto_examine || wizardp(ob))
		return;

	cash = present("cash_money", ob);
	gold = present("gold_money", ob);
	silver = present("silver_money", ob);
	coin = present("coin_money", ob);
	exp = ob->query("combat_exp");

	tval = 0;
	if (cash) tval = cash->query_amount() * 10;
	if (gold) tval += gold->query_amount();
	if (tval < 100) return;
	if (silver) tval += silver->query_amount() / 100;
	if (coin) tval += coin->query_amount() / 10000;

	if (tval > 3000)
	{
		if (! ob->query_temp("reported/too_much_money"))
		{
			ob->set_temp("reported/too_much_money", 1);
			log_msg = sprintf("%s(%s) has (%d gold) at %s on %s",
					  ob->name(1), ob->query("id"), tval,
					  (environment(ob) ? base_name(environment(ob)) : "Unknow"),
					  ctime(time()));
			log_file("user/money_report", log_msg + "\n");
			CHANNEL_D->do_channel(this_object(), "sys", log_msg);
		}

		if (! ob->is_loging_now() && find_object(CONFIG_D) && CONFIG_D->query_int("enable auto log"))
			ob->start_log();
	}
}

string create_log_file(object ob)
{
	string fn;
	mixed lt;

	if (! userp(ob))
		return 0;

	lt = localtime(time());

	fn = "user/" + sprintf("%d-%d-%d/", lt[LT_YEAR],
			       lt[LT_MON] + 1, lt[LT_MDAY]) +
	     ob->query("id");
	assure_file(LOG_DIR + fn);

	return fn;
}

int start_log_player(string id, string me)
{
	mixed by;
	object ob;

	if (! is_root(previous_object()))
		return 0;

	by = query("log_by/" + id);
	if (stringp(by) && (wiz_level(by) > wiz_level(me)))
		return notify_fail("已经有权限比你高的人记录该玩家的日志了。\n");

	if (stringp(by) && by == me)
		return notify_fail("你已经开始记录这个玩家的日志了。\n");

	ob = find_player(id);
	if (! by && ob && ob->is_loging_now() && wizhood(me) != "(admin)")
		return notify_fail("EXAMINE DAEMON 正在记录这个玩家的日志，你无权干涉。\n");

	if (wizhood(id) == "(admin)" &&
	    (! this_player() || ! this_player()->query("env/admin")))
		return notify_fail("不能记录 admin 的日志。\n");

	set("log_by/" + id, me);

	log_file("static/log_user", sprintf("%s start log %s on %s\n",
					    me, id, ctime(time())));
	if (objectp(ob)) ob->start_log();
	save();

	return 1;
}

int end_log_player(string id, string euid)
{
	object ob;
	mixed by;

	if (! is_root(previous_object()))
		return 0;

	ob = find_player(id);
	by = query("log_by/" + id);

	if (! by && (! ob || ! ob->is_loging_now()))
		return notify_fail("系统现在并没有记录这个玩家的日志。\n");

	if (euid == ROOT_UID || wizhood(euid) == "(admin)" ||
	    stringp(by) && (by == euid || wiz_level(by) <= wiz_level(euid)))
	{		
		delete("log_by/" + id);
		log_file("static/log_user", sprintf("%s stop log %s on %s\n",
						    euid, id, ctime(time())));
		save();
		if (objectp(ob)) ob->end_log();
		return 1;
	}

	return notify_fail("你不是 ROOT 或是开始记录日志的巫师，不能中止记录。\n");
}

mixed query(string idx, int raw)
{
	if (previous_object() && ! is_root(previous_object()))
		return 0;

	return ::query(idx, raw);
}

mixed set(string idx, mixed data)
{
	if (previous_object() && ! is_root(previous_object()))
		return 0;

	return ::set(idx, data);
}









void testing_player(object me,string type)
{
	string question,key;
	string *colors = ({WHT,HIW,GRN,HIG,YEL,HIY,BLU,HIB,MAG,HIM,RED,HIR,CYN,HIC});//14
	string *sizes = ({ZJSIZE(20),ZJSIZE(21),ZJSIZE(22),ZJSIZE(23),ZJSIZE(24),ZJSIZE(25),ZJSIZE(26),ZJSIZE(27),ZJSIZE(28),ZJSIZE(29)});
	string sign;
	int a=1+random(10),b=1+random(10),c,ans;
	
	
	if(me->query("test_answer_error") > 5)
	{
		//me->move(D_BLOCKROOM);
		me->delete("test_answer_error");
		me->save();
		return;
	}

	switch( random(3) )
	{
		case 0:
			sign = random(2) == 0 ? "乘" : " * ";
			ans = a*b;
			break;
		case 1:
			if(a < b) {
				c = a;
				a = b;
				b = c;
			}
			sign = random(2) == 0 ? "减" : " - ";
			ans = a - b;
			break;	
		case 2:
			sign = random(2) == 0 ? "加" : " + ";
			ans = a + b;
			break;		
	}
	
	question = sprintf("%s%s%s"NOR" %s%s%s"NOR" %s%s%s"NOR" 等于多少？"ZJBR,
							colors[random(14)],
							sizes[random(10)],
							random(2) == 0 ? ""+a : chinese_number(a),
							
							colors[random(14)],
							sizes[random(5)],
							sign,
							
							colors[random(14)],
							sizes[random(10)],
							random(2) == 0 ? ""+b : chinese_number(b));
	
	tell_object(me,"\n"+INPUTTXT(question,"answer test "+type+" $txt#")+"\n" );
	me->set_temp("answer_key",ans);
	me->set_temp("answer",type);
	
}