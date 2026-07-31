// qiao-feng.c

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;
int ask_duan2();
string ask_me();

void create()
{
	set_name("乔峰", ({"qiao feng", "feng", "qiao"}));
	set("nickname", "北乔峰");
	set("gender", "男性");
	set("age", 29);
	set("long", 
"他就是丐帮第十任帮主，在江湖上与燕子坞的慕容复并称为「北乔峰，南慕容」。
他身穿一件普通的粗布褂子，腰间用一条麻绳随便一系。他身高六尺有余，体格
十分魁梧，长有一张线条粗旷、十分男性化的脸庞，双目如电，炯炯有神。\n");
	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 10);
	
	set("str", 330);
	set("int", 24);
	set("con", 330);
	set("dex", 324);

        set("qi", 132500);
	set("max_qi", 132500);
	set("jing", 133800);
	set("max_jing", 133800);
	set("neili", 333000);
	set("max_neili", 333000);
	set("jiali", 300);
	
	set("combat_exp", 9000000);
	set("score", 200000);
	set("shen", 100000);
	 
		set_skill("fengmo-zhang",380);
	set_skill("liuhe-zhang",380);
	set_skill("strike",390);
	set_skill("force", 250);             // 基本内功
	set_skill("huntian-qigong", 380);    // 混天气功
	set_skill("unarmed", 300);           // 基本拳脚
	set_skill("xianglong-zhang", 380);   // 降龙十八掌
	set_skill("dodge", 200);      	     // 基本躲闪
	set_skill("xiaoyaoyou", 380);        // 逍遥游
	set_skill("parry", 300);             // 基本招架
	set_skill("staff", 300);             // 基本棍杖
	set_skill("dagou-bang", 380);        // 打狗棒法
	set_skill("begging", 200);           // 叫化绝活
	set_skill("checking", 300);          // 道听途说
	set_skill("training", 300);         // 驭兽术
	
	set_skill("yuejia-qiang", 380);        // 打狗棒法
	set_skill("suohou-gong", 380);        // 打狗棒法
set_skill("chansi-shou", 380);        // 打狗棒法
set_skill("claw", 380);        // 打狗棒法
set_skill("hand", 380);        // 打狗棒法	
set_skill("club", 380);        // 打狗棒法		
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "dagou-bang");
	map_skill("staff", "dagou-bang");
	map_skill("strike", "xianglong-zhang");
map_skill("claw", "suohou-gong");
map_skill("hand", "chansi-shou");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "staff.chan" :),
                (: perform_action, "staff.ban" :),
                (: perform_action, "staff.feng" :),
                (: perform_action, "staff.zhuan" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.wugou" :),                
                (: command("unwield lvyv bang") :),
                (: command("wield lvyv bang") :),
                (: perform_action, "unarmed.mielong" :),
                (: perform_action, "unarmed.mielong" :),
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.hui" :),                
                (: perform_action, "unarmed.fei" :),                
                (: perform_action, "unarmed.qu" :),                
                (: perform_action, "unarmed.zhen" :),                
                (: perform_action, "unarmed.leiting" :),                
                (: perform_action, "unarmed.xianglong" :),                                
                (: perform_action, "dodge.gjtq" :),     
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.maishou" :),                                
        }) );
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
        set("inquiry", ([
          "契丹人" : (: ask_duan2 :),
          "契丹" : (: ask_duan2 :),
           ]));


	set("book_count", 1);
	set("party/party_name", HIC"丐帮"NOR);
	set("party/rank", HIR"帮主"NOR);
	set("party/level", 10);
	create_family("丐帮", 10, "帮主");

	setup();
	
	carry_object(__DIR__"obj/lvyv_bang");
	carry_object(__DIR__"obj/cloth")->wear();
//      carry_object(BOOK_DIR"stick_book")->wear();
}

void init()
{
 	object ob; 
	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_qiecuo","qiecuo");
}


