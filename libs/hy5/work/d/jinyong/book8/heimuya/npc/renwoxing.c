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
       //create_family("日月神教",1,"教主");	
	set("max_qi", 20000);
	set("max_jing", 20000);
	set("neili", 30000);
	set("max_neili", 30000);
	set("jiali", 400);
	set("combat_exp", 9000000);
	set("score", 390000);

	set_skill("literate", 180);
	set_skill("force", 390);
	set_skill("dodge", 390);
	set_skill("unarmed", 390);
	set_skill("parry", 390);
	set_skill("sword", 390);
	set_skill("changquan", 390);
	set_skill("kuihua-xinfa", 390);
	set_skill("lingxu-bu", 390);
	set_skill("damo-jian", 390);
	set_skill("taiji-jian", 390);
	set_skill("huifeng-jian", 390);
	set_skill("taishan-sword", 390);
	set_skill("hengshan-jian", 390);
	set_skill("hengshan-sword", 390);
	set_skill("huashan-sword", 390);


	set_skill("songshan-jian", 390);
  set_skill("luoyan-jian",500);
  set_skill("shiba-pan",500);
  set_skill("liuhe-dao",500);
  set_skill("hengshan-jian",500);
  
  
  
	map_skill("dodge", "lingxu-bu");
	map_skill("force", "kuihua-xinfa");
	map_skill("unarmed", "changquan");
	map_skill("sword", "damo-jian");
	map_skill("parry", "damo-jian");
          set_skill("sword", 390);
          set_skill("parry", 390);
        set_skill("literate",200);
          set_skill("dodge", 390);
          set_skill("unarmed", 390);
          set_skill("whip", 390);
          set_skill("force", 390);
         set_skill("tmzhang", 390);
        set_skill("staff", 390);
         set_skill("tmjian", 390);
         set_skill("tmdao", 390);
         set_skill("pmshenfa", 390);
          set_skill("strike",500);
          set_skill("cuff",500);
         set_skill("blade", 390);
         set_skill("tmdafa", 390);
set_skill("tmquan", 390);
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
		"教主"     : (: ask_me() :),
	]));

	prepare_skill("cuff","tmquan");
	
	prepare_skill("strike","tmzhang");

        set_temp("apply/defense", 200);
        set_temp("apply/armor", 390);
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
	if(objectp(present("dongfang bubai", environment(who))))
	{
		message_vision("$N对$n说道： 这位"+ RANK_D->query_respect(who) +"先帮我把东方不败这不男不女的贼人杀了！\n",this_object(),who);
		return 1;
	}	
	
  	if(((int)who->query("jinyong/book8")>=9))
	{
		message_vision("$N对$n说道： 你在说什么啊！\n",this_object(),who);
		return 1;	
	}
	
	message_vision(HIC "$N说： 哈哈哈，东方不败，你也有今天！\n",this_object());
	message_vision(HIC "$N说： 从今以后我才是日月神教的教主，首先第一步，剿灭趁他们开五岳大会内讧时机，剿灭五岳剑派！\n",this_object(),who);
	i = random(3000);
	who->set("jinyong/book8",9);
	who->add("combat_exp",i+30000);
	who->add("potential",i*24);
	who->add("mpgx",10);
	who->add("expmax",2);
	//command("chat "+this_player()->query("name")+"胆色过人，义惩青城恶霸。");
	tell_object (who,"你赢得了"+chinese_number(i+30000)+"点经验"+
	           chinese_number(i*24)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
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