// qinjun.c 武将

inherit NPC;

int ask_job();
void create()
{
        set_name("亲兵", ({ "qin bing", "qin", "bing" }));
        set("gender", "男性");
        set("age", random(10) + 20);
        set("str", 40);
        set("dex", 20);
        set("long", "他是史可法的亲军，明显有与一般军士不同的威慑力。\n");
        set("combat_exp", 100000);
        set("shen_type", 1);
        set("attitude", "peaceful");
		set("uni_target",1);
        set_skill("unarmed", 100);
        set_skill("force", 100);
        set_skill("sword", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 30);
        set("mingqi",1);
		set("skfnokill",1);
		set("qi", 1000); 
		set("max_qi", 1000); 
        set("neili", 800); 
        set("max_neili", 800);
        set("jiali", 10);
		set("inquiry", ([
            "暗号" : (: ask_job :),
            "护送" : (: ask_job :),
			"job" : (: ask_job :),
            
       	]) );

        setup();
        carry_object(__DIR__"items/pixue")->wear();
		carry_object(__DIR__"items/cloth")->wear();
		carry_object(__DIR__"items/sword")->wield();
}

void init()
{
	add_action("do_kill", ({ "kill", "hit"}));
}

void unconcious()
{
	die();
}

void die()
{
	message_vision("$N摇了摇头，忙自己的事情去了。\n",this_object());
	this_object()->fullme();
	return;
}

int ask_job()
{
	object me=this_player();
	object ob=this_object();
	object refugee=new("/d/city/npc/refugee");
    if (me->query_temp("skf/mingpin"))
    {
        command( "say 大人一路保重！");
        return 1;
    }
	if (me->query_temp("skf/ming/tj/pin"))
    {
        command( "say 公公一路保重！");
        return 1;
    }
	if (me->query("skf/jobasked"))
	{
		if(me->query_temp("skf/qjasked"))
		{
			command( "say 你刚才不是问过暗号了吗？难道你是鞑子的奸细？");
			command("consider " + me->query("id"));
		}
		else
		{
			command("look " + me->query("id"));
			command("tell " + me->query("id")+ " 国难当头，人人自危，难得你不忘自己华夏儿女的本色。\n" );
			command("say 民众已经在这里了，他会跟随着你，一路上艰险重重，还望你不负督师所托。\n");
			me->set_temp("skf/qjasked",1);
			refugee->move("/d/city/xiaolu");
			me->set_temp("skf/nanmin",refugee);
			refugee->set("skfleader",me->query("id"));
			message_vision("难民"+refugee->query("name")+"从旁边的军营走了出来。\n",me);
			ob->set("jobid2",me->query("id"));
		}
	}
	else
	{
		command( "say 没有督师手令，你是怎么混进这里的？");
	}
	return 1;
}

int do_kill(string arg)
{
	object me=this_player();
	if(userp(me)&&(arg=="qin bing"||arg =="qin"||arg =="bing"))
	{
		message_vision("$N转过身去，根本理都不理$n。\n",this_object(),me);
		return 1;
	}
}