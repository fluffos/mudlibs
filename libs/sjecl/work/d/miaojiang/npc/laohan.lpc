// 老汉

inherit NPC;
int ask_me(); 
 
 
void create()
{
	set_name("苗族老汉", ({ "miaozu laohan","laohan" }) );
	set("gender", "男性" );
	set("age", 64);
	set("long",
		"这是一位满脸皱纹的苗家老者。\n");
	set("combat_exp", 30000);
	set("attitude", "peaceful");
	 
        set("inquiry", ([
		"name" : "我姓何，年轻的时候在中原那里打铁为生，哎，现在老了。\n",
                "here" : "这里就是苗疆，不远就是五毒教的禁地，要去那里小心些吧。\n",
		"铁铲": (: ask_me :),
	]) );
	setup();
        carry_object(ARMOR_D("cloth"))->wear();
}

int ask_me()
{
        object chan, me, ob;

        me = this_object();
        ob = this_player();
        
        if ( present("xiao tiechan", ob) )
	{
		command("say 你不是有了吗，还想要什麽？\n");
		return 1;
	}
	chan = new(__DIR__"obj/tiechan");
        command("look " + ob->query("id")); 
        command("say 这里正好有一把铁铲没什麽用，你要就拿去吧。\n");
	chan->move(ob);
	message_vision("$N给了$n一把铁铲。\n", me, ob);
	return 1;
}

