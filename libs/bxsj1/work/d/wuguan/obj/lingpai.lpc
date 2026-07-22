#include <ansi.h>

inherit ITEM;


void create()
{
	set("unit","块");
	set("no_get", 1);
	set("no_drop", 1);
	set("no_put", 1);
	set("no_give", 1);      
	set("material", "bamboo");
	set_weight(50);
	setup();
}

void init()
{
	object me = this_player();

	set_name (HIR "武馆令牌" NOR, ({ "lingpai","ling","pai" }));

	set("long", HIR "这是襄阳武馆馆主的信物，用来介绍武馆人员去各大门派拜师所用(here XXX)。\n" NOR);

	if (me && present(this_object(), me)) {
		add_action("do_here", "here");
	}
}

int do_here(string str)
{
	object me = this_player(), ob = this_object();
	object ob1, ob2;
	object ob3;
	int exp,pot,shen;
        
	if (!str || str=="")
		return notify_fail ("你带谁来的？\n");

	if (!ob1 = find_living(str))
		ob1 = LOGIN_D->find_body(str);
	if (ob1 == me) 
		return notify_fail("带自己来的？\n");
	if(!objectp(ob2 = present(str, environment(me))) )
		return notify_fail("这里没 " + str + " 这个人。\n");

	if( !living(ob2) ) 
		return notify_fail("你等" + ob1->name() + "醒来再说吧。\n");            

	if (!userp(ob2) ) 
		return notify_fail("你只能给玩家带路。\n");

	if( !ob2->query_temp("wg_go"))
		return notify_fail( "对方并没有找人带路。\n" );

	if( ob2->query_temp( "wg_road" ) == 1)
		return notify_fail( "你知道对方要去哪里了吗？\n" );
        
	if( !me->query_temp( "wg_lead" ) )
		return notify_fail( "这么晚才到？\n" );

	if( !objectp( ob3 = present( me->query_temp( "wg_goto" ), environment( me ) ) ) )
		return notify_fail( "你把人送到地方了吗？\n" );
        
	message_vision( sprintf(HIC "$N对" + ob3->query( "name" )
		+ "说到：在下受襄阳武馆馆主委托，带这位" + RANK_D->query_respect( ob2 )
		+ "前来" + RANK_D->query_respect( ob3 ) + "这里，这是馆主信物。\n" NOR), me );
	message_vision( sprintf( HIC "" + ob3->query( "name" )
		+ "冲上前去，紧紧握住$N的双手，哽咽着说不出话来。\n"  NOR), ob2 );

	message_vision( sprintf( HIW "$N递给" + ob3->query("name")
		+ "一块武馆令牌。\n" NOR), me );
        
	exp = 100 + random( 100 ) + random( me->query( "combat_exp" ) / 30000 ) ;
	if( exp > 250 )
		exp = 200 + random( 50 );
	pot = 50 + random( 50 ) + random( me->query( "combat_exp" ) / 60000 ) ;
	shen = 200 + random( 2 * exp );
	write( sprintf(HIW "好，任务完成了，你得到了" + CHINESE_D->chinese_number( exp )+ "点实战经验和" 
		+ CHINESE_D->chinese_number( shen ) + "点正神。\n" NOR));

	me->add( "combat_exp", exp );
	me->add( "shen", shen );

	log_file("job/newbie", sprintf("%8s%-10s带路%8s%-10s，得到%3d点经验，现经验%d。\n",
		me->query("name"), "("+me->query("id")+")",
		ob1->query("name"), "("+ob1->query("id")+")", exp, me->query("combat_exp") ), me );

	me->delete_temp( "wg_lead" );
	me->delete_temp( "wg_goto" );
	ob1->delete_temp( "wg_go" );
	ob1->set("wg_help_exp", ob1->query("combat_exp") );
	destruct( ob );
	return 1;
}
