#include <ansi.h>;


inherit NPC;
inherit F_MASTER;


mixed ask_me();
mixed ask_skill();

void create()
{
        set_name("桑土公", ({ "sang tugong", "sang", "tugong"}));
        set("gender", "男性");
        set("title", "川西碧磷洞洞主");
        set("age", 58);
        set("long", @LONG
这便是川西碧磷洞洞主端桑土公，只见他身材
矮小，须发皆白。手持一个大铜鼎，鼎足上铸
着一个“桑”字，乃是几条小蛇、蜈蚣之形盘
成，铜绿斑斓，宛是一件古物。
LONG );
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
    set("pubmaster",1);
        set("qi", 8200);
        set("max_qi", 8200);
        set("jing", 8000);
        set("max_jing", 8000);
        set("neili", 8800);
        set("max_neili", 8800);
        set("jiali", 100);
        set("combat_exp", 2000000);

        set_skill("force", 180);
       // set_skill("shennong-xinjing", 180);
        set_skill("dodge", 200);
        set_skill("feiyan-zoubi", 200);
        set_skill("strike", 180);
        //set_skill("dusha-zhang", 180);
        set_skill("hand", 180);
        //set_skill("lansha-shou", 180);
        set_skill("parry", 180);
        set_skill("staff", 180);
        //set_skill("shennong-zhang", 180);
        set_skill("throwing", 220);
        set_skill("pidi-shenzhen", 220);
        set_skill("literate", 160);
        set_skill("poison", 200);
        set_skill("martial-cognize", 180);
set_skill("xiaowuxiang", 180);
set_skill("martial-cognize", 180);

        map_skill("dodge", "feiyan-zoubi");
        map_skill("force", "xiaowuxiang");
        map_skill("throwing", "pidi-shenzhen");
        map_skill("parry", "pidi-shenzhen");
        //map_skill("staff", "shennong-zhang");

        //prepare_skill("hand", "lansha-shou");
        //prepare_skill("strike", "dusha-zhang");

        set("inquiry", ([
                "斓蜈金针"   : (: ask_me :),
                "虚竹"       : "他是我们灵鹫宫新的主公，我们全部听他号令。",
                "虚竹子"     : "他是我们灵鹫宫新的主公，我们全部听他号令。",
        ]));

        create_family("碧磷洞", 8, "洞主");

        set("zhen_count", 3);

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({

                (: perform_action, "throwing.huan" :),
                (: exert_function, "powerup" :),
                (: exert_function, "shield" :),
        }) );

        set("master_ob",3);
	setup();
        carry_object("/clone/weapon/gangzhang");
        carry_object("/clone/cloth/cloth")->wear();
        carry_object(__DIR__"jinzhen")->wield();
}

int recognize_apprentice(object ob, string skill)
{
        if (ob->query("family/family_name") != "灵鹫宫"  && ob->query("family/family_name") != "逍遥派")
        {
                command("bite");
                command("say 快滚，快滚！我可没时间和你耗。");
                return 0;
        }

  
        if (skill == "throwing" && ob->query_skill("throwing", 1) > 179)
        {
                command("say 你暗器的造诣已经很高了，剩下的就自己去研究吧。");
                return 0;
        }

        if (! ob->query_temp("can_learn/sangtugong"))
        {
                command("bored");
                command("say 唉……看在主公的份上，我教你好了。");
                ob->set_temp("can_learn/sangtugong", 1);
        }
        return 1;
}


mixed ask_me()
{
        object me;
        object ob;

        me = this_player();

        if (me->query("family/family_name") != "灵鹫宫" &&
           me->query("family/family_name") != "碧磷洞")
                return "滚开！我可没时间和你耗。";


        if (me->query_skill("pidi-shenzhen", 1) < 100)
                return "你辟地神针的手法还不到家，拿了这针也没什么用。";

        if (query("zhen_count") < 1)
                return "没了，没了！我老底都被你掀干净了。";

        add("zhen_count", -1);
        ob = new(__DIR__"jinzhen");
        message_vision("$N拿出五十根" HIR "斓蜈金针" NOR "(Lanwu jinzhen)给$n。\n",
                       this_object(), me);
        ob->move(me, 1);
        return "我这儿的斓蜈金针你先拿去用吧。";
}


void attempt_apprentice(object ob)
{
if (ob->query("family/family_name") == "灵鹫宫")
{

        command("sigh2");
        command("say 这个世道真是什么人都有，摆着那么多门派不拜，却跑来拜我。");
        command("say 亏你也想得出来，既然来了，我就收下你吧。");
        command("recruit " + ob->query("id"));
}
} 

