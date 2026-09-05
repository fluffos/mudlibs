// File		: target.c
// Created By	: iszt@pkuxkx, 2007-03-28
// modified by zine @ pkuxkx 2014 for other task.
// 加入了一些厉害一些的npc by yhzzyahoo @2015.4.18
// fix一下npc不发pfm的问题 by yhzzyahoo @2015.4.20
#include <ansi.h>

//inherit FAMILY_NPC;
inherit QUEST_NPC;

varargs void wield_weapon(string weapon);
void die();
int ask_rumors();
int ask_fight();
int ask_name();
void create()
{
	string name,*tmp,*pinying;
	name=NAME_D->create_name();
	tmp=explode(name,"@");
	pinying=explode(tmp[1]," ");
	set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
	set("gender", "男性" );
	set("age", 42);
	set("long", "这是一位投降蒙古的前大宋官员，他警惕地看着周围。\n");
	set("combat_exp", 10000000);
	set("attitude", "heroism");
	set("rank_info/respect", "大人");
	add("inquiry", ([
		"name" : (:ask_name:),
		"here" : "别烦我！",
		"rumors" :  (: ask_rumors :),
        "fight" : (:ask_fight:),
	]));
	set("xiaofeng",1);
	set("food",500);
	set("water",500);
	set("uni_target", 1);
    set("env/wimpy", 35);
	set("jiali", 50);
	set("gem_level", ({0, 8334}));
	set("chat_chance_combat", 100);
	setup();
	carry_object("/clone/armor/tiejia")->wear();
	carry_object(__DIR__"obj/shoes")->wear();
   if(random(5)==0)
	    add_money("gold", random(6));
   if(random(4)==1)
	    add_money("silver", 20+random(8)*10);
	call_out("do_leave", 1200);
}

