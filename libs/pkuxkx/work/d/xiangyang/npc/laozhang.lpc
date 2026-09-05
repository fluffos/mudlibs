#include <ansi.h>
inherit NPC;
void create()
{
        set_name("老丈", ({ "lao zhang", "zhang" }));
        set("title", HIW"贫苦人"NOR);
        set("shen_type", 1);
        set("gender", "男性");
        set("age", 45);
        set("long",
                "老丈六十多岁了,几个儿子都在战场上死了留下他孤苦零丁一个人.\n");
        set_skill("strike", 40);
        set_skill("xianglong-zhang", 40);
        set_skill("dodge", 20);
         map_skill("strike", "xianglong-zhang");
         map_skill("parry", "xianglong-zhang");
        set_temp("apply/damage", 15);
        set("combat_exp", 21000);
        set("attitude", "friendly");
         set("chat_chance", 6);
        set("chat_msg", ({
      HIR"老丈叹了一口气.\n"NOR
      HIR"我那可怜的儿啊!\n"NOR
        }) );     
   setup();
}
void init()
{
	object ob=this_player();
        object book;
	::init();
	if(this_player()->query_temp("兰1"))  
       {this_player()->delete_temp("兰1");
        command("haha " + this_player()->query("id"));
        command("say 多谢这位" + RANK_D->query_respect(ob) + "成全小女的婚事,\n老丈我无以为谢，当年我年轻时曾追随丐帮黎生黎老前辈，\n蒙他传我掌法，老丈我天生愚笨，未得其中精要，特将\n黎老前辈教诲记录成册，今日就送与" + RANK_D->query_respect(ob) + ",也使它有个用武之地。\n");
        book = new(__DIR__"obj/zhbk");
	book->move(this_player());     
        message_vision("老丈给了$N一本发黄的书。\n", ob);
       }
}