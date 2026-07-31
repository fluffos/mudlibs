// /u/dubei/gumu/npc/yangguo
// by dubei
inherit NPC;
inherit F_MASTER;
#include <ansi.h> 
string ask_me();
void create()
{
        set_name("杨过", ({ "yang guo", "yang" }));
        set("nickname", "神雕侠");
        set("long", 
                "他就是神雕大侠杨过，一张清癯俊秀的脸孔，剑眉入鬓，凤眼生威。\n"
                "虽然他只有一只胳膊，但是魁伟的身材仍让人感觉英气逼人。\n");
        set("gender", "男性");
        set("age", 32);
        set("attitude", "friendly");
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        
        set("max_qi", 5000);
        set("max_jing", 3000);
        set("neili", 5000);
        set("max_neili", 5000);
        set("eff_jing", 3000);
        set("jiali", 100);
        set("combat_exp", 2500000);
        set("shen", 25000);
          set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
          (: perform_action, "strike.xiaohun" :),
          (: perform_action, "sword.xunlei" :), }));
        set_skill("force", 300);
        set_skill("yunv-shenfa", 300);
        set_skill("dodge", 300);
        set_skill("yunv-xinfa", 300);
        set_skill("cuff", 300);
        set_skill("meinv-quan", 300);
        set_skill("parry", 300);
        set_skill("sword", 300);
        set_skill("xuantie-jianfa", 300);
        set_skill("taoism", 300);
        set_skill("strike", 300);
        set_skill("literate", 300);
        set_skill("anranxiaohun-zhang", 300);
        set_skill("yunv-jian", 300);
        map_skill("force", "yunv-xinfa");
        map_skill("dodge", "yunv-shenfa");
        map_skill("cuff", "meimv-quan");
        map_skill("parry", "anranxiaohun-zhang");
        map_skill("sword", "xuantie-jianfa");
        map_skill("strike", "anranxiaohun-zhang");
        prepare_skill("strike", "anranxiaohun-zhang");
             set("inquiry", 
                ([
                           "运气之道" : (: ask_me :),
              ]));
        create_family("古墓派", 2, "神雕侠侣");
        setup();
	carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"jzj")->wield();
}

string ask_me()
{ 
       mapping fam; 
       object ob;
       ob = this_player();
//       if (!(fam = this_player()->query("family")) || fam["family_name"] != "古墓派")
//               return RANK_D->query_respect(this_player()) + 
//               "非我古墓传人,不知道此话怎讲?";
            if (!ob->query_temp("xth_hm"))
            return RANK_D->query_respect(this_player()) + 
               "想知道什麽运气之道呢?";
                      ob->delete_temp("xth_hm");
               ob->set_temp("make/xtj_look1",1);
            ob->set_temp("yg_pbask",1);
       return "屏气具息,凝气守中,双肩放松,意守丹田,这是在洪水中运气的诀窍,你好好去领悟一下.";
}

void kill_ob(object me)
{
        command("chat* nomatch " + me->query("id"));
        
        ::kill_ob(me);
}
      
