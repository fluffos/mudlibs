// /d/city/npc/zhang.c 张帐房
// by snowman@SJ 12/02/2000

inherit NPC;
string ask_money();

void create()
{
        set_name("张帐房", ({ "zhang zhangfang", "zhang", "zhangfang" }));
        set("title", "扬州知府帐房主管");
        set("gender", "男性");
        set("age", 63);
        set("str", 20);
        set("dex", 20);
        set("long", "他是扬州现任知府帐房主管。任何公事上的帐务都由他来管。\n");
        set("combat_exp", 2000);
        set("shen_type", 0);
        set("attitude", "peaceful");

        set_skill("unarmed", 10);
        set_skill("force", 10);
        set_skill("sword", 10);
        set_skill("dodge", 10);
        set_skill("parry", 10);

        set("neili", 200); 
        set("max_neili", 200);
        set("jiali", 1);
        
	      set("inquiry", ([
		      "缴款" : (: ask_money :),
	      ]) );

        set("shen_type",1);
        set("score",200);
        setup();
       	carry_object("/clone/armor/cloth")->wear();
}

string ask_money()
{
        object me=this_player();            
        
        if (!me->query_temp("name_wait_modify"))
                return "你没有需要在此办理的手续。\n";
        
        if (me->query("advance_balance")<100*(me->query("name_modify")+1) )
                return "你要缴纳"+chinese_number(100*(me->query("name_modify")+1))+"根金条才能完成所有手续。\n";
        
        me->add("advance_balance", -100*(me->query("name_modify")+1) );
        command("nod " + me->query("id"));
        me->delete_temp("name_wait_modify");
        me->set_temp("name_modify_paid", 1);
        return me->name()+"从自己的账户中转过来足够的税金，记入帐薄。\n";
}

void kill_ob(object ob)
{
      ob->remove_killer(this_object());
      remove_killer(ob);
}

