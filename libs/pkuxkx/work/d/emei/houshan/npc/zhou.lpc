//create bye kiden  
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
void consider();
void heal();
int ask_me();
int ask_job();

void create()
{
        set_name("周芷若", ({"zhou zhiruo","zhou","zhi ruo",}));
        set("long","她是峨嵋派第四代弟子中的杰出人物，功夫犹胜乃师灭绝师太。\n"
        );
        set("gender", "女性");
        set("attitude", "friendly");
        set("age", 20);
        set("shen_type", 1);
        set("str", 30);
        set("int", 27);
        set("con", 20);
        set("dex", 30);
        set("per", 50);
        set("max_qi", 3000);
        set("max_jing", 800);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 120);
        set("combat_exp", 12000000);
        set("score", 100);
        set("sword",1);
        set_skill("force", 400);
        set_skill("linji-zhuang", 450);
        set_skill("dodge", 400);
        set_skill("zhutian", 400);
        set_skill("tiangang-zhi", 480);
        set_skill("finger", 480);
        set_skill("jinding-mianzhang",460);
        set_skill("strike",480);
        set_skill("fuliu-jian",450);
        set_skill("sword",400);
        set_skill("yanxing-dao",450);
        set_skill("blade",400);
        set_skill("throwing",400);
        set_skill("pili-dan",450);
        set_skill("parry", 400);
        set_skill("mahayana", 450);
        set_skill("literate", 400);
        map_skill("force", "linji-zhuang");
        map_skill("dodge", "zhutian");
        map_skill("finger", "tiangang-zhi");
        map_skill("parry", "fuliu-jian");
        map_skill("blade", "yanxing-dao");
        map_skill("sword", "fuliu-jian");
        map_skill("strike", "jinding-mianzhang");
        map_skill("throwing", "pili-dan"); 
        prepare_skill("finger", "tiangang-zhi");
        prepare_skill("strike", "jinding-mianzhang");
        set("chat_chance",100);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        }) );
        set("chat_chance",100);
        set("chat_msg",({
//        (:heal:),
        }));
        create_family("峨嵋派", 4, "弟子");
        setup();
        carry_object(__DIR__"obj/changjian");
        carry_object(__DIR__"obj/gangdao");
        carry_object(__DIR__"obj/cloth")->wear();

        set("inquiry",([
                 "张无忌" : "......",
                 "指点" : (: ask_job :),
                 "zhidian" : (: ask_job :),
                 ]));
}

int ask_job()
{
    object me=this_player();
	object user;
    object key=load_object("/d/emei/houshan/jxan");
    if (!me->query("emeinewbiejobdone"))
    {
        command("hmm");
        return 1;
    }
    user=me->query_temp("link_ob");
        /*if (!user->query("realuser_verified"))
        {
            tell_object(me,"只有通过实名认证的玩家才可领取额外奖励。\n");
            return 1;
        }*/
	if (!user->query("safari_skill/em_jyg"))
        {
            tell_object(me,"你的阅历不够，不足以学习峨嵋九阳功。\n");
            return 1;
        }
    if (me->query("family/family_name")!="峨嵋派")
    {
        command("hmm");
        return 1;
    }
    if (me->query("emeinewbiejobdonedone"))
    {
        command("hmm");
        return 1;
    }
    command("say 好吧，我就教给你点不同的东西。");
    command("say 郭襄祖师创立峨嵋派，其实很多武功源自峨嵋九阳功。");
    command("say 我闭关多年，终于悟得一鳞半爪，今天倾囊传授于你。");
    command("say 多在云台上静坐，也许可以获得些进步。");
    me->set_skill("emei-jiuyanggong",10);
    write(HIC"你的峨嵋九阳功进步了！\n"NOR);
    me->set("emeinewbiejobdonedone",1);
    return 1;
}

void attempt_apprentice(object ob)
{
        object me  = this_object();
        mapping ob_fam;
        mapping my_fam  = me->query("family");
        string name, new_name;
        name = ob->query("name");
        if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "峨嵋派")
        {
                command("say " + RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？");
                return;
        }
        if ((int)ob->query("score") < 2500 ) 
        {
        command("say 我不收徒的，但是如果你对峨眉有突出贡献的话，我可以考虑指点你一些功夫！");
        return;
        } 
        command("recruit "+ob->query("id"));
        return;
}

int recognize_apprentice(object ob, object who)
{
        if((string)ob->query("family/family_name") != "峨嵋派" )
        return 0;
        return 1;
}

int prevent_learn(object me, string skill)
{
  if (me->query("score")<2500)
  {
          command("say 你对本门的贡献太小了！");
          return 1;
  }
  if (skill != "jiuyin-shengong" && skill !="jiuyin-baiguzhao" && skill !="claw") 
  {
          command("heng");
          command("say 其他的这些你跟我师傅去学吧！");
          return 1;
  }
  return 0;
}
