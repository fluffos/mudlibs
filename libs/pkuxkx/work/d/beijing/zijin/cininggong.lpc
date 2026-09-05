// Room: /d/beijing/zijin/cininggong.c
#include <ansi.h>
inherit ROOM;

void create()
{
	int i = random(2);
	set("short", HIY"慈宁宫"NOR);
	set("long",
HIC"这里是皇太后居住的地方，地上铺着厚厚的地毯。正中有一道珠
帘。床上的被褥(bedding)高高隆起不知要有什么古怪，一旁放着一
个大柜子(cabinet)。平时若未得太后宣召，是不能随便进入的。旁
边是一座非常美丽的花园。\n"NOR
	);
	set("exits", ([ /* sizeof() == 4 */
  	"west" : __DIR__"shoukanggong",
  	"north" : __DIR__"dafotang",
  	"south" : __DIR__"ciningmen",
  	"east" : __DIR__"longzongmen",
]));
	set("objects", ([
		"/d/beijing/npc/fake-queen" : 1,
		"/d/beijing/npc/ruichu" : 1,
		]) );
        //set("count1", random(5)-3);
        //set("count2", random(5)-3);
        set("time1", time());
        set("time2", time());
	setup();
}
void init()
{
	add_action("do_open", "open");
	add_action("do_move", "move");
}
int do_open(string arg)
{
	object ob, book;
	object me = this_player();
	int nowtime = time();
	if (!arg || arg != "cabinet") return 0;
	if (objectp(ob = present("huang taihou", environment(me))) && living(ob) && ob->query("fake"))
	{
		ob->kill_ob(me);
		return 1;
	}
       if (query("time1") < nowtime )
       {
             if(!me->query_temp("taihou/open") )
             {
                    switch(random(5))
             	      {
                        case 4:
  		              message_vision("$N打开柜门，只见柜中锦被里正是一本《四十二章经》，$N欣喜若狂，立刻将经书放入怀内。\n", me);
		              book = new("/d/beijing/npc/obj/book42_3");
		              book->move(me);
		              set("time1", 14400+nowtime);
		              break;
                        case 3:
                        case 2:
		              message_vision("$N打开柜门，只见柜中锦被里躺着一个女子，那女子脸色苍白，鹅蛋脸儿。\n", me);
		              ob = new("/d/beijing/npc/real-queen");
		              ob->move(environment(me));
		              set("time1", 7200+nowtime);
                        	break;
                        default:
                        	message_vision("$N打开柜门，只见柜中放着一床锦被。\n", me);
                        	set("time1", 3600+nowtime);
                        	break;
                    }
                    me->set_temp("taihou/open", 1);
                    return 1;
             }
             else
             {
                   tell_object(me, "小样，偷完了还想偷，做人不要太贪心了。\n"); 
                   return 1;
             }
       }
       else
       {
             tell_object(me, "宫里刚丢过东西，戒备森严，还是不要贸然动手的好。\n"); 
             return 1;
       }

}
int do_move(string arg)
{
	object ob, book;
	object me = this_player();
	int nowtime = time();
	if (!arg || arg != "bedding") return 0;
	if (objectp(ob = present("huang taihou", environment(me))) && living(ob) && ob->query("fake") )
	{
		ob->kill_ob(me);
		return 1;
	}
       if (query("time2") < nowtime )
       {
             if(!me->query_temp("taihou/move") )
             {
                    switch(random(5))
             	      {
                        case 4:
  		              message_vision("$N掀开被褥，见床板上有个小铜环，伸指一拉，一块阔约一尺、长约二尺的木板应手而起，
下面是个长方形的暗格，赫然放着一本《四十二章经》，$N欣喜若狂，立刻将经书放入怀内。\n", me);
		              book = new("/d/beijing/npc/obj/book42_7");
		              book->move(me);
		              set("time2", 14400+nowtime);
		              break;
                        case 3:
		              message_vision("$N掀开被褥，见床板上有个小铜环，伸指一拉，一块阔约一尺、长约二尺的木板应手而起，
下面是个长方形的暗格，放着些珠宝银票。\n", me);
		              ob = new("/clone/money/thousand-cash");
		              ob->move(environment(me));
		              set("time2", 7200+nowtime);
                        	break;
                        default:
                        	message_vision("$N掀开被褥，见床板上有个小铜环，伸指一拉，一块阔约一尺、长约二尺的木板应手而起，
下面是个长方形的暗格，里面空无一物。\n", me);
                            set("time2", 3600+nowtime);
                        	break;
                    }
                    me->set_temp("taihou/move", 1);
                    return 1;
             }
             else
             {
                   tell_object(me, "小样，偷完了还想偷，做人不要太贪心了。\n"); 
                   return 1;
             }
       }
       else
       {
             tell_object(me, "宫里刚丢过东西，戒备森严，还是不要贸然动手的好。\n"); 
             return 1;
       }
}

	
