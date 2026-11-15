// combined_item.c

#include <dbase.h>
#include <name.h>

inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_MOVE;
inherit F_NAME;

void setup()
{
	if (!query("unit"))
		set("unit", "些");

	if (query("base_weight") < 1)
		set("base_weight", 1);
}

int query_amount() { return query("amount"); }

private void destruct_me() { destruct(this_object()); }

void set_amount(int v)
{

	if (query("base_weight") < 1)
		set("base_weight", 1);
		
	if (v <= 0)
	{
		destruct(this_object());
	} else
	if (10000000 / query("base_weight") < v)
		error("combine:set_amount too many.\n");
	else
	{
		set("amount", v);
		set_weight(v * (int)query("base_weight"));
		if (! query("money_id"))
			set("value", v * (int)query("base_value"));
	}
}

void add_amount(int v) { set_amount(query("amount") + v); }

string short()
{
	return query_amount() + query("base_unit") + ::short();
}

void clean_me()
{
 
	object env;

	env = environment();

	if (env->is_character())
	{
		remove_call_out("clean_me");
		return;
	}

	destruct(this_object());
	return;
}

varargs int move(mixed dest, int silent)
{
	object env, *inv;
	int i, total, max;
	string file;

	if (::move(dest, silent))
	{
		env = environment();
		if (objectp(env))
		{
			file = base_name(this_object());
			inv = all_inventory(env);
			total = query_amount();
			max = 10000000 / query("base_weight");
			for (i = 0; i < sizeof(inv); i++)
			{
				if (inv[i] == this_object()) continue;
				if (base_name(inv[i]) == file &&
				    total + inv[i]->query_amount() <= max)
				{
					total += inv[i]->query_amount();
					destruct(inv[i]);
				}
			}
			set_amount(total);
		}
		return 1;
	}
}

// does I can combine to an itme in the object env ?
int can_combine_to(object env)
{
	object item;
	string file;

	file = base_name(this_object());
	foreach (item in all_inventory(env))
		if (base_name(item) == file)
			return 1;

	return 0;
}
int value() { return query_amount() * (int)query("base_value"); }

string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if( sscanf(param, "%d", amt)==1 )
		set_amount(amt);
}