void init()
{
	object me=this_player(),*inv;
	if (!me->query_temp("mzj/met")&&me==query("uni_target"))
	{
		me->set_temp("mzj/met",1);
		tell_object(me,BLINK+HBCYN+HIW+"你定睛一看，"+query("name")+"正是你要找的汉奸卖国贼！\n"+NOR);
		inv=all_inventory(me);
		for (int i=0;i<sizeof(inv);i++)
		if (inv[i]->is_MZJ_PASSWD())
		{
			destruct(inv[i]);
		}
	}
}
void delete_init_num(object me)
{
	me->delete("init_num");
	return;
}
int ask_name()
{
	command("hehe");
	command("say 我叫"+this_player()->query("name")+"，我丧尽天良，人人得而诛之。");
	command("haha");
	return 1;
}
int do_copy(object me)
{
	mapping hp_status;
	string* colors=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT}),*titles=({"招讨","安抚","宣抚"});
	string color=colors[random(sizeof(colors))];
	int tempskill,exp,qi_base,quest_times,fix_df;
	exp = me->query("combat_exp");	
	hp_status = me->query_entire_dbase();
	quest_times=me->query("newjobs/completed/mzj");
	if (quest_times>50000)
	{
		quest_times=50000;
	}
	if (random(18)==0||(me->query("hsz_auto")&&(random(7)==1)))
	{
		/*if (me->query("hsz_auto"))
		{
			exp=exp*5/2;
		}
		else
		{
			exp=exp*2;
		}*/
	set("str", hp_status["str"]+10);
	set("int", hp_status["int"]+10);
	set("con", hp_status["con"]+10);
	set("dex", hp_status["dex"]+10);
	set("combat_exp",exp/9*10);
	set("qi", hp_status["max_qi"]/2*3);
	set("eff_qi",hp_status["max_qi"]/2*3);
	set("max_qi",hp_status["max_qi"]/2*3);
	set("max_neili", hp_status["max_neili"]/2*3);
	set("neili", hp_status["max_neili"]/2*3);
	set("max_jingli", hp_status["max_jingli"]/2*3);
	set("jingli", hp_status["jingli"]/2*3);
	set("max_jing", hp_status["max_jingli"]/2*3);
	set("jing", hp_status["max_jingli"]/2*3);
	if (me->query_skill("liumai-shenjian",1))
	{
		fix_df=20;
	}
	else
		{
		fix_df=10;
		}
    set_temp("apply/week_injure", fix_df);
	set_temp("apply/kf_def_wound", 15);
	set_temp("apply/kf_anti_hr", 3);
	set_temp("apply/kf_hit_rate", 3);
	if ((exp>150000000)||(quest_times > 15000))
		{
		set_temp("apply/week_injure", fix_df+10+random(15));
		set_temp("apply/kf_def_wound", 25+random(20));
		}
	}
	else
	{
	set("str", hp_status["str"]+random(2));
	set("int", hp_status["int"]+random(2));
	set("con", hp_status["con"]+random(2));
	set("dex", hp_status["dex"]+random(2));
	if (me->query("hsz_auto")&&(random(3)==1))
		set("combat_exp",exp);
	else
		set("combat_exp",exp/10*9);
	set("qi", hp_status["max_qi"]);
	set("eff_qi",hp_status["max_qi"]);
	set("max_qi",hp_status["max_qi"]);
	set("max_neili", hp_status["max_neili"]);
	set("neili", hp_status["max_neili"]);
	set("max_jingli", hp_status["max_jingli"]);
	set("jingli", hp_status["jingli"]);

	}
	tempskill = to_int(pow(exp/100,0.333)*9);
	if (tempskill<300)
	tempskill=300;
	set("jiali", tempskill);  
	if (query("jing") < 5000)
	{
		set("eff_jing",5000);
		set("max_jing",5000);
		set("jing",5000);
	}
	else
	{
		set("max_jing", hp_status["max_jingli"]);
		set("jing", hp_status["max_jingli"]);
	}
	qi_base=query("qi");
	if ((query("qi")>100000)&&(me->query("chushi/done")||(me->query("betrayer"))))
	{
		qi_base=50000+quest_times;
	}
	else
	{
		if (query("qi")>35000)//为武当长气血的一点点福利 Zine
		{
			if (quest_times < 15000)
			{
				qi_base=35000;
			}
			else
			{
				if (query("qi")>(35000+quest_times/2))
				{
					qi_base=35000+quest_times/2;
				}
				else
				{
					qi_base=query("qi");
				}
			}
		}
		if (qi_base > 50000)
		{
			qi_base = 50000;
		}
	}
	set("eff_qi",qi_base);
	set("max_qi",qi_base);
	set("qi",qi_base);
	set("chat_chance_combat", 150);
	//set("chat_msg_combat", ({(: auto_perform :),	}));
	set("title", WHT"大元 "+colors[random(sizeof(colors))]+MAP_D->place_belong(environment(me))+"路"+titles[random(sizeof(titles))]+"副使"NOR);
	family_skill(this_object(), "random", tempskill, 1);
	if (query("family")=="murong" && random(100)>90)
	{
		set("safari_skill/mr_douzhuan",1);
		family_skill(this_object(), "murong", tempskill, 1);
	}
	set("uni_target", me);
	wield_weapon();
}

void die()
{
	object me = query("uni_target"),ob = this_object();
	if(!me || !objectp(me) || me->query_temp("mzj/target")!=ob)
	{
		::die();
		return;
	}	//for test
	if(!objectp(get_damage_origin_object()) || get_damage_origin_object() != me)
	{
		tell_object(me,RED+"你行刺的目标已经被别人杀死了！行刺任务失败！\n"NOR);
		::die();
		return;
	}
	me->set_temp("mzj/finish",1);
	tell_object(me,HBGRN+HIW+"恭喜！你完成了都统制府行刺任务！\n"+NOR);
	::die();
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
void do_leave()
{
	if(!this_object())
		return;
	message_vision("$N见时候不早，离开了此地。\n", this_object());
	destruct(this_object());
}

int ask_rumors()
{
	object player=this_object()->query("uni_target");
	if (!player)
	{
		command("say 你也知道是rumor了，rumor就是花边新闻，做不得数，有什么好问的？");
		return 1;
	}
	if (this_object()->is_fighting())
	{
		command("say 没看我在打架吗？");
		return 1;
	}	
	if (player==this_player())
	{
		command("say 你也是来行刺本官的吗，送死的人可真不少？");
		kill_ob(this_player());
	}
	else
	command("say 听说有人要来行刺本官。");
	return 1;
}

int ask_fight()
{
        if (this_object()->query("uni_target")==this_player()) {
        	if (environment(this_object())->query("no_fight")) 
        	{
        		command("nod");
        		random_move();
        	}
        	else command("say 你怕了吗？");
        } 
		else 
		{
			command("shake");
			command("say 别没事找事。");
		}
        return 1;
}
