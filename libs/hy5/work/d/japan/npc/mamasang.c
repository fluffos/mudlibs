
inherit NPC;
void create()
{
        set_name("妈妈桑",({"mama sang","laobao"}));
	set("gender","女性");
	set("age",40);
       set("title","神户妓馆");
	set("long",
                 "打扮得很是妖艳的中年女子，身穿和服，正满脸媚笑的看着你。\n");
	set("combat_exp",2000);
	set_temp("apply/attack",15);
	set_temp("apply/defense",15);
	set_skill("unarmed",20);
	set("mingwang",-1);
	set_skill("dodge",30);
	set("attitude", "friendly");
	setup();
         carry_object(__DIR__"obj/hefu")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{

	if( !ob || environment(ob) != environment() ) return;
	if(ob->query("gender")=="女性")	{
               message_vision("$n冲着$N摇头道：这可不是"+
             RANK_D->query_respect(ob)+"来的地方啊。\n",ob,this_object());
		return ;
	}
	switch( random(2) ) {
		case 0:
                message_vision("$n媚声对$N道：这位"+
             RANK_D->query_respect(ob)+"可是看中我家哪位姑娘了吧。\n",ob,this_object());
			break;
		case 1:
          message_vision("$n上前几步，拉住$N的手叫道：姑娘们，接客啦！\n",ob,this_object());
			break;
                           }
}
int accept_fight(object who)
{
	int i;
	object npc,env,*inv;
	npc=new(__DIR__"dashou");
	env=environment(this_object());
         message_vision("$n对着$N冷笑着喝道：敢到这来撒野！？\n"+
        "来人哪！！\n闻声而来的打手立刻将$N包围了起来。\n",who,this_object());
        if(sizeof(children(base_name(npc)))<=4 && (int)query("have_ds")<=4)
        {
                add("have_ds",1);
                npc->move(env);
        }
        else    destruct(npc);
	this_object()->kill_ob(who);
	inv=all_inventory(env);
	for(i=0;i<sizeof(inv);i++)	{
		if (inv[i]->query("id")!="dashou")	continue;
		inv[i]->kill_ob(who);
	}
	return 1;
}
