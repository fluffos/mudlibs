// renwoxing.c

#include <ansi.h>

inherit NPC;
int ask_me();

void create()
{
	set_name("任我行", ({ "ren woxing", "ren","woxing" }));
	set("title", BLU "日月神教教主"NOR );
	set("long", "只见他一张长长的脸孔，脸色雪白，更无半分血色，眉目清秀，
身材甚高，一头黑发，穿的是一袭青衫。\n");
	set("gender", "男性");
	set("class", "scholar");
	set("age", 55);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 70);
	set("per", 27);
	set("int", 70);
	set("con", 70);
	set("dex", 70);
       create_family("日月神教",1,"弟子");	
	set("max_qi", 26000);
	set("max_jing", 26000);
	set("neili", 54000);
	set("max_neili", 54000);
	set("jiali", 400);
	set("combat_exp", 9000000);
	set("score", 500000);

	set_skill("literate", 180);
	set_skill("force", 260);
	set_skill("dodge", 260);
	set_skill("unarmed", 260);
	set_skill("parry", 260);
	set_skill("sword", 260);
	set_skill("changquan", 360);
	set_skill("kuihua-xinfa", 360);
	set_skill("lingxu-bu", 360);
	set_skill("damo-jian", 360);
	set_skill("taiji-jian", 360);
	set_skill("huifeng-jian", 360);
	set_skill("taishan-sword", 360);
	set_skill("hengshan-jian", 360);
	set_skill("hengshan-sword", 300);
	set_skill("huashan-sword", 360);


	set_skill("songshan-jian", 380);
  set_skill("luoyan-jian",380);
  set_skill("shiba-pan",380);
  set_skill("liuhe-dao",380);
  set_skill("hengshan-jian",380);
  
  
  
	map_skill("dodge", "lingxu-bu");
	map_skill("force", "kuihua-xinfa");
	map_skill("unarmed", "changquan");
	map_skill("sword", "damo-jian");
	map_skill("parry", "damo-jian");
          set_skill("sword", 380);
          set_skill("parry", 300);
        set_skill("literate",200);
          set_skill("dodge", 300);
          set_skill("unarmed", 300);
          set_skill("whip", 250);
          set_skill("force", 300);
         set_skill("tmzhang", 380);
        set_skill("staff", 160);
         set_skill("tmjian", 380);
         set_skill("tmdao", 380);
         set_skill("pmshenfa", 380);
          set_skill("strike",300);
          set_skill("cuff",300);
         set_skill("blade", 300);
         set_skill("tmdafa", 320);
set_skill("tmquan", 380);
        map_skill("unarmed", "tmzhang");
        map_skill("sword", "tmjian");
        map_skill("parry", "tmjian");
        map_skill("blade", "tmdao");
        map_skill("dodge", "pmshenfa");
        map_skill("force", "tmdafa");
        map_skill("strike", "tmzhang");
        map_skill("cuff", "tmquan");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.diansha" :),
                (: perform_action, "sword.xuan" :),
                (: perform_action, "sword.tmbiao" :),
                	(: perform_action, "sword.jianshen" :),
                		(: perform_action, "sword.moshen" :),
                (: perform_action, "blade.moxiao" :),
                (: perform_action, "blade.tiandirenmo" :),
                (: perform_action, "blade.xuan" :),                	
                (: perform_action, "blade.yueshen" :),                	
                (: perform_action, "strike.huashen" :),                
                (: perform_action, "strike.zhen" :),                
                (: perform_action, "strike.tmduan" :),                
                (: perform_action, "cuff.tianmo" :),                
                (: perform_action, "cuff.dimo" :),                
                (: perform_action, "cuff.renmo" :),

        }) );

	set("inquiry", ([
		"任盈盈"     : (: ask_me() :),
	]));

	prepare_skill("cuff","tmquan");
	
	prepare_skill("strike","tmzhang");

        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);

 	setup();
	carry_object("/d/wudang/obj/bluecloth")->wear();
if (random(2)==0) 
{
	carry_object("/clone/weapon/changjian")->wield();
}
else
{
carry_object("/clone/weapon/gangdao")->wield();
}
}

int ask_me()
{
	int i;
	object ob = this_object();
	object who = this_player();
	
  	if(((int)who->query("jinyong/book8")>=8))
	{
		message_vision("$N对$n说道： 你在说什么啊！\n",this_object(),who);
		return 1;	
	}
	if(objectp(present("fangzheng dashi", environment(who)))||objectp(present("chongxu daozhang", environment(who)))||objectp(present("yu canghai", environment(who))))
	{
		message_vision("$N对$n说道： 这位"+ RANK_D->query_respect(who) +"，这群假仁假义的秃驴牛鼻子拦着我不让救盈盈！\n",this_object(),who);
		return 1;
	}	
	message_vision(HIC "$N对$n说： 这些所谓的高手不堪一击，居然还敢阻挡我救盈盈，这位"+ RANK_D->query_respect(who) +"居功至伟，对我教大恩，任我行没齿难忘！\n",this_object(),who);
	message_vision(HIC "现今世俗事已了，我该去黑木崖夺回我的教主之位了！\n",this_object(),who);
	i = random(2500);
	who->set("jinyong/book8",8);
	who->add("combat_exp",i+24000);
	who->add("potential",i*20);
	who->add("mpgx",10);
	who->add("expmax",2);
	//command("chat "+this_player()->query("name")+"胆色过人，义惩青城恶霸。");
	tell_object (who,"你赢得了"+chinese_number(i+24000)+"点经验"+
	           chinese_number(i*20)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
	who->save();
call_out("leavet",1);
	return 1;
}

void leavet()
{
        object ob = this_object();
 message_vision("$N飞身向外离去！\n" NOR,this_object());
        destruct(this_object());
}