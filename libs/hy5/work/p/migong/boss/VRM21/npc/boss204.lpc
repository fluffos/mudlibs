#include <ansi.h>

inherit BOSS;
int boss_attack();

void create()
{
	int lev;
	set_name( HIB "魔帝蚩尤" NOR, ({ "modi chiyou", "chiyou", "boss" }) );
	set("long", HIB "魔帝蚩尤，传说中蚩尤与黄帝大战，兵败被杀，没想到居然没死，而是隐匿于此，修行苦练。"
	"以图打败黄帝，东山再起，谁曾想光阴似箭，刹那芳华，黄帝早已不在，唯有炎黄子孙生生不息。\n"NOR);
	set("title",  HIB"黑暗魔君"NOR);
	set("gender",  "男性");
	set("age", 3000);
	set("no_get", 1);
	set("shen_type", -1);
	set("attitude", "aggressive");
	
	set("dex",200);
	set("con",200);
	set("int",200);
	set("str",200);
	set("vendetta/authority",1);
	set("combat_exp", 250000000);
	set("level", 21);
	set("qi", 4000000);
	set("max_qi", 4000000);
	set("jing", 4000000);
	set("max_jing", 4000000);
	set("neili", 3000000);
	set("max_neili", 3000000);
	set("jiali",300);
	set("5zhuan",1);
	set("zhuanfinal/1",1);
	set("zhuanfinal/2",1);	
	set("zhuanfinal/3",1);	
	set("zhuanfinal/4",1);	
	set("zhuanfinal/5",1);	
	set("zhuanfinal/7",1);
		
	set("chat_chance", 5);
	set("chat_msg", ({
	        HIR "魔帝蚩尤恶狠狠的盯着你说：炎黄子孙？也好，找不到黄帝老儿，那你们开刀！\n" NOR,
	}));
	
	set_temp("apply/attack", 200);
	set_temp("apply/damage", 7200);
	set_temp("apply/armor", 7000);
	set_temp("apply/defence",200);

	lev = 1500 + random(500);

	set_skill("force",lev);
	set_skill("dodge",lev);
	set_skill("parry",lev);
	set_skill("unarmed",lev);
	set_skill("strike",lev);
	set_skill("yinyang-shiertian", lev);
	set_skill("tianrenheyi", lev);


	map_skill("strike", "yinyang-shiertian");
	prepare_skill("strike", "yinyang-shiertian");
	map_skill("force", "yinyang-shiertian");
	map_skill("dodge", "tianrenheyi");
	map_skill("unarmed", "yinyang-shiertian");
	map_skill("parry", "yinyang-shiertian");
	
	set("chat_chance_combat", 95);
	set("chat_msg_combat", ({
			(: perform_action, "strike.bo" :),
			(: perform_action, "strike.jue" :),
			(: perform_action, "strike.lu" :),
			(: perform_action, "strike.mie" :),
			(: perform_action, "strike.xuan" :),
			(: perform_action, "strike.zhuan" :),
			(: perform_action, "strike.zhu" :),
	        (: boss_attack :),
	        (: boss_attack :),
	        (: boss_attack :),
	}));
	
	// 物品奖励
	set("bonus", random(200000)+5000);
	set("killer_reward", ([
		"FI&/clone/box/gbox"   :   10000,
		"RI&60"   :   6000,
		"GE&6"   :  6000,
		"KS&9"   :   6000,
		"BL&8"   :  6000,
		"RI&60"   :   6000,
		"GE&6"   :  6000,
		"JD&6"   :  6000,
		"YC&4"   :  6000,
		"WG&4"   :  6000,
		"KS&7"   :  6000,
		"BL&8"   :  6000,
		"YW&5"   :  6000,
		"YA&5"   :  6000,
		"TW&300"   :  6000,
		"TA&300"   :  6000,
    "TZ&0"   :  2800,
    "TZ&1"   :  2400,
    "TZ&2"   :  2300,	
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
	message_vision(HIB "$N" HIR "大喝一声，五行真气汇聚一身，又破体而出，形成五色起浪，朝外翻涌推送，竟然练成了【五气龙兵】！！ \n" NOR, this_object());
	
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
        
        dam = 35000 / num;

        for (i=sizeof(inv)-1; i>=0; i--)
        {
                if (living(inv[i]) && inv[i] != this_object() && inv[i]->is_fighting(this_object()))
                {                        
	                dam -= inv[i]->query_temp("apply/reduce_damage");
	                if (dam <0) dam = 0;
	                inv[i]->apply_condition("new_poison3", 8 );
	                inv[i]->apply_condition("new_poison4", 8 );
	                inv[i]->receive_damage("qi", dam);
	                inv[i]->receive_damage("jing", dam/3);
	                inv[i]->receive_wound("qi", dam);
	                inv[i]->receive_wound("jing", dam/3);
                   	COMBAT_D->report_status(inv[i], 1);
                }
        }

        return 1;
}