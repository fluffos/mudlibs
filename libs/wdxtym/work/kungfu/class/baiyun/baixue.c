#include <ansi.h>
#include "baiyun.h"

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;

mixed ask_skill1();

void create()
{
        set_name("白血", ({"bai xue","bai",}));
        set("long",
                "奇才。他是唯一一个能让西门吹雪和叶孤城强破头的人。\n"
        );
        set("gender", "男性");
        set("nickname", HIR "天才" NOR);
        set("title", "青衣小生");
        set("attitude", "friendly");

        set("age", 30);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        set("max_qi", 30000);
        set("max_jing", 27000);
        set("neili", 30500);
        set("max_neili", 30500);
        set("jiali", 50);
        set("combat_exp", 5000000);

         set_skill("parry", 1200);
        set_skill("dodge", 1800);
        set_skill("force", 1020);
        set_skill("literate", 1200);
	set_skill("sword", 1200);
	set_skill("unarmed",1200);
	set_skill("changquan",1200);
	set_skill("feixian-steps",1200);
	set_skill("feixian-sword",1200);
	set_skill("jingyiforce",1020);

        map_skill("dodge", "feixian-steps");
	map_skill("sword", "feixian-sword");
	map_skill("force", "jingyiforce");
	map_skill("parry", "feixian-sword");
	map_skill("unarmed", "changquan");

        create_family("白云城", 2, "弟子");

        set("inquiry", ([
                "拜师"        : "嘿嘿？",
                "电光四射"    : (: ask_skill1 :),
        ]));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.dian" :),
                (: exert_function, "recover" :),
        }) );

        set("master_ob",3);
	setup();
        carry_object("/d/city/npc/obj/cloth")->wear();
        carry_object("/d/city/npc/obj/changjian")->wield();
}

void attempt_apprentice(object me)
{
        string purename, name, new_name;

        if (! permit_recruit(me))
                return;


       

        if ((int)me->query("shen") > 1000)
        {
                command("heng");
                command("say 我们孤山白云城向来不问江湖事，也不结交你这样的侠义之士。");
                return;
        }

        if ((int)me->query("shen") < -1000)
        {
                command("heng");
                command("say 我白云城向来不问江湖事，更不会结交名声不好之人。");
                return;
        }

        command("say 好吧，既然你有心练武，我就收下你。");
        command("recruit " + me->query("id"));
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/jidian-jian/dian"))
                return "能教的我已经都教完了。";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "和本教素无瓜葛，何出此言？";

        if (me->query_skill("jidian-jian", 1) < 1)
                return "你连疾电剑法都没学，何谈此言？";


        if (me->query_skill("jidian-jian", 1) < 100)
                return "你的疾电剑法还练得不到家，自己下去练练再来吧！";

        if (me->query_skill("force") < 100)
                return "你的内功火候尚不精纯，是学不会这招的。";

        message_vision(HIY "$n" HIY "点了点头，说道：这疾电剑法的电光"
                       "四射其实是慑人声势使其无所施其\n技，我这里给你"
                       "演示一遍，你可看好了。$n" HIY "说完手中长剑一"
                       "抖，将这套剑\n法施展出来，霎时之间，满室都是电"
                       "光，耀人眼目。$N" HIY "看后双目一亮，顿时\n大"
                       "有所悟。\n" NOR, me, this_object());
        command("nod");
        command("say 这招其实很简单，稍微练练便可以施展了。");
        tell_object(me, HIC "你学会了「电光四射」。\n" NOR);

        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500);
        if (me->can_improve_skill("jidian-jian"))
                me->improve_skill("jidian-jian", 1500);
        me->improve_skill("martial-cognize", 1500);
        me->set("can_perform/jidian-jian/dian", 1);


        return 1;
}
