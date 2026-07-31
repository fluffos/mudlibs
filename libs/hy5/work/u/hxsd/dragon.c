// This program is a part of NT mudlib
// boss 模板

#include <ansi.h>

inherit BOSS;

int big_blowing();

void create()
{
        set_name( HIB "镇海神龙" NOR, ({ "sea dragon king", "dragon king", "dragon" }) );
        set("long", HIB "这是一条全身碧绿，吸大海之间的精华而长大"
                    "的神龙！它全身散发着碧绿色的光芒！\n\n" NOR);

        set("race", "野兽");
        set("gender", "雄性");
        set("age", 100);
        set("no_get", 1);
        set("shen_type", 0);
        set("attitude", "aggressive");
        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("dex",100);
        set("con",100);
        set("int",100);
        set("str",100);

        set("combat_exp", 200000);
        set("level", 20);
        set("qi", 1);
        set("max_qi", 1);
        set("jing", 1);
        set("max_jing", 1);
        set("neili", 100);
        set("max_neili", 500000);
        set("neili", 500000);
        set("jiali", 2000);

        set("chat_chance", 5);
        set("chat_msg", ({
                HIB "海底打来一个巨浪！差点把你卷走！\n" NOR,
                HIB "镇海神龙突然吐出一颗湛蓝的珠子，又卷了回去！\n" NOR,
        }));

        set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
                (: big_blowing :),
                (: big_blowing :),	
        }));

        set_temp("apply/attack", 100);
        set_temp("apply/damage", 600);
        set_temp("apply/armor", 600);
        set_temp("apply/defence",100);
      set_skill("dodge", 500);
      set_skill("force", 500);
      set_skill("unarmed", 500);
      set_skill("dragon",550);
      set_skill("spells",550);
     set_skill("magic-old",650);
      map_skill("unarmed", "dragon");

      map_skill("dodge", "dragon");
      map_skill("spells", "magic-old");
      
        set_temp("apply/add_xuruo", 60);
        set_temp("apply/reduce_damage", 80);
        set_temp("apply/reduce_busy", 20);
        set_temp("apply/add_busy", 5);
        
        set("bonus", random(80000)+5000);
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
                "FI&/clone/box/gbox"   :   10000,
                "RI&30"   :   10000,
                "GE&3"   :  10000,
                "JD&3"   :  10000,
                "YC&1"   :  10000,
                "WG&1"   :  10000,
               "KS&3"   :  10000,
                "BL&3"   :  10000,
                "YW&2"   :  10000,
                "YA&2"   :  10000,
                "TW&280"   :  10000,
                "TA&280"   :  10000,
	]));
	
        setup();
        carry_object("/clone/money/gold")->set_amount(20+random(220));
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

int big_blowing()
{
        message_vision(HIB "$N" HIB "从海水里深深地吸入一口气，全身发出耀眼"
                       "的蓝色，整个龙腹胀大了几倍！！\n" NOR, this_object());

        remove_call_out("hurting");
        call_out("hurting", random(2) + 1);
        return 1;
}

int hurting()
{
        int dam, i , num;
        object *inv;
        
        message_vision(HIB "$N" HIB "吐出一股巨大的海浪．．．．．．整个天地似乎都被吞没！！！\n" NOR,
                       this_object());
                       
        inv = all_inventory(environment(this_object()));        

        num = sizeof(inv);       
        if (num < 1) num = 1;
        if (num > 5) num = 5;
        
        dam = 20000 / num;
        
        for (i=sizeof(inv)-1; i>=0; i--)
        {
                if (living(inv[i]) && inv[i] != this_object())
                {
                        dam -= inv[i]->query_temp("apply/reduce_cold");
                        if (dam <0) dam = 0;
                        
                        inv[i]->receive_damage("qi", dam);
                        inv[i]->receive_damage("jing", dam/2);
                        inv[i]->receive_wound("qi", dam);
                        inv[i]->receive_wound("jing", dam/2);
                        COMBAT_D->report_status(inv[i], 1);
                }
        }
        return 1;
}

mixed hit_ob(object me, object ob, int damage_bouns)
{
        int damage;
        int reduce;
        
        damage = 2500 + random(2500);
        reduce = (int)ob->query_temp("apply/reduce_cold");
        damage = damage - damage * reduce / 100;
        if (damage < 0) damage = 0;
        ob->receive_damage("qi", damage);
        ob->receive_wound("qi", damage);
        me->set("neili", me->query("max_neili"));
        return HIB "$N" HIB "“哈”的一声吐出一口寒气，登时令$n"
               HIB "全身几乎冻僵。\n" NOR;
}

