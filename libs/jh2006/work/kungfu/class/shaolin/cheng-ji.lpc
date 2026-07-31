// Npc: /kungfu/class/shaolin/cheng-ji.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;
int ask_wuse();
string ask_luohan();

void create()
{
	set_name("澄寂", ({
		"chengji luohan",
		"chengji",
		"zhihui",
		"luohan",
	}));
	set("long",
		"他是一位须发花白的老僧，身穿一袭金边黑布袈裟。他身材瘦高，\n"
		"太阳穴高高鼓起，似乎身怀绝世武功。\n"
	);

	set("nickname", "智慧罗汉");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 60);
	set("shen", 5000);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 500000);
    set("unique", 1);

	set_skill("force", 100);
	set_skill("yijin-jing", 100);
	set_skill("dodge", 100);
	set_skill("shaolin-shenfa", 100);
	set_skill("club", 100);
	set_skill("weituo-gun", 100);
	set_skill("parry", 100);
	set_skill("buddhism", 100);
        set_skill("yizhi-chan", 100);
        set_skill("finger", 100);
	set_skill("literate", 100);

	map_skill("force", "yijin-jing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("club", "weituo-gun");
	map_skill("parry", "weituo-gun");
        map_skill("finger", "yizhi-chan");
        set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(: perform_action, "finger.wofu" :)
	}));    
        prepare_skill("finger", "yizhi-chan");    

	create_family("少林派", 37, "弟子");
        set("inquiry", ([
                 "无色禅师" : (: ask_wuse :),
                 "铁罗汉" : (:ask_luohan:),
	]));
        set("luohan_count",1);
        setup();

        carry_object("/d/shaolin/obj/qimeigun")->wield();
        carry_object("/d/shaolin/obj/cheng-cloth")->wear();
}


#include "/kungfu/class/shaolin/cheng.h"

 int ask_wuse()
{
  say("澄寂大师说道：无色大师是我少林前辈名僧，凭着一身精纯的武功\n"
      "做下许多行侠仗义之事，当年与古墓派的神雕杨大侠，峨嵋祖师郭女\n"
      "侠都是好友。他执掌罗汉堂三十年间总结我本派绝技，将我派攻防之\n"
      "大成集中于一套罗汉拳之中，算来是我罗汉堂中的第一高僧。哈哈哈\n"             
      );
  this_player()->set_temp("marks/罗汉",1); 
  return 1;
 }
 string ask_luohan()
{
 object ob;
 mapping fam;

	if (!(fam = this_player()->query("family")) || fam["family_name"] != "少林派")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";
 if ((int)this_player()->query_temp("marks/罗汉")) {
       if (query("luohan_count") < 1)   
           return "你师兄拿去研习了，我竟忘却了！";
       say("这对铁罗汉集成了少林武技攻防要诀，当年无色禅师巧手制成此宝\n"
           "曾赠给郭女侠，后来又经武当张真人归还本派。是我们罗汉堂镇堂\n"
           "之宝。\n");
       ob=new("/d/shaolin/npc/obj/book-iron");
       ob->move(this_player());
       add("luohan_count", -1);
       message_vision("澄寂从怀中掏出一对铁罗汉递给$N。\n",this_player());
       this_player()->delete_temp("marks/罗汉");
       return "你要认真研习，不可错失了这学习至宝的机缘！";
      }
     else
        return "铁罗汉在明教呀，我少林只有金，铜，木三种假人做练功器物。";
    }
