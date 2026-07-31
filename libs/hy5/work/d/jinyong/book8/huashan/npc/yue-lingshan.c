// yue-lingshan.c

inherit NPC;
int ask_me();

void create()
{
        set_name("岳灵珊", ({ "yue lingshan", "yue", "lingshan" }) );
        set("nickname", "小师妹");
        set("gender", "女性" );
        set("age", 17);
        set("per", 29);
        set("str", 16);
        set("con", 24);
        set("dex", 30);
        set("int", 27);

        set("attitude", "friendly");

        set("max_qi",50000);
        set("max_jing",50000);
        set("neili", 50000);
        set("max_neili", 50000);
        set("jiali", 80);
        set("combat_exp", 500000);

        set("long",     "岳灵珊是华山派掌门岳不群的独生女儿。\n");

        //create_family("华山派", 14, "弟子");

        set_skill("unarmed", 50);
        set_skill("sword", 50);
        set_skill("force", 60);
        set_skill("parry", 50);
        set_skill("dodge", 50);
        set_skill("literate", 70);

        set_skill("huashan-sword", 150);
        set_skill("yunu-sword", 280);
        set_skill("huashan-ken", 150);
        set_skill("feiyan-huixiang", 150);
set_skill("chongling-jian", 320);
set_skill("zixia-shengong", 150);

        map_skill("sword", "chongling-jian");
        map_skill("parry", "yunu-sword");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-ken");
        map_skill("dodge", "feiyan-huixiang");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
(: perform_action, "sword.ai" :),
(: perform_action, "parry.wushuang" :),	
				
        }) );

	set("inquiry", ([
	     "林平之": (: ask_me :),
       ]) );

        setup();

        carry_object(__DIR__"obj/green_water_sword")->wield();
        carry_object("/clone/cloth/cloth")->wear();

}

void init()
{
	object me = this_object();
	object who= this_player();
	if(me->is_fighting()) return;
	if (who && interactive(who)) 
		call_out ("fighting", 1, who);  
}


void fighting(object who)
{
	object where = environment(who);
	object yue = this_object();
	object lin = present("lin pingzhi",where);
	if(yue && lin) 
	{
		message_vision("$N对$n说道： 小师妹，休怪我心狠，是你父亲杀了我父亲，我如今要替父报仇 !\n",lin,yue);
		message_vision("$N大惊：小林子，你竟然不顾夫妻情谊 !\n",yue);
		lin->kill_ob(yue);
	}
}


int ask_me()
{
	int i;

	object who = this_player();
	message_vision("$N对$n说道： 没想到是我爹爹如此作恶，可怜的小林子 !\n",this_object(),who);
	
	if (this_object()->query("isyue")==0)
{
	call_out ("yueappear", 1,who);  
}
	this_object()->set("isyue",1);
	return 1;
}

void yueappear(object who)
{
	
	object yue=new("/d/jinyong/book8/huashan/npc/yue-buqun");	
	yue->move( environment(who));
	this_object()->set("isyue",1);
	message_vision("$N说道：就是我杀了他父母，偷了他林家剑谱，有本事就杀了我报仇，哈哈哈！\n",yue);
}