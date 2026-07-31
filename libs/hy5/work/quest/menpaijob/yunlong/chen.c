// chen.c 陈近南

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_weiwang();
int ask_tuihui();
int ask_job();
int ask_me2();
int ask_fail();
string ask_me();
int do_gongzuo();
int ask_done();
#include "/quest/givegift.c"
mapping *changxi = ({ 
         ([ "changxi":"扬州","where":"city"   ]),
         ([ "changxi":"北京","where":"beijing"  ]),
         ([ "changxi":"成都","where":"chengdu"]),   
         ([ "changxi":"大理","where":"dali"   ]),   
         ([ "changxi":"佛山","where":"foshan" ]),   
         ([ "changxi":"泉州","where":"quanzhou"]),   
         ([ "changxi":"杭州","where":"hangzhou"]),   
         ([ "changxi":"灵州","where":"lingzhou"]),   
         ([ "changxi":"苏州","where":"suzhou"]),   
         ([ "changxi":"兰州","where":"lanzhou-city"]),   
         ([ "changxi":"盛京","where":"fengtian"]),   
         ([ "changxi":"荆州","where":"jingzhou"]),   
         ([ "changxi":"昆明","where":"kunming"]),   
         ([ "changxi":"襄阳","where":"xiangyang"]),   
         ([ "changxi":"长安","where":"changan"]),   
         ([ "changxi":"长沙","where":"changsha"]), 
         ([ "changxi":"南昌","where":"nanchang"]), 
         ([ "changxi":"中州","where":"zhongzhou"]), 
         ([ "changxi":"贵州","where":"guizhou"]), 
         ([ "changxi":"马邑","where":"mayi"]), 
         ([ "changxi":"徐州","where":"xuzhou"]), 
         ([ "changxi":"巴陵","where":"baling"]), 
         ([ "changxi":"九江","where":"jiujiang"]),          	         	         	         	         	         	         	
         ([ "changxi":"太原","where":"taiyuan"]),          	         	         	         	         	         	         	
         ([ "changxi":"济南","where":"jinan"]),          	         	         	         	         	         	         	
         ([ "changxi":"新疆","where":"xinjiang"]),          	         	         	         	         	         	         	
         ([ "changxi":"碎叶","where":"suiye"]),          	         	         	         	         	         	         	
         ([ "changxi":"定襄","where":"dingxiang"]),          	         	         	         	         	         	         	
         ([ "changxi":"安南","where":"annan"]),          	         	         	         	         	         	         	
         ([ "changxi":"合肥","where":"hefei"]),          	         	         	         	         	         	         	
  	         	         	         	
                   });
mapping query_changxi()
{
        return changxi[random(sizeof(changxi))];
}

void create()
{
	set_name("陈近南", ({ "chen jinnan", "chen","jinnan" }));
	set("title", HIR "天地会"HIM"总舵主"NOR );
	set("nickname", HIC "英雄无敌" NOR);
	set("long", 
		"\n这是一个文士打扮的中年书生，神色和蔼。\n"
		"他就是天下闻名的天地会总舵主陈近南，\n"
		"据说十八般武艺，样样精通。\n"
		"偶尔向这边看过来，顿觉他目光如电，英气逼人。\n");
	set("gender", "男性");
	set("class", "scholar");
	set("age", 45);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 70);
	set("int", 70);
	set("con", 70);
	set("dex", 70);
	set("per", 29);
	
	set("max_qi", 38000);
	set("max_jing", 38000);
	set("neili", 48000);
	set("max_neili", 48000);
	set("jiali", 10);
	set("combat_exp", 8800000);
	set("score", 500000);

	set_skill("literate", 260);
	set_skill("force", 260);
	set_skill("dodge", 260);
	set_skill("unarmed", 260);
	set_skill("parry", 260);
	set_skill("whip", 300);
	set_skill("blade", 300);
	set_skill("sword", 320);
	set_skill("hand", 260);
	set_skill("claw", 300);
	set_skill("cuff", 300);
	set_skill("strike", 300);
	set_skill("houquan", 390);
	set_skill("yunlong-xinfa", 380);
	set_skill("yunlong-shengong", 380);
	set_skill("wuhu-duanmendao", 380);
	set_skill("yunlong-jian", 380);
	set_skill("yunlong-shenfa", 380);
	set_skill("yunlong-bian", 380);
	set_skill("yunlong-shou", 380);
	set_skill("yunlong-zhua", 380);
	set_skill("baihua-cuoquan", 380);
