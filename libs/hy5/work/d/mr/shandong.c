// /u/beyond/mr/shandong.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short",BLU"小山洞"NOR);
        set("long",@long
这里是假山里的地下密室。密室虽小，却也五脏俱全，石桌石椅，石几
石床，连室内放的几件器皿，也都是石制的。看来似乎很久以前有人在这里
住过。墙壁(wall)上好象刻着些什么。
long);
        set("item_desc", ([

 "wall" : "这是一整块墙面，上面刻了些奇怪的图形。\n",
        ]));

        setup();
}

void init()
{
        add_action("do_break","break");
        add_action("do_study", "study");
        add_action("do_study", "du");
}


int do_study(string arg)
{
	object me;

	me = this_player();
        if ( arg != "wall" )
                 return 0;
	if (me->is_busy() || me->is_fighting()) {
		write("你正忙着哪！\n");
		return 1;
	}
	if ( (int)me->query_skill("literate", 1) < 1) {
		write("你是个文盲，先学点文化(literate)吧。\n");
		return 1;
	}
        if ( (int)me->query("jing")<30) {
                 me->receive_damage("jing", 10);
                 write("你太累了，已经没有力气来研读墙壁上「古怪图形」的了！\n");              
	        return 1;
	}
    me->receive_damage("jing", 30 + random(15));

	tell_room(this_object(), me->name() + "正专心研究墙面上的「古怪图形」。\n", ({ me }));

    if ( (int)me->query_skill("blade", 1) < 101 && (int)me->query_skill("blade", 1) >= 40)
	{
        me->improve_skill("blade", me->query("int"));
        write("你对着墙面上的「古怪图形」琢磨了一回儿，似乎对基本刀法略有心得。\n");
		return 1;
	}
        if ( (int)me->query_skill("blade", 1) < 40) {
write("你看了半天还是看不懂上面的图形是什么含义。\n");
return 1;
}

	write("你对着古怪图形研究了一会，但是你已经研究透彻，对你来说已毫无意义了。\n");

	return 1;
}


 int do_break(string arg)
{
        int n;
        n = this_player()->query("neili");
        if( !arg || arg!="wall" ) {
                write("你要打碎什么的东西！\n");
                return 1;
        }

  message_vision(
   "$N深吸一口气，双掌同时拍出。\n", this_player());

  if (n>=200) {
        message_vision(
 "$N只听一声“轰”的一声，$N把岩石震开了！一个向上的洞口出现在你面前。\n", this_player());
        set("exits/up", __DIR__"jiashan");
        this_player()->set("neili",n-200);
        remove_call_out("close");
        call_out("close", 5, this_object());
        }
        else {
        message_vision(
        "$N大吼一声“开！”，结果什么也没发生。看来$N的内力不够强。\n", this_player());
        this_player()->set("neili",0);
           }

        return 1;
    }

     void close(object room)
    {
message("vision","岩石滚回了原位，又挡住了洞口。\n", room);
         room->delete("exits/up");
   }

