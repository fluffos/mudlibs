//xianren.c 闲人
//by zoom
//2004.3.30

#include <ansi.h>

inherit NPC;

int ask_talk();
void greeting(object);

void create()
{
	set_name("闲人", ({ "xian ren", "xian"}));
	set("long", "他是一个游手好闲的家伙。\n");
	set("gender", "男性");
	set("age", 40);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("race", "人类");	
	set("max_qi", 200);
	set("eff_qi", 200);
	set("qi", 200);
	set("max_jing", 200);
	set("eff_jing", 200);
	set("jing", 200);
	set("max_neili", 200);
	set("eff_neili", 200);
	set("neili", 200);
	set("max_jingli", 200);
	set("eff_jingli", 200);
	set("jingli", 200);
	set("combat_exp", 1000);
	set("score", 1000);

	set_skill("force", 20);
	set_skill("dodge", 20);
	set_skill("parry", 20);
	set_skill("cuff", 20);
	set_skill("sword", 20);
        set("inquiry", ([
		"聊天"   :  (: ask_talk :),
        ]));
	setup();
}

void init()
{
        object me = this_player();        

        ::init();

        if( interactive(me) )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
}

void greeting(object me)
{	if (me->query_temp(this_object()->query("id")) == 0 )
	{	command("pat " + me->query("id"));
		command("say 
         这位" + RANK_D->query_respect(me) + 
	          "来这里多久啦？我可在这呆了好几十年了。在这儿
   练功之余可以和别人闲聊(chat)来交流交流感情。还可以散布些谣言
   (rumor)。闲聊和散布谣言时可以用一些已经有了的动作。 你可以试
   试 chat* hi。 用semote可以查出那些已经有了的动作。你还可以用
   cemote来使用自己的动作。想知道都有哪些频道，可以help channel
   如果你话太多惹人厌就会被人投票关闭交谈频道。(vote chblk xxx)
   频道被关了后只有等别人投票打开。(vote unchblk xxx)如果你不喜
   欢某个频道的话也可以用tune关闭，这样你就看不到别人在这个频道
   里的聊天了，再想看到的时候在那个频道里说句话就可以了。如果你
   想找人聊天而不想让其他人听到，你可以告诉(tell)他(她)。有人告
   诉你什麽事，你可以用(reply)来回答他(她)。 你还可以跟某一位与
   你在同一房间的人讲悄悄话(whisper)。 江湖上不少人沉迷在武功之
   中，然而我觉得还是闲聊交友更有趣。你好自为之吧。");
		command("yawn");
		me->set_temp(this_object()->query("id"), 1);
	}

}

int ask_talk()
{
	command("ah");
	command("say 我刚才不是都说过了，好吧，就再告诉你一次。");
	command("say 在这儿
   练功之余可以和别人闲聊(chat)来交流交流感情。还可以散布些谣言
   (rumor)。闲聊和散布谣言时可以用一些已经有了的动作。 你可以试
   试 chat* hi。 用semote可以查出那些已经有了的动作。你还可以用
   cemote来使用自己的动作。想知道都有哪些频道，可以help channel
   如果你话太多惹人厌就会被人投票关闭交谈频道。(vote chblk xxx)
   频道被关了后只有等别人投票打开。(vote unchblk xxx)如果你不喜
   欢某个频道的话也可以用tune关闭，这样你就看不到别人在这个频道
   里的聊天了，再想看到的时候在那个频道里说句话就可以了。如果你
   想找人聊天而不想让其他人听到，你可以告诉(tell)他(她)。有人告
   诉你什麽事，你可以用(reply)来回答他(她)。 你还可以跟某一位与
   你在同一房间的人讲悄悄话(whisper)。 江湖上不少人沉迷在武功之
   中，然而我觉得还是闲聊交友更有趣。你好自为之吧。");
	return 1;
}