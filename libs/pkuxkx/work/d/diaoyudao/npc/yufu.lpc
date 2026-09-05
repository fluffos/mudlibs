// yufu.c 老渔夫
// hongdou 98.10.1

#include <ansi.h>

inherit NPC;

int ask_me();

void create()
{
        set_name("老渔夫", ({ "yu fu","yufu","fu" }) );
        set("gender", "男性");
        set("age", 65);
        set("long", 
        "这是一个被倭寇抓来的普通中国老渔夫，从他那饱经沧桑的脸上看到了两行清泪。\n");
        
        set("combat_exp", 500);
        set("shen_type", 0);
        set("attitude", "friendly");
        set("apply/attack",  10);
        set("apply/defense", 10);
        set("chat_chance", 5);
        set("chat_msg", ({
                "那些坏蛋，抢了我们的东西，绑架了我的孙女，还强迫我给他们做饭，真想毒死他们。\n",
                "我那孙女还小，可别让那伙狗强盗糟蹋了！谁能救救她啊？\n",
                "如果我孙女死了，剩我一个孤老头子可怎么活啊！哎！这是什么世道呀！\n", }) );
        set("inquiry",([ 
              "孙女" : "我就这么一个亲人了，她父母死得早，我们祖孙俩一直相依为命，
现在被他们给关了起来，这可怎么办啊？\n",
              "救人" : (: ask_me :),
	      "逃跑" : "我孙女还在他们手中，我怎么敢逃跑呢？不但不能逃，还要给他
们做饭，这样才能保住我孙女的命。\n",
              ]));

        set("shen_type",1);set("score",200);setup();
        
        carry_object(__DIR__"obj/suoyi")->wear();

}

int ask_me()
{
    say(CYN"老渔夫焦急的道：“我的孙女就关在大帐后的其中一个帐篷内，求求您快把她
救出来吧，我给您磕头了。”\n"NOR);
    this_player()->set_temp("marks/问",1);
    return 1;
}	

int accept_object(object who, object ob)
{
        object me,key,npc,huan;
        npc = this_object();
	huan=new(__DIR__"obj/erhuan");
	key= new(__DIR__"obj/key");
        if ((string)ob->query("name")==HIY"铜耳环"NOR)
	{
	   call_out("destroy",1,ob);
	   if (who->query_temp("marks/救"))
	   { 
                message_vision(HIC
"\n$N喜泣道：“多谢恩公！您的大恩大德我们这辈子都报答不完呀。”\n"NOR,npc);
		tell_object(who,HIC
"\n随即又道：“这是我在附近砍柴时捡到的一把钥匙，就送给恩公吧，也许您有用到的时候。”\n"NOR);
		message_vision(HIC"\n说完$N趴在地上重重地给$n磕了几个响头，悄悄地离开了大帐。\n\n"NOR,npc,who);
		key->move(who);
		who->delete_temp("marks/问");
		who->delete_temp("marks/救");
		who->add("shen",(random(5)+1));
		call_out("destroy",1,npc);
	        return 1;
	   }
	   if (who->query_temp("marks/死"))
	   {
		message_vision(HIC"\n$N喜道：“这就是我孙女的耳环啊！是您救了她吗？我得赶快去找她，
多谢恩公了。” 老汉一溜烟的跑了出去。\n"NOR,npc);
		message_vision(HIC"\n不一会儿，$N又跑了回来，冲$n痛哭道：“你根本没有救出我孙女，怎
么还骗我呢？她死了，我也不想活了！说完跑到海边，跳海自尽了！”\n"NOR,npc,who);
		who->add("shen",-(random(5)+1));
		who->delete_temp("marks/死");
		call_out("destroy",1,npc);
	        return 1;
	   }
	    say("老渔夫说道：“这就是我孙女的耳环，你把他救出来了吗？\n");
		return 0;
	}
}

void destroy(object ob)
{
        destruct(ob);
        return;

}
