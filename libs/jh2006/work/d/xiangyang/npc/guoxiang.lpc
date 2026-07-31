inherit NPC;
int ask_job();
int ask_lineup();
int ask_heal();
void create()
{
	set_name("郭襄", ({"guo xiang", "guo", "xiang",}));
	set("long","她就是峨嵋派开山祖师、郭靖、黄蓉的女儿郭襄。\n");

	set("gender", "女性");
	set("attitude", "friendly");
	set("unique", 1);

	set("age", 20);
	set("shen_type", 1);
	set("str", 32);
	set("int", 32);
	set("con", 32);
	set("dex", 40);
	set("max_qi", 5500);
	set("max_jing", 5500);
	set("neili", 7500);
	set("max_neili", 6500);
	set("max_jingli",6000);
	set("eff_jingli",6000);
	set("jiali", 50);
set("combat_exp",2400000);
	set("chat_chance_combat", 40);

	set_skill("dacheng-fofa", 180);
	set_skill("linji-jianzhen", 180);
	set_skill("linji-zhuang", 180);
	set_skill("jieshou-jiushi", 180);
	set_skill("huifeng-jian", 180);
	set_skill("sixiang-zhang", 180);
	set_skill("yanxing-daofa", 180);
	set_skill("hand", 180);
	set_skill("lanhua-shou",180);
	set_skill("literate", 180);
	set_skill("strike", 180);
	set_skill("sword", 180);
	set_skill("blade", 180);
	set_skill("parry", 180);
	set_skill("dodge", 180);
	set_skill("force", 180);
	set_skill("anying-fuxiang", 180);

	map_skill("force", "linji-zhuang");
	map_skill("sword", "huifeng-jian");
	map_skill("blade", "yanxing-daofa");
	map_skill("parry", "huifeng-jian");
	map_skill("dodge", "anying-fuxiang");
	map_skill("strike", "sixiang-zhang");
	map_skill("hand", "lanhua-shou");

	set("inquiry", ([
		"守城": (: ask_job :),
		"布阵": (: ask_lineup :),
		"疗伤": (: ask_heal:),
	]) );

	prepare_skill("hand", "lanhua-shou");

	create_family("峨嵋派", 1, "掌门");

	setup();
	carry_object("/d/emei/obj/changjian")->wield();
	carry_object("/d/emei/obj/shoes")->wear();
	carry_object("/d/emei/obj/cloth")->wear();
}

int ask_job()
{
       object me = this_player();
       if (!me->query_temp("xy/job"))
       {
	       command("say 请先向我爹爹请示。");
	       return 1;
       }
      if (me->query("family/family_name") != "峨嵋派")
      {
	       command("say 你快去指定的地点吧，看来蒙古兵就要攻城了！");
	       return 1;
      }
      command("say 如果要布阵法，就布好阵後就告诉我们。");
      command("smile");
      me->set_temp("xy/job",2);
      return 1;
}

int ask_lineup()
{
      object me = this_player();
      if (me->query_temp("xy/job")!=2)
      {
	      command("?");
	      return 1;
      }
      command("nod");
      command("lineup with " + me->query("id"));
      return 1;
}

int ask_heal()
{
      object me = this_player();
      if (me->query_temp("xy/job")<2)
      {
	      command("?");
	      return 1;
      }
	command("exert tiandi "+me->query("id"));
	command("nod "+me->query("id"));
      return 1;
}
void init()
{
	object me=this_player();

	::init();
	if (userp(me) && me->query("str")+me->query("int")+me->query("con")+me->query("dex")>80)
	{
		message_vision("一阵神秘的力量，把$N送到了未知的空间。\n",me);
		me->move("/d/xiangyang/lipindian");
	}
}
