// zhang1.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

#include "riyue.h"

int shang_ya();
int ask_pfm(string arg);
int accept_ask2(object me, string topic);

void create()
{
    set_name("张乘风", ({"zhang chengfeng", "zhang", "chengfeng"}));
    set("nickname", HIY "金猴神魔" NOR );
    set("title", "日月神教长老");
    set("gender", "男性");
    set("age", 42);
    set("shen_type", -1);
    set("long",
	"他是日月神教长老。\n");
    set("attitude", "peaceful");

    set("per", 21);
    set("str", 30);
    set("int", 30);
    set("con", 30);
    set("dex", 30);

    set("qi", 3000);
    set("max_qi", 3000);
    set("jing", 1000);
    set("max_jing", 1000);
    set("neili", 3000);
    set("max_neili", 3000);
    set("jiali", 300);

    set("combat_exp", 1500000);
    set("score", 0);
    set("inquiry", ([
    "#11-天旋地转"  : (: ask_pfm("天旋地转") :),
	"黑木崖" : "本教弟子或持教主令牌方能上崖！\n",
	"日月神教" : "本教弟子或持教主令牌方能上崖！\n",
	"日月教" : "本教弟子或持教主令牌方能上崖！\n",
	"黑木令" : "那是本教教主令牌，见牌如见教主亲临！\n",
	"上崖" :   (: shang_ya :),
    ]) );

    set_skill("force", 160);
    set_skill("unarmed", 160);
    set_skill("dodge", 160);
    set_skill("parry", 160);
    set_skill("club", 160);
    
    
    set_skill("riyue-xinfa", 160);
    set_skill("tianmo-gun", 160);
    set_skill("xuwu-piaomiao", 160);
    set_skill("piaomiao-shenfa", 160);
    set_skill("literate", 120);

    map_skill("force", "riyue-xinfa");
    map_skill("club", "tianmo-gun");
    map_skill("parry", "tianmo-gun");
    map_skill("unarmed", "xuwu-piaomiao");
    map_skill("dodge", "piaomiao-shenfa");

	/*
	set("chat_msg_combat", ({
		(: perform_action, "club.tian" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}));
	*/


    create_family("日月神教", 2, "长老");

    setup();
    carry_object(__DIR__"obj/shutonggun")->wield();
    carry_object("/clone/misc/cloth")->wear();
}

int shang_ya()
{
    object ob, myenv ;
    ob = this_player ( ) ;
    if (ob->query("family/family_name") == "日月神教")
    {
	message_vision("张乘风一招手，崖上落下一个大吊篮。\n",ob);
	message_vision("$N一弯腰进了吊篮，吊篮缓缓地铰上崖去......\n", ob);
	myenv = environment (ob) ;
	ob->move ("/d/heimuya/basket");
	call_out("goto_heimuya", 10, ob) ;
       	return 1;
    }
    else  
    message_vision("张乘风上上下下打量了$N一下：什么！上崖？你的黑木令呢？！\n",ob);
    return 1;
}

int accept_object(object who, object ob)
{
    object myenv ;
    if (ob->query("id") == "heimu ling")
    {
	message_vision("张乘风对$N说：好！这位" + RANK_D->query_respect(who) + "不错，那就请吧！\n" , who);
	message_vision("张乘风一招手，崖上落下一个大吊篮。\n", who);
	message_vision("$N一弯腰进了吊篮，吊篮缓缓地铰上崖去......\n", who);
	myenv = environment (who) ;
	who->move ("/d/heimuya/basket");
	call_out("goto_heimuya",10,who) ;
       	return 1;
    }
    else  if (! ::accept_object(who,ob))
    {
        message_vision("张乘风对$N说：你敢耍我？！\n", who);
        this_object()->kill_ob(who);
        return -1;
    }
    return 1;
}

void goto_heimuya (object ob)
{
    tell_object(ob , "你眼前一亮，一幢幢白色建筑屹立眼前，霎是辉煌。\n");
    ob->move ("/d/heimuya/chengdedian") ;
}
void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob))
		return;

    if (ob->query_skill("riyue-xinfa", 1) < 120) {
         tell_object(ob, "你的日月心法还没练到家。\n");
         return;
    }
	command("say 好吧！我就收下你了。");
	command("recruit " + ob->query("id"));
}

int ask_pfm(string arg)
{
	if (arg) {
		object me = this_player();
		
		return accept_ask2(me, arg);
	}
	return 1;
}
int accept_ask2(object me, string topic)
{
	if (me->query("family/family_name") == "日月神教")
	switch (topic)
	{
        case "天旋地转" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/tianmo-gun/tian",
                           "name"    : "天旋地转",
                           "sk1"     : "tianmo-gun",
                           "lv1"     : 100,]));
                break;

        default:
            break;
	}
    tell_object(me, name()+"：你说什么？再说一遍？\n");
	return 1;
}
