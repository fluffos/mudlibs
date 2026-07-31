// go.c

#include <config.h>

inherit F_CLEAN_UP;

mapping default_dirs = ([
	"north":	"北方",
	"south":	"南方",
	"east":	 "东方",
	"west":	 "西方",
	"northup":      "北边",
	"southup":      "南边",
	"eastup":       "东边",
	"westup":       "西边",
	"northdown":    "北边",
	"southdown":    "南边",
	"eastdown":     "东边",
	"westdown":     "西边",
	"northeast":    "东北",
	"northwest":    "西北",
	"southeast":    "东南",
	"southwest":    "西南",
	"up":	   "上面",
	"down":	 "下面",
	"enter":	"里面",
	"out":	  "外面",
]);

static  mapping empty_mapping = ([ ]);

void create() { seteuid(getuid()); }
string to_dir_cn(string dir) 
{ 
    if (undefinedp(default_dirs[dir])) 
    return dir; 
    return default_dirs[dir]; 
} 
int main(object me, string arg)
{
	string dest, mout, min, dir, blk, gud, skill, thing_msg;
	object env, obj, blocker, thing;
	mapping block;
	mixed old_target;
	int result;
	int sen_cost;
	mapping exit;
	object *f_obs, *ob;
	object temp_ob;
	mixed flee;
	mapping my, my_temp;
	mapping my_env, my_armor;

	int i, my_dex, count = 0;
	me->set("lunjian/pot",0);
	//me->set("titles/雪上飞狐",0);

	if (me && me->query_temp("array/name"))
	{
		SKILL_D("fanliangyi-dao")->dismiss_array(me);
	}
	if (! arg) return notify_fail("你要往哪个方向走？\n");

	if (me->over_encumbranced())
		return notify_fail("你的负荷过重，动弹不得。\n");

	if (me->query_encumbrance() < 0)
		return notify_fail("你的负荷出现故障，动弹不得。\n");

	if (me->is_busy() || me->query("doing"))
		return notify_fail("你的动作还没有完成，不能移动。\n");

	env = environment(me);
	if (! env) return notify_fail("你哪里也去不了。\n");

	if (me->is_fighting())
	{
		me->clean_up_enemy();
		f_obs = me->query_enemy();
	} else
		f_obs = ({ });

	if (arrayp(ob = env->query_temp("guarded/" + arg)))
		f_obs += ob;

	my = me->query_entire_dbase();
	my_temp = me->query_entire_temp_dbase();
	if (! my_temp) my_temp = empty_mapping;

	my_armor = my_temp["armor"];
	if (! my_armor) my_armor = empty_mapping;

	my_env = my["env"];
	if (! my_env) my_env = empty_mapping;

	if (sizeof(f_obs))
	{
		int fp, gp;
		int force_power;
		int target_power;
		object g_ob;

		fp  = (int)me->query_skill("dodge");
		fp += my["dex"] * 15;
		force_power = me->query_skill("force") + my["str"] * 2;
		if (flee = my_temp["success_flee"])
		{
			if (stringp(flee)) write(flee);
			f_obs = ({ });
		}
		foreach (g_ob in f_obs)
		{
			if (! g_ob) continue;
			if (! living(g_ob) || g_ob == me) continue;

			if (g_ob->query_temp("guardfor_id") != my["id"] && !g_ob->is_fighting(me))
				continue;

			// calculate flee power & guard power
			gp  = g_ob->query_skill("dodge");
			gp += g_ob->query("dex", 1) * 15;

			if ((fp / 2 + random(fp)) < (gp*5/6))
			{
				me->start_busy(1);
				if (me->is_fighting(g_ob))
				{
					message_vision("$N见势不好，转身要走，"
						       "被$n一把拦在面前。想走"
						       "？可没那么容易！\n",
						       me, g_ob);
					tell_object(me, "你逃跑失败。\n");
				} else
				{
					message_vision("$N刚想离开，被$n一把"
						       "拦住：慢着！想打我这"
						       "儿过，没门！\n",
						       me, g_ob);
					tell_object(me, "你被拦住了去路。\n");
				}

				if (userp(g_ob))
				{
					target_power = g_ob->query_skill("force") + g_ob->query("str") * 2;
					if (force_power > target_power * 4)
					{
						message_vision("$N纵声长笑：“鼠辈！安敢欺吾？”说罢"
							       "往前一冲，将$n带出数步，跌倒在地。\n",
							       me, g_ob);
						g_ob->unconcious();
					} else
					if (force_power > target_power * 3)
					{
						message_vision("$N理都没有理$n，只是旁若无人往前走去"
							       "，将$n撞得鼻青脸肿。\n",
							       me, g_ob);
						g_ob->receive_wound("qi", 100 + random(100));
					} else
					if (force_power > target_power * 2)
					{
						message_vision("$N一声冷笑，大踏步的向前冲"
							       "去，乓的一下将$n撞到了一边。\n",
							       me, g_ob);
						g_ob->receive_wound("qi", 50 + random(50));
					} else
						return 1;
				} else
					return 1;
				// 没有阻挡成功，继续前进
			}
		}
	}
	map_delete(my_temp, "success_flee");

	if (! mapp(exit = env->query("exits")) || undefinedp(exit[arg]))
	{
		if (query_verb() == "go")
			notify_fail("这个方向没有出路。\n");
		return 0;
	}

	notify_fail("你过不去。\n");
	result = env->valid_leave(me, arg);
	if (! objectp(me))
		return 1;

	if (! result) return 0;
	if (result < 0 || environment(me) != env)
		return 1;

	dest = exit[arg];
	if (! (obj = find_object(dest)))
		if (! objectp(obj = load_object(dest)))
			return notify_fail(sprintf("目标物件无法找到，无法向 %s 移动。\n", dest ) );

	if(obj->query("owner_special")&&me->query("id")!=obj->query("owner_build")&&me->query("couple/id")!=obj->query("owner_build"))
	{
		return notify_fail(HIG"特殊个人场景，外人禁止进入！"NOR"\n");
	}

	if(env->query("price_build")&&obj->query("door_room")&&me->query("id")!=obj->query("owner_build")&&me->query("couple/id")!=obj->query("owner_build"))
	{
		return notify_fail(HIG"家园主人已关闭外人参观，外人禁止进入！"NOR"\n");
	}

	if(obj->query("owner_build")&&me->query_condition("killer"))
	{
		return notify_fail(HIM"通缉状态还敢回家？"NOR"\n");
	}

	if (my_temp["is_riding"] &&
	    arg != "north"     && arg != "south" &&
	    arg != "east"      && arg != "west" &&
	    arg != "northeast" && arg != "southeast" &&
	    arg != "northwest" && arg != "southwest")
		return notify_fail("这个方向没法骑在座骑上过去。\n");

	if (! undefinedp(default_dirs[arg]))
		dir = default_dirs[arg];
	else
	{
		if (stringp(env->query_room_id(arg)))
			dir = env->query_room_id(arg);
		else
			dir = arg;
	}

	if (me->is_fighting())
	{
		mout = me->name() + "往" + dest->short()+"("+dir + ")落荒而逃了。\n";
		min = me->name() + "跌跌撞撞地跑了过来，模样有些狼狈。\n";
	} else
	{
		if (objectp(thing = my_armor["cloth"]))
			thing_msg = "身着" + thing->query("name");
		else
		if (userp(me))
			thing_msg = "一丝不挂的";
		else
			thing_msg = "";

		if (objectp(thing = my_temp["weapon"]))
			thing_msg += "手执" + thing->query("name");

		if (my["race"] == "野兽")
		{
			mout = me->name() + "呼地往" + dest->short() + "("+dir + ")一窜就消失了。\n";
			min = me->name() + "呼地窜了出来，警惕地四周张望着。\n";
		} else
		{
			object riding;
			if (objectp(riding = my_temp["is_riding"]))
			{
				mout = me->name() + "骑着" + riding->name() + "向" + dest->short() + "("+dir + ")疾驰而去。\n";
				min = me->name() + thing_msg + "骑着" + riding->name() + "一路疾驰而来。\n";
			} else
			{
				mout = me->name() + "往" + dest->short() + "("+dir + ")离开。\n";
				min = me->name() + thing_msg + "走了过来。\n";
			}
		}
	}

	if (! wizardp(me) || ! my_env["invisible"])
	{
		message("vision", mout, environment(me), ({me}) );
	}

#if INSTALL_EXAMINE
	EXAMINE_D->examine_player(me);
#endif

	// move I to dest
	me->remove_all_enemy(1);
	map_delete(my_temp, "pending");
	if (objectp(obj) && ! my_env["invisible"])
	{
		message("vision", min, dest, ({ me }));
	}

	me->move(dest);
	if (!me)
		return 1;
	if(wizardp(me))
		tell_object(me,"你来到了 "+dest->short()+" 。〔"+dest+"〕\n");
	if(me->query("id")=="yu11222")
		tell_object(me,"你来到了 "+dest->short()+" 。〔"+dest+"〕\n");
//	else
//		//tell_object(me,"你来到了 "+dest->short()+" 。\n");
//		tell_object(me,"你来到了 "+dest->short()+"＜"+localtime(time())[2]+"点"+localtime(time())[1]+"分＞。\n");
	if (! objectp(me))
		return 1;

	if (environment(me) != env)
	{
		object competitor;
		if (competitor = me->query_competitor())
		{
			me->lost();
			competitor->win();
		}
		all_inventory(env)->follow_me(me, arg);
	}
	return 1;
}

