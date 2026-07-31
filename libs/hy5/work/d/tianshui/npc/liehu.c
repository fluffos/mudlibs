// design by 发现号(find) . all right reserved.

// liehu.c

inherit NPC;

void su_xing(object me,object ob);

void create()
{
        set_name("李三", ({ "lie hu" }) );
	set("title","猎户");
        set("gender", "男性" );
        set("age", 33);
        set("long", "只见他面色蜡黄，身上满是血迹，
看样子受了很重的伤。\n");
        set("combat_exp", 20);
        set("attitude", "friendly");
        set("env/wimpy", 60);
	set("max_kee",200);
	set("kee",5);
	set("eff_kee",5);

        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("coin", 20);
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
}

void greeting(object ob)
{
	object me = this_object();
	if( !ob || environment(ob) != environment() ) return;
	say( "李三痛苦的呻吟着：今天出去打猎没想到...发现了...这位"+ RANK_D->query_respect(ob)+ "救救我...\n");

	me->unconcious();
	remove_call_out("su_xing");
	call_out("su_xing", 20, me, ob);
}

void su_xing(object me, object ob)
{
	if ( (int)me->query("eff_kee") <= 100 ) 
	{
		me->die();
	}
	else
	{
		message_vision("\n李三醒了过来，说道: 我发现了一个...神秘山洞，洞里有一头...象牛一样的怪物。\n\n",ob);
		message_vision("我就是被它咬伤的，不是跑得快就...死在那了，山...洞就在...东......\n\n",ob);
		message_vision("李三的手在地上无力地动了几下。\n",ob);
		environment(this_object())->set("item_desc",([
		"地" : "
       ┌———.....
       │
   ┌—┘ 
   │\n",
		"地上" : "
       ┌———.....
       │
   ┌—┘ 
   │\n",
]));
		me->die();
	}
	return;
}