//	/std/medicine/poison.c
// by Find.

inherit ITEM;

int is_poison() { return 1; }

int query_poison()
{
	int value;

	if(previous_object() && previous_object() != find_object("/cmds/std/xiadu"))
		return 0;

	if(this_object()->query("can_use") < 1 )
		return 0;

	this_object()->add("can_use",-1);

	if(!this_object()->query("can_use"))
		this_object()->set("value",0);
	else
	{
		value = this_object()->query("value");
		if(value)
		{
			value -= value/5;
			if(value <0)
				value = 0;
		}
		this_object()->set("value",value);
	}
	return 1;
}

void drug_in_object()
{
	object ob;
	string condition;

	if(!ob = this_player())
		return;

	condition = this_object()->query("apply_poison");
	if(!stringp(condition))
		return;
	if(!find_object("/daemon/condition/"+condition)
	&& !load_object("/daemon/condition/"+condition))
		return;

	ob->apply_condition(condition,ob->query_condition(condition)+10);
}