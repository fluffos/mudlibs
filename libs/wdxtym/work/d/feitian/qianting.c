// Room: dongwuchang.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 

inherit ROOM;

void init();
int do_da(string);
int do_ci(string);

void create ()
{
  set ("short", "前庭");
  set ("long", @LONG
这是一个宽敞的前庭，不过并不像其他居室种了些花花草草，到处都是练
武的器具，一个身形矮小的人正在拿竹剑劈木人。你可以拿把剑跟他一起
(ci)木人做练习。右边有个大沙包，你很想用力一拳打(da)过去。向前是
一个走廊。
LONG);

  set("area", "飞天御剑流");
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"damen",
  "north" : __DIR__"zhongting",
  "east" : __DIR__"xiulianshi",
  "west" : __DIR__"kongdi",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/miyan" : 1,
]));

  setup();

}
int valid_leave(object me, string dir)
{
        if ((!(string)me->query("family") || (string)me->query("family/family_name") != "飞天御剑流") 
               && ( dir == "north")
              && (objectp(present("mi yan", environment(me)))
               || objectp(present("mi yan", environment(me))) ))
               {  if (objectp(present("mi yan", environment(me)))) 
               
                       return notify_fail("弥彦说道：你不是道场弟子，请回吧。\n");
        }

        return ::valid_leave(me, dir);
}

void init()
{
        add_action("do_da", "da");
        add_action("do_ci", "ci");
}

int do_da(string arg)
{
        object me;
        int jingli_cost;
        int qi_cost;

        me = this_player();

        if ( !arg || ( arg != "shabao" ) )
                return notify_fail("你想干什么？\n");
        me->add("qi",-10);

        if ( me->query("qi") <= (10) )
                return notify_fail("你太疲劳了，没有精力去练功了。\n");

        message_vision("$N摆好架势，一拳向沙包打去。\n", me);

        if ( me->query_skill("parry", 1) < 5 )  
        {
                message_vision("$N根本不会格斗，打得手都麻了。\n", me);
   		
        } else if ( me->query_skill("parry", 1) < 20 )
        {
                message_vision("$N把沙包打得晃来晃去。\n", me);
        } else 
        {
                message_vision("嘣的一声，沙包被$N打得飞了起来。\n", me);
        }
 
        if ( me->query_skill("parry", 1) < 30)
        {
                me->improve_skill("parry", me->query("int"));
                me->set_temp("hitted",1);
        }
        if ( me->query_skill("parry",1) >= 30 )
        { 
                write("你一下就把沙包打穿了，沙子落的你满身都是！\n");
        }
        return 1;
}

int do_ci(string arg)
{
        object me;
        int jing_cost;
        int qi_cost;

        me = this_player();

        if ( !arg || ( arg != "muren" ) )
                return notify_fail("你想干什么？\n");
        
        me->add("qi",-10);

        if ( me->query("qi") <= (10) )
                return notify_fail("你太疲劳了，没有精力去练功了。\n");

        message_vision("$N捏个剑诀，一剑向木人刺去。\n", me);

        if ( me->query_skill("sword", 1) < 5 )  
        {
                message_vision("$N根本不会剑法，剑和木人只是轻碰了一下。\n", me);
   		
        } else if ( me->query_skill("sword", 1) < 20 )
        {
                message_vision("$N看准木人的移动，一剑刺在木人的要穴上。\n", me);
        } else 
        {
                message_vision("$N随手一剑，已经刺中木人的要害了。\n", me);
        }
 
        if ( me->query_skill("sword", 1) < 30)
        {
                me->improve_skill("sword", me->query("int"));
                me->set_temp("hitted",1);
        }
        if ( me->query_skill("sword",1)>= 30 )
        { 
                write("你一下就把木人刺倒了，看来刺木人对你没什么作用了！\n");
        }
        return 1;
}



