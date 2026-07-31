// 高丽人参 /d/city/chuzhou/npc/obj/gaoli_renshen.c
// by lala, 1997-12-13

#include <ansi.h>

inherit ITEM;

int do_eat( string arg );

void create()
{
        set_name( RED"高丽"YEL"人参"NOR, ({"gaoli renshen", "renshen", "corean ginseng", "ginseng" }));
        set_weight(200);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", @LONG
这是一枝名贵的高丽人参，大约有四两重。高丽人参作为名贵的药材被中医认为
是特效良药，有大补的功效，且据说对于垂危的病人，可以起“吊”命的作用。
LONG
    );
                set("unit", "枝");
                set("value", 160000);
        }
        setup();
}

void init()
{
    add_action("do_eat", "eat");
}    

int do_eat( string arg )
{
    object me = this_player();
    if( !arg ||
       ( arg != "gaoli renshen" 
      && arg != "renshen"
      && arg != "corean ginseng"
      && arg != "ginseng"
      ))
        return 0;
    me->set("sen", me->query("eff_sen") );
    if( me->query("eff_kee") != me->query("max_qi") )
        me->add("eff_kee", ( me->query("max_qi")-me->query("eff_kee") )/2 );
    if( ( me->query("qi") + 100 ) > me->query("eff_kee") )
        me->set("qi", me->query("eff_kee"));
    else
        me->add("qi", 100);
    me->set("gin", me->query("max_gin") );
    me->add("force", 25);
    message_vision(YEL"$N吃下一枝高丽人参，只觉得全身发热，充满了活力！\n"NOR, me );
    destruct(this_object());
    return 1;
}
