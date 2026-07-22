// zheluoxing.c 哲罗星
// by iceland

#include <ansi.h>
inherit NPC;

string ask_xueliandan();

void create()
{
        set_name("哲罗星", ({ "zheluo xing", "zheluoxing","zheluo","xing" }));
        set("long",@LONG
他身材中等，头发和胡子稀稀拉拉的成枯黄色，一双眉毛下垂，显得愁眉苦脸。
他是个西域胡人，因为仰慕大轮寺的佛法和武功，所以和师弟来此修行。
LONG
        );
        set("title", HIY "大轮寺第十二代弟子" NOR);
        set("gender", "男性");
	set("class", "huanxi");
        set("age", 34);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 28);
        set("int", 15);
        set("con", 28);
        set("dex", 30);
        set("max_qi", 1000);
        set("eff_jing", 400);
	set("max_jing",400);
        set("neili", 1200);
        set("max_neili", 1200);
        set("jiali", 40);
        set("combat_exp", 350000);
        set("score", 140000);
	set("unique", 1);

        set_skill("huanxi-chan", 100);
        set_skill("literate", 80);
        set_skill("force", 100);
        set_skill("longxiang-boruo", 100);
        set_skill("dodge", 100);
        set_skill("yuxue-dunxing", 100);
        set_skill("hand", 100);
        set_skill("dashou-yin", 100);
        set_skill("staff", 100);
        set_skill("wushang-dali", 100);
        set_skill("parry", 100 );

        map_skill("force", "longxiang-boruo");
        map_skill("dodge", "yuxue-dunxing");
        map_skill("hand", "dashou-yin");
        map_skill("parry", "wushang-dali");
        map_skill("staff", "wushang-dali");

        prepare_skill("hand","dashou-yin");

        create_family("大轮寺", 12, "弟子");
        set("class", "huanxi");

        set("inquiry", ([
                "雪莲丹" : (: ask_xueliandan :),
        ]));
        set("xuelian_count", 1 + random(4));
        set("chat_chance", 1);
        set("chat_msg", ({
		"哲罗星怪腔怪调的抱怨：“来到这里老要干活，学不到武功，还不如去少林寺看看。”\n",
        }) );
        setup();
        carry_object(__DIR__"obj/gongde-jiasha")->wear();
        carry_object(BINGQI_D("jingangzuan"))->wield();      

        add_money("gold",1);
}
string ask_xueliandan()
{
	mapping fam; 
        object ob;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] !="大轮寺")
                return RANK_D->query_respect(this_player()) + 
                "不是本派弟子，怎么对本派灵药也垂涎三尺呀？";

        if ( (int)this_player()->query_condition("neili_drug" ) > 0 )
                return RANK_D->query_respect(this_player()) + 
                "体带香气，是不是刚刚吃过？灵药炼制不易，多吃也是浪费，一会再来吧。";

        if (  present("xuelian dan", this_player()) )
                return RANK_D->query_respect(this_player()) + 
                "现在身上不是有颗药丸吗，怎麽又来要了？真是贪得无厌！";

        if ( (int)this_player()->query("max_jingli") < 200 )
                return RANK_D->query_respect(this_player()) +"功力不够，雪莲丹对你有害无益。";

        if (query("xuelian_count") < 1)
                return RANK_D->query_respect(this_player()) +"来的不巧，我这里也没有了。";

        ob = new(MEDICINE_D("xueliandan"));
        ob->move(this_player());
        add("xuelian_count", -1);

        message_vision("$N获得一颗雪莲丹。\n",this_player());
        return "好吧，记住，此药炼制实在不易，万万不要浪费了。";
}
