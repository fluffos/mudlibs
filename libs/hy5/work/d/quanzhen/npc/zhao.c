// zhao.c 赵志敬
// By Lgg,1998.10
#include <ansi.h>
inherit NPC;
int ask_wldh();
void create()
{
        set_name("赵志敬", ({"zhao zhijing", "zhao"}));
        set("gender", "男性");
        set("age", 26);
        set("title", HIY "蒙古大汗亲封全真教掌教" NOR);
        set("class", "taoist");
        set("long",
                "他就是全真教第三代弟子中的好手，王处一的大弟子赵志敬。 \n"
                "他相貌端正，但眉宇间似乎隐藏着一丝狡猾的神色。\n"
		"他是一个长须道人，看起来却有些煞气。\n");
        set("attitude", "friendly");
        set("shen_type",-1);
        set("str", 25);
        set("int", 26);
        set("con", 26);
        set("dex", 25);

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({

                (: perform_action, "strike.ju" :),
                (: perform_action, "sword.jianzhen" :),
                (: perform_action, "sword.chunyang" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.qixing" :),
                (: perform_action, "sword.sanqing" :),
                (: perform_action, "sword.qixinggongyue" :),
        }));

        set("qi", 35500);
        set("max_qi", 35500);
        set("jing", 13800);
        set("max_jing", 13800);
        set("neili", 23000);
        set("max_neili", 23000);
        set("jiali", 60);

        set("combat_exp", 560000);
        set("score", 100000);
set_skill("qixing-jian",250);
set_skill("qixing-shou",250);
set_skill("qixing-array",110);
set_skill("hand", 150);
        set_skill("force", 180);
        set_skill("xiantian-qigong", 180);    //先天气功
        set_skill("sword", 180);
        set_skill("quanzhen-jian",250);  //全真剑
        set_skill("dodge", 170);
        set_skill("jinyan-gong", 170);   //金雁功
        set_skill("parry", 180);
        set_skill("unarmed",180);
        set_skill("strike",180);
        set_skill("haotian-zhang", 180);    //昊天掌
        set_skill("literate",160);
        set_skill("taoism",160);

        map_skill("force", "xiantian-qigong");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jian");
        map_skill("strike", "haotian-zhang");
        prepare_skill("strike", "haotian-zhang");

        create_family("全真教", 3, "弟子");


    set("inquiry", ([
"全真教" :  "我全真教是天下道家玄门正宗。\n",
"全真掌门" : (: ask_wldh() :),
		 ]));   
        setup();
	set_temp("apply/attack", 150);
	set_temp("apply/defense", 150);
	set_temp("apply/damage", 560);
	set_temp("apply/armor", 560);
        carry_object("/clone/weapon/changjian")->wield();
        carry_object(__DIR__"obj/grayrobe")->wear();

}

void attempt_apprentice(object ob)
{
        command("say 好吧，我就收下你这个徒弟了。");
        command("recruit " + ob->query("id"));
}

int ask_wldh()
{

        object me = this_player();
        object ob,where,who,fang;
        mapping quest;
        mapping skl; 
        string *sname, place;        
	
        int i, skill = 0;
	
        ob=this_object();
        who=me;
        where = environment(who);
        if(((int)me->query("jinyong/book10")!=4))
           {
                      message_vision("$N对着$n说道。我就是蒙古大汗亲封全真教掌教。\n", this_object(), me);
	                      return 1;
            }


if (me->is_busy())

            {
                      message_vision("$N对着$n说道。我就是蒙古大汗亲封全真教掌教。\n", this_object(), me);
	                      return 1;
            }
 
 if (me->is_fighting())

            {
                      message_vision("$N对着$n说道。我就是蒙古大汗亲封全真教掌教。\n", this_object(), me);
	                      return 1;
            }
 
         fang = present("yin kexi",where);
	if(fang)
	{
                command("say " + RANK_D->query_respect(me) + "你还是和尹克西谈谈吧!");
                fang->kill_ob(who);
                return 1;
	}

         fang = present("xiaoxiang zi",where);
	if(fang)
	{
                command("say " + RANK_D->query_respect(me) + "你还是和潇湘子谈谈吧!");
                fang->kill_ob(who);
                return 1;
	}
	
         fang = present("ma guangzuo",where);
	if(fang)
	{
                command("say " + RANK_D->query_respect(me) + "你还是和马光佐谈谈吧!");
                fang->kill_ob(who);
                return 1;
	}
	
         fang = present("ni moxing",where);
	if(fang)
	{
                command("say " + RANK_D->query_respect(me) + "你还是和尼摩星谈谈吧!");
                fang->kill_ob(who);
                return 1;
	}
	
	

        if (!me->query_temp("book1051")) {
                command("kick " + me->query("id"));
                command("say 你没有资格和本掌教说话。");
                return 1;
                }
	
        if (!me->query_temp("book1052")) {
                command("kick " + me->query("id"));
                command("say 你没有资格和本掌教说话。");
                return 1;
                }
                
        if (!me->query_temp("book1053")) {
                command("kick " + me->query("id"));
                command("say 你没有资格和本掌教说话。");
                return 1;
                }

        if (!me->query_temp("book1054")) {
                command("kick " + me->query("id"));
                command("say 你没有资格和本掌教说话。");
                return 1;
                }
me->set_temp("book1055",1);
                command("kill " + me->query("id"));
                command("say " + me->query("id") + "你尽然敢坏我的好事，去死吧！" NOR);
                

                return 1;
                             
}

void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;

  	if((int)who->query("jinyong/book10")==4 && who->query_temp("book1055"))
{
		message_vision("$N说道：我才是全真掌教！你们都去死.....\n" NOR,this_object());
		i = 1800+random(2000);
		who->set("jinyong/book10",5);
		who->add("combat_exp",i+15000);
		who->add("potential",i*18);
		who->add("mpgx",10);
		who->add("expmax",2);
		//command("chat "+this_player()->query("name")+"胆色过人，义惩青城恶霸。");
		tell_object (who,"你赢得了"+chinese_number(i+15000)+"点经验"+
		           chinese_number(i*18)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
		who->save();
}
     
::die();
}