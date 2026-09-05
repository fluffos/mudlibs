// jiumozhi.c 鸠摩智
// by iceland

#include <ansi.h>
#include <title.h>
inherit NPC;
inherit F_MASTER;

#include <no1master.h>
string ask_for_leave();

void create()
{
        set_name("鸠摩智", ({ "jiumo zhi", "jiumozhi","zhi" }));
        set("long",@LONG
他身材匀称，脸上神采飞扬，隐隐似有宝光流动，便如是明珠宝玉，自然生辉，
只消向他看得几眼，便生钦仰亲近之意。
LONG
        );
        set("title", HIY "大轮寺掌门" NOR);

        set("job_title", HIW "大轮明王" NOR);
        set("gender", "男性");
        set("class", "huanxi");
        set("age", 55);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 45);
        set("int", 40);
        set("con", 40);
        set("dex", 40);
        set("per", 45);
        set("max_qi", 16500);
        set("eff_jingli", 13500);
        set("max_jing", 16000);
        set("neili", 24000);
        set("max_neili", 24000);
        set("jiali", 380);
        set("combat_exp", 14000000);
        set("score", 290000);
        set("unique", 1);

        set_skill("huanxi-chan", 200);
        set_skill("literate", 160);
        set_skill("force", 380);
        set_skill("longxiang-boruo", 380);
        set_skill("dodge", 390);
        set_skill("yuxue-dunxing", 390);
        set_skill("strike", 390);
        set_skill("huoyan-dao", 390);
        set_skill("parry", 390 );
        set_skill("staff",390);
        set_skill("wushang-dali",390);

        map_skill("force", "longxiang-boruo");
        map_skill("dodge", "yuxue-dunxing");
        map_skill("strike", "huoyan-dao");
        map_skill("staff","wushang-dali");
        map_skill("parry", "huoyan-dao");

        prepare_skill("strike","huoyan-dao");
		set_temp("apply/armor", 500);
		set_temp("apply/damage", 380);
        create_family("大轮寺", 10, "弟子");
        set("class", "huanxi");
        set("chat_chance", 2);     
        set("chat_msg", ({
"鸠摩智低头沉思，说到：嵩山少林寺，大理天龙寺，哼！我大轮寺那点比不上？！\n",
"鸠摩智将双掌举到眼前瞧了瞧，冷笑了一声：天下能有几人是我的敌手？！\n",
}) );

        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: exert_function, "shield jiumo zhi" :),
                (: perform_action, "strike.fen" :), }));

        set("inquiry", ([
                "还俗" : (: ask_for_leave :),
       ]) );

        set_temp("apply/armor", 60);
        set_temp("apply/damage", 50);
        set_temp("apply/attack", 60);
        set_temp("apply/dodge", 50);
        setup();
		setup_no1master();
        carry_object("/d/dalunsi/npc/obj/longxiang-jiasha")->wear();

}

void init()
{
	      add_action("do_decide",  "decide");	
        ::init();
}

string ask_for_leave()
{
	object me;

	me = this_player();

	if( (string)me->query("class")!="huanxi" )
		return "阿弥陀佛！施主并未出家，何故跟贫僧开这等玩笑？";

	if( (string)me->query("family/family_name") != "大轮寺")
		return "阿弥陀佛！施主非我大轮寺弟子，还俗的事情贫僧作不得主。";

	me->set_temp("pending/leave_huanxi", 1);
		return "阿弥陀佛！如果" + RANK_D->query_respect(me) + "真想离我佛门而去，就请下决心(decide)吧！";
}

int do_decide()
{
	object me = this_player();
	
	if (me->query_temp("pending/leave_huanxi") != 1)
		return 0;
	message_vision("鸠摩智对$N说道：「阿弥陀佛！从此施主就不再是我大轮寺门下了，请好自为之！」\n",me);
	tell_object(me,HIR "你决定叛出大轮寺门下！\n" NOR);
	me->delete_temp("pending/leave_huanxi");
  me->expell_family("大轮寺");
	if (me->query("combat_exp") >= 1000)
		me->add("betrayer",1);
	return 1;
}

void attempt_apprentice(object ob)
{
        if( (string)ob->query("gender") == "无性" ) {
                command("say 施主身体残缺，虽说佛祖普渡众生，可是...\n");
                return;
        }
        if ((string)ob->query("family/family_name") != "大轮寺") {
                command("say"+ RANK_D->query_respect(ob) +
                        "不是本寺弟子，在这里捣什么乱？！");
                return;
        }
        if( (int)ob->query("score") < 1500 ){
                command ("say 施主似乎对大轮寺没什么贡献，让我如何能够相信你呢？");
                return;
        }
        if ((int)ob->query_skill("longxiang-boruo", 1) < 160) {
                command("say 我大轮寺各种武功均和内功相辅相成。");
                command("say"+ RANK_D->query_respect(ob) +
                        "再熬几个通宵，多多钻研钻研本门的内功吧。");
                return;
        }
        if (((int)ob->query_con() < 32) || ((int)ob->query_str() < 32))
{
                command("hmm");
                command(
                "say 这位" + RANK_D->query_respect(ob) +"体质似乎不适合学习我火焰刀神功，\n
                  还是尽早想想别的出路吧。");
                return;
        }
       command("say 看你根骨精奇，确实是练武的好材料，好吧，就让我来好好调教调教你吧。");
       command("recruit " + ob->query("id"));
       ob->set("title", HIY "大轮寺掌门座下弟子" NOR);
//title系统记录玩家title by seagate@pkuxkx
	     ob->set_title(TITLE_RANK, ob->query("title"));
}

#include "/kungfu/class/masterdie.h"
