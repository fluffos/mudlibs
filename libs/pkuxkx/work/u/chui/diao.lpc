// Eric 96.9.25

#include <ansi.h>


inherit NPC;

int ask_me();
int getin(object me, object ob);

void create()
{
        set_name("丑雕", ({ "chou diao", "chou", "diao" }));
        set("long", "
此雕身形甚巨，比人还高，形象丑陋之极，全身羽毛疏疏落
落，双腿奇粗，有时伸出羽翼，却又奇短，不知如何飞翔。
只是高视阔步，自有一番威武气概。\n");
        set("gender", "半人半兽");
        set("rank_info/respect", "雕兄");
        set("age", 100);
        set("str", 80);
        set("dex", 85);
	set("shen_type", 1);

        set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set_temp("apply/attack", 100);
        set_temp("apply/armor", 100);

        set_skill("unarmed", 80);
        set_skill("force", 80);
        set_skill("dodge", 80);
        set_skill("whip",80);
        set("jiali",50);

        set("combat_exp", 80000);

        set("max_qi", 5000);
        set("max_jing", 5000);
        set("neili", 500);
        set("max_neili", 500);

        set("inquiry", ([
	    "独孤求败" : (: ask_me :),
       ]) );

        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
		(: this_object(), "random_move" :),
		"丑雕忽地仰起头来，高呼三声。\n",
		"丑雕转过头来，向人柔声低呼。\n" }) );

}

int ask_me()
{

	object me,ob;

 	me = this_object();
	ob = this_player();

	if ( file_name(environment(me)) == "/d/quanzhou/wuminggudi" ) {
		   message("vision",
   BLU "丑雕长鸣一声，看样子很高兴。\n"
   BLU "当下转过身子，往北边的草丛走去，\n"
   BLU "长草分处，俨然是一条只容一人过的小路。\n"
   BLU "$N身不由己地跟着走了过去。\n"
   NOR, environment(), me );

		me->move("/d/quanzhou/caocong");
		ob->move("/d/quanzhou/caocong");

	} else {
		   message("vision",
   HIY "丑雕歪着脖子看了你几眼，显然对你失望极了。\n"
   NOR, environment(), me );
	}

   return 1;
}
  
