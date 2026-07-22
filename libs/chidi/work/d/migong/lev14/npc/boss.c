// migong lev14

#include <ansi.h>

inherit NPC;


void create()

{
    
   set_name(HIR"大火龙"NOR, ({ "huo long" , "long" , "dragon" }));
                set("race", "野兽");
       set("long",
"一条巨大的龙，嘴里喷着火，看到了你，向你扑了过来。
它充斥着这整个洞穴，你顿觉空气的压抑，觉得它十分地可怕
。\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);

set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" , "claw"}) );
	       set("max_qi",30000+random(20000));
  set("max_jing",30000+random(20000));
  set("max_sen",30000+random(20000));
  set("max_mana",30000+random(20000));
  
      set("dex",100);
      set("con",100);
     set("str" ,100);
       
    set("age", 150);

       set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);

        set("combat_exp", 11000000+random(2000000));
            set_temp("apply/attack", 500);
        set_temp("apply/damage", 500);
        set_temp("apply/armor", 500);
        set_temp("apply/defence",500);
      set_skill("dodge", 600+random(100));

      set_skill("unarmed", 600+random(100));

       set_skill("dragon", 600+random(100));

      map_skill("unarmed", "dragon");

      map_skill("dodge", "dragon");

    prepare_skill("unarmed", "dragon");
 set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
               
    (: perform_action, "unarmed.penhuo" :),
    (: perform_action, "unarmed.tuwu" :),
    (: perform_action, "unarmed.yaoyao" :),
 }) );
     
   setup();

        

}

void init( )

{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
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
        object corpse, killer;
        int i;
        string skill;
        object jla , jlb;

        if( !living(this_object()) ) revive(1);
        if( wizardp(this_object()) && query("env/immortal") ) return;

        this_object()->clear_condition();

        COMBAT_D->announce(this_object(), "dead");
        if( objectp(killer = query_temp("last_damage_from")) ) {
                set_temp("my_killer", killer->query("id"));
                COMBAT_D->killer_reward(killer, this_object());
        }

        if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
                corpse->move(environment());

        if (userp(killer) && (int)killer->query("combat_exp") < 1200000)
        {
if (random(15) < 1)
{
             jla=new("/clone/gem/gem");
             message_vision("$N得到一颗亮晶晶的宝石。\n",killer);
             command("rumor "+killer->query("name")+"得到一颗"+jla->query("name")+"!"NOR"。\n");
             jla->move(killer);
}
             message_vision("$N得到一件火龙丹。\n",killer);
             command("rumor "+killer->query("name")+"得到一件"HIR"火龙丹"NOR"。\n");
             jla=new("/d/migong/obj/dan3");
             jla->move(killer);

               }

        this_object()->remove_all_killer();
        all_inventory(environment())->remove_killer(this_object());

        this_object()->dismiss_team();
        destruct(this_object());
}
