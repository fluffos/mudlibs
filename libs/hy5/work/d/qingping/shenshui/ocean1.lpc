 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "海上");
        set("long", @LONG
四周是茫无边际的海水，看不到任何的船只或路地，你被这无边无际的海水
包围着，随着波浪而起浮，苦涩的海水不时地灌入你的口中，你不由地感到了自
己的渺小，不知还有多大的生还机会。
LONG
        );
   set("objects", ([
        __DIR__"npc/snake" : 2
   ]) );    
        set("coor/x",1200);
        set("coor/y",-300);
        set("coor/z",-70);
   setup();
} 
void init()
{
   add_action("do_swim", "swim");
} 
int do_swim(string arg)
{
   object me, room;
   int kar, k;
  
   me = this_player();
   if( me->is_fighting() )
      return notify_fail("你在战斗中！\n");
   if( me->is_busy() )
      return notify_fail("你上一个动作还没有完成。\n");
   me->start_busy(2);
   kar = (int)me->query_kar();
   message_vision("\n$N奋力向前游去!\n", me);
   if(random(200) < kar) {
      tell_object(me, "远远的你似乎看到了一片陆地，你用尽所有的力气向那儿游去。\n");
      message_vision("$N终于湿淋淋地爬到了岸上!\n\n", me);
/*      if(random(50) < kar) {
         room = find_object("/d/tieflag/rock0");
         if(!objectp(room)) room = load_object("/d/tieflag/rock0");
         me->move(room);
      } else {*/
      room = find_object("/d/tieflag/seaside");
      if(!objectp(room)) room = load_object("/d/tieflag/seaside");
      me->move(room);
      message("vision", me->name()+"湿淋淋地从海里爬了上来。\n", environment(me), me);
      return 1;
   } 
   room = find_object(__DIR__"ocean2");
   if(!objectp(room)) room = load_object(__DIR__"ocean2");
   me->move(room);
   return 1;
}       
