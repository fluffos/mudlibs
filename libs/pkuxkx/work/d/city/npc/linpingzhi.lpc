// linpingzhi.c 林平之

inherit NPC;
int ask_guard();
//inherit F_SKILL;

void create()
{
	set_name("林平之", ({ "lin pingzhi", "lin", "pingzhi" }));
	set("gender", "男性");
	set("age", 20);
     set("start_room","/d/city/biaoju");
	set("long", "他就是「福威镖局」的少当家－－林平之。\n");

	set("combat_exp", 10000);
	set("shen_type", 1);

	set_skill("sword", 40);
	set_skill("unarmed", 30);
	set_skill("dodge", 40);
	set_skill("parry", 40);

	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 10);
    set("inquiry", ([
                
                "趟子手" : (: ask_guard:),    
                "保镖" : (: ask_guard:),
        ]) );
	setup();
	carry_object(__DIR__"obj/changjian")->wield();
	carry_object(__DIR__"obj/cloth")->wear();
}

int ask_guard()
{
    object bodyguard;
    object me=this_player();
    if (time()-(me->query("last_time_askguard"))<600)
    {
        tell_object(me,"你不是刚刚问过我？我家也没有那么多趟子手可以雇佣啊。\n");
        return 1;
    }
    if(present("tangzi shou", environment()))
    {
        bodyguard=present("tangzi shou", environment());
        if (bodyguard->query("lord")==me->query("id"))
       
        {
            tell_object(me,"你不是刚刚问过我？我家也没有那么多趟子手可以雇佣啊。\n");
            return 1;
        }
    }
    if (!me->query("in_dart"))
    {
        tell_object(me,"你不是耍我吧？你没帮我家运镖还要雇佣趟子手？\n");
        return 1;
    }
    else
    {
        bodyguard=new("/d/city/npc/tangzishou");
        bodyguard->set("lord",me->query("id"));
        bodyguard->set("title",me->query("name")+"的趟子手");
        bodyguard->move(environment(this_object()));
        message_vision("趟子手走了出来。你可以跟她打听一下“跟随”的消息。\n",me);
       
        me->set("last_time_askguard",time());
        return 1;
    }
}