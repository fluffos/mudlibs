#include <ansi.h>

inherit NPC;

void create()
{
        set_name("时万年",({"shi wannian","shi",}));
        set("gender", "男性");
        set("age", 20);
        set("long", 
               "他是凌霄城第六代弟子时万年，在此守卫监狱。\n");
        set("attitude", "peaceful");

        set("str", 30);
        set("con", 30);
        set("int", 24);
        set("dex", 30);
         set("neili", 33000);
        set("max_neili", 33000);
        set("jing", 18000);
        set("max_jing", 18000);
        set("qi", 18000);
        set("max_qi", 18000);
        set("jiali", 100);


        set("combat_exp", 250000); 
        set("shen_type", 0);
        set("score", 20000);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :)
        }) );
        set("chat_chance", 5);
        set("chat_msg", ({
       "时万年恨恨说道：老疯子不知道又怎么了，把自己关在里面弄死不肯出来。\n", 
       "时万年把剑一弹，傲然道：有我守在这，谁都别想把老疯子放出来。\n", 
        }) );
          set_skill("sword", 280);
        set_skill("force", 230);
        set_skill("parry", 230);
        set_skill("dodge", 230);
        set_skill("literate", 180);

        set_skill("xueshan-sword", 320);
        set_skill("bingxue-xinfa", 320);
        set_skill("snow-zhang", 300);
        set_skill("snowstep", 300);
        set_skill("doom-hand", 300);
        set_skill("hanshan-strike", 300);
        set_skill("snowwhip", 300);
        set_skill("hand", 250);
        set_skill("whip", 250);
         set_skill("strike", 280);
        map_skill("sword", "xueshan-sword");
        map_skill("parry", "xueshan-sword");
        map_skill("force", "bingxue-xinfa");
        map_skill("unarmed", "snow-zhang");
        map_skill("dodge", "snowstep");

        map_skill("strike", "hanshan-strike");
        map_skill("hand", "doom-hand");
	prepare_skill("strike", "hanshan-strike");
	prepare_skill("hand", "doom-hand");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "sword.fengxue" :),
                (: perform_action, "sword.wanmei" :),
                (: perform_action, "sword.xuehua" :),
                (: perform_action, "dodge.snowfly" :),
                (: perform_action, "sword.xuehua" :),
                (: perform_action, "unarmed.yanxue" :),
                (: perform_action, "unarmed.ying" :),
                (: perform_action, "unarmed.zhe" :),
                (: perform_action, "unarmed.lang" :),
                (: perform_action, "strike.zhangjian" :),
                (: perform_action, "strike.siji" :),
	               (: perform_action, "hand.hantian" :),                		
                (: exert_function, "powerup" :),
        }) );
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
        create_family("凌霄城", 6, "弟子");
        setup();

        
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
} 
void init()
{ 
        object ob;
        ::init();

        ob = this_player();  
      if(ob->query("family/family_name") !="凌霄城")
        {
                command("heng");
                command("say 你居然敢闯入本派禁地，受死吧！\n");
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob); 
        }
        else if(ob->query("family")["master_name"]=="白自在")
        {
                command("say 师叔回来了，快去见师祖吧，不过小心点……没准他又犯病了。");
        } 
        else if(ob->query("family")["master_name"]=="白万剑")
        {
                command("say 你是白师哥的弟子吧，快进去见见老爷子吧，他的病越来越不得了啦。");
        }
}

