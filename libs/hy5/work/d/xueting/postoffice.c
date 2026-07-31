// Room: /d/snow/postoffice.c

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "打铁炉");
        set("long", @LONG
这里原来是雪亭的驿站，由于长年没有什么差事，雪亭驿终于
被裁撤了。现在这里摆了一个巨大的炼铁炉，大门口上悬著一块木
牌(sign)，上面写了些字。
LONG
        );

        set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "牌子上写道：
    目前炼铁炉免费使用，玩家只要身上带好了矿石和炭来
这里tilian就可以了。不过要自备打铁工具哦。
=======================================================
            命令        原料         辅料
-------------------------------------------------------
提炼青铜    tilian qt   三颗青铜石   三颗木炭





=======================================================
",
]));
        set("exits", ([ /* sizeof() == 1 */
                "east" : __DIR__"street01",
        
        ]));
        
 //       set("objects", ([
  //              __DIR__"npc/post_officer": 1
  //      ]) );
        set("no_beg",1);
        set("no_sleep_room",1);
        set("indoors", "xueting");
        setup();
}

void init()
{
        add_action("do_tilian", "tilian");
}
int do_tilian(string arg)
{
        object me,ob,*inv;
        int i,s,t,sk;
        me = this_player();
        sk = 10+random(250);
        sk = sk + sk;
           if(me->is_busy())
        	return notify_fail("你正在忙。\n");     
        if( (arg != "qingtong") && (arg != "qt") )
		return notify_fail("  对不起目前只能提炼青铜，其它暂不开放。\n");
        
        inv = all_inventory(me);
        s=0;
        t=0;
        for(i=0; i<sizeof(inv); i++)
		{
		if ( inv[i]->name() == CYN"青铜石"NOR ) {s=s+1;}
		if ( inv[i]->name() == CYN"木炭"NOR ) {t=t+1;}
		}

	if (s<3)
		return notify_fail("  你身上带的青铜石不够，先去找点矿石再说吧。\n");
	if (t<3)
		return notify_fail("  你身上带的木炭不够，先去找点炭火再说吧。\n");
		
	// - 去玩家的原料
	s=3;
	t=3;
	for(i=0; i<sizeof(inv); i++)
		{
		if ( inv[i]->name() == CYN"青铜石"NOR )
			{
			if (s>0) 
			{
				message_vision(HIY"$N把一"+inv[i]->query("unit")+inv[i]->name()+HIY"投入提炼炉。\n"NOR,me);
				destruct(inv[i]);
				s=s-1;
				}
			}
		}

	inv = all_inventory(me);

	for(i=0; i<sizeof(inv); i++)
		{
		if ( inv[i]->name() == CYN"木炭"NOR )
			{
			if (t>0)
			{	message_vision(HIY"$N把一"+inv[i]->query("unit")+inv[i]->name()+HIY"投入提炼炉。\n"NOR,me);
				destruct(inv[i]);
				t=t-1;
				}
			}
		}
        if(me->query("qi")<20)
        	return notify_fail("  你的力气不足了，还是先休息一下吧。\n");
        if(me->query("jing")<20)
        	return notify_fail("  你的精力不足了，还是先休息一下吧。\n");

//查询玩家有没有挖掘工具。
//    if(!sizeof( inv = filter_array(all_inventory(me),
//		(: $1->is_mine_tool() && $1->tool_can_use() :)) ) )
//		return notify_fail("你身上没有用于挖掘的工具。\n");
//        me->start_busy(2);

        message_vision(HIR"$N只见炉火越来越旺，矿石也渐渐融化了……\n"NOR,me);
        

        // 直接加出结果，减轻系统负担
        i = me->query("kar") + me->query("str") + me->query("int");
        
	//1 是否可以得到青铜。
	if ( (random(sk+i) ) > ( (sk+60)*9/10) )
	{
		message_vision( HIR"$N用铁钳提起坩锅，轻轻倒入沙模中...\n"NOR, me);
		message_vision( HIY"$N提炼青铜成功了！！！\n"NOR,me);
                me->receive_damage("qi", 20);
        	me->receive_damage("jing", 20);

                ob = new(__DIR__"kuangshi/qingtong");      
                ob->move(me);
                return 1;
        }
        message_vision("$N用铁钳提起坩锅，手竟然哆嗦了一下，铜水洒了一地。\n",me);
        message_vision("$N提炼青铜失败了......\n",me);
        me->receive_damage("qi", 10);
        me->receive_damage("jing", 10);
       me->start_busy(16);
        return 1;
        
}