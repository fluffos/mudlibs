// yaopu-laoban.c 药铺老板
// by shang 97/6

inherit NPC;
inherit F_DEALER;

int ask_book();
int ask_liaoshang();
void recover(object ob);

void create()
{
	set_name("药铺老板", ({ "yaopu laoban", "laoban", "boss" }));
	set("gender", "男性");
	set("long", "一位精明的药房老板, 经营着祖传的老铺。\n");
	set("age", 65);

	set("int", 20);
	
	set("qi", 300);
	set("max_qi", 300);
	set("jing", 300);
	set("max_jing", 300);
	set("shen_type", 1);

	set("combat_exp", 5000);
	set("attitude", "heroism");

	set_skill("unarmed", 40);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 20);

	set("vendor_goods", ({
	}));
       set("inquiry", ([
       "医书" : (: ask_book :),
       "药典" : (: ask_book :),
		"疗伤" : (:ask_liaoshang:),//for newbie
    ]));

	setup();
	add_money("silver", 15);
}

void init()
{
//add_action("do_buy", "buy");
}
int ask_book()
{
  command("sigh");
  command("say 你是说那本[科金镜赋集解]吧，前几天还在这里卖的，不知道给哪个家伙\n"
+"顺手牵羊给偷走了，唉！。。这年头。。\n");
  this_player()->set_temp("marks/m-book4", 1);
return 1;
}
//for newbie
int ask_liaoshang()
{
	object ob;
	ob=this_player();
	if(ob->query("combat_exp")<3000) 
	{
		command("? "+ob->query("id"));     
		command("say 你怎么从武馆出来了啊，这外面多危险啊！\n");
		command("poor "+ob->query("id"));
		return 1;
	}
	if(ob->query("combat_exp")>50000) 
	{
		command("? "+ob->query("id"));     
		command("say 疗伤？花钱买药啊。公平共价，童叟无欺！\n");
		command("knock "+ob->query("id"));
		return 1;
	}
	if (ob->query("eff_qi") >= ob->query("max_qi"))
	{
		command("? "+ob->query("id"));     
		command("say 调皮蛋，跑我这里添乱！\n");
		command("smile "+ob->query("id"));
		return 1;
	}
	else 
	{
		message_vision("$n对着$N嚷道：“老板叔叔，我受伤了，好痛啊......”\n", this_object(),ob);
		command("poor "+ob->query("id"));
		command("pat "+ob->query("id"));
		command("say 好吧，看你一个小孩子出来闯荡江湖，也可怜的紧。");
                message_vision("$N拿出一根银针轻轻捻入$n受伤部位附近的穴道，$n感觉舒服多了。\n", this_object(),ob);
		ob->start_busy(3);
		call_out("recover", 5, ob);
		return 1;
	}
}
void recover(object ob)
{
	if (!ob || !present(ob)) return;
	if (environment(ob) != environment(this_object())) return;
	ob->set("eff_qi", (int)ob->query("max_qi"));
	//ob->set("eff_jing", (int)ob->query("max_jing"));  
	message_vision("一柱香的工夫过去了，$N觉得伤势已经基本痊愈了。\n",ob);
	command("say 江湖险恶,不小心的话，下次你就没这么幸运了。\n");
	command("pat "+ob->query("id"));
}
