// This program is a part of NT mudlib
// boss 模板

#include <ansi.h>

inherit BOSS;
//inherit  NPC;

int boss_attack();

void create()
{
	set_name( HIB "红云老祖" NOR, ({ "hongyun laozu", "hongyun", "boss" }) );
	set("long", HIB "他就是红云老祖了，红云老祖辛云碧开建红云堡，在红云堡内修真，并"
	"自创红云阵法，厉害非常。\n\n" NOR);
	
	set("gender",  "男性");
	set("age", 60);
	set("no_get", 1);
	set("shen_type", -1);
	set("attitude", "aggressive");
	
	set("dex",150);
	set("con",150);
	set("int",150);
	set("str",150);
	
	set("combat_exp", 10000000);
	set("level", 12);
	set("qi", 660000);
	set("max_qi", 660000);
	set("jing", 660000);
	set("max_jing", 660000);
	set("neili", 300000);
	set("max_neili", 300000);
	set("neili", 300000);
	set("jiali", 500);
	
	set("chat_chance", 5);
	set("chat_msg", ({
	        HIB "红云老祖指着你说，来试试我的红云阵吧！\n" NOR,
	}));
	
	set_temp("apply/attack", 400);
	set_temp("apply/damage", 1400);
	set_temp("apply/armor", 1500);
	set_temp("apply/defence",400);

	set_skill("dodge", 450);
	set_skill("force", 450);
	set_skill("unarmed", 450);
	set_skill("parry", 450); 
	set_skill("sword",450);
	set_skill("sharen-sword",500);
	set_skill("changquan",500);
	set_skill("shadowsteps",500);
	set_skill("cloudforce",500);
	map_skill("force", "cloudforce");
	map_skill("sword", "sharen-sword");
	map_skill("dodge", "shadowsteps");
	map_skill("parry", "changquan");
	map_skill("unarmed", "changquan");

	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
	(: perform_action, "sword.sharenruma" :),
	(: perform_action, "unarmed.yuhuan" :),
	        (: boss_attack :),
	}));
	
    set_temp("apply/reduce_damage", 40);
    set_temp("apply/reduce_busy", 10);
    set_temp("apply/add_busy", 2);
  	set("bonus", random(12000)+1200);
// 物品奖励 说明
// 掉落概率 10000为最大,必掉,5000为1/2机会,数字越小,掉落的可能越少.
// 掉落阵列关键字以 FI 起头表示为掉落某个特定物品
// 掉落阵列关键字以 RI  起头表示为掉落某个戒指 %d为等级(10-60) 
// 掉落阵列关键字以 GE 起头表示为掉落某个宝石 %d为等级(1-8)
// 掉落阵列关键字以 JD 起头表示为掉落某个打造用升级宝石 %d为等级(1-8)
// 掉落阵列关键字以 YC 起头表示为掉落药材 %d为无效参数("随机等级无效)
// 掉落阵列关键字以 WG 起头表示为掉落宝物装备 %d为无效参数
// 掉落阵列关键字以 KS 起头表示为掉落打造用矿石 %d为等级(1-10)
// 掉落阵列关键字以 BL 起头表示为掉落打造用布料 %d为等级(1-10)
// 掉落阵列关键字以 YW 起头表示为掉落打造武器用玉石 %d为等级(1-6)
// 掉落阵列关键字以 YA 起头表示为掉落打造防具用玉石 %d为等级(1-6)
// 掉落阵列关键字以 YW 起头表示为掉落打造武器用玉石 %d为等级(1-6)
// 掉落阵列关键字以 TW 起头表示为掉落打造武器 %d为等级 (0-480)
// 掉落阵列关键字以 TA 起头表示为掉落打造防具 %d为等级(0-480)


	set("killer_reward", ([
                "FI&/clone/box/gbox"   :   5000,
                "RI&10"   :   5000,
                "GE&4"   :  5000,
               "KS&3"   :   3000,
                "BL&3"   :  3000,
                "RI&20"   :   1800,
                "GE&3"   :  1800,
                "JD&4"   :  1800,
                "YC&1"   :  1800,
                "WG&1"   :  1800,
               "KS&5"   :   300,
                "BL&5"   :  300,
                "YW&3"   :  200,
                "YA&3"   :  200,
                "TW&180"   :  600,
                "TA&180"   :  600,
"TZ&0"   :  300,
	]));
	
    setup();
    carry_object("/clone/money/gold")->set_amount(30+random(420));
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/changjian")->wield();
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
	message_vision(HIB "$N" HIR "袍袖一挥，大喝一声：布阵！！ \n" NOR, this_object());
	
	remove_call_out("hurting");
	call_out("hurting", 0);
	return 1;
}

int hurting()
{
        int dam, i , num, busytime;
        object *inv;
        
        message_vision(HIR "红云阵启动，当空幕顶飘落下大片红雨，这片红色光雨，一经散发"
       "而出，立刻形成密如贯珠的一边串巨大雷鸣之声，一团团烈火，击向头顶，险恶无比\n" NOR,
                       this_object());
                       
        inv = all_inventory(environment(this_object()));        

        num = sizeof(inv);       
        if (num < 1) num = 1;
        if (num > 5) num = 5;
        
        dam = 8000 / num;
        busytime = 10 / num;
        
        for (i=sizeof(inv)-1; i>=0; i--)
        {
                if (living(inv[i]) && inv[i] != this_object())
                {                        
                      dam -= inv[i]->query_temp("apply/reduce_damage");
                      if (dam <0) dam = 0;
                      inv[i]->receive_damage("qi", dam);
                      inv[i]->receive_damage("jing", dam/3);
                      inv[i]->receive_wound("qi", dam);
                      inv[i]->receive_wound("jing", dam/3);
                      COMBAT_D->report_status(inv[i], 1);
                      if (!inv[i]->is_busy()) busytime -= inv[i]->query_temp("apply/reduce_busy");
                      if (busytime>0) inv[i]->start_busy(busytime);
                }
        }
        return 1;
}

mixed hit_ob(object me, object ob, int damage_bouns)
{
	int damage;
  	damage = 400 + random(400);
	ob->receive_wound("qi", damage);

	return "$N一拳打中$n的膻中大穴，"HIC "$n" HIC "只觉真气外泄，人也变得昏昏沉沉，快晕倒了！\n" NOR;
}

