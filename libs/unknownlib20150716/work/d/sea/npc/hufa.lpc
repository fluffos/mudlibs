// heaven_soldier.c
#include <ansi.h>
inherit HUFA;

string *msg_in=({
		HIG"一道水波从地底升起，波中出现一个手执钢叉、面目狰狞的虾兵。\n\n$N"HIG"说道：末将奉法主召唤，特来护法！\n" NOR,
		HIG"一道水波从地底升起，波中出现一个手执钢叉、面目狰狞的夜叉。\n\n$N"HIG"说道：末将奉法主召唤，特来护法！\n" NOR,
                HIY"\n忽然狂风大做，半空现出一条$N"HIY"来！\n\n"NOR,
});

string *msg_out=({
		HIR"\n\n$N"HIR"不由身形一颤，再也遮不住原形，顿时现出真身，却原来是一只虾米！\n地上涌出一股清泉，小虾米立时淹没其中消失了。。。\n"NOR,
		HIG"$N"HIG"说道：末将奉法主召唤，现在已经完成护法任务，就此告辞！\n\n$N"HIG"身下涌出一股清泉，身影立时消失了。。。\n"NOR,
		HIB"\n\n忽然狂风大做，卷住$N"HIB"身形朝向东海飞去！\n\n"NOR,
});

varargs void setskills(int i)
{
	set("long", "水晶宫的护法。\n");
	create_family("东海龙宫", 3, "红");	
	set("gender","男性");
	set("look_msg","东海水晶宫护法。\n");
	set("title","龙宫护法");
	//set("receive_damage",1);
	//set("receive_wound",1);
	set_skill("literate", i);
	set_skill("unarmed", i);
       	set_skill("dodge", i);
       	set_skill("force", i);
       	set_skill("parry", i);
       	set_skill("fork", i);
       	set_skill("spells", i);
	set_skill("seashentong", i);
	set_skill("dragonfight", i);
	set_skill("dragonforce", i);
	set_skill("fengbo-cha", i);
	set_skill("dragonstep", i);
	map_skill("spells", "seashentong");
	map_skill("unarmed", "dragonfight");
	map_skill("force", "dragonforce");
	map_skill("fork", "fengbo-cha");
	map_skill("parry", "fengbo-cha");
	map_skill("dodge", "dragonstep");
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
	set("force_factor",this_object()->query_skill("force")*3/2);
	set("mana_factor",this_object()->query_skill("spells")*3/2);
}

string name(int raw)
{
	string *name1 = ({ "花皮", "金角", "金尾","银角"});
	string *name2 = ({ "背苍", "八爪", "虬髯","五爪",});
	if( this_object()->query_level()<50 )
		return  "日值虾兵";
	else if( this_object()->query_level()<70 )
		return "巡海夜叉";
	else	return name1[random(sizeof(name1))]+name2[random(sizeof(name2))]+"龙"; 
}

string *parse_command_id_list()
{
	if( this_object()->query_level()<50 )
		return  ({"xia bing", "xia","hu fa","hufa","bing",});
	else if( this_object()->query_level()<70 )
		return  ({"ye cha","cha","hufa","hu fa",});
	else	return  ({"dragon","long","hufa","hu fa",});
}

