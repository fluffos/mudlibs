#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIY"猪圈"NOR);
        set("long", @LONG
海洋中的一块福地。武林人士通常都来此处发呆，地上有很多猪食，是
个长肉的好地方啦！！在这里你可以用(cizhusi)来吃东西啦。不要钱
很多的，快抢啊!!
[32m
                       我是猪!我是猪，
                       我要变!变肥锗。
                                       
[37m
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : "/d/city/wumiao",
  "west" : "/d/city/zhufang2",
]));


	set("fadaizhu",1);
	set("citybiwu",1);
	set("pingan",1);
	set("no_death_penalty",1);
	set("no_fight",1);
	setup();
}

void init()
{
        add_action("do_quit2","quit");
        add_action("do_levelup","cizhusi");
}
int do_quit(string arg)
{
	if(arg=="all") {
        write(this_player()->query("name")+"，安心的养肉吧！\n");
        return 1;
	}
	if(arg=="corpse") {
        write(this_player()->query("name")+"，安心的养肉吧！\n");
        return 1;
}  
}
int do_quit2(string arg)
{
        write(this_player()->query("name")+"，安心的养肉吧！\n");
        return 1;
}
int  do_levelup(string arg)
{
	object me, ob;
	object gold;
	int cost = 1;
	int i,j,base,current;
	string id,name ;	
	string file,newfile,filestring;
	me = this_player();
	id = me->query("id");
if (me->query("combat_exp") > 500000)
return notify_fail("只要呆猪才能吃猪食!\n");
if (me->query("food")*2 > me->max_food_capacity())
return notify_fail("你现在不饿啦，还是睡觉吧？\n");

message_vision(HIY "$N把头伸进食槽里乱吃一通！终于吃饱了!!\n" NOR,me);
if (random(12)==9)
{
if (random(4)==0)
{
        ob=new("/clone/money/silver");
        ob->set_amount(random(100)+1);
        ob->move(me);
message_vision(HIR "$N在猪槽里吃到了一大块白银!!\n" NOR,me);
}
else if (random(4)==1)
{
        ob=new("/clone/money/coin");
        ob->set_amount(random(100)+1);
        ob->move(me);
message_vision(HIR "$N在猪槽里吃到了一些铜板!!\n" NOR,me);
}
else if (random(4)==2)
{
        ob=new("/clone/money/gold");
        ob->set_amount(random(20)+1);
        ob->move(me);
message_vision(HIR "$N在猪槽里吃到了一些黄金!!\n" NOR,me);
}
else if (random(4)==3)
{
        ob=new("/clone/money/1000-cash");
        ob->set_amount(random(3)+1);
        ob->move(me);
message_vision(HIR "$N在猪槽里吃到了一些银票!!\n" NOR,me);
}
else 
{
        ob=new("/clone/money/silver");
        ob->set_amount(random(100)+1);
        ob->move(me);
message_vision(HIR "$N在猪槽里吃到了一大块白银!!\n" NOR,me);
}
}
me->set("food",me->max_food_capacity());me->set("water",me->max_water_capacity());
	return 1;
}