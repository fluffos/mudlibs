// zhang.c 张三丰
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me_1();
string ask_me_2();
void create()
{
	set_name("张三丰", ({ "zhang sanfeng", "zhang" }));
	set("nickname", "邋遢真人");
	set("long", 
		"他就是武当派开山鼻祖、当今武林的泰山北斗张三丰真人。\n"
		"身穿一件污秽的灰色道袍，不修边幅。\n"
		"身材高大，年满百岁，满脸红光，须眉皆白。\n");
	set("gender", "男性");
	set("age", 100);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 50);
	set("int", 50);
	set("con", 50);
	set("dex", 50);
	set("qi", 28000);
	set("max_qi", 28000);
	set("jing", 28000);
	set("max_jing", 28000);
	set("neili", 55000);
	set("max_neili", 55000);
	set("jiali", 100);
	set("combat_exp", 9000000);
	set("score", 600000);
	set("shen", 200000);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "unarmed.zhenup" :),
                (: perform_action, "unarmed.tu" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.jielidali" :),
                (: perform_action, "hand.leiting" :),
                (: perform_action, "hand.mian" :),
                (: perform_action, "strike.zheng" :),	
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.chanup" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.zhenwu" :),
                (: perform_action, "sword.lian" :),                
        }) );
set_skill("claw", 250);
set_skill("strike", 380);
	set_skill("force", 550);
	set_skill("taiji-shengong", 380);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 380);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 380);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("taiji-jian", 380);
	set_skill("liangyi-jian", 150);
	set_skill("wudang-array", 380);
	set_skill("array",100);
	set_skill("taoism", 500);
	set_skill("literate", 200);
	set_skill("yitian-tulong", 380);
	set_skill("juehu-shou", 380);
	set_skill("raozhi-roujian", 380);
	set_skill("wudang-mianzhang", 380);
	set_skill("hand", 280);
	set_skill("paiyun-shou", 380);
	set_skill("shenmen-jian", 380);
	set_skill("yitian-zhang", 280);
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-quan");
	map_skill("sword", "taiji-jian");
		map_skill("hand", "paiyun-shou");
			map_skill("strike", "yitian-zhang");
//prepare_skill("hand", "paiyun-shou");
//prepare_skill("strike", "yitian-zhang");
set("count",1);
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
        set("inquiry", ([
                "真武剑" : (: ask_me_1 :),
                  "考验" : (: ask_me_2 :),
        ]));
	create_family("武当派", 1, "开山祖师");
	set("class", "taoist");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("guarded") < 5) {
                command("say " + RANK_D->query_respect(ob) +
                        "你对我武当派尽了多少心力，有几分忠心呢？");
                return;
        }
	if ((int)ob->query_skill("taiji-shengong", 1) < 60) {
		command("say 我武当派乃内家武功，最重视内功心法。"); 
		command("say " + RANK_D->query_respect(ob) + 
			"是否还应该在太极神功上多下点功夫？");
		return;
	}
    if ((int)ob->query_skill("taoism", 1) < 80)
    {
        command("say 我武当派乃道家武功，高深的武功离不开道学心法。");
        command("say " + RANK_D->query_respect(ob) +
            "是否还应该多读读道德经？");
        return;
    }
	if ((int)ob->query("shen") < 2000) {
		command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}
	if (ob->query_int() < 30) {
		command("say 我武当派武功全从道藏悟出。");
		command("say 要能达到炉火纯青之境，体质什么的倒是无关紧要，悟性却是半点也马虎不得。");
		command("say " + RANK_D->query_respect(ob) + "的悟性还大有潜力可挖，还是请回吧。");
		return;
	}
	command("chat 哈哈哈哈！！！！");
	command("chat 想不到老道在垂死之年，又觅得一个可塑之才，真是可喜可贺。");
	command("recruit " + ob->query("id"));
}

string ask_me_1()
{
        mapping fam; 
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] !="武当派")
                return RANK_D->query_respect(this_player())+"与本派素无来往，不知此话从何谈起？";

        if (!this_object()->query("count"))
		return "啊！我真老糊涂了，剑不知放哪了。\n";

        command("pat "+ (string)this_player()->query("id"));
        return "此剑乃本门镇山之宝！不经过考验我如何能放心交你保管？\n";
}

string ask_me_2()
{
        mapping fam; 
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] !="武当派")
                return RANK_D->query_respect(this_player())+"与本派素无来往，不知此话从何谈起？";
        command("thumb "+ (string)this_player()->query("id"));
           return "你把郭女侠送我的礼物找来，就算你通过考验！你到我年轻时练功的附近找吧。\n";
}

int accept_object(object who, object ob)
{
        object sword, me;
        mapping fam;
        me = this_object();

        if (!(fam = this_player()->query("family")) || fam["family_name"] !="武当派")
           {
             command("thank "+ (string)who->query("id"));
             command("say 你与本派素无来往，不知为何送如此厚礼？ \n");
//        call_out("destroying", 1, ob);
             return 0;
            }
        
    if (fam["generation"] == 2)
        if ((string)ob->query("id") == "tie luohan")
        {
            command("goodkid "+(string)who->query("id"));
            call_out("destroying", 1, ob);
	    if (present("zhenwu jian", who)) {
                command("? " + who->query("id"));
                command("say 不是已经给你了吗？");
		return 1;
	    }
            if (!me->query("count")) {
                command("say 啊！真老糊涂了，剑不知放哪了。\n");
                return 1;
            }
            sword = new("/clone/unique/zhenwu-jian");
            sword->move(this_player());
	    me->set("count", 0);
            command("say 你如果用这剑为非做歹，我必取你性命!\n");
            return 1;
        }
        command("? "+ (string)who->query("id"));
        command("say 今天不是老道的生日，你送什么礼呀！");

//    call_out("destroying", 1, ob);
    return 0;
}

void destroying(object obj)
{     
    if (!obj) return;
    if (userp(obj)) command("drop "+obj->parse_command_id_list()[0]);
    else destruct(obj);
}
