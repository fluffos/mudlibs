#include <ansi.h>
inherit ROOM;

void init();
//int do_tap();
//int do_sit();
//int do_jump();
//void delete_served();

void create()
{
        set("short",HIW"悠然元宵铺"NOR);
        set("long", @LONG
这里是为了庆祝元宵佳节和冰冰喜得千金新开的『悠然元宵铺』。
元宵铺里人来人往好不热闹，每个人脸上都洋溢着喜庆的笑容，
找张空着坐下拍拍桌子(pat)，就会有小二给你端上可口的元宵。
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
			tell_object(me,"你身上东西太多了，拿不了这许多元宵。\n");
			return 1;
		}
		message_vision("$N拍了拍桌子，一位服务员端上来一碗香浓糯软的元宵。\n",me);
		tell_object(me,HIR"服务员提醒你：吃出的纪念金币可以直接当金子用来买东西，也可以存在钱庄里，只要打cun xxx gold就可以。\n年满十六岁才能吃出金币。\n"NOR);
		ob=new("/clone/gift/yuanxiao");
		ob->move((me));
        return 1;
}