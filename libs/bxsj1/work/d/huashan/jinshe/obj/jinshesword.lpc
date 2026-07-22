// Room: /d/huashan/jinshe/obj/jinshesword.c
// Date: Look 99/03/25

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name(HIY"金蛇剑"NOR,({ "jinshe sword", "sword" }) );
        set_weight(80000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 1);
                set("rigidity", 8);
		set("sharpness", 8);
                set("material", "steel");
                set("weapon_prop/dodge", 20);
                set("weapon_prop/parry", 20);
                set("treasure",1);
                set("long", "这把剑犹如一条盘蛇，剑光灿灿，甚为沉重 。\n剑身上一道血痕，发出碧油油的暗光，极是诡异。\n");                
                set("unwield_msg", HIY "$N随手一挥，手中金蛇剑已不见踪影。姿态潇洒无比。\n" NOR);
                set("unequip_msg", HIY "$N随手一挥，手中金蛇剑已不见踪影。姿态潇洒无比。\n" NOR);
        }
        init_sword(80);
        setup();
}

void init()
{
    add_action("do_wield","wield");
}

int do_wield(string arg)
{
     object me,ob;

     me = this_player();
     ob = this_object();

      
      if( !arg ) return 0;
      if(arg == "jinshe sword" || 
         arg == "sword") {      
        if((int)me->query("max_neili", 1) < 1200 ||
           (int)me->query("neili", 1) < 300  ){
           tell_object(me,"你感觉全身气息翻腾，原来你内力不够，提不起金蛇剑。\n");
           return 1;
           }
        if((int)me->query_str() < 24){
           tell_object(me,"你想举起金蛇剑，怎奈力量不够，只好作罢。\n");
           return 1;
           }
        ob->wield();
        message_vision(HIY"$N微一舞动，一道耀眼的金光绕着$N全身上下游走，光芒顿住，$N手中
已多了柄弯弯曲曲的奇形宝剑。剑身的寒光映照出$N脸上浮现出诡异神情。\n"NOR, me);
        me->add("neili", -100);
        return 1;
        }
}