#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("陈玄风",({"chen xuanfeng","chen","xuanfeng"}));
    set("nickname",GRN"弑人狂魔"NOR);
    set("title",RED"黑风双煞"NOR);
    set("long","他看起来凶神恶煞的样子,一瞧便让人毛骨悚然.\n");
    set("gender","男性");
    set("age",45);
    set("attitude","aggressive");
    set("str",32);
    set("int",29);
    set("con",29);
    set("dex",30);
    set("shen_type",-1);
    set("score",300000);
    set("max_qi",1500);
    set("max_jing",1200);
    set("neili",2000);
    set("max_neili",2000);
    set("jiali",30);
    set("combat_exp",400000);
    set_skill("force",100);
    set_skill("dodge",100);
    set_skill("strike",150);
    set_skill("parry",100);
    set_skill("bihai-shengong",110);
    set_skill("luoying-xinfa", 120);
    set_skill("cuixin-zhang",150);
    set_skill("sword",120);
    set_skill("hand",100);
    set_skill("fuxue-shou",120);
    set_skill("yuxiao-jian",90);
    set_skill("finger",100);
    set_skill("tanzhi-shengong",100);
    set_skill("luoying-shenfa",100);
    set_skill("unarmed",100);
    map_skill("force","bihai-shengong");
    map_skill("hand","fuxue-shou");
    map_skill("sword","yuxiao-jian");
    map_skill("finger","tanzhi-shengong");
    map_skill("dodge","luoying-shenfa");
    map_skill("strike","cuixin-zhang");
    map_skill("parry","cuixin-zhang");
    prepare_skill("finger","tanzhi-shengong");
    prepare_skill("strike","cuixin-zhang");
    create_family("桃花岛",2,"弟子");
    setup();
    carry_object("/d/city/obj/cloth")->wear();
}

void init()
{
    object ob;
    ob = this_player(1);
    ::init();
    if( ob && (string)ob->query("family/family_name") != "桃花岛" && !wizardp(ob)) {
        if( this_object()->is_killing(ob) )
            return;
        if (ob->query("combat_exp") > 100000)
        {
        this_object()->set_leader(ob);
        remove_call_out("do_killing");
        call_out("do_killing", 1, ob);
        }
        return;
    }
}

void do_killing(object ob)
{
    if(!ob||environment(ob)!=environment())
        return;
        
    this_object()->kill_ob(ob);
}

void attempt_apprentice(object ob)
{
    if((string)ob->query("family/family_name")!="桃花岛")
    {
        command("say 我派不收外派弟子。\n");
        command("say "+RANK_D->query_respect(ob)+"要想拜我派可先拜陆冠英。\n");
        return;
    }
    if((int)ob->query_skill("bihai-shengong",1)<40)
    {
        command("say 你的碧海神功太低了，无法修炼我派武功。\n");
        command("say "+RANK_D->query_respect(ob)+"是否应该在碧海神功上多下?点功夫.\n");
        return;
    }
    if((int)ob->query("shen")>=10000)
    {
        command("say 我陈玄风这一辈子就最恨伪善道德之人.\n");
        command("say"+RANK_D->query_respect(ob)+"若能杀他"+"几个伪君子，我一定收你。");
        return;
    }
    if((int)ob->query("betrayer")>=3)
    {
        command("say "+RANK_D->query_respect(ob)+"多次背信弃义,我怎可收你.");
        return;
    }
    else
    {
        command("say 好吧，"+RANK_D->query_respect(ob)+"我就收下你了.\n");
        command("recruit "+ob->query("id"));
        ob->set("title",RED"桃花岛"NOR+GRN"第三代弟子"NOR);
        return;
    }
}

void heal()
{
    object ob = this_object();

    if(ob->query("eff_qi")<ob->query("max_qi"))
    {
        command("exert heal");
        command("enforce 50");
        return;
    }
    if(ob->query("qi")<ob->query("eff_qi"))
    {
        command("exert recover");
        return;
    }
    if(ob->query("jing")<ob->query("eff_jing"))
    {
        command("exert regenerate");
        return;
    }
}
