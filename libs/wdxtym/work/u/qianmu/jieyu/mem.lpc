inherit F_DBASE;

#define ROOM "/d/city/dongmen"

int start_jieyu(object who);
void end_jieyu();
void init_npc(object who, object npc);

object * npcs = ({});
int count = 0;

int start_jieyu(object who)
{
	object npc;
	int i;
	npc = new(__DIR__"duizhang");
	npc->set("mem", this_object());
	npc->set_name(npc->query("name") + "(" + who->query("name") + ")", ({npc->query("id")}));
	init_npc(who, npc);
	npc->move(ROOM);
	npcs += ({npc});
	for (i = 0; i < 4; i++)
	{
		npc = new(__DIR__"duiyuan");
		npc->set("mem", this_object());
		npc->set_name(npc->query("name") + "(" + who->query("name") + ")", ({npc->query("id")}));
		init_npc(who, npc);
		npc->move(ROOM);
		npcs += ({npc});
	}

	call_out("end_jieyu", 1800);

	return 1;
}

void end_jieyu()
{
	object temp;

	foreach(temp in npcs)
	{
		if (objectp(temp))
			destruct(temp);
	}
	destruct(this_object());
}

void npc_die()
{
	count++;
	if (count == 5)
	{
		write("你成功了。\n");
		remove_call_out("end_jieyu");
		end_jieyu();
	}
}

void init_npc(object who, object npc)
{
	mapping skill_map;
	string * force;
	string temp;
	int skill_max_level = 0;
	mapping who_s, npc_s;

	skill_map = who->query_skills();
	foreach (temp in keys(skill_map))
	{
		npc->set_skill(temp, skill_map[temp]);
		if (skill_max_level < skill_map[temp] && SKILL_D(temp)->type() != "knowledge") skill_max_level = skill_map[temp];
	}

	
	npc->set("skill_max_level", skill_max_level);

	who_s = who->query_entire_dbase();
	npc_s = npc->query_entire_dbase();

	npc_s["qi"] = npc_s["eff_qi"] = npc_s["max_qi"] = who_s["max_qi"];
	npc_s["jing"] = npc_s["eff_jing"] = npc_s["max_jing"] = who_s["max_jing"];
	npc_s["jingli"] = npc_s["max_jingli"] = who_s["max_jingli"];
	npc_s["neili"] = npc_s["max_neili"] = who_s["max_neili"];
	npc->set("jiali", npc->query("skill_max_level"));
}