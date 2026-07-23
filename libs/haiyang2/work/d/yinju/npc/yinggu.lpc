inherit NPC;
#include <ansi.h>
string ask_me();
string ask_book();
string ask_yideng();
void create()
{
        set_name("英姑", ({ "ying gu", "gu" }));
        set("nickname", HIR"神算子" NOR );
        set("gender", "女性");
        set("age", 41);
        set("long", 
        "她容色秀丽，不过四十左右年华，想是思虑过度，是以鬓边早见华发。\n");
        set("combat_exp", 1000000);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 25);
        set("int", 25);
        set("con", 35);
        set("dex", 35);
        set("book_count", 1);
        set("max_qi", 11500);
        set("max_jing", 11500);
        set("neili", 11000);
        set("max_neili", 11000);
        set("jiali", 100);
        set("combat_exp", 1500000);
        set_skill("unarmed", 150);
        set_skill("force", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("kurong-changong", 100);     
        set_skill("anying-fuxiang", 300);   
        set_skill("qimen-wuxing",150);     
        set_skill("jinyu-quan", 155);
        set_skill("count",100);            
        set_skill("literate",250);
	set("book_count", 1);
	set("yideng_count", 1);
        map_skill("parry", "duanjia-sword");
        map_skill("cuff", "jinyu-quan");        	
        map_skill("force"  , "kurong-changong");  
        map_skill("dodge"  , "anying-fuxiang");

        prepare_skill("cuff", "jinyu-quan");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 200);
 
             
        set("inquiry", ([
		"一灯" : (:ask_me:),
              "南帝" : (:ask_me:),
                   "周伯通"     : "他、他、、他在哪里！",
                "段智兴"     : "这个老和尚，枉称慈悲！\n",
                "一灯大师"   : (: ask_yideng :),
                "九章算术"   : (: ask_book :),
	  ]) );

        setup();
        carry_object("/clone/cloth/cloth")->wear();
}
void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) 
       {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
 add_action("do_answer", "answer");
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
        command("say 今有无不知其数，三三数之剩二，五五数之剩三，七七数之剩二，问物几何？");
	return;
}
int do_answer(string arg)
{
      object ob;
      object me=this_player();
          if( arg=="23" )
        { 
          if (query("book_count") < 1)
          {
	   command("say 你来晚了我已把秘籍送给别人来不在此处。");
            return 1;
          }
	   add("book_count", -1);
          ob=new("/d/yinju/npc/obj/book");
                 ob->move(me);
          command("say 没想到，你竟然答对了。既然如此你我也算有缘送你一本步法书。\n");

         }
         else 
             command("say 错了，你答错了。\n");
        return 1;
}
string ask_me()
{
	 object me,ob;
	 me=this_player();
        ob=new("/d/yinju/npc/obj/bunan");
        ob->move(me);
     return "英姑皱眉对$N说：二十年了，你带我把布囊给段智兴吧。\n";     
       
}
string ask_book()
{
	mapping fam; 
	object ob;

	if ( (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "大理段家") ||
		(query("book_count") < 1) ) 
		return RANK_D->query_respect(this_player()) + 
		"说什么？我实在不明白。";

	if (this_player()->query_skill("literate",1) < 100)
		return RANK_D->query_respect(this_player()) + 
		"想要这书？你还读不懂它呢。";
	add("book_count", -1);
	ob = new("/d/sdxl/heizhao/npc/lbook4");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"拿到九章算术啦。\n");
	return "好吧，这本「九章算术」你拿回去好好钻研。\n";
}

string ask_yideng()
{
	mapping fam; 
	object ob;
	
	if (query("yideng_count") < 1)
		return RANK_D->query_respect(this_player()) + 
		"想说什么？找一灯大师，那可别找我。";
	add("yideng_count", -1);
	ob = new("/d/sdxl/heizhao/npc/obj/whiteobj");
	ob->move(this_player());
	ob = new("/d/sdxl/heizhao/npc/obj/yellowobj");
	ob->move(this_player());
	ob = new("/d/sdxl/heizhao/npc/obj/redobj");
	ob->move(this_player());
	return "你想见他？好吧，这三个囊儿给你，有缘你就去找他吧。\n";
}

      
