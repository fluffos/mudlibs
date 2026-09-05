// linghu.c 令狐冲
#include <ansi.h>

inherit NPC;
int ask_lingshan();
int ask_feng();
string ask_music();
int ask_dodge();
void create()
{
        set_name("令狐冲",({"linghu chong","linghu","chong"}));
        set("title",GRN "华山派" NOR + YEL +"剑侠" NOR);
        set("long",
              "华山派掌门人岳不群的大弟子，\n"
              "他今年二十多岁。\n");
        set("gender", "男性");
        set("age", 28);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 26);
        set("int", 30);
        set("con", 26);
        set("dex", 28);
        set("max_qi", 800);
        set("max_jing", 500);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 50);
        set("combat_exp", 50000);
        set("score", 10000);
        set("is_LINGHU",1);
		set("huashan_newskills/dodge1",1);
		set_skill("force",80);
        set_skill("huashan-neigong", 80);
        set_skill("dodge", 80);
        set_skill("huashan-shenfa", 80);
        set_skill("huashan-jianfa", 60);
        set_skill("cuff", 70);
        set_skill("poyu-quan", 70);
        set_skill("parry", 80);
        set_skill("sword", 80);
        set_skill("dugu-jiujian",60);
//      set_skill("taoism", 150);
        set_skill("literate", 80);
        set_skill("music::music-theory", 300);
        set_skill("music::qin", 300);
        set_skill("music::qin::hujia-pai", 300);
        set_skill("music::qin::guangling-san", 300);
        set_skill("music::qin::xiaoao-jianghu", 300);
        map_skill("force", "huashan-neigong");
        map_skill("dodge", "huashan-shenfa");
        map_skill("cuff", "poyu-quan");
//      map_skill("unarmed", "taiji-quan");
        map_skill("parry", "huashan-jianfa");
        map_skill("sword", "dugu-jiujian");

        prepare_skill("cuff", "poyu-quan");

        create_family("华山派",19,"弟子");
		set("jingli",1000);
		set("max_jingli",1000);
        set("inquiry", ([
                "岳灵珊" : (: ask_lingshan :),
                "风太师叔" : (: ask_feng :),
				"平沙落雁" : (: ask_dodge :),
                "笑傲江湖" :"笑傲江湖在盈盈那里啊，我好久没有他的消息了。",
                "笑傲江湖曲" : (: ask_music :),  
        ]) );
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/huashan/obj/bluerobe")->wear();
}
int TeachMe(object me)
{
	if (!me)
	return 0;
	if (me->query("huashan_newskills/jianzong"))
	{
		tell_object(me,HIG+"虽然被令狐冲踢得摔了一跤，你却灵光一现，掌握了『屁股向后平沙落雁』。\n"+NOR);
		tell_object(me,"恭喜你，可以在江湖上踢人了。\n");
		me->set("huashan_newskills/dodge2",1);
		return 1;
	}
	else
	{
		message_vision("$N向你讲述踢人屁股的要诀。\n",this_object(),me);
		tell_object(me,HIG+"恭喜你，你掌握了『屁股向后平沙落雁』。\n"+NOR);
		me->set("huashan_newskills/dodge1",1);
		return 1;
	}
}
int ask_dodge()
{
	object me=this_player();
	if (me->query("huashan_newskills/jianzong")&&me->query("huashan_newskills/dodge2"))
		{
			command("say 我不是教过你了吗？");
			return 1;
		}
	if (!me->query("huashan_newskills/jianzong")&&me->query("huashan_newskills/dodge1"))
		{
			command("say 我不是教过你了吗？");
			return 1;
		}
	if (me->query("family/family_name")!="华山派")
	{
		command("sing5");
		return 1;
	}
	if (this_object()->is_busy())
	{
		command("sigh");
		return 1;
	}
	if (time()-me->query("huashan_newskills/TryPingsha")<600)
	{
		command("say 你怎么又来了？被踢得还不过瘾？");
		return 1;
	}
	if (me->query("huashan_newskills/jianzong"))
	{
		command("say 好啊，我今天倒要你试试屁股向后平沙落雁。");
		command("perform dodge.pingsha "+me->query("id"));
		me->set("huashan_newskills/TryPingsha",time());
		if (!random(10))
		call_out("TeachMe",2,me);
		return 1;
	}
	if (me->query_skill("huashan-shenfa",1)<100)
	{
		command("tell "+me->query("id")+" 我可不会什么平沙落雁，你说的是屁股向后平沙落雁吧？");
		command("tell "+me->query("id")+" 这是我戏耍青城派弟子用的，不过你现在轻功太低，我还没法教给你。");
		return 1;
	}
	return TeachMe(me);
}
void init()
{
  object ob;
  ::init();
  ob = this_player();
  if (interactive(ob) && !is_fighting()) {
    remove_call_out("greet");
    call_out("greet", 1, ob);
  }
}

