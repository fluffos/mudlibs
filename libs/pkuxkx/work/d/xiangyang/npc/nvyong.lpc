inherit NPC;

string ask_for_guojing();  
string ask_guo();

void create()  
{	set_name("中年女佣", ({ "nvyong","yong" }));
	set("gender", "女性");
	set("age", 45);
	set("str", 17);
	set("dex", 16);
	set("long", "她是郭靖家的女佣。\n");
	set("combat_exp", 1000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 20);
	
	set("neili", 100); 
	set("max_neili", 100);
       
        set("inquiry",([
                "郭大侠"  : (: ask_for_guojing :),
                "郭靖"  : (: ask_guo :),
          ]));


        set("chat_chance", 8);
        set("chat_msg", ({
       " 郭大侠很久没回过家了，也不知道现在军情如何.\n"
                }) );

        setup();
	carry_object(__DIR__"obj/cloth")->wear();

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

string ask_for_guojing()
{
        object me,ob;
        me = this_player();
        if ((int)me->query_str() < 1 )
           return "这位好汉体质太差,手无缚鸡之力,还是不要从军的好。\n";
           command("sigh");
//           command("admire" + me->query("id"));
//           command("give armor to " + me->query("id"));
//         me->move("/u/chenchen/work/xysouth3");
//          object ob; 
        ob = new(__DIR__"obj/letter");
	ob->move(this_player());
         message_vision("女佣给了$N一张便条。\n", me);
        me->set_temp("女佣", 1);  
          return "郭大侠很少回家，你得到帅府去找他.有了这张便条,
                那守门的就会让你进去了";
}
string ask_guo()
{    
        object me;
        me = this_player();
        command("angry");
        return "郭大侠的名讳也是你叫的?";
}


