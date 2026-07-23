#include <ansi.h>
#include "place.h"

void init()
{
    object me = this_player();
    tell_object(me,"你可以通过("+HIR"look gaoshi"NOR+")，得知有没新的变化。\n");
    add_action("do_jie", ({"jie"}));    
}

int do_jie(string arg)
{
    object me, ob, wsh;
    mapping weizhis, target;
    int exp, position;
    me = this_player();
    exp = (int)me->query("combat_exp");

    if( !arg ) return 0; 
    
    if( arg!="wenshu" && arg != "wen" ) return 0;

    if( exp < 50000 )
        return notify_fail(HIR"[官府]"NOR+":你刚想伸手，忽然看到上面凶神恶煞的画像，想了想觉得自己的这点功夫，还是算了吧。\n");

    if( me->query("mieyao") )
        return notify_fail(HIR"[官府]"NOR+":你现在正忙着做其他任务呢！\n");

    if( time()-me->query("mieyao_time") < 60+10*me->quary_temp("mieyao/level") )
        return notify_fail(HIR"[师门]"NOR+":还是先休息一下,也怪累着呢！\n");

    if( time() < me->query("gf_time")+150 && !wizardp(me) )
        return notify_fail(HIR"[官府]"NOR+":你发现文书已经被人揭光了，看样子要等一会了！\n");
    
    me->delete_temp("guanfu_target");
    me->delete_temp("guanfu_time");
    me->delete_temp("guanfu_target");
    me->delete_temp("ch_weizhi");
    me->delete_temp("path_rooms");
    me->delete_temp("gstart_rooms");
    me->delete_temp("mark/gkill1");
    me->delete_temp("mark/gkill2");
    me->delete_temp("mark/gkill3");
    me->delete_condition("gf_busy");   

    if( wsh=present("wenshu", me) )
    {
        destruct(wsh);
        tell_object(me,HIR"[官府]:"NOR+"算了，原来的不想做，我这里收回啦！\n");
    }

    target = quest[random(sizeof(quest))];
 
    if( exp >= 580000 )
    {
        tell_object(me,HIR"你推开围观的行人，走到近前,微微睁开眼睛，冷冷瞥了一眼告示，随手揭了下来揣进了怀中。\n"NOR);
    } 
    else if( exp <= 120000 )
    {
        tell_object(me,HIY"你壮了壮胆，费力拔开行人，来到近前深深吸了口气，竭力镇定一下紧张的心情，四下看了看，悄悄把文书揭了下来。\n"NOR);
    } 
    else 
    {
        tell_object(me,WHT"你分开行人来到近前，目光淡淡的扫视了几眼告示，嘴角微微一翘，神态自如的把文书揭了下来。\n"NOR);
    }
    
    if( !target ) target = quest[random(sizeof(quest))]; 
    if( !weizhis ) weizhis = wheres[random(sizeof(wheres))];
        
    me->set_temp("mark/gkill1",1);
    me->set_temp("guanfu_target", target["name"]);
    me->set_temp("path_rooms", target["where"]);
    me->set_temp("gstart_rooms", weizhis["weizhi"]);
    me->set_temp("ch_weizhi", weizhis["chinese"]);
    new(__DIR__"wenshu")->move(me);
    ob = new(me->query_temp("path_rooms"));
    ob->move(me->query_temp("gstart_rooms"));
    //固定对象
    ob->set("id2",me->query("id"));
    ob->set("name2",me->query("name"));
    ob->copy_status(ob,me,2);
    me->set_temp("mark/combat_exp", me->query("combat_exp"));       
    me->set("gf_time", time());       
    return 1;
}


