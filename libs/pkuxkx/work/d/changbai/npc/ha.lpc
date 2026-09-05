// /d/changbai/npc/ha.c
#include <ansi.h>
inherit NPC;
int ask_shuaijiao();
int do_answer( string arg );

void create()
{
        set_name("哈合台", ({ "ha hetai", "ha" }));
        set("nickname", HIC"关东四魔"NOR);
        set("long",
"他就是关东六魔中的第四魔。\n"
"本是蒙古牧人，流落关东，也做了盗贼，结合了其余兄弟，成为关东六魔。\n");
        set("gender", "男性");
        set("age", 35);
        set("attitude", "heroism");
        set("shen_type", -1);

        set("str", 26);
        set("int", 30);
        set("con", 26);
        set("dex", 28);

        set("max_qi", 900);
        set("max_jing", 600);
        set("neili", 900);
        set("max_neili", 900);
        set("jiali", 30);
        set("combat_exp", 300000);
        set("score", 20000);

        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("hand", 100);
        set_skill("parry", 100);
        set_skill("blade", 120);
        set_skill("throwing", 100);
        /*
        set_skill("ding-force", 100);
        set_skill("wuxingbu", 100);
        set_skill("liangyi-dao", 120);
        set_skill("lanhua-fuxue", 100);

        map_skill("force", "ding-force");
        map_skill("dodge", "wuxingbu");
        map_skill("parry", "liangyi-dao");
        map_skill("blade", "liangyi-dao");
        map_skill("hand", "lanhua-fuxue");

        prepare_skill("hand", "lanhua-fuxue");
*/

          set("inquiry", ([
      "关东六魔" : "恩，那是江湖上抬举我们弟兄，给送的绰号。\n",
      "老四" : "不错，我排行老四！\n",
      "古兰经" : (: ask_shuaijiao :),
      "霍青桐" : "我不认识，去问问我三哥。\n",
     ]) );  

        setup();

        carry_object("/d/changbai/obj/tiepai")->wield();
        carry_object("/d/changbai/obj/piqiu")->wear();

}

void init()
{
        add_action("do_answer", "answer");
}

int ask_shuaijiao()
{
       object me;
       me = this_player();
       
       if ( me->query_temp("askha") == 1 )
       	   {
       	   	  say("哈合台说道：要摔就痛快点，别跟老娘们似的！\n");
       	   	  return 1;
       	   }
       	   
       if ( me->query("gender") != "男性" )
       	   {
       	   	  say("哈合台说道：非爷们禁止对话！\n");
       	   	  return 1;
       	   }
       	     
       me->set_temp("askha",1);
       say("哈合台说道：我倒知道点这本经书的消息，不过你要和我比一场摔交，好吗？\n");
       return 1;
}

int do_answer( string arg )
{
	    object me,ob;
	    ob = this_object();
	    me = this_player();
	    
	    if ( !me->query_temp("askha") )
	    	  return 0;
	    
	    if ( arg == "不好" )
	    	 {
	    	   say("哈合台说道：胆小鬼，快给我滚！\n");
	    	   return 1;
	    	 }
	    	 
	    if ( arg == "好" )
	    	 {
	         command("haha");
                 say("哈合台说道：这才是条好汉子！！\n");            
	         remove_call_out("shuai");
           call_out("shuai", 2, me, ob);
           return 1;
         }
       else
       	   return 0;         
}

void shuai(object me)
{
            if(me->query_skill("unarmed",1) >= 500)
	    	{
	         message_vision(HIC"$N一个手臂粉碎技把哈合台甩了出去！\n"NOR,me);
	         message_vision(HIR"$N马上箭步又冲上去一个雪崩式过肩摔把哈合台摔在地上！\n"NOR,me);
	         message_vision(HIM"$N一见得手，使出最后绝技“阿拉伯原爆颜面破碎技”，打得哈合台头晕眼花！\n"NOR,me);
	         message_vision(HIW"哈合台向$N一鞠躬说道：哥们摔交技术真是不错，在下甘拜下风！\n"NOR,me);
                 command("whisper "+me->query("id")+" 古兰经那事你还得去问问我大哥，呵呵。\n");

	         me->delete_temp("askha");
                 me->set_temp("sj1",1);
	         return;
	      }
	    
	    else
	    	
	    	{
	         message_vision(HIC"哈合台一个阿拉巴马背摔把$N狠狠得摔在地上，$N疼得直哼哼！\n"NOR,me);
	         message_vision(HIR"哈合台哈哈大笑对着$N说道：就凭你着拳脚，别指望找书了。\n"NOR,me);
	         me->delete_temp("askha");
                 me->unconcious();
	         return;
	      }
}	      
	      
	         
	           	    
