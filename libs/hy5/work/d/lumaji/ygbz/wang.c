// zjb /2002/3/15/
inherit ROOM;
int do_piao(string arg);  
int do_zheng(string arg);
void on_wang();
void create()
{
        set("short", "网中");
        set("long", @LONG 
这是一个大网,由于年代久远,好象已出现朽腐的情况,
虽然可以很容易的挣(zheng)开, 但是下面是个无底洞, 
四周都是钢壁!
LONG
        );
        set("exits", ([
                              ]));
set("no_fight",1);
        set("item_desc", ([ 
          "大网" : "这张大网似乎可以来回晃动(huang)!\n",         
        ]));

        set("no_clean_up", 0);
        setup();
}
void init()
{
                
   add_action("do_piao", "huang"); 
 add_action("do_zheng", "zheng");
}
int do_piao(string arg)
{
        object me; 
               me = this_player();
      if( !arg || arg=="" ) return notify_fail("你要晃动什么东西!\n");
     if( arg=="wang" ) {
       write("你使尽晃动大网,让网来回飘动。\n");
      this_player()->set_temp("piaowang", 1);
                         return 1;
        }
        else {
            write("你想晃动什么东西?!\n");
            return 1;
        }
       }  
int do_zheng(string arg)
{
        object me;
        me = this_player();
      if( !arg || arg=="" ) return notify_fail("你没事挣什么挣!\n");
  if( arg=="wang" ) {
        if (me->query_temp("piaowang") ) {
       write("你使颈挣动,网子寸寸碎裂。\n");
       write("你凌空提气，借着汤势，如脱笼之鸟，灵巧的往钢板所在扑去， 成功吸附在钢板两旁凹凸岩壁的洞壁处。\n");
                        this_player()->delete_temp("piaowang"); 
    me->move(__DIR__"qiangbi");
            return 1;
        }
}
        else {
            write("你没事挣什么挣!\n");
     return 1;
        }
}



