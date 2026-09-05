// wujiang.c 武将

inherit NPC;
// inherit F_SKILL;
string ask_me();

void create()
{
	set_name("武将", ({ "wu jiang", "wu", "jiang" }));
	set("gender", "男性");
	set("age", random(10) + 30);
	set("str", 25);
	set("dex", 16);
        set("long", "他站在那里，的确有说不出的威风。\n看样子想出关得征求他的同意才行。\n");
	set("combat_exp", 75000);
	set("shen_type", 1);
	set("attitude", "peaceful");
       set("no_get", 1);

        set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("halberd", 60);
	set_skill("lujia-ji", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);

	map_skill("halberd", "lujia-ji");
	map_skill("parry", "lujia-ji");

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("neili", 400); 
        set("inquiry", (["出关":(:ask_me:),   ]) );
	set("max_neili", 400);
	set("jiali", 10);

	setup();
	carry_object("/clone/weapon/fangtianji")->wield();
        carry_object("/d/city/npc/obj/tiejia")->wear();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}
string ask_me(){
object me,ob;
int i;
        object* inv;
me=this_object();
ob=this_player();
        inv = deep_inventory(ob);
        for(i=sizeof(inv)-1; i>=0; i--)
        if(inv[i]->is_character()) return "你想干什么？背着别人出关？滚回去！！\n";
        if(base_name(environment(this_object())) != "/d/changbai/shguan1")
        {
        message_vision("武将对$N怒道：“你他妈的把老子给搬到什么地方来了？还不把我给搬回去。”\n",ob);
        command("slapfy " + ob->query("id"));
        return "快滚！\n";
        }
        if (ob->query("combat_exp")<10000000)
        {
        command("look " + ob->query("id"));    
        command("worry " + ob->query("id")); 
        command("say 就你这么点经验，我担心你有去无回！\n"); 
        return "回去好好练功吧！\n";      
        }
        command("look " + ob->query("id"));  
        command("care");  
        message("vision","武将派人把你送到了北门！ \n",ob);
        ob->set_temp("changbai/chuguan", 1);     
        ob->move("/d/changbai/shguan3");
return "你在这里看啥？去！去！没你的事。\n";
}
/*
string ask_me(){
object me,ob;
int i;
me=this_object();
ob=this_player();
        if(base_name(environment(this_object())) != "/d/changbai/shguan3")
        {
        message_vision("武将对$N怒道：“你他妈的把老子给搬到什么地方来了？还不把我给搬回去。”\n",ob);
        command("slapfy " + ob->query("id"));
        return "快滚！\n";
        }
        if (!ob->query_temp("changbai/chuguan"))
        {
        command("look " + ob->query("id"));    
        command("consider " + ob->query("id")); 
        command("say 哪里来的奸细！想入关干什么！！\n"); 
        return "快滚！\n";      
        }
        command("look " + ob->query("id"));  
        command("care");  
        message("vision","武将派人把你送到了南门！ \n",ob);
        ob->delete_temp("changbai/chuguan");
        ob->move("/d/changbai/shguan1");
return "看什么看，滚！";
}
*/
