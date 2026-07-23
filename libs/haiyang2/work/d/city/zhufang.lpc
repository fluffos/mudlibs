#include <ansi.h>
inherit ROOM;
string *box_object=({
"/clone/box/item/0",
"/clone/box/item/1",
"/clone/box/item/2",
"/clone/box/item/3",
"/clone/box/item/4",
"/clone/box/item/5",
"/clone/box/item/6",
"/clone/box/item/7",
"/clone/box/item/8",
"/clone/box/item/9",
"/clone/box/item/10",
"/clone/box/item/11",
"/clone/box/item/12",
"/clone/box/item/13",
"/clone/box/item/14",
"/clone/box/item/15",
"/clone/box/item/16",
"/clone/box/item/17",
"/clone/box/item/18",
"/clone/box/item/19",
"/clone/box/item/20",
"/clone/box/item/21",
"/clone/box/item/22",
"/clone/box/item/23",
"/clone/box/item/24",
"/clone/box/item/25",
"/clone/box/item/26",
"/clone/box/item/27",
"/clone/box/item/28",
"/clone/box/item/29",
"/clone/box/item/30",
"/clone/box/item/31",
"/clone/box/item/32",
"/clone/box/item/33",
"/clone/box/item/34",
"/clone/box/item/35",
"/clone/box/item/36",
"/clone/box/item/37",
"/clone/box/item/38",
"/clone/box/item/39",
"/clone/box/item/40",
"/clone/box/item/41",
"/clone/box/item/42",
"/clone/box/item/43",
"/clone/box/item/44",
"/clone/box/item/45",
"/clone/box/item/46",
"/clone/box/item/47",
"/clone/box/item/48",
"/clone/box/item/49",
"/clone/box/item/50",
"/clone/box/item/51",
"/clone/box/item/52",
"/clone/box/item/53",
"/clone/box/item/54",
"/clone/box/item/55",
"/clone/box/item/56",
"/clone/box/item/57",
"/clone/box/item/58",
"/clone/box/item/59",
"/clone/box/item/60",
"/clone/box/item/61",
"/clone/box/item/62",
"/clone/box/item/63",
"/clone/box/item/64",
"/clone/box/item/65",
"/clone/box/item/66",
"/clone/box/item/67",
"/clone/box/item/68",
"/clone/box/item/69",
"/clone/box/item/70",
"/clone/box/item/71",
"/clone/box/item/72",
"/clone/box/item/73",
"/clone/box/item/74",
"/clone/box/item/75",
"/clone/box/item/76",
"/clone/box/item/77",
"/clone/box/item/78",
"/clone/box/item/79",
"/clone/box/item/80",
"/clone/box/item/81",
"/clone/box/item/82",
"/clone/box/item/83",
"/clone/box/item/84",
"/clone/box/item/85",
"/clone/box/item/86",
"/clone/box/item/87",
"/clone/box/item/88",
"/clone/box/item/89",
"/clone/box/item/90",
"/clone/box/item/91",
"/clone/box/item/92",
"/clone/box/item/93",
"/clone/box/item/94",
"/clone/box/item/95",
"/clone/box/item/96",
"/clone/box/item/97",
"/clone/box/item/98",
"/clone/box/item/99",
"/clone/box/item/100",
"/clone/box/item/101",
"/clone/box/item/102",
"/clone/box/item/103",
"/clone/box/item/104",
"/clone/box/item/105",
"/clone/box/item/106",
"/clone/box/item/107",
"/clone/box/item/108",
"/clone/box/item/109",
"/clone/box/item/110",
"/clone/box/item/111",
"/clone/box/item/112",
"/clone/box/item/113",
"/clone/box/item/114",
"/clone/box/item/115",
"/clone/box/item/116",
"/clone/box/item/117",
"/clone/box/item/118",
"/clone/box/item/119",
"/clone/box/item/120",
"/clone/box/item/121",
"/clone/box/item/122",
"/clone/box/item/123",
"/clone/box/item/124",
"/clone/box/item/125",
"/clone/box/item/126",
"/clone/box/item/127",
"/clone/box/item/128",
"/clone/box/item/129",
"/clone/box/item/130",
"/clone/box/item/131",
"/clone/box/item/132",
"/clone/box/item/133",
"/clone/box/item/134",
"/clone/box/item/135",
"/clone/box/item/136",
"/clone/box/item/137",
"/clone/box/item/138",
"/clone/box/item/139",
"/clone/box/item/140",
"/clone/box/item/141",
"/clone/box/item/142",
"/clone/box/item/143",
"/clone/box/item/144",
"/clone/box/item/145",
"/clone/box/item/146",
});
void create()
{
        set("short", HIW"垃圾场1号"NOR);
        set("long", @LONG
海洋中的一块福地。武林人士通常都来此处找宝，地上有很多垃圾，是
个找东西的好地方啦！！在这里你可以用(cizhusi)来翻垃圾啦。不要钱
很多的，快抢啊!!
[32m
           垃圾处理中心                                       
[37m
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : "/d/city/wumiao",
  "west" : "/d/city/zhufang2",
]));


	set("sleep_room", "1");
	set("fadaizhu",1);
	set("citybiwu",1);
	set("pingan",1);
	set("no_death_penalty",1);
	set("no_fight",1);
	setup();
}

