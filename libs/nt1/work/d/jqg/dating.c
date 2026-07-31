// dating.c 大厅
// Modify By River 99.5.25
inherit ROOM;
#include <ansi.h>
void create()
{
            set("short",HIW"大厅"NOR);
            set("long",@LONG
这里是绝情谷的大厅，是公孙谷主会客的地方，大厅正前大梁上挂着一块
大匾(bian)，上面刻着四个龙飞凤舞的金字，异常气派。主人又特地在大匾之
下挂了一幅「白鹤鸣天」之图（hua)，画技精深，看得出其主特立独行的性格。
LONG
       );
            
           set("item_desc",([ "bian": HIY"    
          ※※※※※※※※※※※※※※※※※※※※
          ※※※※※※※※※※※※※※※※※※※※
          ※※※　                          ※※※
          ※※※   绝        情        谷   ※※※
          ※※※　                          ※※※    
          ※※※※※※※※※※※※※※※※※※※※
          ※※※※※※※※※※※※※※※※※※※※\n"NOR,
             "dao": "这是一条秘道。\n",   
             "hua": "这是一幅「白鹤鸣天」图，但是图后的墙上似乎有条通道。\n",
            ]));

            set("exits",([
               "out": __DIR__"shiwu",
            ]));
            set("objects",([
                 __DIR__"npc/gsz" : 1,
            ]));
            set("valid_startroom", 1);
            setup();
}

void init()
{
            add_action("do_xian","xian");
            add_action("do_enter","zuan");
            add_action("do_wa","jie");
}

int do_xian(string arg)
{
            object me = this_player();
            if(me->is_busy() || me->is_fighting())
                   return notify_fail("你正忙着呢！\n");
            if(!arg) return 0;
            if(arg =="hua"){
            message("vision",me->name() +"揭开图画，发现墙后有一条密道。\n", environment(me), ({me}));
            write("你揭起图画，发现墙后有一条密道(dao)。\n");
            me->set_temp("mark/揭",1);   
            return 1;
            }
            return notify_fail("你想干什么? \n");                    
}

int do_enter(string arg)
{
        object me = this_player();
        if(!arg || arg !="dao")
                return notify_fail("你往哪里钻？\n");
        if(me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着呢！\n");
        if(!me->query_temp("gsz_agree"))
                return notify_fail("这里是绝情谷的禁地，没有庄主的命令，外来弟子不能进入！！\n");
        if((int)me->query_temp("mark/揭")){
          message("vision", me->name() + "弓身钻进密道。\n", environment(me), ({me}));
          tell_object(me,"你弓身钻进密道。\n");
          me->move(__DIR__"houtang");
          message("vision",me->name() +"弓身从密道中钻了过来。\n", environment(me), ({me}));
          me->delete_temp("mark/揭");
          return 1;
          }
      return notify_fail("没事你乱钻什么？ \n");
}

int do_wa(string arg,object ob)
{
        object weapon,me=this_player();
        if(!me->query_temp("jqg/chi")) return 0;
        if( !arg || arg !="zhuan")
               return notify_fail("你乱揭什么啊？\n");
        if(!weapon=(me->query_temp("weapon")))
               return notify_fail("你准备用手揭接开青砖么？\n");        
        if(me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着呢！\n");
        ob=new(__DIR__"obj/jqdan");
        if(!clonep(ob))
           return notify_fail("你来晚了，绝情丹已给别人拿走了。\n");  
if (this_object()->query("aget")>2)
{
           destruct(ob);
           return notify_fail("你来晚了，绝情丹已给别人取走了。\n");
           }
        if(clonep(ob) && ob->violate_unique()){
           destruct(ob);
           return notify_fail("你来晚了，绝情丹已给别人取走了。\n");
           }
        tell_object(me,"你数到第五块青砖，拔出腰间"+weapon->name()+"，从砖缝中插入，揭起砖块，发现下面的绝情丹。\n");
        message("vision", me->name() + "拔出腰间"+weapon->name()+"，从砖缝中插入，揭起砖块。\n", environment(me), ({me}));
        me->delete_temp("jqg/chi");
        this_object()->add("aget",1);
        ob->move(me);
        return 1;
}

