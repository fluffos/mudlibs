// qingfengtangzhu.c
//Made by goodtaste
//1999.5.21


#include <ansi.h>

inherit NPC;
int ask_pk();

void create()
{
	seteuid(getuid());
	set_name("柳随风", ({ "liu suifeng", "liu", "suifeng",}) );
	set("title", HIY "黑云堂主" NOR);
        set("long","杀手帮黑云堂堂主，为人老成而有心计\n");
	set("gender", "男性" );
	set("age", 50);
	set("attitude", "peaceful");
	set("str", 20);
	set("con", 30);
	set("int", 27);
	set("dex", 23);
        set("qi",3000);
        set("max_qi", 3000);
        set("jing",3000);
	set("max_jing", 3000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 150);
	set("shen_type", 1);
	set("combat_exp", 1200000);
        set_skill("force", 200); 
	set_skill("sword", 200);
	set_skill("dodge", 200);
        set_skill("parry", 200);
	set_skill("guihun-jian", 100); //待写
	set_skill("chuforce", 300); 
	set_skill("liuyun", 180);
        map_skill("force", "chuforce");
        map_skill("parry", "guihun-jian");
	map_skill("sword", "guihun-jian");
	map_skill("dodge", "liuyun");
	create_family("杀手帮", 1, "长老");
	set("chat_chance", 5);
	set("chat_msg", ({
          "柳随风说道：人算不如天算，唉.....\n",
	}) );
      set("inquiry",([
              "pk" : ( : ask_pk : ),
              "PK" : ( : ask_pk : ),
              "杀手" : ( : ask_pk : ),
                ]));
     	setup();
     carry_object(__DIR__"obj/changjian")->wield();
     carry_object(__DIR__"obj/cloth")->wear();

       //add_money("gold", 3);
       add_money("silver", 30);
}

void init()
{	
	object me,ob;
        me=this_player();
        ob=this_object();

         add_action("decide","will");
         add_action("bihua","bihua");
        if(me->query_temp("killer")) 
         {
             ob->kill_ob(me);
             message_vision(RED"得罪了帮主,"+RANK_D->query_rude(me)+"以为你还跑得掉吗?看招!\n" NOR,me);
         }
}

int ask_pk()
{
   object me=this_player();
   if(me->query("age")<15)
   {say("柳随风喝道：乳臭未干的东西也敢到这里来，爹娘哪里去了!?\n");
    return 1;  }
   if(!(me->query_temp("gold_given")))
   {
       say("柳随风勃然大怒：你这小子是怎么混进来的，你把阿敏她怎么样了!?\n");
       this_object()->kill_ob(this_player());	
       return 1;
    }
   if(me->query_temp("wu_pass")) 
    {
      say("柳随风奇怪的望着你：你不是胜过在下了吗\n");
      return 1;
    }
    say("柳随风淡淡的说道：要见帮主必须先过我这一关，怎么样，你愿意(will)吗？\n");
    me->set_temp("will",1);
    return 1;
}


int decide()
{
  object me=this_player();
  if(!(me->query_temp("will"))) 
   {
      say("柳随风笑着说：有事没事的你跟我许什么愿啊!\n");
      command("blush me");
      return 1;
   }
   say("柳随风嘿嘿一笑：好吧，那我们就来过过招(bihua)!\n");
   me->set_temp("fight",1);
   me->set_temp("will",0);
   return 1;
}


int bihua()
{
  object me=this_player();
  object ob=this_object();
  if(me->query_temp("wu_pass")) {command("say 你不是已经过了我这一关吗，快去见帮主吧");return 1;}
  if(!me->query_temp("fight")) 
   {
    say("柳随风说道：你活的不耐烦了是吧，要跟我动手？\n"); 
    return 1;
   }
   say("看好了,我要进招了！\n");
   message_vision(RED "柳随风向你发动了攻击!\n" NOR,me);   
   ob->set("eff_qi", ob->query("max_qi"));
   ob->set("qi",     ob->query("max_qi"));
   ob->set("jing",   ob->query("max_jing"));
   ob->set("neili",  ob->query("max_neili"));
    ob->fight_ob(me);
    me->fight_ob(ob);
    me->delete_temp("fight");
   remove_call_out("checking");
   call_out("checking", 1, me, ob);
   return 1;

}



int checking(object me, object ob)
{

	object obj;
	int my_max_qi, his_max_qi;

	my_max_qi  = ob->query("max_qi");
	his_max_qi = me->query("max_qi");
//      ob->fight_ob(me);
//      me->fight_ob(ob);

	if (me->is_fighting()&&(ob->query("qi")*100 / my_max_qi) > 50&&(me->query("qi")*100 / his_max_qi) > 50) {
		if ( (ob->query("qi")*100 / my_max_qi) <= 80&&(ob->query("qi")*100 / my_max_qi) > 50 )
			command("exert recover");
                call_out("checking", 1, me, ob);
		return 1;
	}

        if( !present(me, environment()) ) return 1;


	if (( (int)ob->query("qi")*100 / my_max_qi) <= 50 ) {
		command("say 看不出来，你的武功修为已经到了这个境界，我自愧不如！\n");
                message_vision(HIY "你可以进去了!请吧!\n" NOR,me);
                me->set_temp("wu_pass",1);
                me->delete_temp("fight");
                command("halt");
                return 1;
	}


	if (( (int)me->query("qi")*100 / his_max_qi) <=50 ) {
		command("say 看来" + RANK_D->query_respect(me) + 
			"还得多加练习，才可能成为一个合格的杀手.\n");
                me->delete_temp("fight");
                command("halt");
		return 1;
	}

	return 1;  
}
