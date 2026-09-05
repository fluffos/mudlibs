// 冰崖
// by steel
#include <ansi.h>
int storm(object me);
inherit ROOM;

void create()
{
	set("short", "冰崖");
	set("long", @LONG
冰崖之上,朔风如刀,吹得你脸上生疼。崖上光秃秃的，似乎什么
都没有。仔细一看，冰崖的中央有一块大石，好象不是天然生成的。
LONG
	);
        set("objects",([
             __DIR__"obj/bigstone" : 1,
             ]) );
  set("item_desc",([
  	"hole": "这个孔里原本似乎放着一把刀，如果插入合适的刀也许可以转动石头。\n",
  ]));
	setup();

}
void init()
{
	object ob;
	if( interactive( ob = this_player()))
	storm(ob);
  	add_action("do_climb","climb");
 }

int do_climb(string arg)
{
    object me;
    object obj;
    int dodge;
    me=this_player();
    if(!arg) return 0;
     if(arg!="down")
         return notify_fail("你要爬什么？\n");
    message_vision(HIB"$N抓紧冰崖间的石缝, 开始艰难的向下爬去。\n"NOR,me);
    dodge=me->query_skill("dodge",1);
    if(objectp(obj = me->query_temp("armor/boots")))
    {
      if(obj->query("id")=="snow boots")
       {
        if(dodge>80){
            me->add("jing",-80);
            me->add("qi",-80);
            tell_room(__DIR__"hill2",me->name()+"平安的从上面爬了下来。\n");
            me->move(__DIR__"hill2");
            tell_object(me,  "冰山靴几经磨损终于坏掉了。\n");
            obj->unequip();
            destruct(obj);
            return 1;
          }
      else
       {
       		me->start_busy(2);
            if(dodge<=60)
             {
               call_out("to_die",2);
               return 1;
             }
             else
             {
               call_out("to_yun",2);return 1;
              }
       }
     }
    }
    else
    {
    	me->start_busy(5);
      if(dodge<=60)
             {
               call_out("to_die",5);
               return 1;
             }
             else
             {
               call_out("to_yun",5);
               return 1;
             }
    }
}

void to_die()
{
     message_vision(HIR"不好!$N手上一滑,从半空中摔了下来。\n"NOR,this_player());
     this_player()->receive_damage("qi", 0, "摔下冰崖");
     this_player()->die();
}
void to_yun()
{
     message_vision(HIR"不好!$N手上一滑,从半空中摔了下来。\n"NOR,this_player());
    this_player()->move(__DIR__"hill2");
     this_player()->unconcious();
//     this_player()->move(__DIR__"hill2");               //移到前面去，否则晕了该行就无效   boost
}

int storm(object me)
{
	int i, flag;
	object *inv;
    int qi = me->query("qi");

    inv = all_inventory(me);
    for(i = 0; i < sizeof(inv); i++)
    {
        if(inv[i]->query("id") == "pi qiu" && inv[i]->query("equipped"))
        flag = 1;
    }

	if( environment(me) == this_object())
	{
        if( !flag )
        {
            tell_object(me, HIR"\n一股刺骨的寒风吹过，你只觉得浑身的血液都快被冻住了！\n"NOR);
            write("看来不穿一件保暖的外衣，一定会被冻死的！\n");
            me->start_busy(1);
            me->receive_damage("qi", 10 + random(50), "冻");
            me->receive_wound("qi", 10 + random(20), "冻");
            if( environment(me) == this_object())
                call_out("storm", 5 + random(5) , me);
        }
        else
            tell_object(me, HIC"\n一股刺骨的寒风吹过，你将皮裘裹得更加严实了！\n"NOR);
	}
        return 1;
}
