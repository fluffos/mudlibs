// due.c
#include <ansi.h> 
inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("宝树", ({ "bao shu", "baoshu" }) );
	set("title", HIR"大和尚"NOR);
	set("gender", "男性");
	set("age", 90);
	set("long",
		"宝树和尚贪婪、委琐、龌龊、阴暗。对别人的生命充满的是冷漠与虚伪的真诚。\n 永远无法理解人类的大悲欢，体察不到世间的冷暖。\n");

	set("attitude", "peaceful");
	set("class", "bonze");
	set("combat_exp", 9500000);
	set("score", 200000);

	set("str", 36);
	set("int", 36);
	set("cor", 30);
	set("cps", 30);
	set("con", 36);
	set("jing", 69000);
	set("max_jing", 69000);

	set("qi", 99000);
	set("max_qi", 99000);
	set("neili", 99000);
	set("max_neili", 99000);
	set("jiali", 90);

	//create_family("少林派", 35, "弟子");
	//assign_apprentice("弟子", 0);

	set_skill("force", 550);
	set_skill("club", 500);
	set_skill("parry", 580);
	set_skill("dodge", 580);
	set_skill("yijinjing", 501);
	set_skill("hunyuan-yiqi", 500);
	set_skill("weituo-chu", 500);
	set_skill("shaolin-shenfa", 580);

	map_skill("force", "yijinjing");
	map_skill("club",  "weituo-chu");
	map_skill("parry", "weituo-chu");
	map_skill("dodge", "shaolin-shenfa");

	set_skill("blade", 150);
	set_skill("claw", 150);
	set_skill("club", 550);
	set_skill("cuff", 150);
	set_skill("finger", 550);
	set_skill("hand", 550);
	set_skill("staff", 150);
	set_skill("strike", 150);
	set_skill("sword", 150);

	set_skill("banruo-zhang", 590);
	set_skill("cibei-dao", 590);
	set_skill("damo-jian", 590);
	set_skill("fengyun-shou", 590);
	set_skill("fumo-jian", 500);
	set_skill("jingang-quan", 599);
	set_skill("longzhua-gong", 590);
	set_skill("luohan-quan", 590);
	set_skill("nianhua-zhi", 590);
	set_skill("pudu-zhang", 590);
	set_skill("qianye-shou", 590);
	set_skill("sanhua-zhang", 590);
	set_skill("weituo-gun", 590);
	set_skill("wuchang-zhang", 590);
	set_skill("xiuluo-dao", 590);
	set_skill("yingzhua-gong", 590);
	set_skill("yizhi-chan", 500);
	set_skill("zui-gun", 500);
	set_skill("buddhism", 500);
	//map_skill("blade", "cibei-dao");
	map_skill("claw", "longzhua-gong");
	map_skill("club", "weituo-chu");
	map_skill("cuff", "luohan-quan");
	map_skill("finger", "nianhua-zhi");
	map_skill("hand", "fengyun-shou");
	//map_skill("staff", "weituo-gun");
	map_skill("strike", "sanhua-zhang");
	//map_skill("sword", "fumo-jian");
	prepare_skill("finger", "nianhua-zhi");
	prepare_skill("strike", "sanhua-zhang");
     set("chat_chance_combat", 90);
     set("chat_msg_combat", ({
                (: perform_action, "finger.fuxue" :),
(: perform_action, "strike.sanhua" :),
                (: perform_action, "club.leidong" :),
                (: perform_action, "club.zuijiu" :),
                            }) );


        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 1000);
        set_temp("apply/damage", 1000);

	setup();
	carry_object("/d/shaolin/obj/jingangchu")->wield();
}
void init( )
{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
        ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight") && random(10) < 5)
        call_out("hunting",0);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
        if(!userp(ob[i])) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}                     

void unconcious()
{
	die();
}
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
  	if(((int)who->query("jinyong/book2")>=3))
	{
//::die();	
	}
        else if(who) {
  	if(((int)who->query("jinyong/book2")==2))
{
        	message_vision("$N说道：宝藏全是我一个人的，这不可能！这不可能！\n" NOR,this_object());
		message_vision("$N说道：大人还在辽东要塞等着我，不 不 不！\n" NOR,this_object());
		i = random(5000);
		who->set("jinyong/book2",3);
		who->add("combat_exp",i+20000);
		who->add("potential",i*25);
		who->add("mpgx",10);
		who->add("expmax",2);
		//command("chat "+this_player()->query("name")+"胆色过人，义惩青城恶霸。");
		tell_object (who,"你赢得了"+chinese_number(i+20000)+"点经验"+
		           chinese_number(i*25)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
		who->save();
 }
        }
	::die();
}
