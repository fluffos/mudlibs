// /kungfu/class/xueshan/jiumozhi.c 鸠摩智
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        object ob;
        set_name("鸠摩智", ({ "jiumo zhi", "zhi" ,"ming wang"}));
        set("nickname", HIG "大轮明王" NOR);
        set("long",@LONG
他就是雪山寺的掌门，人称大轮明王的鸠摩智。他对佛法有精深的研究。
身穿一件大红袈裟，头带僧帽。
LONG
        );
        set("title","雪山寺掌门");
        set("gender", "男性");
        set("age", 60);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 60);
        set("int", 60);
        set("con", 60);
        set("dex", 60);
        set("max_qi",  18000);
        set("max_jing", 18000);
        set("neili", 35000);
        set("max_neili", 35000);
        set("jiali", 100);
        set("combat_exp", 8500000);
        set("score", 500000);

        set_skill("necromancy", 380);
        set_skill("force", 200);
        set_skill("xiaowuxiang", 380);
        set_skill("dodge", 200);
        set_skill("shenkong-xing", 380);
        set_skill("unarmed", 200);
        set_skill("yujiamu-quan", 380);
        set_skill("strike", 320);
        set_skill("parry", 200);
        set_skill("cuff", 200);
        set_skill("sword", 200);
        set_skill("mingwang-jian", 380);
        set_skill("lamaism", 380);
        set_skill("literate", 100);
        set_skill("staff", 100);
        set_skill("xiangmo-chu", 380 );
        set_skill("strike", 300 );
        set_skill("huoyan-dao", 380);
	set_skill("dashou-yin", 320);
	        set_skill("xiangmo-chu", 380);
        set_skill("magic", 380);
        set_skill("kwan-yin-spells", 380);
map_skill("magic", "kwan-yin-spells");
map_skill("cuff", "yujiamu-quan");
map_skill("hand", "dashou-yin");
	set("inquiry", ([
		"十三龙象袈裟" : "这是本门佛宝，不能轻易给你，这样吧帮我找一朵藏红花吧！\n",
	]));


        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("unarmed", "yujiamu-quan");
        map_skill("parry", "huoyan-dao");
        map_skill("sword", "mingwang-jian");
        map_skill("staff", "xiangmo-chu");
        map_skill("strike","huoyan-dao");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 250);

if (random(3)==0)
{
map_skill("unarmed", "longxiang");
map_skill("parry", "longxiang");
	set("chat_chance_combat", 99);  
	set("chat_msg_combat", ({
                (: perform_action, "strike.fen" :),
                (: perform_action, "strike.honglian" :),
                (: perform_action, "strike.xiuluo" :),
                (: perform_action, "strike.yan" :),
                (: perform_action, "unarmed.die" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.tun" :),
                (: perform_action, "unarmed.zhen" :),
                (: perform_action, "magic.ni" :),
                (: perform_action, "magic.hong" :),
                (: perform_action, "magic.ba" :),
                (: perform_action, "magic.an" :), 
                (: perform_action, "dodge.tianmaxingkong" :),
	}) );

}	
else
{

	set("chat_chance_combat", 99);  
	set("chat_msg_combat", ({
                (: perform_action, "strike.fen" :),
                (: perform_action, "strike.honglian" :),
                (: perform_action, "strike.xiuluo" :),
                (: perform_action, "strike.yan" :),
                (: perform_action, "cuff.chen" :),
                (: perform_action, "cuff.jiang" :),
                (: perform_action, "hand.dashouyin" :),
                (: perform_action, "hand.jingang" :),
                (: perform_action, "hand.yin" :),
                (: perform_action, "magic.ni" :),
                (: perform_action, "magic.hong" :),
                (: perform_action, "magic.ba" :),
                (: perform_action, "magic.an" :), 
                (: perform_action, "dodge.tianmaxingkong" :),
	}) );
}

        create_family("雪山寺", 2, "掌门");
        set("class", "bonze");

        setup();

//        carry_object("/clone/weapon/changjian")->wield();
        if (clonep()) {
                if (random(4)==0)
{
                ob = new(__DIR__"13jiasha");
                ob->set("jiasha/neili",13);
                ob->move(this_object());
                ob->wear();
}
}
        carry_object("/d/xueshan/obj/r-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();

        add_money("silver",50);
}

void attempt_apprentice(object ob)
{

 		  if ((string)ob->query("gender") != "男性") {
        			 command("say 修习密宗内功需要纯阳之体。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "还是请回吧！");
                return;
		  }

		  if ((string)ob->query("class") != "bonze") {
        			 command("say 我佛门的清规戒律甚多。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "还是请回吧！");
                return;
		  }

        if ((string)ob->query("family/family_name") != "雪山寺")        {
                command("say 这位" + RANK_D->query_respect(ob) +
                        "既非本寺弟子，还是请回吧！");
                return;
		  }

        if ((int)ob->query_skill("lamaism", 1) < 100) {
                command("say 入我雪山寺，修习密宗心法是首要的。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "是否还应该多多钻研本门的心法？");
                return;
        }

//        command("chat 哈哈哈哈！！！！！");
//        command("chat 我雪山寺真是后继有人，真是可喜可贺。");
//        command("chat 哈哈哈哈！！！！！");
        command("recruit " + ob->query("id"));

	ob->set("title",HIY"法王"NOR);
}

int accept_object(object ob, object obj)
{
       if(!ob||environment(ob)!=environment() ) return 0;
       
       if(!objectp(ob) ) return 0;
 
       if( !present(obj,ob) )
        { 
         say("你有吗？？\n");
         return 1;
        }  

        if(obj->query("id")=="zang honghua")
{
        if( present("shisan longxiang",this_object()) )
{
obj->set("no_get",1);
command("say 太好了，藏红花可是雪山一宝啊!");
command("remove shisan longxiang");
command("say 这件十三龙象袈裟就送给你护法之用吧。");
command("give shisan longxiang to "+ob->query("id"));
}
else command("say 老僧，身无长物，真不知道怎么谢谢你!");
        return 1;
}
}