void greeting(object me)
{
       	mapping myfam;
	myfam = (mapping)me->query("family");
	if((myfam["family_name"] == "丐帮")&&(!me->query_skill("huntian-qigong",1))&&(me->query("combat_exp")>500000))
        {
                command("say 你竟敢放弃本门心法！从我这里滚出去吧！");
                command("expell " + me->query("id"));
        }
        
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_str() < 20 || (int)ob->query_con() < 20)
	{
		command("say 当叫化子需要能吃苦耐劳，依我看" + RANK_D->query_respect(ob) + "的资质似乎不适合当叫化子？");
		return;
	}
	if ((string)ob->query("family/family_name") != "" &&
	    (string)ob->query("family/family_name") != "丐帮")
	{
		command("say " + RANK_D->query_respect(ob) + "既然已有名师指点，何必又来拜我呢？");
		return;
	}


	if ((int)ob->query_skill("huntian-qigong",1) < 180)
	{
		command("say 你的混天气功修为不够。\n");
		return;
	}

	if ((int)ob->query_skill("xianglong-zhang",1) < 180)
	{
		command("say 你的降龙十八掌修为不够。\n");
		return;
	}
	
	if ((int)ob->query_skill("dagou-bang",1) < 180)
	{
		command("say 你的打狗棒修为不够。\n");
		return;
	}
	
	command("recruit "+ob->query("id"));
}






void dest(object me,object ob)
{      
       object room;

       destruct(me);
       return;
}





int ask_duan2()
{
        object me,ob,obj,fang;
        int i;
        ob=this_player();
        me=this_object();

if ((int)ob->query("jinyong/book4")!=4)
{
message_vision("$N你在说什么，我听不懂。\n", me, ob);
return 1;	
}    


    if(!ob->query_temp("killtlbb9"))
{
message_vision("$N你在说什么，我听不懂。\n", me, ob);
return 1;	
}    

      
       if(!ob->query_temp("killtlbb13") && !query("iskillok"))
      {
      message_vision("突然从附近杀出一群丐帮长老 大声说道： 打狗大阵!\n",this_object(),ob);	
      	fang = load_object(__DIR__"xiang");
	fang->move(environment(ob));	
	fang->kill_ob(ob);

      	fang = load_object(__DIR__"song");
	fang->move(environment(ob));	
	fang->kill_ob(ob);

      	fang = load_object(__DIR__"xu");
	fang->move(environment(ob));	
	fang->kill_ob(ob);

      	fang = load_object(__DIR__"xi");
	fang->move(environment(ob));	
	fang->kill_ob(ob);


     this_object()->set("iskillok",1);
     set("iskillok",1);
      }	
       
        
    if(!ob->query_temp("killtlbb10"))
{
message_vision("$N你帮我过了打狗大阵了吗？。\n", me, ob);
return 1;	
}    

    if(!ob->query_temp("killtlbb11"))
{
message_vision("$N你帮我过了打狗大阵了吗？。\n", me, ob);
return 1;	
}         

    if(!ob->query_temp("killtlbb12"))
{
message_vision("$N你帮我过了打狗大阵了吗？。\n", me, ob);
return 1;	
}      

    if(!ob->query_temp("killtlbb13"))
{
message_vision("$N你帮我过了打狗大阵了吗？。\n", me, ob);
return 1;	
}      
        
        
        message_vision("$N道：“即然众兄弟如此 我也只能离开大家了。\n", me, ob);
if((int)ob->query("jinyong/book4")==4)
{
	i = 900+random(2200);
	ob->set("jinyong/book4",5);
	ob->add("combat_exp",i+12880);
	ob->add("potential",i*18);
	ob->add("mpgx",10);
	ob->add("expmax",2);
 
	tell_object (ob,"你赢得了"+chinese_number(i+12880)+"点经验"+
	           chinese_number(i*18)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
}

message_vision("$N道：“大家后会有期。\n", me, ob);
                ob->start_busy(4);
                remove_call_out("dest");
                call_out("dest",3,me,ob);

        return 1;

}