//mhuadi2.c
//by hehe
//2003.3.20

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "茶花地");
    set("long", @LONG
这是小山背后的一片空地，此处甚为阴凉，
是曼陀山壮栽种茶花的地方。
LONG
    );

    set("exits", ([
		"west" : __DIR__"mzhulin",
		"east" : __DIR__"mhuadi1",
    ]));
    
    set("outdoors", "murong");
    setup();

}


void init()
{
	add_action("do_zai","zai");
}

int do_zai()
{
	object me;
	me=this_player();

	if (!(present("chutou",me)))
	{
		message_vision("$N没带锄头怎么种啊。\n",me);
		return 0;
	}
	if (!(present("huazhong",me)))
	{
		message_vision("$N没有花种怎么种。\n",me);
		return 0;
	}
 
	message_vision("$N卷起衣袖，拿起锄头，在地上刨了起来。\n",me);
	call_out("wait1",10,me);

	return 1;
}

void wait1(object me)
{
	tell_object(me, "\n............................\n" ) ;
	tell_object(me, "\n.......................\n" ) ;
	tell_object(me, "\n...................\n" ) ;
	tell_object(me, "\n..............\n" ) ;
	tell_object(me, "\n.....\n" ) ;
	message_vision("刨了半响，$N累得满头大汗，终于在地上弄了小坑。\n",me);
	message_vision("$N用衣袖擦了擦脸上的汗，把身上的种子放到坑里。\n",me);
	message_vision("$N又把土拢向坑内，把种子埋了起来。\n",me);
	call_out("wait2",10,me);
}
void wait2(object me)
{
	tell_object(me, "\n............................\n" ) ;
	tell_object(me, "\n.......................\n" ) ;
	tell_object(me, "\n...................\n" ) ;
	tell_object(me, "\n..............\n" ) ;
	tell_object(me, "\n.....\n" ) ;
	message_vision("慢慢地，一个小芽从地下钻了出来。\n",me);
	message_vision("它慢慢的长大，长出新枝，张满绿叶。\n",me);
	call_out("wait3",10,me);
}
void wait3(object me)
{
	object ob;
	tell_object(me, "\n............................\n" ) ;
	tell_object(me, "\n.......................\n" ) ;
	tell_object(me, "\n...................\n" ) ;
	tell_object(me, "\n..............\n" ) ;
	tell_object(me, "\n.....\n" ) ;
	message_vision("一朵粉红的茶花开了。\n",me);
	message_vision("$N欢呼起来，小心的把茶花摘了下来。\n",me);
	me->delete_temp("murong/chuhua");
	me->set_temp("murong/zhonghua",1);
	ob=new("/d/murong/obj/hua");
	ob->move(me);
}