void greet(object me)
{
  if (!me) return;
  if (me->query_temp("riyue/leading") && (present("ren yingying", environment(me))))
  {
    command("follow none");
    message_vision("令狐冲走上前去，轻轻搂住任盈盈，说道：「盈盈，我回来了！」\n",me);
    me->set_temp("riyue/lead_ok",1);
    return;
  }
  return;
}


int ask_lingshan()
{ 
  mapping myfam;
  
  if (!(myfam = this_player()->query("family"))
      || myfam["family_name"] != "华山派")
  {
    say("令狐冲说：你问我小师妹干什么？\n");
    return 1;
  }
  else
  {
    say("令狐冲说：她是我的小师妹呀。你怎么会不知道呢？\n");
    set("chat_chance", 10);
    set("chat_msg", ({
        "令狐冲低头自言自语说：小师妹已经几天没来了。\n",
        "令狐冲低头自言自语说：小师妹知道我学了风太师叔的剑法应该替我高兴吧。\n",
        "令狐冲低头自言自语说：小师妹现在又和林平之在一起吧。咳！\n",
    }) );
    this_player()->set_temp("marks/珊1", 1);
    return 1;
  }
}

int ask_feng()
{
  if ((int)this_player()->query_temp("marks/珊1")) {
    say("令狐冲说：风太师叔在山洞中，可他平时不愿见华山弟子。\n");
    this_player()->set_temp("marks/风1", 1);
    return 1;
  }
  else {
    say("令狐冲说：风太师叔是前辈高人，已隐居多年，没人知道他在哪里。\n");
    return 1;
  }
}

int accept_object(object me,object ob)
{
  object obj;
  if ((string)ob->query("id") == "letter to linghu chong")
  if (me->query_temp("riyue/get_letter") == 1)
  {
      message_vision("令狐冲接过信，打开看了一遍，激动得流出泪来。\n", me);
      command("say 多谢这位" + RANK_D->query_respect(me) + "。盈盈她现在在哪里？你带我去好吗？");
      command("follow " + me->query("id"));
      me->set_temp("riyue/leading",1);
      remove_call_out("destroying");
      call_out("destroying", 1, me, ob);
      return 1;
  }
  else  {
      message_vision("令狐冲接过信，狐疑地看了你一眼，说道：「这信是盈盈亲手交给你的吗？」\n",me);
      remove_call_out("destroying");
      call_out("destroying", 1, me, ob);
      return 1;
  }
  return 0;
}

void destroying(object me, object obj)
{
  destruct(obj);
  return;
}

string ask_music()
{
  object me=this_player(), ob;
  
  if ( !SKILL_D("music")->valid_learn_subskill(me, ({"music","qin","xiaoao-jianghu"})) )
    return "看来你没有能力学习笑傲江湖曲。";
  
  if ( me->query("family/family_name") != "华山派" )
    return "我只教本派弟子学习笑傲江湖曲。";
  
  if ( me->query_sub_skill("music::qin::xiaoao-jianghu",1)>=300 )
    return "我已经没有什么东西可以教你了。";
  
  if ( !objectp(ob=present("xiao ao jiang hu", me) ) )
    return "你没有携带笑傲江湖曲谱，我怎么教你？";
  
  if ( me->is_busy()||me->is_fighting() )
    return "你正忙着呢，无法教你曲谱。";  
  
  if ( me->query("potential")-me->query("learned_points")<500 )
    return "你的潜能不够，无法学习笑傲江湖曲。";
  
  me->set_skill("music::qin::xiaoao-jianghu", me->query_sub_skill("music::qin::xiaoao-jianghu",1)+1 );
  me->add("music/xiaoao-jianghu",1);
  
  if ( me->query("music/xiaoao-jianghu")>=100 )
  {
    destruct(ob);
    me->delete("music/xiaoao-jianghu");
    tell_object(me, "你翻了太多遍笑傲江湖曲谱，以至于把曲谱翻烂了。\n");
  }
  
  me->add("learned_points",500);
  me->start_busy(10);
  return HIC"看了你的悟性不错，对笑傲江湖曲的了解又深入了一步。"NOR;
}