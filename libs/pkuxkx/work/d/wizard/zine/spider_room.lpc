#include <room.h>
#include <ansi.h>

inherit ROOM;
string look_shelf();



void create()
{
        set("short", HIW"养蛛室"NOR);
        set("long", @LONG
这里是古铜雀台的一处密室，架上(shelf) 分格内放置这各色大大小小的蜘
蛛，让人头皮一麻。

LONG
        );
        set("exits", ([
             "out" : __DIR__"the-room",
 
        ]));
        set("item_desc", ([
		"shelf" : (:look_shelf:),
	    ]));
		set("valid_startroom", 1);
        set("spider_room",1);
        setup();
      
}

string look_shelf()
{
    string msg=BLINK+RED+"架上的蜘蛛是修炼千蛛万毒手专用的，如果你没有千蛛万毒手的武功在身，千万不要乱用，致命！\n"+NOR;
    msg+="修炼方式：伸手(shen shelf)进入架子，让蜘蛛噬咬后练功(lian)逼毒。\n";
	return msg;
}

void init()
{
	object me=this_player();
    add_action("do_shen","shen");
	if (time()-me->query("tqt/mishi/enter_time")>3600*12)//12小时
	{
		tell_object(me,"这次铜雀台密室使用时间到了，你离开了此间。\n");
		me->move("/d/wizard/zine/the-room");
		return;
	}
}


int do_shen(string arg)
{
    object me=this_player();
	if (!arg||arg!="shelf")
	{
		tell_object(me,"你要把手伸进哪里？\n");
		return 1;
	}
	if (me->query_condition("qianzhu"))
	{
		tell_object(me,"你此刻已经身中千蛛万毒手之毒了。\n");
		return 1;
	}
	if (!me->query("qianzhu-wandu"))
	{
		me->set("qianzhu-wandu",1);
	}
	message_vision(WHT+"$N把手伸入架子，被架子里的蜘蛛狠狠地咬了一口。\n"+NOR,me);
	F_POISON->poison_attack(this_object(),me,"qianzhu",6+random(6));
    return 1;
}
