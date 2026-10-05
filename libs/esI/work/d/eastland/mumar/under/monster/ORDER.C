#include <../under.h>
inherit MONSTER;
 
void create ()
{
        ::create();
    set_level(15);
    set_name("order","传令兵");
    add ("id", ({ "order" }) );
    set_short( "传令兵");
        set_long( @C_LONG
你看到的是一个体格相当不错的传令兵，他正瞪著你，似乎不太欢迎你。
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
        "传令说:这儿不是你该来的地方，快离开吧,不然我要报告长官罗。\n"
       }) );
    set( "att_chat_output", ({
         "传令轻笑著道:闲著也是闲著!!就跟你这个刁民玩玩吧!!。\n"
        }) );
 
    equip_armor(OBJS"mail01");
    wield_weapon(OBJS"javelin");
}
void die()
{   object killer;
 
    killer = query("last_attacker");
    if( killer ) killer->set_temp("under/killer",1);
    tell_room(environment(this_object()),
@DIE
传令兵奸笑一声: 你一定会有报应的.......嘿嘿嘿......
 
DIE
,this_object());
   ::die(1);
}
