// dongfang.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
#include "riyue.h"

int ask_pfm(string);
string ask_baodian();
string ask_kuihua();
int accept_ask(object me, string topic);

void create()
{
    set_name("东方不败", ({"dongfang bubai", "dongfang", "bubai"}));
    set("nickname", HIY "天下无敌" NOR);
    set("title", HIM "日月神教教主" NOR);
    set("gender", "无性");
    set("shen_type", -1);
    set("age", 42);
    set("long",
	"她就是日月神教教主。号称无人可敌，因此有一称号为「东方不败」。\n");
    set("attitude", "peaceful");

    set("per", 21);
    set("str", 21);
    set("int", 30);
    set("con", 26);
    set("dex", 30);

    set("chat_chance", 1);
    set("chat_msg", ({
  	"东方不败叹了口气道：“唉 …… 我的杨大哥....他怎么还不回来，我好\n"
 	"挂念他 ……东方不败眼中流露无限迷茫。\n",
    }));

    set("qi", 400000);
    set("max_qi", 400000);
    set("jing", 100000);
    set("max_jing", 100000);
    set("neili", 400000);
    set("max_neili", 400000);
    set("jiali", 400);

    set("combat_exp", 5500000);
    set("score", 0);

    set_skill("force", 300);
    set_skill("unarmed", 300);
    set_skill("dodge", 300);
    set_skill("parry", 300);
    set_skill("sword", 300);
    set_skill("hand", 300);
    
    set_skill("riyue-xinfa", 300);
    set_skill("riyue-guanghua", 300);
    set_skill("pixie-jian", 300);
    set_skill("kuihua-shengong", 300);
    set_skill("xuwu-piaomiao", 300);
    set_skill("piaomiao-shenfa", 300);
    set_skill("literate", 300);

    map_skill("force", "kuihua-shengong");
    map_skill("sword", "pixie-jian");
    map_skill("parry", "pixie-jian");
    map_skill("unarmed", "pixie-jian");
    map_skill("dodge", "piaomiao-shenfa");

     set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "unarmed.cimu" :),
		(: perform_action, "dodge.gui" :),
		(: perform_action, "kuihua" :),
		(: perform_action, "pi" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}));
	set("inquiry", ([
		"#01-葵花秘诀"  : (: ask_kuihua() :),
		"#11-钟馗抉目"  : (: ask_pfm("钟馗抉目") :),
		"#21-剑魔乱舞"  : (: ask_pfm("剑魔乱舞") :),
		"#31-葵花宝典2"  : (: ask_baodian() :),
         "杨莲亭"   : "你敢直称我爱人的名字，想找死呀？ \n",
         "葵花上册" : "如果你能帮我取得葵花宝典上册，我一定重重谢你。\n",
	]) );
	set("no_teach", ([
		"kuihua-shengong"     : "嘿嘿！想学葵花神功？这种技能只可以研究和读书，我可不会教你。",
	]));
     
    create_family("日月神教", 1, "第二代教主");

    setup();
    carry_object("/d/fuzhou/obj/xiuhua")->wield();
    carry_object("/d/wanjiegu/npc/obj/qi-dress")->wear();
}

string ask_kuihua()
{
   mapping family; 
   object ob, me;
	
   me = this_player();
   if (me->query("quest2/kuihua/pass"))
      return RANK_D->query_respect(me) + "已经尽得我真传，还问什么？";
   if ( !(family = me->query("family")) || family["family_name"] !=  "日月神教")
      return RANK_D->query_respect(me) + "与本教素无来往，不知此话从何谈起？";
   if (family["master_id"] != "dongfang bubai")
      return RANK_D->query_respect(me) + "与我毫无关系，有什么资格问我要秘诀？";
   if (me->query_skill("kuihua-shengong", 1) < 200)
      return RANK_D->query_respect(me) + "的葵花神功好像练得不够火候？";

   me->set("quest2/kuihua/pass", 1);
   
   command("chat 今日我将秘诀传授于"+me->name()+"，望你能将我日月神教发扬光大！");

   return "好，好，好，我东方不败一身绝技终于后继有人！";
}
string ask_baodian()
{
   mapping family; 
   object ob, me;
	
   me = this_player();
   if ( !(family = me->query("family")) || family["family_name"] !=  "日月神教")
      return RANK_D->query_respect(me) + "与本教素无来往，不知此话从何谈起？";
   if (family["master_id"] != "dongfang bubai")
      return RANK_D->query_respect(me) + "与我毫无关系，有什么资格问我要东西？";
   if (me->query_skill("kuihua-shengong", 1) < 1 && me->query_skill("pixie-jian", 1) < 180)
      return RANK_D->query_respect(me) + "的辟邪剑法好像练得不够火候？";

   ob = new("/clone/book/kuihuabaodian");
   ob->move(me);
   message_vision("$N在东方不败那里拿到一本"+ob->name()+NOR"。\n",me);

   return "好吧，"+ob->name()+NOR"就交给你了，一定要好好学习！";
}
void attempt_apprentice(object ob)
{
   if (! permit_recruit(ob))
		return;
   
   if (ob->query_skill("riyue-xinfa", 1) < 0) {
         tell_object(ob, "你的日月心法还没练到家。\n");
         return;
   }
   if (ob->query("shen", 1) > -100000) {
         tell_object(ob, "你还不够邪恶，我暂时不能收你。\n");
         return;
   }
   if (ob->query("gender", 1) !="无性") {
         tell_object(ob, "你的性别不适合修炼我的神功，真是可惜。\n");
         return;
   }
   if (ob->query_skill("xixing-dafa", 1) > 1 || ob->query_skill("tianmo-jian", 1) > 1) {
         tell_object(ob, "你已经学会吸星大法或是天魔剑法，我怎能收你？\n");
         return;
   }
   if (ob->query("family/master_id") == "ren woxing") {
         tell_object(ob, "你个臭不要脸的，任我行派你来做卧底的吗？！\n");
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
	if (me->query("family/family_name") == "日月神教" && me->query("family/master_id") =="dongfang bubai")
	switch (topic)
	{
        case "钟馗抉目" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/kuihua-shengong/juemu",
                           "name"    : "钟馗抉目",
                           "sk1"     : "kuihua-shengong",
                           "lv1"     : 150,]));
                break;

        case "剑魔乱舞" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/kuihua-shengong/luanwu",
                           "name"    : "剑魔乱舞",
                           "sk1"     : "kuihua-shengong",
                           "lv1"     : 200,]));
                break;
        default:
			break;
	}
      tell_object(me, name()+"：你说什么？再说一遍？\n");
	return 1;
}