set_skill("bazhen-zhang", 380);
set_skill("wushen-jian", 380);
	map_skill("dodge", "yunlong-shenfa");
	map_skill("force", "yunlong-shengong");
	map_skill("unarmed", "baihua-cuoquan");
	map_skill("blade", "wuhu-duanmendao");
	map_skill("hand", "yunlong-shou");
	map_skill("parry", "baihua-cuoquan");
	map_skill("claw", "yunlong-zhua");
	map_skill("sword", "wushen-jian");
	map_skill("whip", "yunlong-bian");

	map_skill("cuff", "baihua-cuoquan");
	map_skill("strike", "bazhen-zhang");
	
	prepare_skill("cuff", "baihua-cuoquan");
	prepare_skill("strike", "bazhen-zhang");
//	prepare_skill("unarmed","baihua-cuoquan");
	create_family("云龙门",1, "开山祖师");
	set("book_count", 1);
        set("inquiry", ([
		"天地会" :  "\n只要是英雄好汉，都可以入我天地会(join tiandihui)。\n",
		"入会" :  "\n只要入我天地会，可以向各位好手学武艺。\n",
                "反清复明" : "去棺材店和回春堂仔细瞧瞧吧！\n",
                "暗号" : "敲三下！\n",
                "切口" : "敲三下！\n",
                "独臂神尼" :  (: ask_me2 :),
                "威望" :  (: ask_weiwang :),
                "江湖威望" : (: ask_weiwang :),
		"云龙剑谱" : (: ask_me :),
                "job" : (: ask_job() :),
                "失败" : (: ask_fail() :),
		"退会" : (: ask_tuihui :),
		"tuihui"   : (: ask_tuihui :),
                "宣传工作" : (: do_gongzuo :),
                "work"  : (: do_gongzuo :),
                "done" : (: ask_done    :),
                "完成" : (: ask_done    :),
                "报酬" : (: ask_done    :),
	]) );
	set("env/wimpy", 60);
	set("chat_chance_combat", 90);  
	set("chat_msg_combat", ({
		"\n陈近南摇头叹道：螳臂当车，不自量力。唉，你这又是何苦呢?\n",
		(: command("say 这位" + RANK_D->query_respect(this_player())+",你我无冤无仇，何必如此?\n") :),
		(: command("unwield changjian") :),
		(: command("wield changjian") :),
                (: perform_action, "sword.slj" :),
                (: perform_action, "sword.duoming" :),
                (: perform_action, "sword.qi" :),
                (: perform_action, "sword.shen" :),
(: perform_action, "sword.jueming" :),
                (: perform_action, "cuff.hong" :),
                (: perform_action, "cuff.luan" :),
                (: perform_action, "cuff.yi" :),                	                	
                                
                (: perform_action, "strike.bafang" :),
                (: perform_action, "strike.baxianzuijiu" :),
                (: perform_action, "strike.jueming" :),                	                	


                (: perform_action, "claw.ji" :),
                (: perform_action, "claw.ningxue" :),
	}) );
 	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
	carry_object("/d/city2/obj/yaodai")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/city2/obj/hlbian");
	carry_object("/d/city/obj/gangdao");
}

string ask_me()
{
        mapping fam; 
        object ob;

        if (!(fam = this_player()->query("family")) 
	    || fam["family_name"] != "云龙门")
                return RANK_D->query_respect(this_player()) + 
                "与本派素无来往，不知此话从何谈起？";
        if (query("book_count") < 1)
                return "你来晚了，本派的云龙真经不在此处。";
        add("book_count", -1);
        ob = new("/clone/book/yljianpu");
        ob->move(this_player());
        return "好吧，这本「云龙剑谱」你拿回去好好钻研。";
}

void init()
{
	::init();
	add_action("do_join","join");
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("yunlong-shengong", 1) < 50)
	{
		command("say 我云龙神功乃内家武功，最重视内功心法。"); 
		command("say " + RANK_D->query_respect(ob) + 
			"是否还应该在云龙神功上多下点功夫？");
		return;
	}
	if ((int)ob->query("weiwang") <60)
	{
		command("say 我云龙门武功天下无敌，凡入我门，\n必闯荡江湖，行侠仗义，为天下苍生谋福利。\n"); 
		command("say " + RANK_D->query_respect(ob) + 
			"是否应该先出去闯一闯，做几件惊天动地的大事？");
		return ;
	}
	if ((int)ob->query("shen") >0&&(int)ob->query("shen") < 5000) {
		command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return ;
	}
	if(ob->query("weiwang")<80)
	{
		if((int)ob->query("shen")<0)
 command("say "+ RANK_D->query_respect(ob) +"虽然是邪派中人，但也还做了些好事。\n");
		command("chat 我天地会所作所为，无一不是前人所未行之事。\n");
		command("chat 万事开创在我，骇人听闻，物议沸然，又何足论？\n");
		command("chat 今天就收了你吧！！\n");
		command("chat 想不到我一身惊人艺业，今日终于有了传人，哈哈哈哈！！！！\n");
		message_vision(HIC "$N的江湖威望提高了！\n" NOR,this_player());
		ob->set("weiwang",80);
	}
	command("recruit " + ob->query("id"));
	if((!(string)ob->query("class")) || ((string)ob->query("class") != "fighter"))
		ob->set("class","fighter");
}


