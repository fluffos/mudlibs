//abi.c
//by hehe
//2003.3.13

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include "/new_quest/qzhongli.h"
#include "/new_quest/quest.h"

string ask_sword();
void do_answer(string);

void create()
{
    set_name("阿碧", ({ "a bi", "abi", "bi" }));
    set("long",
            "她是慕容复的贴身丫鬟\n"
            "她看起来十多岁，容貌秀丽，别有一番可人之处。\n");
    set("gender", "女性");
    set("age", 20);
    set("title",RED"姑苏慕容"NOR + HIB"侍女"NOR);
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
    set_skill("literate",70);
    set_skill("canhe-zhi",70);
    set_skill("murong-daofa",70);
    set_skill("murong-jianfa",70);
    set_skill("yanling-shenfa",70);
    set_skill("shenyuan-gong",70);
    set_skill("xingyi-zhang",70);
    set_skill("strike",70);

    map_skill("finger","canhe-zhi");
    map_skill("strike","xingyi-zhang");
    map_skill("sword","murong-jianfa");
    map_skill("blade","murong-daofa");
    map_skill("force","shenyuan-gong");
    map_skill("dodge","yanling-shenfa");

    prepare_skill("finger","canhe-zhi");
    set_temp("apply/attack", 20);
    set_temp("apply/defense", 20);

    create_family("姑苏慕容" , 4, "弟子");
    setup();
    set("count",1);

    carry_object("/d/murong/npc/obj/shoe")->wear();
    carry_object("/d/murong/npc/obj/skirt")->wear();
    set("inquiry", ([
                "name" : "我是慕容公子的贴身丫鬟，叫做阿碧，好久没有见到慕容公子了。\n",
                "here" : "这里是琴韵小筑，是慕容老爷为了照顾我给我安排的住处。\n",
                "曼佗罗山庄" : "曼佗罗山庄的王姑母这一阵子不让外人去她的山庄，连我们都不敢。\n",
                "慕容复" : "慕容复是燕子坞的主人，你找我们家公子什么事?\n",
                "听香剑" : (: ask_sword :),
        "quest":   (: ask_quest() :),
        "cancelquest":   (: ask_cancel() :),
        "取消任务":   (: ask_cancel() :),
                ]));
}
string ask_sword()
{
    object me,ob;
    me = this_player();

    if( me->query("family/family_name")!="姑苏慕容")
        return "你不是我们姑苏慕容的弟子，也想要剑，也不害臊！";
    if( me->query("score") < 400 )
        return "你对本派贡献不够，本派的宝剑怎么能交给你呢？";
    if( me->query("str")<18)
        return "你的膂力太低，这把剑不太适合你用吧!";
    if( me->query("combat_exp")<2000000)
        return "你的实战经验还是太浅，再去多历练一下再来吧！";
    if( query("count") < 1)
        return "听香剑已经被你的师兄弟们拿走了！";
    ob = new("/d/murong/obj/ting-jian");
    ob->move(me);
    add("count", -1);
    return "好吧，这把“听香剑”就交给你保存吧！";
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
/*
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
*/
