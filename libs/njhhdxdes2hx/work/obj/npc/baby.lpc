#include <ansi.h>

inherit NPC;
inherit F_SAVE;

void hungry();

int do_feed(string arg)
{
 object me;
 int max_food;
 if(arg!="baby") return 0; 
 me=this_player();
 if(!me->query("marks/妈妈")) return 0;
 max_food = (query("str") - 10) * 10 + 200;
 if (query("food")<max_food) {
 message_vision(HIM"$N给小孩喂起奶来...\n"NOR,me);
 add("food",100);
 add("water",100);
 }
 else tell_object(me, HIM"的孩子已经吃饱了。\n");
 return 1;
 
}

int do_drop(string arg)
{
 if (arg != "baby") return 0;
 say("你想把这么小的孩子丢弃吗? 太狠心了…\n");
 return 1;
}

void create()
{
        set_name( "婴儿", ({ "baby" }) );
        if( !restore() ) {
		set("short", "婴儿(baby)");
                set("long","一个还在襁褓中的婴儿。");
                set("chat_chance",15);
                set("chat_msg", ({
                        (: hungry() :),
			"婴儿又哭闹了，准是尿布该换了…，唉，烦死人了。\n",
                }) );
		set("chat_chance_combat", 15);
		set("chat_msg_combat", ({
"孩子声斯力竭的哭着，你这残忍的家伙，怎么忍心下得去手噢!!!!\n"}));
                set("age", 0);
                set("str", 10);
                set("int", 30);
                set("cps", 30);
                set("kar", 30);
                set("cor", 30);
                set("spi", 30);
		set("mother", "none");
		set("father", "none");
        }
	set("nodrop", 1);
        setup();
}

void init()
{
 add_action("do_feed","feed");
 add_action("do_drop", "drop");
}

string query_save_file()
{
        return __DIR__"baby/"+(string)query("father")+"_"+(string)query("mother");
}

void reset()
{
        save();
}

void hungry()
{
	int max_food;
	max_food = ((int)query("str") - 10) * 10 + 200;
	if (query("food") < max_food) say("婴儿大声哭了起来，想必他是饿了。\n");
        if (query("water") < max_food) say("婴儿大声哭了起来，想必他是渴了。\n");
}

int query_autoload() { return 1; }

