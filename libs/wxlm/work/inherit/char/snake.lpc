// Inherit: snake.c 蛇类


inherit NPC;

int is_snake() { return 1; }

void setup()
{
	mapping p;

	// 设置毒蛇毒性level和毒液的量remain/maximum，毒蛇每次
	// 咬中对方，都会将perhit 指明的毒量注入到对方的体内，
	// 每过一段时间，毒蛇会自动恢复supply量的毒液。
	//
	// level将和武功的force做比较。设置level时候应该参考内功
	// 等级。
	// 毒量和中毒UPDATE_CONDITION的次数成正比，设置毒量的时候
	// 应该参考气，精。
	p = this_object()->query("snake_poison");
	if (! p)
	{
		::setup();
		return;
	}

	if (! intp(p["level"]))   p["level"]   = 30;
	if (! intp(p["perhit"]))  p["perhit"]  = 10;
	if (! intp(p["maximum"])) p["maximum"] = 20;
	if (! intp(p["remain"]))  p["remain"]  = p["maximum"];
	if (! intp(p["supply"]))  p["supply"]  = 1;
	if (! stringp(p["id"]))   p["id"]      = "nature snake";

	::setup();
}

void init()
{
 object me;

	::init();
	if (query_temp("owner"))
		return;

	if (! interactive(me = this_player()))
		return;

	if (present("xiong huang", this_player()) ||
	    (int)me->query_skill("shedu-qiqiao", 1) >= 100)
		return;

	remove_call_out("kill_ob");
	call_out("kill_ob", 0, me);
}

mixed hit_ob(object me, object ob, int damage)
{
	mapping p;
	string  msg;
	int force;
	int dur;

	p = me->query("snake_poison");
	if (! p) return;
	if (damage / 3 + random(damage * 2 / 3) <
	    (int)ob->query_temp("apply/armor"))
	{
		// Defeated by armor
		return;
	}

	msg = "";
	dur = p["perhit"];
	if (dur > (int)p["remain"]) dur = p["remain"];
	p["remain"] = (int)p["remain"] - dur;
	this_object()->apply_condition("poison-supply", 1);
	if (! dur) return;

	force = (int)ob->query_skill("force");
	if (random(force / 2) + force / 2 >= (int)p["level"] && ob->query("neili") > damage / 5)
	{
		if (ob->query("qi") < 150)
		{
			msg = MAG "$n" MAG "觉得伤口有些发麻，连忙运功化解，但是一时体力不支，难以施为。"NOR"\n";
		} else
		if (ob->query("jing") < 60)
		{
			msg = MAG "$n" MAG "觉得伤口有些发麻，连忙运功化解，但是一时精神不济，难以施为。"NOR"\n";
		} else
		if (ob->query("neili") < damage / 5 + 50)
		{
			msg = MAG "$n" MAG "觉得伤口有些发麻，连忙运功化解，但是一时内力不足，难以施为。"NOR"\n";
		} else
		{
			ob->add("neili", -damage / 5);
			ob->receive_damage("qi", 20);
			ob->receive_damage("jing", 10);
			return MAG "$n" MAG "觉得被咬中的地方有些发麻，连忙运功化解毒性。"NOR"\n";
		}
	}

	if (ob->affect_by("poison", ([ "level" : (int)p["level"],
				       "name"  : "蛇毒",
				       "id"    : "nature poison",
				       "duration" : dur, ])))
	{
		msg += HIG "$n" HIG "觉得被咬中的地方一阵麻木！"NOR"\n";
	}

	return msg;
}