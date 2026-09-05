#include <ansi.h>
inherit ROOM;

void init();
//int do_tap();
//int do_sit();
//int do_jump();
//void delete_served();

void create()
{
        set("short",HIW"北侠饺子馆"NOR);
        set("long", @LONG
这里是北侠新开的庆新春饺子馆，里面热气腾腾的饺子和满头大汗的售货员都让你
感受到了新春的喜庆，很多食客正在狼吞虎咽地吃着各种口味的饺子。你只要拍拍
(pat)桌子，就会有服务员给你端上刚出锅的大饺子。
LONG);

        set("exits", ([
                 "southeast" : "/d/city/guangchang",
        ]));


        set("no_fight", 1);
        set("no_steal", 1);
        set("no_beg", 1);
        set("no_sleep_room", 1);
		set("least_msg",1);

        setup();
}

void init()
{
        add_action("do_sit", "pat");
}

int do_sit()
{

        object me = this_player();
        object ob;

		if (sizeof(deep_inventory(me))>50)
		{
			tell_object(me,"你身上东西太多了，拿不了这许多饺子。\n");
			return 1;
		}
		message_vision("$N拍了拍桌子，一位服务员端上来三盘热气腾腾的饺子。\n",me);
		tell_object(me,HIR"服务员提醒你：吃出的纪念金币可以直接当金子用来买东西，也可以存在钱庄里，只要打cun xxx gold就可以。\n年满十六岁才能吃出金币。\n"NOR);
		ob=new("/clone/gift/jiaozi");
		ob->move((me));
		ob=new("/clone/gift/jiaozi");
		ob->move(me);
		ob=new("/clone/gift/jiaozi");
		ob->move((me));
        return 1;
}
