#include <../under.h>
inherit MONSTER;
 
void create ()
{
        ::create();
    set_level(15);
    set_name("Mumar guard","密道守卫");
    add ("id", ({ "guard" }) );
    set_short( "密道守卫");
        set_long( @C_LONG
你看到的是一个体格相当不错的卫兵，他正直挺挺地站在这儿看守著密道。
C_LONG
        );
    set("alignment",500);
    set( "gender", "male" );
    set( "unit", "个" );
    set_perm_stat( "str",  20);
    set_perm_stat( "int",  10);
    set_skill("longblade",80);
    set_skill("parry",80);
    set ("max_hp",375);
    set ("hit_points",375);
    set ("wealth", ([ "silver":200]) );
    set_natural_weapon(10,15,20);
    set_natural_armor(55,10);
    set ("weight", 350);
    set("chat_chance",5);
    set("chat_output",({
        "守卫说:这儿不是你该来的地方，快离开吧,不然我要报告长官罗。\n"
       }) );
    set( "att_chat_output", ({
         "守卫轻笑著道:闲著也是闲著!!就跟你这个刁民玩玩吧!!。\n"
        }) );
 
    equip_armor(OBJS"mail01");
    wield_weapon(OBJS"javelin");
}
