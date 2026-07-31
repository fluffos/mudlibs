#include <ansi.h>
inherit NPC;

void create()
{
    set_name("蒙古兵", ({ "menggubing", "bing" }));
    set("gender", "男性" );//性别与上面对应
        set("long",
"一个身高大但满脸又是伤疤加横肉的蒙古兵。\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
	set("nickname",HIC"蒙古精兵"NOR);
  set("force_factor",2+random(190));
  set("max_qi",1500+random(390));
  set("max_jing",1500+random(390));
  set("max_sen",1500+random(390));
  set("max_neili",1500+random(390));
  set("eff_neili",1500+random(390));
  set("neili",2500+random(390));
  set("max_mana",2500+random(390));
        set("per", 21);
        set("age", 22);
        set("shen", -1000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 350000+random(150000));
	set("bellicosity", 10000);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.kuang" :),
                (: perform_action, "blade.leitingpili" :),
		            (: random_move :),
        }) );
        set("chat_chance", 20);
        set("chat_msg", ({
                "蒙古兵喝道：杀啊的！！\n",
                "蒙古兵笑道：这次一定要消灭南蛮!\n",
                (: random_move :),
        }) );

        set_skill("force", 150+random(100));
        set_skill("unarmed", 50+random(100));
        set_skill("blade", 50+random(100));
        set_skill("parry", 150+random(100));
        set_skill("dodge", 90+random(100));
        set_skill("kuang-blade", 290+random(100));
        
        map_skill("blade", "kuang-blade");
        map_skill("parry", "kuang-blade");
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 60);
        set_temp("apply/armor", 120);
        set_temp("apply/damage", 20);
if (random(20)>15)
{
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 200);
}

        setup();

        carry_object(__DIR__"obj/japancloth")->wear();
        carry_object(__DIR__"obj/japanblade")->wield();
	add_money("silver", random(50));
}
void init( )
{
        call_out("hunting",180);
}

void hunting()
{
object ob=this_object();
write(HIW"只听，城外三声令响!蒙古兵撒出了襄阳!\n"NOR);
destruct(ob);
}

void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
        
if (me)
{
        message_vision(WHT"$N大叫一声,大汉万岁!!倒地而亡。\n"NOR,ob,me);
//        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
//        corpse->move(environment(this_object()));
        if((int)me->query("combat_exp") < 600000)   {
        message("vision", me->name() + "由于成功的保卫了襄阳,增加了200修为和100潜能。\n", me);
        me->add("combat_exp",200);
        me->add("potential",100);
        destruct(ob);
        }
        me->add("score",2);
        me->add("shen",10);
}
        destruct(ob);
        return;
}
