// migong lev2

#include <ansi.h>

inherit NPC;


void create()

{

    set_name(HIR"山贼王"NOR, ({ "boss zei", "zei" }));

     set("gender", "男性" );
      set("long",
"一个抢家劫舍的恶棍大王。\n");
        set("attitude", "aggressive");

  set("vendetta/authority",1);

 set("force_factor",10+random(100));

 set("max_qi",24900+random(3900));

 set("max_jing",24900+random(3900));

 set("max_sen",24900+random(3900));

 set("max_neili",24900+random(3900));

 set("max_mana",24900+random(3900));
 set("no_get",1);
 set("eff_neili",9900+random(3900));

 set("neili",29900+random(3900));

   set("per", 1);

   set("age", 22);
     set("dex", 100);
    set("str", 100);
    set("shen", -5000);

     set("intellgent",1);

   set("pursuer",1);

  set("combat_exp", 1000000);


  set_skill("unarmed", 300);

  set_skill("sword", 300);

  set_skill("parry", 300);

   set_skill("dodge", 300);

  set_skill("force", 300);

   set_temp("apply/attack", 100);

  set_temp("ap5ly/defense", 100);

   set_temp("apply/armor", 100);

  set_temp("apply/damage", 300);


 setup();


 carry_object("/d/migong/obj/cloth")->wear();

   carry_object("/d/migong/obj/sword")->wield();

add_money("gold", 2);

}

void init( )
{
	object ob;
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(3);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight"))
        call_out("hunting",0);
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
void unconcious()
{
    die();
}
void die()
{
        object ob, me, corpse,obj;
        int exp,pot,score,i;
        int maxpot;
        ob = this_object();
       // me = query_temp("last_damage_from");
             //   me = this_player();
                me=  this_object()->query_last_damage_from();
if (!me) return;
              me->add("score",1);
        message_vision(WHT"$N啪的一声瘫倒在地上。\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));me->add("combat_exp",random(12));me->add("potential",random(8));me->add("combat_exp",random(12));me->add("potential",random(8));


if (!me->query("migong/lev2"))
{
me->set("migong/lev2",1);
message("channel:chat", HIM"【江湖谣言】听说"+me->name() + "完成了迷宫第二层!"NOR"。\n", users());
exp = 100000+random(25000);
pot = exp/2;
score = random(300)+100;
             me->add("combat_exp",exp);
             me->add("potential",pot);
             me->add("score",score);
tell_object(me,HIW"你被奖励了：\n" +
             chinese_number(exp) + "点实战修为\n"+
             chinese_number(pot) + "点潜能\n" +
            chinese_number(score)+"点江湖阅历\n"NOR);

}
        if((int)me->query("combat_exp") < 1500000)   {
        message("vision", me->name() + "成功打死山贼王增加了4000修为和2000潜能。\n", me);
        me->add("combat_exp",4000);
        me->add("potential",2000);
        destruct(ob);
        }
               destruct(ob);
        return;
}


