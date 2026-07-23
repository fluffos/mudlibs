#include <ansi.h>;


inherit NPC;
inherit F_MASTER;


mixed ask_me();

void create()
{
        set_name("端木元", ({ "duanmu yuan", "duanmu", "yuan"}));
        set("gender", "男性");
        set("title", "海南岛赤焰洞洞主");
        set("nickname", HIR "归去来兮" NOR);
        set("age", 54);
        set("long", @LONG
这大头老者就是海南岛五指山赤焰洞洞主端木
元。只见他一颗大脑袋光秃秃地，半根头发也
无，脸上巽血，远远望去，便如大血球般。
LONG );
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
    set("pubmaster",1);
        set("qi", 8000);
        set("max_qi", 8000);
        set("jing", 8800);
        set("max_jing", 8800);
        set("neili", 8200);
        set("max_neili", 8200);
        set("jiali", 120);
        set("combat_exp", 2200000);

        set_skill("force", 200);
        set_skill("wudoumi-shengong", 200);
        set_skill("dodge", 180);
        set_skill("feiyan-zoubi", 180);
        set_skill("unarmed", 200);
        set_skill("parry", 200);
        set_skill("martial-cognize", 180);
        set_skill("literate", 140);

        map_skill("dodge", "feiyan-zoubi");
        map_skill("force", "wudoumi-shengong");
        map_skill("parry", "wudoumi-shengong");
        map_skill("unarmed", "wudoumi-shengong");

        prepare_skill("unarmed", "wudoumi-shengong");

        set("inquiry", ([
                "五斗米神功" : "这…这个……这是由地火功演化而来的一门功夫。",
                "地火功"     : "地火功是我海南岛五指山赤焰洞一派的基本功夫。",
                "虚竹子"     : "他是我们灵鹫宫新的主公，我们全部听他号令。",
                "虚竹"       : "他是我们灵鹫宫新的主公，我们全部听他号令。",
        ]));

        create_family("赤焰洞", 14, "洞主");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.gui" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );

        set("master_ob",3);
	setup();
        carry_object("/clone/misc/cloth")->wear();
}

int recognize_apprentice(object ob, string skill)
{
if (ob->query("family/family_name") == "灵鹫宫"  && ob->query("family/family_name") != "逍遥派")
        {
                command("?");
                command("say 你是哪里钻来的鬼东西？");
                return 0;
        }



/*        if (skill != "wudoumi-shengong" && skill != "unarmed")
        {
                command("say 我只传授你五斗米神功和一些拳脚知识，不学就算了。");
                return 0;
        }
*/
        if (skill == "unarmed" && ob->query_skill("unarmed", 1) > 179)
        {
                command("sweat");
                command("say 够了，够了！累死我了，剩下的你自己去研究。");
                return 0;
        }

        if (! ob->query_temp("can_learn/duanmuyuan"))
        {
                command("sigh");
                command("say 这个…既然你是主公派来的，我也只有教你好了。");
                ob->set_temp("can_learn/duanmuyuan", 1);
        }
        return 1;
}



 
void attempt_apprentice(object ob)
{
if (ob->query("family/family_name") != "灵鹫宫")
{
 
        command("@@");
        command("say 你…你没搞错吧？既然这样，那你跟着我好了。");
        command("recruit " + ob->query("id"));
}
}



