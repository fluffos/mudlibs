inherit NPC;
void do_move();
int dest()
{
	if (!this_object()->is_fighting())
	{
		message_vision("$N匆匆离去了。\n",this_object());
		destruct(this_object());
	}
}
void create()
{
    set_name("壮汉", ({
	    "zhuang han", "han",
    }));
    set("long",
	"这是一个满脸横肉的乡下汉子。\n"
    );


    set("gender", "男性");
    set("attitude", "heroism");

    set("age", 25);
    set("shen_type", 1);
    set("str", 30);
    set("int", 30);
    set("con", 30);
    set("dex", 30);
    set("max_qi", 400);
    set("max_jing", 400);
    set("neili", 600);
    set("max_neili", 600);
    set("combat_exp", 10000);
    set("score", 100);
	set("HZ_mob",1);
    set("shiwei_level", 0);


    set_skill("force", 40);
    set_skill("dodge", 40);
    set_skill("cuff", 40);
    set_skill("parry", 40);
    set_skill("blade",40);

    setup();

    carry_object("/clone/armor/cloth")->wear();
    carry_object("/clone/weapon/gangdao")->wield();
	call_out("dest",120);

}

void init()
{
    object me = this_object();
    if(!me->query_temp("init"))
    {
        me->set_temp("init", 1);
        remove_call_out("do_move");
        call_out("do_move", 1);
    }
}

void upgrade(int lvl)
{
	lvl += 1;
    set("combat_exp", 50000 * lvl);
    set_skill("force", 40 * lvl);
    set_skill("dodge", 40 * lvl);
    set_skill("cuff", 40 * lvl);
    set_skill("parry", 40 * lvl);
    set_skill("blade",40 * lvl);
    set("shiwei_level", 1);
}

void do_move()
{
    object me = this_object();
    object env = environment(me);

    if (query_temp("no_move")) return;
    if (! env) destruct(me);

    if (env->query("short")!="丽正门"&&env->query("short")!="和宁门") 
	{	// we are at gate
	if ( !me->is_fighting() )
	    command("go "+env->query("enter_dir"));
	call_out("do_move", 4);
    } else {
	message_vision("$N走进了人群，一会儿就不见了。\n", me);
	destruct(me);
    }
    return;
}

void die()
{
    object me = this_object();
    object env = environment(me);
    object player, *inv;
    int    kill_num, i, found_shiwei=0;

    inv = all_inventory(env);
    if (inv)
    {
    	for (i=0; i<sizeof(inv); i++)
    	{
    	    if (userp(inv[i]) && inv[i]->query("class") == "officer" &&
    //		PIN(inv[i]) == (8 - query("shiwei_level")) &&
    		inv[i]->is_fighting() &&
    		get_damage_origin_object() == inv[i] &&
    		query_temp("outer_gate_killer") &&
    		inv[i]->query_temp("chaoting/newjob/guard/can_allow") )
    		{
        		message_vision("\n$N踢了一脚$n的尸体，得意地笑了笑。\n", inv[i], me);
        		player = inv[i];
        		if (env->query("short")!="丽正门"&&env->query("short")!="和宁门")
        		{
        		    kill_num = player->query_temp("chaoting/newjob/guard/kill_num");
        		    player->set_temp("chaoting/newjob/guard/kill_num", kill_num+1);
                    if(player->query_temp("chaoting/newjob/guard/kill_num") < 100)
                    player->add_temp("chaoting/newjob/guard/gateexp", (kill_num + 1) * 3);
        		}
        		found_shiwei ++;
                break;
    	    }
    	}
    }
    if (! found_shiwei) 
    {
        message_vision("\n$N大叫一声：“乱杀无辜！”说罢倒在地上，挣扎了几下就死了。\n", me);
    }


    destruct(me);
}
