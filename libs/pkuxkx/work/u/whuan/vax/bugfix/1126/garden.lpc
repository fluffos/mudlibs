#include <room.h>
inherit ROOM;

void create()
{
        set("short", "花园");
        set("long", @LONG
这是一座极大的花园，四面群山围绕，园中万花竞艳。牡丹芍药，黄菊
红玫，四季香花，在这地竞同时开放，抬眼望去，宛如置身一片香涛花海之
中。白石小径，青竹篱笆间，零乱地站了十余个红衣少女，正在剪草灌花。
西面是闭关室，据说很多上岛的武林人士，在这里自创出独门武功，北面的
花丛似乎有人拨弄过，看起来有点凌乱。
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"shilu",
		"west" : __DIR__"biguan",
]));
        set("objects", ([
        __DIR__"npc/girls" : 5,
                        ]) );

	set("outdoors","xiakedao");
        setup();

}

void init()
{
    add_action("do_bo","bo");
    add_action("do_bo","push");
    add_action("do_bo","move");
}

int do_bo(string arg)
{
    object me, room;
    me=this_player();
    if(!arg || (arg!="huacong" && arg!="花丛" && arg!="花" && arg!="hua"))
		return notify_fail("你要拨什么？\n");
	message_vision("$N从北面的一处花丛中钻了进去。\n", me);
	room = load_object(__DIR__"secretpath0");
	if(me->move(room))
		tell_object(me,"\n你到了一处秘密所在，好像有人住在这边。\n");
	return ::valid_leave(me, "north");
}

int valid_leave(object me, string dir)
{
	int i, j, flag, flag2;
	object  key, *inv, *allinv;
	object biguanshi;

	biguanshi = load_object(__DIR__"biguan");
       inv = all_inventory(biguanshi);
       for(i=0; i<sizeof(inv); i++) 
	   if(userp(inv[i])) 
	   {
		   flag = 1;
		   break;
	   }


       allinv = deep_inventory(me);
       for(j = sizeof(allinv) - 1; j >= 0; j--)
       if(userp(allinv[j])) 
	   {
		   flag2 = 1;
		   break;
	   }
  
	if(dir == "west") 
	{

		if(!me->query("createskill/long") )
		{
			return notify_fail("没有岛主的同意还是不要私自进入闭关室的好。\n");
		}	
		else if( !objectp(key = present("biguanshi key", me)))
		{
			return notify_fail("你还是先去石破天那里拿钥匙吧。\n");
		}	
		else if( flag )
		{
			return notify_fail("闭关室里面有人在修行，你还是等他出来再进去吧。\n");
		}
		else if( flag2 )
		{
			return notify_fail("你不能背着别的玩家进入闭关室！\n");
		}
		else
		{
		    message_vision("$N打开了闭关室的门走了进去，却不小心把钥匙折断了。\n", me);
		    destruct(key);
		    return ::valid_leave(me, dir);
		}
	}
    return ::valid_leave(me, dir);
}


