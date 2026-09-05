// liumang.c 流氓

inherit NPC;

void create()
{
	set_name("流氓", ({ "liu mang", "liu" }));
	set("gender", "男性");
	set("age", 19);
	set("long", "他是一个成天游手好闲的流氓，长得倒是白白胖胖的，也许以前有过钱。\n");
	
	set("combat_exp", 1000);
	set("shen_type", -1);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

        set("inquiry", ([  //add by iszt, 2006-08-14
                "name" : "大爷我姓甚名谁关你什么事？走开，别烦我！",
                "rumors" : "嘿，我们老大昨天把丽春院的姑娘们都看了一遍，挑了最风骚的，那叫一个爽！！",
        ]) );

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
    add_action("block_cmd", "",1);
}


int block_cmd(string args)
{
       object ob = this_player();
       object me = this_object();
string verb = query_verb();

object dashi = query("dashi");
        int is_husong_player = 0;
int i, teamsize;
        if(dashi)
        {
        		teamsize = dashi->query_temp("teamsize");
        		for(i = 0; i < teamsize; i++)
        		{
        			if(dashi->query_temp("team"+i) == ob)
        			{
        				is_husong_player = 1;
        				break;
        			}
        		}
        }
        if(is_husong_player == 0)
        {
        	if( verb == "kill" || verb == "killall" || verb == "hit" || verb == "hitall" || verb == "exert" ||
        			verb == "perform" || verb == "steal")
return 1;
else return 0;
}
        return 1;
}
