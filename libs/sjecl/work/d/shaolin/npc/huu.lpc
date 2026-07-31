inherit NPC;
string ask_me();

void create()
{
        set_name("慧云尊者", ({
                "huiyun zunzhe",
                "huiyun",
		"zunzhe",
	}));
	set("long",
                "他是一位身裁微胖的老僧，身穿一袭青布镶边袈裟。\n"
                "太阳穴微微下陷，一副没精打采的样子。\n"
	);

        set("gender", "男性");
	set("attitude", "friendly");
       set("class", "bonze");
	set("age", 50);
	set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 850);
        set("max_jing", 800);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 150);
        set("combat_exp", 250000);
	set("score", 100);
        set_skill("force", 100);
        set_skill("yijin-jing", 100);
        set_skill("dodge", 100);
        set_skill("shaolin-shenfa", 100);
        set_skill("club", 100);
        set_skill("weituo-gun", 120);
        set_skill("parry", 100);
        set_skill("buddhism", 100);
        set_skill("literate", 100);

    map_skill("force", "yijin-jing");
	map_skill("dodge", "shaolin-shenfa");
        map_skill("club", "weituo-gun");
        map_skill("parry", "weituo-gun");
        create_family("少林派", 38, "弟子");
	setup();
        carry_object("/d/shaolin/obj/qimeigun")->wield();
        carry_object("/d/shaolin/obj/hui-cloth")->wear();
	set("inquiry", ([
		"心禅七老"       : (: ask_me :),
                "心禅堂大阵"     : (: ask_me :)
	]));
}
 int accept_object(object who, object ob,object me)
{
        mapping fam;
        me=this_object();
        if (ob->query("id")!="baitie")
         {
           command("say 你给我这个东西干什么?\n");
// 除了baitie，不接受其它物品 River@SJ
             return 0;
          } 
        if(!who->query_temp("baitie")){
                command("say 你的拜贴是哪来的，别人转赐老衲恕不接待！");
                return 1;
	  }
        if (!(fam = this_player()->query("family")) 
           || fam["family_name"] != "少林派"){
                command("angry "+who->query("id"));
                command("say 好啊，你公然挑战我派，老衲让你知道厉害！");
                kill_ob(this_player());
        return 1;
             }
         call_out("destroying", 1, me, ob);           
         command("hmm");
         command("say 当年昆仑三圣何足道挑我少林，寺中高手无一是其敌手
                      连心禅七老都大受挫折。");
         command("say 此后他们苦练绝技，终身以抱负为念，使此等七位大智慧
                      的长老终不能成我佛家高僧大贤。");
         command("say 所以入这心禅堂也实是我少林凶险之处，虽也有不少高僧大
                      贤，可以入内清修。但我佛家首推禅理，武功乃是末节"+
                      RANK_D->query_respect(this_player()) +"何必定要冒此大险？
                      望你自决。");
        this_player()->set_temp("try",1);
                     return 1;

}
 
#include "huu.h"
