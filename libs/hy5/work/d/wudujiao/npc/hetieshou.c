// hetieshou.c
// 何铁手
// by victori
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_me();
int ask_box();

void create()
{
        set_name("何铁手", ({ "he tieshou", "he" }));
        set("nickname", HIG "五毒仙子" NOR);
        set("long",@LONG
你对面的是一个一身粉红纱裙，笑靥如花的少女。她长得肌肤雪白，眉目如画，
赤着一双白嫩的秀足，手脚上都戴着闪闪的金镯。谁能想到她就是五毒教的教
主何铁手，武林人士提起她无不胆颤心惊。
LONG
        );
        set("title","五毒教教主");
        set("gender", "女性");
        set("age", 25);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 50);
        set("int", 50);
        set("con", 50);
        set("dex", 50);
         set("per", 36);
        set("max_qi", 29000);
        set("max_jing", 29000);
        set("neili", 36000);
        set("max_neili", 36000);
        set("jiali", 100);
        set("combat_exp", 5500000);
        set("score", 500000);
        set("box_count",1);
        set("tieshao_count",1);

        set_skill("force", 300);
        set_skill("wudu-shengong", 380);
          set_skill("dodge",300);
          set_skill("wudu-yanluobu",380);
          set_skill("unarmed",300);
          set_skill("qianzhu-wandushou",380);
          set_skill("parry",300);
          set_skill("sword",300);
          set_skill("wudu-goufa",380);
          set_skill("poison",300);
          set_skill("literate",200);
          set_skill("finger",290);
          set_skill("shedu-qiqiao",380);
        set_skill("wudu-yanluobu", 380);
        set_skill("unarmed", 260);
        set_skill("qianzhu-wandushou", 380);
        set_skill("parry", 250);
        set_skill("duji", 600);
        set_skill("sword", 280);
        set_skill("wudu-goufa", 380);
        set_skill("poison", 380);
        set_skill("literate", 200);
        set_skill("finger",230);
        set_skill("shedu-qiqiao",380);
	set_skill("whip",500);
	set_skill("chilian-shenzhang",380);
	set_skill("jueqing-bian",380);
 	set_skill("ruanhong-zhusuo",380);
	set_skill("dusha-zhang", 380);
	set_skill("lansha-shou", 380);
	set_skill("hand", 380);
	set_skill("strike", 380);
	map_skill("strike", "dusha-zhang");
	map_skill("hand", "lansha-shou");
	prepare_skill("strike", "dusha-zhang");
	prepare_skill("hand", "lansha-shou");
        map_skill("poison","shedu-qiqiao");
        map_skill("finger","shedu-qiqiao");
        map_skill("force", "wudu-shengong");
        map_skill("dodge", "wudu-yanluobu");
        map_skill("unarmed", "qianzhu-wandushou");
        map_skill("parry", "wudu-goufa");
        map_skill("sword", "wudu-goufa");
map_skill("whip", "ruanhong-zhusuo");
//      map_skill("hammer", "jinshe-chui");
	prepare_skill("strike", "dusha-zhang");
	prepare_skill("hand", "lansha-shou");
         set("chat_chance_combat", 99);
         set("chat_msg_combat", ({
                (: perform_action, "whip.bohu" :),
                (: perform_action, "whip.pan" :),
                (: perform_action, "whip.teng" :),
                (: perform_action, "whip.suo" :),
                (: perform_action, "unarmed.qzwd" :),
                (: perform_action, "dodge.snake" :),
                (: exert_function, "recover" :),
		(: perform_action, "strike.tianxie" :),
		(: perform_action, "strike.hantian" :),
		(: perform_action, "hand.canglong" :),
		(: perform_action, "hand.xiangyi" :),
		(: perform_action, "hand.luanpo" :),		
        }) );
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
        create_family("五毒教", 11, "教主");

        setup();
        set("inquiry", ([
//              "name": "在下乃诸葛武候之第二十三代孙诸葛不亮是也．\n",
                "万毒窟": (: ask_me :),
                "信物": (: ask_me :),
                "含沙射影": (: ask_box :),
         ]) );

carry_object("/kungfu/class/xingxiu/chanhunsuo")->wield();
        carry_object(__DIR__"obj/jingou");
        carry_object(__DIR__"obj/skirt")->wear();

        add_money("gold",1);
}
int ask_me()
{
        object ob;
        if ((string)this_player()->query("family/master_id")!="he tieshou"){
               command("say 万毒窟乃本教圣地，除本教长老之外别人不得进入。");
               return 1;
         }
        if(query("tieshao_count")< 1 ){
              command("say 你来晚了，信物我已经给别人了。");
              return 1;
        }
        command("say 万毒窟内凶险异常，千万要小心啊。\n");
        command("say 这只铁哨是我的信物，你可以凭此自由进入洞中！");
        ob = new("d/wudujiao/obj/tieshao");
        ob->move(this_player());
        add("tieshao_count",-1);
         remove_call_out ("give_tieshao");
         call_out ("give_tieshao", 900); // 15 分钟
        return 1;
}
int ask_box()
{
       object ob;
       if ((string)this_player()->query("family/master_id")!="he tieshou"){
               command("say 此乃本教重宝，轻易不会给人的。");
               return 1;
        }
       if(query("box_count")< 1 ){
              command("say 你来晚了，含沙射影我已经送给别人了。");
              return 1;
        }
       command("smile");
       command("say 怎么？是要和人打架吗？可别弱了我五毒教威风啊！");
       command("say 含沙射影你拿去吧，叫他们尝尝我们五毒教的厉害。");
       ob = new(__DIR__"obj/hanshasheying");
       ob->move(this_player());
       add("box_count",-1);
       ob->set("own_name",this_player()->query("id"));
        remove_call_out ("give_hssy");
        call_out ("give_hssy", 900); // 15 分钟
       return 1;
}

void attempt_apprentice(object ob)
{

          if ((string)ob->query("gender") == "无性") {
                                 command("say 这位公公不要开玩笑了。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "还是快去伺候皇上吧！");
                return;
                  }

          if ((int)ob->query("shen") > 1000) {
                                 command("say 做我五毒教弟子必须心狠手辣。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "心慈手软，可惜与我教没有缘分啊！");
                return;
                  }

        if ((string)ob->query("family/family_name") != "五毒教")        {
                command("say 这位" + RANK_D->query_respect(ob) +
                        "不是本教弟子，还是请回吧！");
                return;
                  }

        if ((int)ob->query_skill("poison", 1) < 120) {
                command("say 我五毒教弟子以毒杀人，修习毒技是首要的。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "是否还应该多多钻研本门的绝学？");
                return;
        }
        if ((int)ob->query_skill("wudu-shengong", 1) < 100) {
                command("say 你的五毒神功还学的不够啊。");
                return;
        }

//        command("chat 嘿嘿嘿嘿！！！！！");
          command("chat 好吧，既然如此本姑娘就收下你这个徒弟。");
          command("chat 终有一天，要让天下人都知道我们五毒教的厉害！！！");
        command("recruit " + ob->query("id"));
        ob->set("class", "none");
         ob->set("title","五毒教长老");
        return;
}
void give_hssy()
{
        set("box_count",1);
}
void give_tieshao()
{
        set("tieshao_count",1);
}

