//lwc13.c

inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long", @LONG
这里是少林寺的练武场。由无数块巨大的花岗岩石板铺就。上千年的踩
踏已使得这些石板如同镜子般平整光滑。十来个僧人正在练习武技。武场的
一角有一组练功用的梅花桩。东南西三面各有一练武场。
LONG
	);

	set("exits", ([
		"east" : __DIR__"lwc12",
		"south" : __DIR__"lwc15",
                "west" : __DIR__"lwc14",
		]));
        set("objects",([
		__DIR__"obj/zhuang" : 1,
	]));

        
       set("item_desc", ([
             "zhuang" : "这是一组青竹制成的木桩，高一丈两寸，状成梅花排列。\n",
       ]));
	set("outdoors", "shaolin");
	set("coor/x",90);
  set("coor/y",280);
   set("coor/z",110);
   setup();

}
/*
  void init()
   {
     add_action("do_jump","jump");
   }

  int do_jump(string arg)
     {
      object me;
      me = this_player();
      if(!living(this_player()) || arg!="zhuang")
       return 0;
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");
      if((int)me->query_skill("dodge",1)>30) 
        return notify_fail("你在梅花桩上不停的穿梭来去，但已无法再提高轻功了\n");
      if((int)me->query("jingli")<30){
           me->receive_damage("jingli",10);
           write("你脚下一个不稳，从梅花桩上栽了下去\n");
           me->unconcious();
		return 1;
	}
       me->receive_damage("jingli", random(35));
        write("你在梅花桩上不停的穿梭来去，对基本轻功有所领悟\n");
message_vision("$N纵身一跃上了梅花桩，在桩上回旋来去。\n", me);  
                        me->improve_skill("dodge", me->query("int"));       
         return 1;         
}
*/
