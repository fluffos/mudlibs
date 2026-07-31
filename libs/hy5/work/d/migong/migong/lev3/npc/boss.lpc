// migong lev2

#include <ansi.h>

inherit NPC;


void create()

{
    
    set_name(HIY"采花淫僧"NOR, ({ "boss hua", "hua" }));
    
     set("gender", "男性" );
      set("long",
"一个采花无数的采花淫僧。\n");
        set("attitude", "aggressive");
      
  set("vendetta/authority",1);
	 
 set("force_factor",10+random(100));
 
 set("max_qi",5900+random(3900));
 
 set("max_jing",5900+random(3900));
 
 set("max_sen",5900+random(3900));
 
 set("max_neili",5900+random(3900));
 
 set("max_mana",5900+random(3900));
 
 set("eff_neili",9900+random(3900));
 
 set("neili",9900+random(3900));
        
   set("per", 1);
       
   set("age", 22);
     
    set("shen", -5000);
    set("no_get",1);    
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
   set_temp("apply/attack", 100);
      
  set_temp("ap5ly/defense", 100);
     
   set_temp("apply/armor", 100);
      
  set_temp("apply/damage", 100);

       
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

void die()
{
        object ob, me, corpse,obj;
        int exp,pot,score,i;
        int maxpot;
        ob = this_object();
        me = query_temp("last_damage_from");
if (!me) return;   
              me->add("score",1);
        message_vision(WHT"$N啪的一声瘫倒在地上。\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));me->add("combat_exp",random(12));me->add("potential",random(8));
if (me->query("migong/lev3"))
{
if( !environment(me)->query("no_fight")
&& random(3)==1)
{
		obj = new("/clone/npc/antirobot"+(2+random(2)));
		obj->test_robot(me);
}
else 
{
		obj = new("/clone/npc/antirobot"+(2+random(2)));
		obj->test_robot(me);
}
}

if (!me->query("migong/lev3"))
{
me->set("migong/lev3",1);
message("channel:chat", HIM"【江湖谣言】听说"+me->name() + "完成了迷宫第三层!"NOR"。\n", users());
exp = 150000+random(25000);
pot = exp/2;
score = random(300)+150;
             me->add("combat_exp",exp);
             me->add("potential",pot);
             me->add("score",score);
tell_object(me,HIW"你被奖励了：\n" +
             chinese_number(exp) + "点实战经验\n"+
             chinese_number(pot) + "点潜能\n" +
            chinese_number(score)+"点江湖阅历\n"NOR);
i=random(8);
	if (i==7) {
        if ( me->query("per")< 60)
        {
	me->add("per",1);tell_object(me,HIM"以及一点容貌。\n"NOR);
        }
	}
	else if (i==6) {
        if ( me->query("kar")< 60)
        {
	me->add("kar",1);tell_object(me,HIM"以及一点福缘。\n"NOR);
        }
	}
	else if (i==5) {
        if ( me->query("dex")< 60)
        {
	me->add("dex",1);tell_object(me,HIM"以及一点身法。\n"NOR);
        }
	}
	else if (i==4) {
        if ( me->query("str")< 60)
        {
	me->add("str",1);tell_object(me,HIM"以及一点力量。\n"NOR);
        }
	}
	else if (i==3) {
        if ( me->query("per")< 60)
        {
	me->add("per",1);tell_object(me,HIM"以及一点容貌。\n"NOR);
        }
	}
	else if (i==2) {
        if ( me->query("kar")< 60)
        {
	me->add("kar",1);tell_object(me,HIM"以及一点福缘。\n"NOR);
        }
	}
	else if (i==1) {
        if ( me->query("con")< 60)
        {
	me->add("con",1);tell_object(me,HIM"以及一点根骨。\n"NOR);
        }
	}
	else if (i==0) {
        if ( me->query("int")< 60)
        {
	me->add("int",1);tell_object(me,HIM"以及一点悟性。\n"NOR);
        }
	}
	else if (me->query("per")< 100) {
	me->add("per",1);tell_object(me,HIM"以及一点容貌。\n"NOR);
	}
}
        if((int)me->query("combat_exp") < 1000000)   {
        message("vision", me->name() + "成功打死采花淫僧增加了400经验和200潜能。\n", me);
        me->add("combat_exp",400);
        me->add("potential",200);
        destruct(ob);
        }
               destruct(ob);
        return;
}