void init()
{
        add_action("do_quit2","chen");
        add_action("do_quit2","quit");
        add_action("do_levelup","cizhusi");
}
int do_quit(string arg)
{
	if(arg=="all") {
        write(this_player()->query("name")+"，安心的找垃圾吧！\n");
        return 1;
	}
	if(arg=="corpse") {
        write(this_player()->query("name")+"，安心的找垃圾吧！\n");
        return 1;
}  
}
int do_quit2(string arg)
{
        write(this_player()->query("name")+"，安心的找垃圾吧！\n");
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
return notify_fail("只要新手才能找垃圾!\n");
if ((int)me->query("combat_exp") > 200000 && (int)me->query("combat_exp") < 303000)
return notify_fail("获得2000经验以上才能找垃圾!先去练点经验吧!!\n");
if ((int)me->query("age") < 15)
return notify_fail("15岁经验以上才能找垃圾!先去练点经验吧!!\n");

if ((int)me->query("combat_exp") < 2000)
return notify_fail("2000经验以上才能找垃圾!先去练点经验吧!!\n");
if (me->query("food")*1.5 > me->max_food_capacity())
return notify_fail("你现在不饿啦，还是睡觉吧？\n");
if (me->query_condition("yzhu_busy"))
return notify_fail("你刚找垃圾过！现在还没到找垃圾的时间呢!\n");
if ((int)me->query("dietimes")>2)
return notify_fail("死过三次的人，找垃圾不行了!!\n");


me->apply_condition("yzhu_busy",75);
message_vision(HIY "$N把头伸进垃圾场里乱找一通！终于找好了!!\n" NOR,me);

if (random(10)==9)
{
if (random(3)==0)
{
       int rand;
       rand=random(sizeof(box_object));
           ob=new(box_object[rand]);
 if(ob)
{
        ob->move(me);
message_vision(HIR "$N在垃圾场里找出了"+HIY":"+ob->query("name")+"."NOR+"。\n" NOR,me);
}
}
else
if (random(3)==0)
{
       int rand;
       rand=random(sizeof(box_object));
           ob=new(box_object[rand]);
 if(ob)
{
        ob->move(me);
message_vision(HIR "$N在垃圾场里找出了"+HIY":"+ob->query("name")+"."NOR+"。\n" NOR,me);
}
}
else if (random(3)==1)
{
        ob=new("/clone/money/gold");
        ob->set_amount(random(5)+1);
        ob->move(me);
message_vision(HIR "$N在垃圾场里找出了一些黄金!!\n" NOR,me);
}
else if (random(3)==2)
{
        ob=new("/clone/money/1000-cash");
        ob->set_amount(1);
        ob->move(me);
message_vision(HIR "$N在垃圾场里找出了一些银票!!\n" NOR,me);
}

else 
{
        ob=new("/clone/money/silver");
        ob->set_amount(random(50)+1);
        ob->move(me);
message_vision(HIR "$N在垃圾场里找出了一大块白银!!\n" NOR,me);
}
}
else if(random(500)==499)
      {
message_vision(HIY "$N在垃圾场里找出了一个宝石!!\n" NOR,me);
        ob=new("/clone/gem/gem");
if (ob->query("level") >4)
{
        ob=new("/clone/gem/gem");
}
if (ob->query("level") >4)
{
        ob=new("/clone/gem/gem");
}
if (ob->query("level") >4)
{
        ob=new("/clone/gem/gem");
}
        ob->move(me);
}
else if(random(600)==599)
      {
if (random(3)==0)
{
message_vision(HIY "$N在垃圾场里找出了一个机会珠!!\n" NOR,me);
        ob=new("/clone/box/zhu7");
        ob->move(me);
}
}
me->set("food",me->max_food_capacity());me->set("water",me->max_water_capacity());
me->start_busy(2);
	return 1;
}