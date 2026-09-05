//azhu.c
//by hehe
//2003.3.13

#include <ansi.h>

string ask_mg();
string ask_ml();
string ask_hm();
void do_answer(string);
inherit NPC;
inherit F_MASTER;

void create()
{
    set_name("阿朱", ({ "a zhu", "azhu", "zhu" }));
    set("long",
            "她是慕容复的贴身丫鬟\n"
            "她看起来十多岁，容貌秀丽，别有一番可人之处。\n");
    set("gender", "女性");
    set("age", 20);
    set("title",RED"姑苏慕容" + HIB"侍女"NOR);
    set("str", 25);
    set("int", 26);
    set("con", 26);
    set("dex", 26);
    set("combat_exp", 13000);
    set("shen_type", 1);
    set("attitude", "peaceful");
    set("max_qi",1000);
    set("max_jing",1000);
    set("neili",1000);
    set("max_neili",1000);
    set("jiali",30);
    set("score", 8000);

    set_skill("cuff", 70);
    set_skill("finger", 70);
    set_skill("sword", 70);
    set_skill("blade", 70);
    set_skill("parry",70);
    set_skill("dodge", 70);
    set_skill("force",70);
    set_skill("strike",70);
    set_skill("xingyi-zhang",70);
    set_skill("literate",70);
    set_skill("canhe-zhi",70);
    set_skill("murong-daofa",70);
    set_skill("murong-jianfa",70);
    set_skill("yanling-shenfa",70);
    set_skill("ziwei-xinfa",70);

    map_skill("finger","canhe-zhi");
    map_skill("sword","murong-jianfa");
    map_skill("blade","murong-daofa");
    map_skill("force","ziwei-xinfa");
    map_skill("dodge","yanling-shenfa");
    map_skill("strike","xingyi-zhang");

    prepare_skill("finger","canhe-zhi");
    set_temp("apply/attack", 20);
    set_temp("apply/defense", 20);

    setup();

    create_family("姑苏慕容" , 4, "弟子");
    set("mg_count",1);
    set("ml_count",1);
    set("hm_count",1);

    carry_object("/d/murong/npc/obj/shoe")->wear();
    carry_object("/d/murong/npc/obj/cloth1")->wear();
    set("inquiry", ([
                "玫瑰花露" : (:ask_mg:),
                "茉莉花露" : (:ask_ml:),
                "寒梅花露" : (:ask_hm:),
                "name" : "我是慕容公子的贴身丫鬟，叫做阿朱，好久没有见到慕容公子了。\n",
                "here" : "这里是听香水榭，是慕容老爷为了照顾我给我安排的住处。\n",
                "曼佗罗山庄" : "曼佗罗山庄的王姑母这一阵子不让外人去她的山庄，连我们都不敢。\n",
                "慕容复" : "慕容复是我们燕子坞的主人，以以彼之道，还施彼身而天下闻名。\n",
                "花露" : "你想清楚要什么花露，再来找我吧!\n"
                ]));
}

string ask_mg()
{
    mapping fam;
    object ob;
    if (!(fam = this_player()->query("family") ) || (fam["family_name"]!="姑苏慕容"))
        return RANK_D->query_respect(this_player()) +
            "你非本派弟子，也来偷窥我的宝物，简直是笑话！";
    if ( this_player()->query("score") < 400 )
        return "你对本派贡献不够，本派的灵药现在不能给你。";
    if (query("mg_count") < 1)
        return "现在我这没有玫瑰花露。";
    add("mg_count",-1);
    ob = new("/d/murong/npc/obj/meigui");
    ob->move(this_player());
    return "我这滴玫瑰花露你就拿去吧。";
}
string ask_ml()
{
    mapping fam;
    object ob;
    if (!(fam = this_player()->query("family") ) || (fam["family_name"]!="姑苏慕容"))
        return RANK_D->query_respect(this_player()) +
            "你非本派弟子，也来偷窥我的宝物，简直是笑话！";
    if ( this_player()->query("score") < 400 )
        return "你对本派贡献不够，本派的灵药现在不能给你。";
    if (query("ml_count") < 1)
        return "现在我这没有茉莉花露。";
    add("ml_count",-1);
    ob = new("/d/murong/npc/obj/moli");
    ob->move(this_player());
    return "我这滴茉莉花露你就拿去吧。";
}
string ask_hm()
{
    mapping fam;
    object ob;
    if (!(fam = this_player()->query("family") ) || (fam["family_name"]!="姑苏慕容"))
        return RANK_D->query_respect(this_player()) +
            "你非本派弟子，也来偷窥我的宝物，简直是笑话！";
    if ( this_player()->query("score") < 400 )
        return "你对本派贡献不够，本派的灵药现在不能给你。";
    if (query("hm_count") < 1)
        return "现在我这没有寒梅花露。";
    add("hm_count",-1);
    ob = new("/d/murong/npc/obj/hanmei");
    ob->move(this_player());
    return "我这滴寒梅花露你就拿去吧。";
}
void attempt_apprentice(object ob)
{
    if ( ob->query("class")=="bonze" ) {
        if (ob->query("gender")=="女性")
            command ("say 师太还是先还了俗再来拜我派吧。");
        else
            command ("say 大师傅还是先还了俗再来拜我派吧。");
        return;
    }
    if ((string)ob->query("family/family_name") == "灵鹫宫"
            && ob->query("lingjiu/xiulian"))
    {
        ob->set_temp("bai/ask",1);
        command("say "+RANK_D->query_respect(ob)+"，你现在拜我似乎会有很大损失，你能拿定主意吗？(answer)");

    }
    else
    {
        command("say 好吧，"+RANK_D->query_respect(ob)+"！我就收下你了！\n");
        command("recruit " + ob->query("id"));
        return;
    }
}
void do_answer(string arg)
{
    object me=this_player();
    if (!me->query_temp("bai/ask")) return;
    if (!arg || (arg != "是" && arg != "能" && arg != "yes"))
        command("say 你说的什么乱七八糟的，看来你是没有诚心，算了！");
    else
    {
        command("say 好吧，"+RANK_D->query_respect(me)+"，我就收下你了！");
        me->set("mud_age",me->query("lingjiu/mud_age"));
        me->set("age",14+me->query("mud_age")/3600/24);
        me->delete("lingjiu/skill_status");
        me->delete("lingjiu/qi");
        me->delete("lingjiu/eff_qi");
        me->delete("lingjiu/max_qi");
        me->delete("lingjiu/jing");
        me->delete("lingjiu/eff_jing");
        me->delete("lingjiu/max_jing");
        me->delete("lingjiu/jingli");
        me->delete("lingjiu/neili");
        me->delete("lingjiu/max_jingli");
        me->delete("lingjiu/max_neili");
        me->delete("lingjiu/combat_exp");
        me->delete("lingjiu/need_xiulian");
        me->delete("lingjiu/mud_age");
        me->delete("lingjiu/xiulian");
        me->delete("lingjiu/last_xiulian_time");
        me->delete_temp("bai/ask");
        command("recruit "+me->query("id"));
    }
    return;
}
