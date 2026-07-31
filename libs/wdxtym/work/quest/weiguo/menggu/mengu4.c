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
    set_name(nm1_jp[i]+nm2_jp[random(sizeof(nm2_jp))], ({"yuanshuai"}));
    set("gender", "男性" );//性别与上面对应
//        set_name("东洋倭寇", ({ "wokou", "japan wokou" }) );
        set("long",
"一个身高大但满脸又是伤疤加横肉的蒙古人。\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
	set("nickname",HIR"蒙古特务"NOR);
  set("force_factor",2+random(390));
  set("max_qi",300+random(1690));
  set("max_jing",300+random(1890));
  set("max_sen",300+random(1890));
  set("max_neili",300+random(1890));
  set("max_mana",300+random(1890));
  set("eff_neili",300+random(1390));
  set("neili",300+random(1390));
        set("per", 28);
        set("age", 22);
        set("shen", -10000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 400000+random(900000));
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),
                (: random_move :),
        }) );
        set("chat_chance", 60);
        set("chat_msg", ({
                (: random_move :),
        }) );

        set_skill("unarmed", 80+random(180));
        set_skill("blade", 80+random(180));
        set_skill("parry", 80+random(180));
        set_skill("dodge", 180+random(180));
      //  set_skill("kuang-blade", 80+random(180));

        map_skill("blade", "kuang-blade");
        map_skill("parry", "kuang-blade");
        set_temp("apply/attack", 20);
        set_temp("apply/defense",50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 20);

        setup();

        carry_object(__DIR__"obj/japancloth")->wear();
        carry_object(__DIR__"obj/japanblade")->wield();
	add_money("silver", random(50));
}
void init( )
{
	object ob;
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
        call_out("hunting",1);
        }
	if(!environment()->query("no_fight") && random(100) < 1)
        call_out("hunting",1);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}

void die()
{
        object ob, me, corpse, obn;

        ob = this_object();
        me = query_temp("last_damage_from");

        message_vision(WHT"$N大叫一声,大汉万岁!!倒地而亡。\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
        message("vision", me->name() + "从蒙古特务身上发现了大量的银两。\n", me);
        message("vision", me->name() + "由于成功的保卫了祖国,增加了2000修为和1000潜能。\n", me);
        me->add("combat_exp",2000);
        me->add("potential",1000);
        obn=new("/clone/money/gold");
        obn->set_amount(random(10));
        obn->move(me);
        me->add("score",50);
        destruct(ob);
        return;
}
