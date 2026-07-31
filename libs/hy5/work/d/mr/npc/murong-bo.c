 // /u/beyond/mr/npc/murong-bo.c  慕容博
// this is made by beyond
// update 1997.6.23
inherit NPC;
inherit F_MASTER;
 string ask_huijia();
#include <ansi.h>
void create()
{
	set_name("慕容博",({"murong bo","murong","bo"}));
        set("title","姑苏慕容老爷子");
        set("nick","以彼之道 还施彼身");
	set("long", 
              "他就是天下号称以彼之道，还彼之身的姑苏慕容博。\n"
              "他脸上带着不可一世的笑容。\n");
        set("age", 57);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 60);
	set("int", 60);
	set("con", 60);
	set("dex", 60);
	
	set("max_qi", 86500);
	set("max_jing", 86500);
	set("neili", 88500);
	set("max_neili", 88500);
	set("jiali", 50);
	set("combat_exp", 9000000);
	set("score", 50000);                
        set_skill("xingyi-zhang",380);
        set_skill("strike",280);
        set_skill("finger",280);
        set_skill("dodge",280);
        set_skill("force", 280);
	set_skill("canhe-zhi", 380);
	set_skill("murong-jianfa",380);       
        set_skill("shenyuan-gong", 380);
	set_skill("yanling-shenfa", 380);
        set_skill("douzhuan-xingyi", 380);
	set_skill("parry", 320);
	set_skill("sword", 300);
	set_skill("literate", 300);
        set_skill("murong-daofa", 380);
        set_skill("blade",250);
         set_skill("hand", 380);
         set_skill("qxxy-shou", 380);
        set_skill("six-sword",380);       
        map_skill("blade", "murong-daofa");
        map_skill("finger", "canhe-zhi");
        map_skill("hand", "qxxy-shou");
	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
        map_skill("parry", "douzhuan-xingyi");
	//if (random(3)==0)	map_skill("parry", "murong-jianfa");
	map_skill("sword", "six-sword");
                map_skill("strike", "xingyi-zhang");
       prepare_skill("finger", "canhe-zhi");
        prepare_skill("hand", "qxxy-shou");

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "parry.xingyi" :),
                 (: perform_action, "parry.yihuajiemu" :),
                (: perform_action, "finger.ci" :),
                (: perform_action, "finger.dianxue" :),
                 (: perform_action, "finger.jin" :),
                (: perform_action, "finger.canshang" :),
                 (: perform_action, "finger.lian" :),
                (: perform_action, "sword.lhj" :),
                (: perform_action, "sword.nbajian" :),
                (: perform_action, "sword.tx" :),
                (: perform_action, "sword.wbajian" :),
             		(: command("unwield sword") :),
		               (: command("wield sword") :),  
                (: perform_action, "dodge.yanling" :),                
                   (: perform_action, "strike.riyue" :),
                	(: perform_action, "strike.xingdian" :),
                (: perform_action, "hand.po" :),
                 (: perform_action, "hand.xy" :),
                (: perform_action, "hand.zhai" :),

        }));
                set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
        create_family("姑苏慕容",1,"弟子");

       	set("inquiry", 
                ([
                        "name" : "我就是以彼之道，还施彼身的姑苏慕容博。\n",
                        "here" : "这里是少林寺的藏经楼。\n",
                        "rumors" : "我那慕容复儿在武林之中闯出了名头，老爷子我是真高兴呀！\n",
                         "带头大哥" : (: ask_huijia :),
                ]));
       	setup();
	carry_object("/clone/weapon/gangjian")->wield();
    carry_object("/clone/misc/cloth")->wear();
	
}
void attempt_apprentice(object ob)
{
          object me  = this_player();
 
        string name, new_name;
	name = ob->query("name");
 
        if (present("jiaxin", me))
         {  destruct(present("jiaxin",me));

           command("say 好吧，既然" + RANK_D->query_respect(ob) + "有我儿的信件，难为你" +
		"如此辛苦跑来，我就收下你吧。");
 
           new_name = "慕容" + name[2..3];
	   ob->set("name", new_name);
           command("say 从今以后你就叫做" + new_name + "，希望你能把慕容功夫发扬光大！");
           command("recruit " + ob->query("id"));
           command("chat 淡淡一笑，谁言 以彼之道 还施彼身 绝迹江湖！");
           command("chat* haha"); 
         }
        else
          command("say 我慕容博岂能随便收徒!");
        return;
           
}
 

string ask_huijia()
{
	int i;
	object fang,who,where;
object me=this_player();
object ob = this_object();
	who=me;
	where = environment(who);

if(!me->query_temp("killtlbb81") )
return "听说大轮明王来少林，你先去找找他吧。。。\n";

if(!me->query_temp("killtlbb82") )
return "听说星宿老怪来少林，你先去找找他吧。。。\n";
if((int)me->query("jinyong/book4")>8 )
return "我已经认命了。。。\n";
if(me->query("jinyong/book4")!=8 )
return "我不知道什么带头大哥的事啊。。。\n";



if(me->is_fighting() )
return "你正在战斗中呢。。。\n";

      if(!query("iskillok"))
      {
      message_vision("突然从周围杀进了一个黑布蒙面人 说道：我的大仇人 终于找到了 !\n",this_object(),who);	
      	fang = load_object("/d/mr/npc/xiaoyuanshan");
	fang->move(environment(who));	
	fang->kill_ob(who);

     this_object()->set("iskillok",1);
     set("iskillok",1);
return "我就是带头大哥。 \n";
      }	

        fang = present("xiao yuanshan",where);
	if(fang)
	{
		who->start_busy(3);
return "先对付萧远山吧 \n";
	}

if(!me->query_temp("killtlbb83") )
return "你帮我对付了萧远山了不?\n";

me->set_temp("killtlbb84",1);
kill_ob(me);
return "即然你知道了我的秘密 你也去死吧.\n";
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


  	if(who->query_temp("killtlbb84") && !query("iskillok1"))
	{
      message_vision(HIR"$N说道：我要复国.....\n" NOR,this_object());
      message_vision(HIR"$N运起斗转星移功，吐出一口鲜血...又精神起来了。\n" NOR,this_object());
	who->start_busy(6);
	this_object()->set("qi", 59000);
	this_object()->set("eff_qi", 59000);
	this_object()->set("max_qi", 59000);
	this_object()->set("jing", 59200);
	this_object()->set("max_jing", 59200);
	this_object()->set("neili", 57500);
	this_object()->set("max_neili", 57500);
     this_object()->set("iskillok1",1);
     set("iskillok1",1);	
     this_object()->kill_ob(who);
     who->kill_ob(this_object());
	return;
	}
  	if(((int)who->query("jinyong/book4")>=9) || !who->query_temp("killtlbb84"))
	{
//::die();	
	}
        else if(who) {
        	message_vision(RED"$N说道：我骗了阿紫，萧峰现在在辽国人手上，回不来了，哈哈哈 .....\n"NOR NOR,this_object());
		i = 800+random(2000);
		who->set("jinyong/book4",9);
		who->add("combat_exp",i+30000);
		who->add("potential",i*25);
		who->add("mpgx",10);
		who->add("expmax",2);
		//command("chat "+this_player()->query("name")+"胆色过人，义惩青城恶霸。");
		tell_object (who,"你赢得了"+chinese_number(i+30000)+"点经验"+
		           chinese_number(i*45)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
		who->save();
        }
	 call_out("leavet",1);

}
void leavet()
{
        object ob = this_object();
	message_vision(HIG"$N在一阵佛号声中，被一个扫地老僧救走..\n"NOR NOR,this_object());

        destruct(this_object());
}
