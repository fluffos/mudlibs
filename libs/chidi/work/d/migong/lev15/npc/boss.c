// migong lev15

#include <ansi.h>

inherit NPC;


void create()

{
    
   set_name(HIR"千年火龙王"NOR, ({ "huo long" , "long" , "dragon" }));
                set("race", "野兽");
       set("long",
"一条巨大的龙，嘴里喷着火，看到了你，向你扑了过来。
它充斥着这整个洞穴，你顿觉空气的压抑，觉得它十分地可怕
。\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);

set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" , "claw"}) );
	       set("qi",159999);
	       set("eff_qi",159999);
	       set("max_qi",159999);
set("jing",209999);
  set("eff_jing",159999);
  set("max_jing",209999);
set("neili",209999);
  set("max_neili",209999);
  set("max_sen",109999);
  set("max_mana",109999);
  
      set("dex",150);
      set("con",150);
      set("int",150);
     set("str" ,150);
       set("no_get",1);
    set("age", 999);

       set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);

        set("combat_exp", 20000000);
            set_temp("apply/attack", 500);
        set_temp("apply/damage", 400);
        set_temp("apply/armor", 800);
        set_temp("apply/defence",500);
      set_skill("dodge", 800);
      set_skill("force", 800);
      set_skill("unarmed", 700);
      set_skill("dragon", 700);
      set_skill("spells",700);
     set_skill("magic-old",700);
      map_skill("unarmed", "dragon");

      map_skill("dodge", "dragon");
      map_skill("spells", "magic-old");
    prepare_skill("unarmed", "dragon");
 set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
    (: perform_action, "unarmed.penhuo" :),
    (: perform_action, "unarmed.tuwu" :),
    (: perform_action, "unarmed.yaoyao" :),
    (: perform_action, "spells.magic1" :),
    (: perform_action, "spells.magic2" :),
    (: perform_action, "spells.magic3" :),
    (: perform_action, "spells.magic4" :),
    (: perform_action, "spells.magic5" :),
    (: perform_action, "spells.magic6" :),
    (: perform_action, "spells.magic7" :),

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
        call_out("check",0);
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

if (!killer) return;
        if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
                corpse->move(environment());
if (random(10) < 1)
{
             jla=new("/clone/gem/gem");
             message_vision("$N得到一颗亮晶晶的宝石。\n",killer);
             command("rumor "+killer->query("name")+"得到一颗"+jla->query("name")+"!"NOR"。\n");
             jla->move(killer);
}

        if (userp(killer) && !environment(this_object())->query("already"))
        {
             jla=new("/clone/gem/robe");
             message_vision("$N得到一件魔法师袍。\n",killer);
             command("rumor "+killer->query("name")+"得到一件"+jla->query("name")+"!"NOR"。\n");
             jla->move(killer);
             jla=new("/clone/gem/ring"+random(10));
             message_vision("$N得到一个魔法戒指。\n",killer);
             command("rumor "+killer->query("name")+"得到一个"+jla->query("name")+"!"NOR"。\n");
             jla->move(killer);
             jla=new("/clone/gem/gem");
             message_vision("$N得到一颗亮晶晶的宝石。\n",killer);
             command("rumor "+killer->query("name")+"得到一颗"+jla->query("name")+"!"NOR"。\n");
             jla->move(killer);
             jla=new("/clone/gem/gem");
             message_vision("$N得到一颗亮晶晶的宝石。\n",killer);
             command("rumor "+killer->query("name")+"得到一颗"+jla->query("name")+"!"NOR"。\n");
             jla->move(killer);
             jla=new("/clone/gem/gem");
             message_vision("$N得到一颗亮晶晶的宝石。\n",killer);
             command("rumor "+killer->query("name")+"得到一颗"+jla->query("name")+"!"NOR"。\n");
             jla->move(killer);

             message_vision("$N得到一件千年火龙甲。\n",killer);
             command("rumor "+killer->query("name")+"得到一件"HIR"千年火龙甲"NOR"。\n");
             jla=new("/d/migong/obj/jia3");
             jla->move(killer);

              message_vision("$N得到一颗千年火龙丹。\n",killer);
             command("rumor "+killer->query("name")+"得到一颗"HIR"千年火龙丹"NOR"。\n");
             jlb=new("/d/migong/obj/dan4");
             jlb->move(killer);
            
             }
environment(this_object())->set("already",1);
        this_object()->remove_all_killer();
        all_inventory(environment())->remove_killer(this_object());

        this_object()->dismiss_team();
        destruct(this_object());
}
void check()
{
        object ob=this_object();
        object me=this_player();
    
     if (!ob)
     {
     remove_call_out("check");
     return;
     }

     if (!me)
     {
     remove_call_out("check");
     return;
     }


     if(! present(me,environment()) )
     {
     remove_call_out("check");
     return;
     }
     if( me->is_ghost() )
     {
     remove_call_out("check");
     return;
     }
     
if (ob->is_busy() && ob->is_fighting())
{
        message_vision(HIW"$N"HIW"身上圣光一闪，又恢复了行动！\n",ob,me);
        ob->interrupt_me();
        ob->start_busy(1);
        ob->start_busy(0);
}
        remove_call_out("check");
        call_out("check",1+random(3));
}
int hit_ob(object me, object ob, int damage)
{
	ob->apply_condition("wugong_poison", 40);
        ob->apply_condition("chanchu_poison", 40);
        ob->apply_condition("xiezi_poison", 40);
        ob->apply_condition("snake_poison", 40);
        ob->apply_condition("zhizhu_poison", 40);
        tell_object(ob, HIG "你觉得被咬中的地方一阵麻痒！\n" NOR );
}
