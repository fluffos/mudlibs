#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","后山");
        set("long", @LONG
古树参天，荆棘密布，一不小心就会被挂到了手脚。浓密宽厚的树叶遮蔽
了日月星辰，地上零星散落着捕蛇人踩过的脚印，四周死一般的寂静，只有风
吹过树梢的沙沙之声。遍地爬满了各种毒虫，你不禁产生了退缩之心。
LONG                           
        );

        set("exits", ([
                "southeast" : __DIR__"shanlu",
        ]));
        set("objects", ([
              __DIR__"npc/yan-ji" :1,
        ]) );
        set("outdoors", "苗疆");
        setup();
}
void init()
{
        add_action("do_find", "find");
}
int do_find(string arg)
{
        object me = this_player();

        if(!arg ||arg != "snake") 
        	return notify_fail("你在干吗？\n");
        if (!me->query("gb/snaked")|| me->query("gb/found"))
        	return notify_fail("想干吗？\n");
        if (me->is_busy())
                return notify_fail("你正忙着呢。\n");

	message_vision("$N拨开一丛丛杂草，仔细搜寻着。\n", me);
        me->start_busy(2);
        if (random(me->query_int())>20){
        	remove_call_out("happen1");
        	call_out("happen1", 1, me);
        	return 1;
        }
        if ( random((int)me->query("snake_job"))>1000){
        	remove_call_out("happen2");
        	call_out("happen2", 1, me);
        	return 1;
        }
	return 1;
}
int happen1(object me)
{
        message_vision("$N眼前一亮，发现草丛里仿佛有什么东西在动，急忙定睛仔细观瞧。”\n",me);
	if(random(me->query("kar"))>15){
		message_vision("$N满脸惊喜地伸手捡起一块玉石。\n",me);
		new(MISC_D("yushi"))->move(me);
		return 1;
	}
	if(random(me->query("int"))>10){
		remove_call_out("happen3");
		call_out("happen3", 1, me);
		return 1;
	}

	message_vision("$N使劲揉了揉眼睛，原来是眼花了。\n",me);
	return 1;
}
int happen2(object me)
{

        if (NATURE_D->query_daytime() == "event_noon"){
    		message_vision("$N满脸惊喜地伸手捡起一块金锭。\n",me);
		new("/clone/money/gold")->move(me);
		return 1;
	}
	if(random(me->query("int"))>10){
		remove_call_out("happen3");
		call_out("happen3", 1, me);
		return 1;
	}
	message_vision("$N找了半天，什么也没发现，不由地沮丧得叹了口气。\n",me);
	return 1;
}

int happen3(object me, object snake)
{
        
        message_vision("$N忽然高兴地跳了起来，大喝一声：“哪里跑！可让我逮着了！”\n",me);
	message_vision("$N用力按住一条小蛇的尾巴，把它抓了起来。\n",me);
	snake = new("/clone/animal/gbsnake");
        snake->set("name",me->query("name")+"的蛇");
	snake->set_temp("owner",me->query("id"));
	snake->move(me);
	if (!wizardp(me))
	me->set("gb/found",1);
	return 1;
}
