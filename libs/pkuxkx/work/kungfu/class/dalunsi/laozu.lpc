// laozu.c 血刀老祖
// by iceland

#include <ansi.h>
#include <title.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        object weapon;
        set_name("血刀老祖", ({ "xuedao laozu", "laozu","xuedaolaozu" }));
        set("long",@LONG
他身材高瘦，眼窝深陷，一双眼睛射出凶狠的光芒，令人不敢直视。他在江湖
中以残忍好色而著称，曾凭一手血刀经的功夫斗败无数中原的武林豪杰。
LONG
        );
        set("title", HIR "大轮寺血刀门掌门" NOR);
        set("gender", "男性");
        set("class", "huanxi");
        set("age", 65);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 35);
        set("int", 30);
        set("con", 35);
        set("dex", 35);
        set("max_qi", 2100);
        set("eff_jing", 600);
        set("max_jing",600);
        set("neili", 2500);
        set("max_neili", 2500);
        set("jiali", 30);
        set("combat_exp", 1000000);
        set("score", 500000);
        set("unique", 1);

        set_skill("huanxi-chan", 180);
        set_skill("literate", 150);
        set_skill("force", 180);
        set_skill("longxiang-boruo", 180);
        set_skill("dodge", 180);
        set_skill("yuxue-dunxing", 180);
        set_skill("claw", 180);
        set_skill("tianwang-zhua", 180);
        set_skill("hand", 180);
        set_skill("dashou-yin", 180);
        set_skill("blade",200);
        set_skill("xuedao-jing",200);
        set_skill("parry", 180 );

        map_skill("force", "longxiang-boruo");
        map_skill("dodge", "yuxue-dunxing");
        map_skill("hand", "dashou-yin");
        map_skill("parry", "xuedao-jing");
        map_skill("claw", "tianwang-zhua");
        map_skill("blade", "xuedao-jing");

        prepare_skill("hand","dashou-yin");
        prepare_skill("claw","tianwang-zhua");

        create_family("大轮寺", 10, "弟子");
        set("class", "huanxi");

        set("chat_chance", 2);
        set("chat_msg", ({
"血刀老祖抬起头，若有所思的自言自语：“月亮快圆了，得下山杀个人祭祭刀了。”\n",
"血刀老祖恨恨的说：“什么时候再入中原，再闹个天翻地覆！”\n",
"血刀老祖咬牙切齿，眼露凶光的说：“下次来个斩草除根，一个活口也不留！”\n",
"血刀老祖自言自语道：“年纪大了，体力可一点也不含糊。”言下甚为得意。\n",
}) );
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: exert_function, "shield xuedao laozu" :),
                (: perform_action, "blade.shendao" :), }));

        setup();
        carry_object("/d/dalunsi/npc/obj/longxiang-jiasha")->wear();
        carry_object("/d/dalunsi/npc/obj/xingyuedao")->wield();


}
void attempt_apprentice(object ob)
{
        if ((string)ob->query("family/family_name") != "大轮寺") {
                command("say"+ RANK_D->query_respect(ob) +
                        "不是本寺弟子，在这里捣什么乱？！");
                return;
        }

        if ((int)ob->query_skill("longxiang-boruo", 1) < 150) {
                command("say 我大轮寺各种武功均和内功相辅相成。");
                command("say"+ RANK_D->query_respect(ob) +
                        "再熬几个通宵，多多钻研钻研本门的心法吧。");
                return;
        }

        if( (string)ob->query("gender") == "无性" ) {
                command("say"+ RANK_D->query_respect(ob)+
                 "身体残缺，如何随我修炼？\n");
                return;
        }
        if ((int)ob->query("shen") > -100000) {
                command("hmm");
                command("say 我血刀老祖声名远扬，那些所谓的江湖大侠哪个不是望风而逃？");
                command("say 以你现在的资历，如果收你为徒，恐怕会被人耻笑。");
                return;
        }
        command("say 老祖我就喜欢你这样的年轻人。好，就收你为我弟子吧。");
        command("recruit " + ob->query("id"));

        ob->set("title", HIR "大轮寺血刀老祖亲传弟子" NOR);
//title系统记录玩家title by seagate@pkuxkx
	      ob->set_title(TITLE_RANK, ob->query("title"));
}

#include "/kungfu/class/masterdie.h"