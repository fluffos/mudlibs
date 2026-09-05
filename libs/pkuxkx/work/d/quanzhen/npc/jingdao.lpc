//made by hacky;
//97.12.1
#include <ansi.h>

inherit NPC;
string ask_me();

string *books=({
       "jing1",
//        "jing2",
       "jing",
//        "jing8",
       "jing13",
       "jing16",
       "jing18",
});

void create()
{
 set_name("藏经阁道长",({"daozhang","zhang"}));
 set("title",HIB"全真派"NOR+GRN"道长"NOR);
 set("age",30);
 set("long",@LONG
他是藏经阁主管经书的道长.
LONG
    );
 set("attitude","peaceful");
 set("gender","男性");
 
 set("str",24);
 set("int",25);
 set("con",20);

 set("shen",2000);
 set("max_neili",700);
 set("neili",700);
 set("max_qi",600);
 set("eff_qi",600);
 set("qi",600);
 set("score",10000);
 set("combat_exp",20000);

 set_skill("parry",50);
 set_skill("dodge",50);
 set_skill("force",50);
 set_skill("sword",50);
 set_skill("quanzhen-jian",50);
 set_skill("daoxue-xinfa",50);
 set_skill("xiantian-gong",50);
 
 map_skill("sword","quanzhen-jian");
 map_skill("force","tianshi-zhengqi");
 map_skill("parry","quanzhen-jian");
 
 set("inquiry",([
     "经书" : (: ask_me : ),
  ]));

 set("book_count",3);
 setup();
}

string ask_me()
{
  object ob;
  object me;
  me=this_player();
  if(me->query("family/family_name")=="武当派")
  return "武当虽与我全真都属道家,但是经书却有些差别,我看"+RANK_D->query_respect(me)
   +"还是去研读武当的道德经吧.\n";

  if(me->query("family/family_name")!="全真派")
  return RANK_D->query_respect(me)+"与我全真素无来往,此话从何而来?\n";

  if(me->query_temp("have_ask"))
  return RANK_D->query_respect(me)+"不要贪得无厌!\n";

  if(query("book_count")<1)
  return "你来晚了,本派的经书已经发完了\n";
  
  add("book_count",-1);
  ob=new(__DIR__"obj/"+books[random(sizeof(books))]);
  ob->move(me);
  return "好吧,这本经书就给你拿去吧.\n";
 }

