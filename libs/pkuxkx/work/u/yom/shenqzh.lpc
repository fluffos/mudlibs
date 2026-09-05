// waiter.c

inherit NPC;
#include <ansi.h>
inherit F_DEALER;
void create()
{
	set_name("沈千盅", ({ "shen qianzhong","shen"}) );
	set("gender", "男性" );
	set("age", 30);
	set("long",
		"他就是好酒如命的酒店老板沈千盅，据说，他喝的酒比卖的还多。不过，此人\n"
                "生性豪爽，爱交结朋友，是个黑白两道都吃的开的人！\n");
	set("combat_exp", 50000);
     set("start_room","/d/city/jiuguan");
	set("attitude", "friendly");
               set("inquiry", ([
                "万年醉" : "万年醉可是酒中极品啊，酒劲极大，而且听说多喝此酒还可以增加功力呢！只是不知道哪里有卖的,唉!\n" ,
        ]) );
	set("rank_info/respect", "老板");
      	set("vendor_goods", ({
		__DIR__"obj/lbg",
		__DIR__"obj/nerh",
		__DIR__"obj/zyq",
                __DIR__"obj/fj",
                __DIR__"obj/sdz",
                __DIR__"obj/xhj",
            }));
        set("chat_chance", 8);
        set("chat_msg", ({
       "我最喜欢酒了，但是.....万年醉这酒中极品我却还没尝过....死不瞑目啊!\n",
       "听说万年醉，喝了一口就会醉上十天半个月，多喝的话武功都要提高呢！也不知道是不是真的\n",
       "我要是能喝上一口，死也瞑目了啊！\n"
        }) );
     set("given",0);
	setup();
}

void init()
{	
	object ob;

	::init();
      add_action("do_list","list");
      add_action("do_buy","buy");
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
        if (ob->query("gender")=="女性")
           {
            command("haha "+ ob->query("id"));
            command("admire "+ob->query("id"));
            command("say 这位姑娘，难得有此豪情，来来来，请里面坐！");
        
           }
        else if (ob->query("gender")=="无性")
           {
            command("haha "+ ob->query("id"));
            command("nod");
            command("say 难得公公也来照顾小店的生意，请请！");
           } 
       else {
            command("haha"); 
            command("hi " +ob->query("id"));
            command("say 这位大爷，不是我自夸，本店的酒远近闻名，您不来几坛？");
             }
           
}
int accept_object(object me, object ob)
{
 object book;
 if(query("given")) 
{
{
 if(ob->id("wannian zui"))
 message_vision("沈千盅见到万年醉大喜过望：啊？！这真的是我梦寐以求的万年醉么？是真的么？\n沈千盅迫不及待地将万年醉一饮而尽！\n",me);
  call_out("destroy",1,ob);
call_out("yun",3);
}
return 1;
}
{
 if(ob->id("wannian zui"))
  call_out("destroy",1,ob);
if(random(2)==0)
{
 message_vision (HIR"沈千盅见到万年醉大喜过望：啊？！这真的是我梦寐以求的万年醉么？是真的么？\n你愿意把他给我？好，既然这样，在下无以为报，\n这本枪法总诀是在下祖上之物，只惜本人好酒不好武，留着也是浪费，希望对你有所帮助\n"NOR,me);
book=load_object("/d/city/obj/spear_book");
if(book) book->move(me);
message_vision("沈千盅交给$N一本枪法总诀\n",me);
}
else
{
 message_vision("沈千盅见到万年醉大喜过望：啊？！这真的是我梦寐以求的万年醉么？是真的么？\n沈千盅迫不及待地将万年醉一饮而尽！\n",me);
call_out("yun",3);
}
set("given",1);
}
return 1;
}
void yun()
{
 message_vision(HIB"沈千盅突然感到一阵醉意袭来，眼睛都睁不开了。\n沈千盅一边喃喃自语道：不可能，不可能，我可是千杯不醉的呀！\n话音未落，就只见.....\n"NOR,this_player());
this_object()->unconcious();
return;
}
void destroy(object ob)
{

     destruct(ob);
     return;
}
