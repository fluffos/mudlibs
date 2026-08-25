/* Do not remove the headers from this file! see /USAGE for more info. */

// John
// Sep 7 94

private
nosave mixed throw_response = 1;
private
nosave function my_throw_hook;
private
nosave string skill_used = "combat/thrown";

void add_hook(string, function);
mixed move(object);

private
mixed prevent_throw()
{
	return throw_response;
}

void set_throwmsg(string s)
{
	throw_response = s;
	if (!my_throw_hook)
	{
		my_throw_hook = (
			: prevent_throw:);
		add_hook("prevent_throw", my_throw_hook);
	}
}

string
query_throwmsg()
{
	if (stringp(throw_response))
		return throw_response;
}

void set_throwable(int g)
{
	if (g == -1 || !g)
		throw_response = 0;
	else
		throw_response = 1;

	if (!my_throw_hook)
	{
		my_throw_hook = (
			: prevent_throw:);
		add_hook("prevent_throw", my_throw_hook);
	}
}

varargs void has_been_thrown(object ob)
{
	//Override me
}

void do_thrown_damage(object target, function damage_func)
{
	this_body()->start_fight(target);
	this_body()->add_event(target, this_object(), 0,
						   evaluate(damage_func));
}

void do_thrown_vital_damage(object target, function damage_func)
{
	this_body()->start_fight(target);
	this_body()->add_event(target, this_object(), choice(target->query_vital_limbs()),
						   evaluate(damage_func));
}

mixed land_throwable(object target, int success)
{
	if (success && target)
	{
		int damage = this_body()->calculate_damage(this_object(), target);
		this_body()->start_fight(target);
		this_body()->add_event(target,
							   this_object(),
							   target->query_random_armour_slot(),
							   damage);
		has_been_thrown(target);
	}
	else if (target)
	{
		if (target)
		{
			TBUG("Target is: " + target);
			this_body()->targetted_action("$N $vthrow a $o at $t, but $n1 $v1dodge out of the way.", target);
		}
		else
			this_body()->simple_action("$N $vthrow a $o nothing in particular.");
		has_been_thrown();
	}
	else
	{
		this_body()->simple_action("$N $vthrow a $o limply. $O didn't seem to detonate", this_object());
		return 1;
	}
}

mixed do_throw(object target)
{
	object env;
	mixed tmp;
	int train_limit;

	if (throw_response != 1)
		return throw_response;

	env = environment();
	tmp = move(environment(this_body()));
	if (tmp == 1)
	{
		if (!target)
		{
			this_body()->simple_action("$N $vthrow a $o.", this_object());
			return 1;
		}
		else
		{
			string defend_skill = target->query_defend_skill_used();
			int defend_value;
			string skill = this_object()->query_skill_used() || skill_used;

			//If it's not a weapon, then we're basically done.
			if (!this_object()->is_weapon())
			{
				this_body()->targetted_action("$N $vthrow a $o at $t. "
											  "It bounces off of $p1 head, "
											  "and lands in front of $p1 feet.",
											  target, this_object());

				return 1;
			}

			defend_value = target->aggregate_skill(defend_skill);
			train_limit = this_body()->cached_skill_value(skill) >= this_body()->level_skill_cap();

			//Skill successful
			if (this_body()->test_skill(skill, defend_value))
			{
				call_out("land_throwable", random(2) + 1, target, 1);
				return 1;
			}
			else //Target dodged us
			{
				call_out("land_throwable", random(3) + 1, target, 0);
				return 1;
			}
		}
	}
}

int is_throwable()
{
	return throw_response == 1;
}
