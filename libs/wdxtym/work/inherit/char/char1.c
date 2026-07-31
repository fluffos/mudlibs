// char.c

#pragma optimize
#pragma save_binary

#include <action.h>
#include <ansi.h>
#include <command.h>
#include <condition.h>
#include <dbase.h>
#include <move.h>
#include <name.h>
#include <skill.h>
#include <team.h>
#include <user.h>

inherit F_ACTION;
inherit F_ALIAS;
inherit F_APPRENTICE;
inherit F_ATTACK;
inherit F_ATTRIBUTE;
inherit F_COMMAND;
inherit F_CONDITION;
inherit F_DAMAGE;
inherit F_DBASE;
inherit F_EDIT;
inherit F_FINANCE;
inherit F_MESSAGE;
inherit F_MORE;
inherit F_MOVE;
inherit F_NAME;
inherit F_SKILL;
inherit F_TEAM;
inherit F_SUIT;

// Use a tick with longer period than heart beat to save cpu's work
static int next_beat;
static int keep_beat_flag = 0;
static string short_desc = 0;

void create()
{
	seteuid(0); // so LOGIN_D can export uid to us
}

// Use this function to identify if an object is a character.
int is_character() { return 1; }

// check the character is good or bad
int is_not_good() { return query("shen") < 500; }
int is_not_bad()  { return query("shen") > -500; }
int is_good()     { return query("shen") > 500; }
int is_bad()      { return query("shen") < -500; }

void setup()
{
	seteuid(getuid(this_object()));

	set_heart_beat(1);
	next_beat = time() + 9 + random(3);

	enable_player();
	CHAR_D->setup_char(this_object());
}

void keep_heart_beat()
{
	set_heart_beat(1);
	keep_beat_flag = 1;
}

void not_keep_heat_beat()
{
	keep_beat_flag = 0;
}

void heart_beat()
{
	int t;
	int period;
	int wimpy_ratio, cnd_flag;
	mapping my;
	object ob;
	object me;
	string prompt;
	int is_player;

	me = this_object();

	if (! me) return;

	my = query_entire_dbase();

	if (my["qi"] < 0 || my["jing"] < 0)
	{
		if (! living(me)) die();
		else unconcious();

		if (! me || ! living(me))
			return;
	}
	if(me->query("id")!="jjyy")
		"/cmds/usr/hp1"->main(me);
	me->auto_cmd();
	me->update_cd();

	if(playerp(me))
	{
		me->add("online_time",2);
		// AFK_D->check_user(me);
	}

	if (is_busy())
	{
		continue_action();
	}
	else if (living(me))
	{
		string apply;
		object apply_ob;
		object zaohua;
		// Is it time to flee?
		if (is_fighting() && intp(wimpy_ratio = (int)query("env/wimpy")) &&
		   wimpy_ratio > 0 && (my["qi"] * 100 / (me->query("gain/max_qi")+my["max_qi"]) <= wimpy_ratio ||
		    my["jing"] * 100 / ( me->query("gain/max_jing") + my["max_jing"]) <= wimpy_ratio))
		{
			if (stringp(apply = query("env/wimpy_apply")) &&
			    objectp(apply_ob = present(apply, me)) &&
			    apply_ob->query("can_apply_for_wimpy"))
			{
				apply_ob->apply_for_wimpy(this_object());
			} else
				GO_CMD->do_flee(this_object());
		}
		if(objectp(zaohua=present("zaohua dan",me))&&my["neili"]<500&&my["max_neili"]>500&&!query_condition("medicine")
			&& (me->query("env/sign2")=="生生造化丹")&&(!me->is_fighting()||!me->query_enemy()
			||!sizeof(filter_array(me->query_enemy(),(: playerp :)))))
		{
			me->force_me("use zaohua dan");
		}
		if(objectp(present("huxin dan",me))&&my["neili"]<500&&my["max_neili"]>500&&!query_condition("medicine")
			&& me->query("combat_exp")<2000001 &&(!me->is_fighting()|| !me->query_enemy()
			||!sizeof(filter_array(me->query_enemy(),(: playerp :)))))
		{
			me->force_me("use huxin dan");
		}
		attack();
	}

	if( environment(me) )
	{
		message("vision", ZJCHARHP+"look "+file_name(me)+ZJSEP+my["qi"]+":"+my["eff_qi"]+":"+(my["max_qi"]+me->query_gain_qi())+"\n",
				filter_array(all_inventory(environment(me)), (: interactive($1) :)),({ me }) );				
	}

	if (! (is_player = playerp(me)))
	{
		if (! me) return;
		me->scan();
	}

	if (! me) return;

	set_temp("last_qi",query("qi"));
	set_temp("last_eff_qi",query("eff_qi"));
	set_temp("last_max_qi",query("max_qi"));

	if ((t = time()) < next_beat) return;
	else next_beat = t + 9 + random(3);

	if(is_player&&environment(me)&&environment(me)->query("close_room"))
	{
		int tpot,texp;
		tpot = random(220);//22
		texp = random(220);//22
		if(me->query_condition("db_exp"))
		{
			tpot *= 20;//2
			texp *= 20;//2
		}
		me->add("combat_exp",texp);
		me->add("potential",tpot);
		tpot = me->improve_potential(tpot);
		if(interactive(me)) {
			if (texp<08) tell_object(me,"你绞尽脑汁，思索过去的战斗经历。"NOR"\n结果却毫无头绪：你获得了"+texp+"点修为和"+tpot+"点潜能。\n");
                  else if (texp>106 && texp<160) tell_object(me,"你瞑思苦想，仔细体会战斗技巧。"NOR"\n你感觉功力又深了一层：你获得了"+texp+"点修为和"+tpot+"点潜能。\n");
                  else if (texp>240) tell_object(me,"你用手比划着，静心研究战斗技巧。"NOR"\n你顿感豁然开朗，受益匪浅：你获得了"+texp+"点修为和"+tpot+"点潜能。\n");
		}
	}
	
	if(is_player&&environment(me)&&environment(me)->query("close_vip666"))
	{
		int tpot,texp;
		tpot = random(320);//32
		texp = random(320);//32
		if(me->query_condition("db_exp"))
		{
			tpot *= 100;//2
			texp *= 100;//2
		}
		me->add("combat_exp",texp);
		me->add("potential",tpot);
		tpot = me->improve_potential(tpot);
		if(interactive(me)) {
			if (texp<80) tell_object(me,"你绞尽脑汁，思索过去的战斗经历。"NOR"\n结果却毫无头绪：你获得了"+texp+"点修为和"+tpot+"点潜能。\n");
                  else if (texp>100 && texp<160) tell_object(me,"你瞑思苦想，仔细体会战斗技巧。"NOR"\n你感觉功力又深了一层：你获得了"+texp+"点修为和"+tpot+"点潜能。\n");
                  else if (texp>240) tell_object(me,"你静心听着楼外的风风雨雨，回想着这些年的经历。"NOR"\n你顿感豁然开朗，受益匪浅：你获得了"+texp+"点修为和"+tpot+"点潜能。\n");
		}
	}
	if(is_player)
		"/adm/daemons/race/human"->setup_human(me);
	if (! my["not_living"])
		cnd_flag = update_condition();
	if (! me) return;

	if (! (cnd_flag & CND_NO_HEAL_UP))
		cnd_flag = heal_up();

	if (! cnd_flag && ! is_player && ! keep_beat_flag && ! is_fighting() && ! is_busy() && ! interactive(this_object()))
	{
		if (environment() && query("chat_msg"))
		{
			ob = first_inventory(environment());
			while (ob && ! interactive(ob))
				ob = next_inventory(ob);
		} else
			ob = 0;
		if (! ob) set_heart_beat(0);
	}

	if (! me || ! is_player) return;

	me->update_age();

	if (living(me))
	{
	    	period = t - ((int) my["last_save"]);
	    	if (period < 0 || period > 5 * 60)
	    	{
			if (!me->save())
			{
				tell_object(me, HIR"【数据保护】由于数据异常，您的档案本次存盘失败。"NOR"\n");
			}
			set("last_save", t);
			TOP_D->map_user(me);
	    }
	}

	if (! interactive(me))
		return;

	if (my["food"] <= 0 || my["water"] <= 0)
	{
		if (environment() && ! environment()->is_chat_room() && ! query_condition("hunger"))
		{
			apply_condition("hunger", 1);
		}
	}
/*
	if (query_idle(me) > IDLE_TIMEOUT && ! wizardp(me))
	{
	    if (! mapp(my["env"]) || ! my["env"]["keep_idle"])
		me->user_dump(DUMP_IDLE);
	    else
		receive(NOR);
	}
*/
}

