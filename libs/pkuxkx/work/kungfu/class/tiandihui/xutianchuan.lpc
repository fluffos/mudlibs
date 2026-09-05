// xutianch.c 徐天川

#include <ansi.h>
#include <title.h>
inherit NPC;
inherit F_MASTER;
string ask_qingming();
int do_answer(string arg);

void create()
{
	set_name("徐天川", ({ "xu tianchuan", "xu", "tianchuan" }));
	set("title", HIR "天地会"HIG"青木堂"HIY"护法"NOR);
	set("nickname", "八臂猿猴");
	set("gender", "男性");
	set("long", "\n他是青木堂数一数二的好手，手上功夫十分了得，尤其擅使一套猴拳。\n");
	set("age", 55);

	set("int", 30);

	set("qi", 1200);
	set("max_qi", 1200);
	set("jing", 500);
	set("max_jing", 500);
	set("max_neili", 1000);
	set("neili", 1000);
	set("max_jingli", 500);
	set("jingli", 500);

	set("jiali", 100);

	set("shen_type", 1);

	set("combat_exp", 750000);
	set("attitude", "peaceful");

	set_skill("force", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);
	set_skill("cuff", 180);
	set_skill("hand", 100);
	set_skill("claw", 100);
	set_skill("literate", 80);

	set_skill("cangming-gong", 100);
	set_skill("lingding-piao", 120);
	set_skill("yunlong-zhua", 100);
	set_skill("fulong-shou", 100);

	set_skill("houquan", 220);

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 60);
	set_temp("apply/armor", 150);
	set("env/wimpy", 30);

	map_skill("force", "cangming-gong");
	map_skill("dodge", "lingding-piao");
	map_skill("hand", "fulong-shou");
	map_skill("claw", "yunlong-zhua");
	map_skill("cuff", "houquan");
	map_skill("parry", "houquan");

	prepare_skill("cuff", "houquan");

	create_family("天地会", 3, "弟子");

	set("chat_chance", 3);
	set("chat_msg", ({
	"徐天川想了想，说：有人想要进出皇宫，我得想个法子才好啊。\n",
        "徐天川突然说：自此传得众兄弟，后来相认团圆时。\n",
        "徐天川突然说：初进洪门结义兄，对天明誓表真心。\n",
	}));
	set("chat_chance_combat", 100);  
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),		
		(: perform_action, "cuff.pofuchenzhou" :),
                      }) );
        set("inquiry", ([
		"陈近南" :  "\n为人不识陈近南，便称英雄也枉然。\n",
		"天地会" :  "\n只要是英雄好汉，都可以入我天地会。\n",
                "去清复明膏" : (: ask_qingming :),
                "清毒复明膏" : (: ask_qingming :),
                "去清复明膏药" : (: ask_qingming :),
                "清毒复明膏药" : (: ask_qingming :),
                "去清复明" : (: ask_qingming :),
                "反清复明" : (: ask_qingming :),
                "暗号" : "敲三下！\n",
                "切口" : "敲三下！\n",
	]) );

	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 5);
}

void init()
{
	add_action("do_answer","answer");

}

string ask_qingming()
{
          object me = this_player();
            if (me->query_temp("tiandihui/ask_qm"))
          return ("你还没回答我呢？\n");
          me->set_temp("tiandihui/ask_qm",1);
          return ("地振高冈，一派溪山千古秀。(answer)\n");
}

int do_answer(string arg)
{
	object me = this_player();
	object ob = this_object();
	if (!me->query_temp("tiandihui/ask_qm")) return 0;
	if (!arg) return notify_fail("你要回答什么？\n");
	if ( arg != "门朝大海，三河合水万年流。"
	    && arg != "门朝大海,三河合水万年流."
	    && arg != "门朝大海三河合水万年流"
	    && arg != "门朝大海，三河合水万年流"
	    && arg != "门朝大海,三河合水万年流")
	return notify_fail("你说的都是些什么乱七八糟的。\n");
	else
	{
		me->set_temp("tiandihui/ask_qm", 0);
		me->set_temp("tiandihui/bai", 1);
		message_vision("$N大笑道：“原来这位" + RANK_D->query_respect(me) + "是自己人。不知道找在下有何贵干啊？”\n", ob);
		return 1;
	}
}

void attempt_apprentice(object ob)
{
       if((string)ob->query("family/master_id") == "chen jinnan")
       {
	   command ("say 这位" + RANK_D->query_respect(ob) + "既已得到总舵主真传，又何必来找我呢?");
           return;
	}

       if (!ob->query_temp("tiandihui/bai"))
          {
          command ("say 这...怎么敢当。");
          return;
          }
	if((string)ob->query("gender")=="无性")

           {

 		command("say 天地会顶天立地，怎会收你这样的废人？！");

		return;

	   }
	if ( ob->query("class")=="bonze" ) {
             if (ob->query("gender")=="女性")
		command ("say 师太还是先还俗了再来吧。");
	     else
		command ("say 大师傅还是先还俗了再来吧。");
	     return;
	}

      if((int)ob->query("betrayer")>=2)
   {
   command("say 你多次判师，我怎么能够收你!\n");
   return;
    }
   if((int)ob->query("shen") < 0)
   {
    command("say 你多行不义，如果收你岂不堕了天地会的名声？\n");
   return;
      }
		else
		{
       this_player()->delete_temp("tiandihui/bai");
       command("say 好吧，"+RANK_D->query_respect(ob)+"！我就收下你了！\n");
       command("recruit "+ob->query("id"));
		}
}


void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        {
          ob->set("title", HIR "天地会"HIG"青木堂"NOR"会众");
//title系统记录玩家title by seagate@pkuxkx
	        ob->set_title(TITLE_RANK, ob->query("title"));
	      }
}
void re_rank(object student)
{
        student->set("title", HIR "天地会"HIG"青木堂"NOR"会众");
//title系统记录玩家title by seagate@pkuxkx
	      student->set_title(TITLE_RANK, student->query("title"));
}

