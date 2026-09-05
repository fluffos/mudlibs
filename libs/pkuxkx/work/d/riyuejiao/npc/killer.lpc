
#include <ansi.h>
#include "/d/riyuejiao/bonus.h"
inherit FAMILY_NPC;
varargs void wield_weapon(string weapon);
void die();
int kill_target();

void create()
{
	string name,*tmp,*pinying;
    name=NAME_D->create_name();
    tmp=explode(name,"@");
    pinying=explode(tmp[1]," ");
    set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
    set("realname",query("name"));
    set("realid",query("id"));
    set("realtitle",HIW+"盖世豪侠"+NOR);
	set("gender", "男性" );
	set("age", 22+random(10));
	set("reallong", "这是一个其他门派准备混入黑木崖的间隙。\n");
	set("combat_exp", 10000000);
	set("attitude", "heroism");
	set("random_npc",1);
    set("food",500);
    set("water",500);
	set("chat_chance", 25);
	set("uni_target", 1);
	set("ry_newbie_target", 1);
    set("bonus",40);
	setup();
    carry_object("/clone/cloth/cloth")->wear();
	
	call_out("kill_target",10);
    call_out("dest",240);
}

int dest()
{
    object ob=this_object();
    if (!ob->is_fighting()&&!ob->is_busy())
    {
        message_vision("$N见没有什么情报可以收集，于是离开了。\n",ob);
        destruct(ob);
    }
    call_out("dest",60);
    return 1;
}

int do_copy(object me)
{
	int level,exp;
	int addition = 1;
	int life = 0;

	if(!objectp(me))
		return 0;
	exp = me->query("combat_exp");
    
	level = to_int(pow(exp/100,0.333)*(6+random(2)));
    set("combat_exp", me->query("combat_exp")/10*(random(3)+6));
	family_skill(this_object(), "random", level, 1);
	
    set("chat_chance_combat", 150);
	
	life = to_int(exp/(120-random(41)));

	set("max_qi", life);
	set("eff_qi", life);
	set("qi", life);
	set("max_jing", life);
	set("eff_jing", life);
	set("jing", life);
	set("max_jingli", life);
	set("jingli", life);
	set("max_neili", life*1.5);
	set("neili", life*2);

	set("uni_target", me);
	wield_weapon();
}

void die()
{
	
	object ob = this_object();
    object me = ob->query("uni_target");
    if (ob->get_damage_origin_object()==me)
    {
        bonus(me); 
    }
    
    CHANNEL_D->do_channel(this_object(), "bd", "disapp", 1);
      
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

int kill_target()
{
    object ob=this_object();
	object target = query("uni_target");
	if(objectp(target)&&base_name(environment(this_object()))==base_name(environment(target)))
	{
		kill_ob(target);
	}
    if ((ob->query("realname")!=ob->query("name"))&&ob->is_fighting())
    {
        message_vision("$N怪叫一声，露出了本来面目。\n",ob);
        ob->set("name",query("realname"));
        ob->set("id",query("realid"));
        ob->set("long",query("reallong"));
        ob->set("title",query("realtitle"));
    }
	remove_call_out("kill_target");
	call_out("kill_target",5+random(5));
	return 1;
}
