
#include <ansi.h>

inherit FAMILY_NPC;
varargs void wield_weapon(string weapon);

void die();

int kill_target();

void create()
{
	set_name("近卫武士", ({ "jinwei wushi", "jinwei", "wushi" }) );
	set("gender", "男性" );
	set("age", 22+random(10));
	set("long", "这是一个全副武装的近卫武士，看上去杀气腾腾，一副致人死地的模样。\n");
	set("combat_exp", 10000000);
	set("attitude", "heroism");
	
    set("food",500);
    set("water",500);
	set("chat_chance", 25);
	set("uni_target", 1);
	set("lvliu_biwuchang_jinwei", 1);

	setup();
    carry_object("/clone/armor/jinzhuang")->wear();
    carry_object("/clone/armor/tiejia")->wear();
	
	call_out("kill_target",10);
}

void init()
{
	add_action("do_halt", "halt");
}

int do_copy(object me)
{
	int level;
	int succ_times = 0;
	int addition = 0;
	int life = 0;

	if(!objectp(me))
		return 0;

	set("uni_target", me);
	
	succ_times = me->query_temp("lvliu_biwuchang/count");
	set("job_level", succ_times);
	
	set("level", succ_times + to_int(pow(me->query("combat_exp")/400, 0.333)));
	level = pow(me->query("combat_exp")/100, 0.333) * 9;
	level += succ_times * 10;
     
	if(level < 100)
		level = 100;
	if(succ_times > 10)
	{
        addition = succ_times / 10 - 1;
		if (addition < 1)	addition = 1;
	    else if (addition > 10) addition = 10;
	    set("combat_exp", (me->query("combat_exp")/10) * (random(5)+ 8 +addition) );	    
	    family_skill(this_object(), "random", level*(10+addition)/10, 1);
	}
	else
	{
		set("combat_exp", me->query("combat_exp")/10*(random(5)+8));
		family_skill(this_object(), "random", level, 1);
	}

	set("chat_chance_combat", 150);

	life = level * ( 10 + addition );
	set("max_qi", life);
	set("eff_qi", life);
	set("qi", life);
	set("max_jing", life);
	set("eff_jing", life);
	set("jing", life);
	set("max_jingli", life);
	set("jingli", life*2);
	set("max_neili", life);
	set("neili", life*2);

	wield_weapon();
}

void unconcious()
{
	//拒绝一招晕
	if(random(2) == 1 && query("qi") > (query("max_qi")/100)*40 && query("eff_qi") > (query("max_qi")/100)*40 && query("jing") > (query("max_jing")/100)*40 && query("eff_jing") > (query("max_jing")/100)*40)
			return;
	::unconcious();
}

void die()
{
	object me = query("uni_target");
	object ob = this_object();
	object room;
	int num, reward, reward_re, reward_qn, reward_exp;

	if(!objectp(me))
		return ::die();
	
	room = environment(me);
	if (room != environment(ob) || !room->query("lvliu_biwuchang"))
		return ::die();
	
	me->add_temp("lvliu_biwuchang/count", 1);
	num = (int)me->query_temp("lvliu_biwuchang/count"); 
	reward_re = (int)me->query_temp("lvliu/biwuchang/reward_re"); 
	reward_qn = (int)me->query_temp("lvliu/biwuchang/reward_qn"); 
	reward_exp = (int)me->query_temp("lvliu/biwuchang/reward_exp"); 
	if (num == 1) reward = 1000;
	else if (num <= 10) reward = 200;
	else if (num <= 20) reward = 240;
	else if (num <= 30) reward = 280;
	else if (num <= 40) reward = 320;
	else if (num <= 50) reward = 360;
	else reward = 400;
	reward = reward * (80 + random(41)) / 50;
	reward_exp += reward;
	reward_qn += reward / 10 + random(reward / 10) ;
	reward_re += reward * 9 / 10 + random(reward / 10);
	me->set_temp("lvliu/biwuchang/reward_re",reward_re);
	me->set_temp("lvliu/biwuchang/reward_qn",reward_qn);
	me->set_temp("lvliu/biwuchang/reward_exp",reward_exp);

	tell_room(room, HIY"几个武士把死猪一样的近卫武士拖走了。\n"NOR);
	room->next_turn(me, HIR"$N" HIR "击败第"+chinese_number(num)+"位对手！\n"NOR );
	destruct(ob);
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
	message_vision(HIR"近卫武士趁$N露怯之际猛攻几招，逼得你更加手忙脚乱！\n"NOR, me);
	me->add_busy(1+random(4));
	return 1;
}

int kill_target()
{
	object me, ob;
	ob = this_object();
	me = query("uni_target");
	if(objectp(me))
	{
		if (environment(me)==environment(ob))
			command("kill "+me->mask_id());
	}
	remove_call_out("kill_target");
	call_out("kill_target", 10);
	return 1;
}

varargs int receive_damage(string type, int damage, mixed who)
{
    object ob = this_object();
	int ret=0;
    ret=::receive_damage(type, damage, who);

	if(ob->query("job_level") >= 10 && ob->query_busy()>=10)
	{
		if(!random(3))
		{
			message_vision(HIR"伤痛激发了$N的凶性，$P强运真气怒吼一声，以经脉受创为代价摆脱了纠缠！\n"NOR, ob);
			ret+=::receive_damage(type, damage/10, who);
			ob->start_busy(0);
		}
	}
	return ret;
}
