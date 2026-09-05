inherit NPC;
string ask_ma();  
string ask_jiema();  
string ask_guofu();
int ask_quma();
void create()  
{	set_name("中年马夫", ({ "ma fu","fu" }));
	set("gender", "男性");
	set("age", 45);
	set("str", 17);
	set("dex", 16);
	set("long", "她是郭靖家的马夫。\n");
	set("combat_exp", 1000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set_skill("unarmed", 20);
	set("neili", 100); 
	set("max_neili", 100);
 
        set("chat_chance", 6);
        set("chat_msg", ({
       " 郭大小姐也太顽皮了,成天到城里乱跑.黄帮主又该生气了\n."
       "郭大小姐很喜欢这匹马.我得好好喂,她可不象她父母那么和善.\n"

                }) ); 
        set("inquiry",([  
              "汗血宝马"  : (: ask_ma :),
                "小红马"  : (: ask_ma :),
                  "借马"  : (: ask_jiema :),
                  "取马"  : (: ask_quma :),
                  "郭芙"  : (: ask_guofu :),
          ]));


        setup();
//	carry_object(ne/weapon/fangtianji")->wield();
	carry_object(__DIR__"obj/cloth")->wear();

}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}

int ask_quma()
{
    object me=this_player();
    object ob=this_object();
    object horse;
    if (!me->query_temp("取马"))
    {
        tell_object(me,"马夫道：你得找郭大小姐去说,我们当下人的怎么做得了主啊.\n");
        return 1;
    }
    else
    {
        me->delete_temp("取马");
        horse=new("/d/xiangyang/npc/obj/hanxuema");
        horse->move(environment(me));
        horse->set_lord(ob);
        message_vision("$N牵出一匹汗血宝马，递给$n，道：既然小姐吩咐了，就交给你吧。\n",ob,me);
        return 1;
    }
}

string ask_jiema()
{
        object me;
        me = this_player();
        me->set_temp("马夫",1);
        return "要想借马,你得找郭大小姐去说,我们当下人的怎么做得了主啊.\n";
}

string ask_ma()
{
        return "这是郭大小姐最喜欢的马了,日行一千夜走八百,在大草原上,没它可不行.\n";
}
string ask_guofu()
{
        return "那是我家大小姐呀,现在又不知道跑到哪去了,你到街上看看吧.\n";
}
