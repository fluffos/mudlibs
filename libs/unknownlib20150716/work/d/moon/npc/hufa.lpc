// heaven_soldier.c
#include <ansi.h>
inherit HUFA;

varargs void setskills(int i)
{
	set("long", "广寒宫的护法。\n");
	create_family("月宫", 3, "红");	
	set("gender","女性");
	set("look_msg","广寒宫护法。\n");
	set("title","月宫护法");
	set("receive_damage",1);
	//set("receive_wound",1);
	set_skill("unarmed",i);
	set_skill("dodge",i);
	set_skill("force",i);
	set_skill("parry",i);
	set_skill("sword",i);
	set_skill("spells",i);
	set_skill("moonshentong",i);
	set_skill("baihua-zhang",i);
	set_skill("moonforce",i);
	set_skill("snowsword",i);
	set_skill("moondance",i);
	map_skill("spells", "moonshentong");
	map_skill("unarmed", "baihua-zhang");
	map_skill("force", "moonforce");
	map_skill("sword", "snowsword");
	map_skill("parry", "snowsword");
	map_skill("dodge", "moondance");
	set("max_force",query_skill("force")*10);
	set("max_mana",query_skill("spells")*10);
	if( this_object()->query_level()<70 )
	{
		add_temp("apply/max_kee",500);
		add_temp("apply/max_sen",500);
	}
	else if( this_object()->query_level()<90 )
	{
		add_temp("apply/max_kee",800);
		add_temp("apply/max_sen",800);
	}
	else
	{
		add_temp("apply/max_kee",1000);
		add_temp("apply/max_sen",1000);
	}
}

string name(int raw)
{
	string *order = ({"甲", "乙", "丙", "丁", "戊", "己", "庚", "辛", "壬", "癸"});
	if( this_object()->query_level()<50 )
		return  "天" + (order[random(10)]) + "神兵";
	else if( this_object()->query_level()<70 )
		return "天狐";
	else if( this_object()->query_level()<90 )
		return "仙狐";
	else	return "巫神";
}

string *parse_command_id_list()
{
	if( this_object()->query_level()<50 )
		return  ({"heaven soldier", "soldier","hu fa","hufa","bing",});
	else if( this_object()->query_level()<70 )
		return  ({"tian hu","hu","hufa","hu fa",});
	else if( this_object()->query_level()<90 )
		return  ({"xian hu","hu","hufa","hu fa",});
	else	return  ({"wu shen","wu","hufa","hu fa",});
}

varargs string short(int raw)
{
	string str = ::short(raw);
	if( this_object()->query_level()<50 )
		return str;
	else if( this_object()->query_level()<70 )
		str+= " (三尾)";
	else if( this_object()->query_level()<90 )
		str+= " (六尾)";
	else	str+= " (残魂)";
	return str;
}	

string query_hufa_msg()
{
	return HIC"月华一闪，"+this_object()->name()+HIC"已挡在了$N"HIC"身前，替$P抵挡了$n"HIC"的部分攻击。\n"NOR;
}