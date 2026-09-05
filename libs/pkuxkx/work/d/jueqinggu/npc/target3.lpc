// modified by zine @ pkuxkx 2014 for other task.
#include <ansi.h>

inherit FAMILY_NPC;

varargs void wield_weapon(string weapon);
void die();
int ask_fight();
void create()
{
	string name,*tmp,*pinying;
	name=NAME_D->create_name();
	tmp=explode(name,"@");
	pinying=explode(tmp[1]," ");
	set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
	set("gender", "男性" );
	set("age", 42);
	set("combat_exp", 10000000);
	set("attitude", "heroism");
	add("inquiry", ([
		"here" : "别烦我！",
        "fight" : (:ask_fight:),
	]));
	set("xiaofeng",1);
	set("food",500);
	set("water",500);
	set("uni_target", 1);
        set("env/wimpy", 35);
	set("jiali", 50);
	set("chat_chance_combat", 100);
	set("gem_level", ({0, 8334}));
	setup();
	carry_object("/clone/armor/tiejia")->wear();
	carry_object("/clone/cloth/male-shoe")->wear();
   if(random(5)==0)
	    add_money("gold", random(6));
   if(random(4)==1)
	    add_money("silver", 20+random(8)*10);
	call_out("do_leave", 300);
}
void init()
{
	object me=this_player(),*inv;
	if (!me->query_temp("gongsun/met")&&me==query("uni_target"))
	{
		me->set_temp("gongsun/met",1);
		message_vision("$N大声道：“"+query("name")+"，今天看你还往哪逃。”\n",me);
		me->kill_ob(this_object());
		this_object()->kill_ob(me);
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
int do_copy(object me,string mp)
{
	mapping hp_status;
	int tempskill,exp,quest_times,qi_base,qi_int;
	mapping menpai=(["明教":"mingjiao","日月神教":"riyuejiao","武当派":"wudang","少林派":"shaolin","华山派":"huashan","天龙寺":"tianlong","丐帮":"gaibang",
	"峨嵋派":"emei","姑苏慕容":"murong","白驼山":"baituo","星宿派":"xingxiu","古墓派":"gumu","灵鹫宫":"lingjiu","全真派":"quanzhen","桃花岛":"taohua",
	"神龙教":"shenlongjiao","朝廷":"chaoting","大轮寺":"dalunsi","雪山派":"xueshan"]);
	exp = me->query("combat_exp");
	quest_times=me->query("jobs/completed/gongsun");
	if (quest_times>50000)
	{
		quest_times=50000;
	}
	tempskill = to_int(pow(exp/100,0.333)*9);
	if (tempskill<300)
	tempskill=300;
	hp_status = me->query_entire_dbase();
	set("str", hp_status["str"]+random(5));
	set("int", hp_status["int"]+random(5));
	set("con", hp_status["con"]+random(5));
	set("dex", hp_status["dex"]+random(5));
	set("combat_exp",exp/11*9);
	set("qi", hp_status["max_qi"]);
	set("eff_qi",hp_status["max_qi"]);
	set("max_qi",hp_status["max_qi"]);
	set("max_neili", hp_status["max_neili"]+quest_times);
	set("neili", hp_status["max_neili"]+quest_times);
	set("max_jingli", hp_status["max_jingli"]);
	set("jingli", hp_status["jingli"]);
	if (query("jing") < 5000)
	{
		set("eff_jing",5000);
		set("max_jing",5000);
		set("jing",5000);
	}
	qi_int=query("qi");
	if (qi_int>75000)
	{
		qi_base=50000+quest_times;
	}
	else
	{
		if (qi_int>25000)
		{
			if (qi_int>(25000+quest_times/2))
				{
					qi_base=25000+quest_times/2;
				}
				else
				{
					qi_base=qi_int;
				}
		}
	}
	if (qi_int>qi_base)//为武当长气血的一点点福利 Zine
	{
		set("eff_qi",qi_base);
		set("max_qi",qi_base);
		set("qi",qi_base);
	}
	if (random(10)==0)
	{
		set("combat_exp",exp*3/2);
		set("eff_qi",query("qi")*3/2+quest_times);
		set("max_qi",query("qi")*3/2+quest_times);
		set("qi", query("qi")*3/2+quest_times);
		set_temp("apply/week_injure", 10 + random(10));
		set_temp("apply/kf_def_wound", 15 + random(10));
		set_temp("apply/kf_anti_hr", 3);
		set_temp("apply/kf_hit_rate", 3);
		set("chat_chance_combat", 100);
		set("jiali",hp_status["max_neili"]/20);
		if ((quest_times>12000)||(exp > 150000000))
		{
			set_temp("apply/week_injure", 20 + random(20));
			set_temp("apply/kf_def_wound", 25 + random(20));
		}
	}
	else
	{//fix by yhzzyahoo加入机器人增强
		if (me->query("hsz_auto")&&random(7)==0)
		{
			quest_times=me->query("jobs/completed/gongsun");
			set("combat_exp",exp*3/2);
			set("eff_qi",query("qi")*3/2+quest_times);
			set("max_qi",query("qi")*3/2+quest_times);
			set("qi", query("qi")*3/2+quest_times);
			set_temp("apply/week_injure", 30);
			set_temp("apply/kf_def_wound", 30);
			set_temp("apply/kf_anti_hr", 3);
			set_temp("apply/kf_hit_rate", 3);
			set("chat_chance_combat", 100);
			set("jiali",hp_status["max_neili"]/20);
			if ((quest_times>12000)||(exp > 150000000))
			{
				set_temp("apply/week_injure", 40);
				set_temp("apply/kf_def_wound", 40);
			}
		}
	}

	set("title", HBWHT+HIR+mp+"逆徒"NOR);
	set("long","他是一个"+query("title")+"，听闻正在躲避"+me->query("name")+"的追杀。\n");
	if (mp=="姑苏慕容"&&random(100)>90)
	{
		set("safari_skill/mr_douzhuan",1);
	}
	family_skill(this_object(), menpai[mp], tempskill, 1);
	set("uni_target", me);
	set("family/family_name",mp);
	me->set_temp("gongsun/kill_target",this_object());
	wield_weapon();
}

void die()
{
	object me = query("uni_target"),ob = this_object();
	if(!me || !objectp(me) || me->query_temp("gongsun/kill_target")!=ob)
	{
		::die();
		return;
	}	//for test
	if(!objectp(get_damage_origin_object()) || get_damage_origin_object() != me)
	{
		tell_object(me,RED+query("family/family_name")+"已经死于江湖仇杀，你可以回去向公孙谷主复命了！\n"NOR);
		::die();
		return;
	}
	me->set_temp("gongsun/finish",3);
	tell_object(me,HIC+"完整完成公孙谷主的要求，你可以回去复命了！\n"+NOR);
	me->start_busy(2+random(2));
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
void start_busy(mixed new_busy, mixed new_interrupt)
{
	message_vision("$N不屑地撇了撇嘴，“小儿科。”\n",this_object());
	::start_busy(random(3));
}

varargs int receive_damage(string type, int damage, mixed who)
{
    int ret=0,suc=0;
    object killer;
	killer=get_damage_origin_object();
	if (time()-query_temp("hit_time")<1) //这次击中和上次击中间隔小于1秒，加连击数
	add_temp("hit_hits",1);
	if (query_temp("hit_by")&&query_temp("hit_by")==killer&&query_temp("hit_hits")>3)
	{
		suc=1;
		damage=damage*6/5;
	}
	set_temp("hit_time",time());
	set_temp("hit_by",killer);
	if (killer&&suc)
		message_vision(RED+"$N被$n连续击中，伤势更重。\n"+NOR,this_object(),killer);
	ret=::receive_damage(type, damage, who);
	return ret;
}