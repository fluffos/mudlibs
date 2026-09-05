//石门
// for xiake dao
// modified by aiai 98/10/27

#include <ansi.h>

#include <command.h>
inherit ROOM;

string look_shimen();

void create()
{
    set("short",HIY"石门"NOR);
    set("long", HIC @LONG

    前面是一道"石门"，它通往侠客台的毕经之路，门上刻着三个斗大古棣：

      ■■■■■■■■■■■■■■■■■■■■■■■■■■■■
      ■                                                    ■  
      ■                                                    ■  
      ■                侠      客      行                  ■  
      ■                                                    ■
      ■                                                    ■  
      ■■■■■■■■■■■■■■■■■■■■■■■■■■■■
      ■■■■■■■■■■■□□‖□□■■■■■■■■■■■■
      ■■■■■■■■■□□□□‖□□□□■■■■■■■■■■
      ■■■■■■■■□□□□□‖□□□□□■■■■■■■■■
      ■■■■■■■■□□□□□‖□□□□□■■■■■■■■■
      ■■■■■■■□□□□□□‖□□□□□□■■■■■■■■
      ■■■■■■■□□□□□□‖□□□□□□■■■■■■■■

LONG  NOR
    );

    set("exits", ([
        "southeast" : __DIR__"lang2",
    ]));

    set("item_desc",([
        "石门"        :    (: look_shimen :),
    ]));
    setup();
}

void init()
{
    add_action("do_push","push");       
}
string look_shimen()
{
    object me;
    me = this_player();
    me->set_temp("石门/看",1);
    return "此石门为青石所筑，实为坚固，似乎不是常人能推(push)得开的。\n";
}

int do_push(string arg)
{
    object me;
    object *inv;

    me = this_player();
    if ((!arg) || (arg != "石门") || (! me->query_temp("石门/看")) )
        return 0;
    if ( me->query("combat_exp") < 1000000 )
        return notify_fail("唉！你的经验不够，看来无缘进入石室了。\n");
        
          if ( me->query_str() <= ( 20 + random(20) ) )
    {
        message_vision("$N用尽全身的力气试图推开石门，但大门却是纹丝不动。$N顿时感到气血翻滚，晕了过去。\n",me);
        me->unconcious();  
        me->delete_temp("石门/看");
        return 1;
    }
    else{
        message_vision(HIG"$N气沉丹田，用力一推，石门顿开。$N随即轻身一跃，进入石门，石门随即关上。\n"NOR,me);
        me->delete_temp("石门/看");
        inv = all_inventory(me);
        for(int i=0; i<sizeof(inv); i++) {
                if( (string)inv[i]->query("armor_type") != "cloth" || userp(inv[i]) )
                        DROP_CMD->do_drop(me, inv[i]);
        }
        
        me->move(__DIR__"shishi1");

        return 1;
    }
}

