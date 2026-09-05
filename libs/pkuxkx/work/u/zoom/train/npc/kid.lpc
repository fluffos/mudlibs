//kid.c
//by zoom
// 2004.3.29

inherit NPC;

int ask_mimi();
void greeting(object);

void create()
{
	set_name("小孩",({ "kid" }) );
        set("gender", "男性" );
        set("age", 7);
        set("long", "这是个农家小孩子\n");
        set("combat_exp", 50);
	set("shen_type", 1);
	set("str", 11);
	set("dex", 11);
	set("con", 11);
	set("int", 11);
        set("attitude", "friendly");
        set("inquiry", ([
		"秘密"   :  (: ask_mimi :),
		"鱼"   :  "花园的池塘里有鱼，可惜我抓不到。\n",
        ]));
        setup();
//	carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{
        object me = this_player();        

        ::init();

        if( interactive(me) )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
}

void greeting(object me)
{
	command("xixi " + me->query("id"));
	command("say 跟我玩好不好，我告诉你个秘密...");
}

int ask_mimi()
{
        object me = this_player(); 
	command("heng ");
	command("say 你要是能抓到鱼给我，我就告诉你秘密");
 	me->set_temp("mark/catchfish_train",1);
	return 1;
}

int accept_object(object who, object ob)
{
        object wateryi;
        object me=this_player();
        object obj=ob;
        if (!userp(ob) && (string)ob->query("id")=="fish") {
              if((int)this_player()->query_temp("mark/catchfish_train")) {
		command("xiao " + me->query("id"));
                say("好吧，我告诉你个秘密：前边院子里的叔叔什么都知道，可厉害着呢，
你只要给他东西他就告诉你大秘密呢!\n");
              }
           else say("小孩对着你哼了一声：连小孩子都骗...\n");
                remove_call_out("destroying");
                call_out("destroying", 1, me, obj);
        return 1;
        }
        return 0;
}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}
