// patrol.c

mapping init_user(mapping quest,int exp)
{
	object who = this_player();
	mapping q;
	string *p = ({
"/d/feiyu/yu13",
"/d/feiyu/yu10",
"/d/feiyu/yu9",
"/d/feiyu/yu7",
"/d/feiyu/yu6",
"/d/feiyu/yu5",
"/d/feiyu/yu15",
"/d/feiyu/yu16",
"/d/feiyu/yu17",
"/d/feiyu/yu19",
});

	if(!mapp(quest) || !sizeof(quest) || !who)
		return 0;

	who->set("patroling/path",p);

	q = allocate_mapping(sizeof(quest)-1);
	q["quest"] = quest["quest"];
	q["begin_msg"] = quest["begin_msg"];
	q["hint"] = quest["hint"];
	q["name"] = quest["name"];
	q["reward"] = quest["reward"];
	q["end_msg"] = quest["end_msg"];

	return q;
}
