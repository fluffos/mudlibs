#include <ansi.h>
#include <title.h>
inherit NPC;

inherit F_MASTER;

void create()
{
    set_name("梅超风",({"mei chaofeng","mei"}));
    set("nickname",GRN"风流女魔"NOR);
    set("title",RED"黑风双煞"NOR);
    set("long","她是一位冷血女魔，见人就杀。\n");
    set("gender","女性");
    set("age",40);
    set("attitute", "peaceful");
    set("str",28);
    set("int",29);
    set("con",29);
    set("dex",28);
    set("shen_type",-1);
    set("score",300000);
    set("max_qi",1200);
    set("max_jing",1000);
    set("neili",1500);
    set("max_neili",1500);
    set("jiali",30);
    set("combat_exp",350000);
    set_skill("force",100);
    set_skill("luoying-shenfa",110);
    set_skill("dodge",100);
    set_skill("claw",150);
    set_skill("parry",100);
    set_skill("bihai-shengong",110);
    set_skill("luoying-shenfa",100);
    set_skill("jiuyin-baiguzhao",150);
    map_skill("force","bihai-shengong");
    map_skill("dodge","luoying-shenfa");
    map_skill("claw","jiuyin-baiguzhao");
    map_skill("parry","jiuyin-baiguzhao");
    prepare_skill("claw","jiuyin-baiguzhao");
    create_family("桃花岛",2,"弟子");
    setup();
    carry_object("/d/city/obj/cloth")->wear();
}

void init()
{

    object ob;
    mapping myfam;
    ::init();
    if (interactive(ob = this_player())) {
	  myfam = (mapping)ob->query("family");
          if ((!myfam || (myfam["family_name"] != "桃花岛"&&myfam["master_name"] != "梅超风")) &&
(!wizardp(ob))) {
        if( this_object()->is_killing(ob) )
            return;
        if (ob->query("combat_exp") > 1000000)
        {
        this_object()->set_leader(ob);
        remove_call_out("do_killing");
        call_out("do_killing", 1, ob);
        }
        return;
        }
    }
}

void do_killing(object ob)
{
    object me = this_object();

    if( !ob || (environment(ob) != environment()) )
        return;

    command("say 哪里钻出来的野种，到这里来暗算老娘，现今想逃也来不及了！\n");
    command("say 又有人白送死来为我练「九阴白骨爪」了！\n");
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
        command("say 我梅超风生平最讨厌伪善道德之人。\n");
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
        if((string)ob->query("gender")!="女性")
      			ob->set("title",RED "桃花岛" NOR + HIW +" 第三代弟子" NOR);
	        else
      			ob->set("title",RED "桃花岛" NOR + YEL +" 第三代弟子" NOR);
//title系统记录玩家title by seagate@pkuxkx
	      ob->set_title(TITLE_RANK, ob->query("title"));
        return;
    }
}

void heal()
{
    object ob = this_object();

    if( ob->query("eff_qi") < ob->query("max_qi") )
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
