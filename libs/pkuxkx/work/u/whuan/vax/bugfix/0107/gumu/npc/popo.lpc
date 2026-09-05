// popo.c
#include "/quest/quest0.h"
inherit NPC;

void init();
int do_ling(string);
string ask_me();
void create()
{
        set_name("孙婆婆", ({
                "sun popo",
                "sun",
                "popo",
        }));
	set("title","古墓派总管");
        set("long",
                "她是一位老婆婆，脸上布满皱纹。\n"
        );
        set("gender", "女性");
        set("attitude", "friendly");
        
        set("age", 75);
        set("shen_type", 1);
        set("str", 21);
        set("int", 25);      
        set("con", 20);
        set("dex", 25);
        set("max_qi", 1000);
        set("max_jing", 500);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 70);
        set("combat_exp", 150000);
        set("score", 10000);
        set_skill("force", 100);
        set_skill("changhen-xinfa", 100);
        set_skill("dodge", 100);
        set_skill("xianyun", 100);
        set_skill("meinu-quan", 100);
        set_skill("cuff", 100);
        set_skill("parry", 100);
 //       set_skill("mahayana", 100);
        set_skill("literate", 100);
        map_skill("force", "changhen-xinfa");
        map_skill("dodge", "xianyun");
        map_skill("cuff", "meinu-quan");
        map_skill("parry", "meinu-quan");
        prepare_skill("cuff", "meinu-quan");
	 set("inquiry", ([
                "出墓" : (: ask_me :),
           
        ]));
        
 set("jian_count",10);
 set("bian_count",10);
  //      create_family("古墓派", , "弟子");
        setup();
//        carry_object(__DIR__"obj/changjian")->wield();
//        carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{
   add_action("do_ling","ling");
}                               


int do_ling(string arg)
{
 object ob = this_object();
 object me = this_player();
 object obj;
 if(me->is_busy()) return notify_fail("你正忙着呢！\n");
if (me->query("family/family_name") != "古墓派")
return notify_fail("孙婆婆说道：“只有本门弟子才能领武器”。\n");
 if(!arg || (arg != "zhujian" && arg != "changbian"))
    return notify_fail("你要领什么？\n"); 
 
if( arg == "zhujian" && this_object()->query("jian_count") < 1)
return notify_fail("孙婆婆说道：“竹剑已经被你的师兄妹们领完了。”\n");
 if( arg == "zhujian" && this_object()->query("jian_count") > 0)
    { 
      if(objectp(present("zhujian", this_player())) ) 
         return notify_fail("你已有了，还领什么？\n");
      command("say 好吧，就给你一把竹剑。\n");
      message_vision("$N交给$n一把竹剑。\n", ob, me);
      obj=new(__DIR__"obj/zhujian");
 this_object()->add("jian_count",-1);
    }  
if( arg == "changbian" && this_object()->query("bian_count") < 1)
return notify_fail("孙婆婆说道：“长鞭已经被你的师兄妹们领完了。”\n");
 if( arg == "changbian" && this_object()->query("bian_count") > 0)
    { 
      if(objectp(present("changbian", this_player())) ) 
         return notify_fail("你已有了，还领什么？\n");
      command("say 好吧，就给你一把长鞭。\n");
      message_vision("$N交给$n一把长鞭。\n", ob, me);
      obj=new(__DIR__"obj/changbian");
 this_object()->add("bian_count",-1);
    }                          
  obj->move(me);
    me->start_busy(2);
  return 1;
}
string ask_me()
{	 mapping fam;
        object me=this_player();
        object ob;
	/*if (me->query("age")<15)
	{
	//message_vision("杨女说道“好吧，我就带你去古墓吧。”\n",me);
	//	 me->move("/d/gumu/dating");
	return"江湖险恶，你好了，我要出去了。";
	}*/
	 if (!(fam = this_player()->query("family")) || fam["family_name"] != "古墓派")
      		{  
		if(me->query("max_neili")<1000){
		message_vision("孙婆婆说道“好吧，我就带你出古墓吧。”\n",me);     
	me->move("/d/gumu/duanlongshi");  
	 return "想不到外人对我古墓派还也有兴趣。";}
		else
		return"你又不是不能出墓，何必麻烦老妪呢。";
		}
 	else
	{
		if (me->query("age")<15)
		{
	
		return"江湖险恶，你年龄太小，还是不要出去为好。";
		}
	message_vision("孙婆婆说道“好吧，我就带你出古墓吧。”\n",me);     
	me->move("/d/gumu/duanlongshi");  
	return"好了，我要回去了。";
	}
	//if (me->query("age")>15)
	//return "你也不小了，还要进古墓。";
	//else
	//return RANK_D->query_respect(this_player()) +
        //        "与本派素无来往，不知此话从何谈起？";
//
}
