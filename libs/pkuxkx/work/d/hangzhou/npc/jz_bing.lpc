inherit NPC;
void destme();
void himsg();
int auto_kill(object player);
void create()
{
	set_name("官兵", ({
		"guan bing",
		"bing",
	}));
//	set("title", "守门官兵");
	set("long",
		"这是一个负责监斩犯人的大宋军士。\n"
	);
	set("gender", "男性");
	set("attitude", "heroism");

	set("age", 35);
	set("shen_type",0);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 300);
	set("max_jing", 300);
	set("neili", 300);
	set("max_neili", 300);
	set("combat_exp", 20000+random(50000));
	set("score", 100);

	set_skill("force", 30);
	set_skill("dodge", 30);
	set_skill("cuff", 30);
	set_skill("parry", 30);
	set_skill("blade",30);

	setup();
  himsg();
  carry_object(__DIR__"obj/junfu")->wear();
	carry_object("/d/city/obj/gangdao")->wield();
}
int JZ_BING()
{
	return 1;
}
void init ()
{
    auto_kill(this_player());
}
void himsg()
{
       remove_call_out("destme");
       call_out("destme",120);
       return; 
}
void destme()
{
  if (!objectp(this_object()))
        return;
        if (environment(this_object()))
        {
                destruct(this_object());
        }
        return;
}
int auto_kill(object player)
{
    object me = this_object();

    if (player->query("special_skill/sociability")) return 0;  //sociability不被追杀
    if (//interactive(player) &&
        player->query_condition("bjkiller"))
    {
        remove_call_out("kill_ob");
        call_out("kill_ob", 1, player);
        if (me->query("follow_killer") && player->query("combat_exp") > 150000)
            command("follow "+player->query("id"));
        return 1;
    }
//在紫禁城内并且非朝廷官员，格杀勿论(排除天安门广场，端门，武门和神武门)
 /*   if (interactive(player)
        && strsrch(base_name(environment(me)), "/d/beijing/zijin/") != -1   //自己要在紫禁城内
        && strsrch(base_name(environment(player)), "/d/beijing/zijin/") != -1
        && strsrch(base_name(environment(player)), "/d/beijing/zijin/tianansquare") == -1
        && strsrch(base_name(environment(player)), "/d/beijing/zijin/tiananmen") == -1
        && strsrch(base_name(environment(player)), "/d/beijing/zijin/duanmen") == -1
        && strsrch(base_name(environment(player)), "/d/beijing/zijin/wumen") == -1
        && strsrch(base_name(environment(player)), "/d/beijing/zijin/shenwumen") == -1
        && player->query("class") != "officer" 
        && player->query("class") != "eunuch" )
    {
    //如果不是朝廷官员没有通行令
        if (!present("hgtongxing ling",this_player())){
        remove_call_out("kill_ob");
        call_out("kill_ob", 1, this_player());
      if (me->query("follow_killer") && player->query("combat_exp") > 150000)
            command("follow " + player->query("id"));
        return 1;
        }
            return 0;
    }
    return 0;
*/
}

int accept_fight(object player)
{
        object me=this_object();
        if(living(me))
        {
        command("say " + RANK_D->query_self_rude(me) + "正想找人杀呐，今天算你倒霉。\n");
        player->apply_condition("bjkiller", 100 + player->query_condition("bjkiller"));
        me->kill_ob(player);
        }
        return 1;
}

int accept_kill(object player)
{
        object me=this_object();
        if(living(me))
        {
        command("say " + RANK_D->query_self_rude(me) + "正想找人杀呐，今天算你倒霉。\n");
        player->apply_condition("bjkiller", 100 + player->query_condition("bjkiller"));
        me->kill_ob(player);
        }
        return 1;
}

int accept_hit(object player)
{
		accept_kill(player);
    return 1;
}

void set_shiwei_status(int lvl)
{
        int exp;
        object me=this_object();

        me->set("gender", "男性");
        me->set("attitude", "heroism");
        me->set("shen_type",0);
        me->set("score", 100);
        me->set("str", 30);
        me->set("int", 30);
        me->set("con", 30);
        me->set("dex", 30);

        me->set("max_qi", lvl*10);
        me->set("eff_qi", lvl*10);
        me->set("qi", lvl*10);

        me->set("max_jing", lvl*10);
        me->set("eff_jing", lvl*10);
        me->set("jing", lvl*10);

        me->set("jingli", lvl*20);
        me->set("max_jingli", lvl*20);

        me->set("neili", lvl*20);
        me->set("max_neili", lvl*20);

        me->set("jiali", lvl);

        exp = lvl*lvl/10*lvl;

        me->set("combat_exp", exp+random(exp/4));

        me->set_skill("force", lvl);
        me->set_skill("dodge", lvl);
        me->set_skill("cuff", lvl);
        me->set_skill("hand",lvl);
        me->set_skill("parry", lvl);
        me->set_skill("blade",lvl);
        me->set_skill("sword",lvl);
        me->set_skill("staff",lvl);
        me->set_skill("whip",lvl);
        me->set_skill("halberd",lvl);
        me->set_skill("spear",lvl);

	set_skill("bixue-xinfa", lvl);
	set_skill("longfeng-xiang", lvl);
	set_skill("panlong-gun", lvl);
	set_skill("taizu-changquan", lvl);
	set_skill("pojun-daofa", lvl);
	set_skill("huqian-jianfa", lvl);
	set_skill("gehu-ji", lvl);
	set_skill("lihua-qiang", lvl);
	set_skill("yuejia-sanshou", lvl);
	set_skill("menghu-bian", lvl);
	map_skill("force", "bixue-xinfa");
	map_skill("sword", "huqian-jianfa");
	map_skill("blade", "pojun-daofa");
	map_skill("dodge", "longfeng-xiang");
	map_skill("parry", "yuejia-sanshou");
	map_skill("hand", "yuejia-sanshou");
	map_skill("whip", "menghu-bian");
	map_skill("halberd", "gehu-ji");
	map_skill("staff", "panlong-gun");
	map_skill("spear", "lihua-qiang");
	map_skill("cuff", "taizu-changquan");

	prepare_wskill("sword", "huqian-jianfa");
	prepare_wskill("blade", "pojun-daofa");

	prepare_skill("cuff", "taizu-changquan");
	prepare_skill("hand", "yuejia-sanshou");
        me->carry_object(__DIR__"obj/junfu")->wear();
        if (random(2) == 1)
            me->carry_object("/d/city/obj/gangjian")->wield();
        else
            me->carry_object("/clone/weapon/gangdao")->wield();
}
