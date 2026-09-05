// zhike.c 知客                              
//made by hacky

#include <ansi.h>

inherit NPC;

void heal();

void create()
{
	set_name("知客道长", ({ "zhike daozhang", "zhike" }));
	set("long", 
		"他是全真教的知客道长。\n");
	set("gender", "男性");
	set("title", HIB"全真教" NOR + GRN "道长" NOR);
	set("age", 30);
	set("attitude", "peaceful");
	set("shen_type", 1);

	set("str", 20);
	set("int", 20);
	set("con", 25);
	set("dex", 20);
	
        set("chat_chance", 100);
        set("chat_msg", ({
	        (: heal :),
        }));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: exert_function , "powerup" :),
        }) );

	set("max_qi", 300);
	set("max_jing", 200);
	set("neili", 300);
	set("max_neili", 300);

	set("combat_exp", 5000);
	set("score", 1000);

	set_skill("force", 60);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("sword", 40);
	set_skill("quanzhen-jian", 20);
	set_skill("daoxue-xinfa", 20);
       set_skill("xiantian-gong",40);
	set_skill("literate", 20);

	
	map_skill("parry", "quanzhen-jian");
        map_skill("force","xiantian-gong");
	map_skill("sword", "quanzhen-jian");


        create_family("全真派",4,"弟子");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
}

void heal()
{
	object ob=this_object();
	
	if (ob->query("eff_qi") < ob->query("max_qi"))
	{
		command("exert heal");
		return;
	}

	if (ob->query("qi") < ob->query("eff_qi"))
	{
		command("exert recover");
		return;
	}

	if (ob->query("jing") < ob->query("eff_jing"))
		command("exert regenerate");

	return;
}

void init()
{
 object me;
 ::init();
 if(interactive(me=this_player())&&!is_fighting() )
  {
   remove_call_out("greeting");
   }
}

void greeting( object me)
{
 
  if(me->query("family/family_name")=="全真派")
  {
      command("say "+RANK_D->query_respect(me)+"辛苦了,快进门休息吧.");
      command("smile "+me->query("id"));

  }
  else {
   command("say 欢迎来到全真教"+RANK_D->query_respect(me)+"请进!");
   }
 }

int accept_fight(object me)
{
 command ("say 我与"+RANK_D->query_respect(me)+"无冤无仇,为何要打打杀杀?");
 command ("sigh"+me->query("id"));
 return 0;
 }

  

