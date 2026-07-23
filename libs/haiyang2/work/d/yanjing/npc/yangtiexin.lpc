inherit NPC;
void create()
{
	set_name("杨铁心",({"yang tiexin","yang"}));
   set("gender","男性");
   set("mingwang",5000);
   set("combat_exp",60000);
   
set("age",45);
   set("qi",600);
   set("max_qi",600);
set("food",250);
set("water",250);
   set("neili",500);
   set("max_neili",500);
   set("force_factor",10);
set("pubmaster",1);
   set_skill("dodge",120);
   set_skill("force",120);
   set_skill("parry",120);
   set_skill("unarmed",120);
   set_skill("club",180);
   set_skill("yangjia-qiang",200);
        map_skill("club", "yangjia-qiang");
   setup();
   add_money("silver",10);
carry_object(__DIR__"obj/cloth")->wear();
carry_object(__DIR__"obj/tiespear")->wield();
}
int accept_object(object who, object ob)
{
	int i;

	if (!(int)who->query_temp("learn_timeh"))      
		who->set_temp("learn_timeh", 0);

	if( !ob->query("money_id") )
		return 0;		


	if(who->query_skill("yangjia-qiang",1)<30)
		i=ob->value() / 50;
	else
	{
		if(who->query_skill("yangjia-qiang",1)<60)
			i=ob->value() / 100;
		else
		{
			if(who->query_skill("yangjia-qiang",1)<100)
				i=ob->value() / 150;
			else
				i=ob->value() / 300;
		}
	}
	who->add_temp("learn_timeh",i);

      message_vision("杨铁心对$N说道：既然你诚心想学我的武功，我就成全成全你吧。\n",who);

	return 1;
}

int recognize_apprentice(object ob)
{
	if( ob->query_temp("learn_timeh") <= 0) return 0;
else         
ob->add_temp("learn_timeh",-1);
return 1;
}
