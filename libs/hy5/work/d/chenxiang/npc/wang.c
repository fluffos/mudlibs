 //Tie
inherit NPC;
inherit F_VENDOR;
int tell_him();
int tell_him2();
void create()
{
    set_name("王石匠", ({ "wang", "shijiangfang" }) );
    set("gender", "男性" );
    set("age", 49);
    set("long", @LONG
王石匠年纪已经颇大了，听说他年轻的时候有个大恩人。
如果不是恩人的话，王石匠恐怕早已经被人害死了。
LONG
        );
    set("combat_exp", 700);
    set("attitude", "friendly");
    set_skill("dodge", 50);
    set_skill("parry", 50);
	set("vendor_goods", ({
        __DIR__"obj/stone1",
        __DIR__"obj/stone2",
        __DIR__"obj/stone3",
        __DIR__"obj/stone4",
	}));
    set("inquiry", ([
        "玉脖套" : (: tell_him :),
        "yubotao" : (: tell_him :),
        "康七" : (: tell_him2 :),
        "kangqi" : (: tell_him2 :),
        ]));
    setup();
    carry_object("/clone/misc/cloth")->wear();
} 
void init()
{
    object ob; 
    ::init();
    if( interactive(ob = this_player()) && !is_fighting() )
    {
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
    }
		add_action("do_buy", "buy");
	add_action("do_list", "list");
} 
void greeting(object ob)
{
    if( !ob || environment(ob) != environment() ) return;
    switch( random(10) )
    {
    case 0:
        say( " 王石匠笑着道：这位"
             + RANK_D->query_respect(ob)
             + "，买石狮子么？ \n");
        break;
    case 1:
        say( " 王石匠笑着道：这位"
             + RANK_D->query_respect(ob)
             + "，我这儿的大理石质量最好了。 \n");
        break;
    }
}  
int tell_him2()
{
    object me;
    me=this_player();
    if (me->query("combat_exp")<1000000) {
        tell_object(me,"王石匠道：你怎么可能认识我的大恩人呢？大概是听别人说了想来冒充的吧！\n");
        return 1;
        }
    tell_object(me,"王石匠道：你，你居然认识我的大恩人？！你有什么要帮忙的！尽管说！\n");
    me->set_temp("marks/王石匠",1);
    return 1;
}  
int tell_him()
{
    object me;
    me = this_player();
    if(me->query_temp("marks/王石匠")) 
        message_vision("$N对$n道：我虽然年老眼花，但你是我恩人的朋友，"
                       "拿来给我看看吧！\n",this_object(),me);
    else
        message_vision("$N对$n道：我已经年老眼花，不能帮你做这么细的活了！\n",
                       this_object(),me);
    return 1;
}  
int accept_object(object me, object obj)
{
    if(me->query_temp("marks/王石匠") && obj->query("id") == "round jade" &&
        obj->query("need_fix") && !obj->query("fixed"))
    {
        obj->set("fixed",1);
        obj->set("long","一个用缅玉琢磨成的玉弧，大约有八寸宽，三分之一园。
两端有一凸一凹的两个槽。\n");
        message_vision("$N将$n接过去，将$n的两端刻出一凸一凹的两个槽。\n",
                       this_object(),obj);
        notify_fail(name()+"拍了拍身上的尘土，将缅玉弧给还了你。\n");
    } 
    return 0;
}       
