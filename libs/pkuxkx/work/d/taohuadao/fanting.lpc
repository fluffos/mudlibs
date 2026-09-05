// Room: /d/taohuadao/fanting.c
// By llx 22/10/97

#include <ansi.h>
inherit ROOM;

void init();
//int do_tap();
//int do_sit();
//int do_jump();
//void delete_served();

void create()
{
	set("short", "饭厅");
	set("long", @LONG
屋内散发着各种各样的野味，和着清香的茶香和鲜嫩的鲜汤味，沁人心脾，让人不忍将
手中的饭具。屋内有一些景德镇瓷器，供桃花岛的弟子和远方的来客们使用。屋里四周
得体地摆着些未刨皮的榕树做的桌子(table)和藤制的椅子(chair)，其上坐满了桃花岛
的男女弟子。南边有扇窗子(window)，景色宜人。
LONG
	);

	set("exits", ([
		"west" : __DIR__"zoulang",
	]));
	
    set("item_desc", ([
	    "table" : "一张典雅的未刨皮的木桌，上面放着一些瓷器和茶具。\n",
	    "chair" : "一只藤制的坐椅，坐上去冰凉凉的感觉，好舒服耶！\n",
		"window" : "可以看得见东南远处桃花林一片，拟似彩云盖地，让人神往。
                  窗子的下面就是积翠亭。\n",
	]));
	                                

	set("objects",([
		__DIR__"npc/yapu" : 1,
		__DIR__"obj/feiya" : 1,
		__DIR__"obj/xuntianji" : 1,
                __DIR__"obj/yinsijuan" :1,
                __DIR__"obj/mudancha" : 1,
                __DIR__"obj/haoqiutang" : 1,

	]));
	
	set("no_fight", 1);
	
	setup();
}

void init()
{
	add_action("do_jump", "jump");
	add_action("do_tap", "tap");
	add_action("do_tap", "knock");
	add_action("do_sit", "sit");
}

int do_jump(string arg)
{

	object me = this_player();
	int dex = this_player()->query_dex();
	object ob;

    if (arg != "window" && arg != "out") return command("jump "+arg);
    
	me->delete_temp("marks/sit");
	me->delete_temp("tea_cup");
	
    message_vision("$N＂嗖＂地一声跳出窗户。\n", me);
    
    if ((dex <= 23)&&(random(4)>2) ||((dex < 23)&& dex <=26)&&random(2) )
    {
    	message_vision("结果＂啪＂地一声$N在积翠亭摔了个结结实实。\n",me);
	    if ( objectp(ob=present("fei ya",this_player())))
	    {
    		message_vision("肥鸭压烂了，沾了$N一屁股油汁。\n", me);
    		destruct(ob);
   		}
	    if ( objectp(ob=present("mudan cha",this_player())))
	    {
    		message_vision("怀里的牡丹茶倒了，溅了$N一屁股茶水。\n",me); 
    		destruct(ob);
   		}
            if ( objectp(ob=present("tian ji",this_player())))
             {
                message_vision("$N手中的熏田鸡压烂了，沾了$N一屁股的鸡油。\n",me);
                destruct(ob);
                }
            if ( objectp(ob=present("yin si",this_player())))
               {
                message_vision("$N手中的银卷死烂了，把$N弄脏了一身。/n",me);
                destruct(ob);
                }
             if ( objectp(ob=present("haoqiu tang",this_player())))
                {
                 message_vision("$N怀中的好逑汤倒了，溅了$N一身。\n",me);
                 destruct(ob);
		 }
   		me->receive_damage("qi", 55, me);
   		me->receive_wound("qi", 35, me); 
   		me->improve_skill("dodge", random(4));
   		
    } else if (dex <= 26)
    {
    	message_vision("$N摇摇晃晃地落在积翠亭上，差点摔倒！\n", me);
   		me->improve_skill("dodge", random(3));
    
    } else 
    {
    	message_vision("$N提一口气，姿态潇洒地飘落在积翠亭上！\n", me);
    }
    
    me->move(__DIR__"jicuiting");
    
    return 1;
}

int do_tap(string arg)
{

	object me;
	object yapu;

	if (!arg || (arg != "desk" && arg != "table"))
	{
		return notify_fail("你要敲什么？\n");	
	}
		
	me = this_player();	
	if( !objectp(yapu = present("yapu", environment(me))))
	 	return notify_fail("你敲了敲桌子，却还是没人理你。你突然感觉自己很无聊。\n");
	 			
	if( !me->query_temp("marks/sit") )  
		return notify_fail("你敲了敲桌子，却没想到有对年轻人从桌底下钻出来，愕然地看着你，"
	 		+"\n你突然感觉自己很愚蠢。\n");
	
    if( me->query_temp("marks/served") )
    {
        message_vision("哑仆白了$N一眼，显然对你很反感。\n",me);
        return notify_fail("");
    }

	message_vision("$N端坐在桌前，轻轻扣了下桌面，哑仆看见后，走过来招呼。\n", me);
	
	yapu->serve_tea(me);

    me->set_temp("marks/served", 1);
//  remove_call_out("delete_served");
    call_out("delete_served", 10, me);

	return 1;
}


void delete_served(object me)
{
	if ( objectp(me) ) me->delete_temp("marks/served");
}


int do_sit(string arg)
{

	if ( !arg || (arg != "chair") )
		return notify_fail("你要坐什么上面？\n");	
	
	if (this_player()->query_temp("marks/sit"))
		return notify_fail("你已经有了个座位了。\n");	
			
	this_player()->set_temp("marks/sit", 1);
	return notify_fail("你找了个空位座下，等着上茶。\n");	
}
/*


int valid_leave(object me, string dir)
{

	if (  (dir == "west")
	   && ( present("mudan cha", this_player()) || present("haoqiu tang",this_player())
	        || present("fei ya", this_player()) || present("tian ji",this_player())
		|| present("yin si",this_player()) )
	   && objectp(present("yapu", environment(me))) )
	switch ( random(2) ) 
	{
	case 0: 
	 return notify_fail
		("哑仆拦住了你，显然对你很不满意。\n");
	 break;
	case 1:
	 message_vision("哑仆对$N做了个手势：让$N把饮食留下。", me);
	 return notify_fail("\n");
	 break;
	}
	
	me->delete_temp("marks/sit");
	me->delete_temp("tea_cup");
	return ::valid_leave(me, dir);
}

*/
