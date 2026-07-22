// butou

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("捕头", ({"bu tou","bu"}));
        set("long",
                "一位威风凛凛的捕头，身材不高，但是两眼有神。\n"
                "据说大理这带的草寇都怕他三分。\n"
        );
        set("nickname", "大理神捕");
        set("gender", "男性");
        set("attitude", "peaceful");
        
        set("age", 35);
        set("shen", 2000);
        set("str", 35);
        set("int", 20);
        set("con", 30);
        set("dex", 35);
        set("max_qi", 1500);
        set("max_jing", 1600);
        set("neili", 2500);
        set("max_neili", 2500);
        set("jiali", 120);
        set("combat_exp", 350000);
 
        set_skill("force", 140);
	set_skill("blade",140);
	set_skill("cuff",140);
	set_skill("taizu-quan",140);
        set_skill("shenghuo-shengong", 140);
        set_skill("dodge", 140);
        set_skill("tiyunzong", 140);
        set_skill("parry", 140);
        
        map_skill("force", "shenghuo-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("parry", "taizu-quan");
        map_skill("cuff", "taizu-quan");
       prepare_skill("cuff", "taizu-quan");

        setup();
        carry_object("/clone/armor/armor")->wear();
}

void init()
{
        object me, ob;
        mapping fam;

        ::init();

        ob = this_player();
        me = this_object();
        
        if (interactive(ob) 
        && !environment(ob)->query("no_fight")
          && (int)ob->query("PKS",1) >40 )
        {
 
         command("say 听说你最近做了不少案子，今天撞见本官，就和我走一趟吧。\n");
         ob->start_busy(2);
         me->set_leader(ob);
         remove_call_out("kill_ob");
         call_out("kill_ob", 1, ob); 

		 
        }       
}
 
int accept_fight(object me)
{
       command("say  本官公务在身，没时间陪你玩。");
       return 0;
}

