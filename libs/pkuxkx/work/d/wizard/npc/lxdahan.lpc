//lxdahan.c
//蒙面大汉for自助蜡像
//by all@pkuxkx, 2012/12/3

#include <ansi.h>

inherit FAMILY_NPC;

varargs void wield_weapon(string weapon);
void die();
int kill_target();

void create()
{
	set_name("蒙面大汉", ({ "mengmian dahan", "dahan" }) );
	set("gender", "男性" );
	set("age", 22+random(10));
	set("long", "这是一个穿着奇怪的彪形大汉，脸上罩着黑纱，看上去就不怀好意。\n");
	set("combat_exp", 10000000);
	set("attitude", "heroism");
	set("food",500);
	set("water",500);
	set("chat_chance", 25);
	set("uni_target", 1);
	setup();
	carry_object("/clone/armor/bianfuxuejia")->wear();
	call_out("kill_target",10);
}

void init()
{
	add_action("do_halt", "halt");
	call_out("leave",15);	
}

void start_busy(mixed new_busy, mixed new_interrupt)
{
        if(intp(new_busy) && new_busy > 30)
                ::start_busy(30+random(3));
}

int do_copy(object me)
{
	int level;
	int life = 0;
	int killer_exp=(320+random(81))*1000000;
	if(!objectp(me))
		return 0;
	set("level",to_int(pow(killer_exp/400, 0.333)));
	level = pow(killer_exp/100, 0.333) * 10;
	set("combat_exp", killer_exp );	    
	family_skill(this_object(), "random", level, 1);
	set("chat_chance_combat", 100);

	life = level * 15;
	set("max_qi", life);
	set("eff_qi", life);
	set("qi", life);
	set("max_jing", life);
	set("eff_jing", life);
	set("jing", life);
	set("max_jingli", life);
	set("jingli", life);
	set("max_neili", life);
	set("neili", life);
	set("uni_target", me);
	wield_weapon();
}

void unconcious()
{
	//一招晕有几率失效
	if(random(2) == 1 && query("qi") > (query("max_qi")/100)*50 && query("eff_qi") > (query("max_qi")/100)*50 && query("jing") > (query("max_jing")/100)*50 && query("eff_jing") > (query("max_jing")/100)*50)
	{
		return;
	}
        else call_out("die",1);
}

void die()
{
	object ob = this_object();
	object me = query("uni_target");
	if(!objectp(me) || !present(me, environment()))
	{
		::die();
		return;
	}
    	tell_object(me,HIB"蒙面大汉愣愣的看着你，似乎心有不甘，慢慢倒在了地上。\n"NOR);	    
	me->add_temp("laxiang/killed",1);
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

int do_halt()
{
	object me = this_player();
	if(!me->is_fighting())
	{
		return 0;
	}	
	
	tell_object(HIR"这里岂是你想走就走的？！\n"NOR);
	me->start_busy(1+random(4));
	return 1;
}


int visible(object ob)
{
    if(query("uni_target") != ob) return 0;
    return 1;
}

int kill_target()
{
	object target = query("uni_target");
	if(objectp(target))
	{
   		command("kill "+target->mask_id());
	}
	remove_call_out("kill_target");
	call_out("kill_target",5+random(5));
	return 1;
}

void leave()
{
    object ob = this_object();
    object me = ob->query("uni_target");
    if (!me ||
    	  environment(me) != environment(ob) )
    {
      destruct(this_object());
	    return ;
    }
    else
    {
        if (base_name(environment(me))!="/d/wizard/lxmidao2") 
            {
                destruct(this_object());
                return ;
            }
        else call_out("leave",90);
    }
}

varargs int receive_damage(string type, int damage, mixed who)
{
    int ret=0;
    object killer;

    ret=::receive_damage(type, damage, who);
    killer=get_damage_origin_object();

    if(random(12) == 0)
    {
        if(objectp(killer))
        {
            tell_object(killer, query("name")+"被伤痛一激,爆发出不可思议的力量，竟然摆脱了你的纠缠，但同时也伤的更重了。\n");				
        }
        ret+=::receive_damage(type, damage, who);
        ::start_busy(0);
    }

    return ret;
}
