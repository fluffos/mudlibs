#include <ansi.h>

inherit BOSS;
int boss_attack();

void create()
{
	int lev;
	set_name( HIB "帝鸿" NOR, ({ "dihong", "boss" }) );
	set("long", HIB "上古传说中的帝鸿毒兽，化为人形，与黄帝对抗，结果被黄帝所杀！\n"NOR);
	set("title",  HIG"众神的宏物"NOR);
	set("gender",  "男性");
	set("age", 3500);
	set("no_get", 1);
	set("shen_type", -1);
	set("attitude", "aggressive");
	
	set("dex",200);
	set("con",200);
	set("int",200);
	set("str",200);
	
	set("combat_exp", 650000000);
	set("vendetta/authority",1);
	set("level", 21);
	set("qi", 5000000);
	set("max_qi", 5000000);
	set("jing", 5000000);
	set("max_jing", 5000000);
	set("neili", 5000000);
	set("max_neili", 5000000);
	set("jiali",300);
	set("5zhuan",1);
	set("zhuanfinal/1",1);
	set("zhuanfinal/2",1);	
	set("zhuanfinal/3",1);	
	set("zhuanfinal/4",1);	
	set("zhuanfinal/5",1);	
	set("zhuanfinal/7",1);

	set("family/family_name","五毒教");
		
	set_temp("apply/attack", 500);
	set_temp("apply/damage", 92000);
	set_temp("apply/armor", 92000);
	set_temp("apply/defence",500);

	lev = 1800 + random(500);

	set_skill("force",lev);
	set_skill("wudu-shengong",lev);
	set_skill("dodge",lev);
	set_skill("parry",lev);
	set_skill("sword",lev);
	set_skill("wudu-yanluobu",lev);
	set_skill("qianzhu-wandushou",lev);
	set_skill("poison",300);
	set_skill("literate",300);
	set_skill("unarmed",lev);
	set_skill("duji",300);
	set_skill("strike",lev);
	set_skill("yinyang-shiertian", lev);
	set_skill("tianrenheyi", lev);
	set_skill("shedu-qiqiao",lev);
	set_skill("chilian-shenzhang",lev);
	set_skill("jueqing-bian",lev);
	set_skill("ruanhong-zhusuo",lev);
	set_skill("dusha-zhang",lev);
	set_skill("lansha-shou",lev);

	map_skill("strike", "yinyang-shiertian");
	prepare_skill("strike", "yinyang-shiertian");
	map_skill("force", "wudu-shengong");
	map_skill("dodge", "wudu-yanluobu");
	map_skill("unarmed", "qianzhu-wandushou");
	map_skill("parry", "yinyang-shiertian");
	
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
			(: perform_action, "unarmed.qzwd" :),
			(: perform_action, "unarmed.qzwd" :),
			(: perform_action, "strike.xuan" :),
	        (: boss_attack :),
	        (: boss_attack :),
	}));
	
	// 物品奖励
	set("bonus", random(200000)+9000);
	set("killer_reward", ([
		"FI&/clone/box/gbox"   :   10000,
		"RI&40"   :   5000,
		"GE&6"   :  5000,
		"KS&9"   :   5000,
		"BL&9"   :  5000,
		"RI&60"   :   5000,
		"GE&7"   :  5000,
		"JD&6"   :  5000,
		"YC&4"   :  5000,
		"WG&4"   :  5000,
		"KS&9"   :  1000,
		"BL&9"   :  1000,
		"YW&5"   :  1000,
		"YA&5"   :  1000,
		"TW&300"   :  2000,
		"TA&300"   :  2000,
    "TZ&0"   :  800,
    "TZ&1"   :  500,
    "TZ&2"   :  300,	
	]));
	
	setup();
	carry_object("/clone/money/gold")->set_amount(30+random(800));
	carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
	object me, ob;
	::init();
	if (! interactive(me = this_player()))
	        return;
	if( !me->is_character() || me==this_object() || !me) return;
	if(me->query("vendetta/authority")) return;
	if(!userp(me)) return;
	
	remove_call_out("kill_ob");
	call_out("kill_ob", 0, me);
}

varargs void start_busy(mixed new_busy, mixed new_interrupt)
{
        return;
}

int boss_attack()
{
	if (this_object()->is_busy()) return 1;
	if (!this_object()->is_busy()) this_object()->start_busy(2);
	message_vision(HIB "$N" HIR "身躯突然膨胀，化为一个长满触角的肉球，血球中间张开一条缝，便是帝鸿兽身的血盆大口了，似乎要将人吞吃下去！！ \n" NOR, this_object());
	
	remove_call_out("hurting");
	call_out("hurting", 1);
	return 1;
}

int hurting()
{
        int dam, i , num;
        object *inv;
                               
        inv = all_inventory(environment(this_object()));        
        num = sizeof(inv);       
        for (i=sizeof(inv)-1; i>=0; i--)
		if (living(inv[i]) && inv[i] != this_object() && inv[i]->is_fighting(this_object())) num++;
	if (num < 1) num = 1;
	if (num > 5) num = 5;
        
        dam = 40000 / num;

        for (i=sizeof(inv)-1; i>=0; i--)
        {
                if (living(inv[i]) && inv[i] != this_object() && inv[i]->is_fighting(this_object()))
                {                        
	                dam -= inv[i]->query_temp("apply/reduce_damage");
	                if (dam <0) dam = 0;
	                inv[i]->receive_damage("qi", dam);
	                inv[i]->receive_damage("jing", dam/3);
	                inv[i]->receive_wound("qi", dam);
	                inv[i]->receive_wound("jing", dam/3);
	                inv[i]->apply_condition("new_poison7", 8 );
					inv[i]->apply_condition("snake_poison", 50 );
					inv[i]->apply_condition("wugong_poison",  50 );
					inv[i]->apply_condition("zhizhu_poison", 50 );
					inv[i]->apply_condition("xiezi_poison",  50 );
					inv[i]->apply_condition("chanchu_poison",  50 );

                   	COMBAT_D->report_status(inv[i], 1);
                }
        }

		message_vision(HIY "$N" HIR "急速旋转，霎时间又恢复人形！！ \n" NOR, this_object());
        return 1;
}


mixed hit_ob(object me, object ob, int damage_bouns)
{
	if (random(5)==0)
	{
		if (!ob->is_busy()) ob->start_busy(3);	
		if (me->query("qi") <= me->query("max_qi")*2) me->add("qi",random(5000));
		if (me->query("eff_qi") <= me->query("max_qi")*2) me->add("eff_qi",random(5000));
		 return HIG "$N使出五毒神功！舔了舔$n流出的鲜血，全身的伤好像好了很多！!\n";
	}
	return 0;
}