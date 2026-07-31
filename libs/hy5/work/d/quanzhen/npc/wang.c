// wang.c 王重阳
// By Lgg,1998.10

#include <ansi.h>

inherit NPC;

string ask_jiuyin();
string ask_zhipu();
string ask_duan();

void create()
{
        set_name("王重阳", ({"wang chongyang", "wang"}));
        set("gender", "男性");
        set("age", 66);
        set("class", "taoist");
        set("nickname",HIW"活死人"NOR);
        set("long",
                "他就是全真教的开山祖师、首代掌教王重阳王真人。他白须飘\n"
                "飘，宽袍缓袖，眉目清癯，颇有些仙风道骨的味道。他本来一\n"
                "腔热血欲报效国家力抗金兵，可惜朝廷腐败，于是心灰意冷，\n"
                "又从道德经中悟得了天地滋生的大道，手创全真教。\n");
        set("attitude", "peaceful");
        set("shen_type",1);
        set("str", 85);
        set("int", 85);
        set("con", 85);
        set("dex", 85);
        set("per", 85);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "hup" :),
                (: exert_function, "recover" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.jianqi" :),
                (: perform_action, "sword.sanqing" :),
                (: perform_action, "sword.tonggui" :),                
                (: perform_action, "sword.qixing" :),
                (: perform_action, "sword.qixinggongyue" :),
                (: perform_action, "unarmed.kong" :),
                (: perform_action, "unarmed.luanwu" :),                	
                (: perform_action, "unarmed.quan" :), 	
                (: perform_action, "unarmed.ming" :), 		
                (: perform_action, "unarmed.ruo" :),                	                	

                (: perform_action, "unarmed.dang" :),
                (: perform_action, "unarmed.shen" :),                	
                (: perform_action, "unarmed.fen" :), 	
                (: perform_action, "unarmed.hun" :), 		
                (: perform_action, "unarmed.jian" :),                	                	

                (: exert_function, "shield" :),                
                (: exert_function, "xiantiandafa" :),                
                (: exert_function, "powerup" :),                
        }));

        set("qi", 26500);
        set("max_qi", 26500);
        set("jing", 25400);
        set("max_jing", 25400);
        set("neili", 59000);
        set("max_neili", 59000);
        set("jiali", 100);

        set("combat_exp", 9000000);
        set("score", 500000);

        set_skill("force", 380);
        set_skill("xiantian-qigong", 390);    //先天气功
        set_skill("sword", 380);
        set_skill("quanzhen-jian",380);  //全真剑
        set_skill("dodge", 260);
        set_skill("jinyan-gong", 380);   //金雁功
        set_skill("parry", 280);
        set_skill("unarmed",280);
        set_skill("haotian-zhang", 380);    //昊天掌
        set_skill("array",580);
        set_skill("qixing-array",580);
set_skill("kongming-quan",380);
set_skill("qixing-jian",380);
set_skill("qixing-shou",380);
set_skill("hand", 300);
        set_skill("literate",220);
        set_skill("strike",350);
        set_skill("taoism",500);
        set_skill("finger",200);
        set_skill("sun-finger",200);  //一阳指
        map_skill("force", "xiantian-qigong");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "xiantian-qigong");
        map_skill("strike", "haotian-zhang");
        map_skill("finger","sun-finger");
        map_skill("unarmed","kongming-quan");
if (random(2)==0)	        map_skill("unarmed","xiantian-qigong");
        //prepare_skill("finger","sun-finger");
        //prepare_skill("strike","haotian-zhang");

        create_family("全真教", 1, "掌教");

        set("book_count",1);
        set("inquiry", ([
                "全真教" :  "我全真教是天下道家玄门正宗。\n",
                "九阴真经" : (: ask_jiuyin :),
                "一阳指" : (: ask_zhipu :),
                "段皇爷" : (: ask_duan :),
        ]) );
	set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 250);
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object(__DIR__"obj/greenrobe")->wear();

}

void attempt_apprentice(object ob)
{
        if (ob->query_int() < 30) {
                command("say 你的资质不够，还是先找我那几个徒弟学习吧。");
                return;
        }
        if ((int)ob->query_skill("xiantian-qigong",1) < 100 ) {
                command("say 你的本门内功心法火候不足,难以领略更高深的武功。");
                return;
        }
        if ((int)ob->query("shen")<10000) {
                command("say 行侠仗义是我辈学武人的基本品质，你若能多做些狭义之
事，我一定收你为徒。\n");
                return;
        }
        ob->set("class", "taoist");
        command("say 好吧，依你资质，定可传我衣钵，我就收下你这个徒弟了。");
        command("recruit " + ob->query("id"));
}

string ask_jiuyin()
{
        mapping fam;
        int lvl_force;

        if (!(fam = this_player()->query("family"))
            || fam["family_name"] != "全真教")
                return RANK_D->query_respect(this_player()) +
                "与本教毫无瓜葛，这话从何说起？";
        if (!(lvl_force = this_player()->query_skill("force",1))
            || lvl_force < 50)
                return RANK_D->query_respect(this_player()) +
                "的基本内功火候如此之浅，强练真经上的上乘武功有害无益。";
        return "九阴真经是天下武学正宗，我已交给我师弟周伯通保管，\n"
                +"不过....在古墓派的石棺内，我还刻着一些图形。\n";
}

string ask_duan()
{
        object me=this_player();
        if(me->query_temp("tmark/指")==4) {
                me->add_temp("tmark/指",1);
                return("段皇爷号称‘南帝’，家传的一阳指是天下最厉害的指法。\n");
        }
        else {
                me->set_temp("tmark/指",0);
                return("你问段皇爷做甚么，莫非想与他为难？\n");
        }
}

string ask_zhipu()
{
        object ob,me=this_player();
        if(me->query_temp("tmark/指")==5) {
                me->set_temp("tmark/指",0);
                if(query("book_count")>0) {
                        ob=new("/clone/book/zhifapu");
                        ob->move(me);
                        add("book_count",-1);
                        return("好吧，你历经艰苦，意志甚坚，这本指法谱就交给你了。\n");
                }
                else
                        return("你来晚了，指法谱已经被人取走了。\n");
        }
        else {
                me->set_temp("tmark/指",0);
                return  RANK_D->query_respect(me) +
                        "不是想跟我较量较量吧？\n";
        }
}
