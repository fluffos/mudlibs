// migong lev14

#include <ansi.h>

inherit NPC;


void create()

{

   set_name(HIR"红龙"NOR, ({ "hong long" , "long" , "dragon" }));
                set("race", "野兽");
       set("long",
"一条巨大的红色的龙，看到了你，向你扑了过来。
。\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);

set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" , "claw"}) );
	       set("max_qi",20000+random(10000));
  set("max_jing",20000+random(10000));
  set("max_sen",20000+random(10000));
  set("max_mana",20000+random(10000));

      set("dex",50);
      set("con",50);
     set("str" ,50);

    set("age", 80);

       set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);

        set("combat_exp", 8000000+random(2000000));
            set_temp("apply/attack", 100);
        set_temp("apply/damage", 100);
        set_temp("apply/armor", 100);
        set_temp("apply/defence",100);
      set_skill("dodge", 400+random(100));

      set_skill("unarmed", 400+random(100));

       set_skill("dragon", 400+random(100));

      map_skill("unarmed", "dragon");

      map_skill("dodge", "dragon");

    prepare_skill("unarmed", "dragon");
 set("chat_chance_combat", 60);
        set("chat_msg_combat", ({

    (: perform_action, "unarmed.penhuo" :),

 }) );
           set("chat_chance", 20);
        set("chat_msg", ({
		(: command("get silver") :),
		(: command("get coin") :),
                (: random_move :),
           }) );

   setup();


carry_object("/d/migong/obj/longdan");


}

void init( )

{
	object ob;
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(1);
        call_out("hunting",1);
        }
	if(!environment()->query("no_fight") && random(10) < 5)
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
        object ob, me, corpse;

        ob = this_object();
 //       me = query_temp("last_damage_from");
        me=  this_object()->query_last_damage_from();
        if (!me) return;
              me->add("score",1);
        message_vision(WHT"$N一声怒吼，浑身鲜血直流，缓缓躺倒在地。\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));me->add("combat_exp",random(12));me->add("potential",random(8));
        if((int)me->query("combat_exp") > 700000)   {
        message("vision", me->name() + "为江湖除害,增加了1200修为和600潜能。\n", me);
        me->add("combat_exp",1200);
        me->add("potential",600);
        destruct(ob);
        }
               destruct(ob);
        return;
}


