// migong lev9 boss

#include <ansi.h>

inherit NPC;


void create()
{

        set_name(WHT"机关人"NOR, ({ "jiguan ren" , "ren" }));

set("title", HIG"巧夺天功"NOR);
   set("gender", "男性" );
 set("long",
"一具结实而又精致的机关人。\n");
         set("force_factor",100+random(200));
  set("max_qi",999999+random(99999));
  set("max_jing",99999+random(99999));
  set("max_sen",99999+random(99999));
  set("max_neili",99999+random(99999));
  set("max_mana",99999+random(99999));
  set("eff_neili",9999+random(9999));
  set("neili",9999+random(9999));
        set("per", 1);
        set("age", 32);
set("no_get",1);
       set("str" , 100);
       set("jiali" , 100);
        set("shen", -10000);

        set("combat_exp", 4500000+random(1200000));
                 set_skill("unarmed", 330+random(50));

 set_skill("taixuan-gong", 530+random(50));

set_skill("force", 530+random(50));
set_skill("parry", 530+random(50));

set_skill("dodge", 530+random(50));


        map_skill("unarmed", "taixuan-gong");

      map_skill("parry", "taixuan-gong");

 map_skill("force", "taixuan-gong");

 map_skill("dodge", "taixuan-gong");

prepare_skill("unarmed", "taixuan-gong");
set("chat_chance_combat", 90);
        set("chat_msg_combat", ({

         //(: exert_function, "recover" :),
	    }) );
            set_temp("apply/attack", 200);
        set_temp("apply/defense", 400);

          set_temp("apply/armor", 500);
        set_temp("apply/damage", 600);


        setup();

        carry_object("/d/migong/obj/cloth")->wear();



}
void unconcious()
{
    die();
}

void die()
{
        object ob, me, corpse,obj;
   int maxpot;
   int exp,pot,score,i;
        ob = this_object();
 //       me = query_temp("last_damage_from");
        me=  this_object()->query_last_damage_from();
        if (!me) return;
             me->add("score",1000);
        me->add("shen",1000);

        message_vision(WHT"$N被打烂了!!。\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));me->add("combat_exp",random(12));me->add("potential",random(8));
if (me->query("migong/lev9"))
{
if( !environment(me)->query("no_fight")
&& random(4)==1)
{
obj=new("/d/migong/obj/npct");
maxpot=me->query_temp("maxpot")+10;
obj->do_copy(me,maxpot,2);
obj->set("usename",me->query("name"));
obj->move(environment(me));
message_vision(HIY"$N狂笑道：让你见识是一下武术的真髓! !\n"NOR, obj);
me->start_busy(3);
me->kill_ob(obj);
obj->kill_ob(me);
}

}

if (!me->query("migong/lev9"))
{
me->set("migong/lev9",1);
message("channel:chat", HIM"【江湖谣言】听说"+me->name() + "完成了迷宫第九层!"NOR"。\n", users());
exp = 370000+random(25000);
pot = exp/2;
score = random(300)+550;
             me->add("combat_exp",exp);
             me->add("potential",pot);
             me->add("score",score);
tell_object(me,HIW"你被奖励了：\n" +
             chinese_number(exp) + "点实战修为\n"+
             chinese_number(pot) + "点潜能\n" +
            chinese_number(score)+"点江湖阅历\n"NOR);


}
        if((int)me->query("combat_exp") < 600000)   {
        message("vision", me->name() + "为江湖除害,增加了4000修为和2000潜能。\n", me);
        me->add("combat_exp",4000);
        me->add("potential",2000);
        destruct(ob);
        }
        destruct(ob);
        return;
}
