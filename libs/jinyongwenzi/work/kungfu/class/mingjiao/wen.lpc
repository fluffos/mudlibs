// wen.c 闻苍松
// Modify By River@sj 99.06
inherit NPC;
string ask_xunluo();
string ask_jihe();
void create()
{
        set_name("闻苍松", ({ "wen cangsong", "wen", "cangsong" }));
        set("gender", "男性");
        create_family("明教",37,"弟子");
        set("age", 46);                
        set("rank_info/respect","旗主");
        set("title","明教巨木旗掌旗使");
        set("str", 27);
        set("int", 20);
        set("con", 26);
        set("dex", 22);
        set("per", 14);
        set("combat_exp", 160000);
        set("unique", 1);
        set("attitude", "peaceful");
        set("max_qi",1000);
        set("max_jing",1000);
        set("neili",1000);
        set("max_neili",1000);
        set("eff_jingli", 1000);
        set("jiali",30);
        set_skill("cuff", 60);
        set_skill("parry",60);
        set_skill("blade",60);
        set_skill("lieyan-dao",60);
        set_skill("piaoyi-shenfa",60);
        set_skill("dodge", 60);
        set_skill("force",60);
        set_skill("shenghuo-shengong",60);        
        map_skill("force","shenghuo-shengong");
        map_skill("dodge","piaoyi-shenfa");
        map_skill("blade","lieyan-dao");
        map_skill("parry","lieyan-dao");
        set_skill("taizu-quan",60);
        map_skill("cuff","taizu-quan");
        prepare_skill("cuff","taizu-quan"); 
        set("inquiry", ([
                "画印"  : (: ask_xunluo :),
                "集合"  : (: ask_jihe :),
        ]));
        set("xl", 7);      
        set("xl2", "wen"); 
        setup();
        carry_object(BINGQI_D("blade"))->wield();
        carry_object("/d/mingjiao/obj/red-cloth")->wear();
}

string ask_jihe()
{
        if (!this_player()->query_temp("mj/ling"))
           return "集合什么呀？吃饭时间到了？";
        command("nod");
        command("say 我立刻到光明顶广场集合。");
        this_object()->move("/d/mingjiao/gmd");
        return "你去请其他的旗使吧";
}

void attempt_apprentice(object ob)
{     
        command("say 由于教事繁忙，我已许久不收弟子了。");
        command("say 这位"+RANK_D->query_respect(ob)+"还是请回吧。");
        return;
}

#include "xunluo.h";