void do_flee(object me)
{
	mapping exits;
	string *directions;

	if (! environment(me) || ! living(me)) return;
	exits = environment(me)->query("exits");
	if (! mapp(exits) || ! sizeof(exits)) return;
	directions = keys(exits);
	tell_object(me, "看来该找机会逃跑了...\n");
	main(me, directions[random(sizeof(directions))]);
}

static mapping r_dirs = ([
	"north":	"south",
	"south":	"north",
	"east":	 "west",
	"west":	 "east",
	"northup":      "southdown",
	"southup":      "northdown",
	"eastup":       "westdown",
	"westup":       "eastdown",
	"northdown":    "southup",
	"southdown":    "northup",
	"eastdown":     "westup",
	"westdown":     "eastup",
	"northeast":    "southwest",
	"northwest":    "southeast",
	"southeast":    "northwest",
	"southwest":    "northeast",
	"up":	   "down",
	"down":	 "up",
	"enter":	"out",
	"out":	  "enter",
]);

string query_reverse(string dir)
{
	if (undefinedp(r_dirs[dir]))
		return 0;

	return r_dirs[dir];
}

string query_chinese_dir(string dir)
{
	return default_dirs[dir];
}

int help(object me)
{
	write(@HELP
指令格式 : go <方向>
 
让你往指定的方向移动。
 
HELP );
	return 1;
}