int ask_weiwang()
{
	command("tell "+this_player()->query("id")+" 你现在的江湖威望是 " +(string)(this_player()->query("weiwang")));
	say("\n陈近南说道：如果你威望值很高，有些人见了你不但不会杀你，还会教你武功，送你宝贝。\n"
	+"而且你还可以加入帮会，率领会众去攻打目标，就连去钱庄取钱也会有利息 。。。。。\n");
	say("陈近南又说：杀某些坏人或救某些好人可以提高江湖威望。\n");
	return 1;
}
int ask_tuihui()
{
	object ob;
	ob=this_player();

	if(ob->query("party/party_name") != HIR "天地会" NOR )
	{
message_vision("陈近南笑了笑，对$N说道：你还没加入我天地会呢，退什么退？\n", ob);
		return 1;
	}
	if(ob->query("family/family_name") == "云龙门" )
	{
message_vision("陈近南板着脸对$N说道：你已经是我云龙门弟子，如何能退会？\n", ob);
		return 1;
	}
	command("look "+ob->query("id"));
	command("sigh ");
	command("say 反清复明，就要坚贞志士，你去吧! ");
	ob->delete("party");
	ob->delete("rank");
	ob->delete("level");
	return 1;
}                                           

int ask_job()
{

        object me = this_player();
        object ob;
        mapping quest;
        mapping skl; 
        string *sname, place;        
        int i, skill = 0;
        quest = ("/quest/where")->query_quest();

        skl = me->query_skills();
        if ( !skl ) {
                tell_object(me, "你去学一些本事先吧！\n");
                return 1;
                }
        sname  = sort_array( keys(skl), (: strcmp :) );
        for(i=0; i<sizeof(skl); i++) 
                if (skl[sname[i]] >= skill && sname[i] != "literate" && sname[i] != "taoism")

                        skill = skl[sname[i]];
                        
        if (skill < 80) skill = 80;

        if( me->query("family/family_name") != "云龙门")
           {
                      message_vision("$N对着$n说道。你是哪里来的奸细？\n", this_object(), me);
                      return 1;
            }

           if (me->query("combat_exp") < 100000) {
                command("say " + RANK_D->query_respect(me) + "救反清义士的事没那么容易，你还是练高经验再来吧");
                return 1;
}
if ((int)me->query_condition("guojob2_busy"))
           {
                      message_vision("$N对着$n说:现在没有任务,你等会再来吧!\n", this_object(), me);
                      return 1;
            }  
      if( (int)me->query_skill("yunlong-shengong",1) < 50)
            {
                message_vision("$N对着$n大喝一声：你的本门内功不够！\n", this_object(), me);
                return 1;
            }
        if ((int)me->query_condition("menpai_busy"))  
            {
                      message_vision("$N对着$n摇了摇头说：你等会再来!\n", this_object(), me);
                      return 1;
            }
        if (me->query("potential") < 200 || me->query("combat_exp") < 300) {
                command("say 你的潜能太少了!!");
                return 1;
        }
    if( me->query_temp("yljob2"))
    {
                tell_object(me,HIW"你现在有别的任务！\n"NOR);
                return 1;
    } 

    me->delete_temp("yljob2");
	  me->delete_temp("yljob2/changxi");
	  me->delete_temp("yljob2/where");
	  me->delete_temp("yljob2/cx");

        if (me->query("kill_yunlong") == 1) {
                command("kick " + me->query("id"));
                command("say 我不是给了你任务了吗？");
                return 1;
                }
        else {
                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "反清复明，就要坚贞志士，你去吧!");
                command("say " + me->query("id") + " 有一个反清义士被抓了，要送往京城，要在『" + quest["short"]             + "』路过，快去救人吧！\n" NOR);
                me->set("kill_yunlong", 1);
                me->set("quest/quest_type", "救");
                me->set("quest/quest", "反清义士");
                me->set("task_time", time() + 300);
                me->apply_condition("menpai_busy",22);
                ob = new(__DIR__"shangdui",1);
                ob->move(quest["place"]);
                ob->set_temp("owner/id",me->query("id"));
                ob->set("combat_exp", me->query("combat_exp"));
                ob->set("max_force", me->query("max_force"));
                ob->set("eff_kee", me->query("max_kee"));
                ob->set("max_kee", me->query("max_kee"));
                ob->set("kee", me->query("max_kee"));
                ob->set_skill("dodge", skill);
                ob->set_skill("force", skill);
                ob->set_skill("parry", skill);
                
                ob->set("force_factor", random(10));   
                return 1;
               }                              
}

