//fix by yhzzyahoo 加入韩世忠机器标记处理
#include <ansi.h>

inherit FAMILY_NPC;
varargs void wield_weapon(string weapon);
int ask_betray();
void create()
{
	string weapon;
    string name,*tmp,*pinying;
	name=NAME_D->create_name();
	tmp=explode(name,"@");
	pinying=explode(tmp[1]," ");
	set_name(tmp[0],({tmp[1],pinying[0],pinying[1],"yizu jianxi","jianxi"}));
	set("title",HBGRN+HIW+"异族奸细"+NOR);
	set("gender", random(2)?"女性":"男性" );
	set("age", 22);
	set("long", "这是一个来到大宋的奸细。\n");
	set("combat_exp", 10000000);
	set("attitude", "heroism");
	set("food",500);
	set("water",500);
	set("random_npc", 1);
	set("hsz_jianxi",1);
	set("jiali", 300);
	set("inquiry", ([
				"反间" : (: ask_betray :),
	]) );
	setup();
	carry_object("/clone/armor/pifeng")->wear();
}
int ask_betray()
{
	object me=this_player(),ob=this_object(),*enemy;
	if (me->is_busy())
	{
		tell_object(me,"你正忙着呢。\n");
		return 1;
	}
	if (ob->query("double_faced"))
	{
		tell_object(me,ob->name()+"已经反叛了。\n");
		return 1;
	}
	if (!ob->query("double_face"))
	{
		command("pei");
		me->add_busy(1);
		return 1;
	}
	ob->set("double_faced",me);
	ob->remove_all_killer();
	enemy=all_inventory(environment(ob));
	for (int i=0;i<sizeof(enemy);i++)
	{
		if (enemy[i]!=me&&enemy[i]->is_character()&&living(enemy[i])&&enemy[i]->query("hsz_jianxi")&&enemy[i]!=ob)
		ob->kill_ob(enemy[i]);
	}
	tell_object(me,"你向"+ob->name()+"细细分说倒向大宋的好处，说得"+ob->name()+"叛变，反戈一击了。\n");
	tell_object(me,HIR+"不过双面间谍也不可靠，事完之后还是杀了他更为保险。\n"+NOR);
	return 1;
}
int reset_chance()
{object me=this_player();
	if (me->query("hsz_auto"))
	{
		set("chat_chance_combat", 80);
	}
	else
	{
		set("chat_chance_combat", 55);
	}
}
void init()
{
	object me=this_player();
	if (me==query("owner")&&query("double_faced")!=me)
	kill_ob(me);
	if (!query("init_combat")&&me&&environment(me)==environment())
	{
		set("init_combat",1);
		remove_call_out("reset_chance");
		call_out("reset_chance",5);
	}
}
int do_copy(object me)
{
	int level;
	int t_exp,t_maxqi;
	int fix_d1,fix_d2,fix_d3,jl_int;
	string *family=({"shaolin", "wudang", "emei", "gaibang","tianlong", "tiandihui","xueshan","baituo", "shenlongjiao","lingjiu", "murong", "mingjiao","mingjiao"});
	if(!objectp(me))
		return 0;
	
	if (random(40)==0)
	{
		t_exp=me->query("combat_exp")*3;
		t_maxqi=me->query("max_qi")*2;
		fix_d1=25;
		fix_d2=3;
		fix_d3=5;
	}
	else
	{
		t_exp=me->query("combat_exp");
		t_maxqi=me->query("max_qi");
		fix_d1=0;
		fix_d2=0;
		fix_d3=0;
	}

	if (me->query("hsz_auto")==1)
	{
		set("chat_chance_combat", 150);
		fix_d1+=15;
		fix_d2+=3;
		fix_d3 = 10;
		t_exp=t_exp*6/5;
		t_maxqi=t_maxqi*7/5;
	}
	else
	{
		set("chat_chance_combat", 20);
	}
	level=to_int(pow(t_exp/100,0.333))*8;
	if(level < 200)
		level = 200;
	set("combat_exp", t_exp/10*8);
	family_skill(this_object(), family[random(sizeof(family))], level, 1);

//	set("chat_chance_combat", 70);
	set("max_qi", t_maxqi/2);
	set("eff_qi", t_maxqi/2);
	set("qi", t_maxqi/2);
	set("max_jing", me->query("max_jing")/2);
	set("eff_jing", me->query("max_jing")/2);
	set("jing", me->query("max_jing")/2);
	set("max_jingli", me->query("max_jingli"));
	set("jingli", me->query("max_jingli"));
	set("max_neili", me->query("max_neili")*2/3);
	set("neili", me->query("max_neili")*2/3);
	set("level",me->query("level")+random(10));
	set("jiali",jl_int);
	if (random(4)==0)
	{
		set("per",me->query("level")+random(30));
	}
	set_temp("apply/strength",me->query("level"));
    set_temp("apply/week_injure", fix_d3);
	set_temp("apply/kf_def_wound", fix_d1);
	set_temp("apply/kf_anti_hr", fix_d2);
	set_temp("apply/kf_hit_rate", fix_d2);

	set("owner",me);
	wield_weapon();
	set("long",query("long")+"这是一位擅长"+HBGRN+HIR+to_chinese(query_skill_mapped("dodge"))+NOR+"的高手。\n");
}

void start_busy(mixed new_busy, mixed new_interrupt)
{
	::start_busy(1);
}
void die()
{
	object pl;
	if (!pl=query("owner"))
	return;
	if (environment(pl)!=environment(this_object()))
	return;
	if (!userp(pl)||!pl->query_temp("hansz/jianxi_num"))
	return;
	pl->add_temp("hansz/kill_jianxi",1);
	::die();
}
void unconcious() 
{
    object ob=this_object();
    if(ob->query("qi") > (ob->query("max_qi")/100)*50 && ob->query("eff_qi") > (ob->query("max_qi")/100)*50 && ob->query("jing") > (ob->query("max_jing")/100)*50 && ob->query("eff_jing") > (ob->query("max_jing")/100)*50)
	return;
	die();
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
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/npc/obj/yuxiao")->wield();
         break;
         case "ling":
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/obj/shenghuo-ling")->wield();
         break;
	case "hammer":
		carry_object("/d/dalunsi/npc/obj/iron-falun")->wield();
		break;
	default:
	}
	return;
}

