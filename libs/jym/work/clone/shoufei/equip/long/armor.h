int init()
{
	object ob = this_object();
	string name,gender;
	int weight,level,value,armor,pp,hp,mp,exp,lasting;

	if(!ob->query("long"))
	{
		name = ob->query("name");
		gender = ob->query("gender");
		weight = ob->query_weight();
		level = ob->query("level");
		value = ob->query("value");
		armor = ob->query("armor_prop/armor");
		pp = ob->query("armor_prop/pp");
		hp = ob->query("armor_prop/hp");
		mp = ob->query("armor_prop/mp");
		exp = ob->query("exp");
		lasting = ob->query("max_lasting");
		
		ob->set("long",sprintf("\n%s\n\n最低经验需求：%d\n要求性别：%s\n重量：%d\n等级：%d\n价值：%d\n物防：%d\n法防：%d\n增气血：%d\n增内力：%d\n耐久度：%d\n\n"
		,name,exp,gender,weight,level,value,armor,pp,hp,mp,lasting));
	}
	return 1;
}