int ask_fail()
{
        object me = this_player();
        
        if (me->query("kill_yunlong") == 1) {
                command("pk1");
                command("say 我看错你了，我只能派别人去救反清义士,扣你150点POT.");
                me->add("potential",-50);
                me->delete("kill_yunlong");
                me->apply_condition("menpai_busy",10);
                return 1;
                }
}

int do_gongzuo()
{      
        mapping changxi,changxiwhere;
        object me,ob;
        me = this_player(); 
        
    if( me->query_temp("yljob2/changxi")>0)
    {
                tell_object(me,HIW"你快去做反清复明的宣传吧！\n"NOR);
                return 1;
    } 
        if ((int)me->query_condition("yl2_busy"))  
            {
                      message_vision("$N对着$n摇了摇头说：你刚要过任务,等会再来!\n", this_object(), me);
                      return 1;
            }

        if( me->query("family/family_name") != "云龙门")
           {
                      message_vision("$N对着$n说道。你是哪里来的奸细？\n", this_object(), me);
                      return 1;
            }

    changxi = this_object()->query_changxi();
    changxiwhere = changxi["where"];
    message_vision(HIC"陈近南对$N说道：你去" + changxi["changxi"] + "去宣传反清复明的道理吧。\n"NOR,me); 
        me->set_temp("yljob2/changxi", 1);
        me->set_temp("yljob2/where",changxiwhere);
        me->set_temp("yljob2/cx",changxi["changxi"]);

me->apply_condition("yl2_busy", 4);
        ob=new(__DIR__ "ling");
        ob->move(me);
    message_vision(HIC"陈近南对$N说道：这些资料你拿去做宣传(xuanchuan)吧。\n"NOR,me); 
        return 1;   
}

int ask_done()
{      

        object me,ob;
int exp,pot;
exp=80+random(20);
pot=50+random(85);

        me = this_player(); 
        
        if( me->query("family/family_name") != "云龙门")
           {
                      message_vision("$N对着$n说道。你是哪里来的奸细？\n", this_object(), me);
                      return 1;
            }
  
    if( me->query_temp("yljob2/changxi")< 1)
    {
                tell_object(me,CYN"你没事做吗？。\n"NOR);
                return 1;
    } 

    if( me->query_temp("yljob2/done")< 1)
    {
                tell_object(me,HIW"我听说好像宣传的目的还没有达到？快去宣传吧。\n"NOR);
                return 1;
    }
    message_vision(HIG"陈近南对$N说道：做得不错！给你些奖励吧。\n"NOR,me); 

        me->delete_temp("yljob");
    me->delete_temp("yljob2");
	  me->delete_temp("yljob2/changxi");
	  me->delete_temp("yljob2/where");
	  me->delete_temp("yljob2/cx");
exp=exp/2+8;
addnl(me,"exp",exp);	  

    return 1;
}

int ask_me2()
{
	int i;
        object fang;
	object who = this_player();
	object where = environment(who);
	
		  	if(((int)who->query("jinyong/book7")!=1))
	{
		message_vision("$N对$n说道： 你见了独臂神尼了吗?\n",this_object(),who);
		return 1;	
	}

	
        if( who->is_fighting())
        {
		message_vision("$N对$n说道： 你打玩再说吧！\n",this_object(),who);
		return 1;	
	}
	

		
		
        fang = present("guan bing",where);
	if(fang)
	{
		who->start_busy(3);
		message_vision("$N对$n说道： 这位"+ RANK_D->query_respect(who) +"先帮我战败宫兵吧。\n",this_object(),who);
		return 1;
	}
        fang = present("hai gonggong",where);
	if(fang)
	{
		who->start_busy(3);
		message_vision("$N对$n说道： 这位"+ RANK_D->query_respect(who) +"先帮我战败大内高手吧。\n",this_object(),who);
		return 1;
	}


      if(!query("iskillok"))
      {
      message_vision("突然从门外突然杀进一队官军 对$n说道： 反贼，受死吧!\n",this_object(),who);	
      	fang = load_object("/d/city/npc/bing");
	fang->move(environment(who));	
	fang->kill_ob(who);
      	fang = load_object("/d/beijing/npc/killchen");
	fang->move(environment(who));	
	fang->kill_ob(who);
     this_object()->set("iskillok",1);
     set("iskillok",1);
      return 1;
      }	

 



	command("thank " + who->query("id"));
	message_vision("$N对$n说道： 多谢 相助。\n",this_object(),who);
	message_vision("$N对$n说道： 不愧是独臂神尼介绍来的高手。\n",this_object(),who);
	message_vision("$N对$n说道： 再请帮个忙，去帮一下北京东门外的庄夫人吧。\n",this_object(),who);
	who->set_temp("book721",1);

	//call_out("destroying", 0); 
	//this_object()->kill_ob(who);
	return 1;
}


#include "/kungfu/class/yunlong/tiandihui.h";