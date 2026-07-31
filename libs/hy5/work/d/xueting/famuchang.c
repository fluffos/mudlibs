// famuchang.c  edit by pian

inherit ROOM;
void create()
{
	set("short", "伐木场");
	set("long", @LONG
雪亭北边是一个小树林，也是雪亭镇樵夫常来的伐木场，由于
刚刚开发，这里的条件还很简陋。许多人来这里伐木，然后到雪亭
镇上的当铺里去出售，换点钱来生活。（请用 famu 进行伐木。）
LONG
        );
	set("exits", ([ /* sizeof() == 1 */
	"west" : __DIR__"palace_path2",
	//"east" : __DIR__"diggroom2",
]));
	setup();
}
void init()
{
        add_action("do_famu", "famu");
}
int do_famu()
{
        object me,ob,*inv;
        int i,s,sk;
        me = this_player();
        sk = 10+random(25);
        sk = sk + sk;
        
        if(me->query("qi")<20)
        	return notify_fail("你的力气不足了，还是先休息一下吧。\n");
        if(me->query("jing")<20)
        	return notify_fail("你的精力不足了，还是先休息一下吧。\n");
        if(me->is_busy())
        	return notify_fail("你正在忙。\n");

	// 查询over
	
        
        me->start_busy(2);
        message_vision("$N拿起开山斧狠命地向树根砍下去……\n", me);
if (random(12)>= 1)
{
                message_vision("$N砍的手臂发麻，可是$N怎么也没有砍下来。\n",me);
        me->receive_damage("qi", 10);
        me->receive_damage("jing", 10);
        me->start_busy(16);
        return 1;        
}         
        // 直接加出结果，减轻系统负担
        i = me->query("kar") + me->query("str") + me->query("int");
        
	
        //5
        if ((sk>50) && (random(sk+i))>((sk+70)*994/1000))
	{
		message_vision("$N得到一块黄桧木!!!\n", me);
                me->receive_damage("qi", 10);
        	me->receive_damage("jing", 10);

                ob = new(__DIR__"wood/huanghui_mu");      
                ob->move(me);
                return 1;
        }
        
        //6
        if ((sk>20) && (random(sk+i))>((sk+65)*990/1000))
	{
		message_vision("$N得到一块雪松木!!!\n", me);
                me->receive_damage("qi", 10);
        	me->receive_damage("jing", 10);

                ob = new(__DIR__"wood/xuesong_mu");      
                ob->move(me);
                return 1;
        }
        
        //7
        if ((random(sk+i))>((sk+65)*9/10))
	{
		message_vision("$N得到一块杨柳木!!!\n", me);
                me->receive_damage("qi", 10);
	        me->receive_damage("jing", 10);

                ob = new(__DIR__"wood/yangliu_mu");      
                ob->move(me);
                return 1;
        }
        
        message_vision("$N砍的手臂发麻，可是$N怎么也没有砍下来。\n",me);
        me->receive_damage("qi", 10);
        me->receive_damage("jing", 10);
  me->start_busy(16);
        return 1;        
}