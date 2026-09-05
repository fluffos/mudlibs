inherit NPC;
string ask_me();
string ask_quest();   //为了帮助修改quest系统时间错误临时加的

void create()
{
        set_name("寂寞剑", ({ "lonely sword", "man" }));
        set("gender", "男性");
        set("age", 21);
        set("long", "一个衰小伙，无聊的话可以向他打听有关聊天的事情。\n");
        set("combat_exp", 1000);
        set("shen_type", -1);
        set("attitude", "peaceful");
        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
        set("inquiry",
                ([
                "聊天" : (: ask_me :),
                "quest" : (: ask_quest :),
                "mm" : "你能帮我找一个mm吗？我会答谢你的\n",
                "gg" : "哼，哪个gg有我帅？我是最帅的\n",
                "刷刷" : "你怎么知道我喜欢刷刷，什么时候一起去吧\n",
                ]));
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/u/gxdj/obj/xie")->wear();
}

string ask_me()
{
        mapping fam;
        object ob;
     ob=this_player();
  if (this_player()->query("gender")!="女性")
             return "对不起，我不和非mm的人聊天。";
                            command("xixi " + ob->query("id"));
           command("whisper " + ob->query("id")+" 呵呵，你是霉女么？我的qq号是5009632，记得多聊天哦！:)");
                       command("qing " + ob->query("id"));
               return "偶很想和你聊天哦!";
}

string ask_quest()
{
	object me=this_player();
	if (!me->query("quest/xiugai"))
	{
	me->add("quest/time",-500000000);
	me->set("quest/xiugai",1);
	}
	return "你的问题已经解决了，回去继续做吧！";
}
