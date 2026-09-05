
#include <ansi.h>

inherit FAMILY_NPC;
varargs void wield_weapon(string weapon);
void die();
#include "medi_drop.h"
int kill_target();

void create()
{
	string name,*tmp,*pinying;
    int i=random(2);
    name=NAME_D->create_name();
    tmp=explode(name,"@");
    pinying=explode(tmp[1]," ");
    set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
	set("gender", i?"男性":"女性");
	set("age", 22+random(100));
	set("combat_exp", 10000000);
	set("attitude", "heroism");
	set("yanmen_enemy",1);
    set("food",500);
    set("water",500);
	set("yanmenkiller",1);
    setup();
    
    carry_object("/clone/armor/tiejia")->wear();
    call_out("leave",600);
    call_out("kill_target",3);
}

void init()
{
    add_action("do_none", "steal");
    add_action("do_none", "attack");
    add_action("do_none", "beg");
    set("random_npc",1);
}

int kill_target()
{
	object ob=this_object();
    object env=environment(ob);
    object *all_target;
    int i;
    if (env)
    {
        all_target=all_inventory(env);
    }
    for (i=0;i<sizeof(all_target);i++)
    {
        if (all_target[i]->query_temp("yanmen/permit"))
        {
            kill_ob(all_target[i]);
        }
    }
	return 1;
}

void leave()
{
    object ob = this_object();
    message_vision("$N眼见无法占到便宜，干脆先撤离了。\n",ob);
    destruct(ob);
	return;
}

void do_copy(object me,int type)
{
        object ob=this_object();
        mapping skills, hp_status, skill_status;
        int i,exp,count,tempskill;
        string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
	    string color1=color[random(sizeof(color))];
        if (!type||type<1||type>2)
        {
            type=1;
        }
        exp = (int)me->query("combat_exp");
        tempskill = to_int(pow(exp/100,0.333)*10);
        if (type==1)
        {
            ob->set("title",color1+"刺客斥候"+NOR);
            ob->set("long","这是一位刺客斥候。\n");
            tempskill=tempskill*6/10;
        }
        if (type==2)
        {
            ob->set("title",color1+"斥候首领"+NOR);
            ob->set("long","这是一位斥候首领。\n");
            tempskill=tempskill*11/10;
        }
        if (tempskill<300)
                 tempskill=300;
        skills = ob->query_skills();
        for (i=0;i<sizeof(skills);i++)
        {
            skills[keys(skills)[i]] = tempskill;
        }
        hp_status = me->query_entire_dbase();
        ob->set("str", hp_status["str"]+random(2));
        ob->set("int", hp_status["int"]+random(2));
        ob->set("con", hp_status["con"]+random(2));
        ob->set("dex", hp_status["dex"]+random(2));
        
        ob->set("combat_exp",exp);// exp浮动，0.95至1.20倍玩家经验 Zine
        ob->set("qi", hp_status["max_qi"]);
        ob->set("eff_qi",hp_status["max_qi"]);
        ob->set("max_qi",hp_status["max_qi"]);
        ob->set("max_neili", hp_status["max_neili"]);
        ob->set("neili", hp_status["max_neili"]);
        ob->set("max_jingli", hp_status["max_jingli"]);
        ob->set("jingli", hp_status["jingli"]);
        if (ob->query("jing") < 5000)
        {
            ob->set("eff_jing",5000);
            ob->set("max_jing",5000);
            ob->set("jing",5000);
        }
        if (ob->query("qi")>10000&&type==1)
        {
            ob->set("eff_qi",10000);
            ob->set("max_qi",10000);
            ob->set("qi",10000);
        }
        if (ob->query("qi")>16000&&type==2)
        {
            ob->set("eff_qi",16000);
            ob->set("max_qi",16000);
            ob->set("qi",16000);
        }
        set("chat_chance_combat", 100);
        family_skill(this_object(), "random", tempskill, 1);
        wield_weapon();
}

void unconcious() 
{
    object ob=this_object();
    object killer=ob->get_damage_origin_object();
    int damage=(int)ob->query("max_qi")/8;
    if(random(3) == 1 && ob->query("qi") > (ob->query("max_qi")/100)*50 && ob->query("eff_qi") > (ob->query("max_qi")/100)*50 && ob->query("jing") > (ob->query("max_jing")/100)*50 && ob->query("eff_jing") > (ob->query("max_jing")/100)*50)
		{
            ob->receive_damage("qi", damage, killer);
        	ob->receive_wound("qi", damage/2, killer);
			return;
		}
        else
        {
            call_out("die",1);
        }
}

int do_none()
{
    return 1;
}

varargs int receive_damage(string type, int damage, mixed who)
{
    object ob=this_object();
	if(random(10) == 0&&ob->is_busy())
		{
			if(objectp(who))
			{
				tell_object(who,ob->query("name")+"被伤痛一激,爆发出不可思议的力量，竟然摆脱了你的纠缠，但同时也伤的更重了。\n");				
			}
			damage = damage*2;
			ob->start_busy(0);
		}
	return ::receive_damage(type,damage,who);
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

