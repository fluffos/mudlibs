// migong lev2

#include <ansi.h>

inherit NPC;


void create()

{

    set_name(RED"杀手楼主"NOR, ({ "boss killer", "killer" }));

     set("gender", "男性" );
      set("long",
"一个杀手楼的楼主。\n");
        set("attitude", "aggressive");

  set("vendetta/authority",1);

 set("force_factor",10+random(100));

 set("max_qi",26900+random(3900));

 set("max_jing",26900+random(3900));

 set("max_sen",26900+random(3900));

 set("max_neili",16900+random(3900));

 set("max_mana",26900+random(3900));

 set("eff_neili",19900+random(3900));

 set("neili",19900+random(3900));
set("no_get",1);
   set("per", 1);

   set("age", 22);

    set("shen", -5000);

     set("intellgent",1);

   set("pursuer",1);

  set("combat_exp", 1000000);


  set_skill("unarmed", 300);

  set_skill("sword", 300);

  set_skill("parry", 300);

   set_skill("dodge", 300);

  set_skill("force", 300);
	set_skill("hunyuan-yiqi", 185);
	set_skill("shaolin-shenfa", 185);
	set_skill("finger", 190);
	set_skill("nianhua-zhi", 190);
	set_skill("buddhism", 185);
	set_skill("literate", 185);

set_skill("jingang-quan", 185);
	set_skill("damo-jian", 185);
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("parry", "nianhua-zhi");
       map_skill("sword", "damo-jian");
   map_skill("unarmed", "jingang-quan");
	set_skill("shiren-jianfa", 200);
	set_skill("shiren-quanfa", 200);
	set_skill("wuxing-dun", 200);
	map_skill("unarmed", "shiren-quanfa");
	map_skill("parry", "shiren-jianfa");
	map_skill("blade", "shiren-jianfa");
	map_skill("dodge", "wuxing-dun");
   set_temp("apply/attack", 100);

  set_temp("ap5ly/defense", 100);

   set_temp("apply/armor", 100);

  set_temp("apply/damage", 100);


 setup();


 carry_object("/d/migong/obj/cloth")->wear();

//   carry_object("/quest/weiguo/japan/obj/japanblade")->wield();

add_money("gold", 2);

}

void init( )
{
	object ob;
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(3);
        call_out("hunting",1);
        }
	if(!environment()->query("no_fight"))
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
        //me = query_temp("last_damage_from");
     //           me = this_player();
                me=  this_object()->query_last_damage_from();
if (!me) return;
              me->add("score",1);
        message_vision(WHT"$N啪的一声瘫倒在地上。\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));me->add("combat_exp",random(12));me->add("potential",random(8));


if (!me->query("migong/lev4"))
{
me->set("migong/lev4",1);
message("channel:chat", HIM"【江湖谣言】听说"+me->name() + "完成了迷宫第四层!"NOR"。\n", users());
exp = 190000+random(25000);
pot = exp/2;
score = random(300)+250;
             me->add("combat_exp",exp);
             me->add("potential",pot);
             me->add("score",score);
tell_object(me,HIW"你被奖励了：\n" +
             chinese_number(exp) + "点实战修为\n"+
             chinese_number(pot) + "点潜能\n" +
            chinese_number(score)+"点江湖阅历\n"NOR);

}
        if((int)me->query("combat_exp") < 200000)   {
        message("vision", me->name() + "成功打死杀手楼主增加了400修为和200潜能。\n", me);
        me->add("combat_exp",4000);
        me->add("potential",2000);
        destruct(ob);
        }
               destruct(ob);
        return;
}


