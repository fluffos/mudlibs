#include <ansi.h>
inherit NPC;

string *nm1_jp =({
"金伊账","成吉思","大好山","日不落","金王朝",
});

    
string *nm2_jp =({
"汉",
});

void create()
{
   int i = random(sizeof(nm1_jp));
    set_name(nm1_jp[i]+nm2_jp[random(sizeof(nm2_jp))],({"yuanshuai"}));
    set("gender", "男性" );//性别与上面对应
        set("long",
"一个身高大但满脸又是伤疤加横肉的蒙古人。\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
	set("nickname",HIR"蒙古元师"NOR);
  set("max_qi",5900+random(1890));
  set("max_jing",3900+random(1890));
  set("max_sen",3900+random(1890));
  set("max_neili",3900+random(1890));
  set("max_mana",3900+random(1890));
  set("eff_neili",3900+random(2000));
  set("neili",6500+random(2000));
        set("per", 1);
        set("age", 22);
        set("shen", -10000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 700000+random(900000));
	set("bellicosity", 10000);
	set("chat_chance_combat", 60);  
	set("chat_msg_combat", ({
                (: perform_action, "blade.kuangdao" :),
                (: perform_action, "blade.shendao" :),
                (: perform_action, "blade.kuangdao" :),
                (: perform_action, "blade.shendao" :),
                (: perform_action, "dodge.tianmaxingkong" :),
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.leiting" :),                
                (: exert_function, "fumozhou" :),                
                (: exert_function, "fumozhou" :),                
                (: exert_function, "fanchang" :),                
	}) );

        set("chat_chance", 20);
        set("chat_msg", ({
                "蒙古元师喝道：杀啊的！！\n",
                "蒙古元师笑道：这次一定要消灭南蛮!\n",
                (: random_move :),
        }) );
        
        set_skill("xue-dao", 350+random(180));
        set_skill("unarmed",150+random(180));
        set_skill("xianglong-zhang",250+random(180));
        set_skill("dodge", 150+random(180));
        set_skill("blade", 150+random(180));
        set_skill("parry", 250+random(180));
        set_skill("dashou-yin", 250+random(180));
        set_skill("shenkong-xing", 250+random(180));
        set_skill("longxiang", 250+random(180));
        set_skill("huntian-qigong", 250+random(180));

        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("hand", "dashou-yin");
        map_skill("parry", "xue-dao");
        map_skill("blade", "xue-dao");
        map_skill("sword", "mingwang-jian");
        map_skill("unarmed","xianglong-zhang");
        map_skill("unarmed","xianglong-zhang");
        prepare_skill("unarmed", "xianglong-zhang");

        set_temp("apply/attack", 50);
        set_temp("apply/defense", 80);
        set_temp("apply/armor", 250);
        set_temp("apply/damage", 100);

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
write(HIW"只听，城外三声令响!蒙古元师撒出了襄阳!\n"NOR);
destruct(ob);
}


void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
        

if (me)
{        message_vision(WHT"$N大叫一声,大汉万岁!!倒地而亡。\n"NOR,ob,me);
//        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
//        corpse->move(environment(this_object()));
        if((int)me->query("combat_exp") < 2300000)   {
        message("vision", me->name() + HIG"由于成功的保卫了襄阳,增加了300修为和150潜能。\n"NOR, me);
        me->add("combat_exp",300);
        me->add("potential",150);
        me->add("score",50);
        destruct(ob);
        }
        me->add("score",2);
        me->add("shen",10);
}
        destruct(ob);
        return;
}
