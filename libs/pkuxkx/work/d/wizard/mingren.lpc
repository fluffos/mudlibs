// Modified by iszt@pkuxkx, 2007-04-03
// Modified by whuan,2007-12-24

#include <room.h>
#include <ansi.h>
inherit ROOM;
int do_none();
int do_bless(string arg);

void create()
{
        set("short", HIR"名人堂"NOR);
        set("long", @LONG
这里就是北大侠客行的名人堂。在这里供奉的有大侠，也有魔头，
也有不是大侠不是魔头的玩家。无论是哪一位，都曾冠绝一时，都有
一个长长而惊心动魄的故事，每一个故事都曾很深远地影响了一代甚
至两三代玩家。
    虽然他们都曾经轰轰烈烈掀起满江湖的风雨，如今，他们再也不
会在江湖出现了。他们都已经退出江湖，但他们的侠影魔踪很长时间
以后仍是一个传说。
LONG );

        set("no_fight", 1);
        set("no_steal", 1);
        set("no_beg", 1);
        set("no_sleep_room", 1);
        set("valid_startroom", 1);

        set("exits", ([
                "down" : "/d/city/wumiao",
                "north" : __DIR__"gemroom2",
//                "enter" : "/d/wizard/laxiang",
                "enter" : "/adm/room/lxguan",
        ]));
        set("objects", ([
               "/d/reborn/jinyong/npc/jinyong" : 1,
               "/d/wizard/npc/icer":1,
                "/d/wizard/npc/whuan":1,
               "/d/wizard/npc/hongdou2":1,
               "/clone/misc/yxdh-bei" : 1,
//               "/clone/cs/referee" : 1,
        ]));

        set("room_location", "/d/city/");

        setup();
}
void init()
{
        add_action("do_none","perform");
        add_action("do_bless","bless");
        add_action("do_none","attack");
        add_action("do_none","alert");
        add_action("do_none","zhaoshe");
        add_action("do_none","exert");
        add_action("do_none","xiulian");
        add_action("do_go", "go");
        add_action("do_say","say");
}
int do_say()
{
	if (userp(this_player()))
	{
		write("你想说话，但看到旁边一块『保持安静』的牌子，又看到旁人都在认真参观，只好又闭上了嘴。\n");
		return 1;
	}
	return 0;
}
int do_none()
{
        object ob = this_player();
        if(ob->is_busy())
        {
                write("你正忙着呢。\n");
                return 1;
        }
        message_vision(HIR"$N想动手，突然天上一个声音传来：「这里不准打架！」\n"NOR,ob);
        ob->start_busy(2);
        return 1;
}

int valid_leave(object me, string dir)
{
        object* inv = deep_inventory(me);
        int i;
        if(me->query("tooold"))
                return notify_fail("老死了就别四处跑了，在名人堂老老实实呆着聊天吧。\n");
        if(!userp(me) && dir!="down")
                return notify_fail("NPC乱跑啥？\n");                
        for(i=sizeof(inv)-1; i>=0; i--)
                if(inv[i]->is_character())
                        return notify_fail("名人堂的人你也往外搬？\n");
        return ::valid_leave(me, dir);
}

int do_go(string arg)
{
        if(this_player()->query("tooold"))
        {
                write("老死了就别四处跑了，在名人堂老老实实呆着聊天吧。\n");
                return 1;
        }
}
int do_bless(string arg)
{
        object me=this_player();
        object gift;
        if (me->query("gift/xmas")) return 0;
         return notify_fail("过年了，去放烟花吧。\n");
        if (me->query_temp("asked_2007ma")) return 0;
        if(me->query("combat_exp")<100815) 
                return notify_fail("至少需要100815经验才能领礼物。\n");
        if(me->query("age")<15) 
               return notify_fail("至少需要16岁才能领礼物。\n");
        if(!arg||arg!="祝北侠玩家圣诞快乐！元旦快乐！新年快乐！")
        { 
          write("冰冰说：“你说的祝词我听不懂哦！你应该说：祝北侠玩家圣诞快乐！元旦快乐！新年快乐！”\n");
          return 1; 
        }
        write("冰冰拍了拍"+me->query("name")+"的头说：“乖！无欢说给你一个礼物。”\n");  
        shout( HIY + me->name() + HIY"：「" + arg + "」\n"NOR);
        gift=new("/clone/gift/gift20080101");
        gift->set("owner",me->query("id"));   
        gift->move(me);
        write("冰冰偷偷塞给"+me->query("name")+"一件礼物。\n");
        me->add_temp("asked_2007ma",1);
        return 1;
}
