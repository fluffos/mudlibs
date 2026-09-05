// File		: killer.c
// Created By	: iszt@pkuxkx, 2007-04-16

#include <ansi.h>

inherit FAMILY_NPC;

varargs void wield_weapon(string weapon);
string ask_surrender(string arg);

void create()
{
	string name, nickname;
	string *tmp, *pinyin;
	name=NAME_D->create_name();
	nickname=NAME_D->create_color_nick();
	tmp=explode(name,"@");
	pinyin=explode(tmp[1]," ");

	set_name(tmp[0],({tmp[1],pinyin[0],pinyin[1]}));
	set("nickname", nickname);
	set("gender", "男性" );
	set("age", 22);
	set("long", "这是一个劲装结束的杀手，不知受雇于什么人物。\n");
	set("combat_exp", 10000000);
	set("attitude", "heroism");
	set("rank_info/respect", "大哥");
	add("inquiry", ([
		"name" : "大爷叫什么名字是你问得的么？",
		"here" : "嘿嘿，这里就是你的葬身之所！",
		"rumors" : "嘿嘿，岳不群那老儿万万料不到信会落在我们手上！",
		"认输" : (: ask_surrender :),
	]));
	set("uni_target", 1);
	set("jiali", 50);

	setup();

	if(random(4)==1)
		add_money("gold", random(6));
	add_money("silver", 20+random(8)*10);

	call_out("do_leave", 300);
}

void init()
{
	object me = this_player();
	if(me == query("uni_target"))
	{
		remove_call_out("do_kill");
		call_out("do_kill", 1, me);
	}
}

void do_kill(object me)
{
	object newkiller;

	if(!me)
		return;
	if(query("first_met"))
	{
		command("say 想跑，没那么容易！");
		add("combat_exp", query("combat_exp")/10);
		if(query("combat_exp") > 300000000)
			set("combat_exp", 300000000);
		if(query("killing"))
			kill_ob(me);
		else
		{
			command("hit "+me->query("id"));
			fight_ob(me);
		}
		set_leader(me);
	}
	else
	{
		if(random(2))
		{
			command("say 既然甘当岳不群那老贼的走狗，就别怪本大爷不客气了！");
			set("killing", 1);
			kill_ob(me);
			set("first_met", 1);
		}
		else
		{
			command("say 嘿嘿，让本大爷来教训教训你！");
			fight_ob(me);
			set("first_met", 1);
			newkiller = new(__FILE__);
			newkiller->do_copy(me);
			newkiller->set("first_met", 1);
			newkiller->add("combat_exp", query("combat_exp")/10);
			newkiller->move(environment(me));
			message_vision(CYN"$N笑道：「$n你别逞能，点子爪子硬，老子来帮你！」\n"NOR, newkiller, this_object());
		}
	}
}

int do_copy(object me)
{
	int level;
	int job_level;
	string job_type;

	if(!objectp(me))
		return 0;

	job_level = query_temp("huashan/songxin/level");

	level = pow(me->query("combat_exp")/100, 0.333) * 7;
	level += level/5*job_level;
	if(level < 80)
		level = 80;
	set("combat_exp", me->query("combat_exp")*(job_level*2)/3);
	family_skill(this_object(), "random", level, 1);
	set("chat_chance_combat", 30);
	set("max_qi", level * 10);
	set("eff_qi", level * 10);
	set("qi", level * 10);
	set("max_jing", level * 10);
	set("eff_jing", level * 10);
	set("jing", level * 10);
	set("max_jingli", level * 10);
	set("jingli", level * 10);
	set("max_neili", level * 15);
	set("neili", level * 30);

	set("uni_target", me);
	wield_weapon();
}

void unconcious()
{
	object me = query("uni_target");
	if(get_damage_origin_object()!=me)
		die();
	else
		::unconcious();
}

void die()
{
	object me = query("uni_target");
	if(objectp(get_damage_origin_object()) && get_damage_origin_object() == me)
		me->add_temp("huashan/songxin/killer", 1);
	::die();
	return;
}
int accept_fight(object me)
{
	return 0;
}

varargs void wield_weapon(string weapon)
{
	if(!weapon && query("use_weapon1"))
		wield_weapon(query("use_weapon1"));
	if(!weapon && query("use_weapon2"))
		wield_weapon(query("use_weapon2"));
	if(!weapon)
		return;
	switch(weapon)
	{
	case "sword":
		carry_object("/clone/weapon/changjian")->wield();
		break;
	case "blade":
		carry_object("/clone/weapon/gangdao")->wield();
		break;
	case "staff":
		carry_object("/clone/weapon/gangzhang")->wield();
		break;
	case "whip":
		carry_object("/clone/weapon/changbian")->wield();
		break;
	case "zhen":
		set("gender", "无性");
		carry_object("/d/city/obj/flower_shoe")->wear();
		carry_object("/d/city/obj/pink_cloth")->wear();
		carry_object("/d/city/obj/goldring")->wear();
		carry_object("/d/city/obj/necklace")->wear();
		carry_object("/d/quanzhou/obj/xiuhua")->wield();
		carry_object("/d/riyuejiao/obj/xiuhuajia");
		break;
	case "dagger":
		carry_object("/clone/weapon/bishou")->wield();
		break;
	case "xiao":
		carry_object("/clone/weapon/dart");
		carry_object("/clone/weapon/dart");
		carry_object("/clone/weapon/dart");
		carry_object("/clone/weapon/dart");
		carry_object("/clone/weapon/dart");
		carry_object("/clone/weapon/dart");
		carry_object("/clone/weapon/dart");
		carry_object("/clone/weapon/dart");
		carry_object("/clone/weapon/dart");
		carry_object("/d/taohuadao/npc/obj/yuxiao")->wield();
		break;
	case "ling":
		carry_object("/clone/weapon/dart");
		carry_object("/clone/weapon/dart");
		carry_object("/clone/weapon/dart");
		carry_object("/clone/weapon/dart");
		carry_object("/clone/weapon/dart");
		carry_object("/clone/weapon/dart");
		carry_object("/clone/weapon/dart");
		carry_object("/clone/weapon/dart");
		carry_object("/clone/weapon/dart");
		carry_object("/clone/weapon/changjian")->wield();
		break;
	case "hammer":
		carry_object("/d/dalunsi/npc/obj/iron-falun")->wield();
		break;
	default:
	}
	return;
}
void do_leave()
{
	if(!this_object())
		return;
	message_vision("$N纵身远远的去了。\n", this_object());
	destruct(this_object());
}