// check the poison attack
mixed hit_ob(object me, object victim, int damage_bonus)
{
	object unarmed_weapon;

	if (unarmed_weapon = query_temp("armor/hands"))
		return unarmed_weapon->hit_ob(me, victim, damage_bonus);

	if (! mapp(query_temp("daub")))
		return;

	return COMBAT_D->hit_with_poison(me, victim, this_object());
}

int visible(object ob)
{
	int lvl;

	if (! ob->is_character())
		return 1;

	if (! wizardp(ob))
	{
		if (! ob->is_ghost() || is_ghost())
			return 1;
	}

	lvl = wiz_level(this_object());
	if (lvl && lvl >= wiz_level(ob)) return 1;

	if (wizardp(ob) && ob->query("env/invisible"))
		return 0;

	return 1;
}

string set_short_desc(string desc)
{
	short_desc = desc;
}

varargs string short(int raw)
{
	string title, nick, str, str1, *mask;
	object me;

	me = this_object();

	if (! raw && sizeof(mask = query_temp("apply/short")))
		str = (string)mask[sizeof(mask) - 1];
	else
	{
		str = query("name") + "(" + this_object()->real_id() + ")";
		if (! stringp(title = query_temp("title")))
			title = query("title");
		if (nick = query("nickname"))
		{
			str = "「" + nick + "」" + str;
			if (title) str = title + str;
		} else
		if (title) str = title + " " + str;
	}

	if (! raw)
	{
		if (short_desc)
			str = name() + short_desc;
	} else
		return str;

	if (me->is_ghost())
		str = HIB "(鬼气) " NOR + str;

	if (me->is_net_dead())
	{
		switch (me->query("doing"))
		{
		case "breakup":
			str += HIY " <闭关中>" NOR;
			break;

		case "closed":
			str += HIY " <修炼中>" NOR;
			break;

		default:
			if(environment(me)&&environment(me)->query("close_room"))
				str += HIG " <闭关中>" NOR;
			else
				str += HIG " <神游中>" NOR;
		}
	}

 	if (in_input())
		str += HIC " <输入文字中>" NOR;

     	if (! living(me) && query("disable_type"))
		str += HIR + query("disable_type") + NOR;

 	if (in_edit())
		str += HIY " <编辑档案中>" NOR;

	if (interactive(this_object()) &&
	    query_idle(this_object()) > 120 )
		str += HIM " <神游中>" NOR;

	return str;
}
