//      chufang.c 厨房
//      Designed by secret (秘密)
//      97/04/09
/*Updated by George 98/7
	1. now work only add exp and silver;
*/

inherit ROOM;

void init();
int work();

void create()
{
        set("short","柴房");
        set("long",@LONG
这里是灵鹫宫的柴房，墙角堆着一捆捆的干柴，低矮的墙壁已经发黑，显示着
岁月的沧桑。房中醒目的位置有一块牌子（paizi）。
LONG
        );

        set("item_desc",([
                "paizi" : "本柴房招收杂工。工作(work)一次付银１两。\n",
        ]));
        set("no_fight",1);
        set("no_steal",1);
        set("exits",([
                "east" : __DIR__"chufang",
        ]));

        set_temp("times" , 10);

        setup();

}

void init()
{
        add_action("do_work","work");
}

int do_work()
{
        object me=this_player();
        object ob;

        if (query_temp("times")==0)
			return notify_fail("今天的活干完了，明天再来吧！\n");
        if(me->query("qi")<20)
                return notify_fail("你身体太虚弱，去休息一会吧！\n");
        me->add("qi",-20);
        message_vision("$N干了一些杂活，累得够呛。\n" , me);
        add_temp("times",-1);
        if (query_temp("times")==0)
                {
			remove_call_out("renewing");	
			call_out("renewing", 900 + random(900));	
		   }
		
		ob=new("/clone/money/silver");
		ob->set_amount(1);
		ob->move(me);

		me->set("combat_exp", ((int)me->query("combat_exp")+random(2)));
        return 1;
}
void renewing()
{
	add_temp("times",10);
}

