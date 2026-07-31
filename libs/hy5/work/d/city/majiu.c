//Room: majiu1.c 马厩
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","马厩");
      set("long",@LONG
这是客店后的马厩，常年供应新鲜草料。扬州民风淳朴，马夫们会把
马牵到马厩好生照看，将它们喂饱饮足，再洗刷得干乾净净，一直伺候到
客人上路。马厩雨檐下的烂木柱上钉着一块破木牌(paizi)。
    马厩中堆放著几堆草料，正中有一口泔槽。
LONG);
      set("outdoors", "city");
      set("no_fight", "1");
      set("no_beg", "1");
      set("no_clean_up", 0);
      set("objects", ([
               __DIR__"npc/zaohongma": 1,
               __DIR__"npc/huangbiaoma": 1,
               __DIR__"npc/ziliuma": 1,
               __DIR__"npc/mafu": 1,
      ]));
      set("item_desc", ([
          "paizi": @TEXT
客人们只要给马夫一两白银的租金就可以雇到一匹马了。

前往      北京城:  ridebj
          苏州城:  ridesz
          杭州城:  ridehz
          福州城:  ridefz
          大理城:  ridedl
          襄阳城:  ridexy
          永登城:  rideyd
          伊犁镇:  rideyl
          佛山镇:  ridefs
          峨嵋山:  rideem
          扬州城:  rideyz
          延平城:  rideyp
          江陵城:  ridejl
          长安城:  rideca
          成都城:  ridecd                                               
          无锡城:  ridewx                                               
          灵州城:  ridelz                                               
          扬州城:  rideyz                                                      
          赫图阿拉城:  rideht
          荆州城:  ridejingzhou
          昆明城:  ridekm
TEXT]));
      set("exits",([ /* sizeof() == 1 */
          "west"      : __DIR__"kedian",
      ]));
      setup();
     
}
void init()
{
	add_action("do_yao","yaoche");
}
int do_yao()
{
	object *inv,kicker;
	int sizeinv,n,tt;
object me;
me = this_player();
if(!me->query("marks/mengzhu"))
		return notify_fail("你没有乘马车的权限。\n");
   if (me->query_temp("che"))
		return notify_fail("你已经要过马车了。\n");
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("你想进去拐卖人口？\n");
       		
		}
	me->set_temp("che",1);
message_vision("$N乘上了一辆马车匆匆忙忙地离去了。\n",me);
if (me->query("shen")<0)  me->move("/d/biwu/a11");
else me->move("/d/biwu/b11");
message_vision("$N突然出现在众人眼前。\n",me);
return 1;
}
