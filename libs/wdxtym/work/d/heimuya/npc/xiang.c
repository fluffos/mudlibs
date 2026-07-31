// xiang.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include "riyue.h"
int ask_pfm(string);
int accept_ask(object me, string topic);

int ask_kill();

void create()
{
    set_name("向问天", ({ "xiang wentian", "xiang"}));
    set("nickname", HIR "天王老子" NOR );
    set("gender", "男性");
    set("title", "日月神教光明右使");
    set("long", "他就是日月神教的光明右使。为人极为豪爽。\n");
    set("age", 45);
    set("shen_type", -1);

    set("str", 21);
    set("per", 28);
    set("int", 30);
    set("con", 26);
    set("dex", 30);
    set("chat_chance", 1);
    set("inquiry", ([
      "#11-望断秋水"  : (: ask_pfm("望断秋水") :),
      "杨莲亭"     : "这种人，该杀！\n",
      "东方不败"   : "篡位叛徒，我非杀了他不可！\n",
      "杀东方不败" : (: ask_kill() :),
      "任我行"     : "教主被困，已历十年......\n",
    ]));
    set("qi", 4000);
    set("max_qi", 4000);
    set("jing", 1000);
    set("max_jing", 1000);
    set("neili", 3500);
    set("max_neili", 3500);
    set("jiali", 80);

    set("combat_exp", 2500000);
    set("score", 0);

    set_skill("force", 160);
    set_skill("unarmed", 160);
    set_skill("dodge", 160);
    set_skill("parry", 160);
    set_skill("sword", 160);
    set_skill("blade", 160);
    set_skill("strike", 160);
    
    set_skill("riyue-xinfa", 160);
    set_skill("tianmo-zhang", 160);
    set_skill("tianmo-dao", 160);
    set_skill("tianmo-jian", 160);
    set_skill("xuwu-piaomiao", 160);
    set_skill("piaomiao-shenfa", 160);
    set_skill("literate", 160);

    map_skill("force", "riyue-xinfa");
    map_skill("sword", "tianmo-jian");
    map_skill("blade", "tianmo-dao");
    map_skill("strike", "tianmo-zhang");
    map_skill("parry", "tianmo-gun");
    map_skill("unarmed", "xuwu-piaomiao");
    map_skill("dodge", "piaomiao-shenfa");

	/*
	set("chat_msg_combat", ({
		(: perform_action, "strike.huashen" :),
		(: perform_action, "strike.huashen" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}));
	*/
    create_family("日月神教", 2, "光明右使");

    setup();
    carry_object(__DIR__"obj/cloth")->wear();
}

int ask_kill()
{
   object ob,me = this_player();

   command("tell "+this_player()->query("id")+" 你要去杀东方不败？\n");
   message_vision(HIC "向问天对$N点了点头说：我助你一臂之力。"NOR"\n",this_player());
   ob=new("/d/heimuya/npc/obj/card4");
   ob->move(me);
   tell_object(me,"向问天从怀里摸出一块令牌塞到你的手上。\n");
   return 1;
}
void attempt_apprentice(object ob)
{
   if (! permit_recruit(ob))
		return;
   
   if (ob->query_skill("riyue-xinfa", 1) < 120) {
         tell_object(ob, "你的日月心法还没练到家。\n");
         return;
   }

   if (ob->query("gender", 1) =="无性") {
         tell_object(ob, "我生平最讨厌如东方老贼一样的阉人！\n");
         return;
   }
   
   command("say 好吧！我就收下你了。");
   command("recruit " + ob->query("id"));
}

int ask_pfm(string arg)
{
	if (arg) {
		object me = this_player();
		
		return accept_ask(me, arg);
	}
	return 1;
}
int accept_ask(object me, string topic)
{
	if (me->query("family/family_name") == "日月神教")
	switch (topic)
	{
        case "望断秋水" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/liushui-bian/wang",
                           "name"    : "望断秋水",
                           "sk1"     : "liushui-bian",
                           "lv1"     : 120,]));
                break;

        default:
			break;
	}
	tell_object(me, name()+"：你说什么？再说一遍？\n");
	return 1;
}

