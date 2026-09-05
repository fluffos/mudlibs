// hufei.c
#include <ansi.h>;
inherit NPC;

void create()
{
	set_name("狄云", ({"di yun", "di", "yun"}));
	set("gender", "男性");
	set("nickname", HIR"连城剑"NOR);
	set("age", 25);
	set("long",
		"他就是狄云发的大弟子，因其武功高强神出鬼没。\n"
		"在江湖上人送外号「连城剑」。\n"
		"他看上去就像一个乡下的农民。\n");
	set("attitude", "peaceful");
	set("str", 45);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 25);
	set("chat_chance", 20);
	set("chat_msg", ({
		"狄云叹了口气道：“不知什么时候还能再见到师妹。\n",
		"狄云恨恨道：“万震山是我杀师仇人，我必报此仇！”\n",
		"狄云切齿恨道：“万老贼暗下毒手，我必手刃此人！”\n",
		(: random_move :),
	}));
  set("chat_chance_combat", 90);
  set("chat_msg_combat", ({
                (: perform_action, "sword.ci" :),
                (: perform_action, "sword.erguang" :),
                (: perform_action, "sword.qu" :),
		            (: random_move :),
        }) );


	set("qi", 3000);
	set("max_qi", 3000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);
	set("combat_exp", 890000);
	set("score", 20000);

	set_skill("force", 110);             // 基本内功
	set_skill("liancheng-jian", 250);       // 连城剑法
	set_skill("sword", 220);             // 基本刀法
	set_skill("hunyuan-yiqi", 220);      // 混元一气功
	set_skill("dodge", 120);             // 基本躲闪
	set_skill("shaolin-shenfa", 220);    // 胡家身法
	set_skill("parry", 220);             // 基本招架

	map_skill("force", "hunyuan-yiqi");
	map_skill("sword", "liancheng-jian");
	map_skill("parry", "liancheng-jian");
	map_skill("dodge", "shaolin-shenfa");
  set_temp("apply/attack", 120);
  set_temp("apply/defense", 120);
  set_temp("apply/armor", 120);
  set_temp("apply/damage", 520);

	set("inquiry",([
		"万震山":     "万震山这个狗贼我非杀了他不可。\n",
		"连城诀":     "你必须找到《血刀秘籍》跟我交换。\n",	
	]));
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/city/obj/cloth")->wear();
}

 int accept_object(object who, object ob)
{
        object obj;
        if( !who || environment(who) != environment() ) {return 0;}
        if ( !objectp(ob) ) {return 0; }
        if ( !present(ob, who) ) return notify_fail("你没有这件东西。");

        if ((string)ob->query("id") == "xuedao miji" ) 
        {
        	if (query("lcj") >= 0) 
        	{
        		command("ah");
        		message_vision("狄云说道：$N帮我找回血刀秘籍，我就送你《连城诀》吧。\n",who);
            obj=new("/d/reborn/jinyong/obj/lcj");
            obj->move(who);
            add("lcj",-1);
          }  
          else
          {
          	command("ah");
        		message_vision("狄云说道：多谢$N帮我找回血刀秘籍，但是我的《连城诀》刚刚送给别人了。\n",who);
          }
          remove_call_out("destroying");
          call_out("destroying", 1, this_object(), ob);
          command("say 多谢了！");
          return 1;
          }
         return 0;
}
void destroying(object me, object obj)
{
        destruct(obj);
        return;
}                		
