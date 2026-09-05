// guo.c 周伯通
//modified by bing

#include <ansi.h>
inherit NPC;
int ask_yinggu();
int ask_kid();
int ask_xueyi();
void destroy(object ob);

void create()
{
	set_name("周伯通",({"zhou botong","zhou"}));
	set("nickname",RED"老顽童"NOR);
	set("long","他看起来笑嘻嘻的，活像一个白发顽童."
	"他看起来五十多岁.\n");
	set("str",29);
	set("con",28);
	set("int",30);
	set("dex",29);
	set("gender","男性");
	set("shen_type",1);
	set("attitute","frieldly");
	set("age",56);
	set("max_qi",4500);
	set("qi",4500);
	set("max_neili",2500);
	set("neili",2500);
	set("max_jing",2000);
	set("jing",2000);
	set("jiali",150);
	set("combat_exp",2000000);
	set("score",500000);
	set_skill("force",200);
	set_skill("quanzhen-xinfa",200);
	set_skill("dodge",200);
	set_skill("panyun-gong",200);
	set_skill("parry",200);
	set_skill("cuff",200);
	set_skill("kongming-quan",200);
	set_skill("literate",150);
	map_skill("force","quanzhen-xinfa");
	map_skill("dodge","panyun-gong");
	map_skill("parry","kongming-quan");
	map_skill("cuff","kongming-quan");
	prepare_skill("cuff","kongming-quan");
        set("inquiry", ([
	    "瑛姑" : (:ask_yinggu : ),
	    "孩子" : (:ask_kid : ),
         "左右互搏" : (: ask_xueyi : ),
       ]) );
	setup();
	carry_object("d/city/obj/cloth")->wear();
}

int ask_yinggu()
{
	object me;
	me =  this_player();
	if( me->query_temp("marks/find周"))
	{
		command("fear " + this_player()->query("id"));
		command("say 女人的面是见不得的，她身子更加碰不得，你教她点穴功夫，让她抚摸你周身穴道，那便上了大当……要娶她为妻，更是万万不可……");
		me->set_temp("marks/ask周",1);
		return 1;
	}
	return notify_fail("周伯通两只手正打得热火朝天，显然不会听你说话。\n");
}
int ask_xueyi()
{
  mapping myfam;
  if(!(myfam = this_player()->query("family"))
     ||myfam["family_name"]!="全真派")
   {
    command("say 你又不是我师兄的徒弟，我为什么要教你?");
    return 1;
    }
   else {
   command("say 左右互搏可是我好不容易研究出来的，可不能随便教给别人!");
   command("say 你要是能给我一件我想要的东西，我还是可以教你的.");                                                
   command("hehe");
   this_player()->set_temp("marks/学艺",1);
   return 1;
    }
}

int accept_object(object ob,object obj)
{
    ob=this_player();
    if(obj->query("id")=="feng wang mi")
    {
        this_object()->start_busy(5);
      call_out("destroy",1,obj);
    if((string)ob->query("family/family_name")=="全真派")
    {   command("say 哇，这就是我想要的蜂王蜜，你从哪里弄来的？");
        command("say 好，我就把我的双手互搏教给你!");
        if(ob->query("int")<25)
       {
        say("你听了老顽童的讲解，学会了左右互搏!\n");
        ob->set("zuoyou-hubo",1);
        return 1;
       }
       else 
      {
      say("老顽童讲了半天，你却不知道他在讲些什么.\n");
      command("chat "+ob->query("name")+",你怎么这么笨啊！");
      return 1;
      }
    }
   else 
  {
    command("say 我可没法报答你啊!");
    return 1;
  }
}
    command("smile");
    command("say 那我就不客气了");
    return 1;
  }



int ask_kid()
{
	object me;
	me = this_player();
	if ( me->query_temp("marks/ask周"))
	{
		command("say 什么？？？我的孩子？我有孩子？");
		command("say 好吧，你先回去，我就去见瑛姑。");
		me->set_temp("marks/get周",1);
		return 1;
	}
	return notify_fail("周伯通傻乎乎地朝你笑着：我最喜欢和小孩玩了，过来陪我玩吧！\n");
}
	
		
void destroy(object ob)
{
    destruct(ob);
}
