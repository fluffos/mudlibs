// Room: /d/emei/liangfengqiao.c 凉风桥
// create by host dec,20 1997

inherit ROOM;
string* npcs = ({
        "fish",
        "fish1",
});

string* npcs1 = ({
        "fish2",
        "fish3",
});

void create()
{
        set("short", "凉风桥");
	set("long", @LONG
这里已经是峨嵋山脚下，在你面前有一条小溪横贯东西，在溪水上方搭
了一座木桥，走在木桥上附身看去，只见小河水可清澈见底，偶尔可见鱼儿
在水中游来游去。远方吹来阵阵微风，顿使你觉的精神气爽。
LONG
	);
       set("outdoors", "emei");
	set("exits", ([
                "southup" :  __DIR__"jietuopo",
                "north" : __DIR__"milin2",
	]));

	set("objects",([
	]));

	setup();
}
void init()
{
   add_action("do_catch","catch");
}

void wait_catch()
{
   
    object me;
    me=this_player();
    message_vision("$N拿起了钢叉，静静的看着水面。\n",me);
    
    me->set_temp("busy",1);
    me->start_call_out( (: call_other, __FILE__, "delay_message", me :), 5);
}

void delay_message(object me,object obn)
{

  int i = random(sizeof(npcs));
  int j = random(sizeof(npcs1));
  me->delete_temp("busy");

  if ( random(me->query_str()) > (me->query_str())/2)
   { 
     if ( random(me->query_str()) < 18)
    {
       message_vision("一条鱼儿游了过来，$N奋力扎了过去，鱼儿急窜而过！\n",me);
          return 0;
        } 
    else if ( random(me->query_str()) <  25)
       {
      obn= new("/d/emei/obj/"+npcs[i]);
      obn->move(me); 
      message_vision("突然一条鱼儿游了过来，$N猛的扎了过去，正中鱼身！\n",me);
         return 0;
      }
    else {
      obn= new("/d/emei/obj/"+npcs1[j]);
      obn->move(me); 
      message_vision("突然一条鱼儿游了过来，$N飞快的扎了过去，正中鱼身！\n",me); 
      return 0;
      }
   }
  message_vision("一条鱼儿游了过来，$N奋力扎了过去，鱼儿急窜而过.\n",me);
    return 0;  
}


int do_catch(string arg)
{

    object me,obj; 
    me=this_player();

    if (me->query_temp("busy"))
       return notify_fail("你现在正忙着捉鱼！\n");

    if ( !arg || (arg != "fish"))
       return notify_fail("你要捉什么？\n");
    
   if (!(obj = present("gangcha", this_player())))
       return notify_fail("你想拿什么捉鱼？\n");

   if( me->query("jing") < 15)
       return notify_fail("你已经无法集中精力去捉鱼了。\n");

   this_player()->receive_damage("jing", 10);

   wait_catch();
   return 1;
}

