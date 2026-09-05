// huoqingtong.c 霍青桐

#include <ansi.h>
inherit NPC;
int ask_me();
void create()
{
	set_name("霍青桐", ({ "huo qingtong", "huo","qingtong" }));
	set("long", 
"这女郎秀美中透着一股英气，光采照人，当真是丽若春梅绽雪，神如
秋蕙披霜，两颊融融，霞映澄塘，双目晶晶，月射寒江。腰插匕首，
长辨垂肩，一身鹅黄衫子，头戴金丝绣的小帽，帽边插了一根长长的
翠绿羽毛，旖旎如画。\n");
	set("nickname", HIG"翠羽"HIY"黄衫"NOR);
	set("gender", "女性");
	set("class", "swordsman");
	set("age", 18);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 30);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 2000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 600000);
  set("book_count",1);
	set_skill("literate", 120);
	set_skill("force", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);
	set_skill("sword", 120);
	set_skill("hand", 120);
	set_skill("claw", 120);
	set_skill("yunlong-xinfa", 120);
	set_skill("yunlong-shengong", 120);
	set_skill("yunlong-jian", 120);
	set_skill("yunlong-shenfa", 120);
	set_skill("yunlong-shou", 120);
	set_skill("yunlong-zhua", 120);

	map_skill("dodge", "yunlong-shenfa");
	map_skill("force", "yunlong-shengong");
	map_skill("hand", "yunlong-shou");
	map_skill("parry", "yunlong-shou");
	map_skill("claw", "yunlong-zhua");
	map_skill("sword", "yunlong-jian");

	prepare_skill("hand","yunlong-shou");
	prepare_skill("claw","yunlong-zhua");
	set("env/wimpy", 60);
        set("chat_chance",30);
        set("chat_msg", ({                 
                (: random_move :), 
        }) ); 
  set("inquiry", ([
      "书剑恩仇录" : (: ask_me :),
      "书剑" : (: ask_me :),
      "香香公主" : "她是我的小妹子。\n",
      "陈家洛" : "...\n",
     ]) );  
 	setup();
	carry_object("/d/reborn/jinyong/obj/sj_cuiyu")->wear();
	carry_object("/d/reborn/jinyong/obj/sj_huangshan")->wear();
	carry_object("/d/reborn/jinyong/obj/sj_shortsword")->wield();
	call_out("do_leave", 400);
        call_out("greeting", 1);
}

void init()
{	
  if (random(20) && !this_object()->query("moving"))
  {
	this_object()->set("moving",1);
  	::random_move();
  	::random_move();
  	::random_move();
  	::random_move();
  	::random_move();
  	::random_move();
  	::random_move();
  	this_object()->delete("moving");
  	::random_move();
	}
}

int ask_me()
{
	object book;
	object me=this_player();
	if (query("book_count")>0)
		{
	    book=new("/d/reborn/jinyong/obj/sjecl");
	    book->move(me);
	    add("book_count",-1);
            message_vision("霍青桐说道：今天你我有缘，我就把这本《书剑恩仇录》送给你吧。\n",me);
    }
   else
   	{
                message_vision("霍青桐说道：今天你我有缘，但可惜《书剑恩仇录》我已经送给别人了。\n",me); 
   	}
   return 1;
}
void do_leave()
{
        if(!this_object())
                return;
        message_vision("$N一声呼哨，一匹青骢马呼啸而至，霍青桐一个飞身跃上青骢马，消失在暮色中。\n", this_object());
        CHANNEL_D->do_channel(this_object(), "bd", "byebye", 1);
        destruct(this_object());
}

void greeting()
{
CHANNEL_D->do_channel(this_object(), "jh", "visit", 1);
}
