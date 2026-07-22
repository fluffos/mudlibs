#include <../under.h>
inherit WEAPON;
 
void init()
{
        add_action( "dig_ground", "dig" );
}
 
 
void create()
{
        seteuid(getuid());
        set_name("spade", "圆锹");
        add ("id",({ "spade" }) );
        set_short("圆锹");
        set_long(
"一把圆锹，应该可以用来挖(dig)土。\n"
        );
        set( "unit", "把" );
        set( "weapon_class", 5 );
        set( "type", "axe" );
        set( "min_damage", 6 );
        set( "max_damage", 12 );
        set( "weight", 100 );
        set( "value", ({ 200, "silver" }) );
}
int dig_ground(string arg)
{
    if( !arg || arg != "ground" )
    return notify_fail("挖那里？\n");
    if ((string)environment(this_player())->query("short")=="废坑道" ) {
             tell_object(this_player(),set_color(
    "当你的铲子插入土中的那一刹那，整个坑道都随之剧烈震动......\n\n"
    "无数耀目的光线从土中夹杂著沙石激射而出......\n\n","HIY" ));
    this_player()->set_temp("block_command",1);
    call_out("recover",5,this_player());
    } else
    tell_object(this_player(),
    "你把这里的地面挖得坑坑巴巴的，但是什麽都没发现。\n" );
    tell_room(environment(this_player()), this_player()->query("c_name")+
    "拿著一把铲子把这里挖得坑坑巴巴的, 不知在找什麽..\n",
    ({ this_player() }) );
    return 1;
}
int recover(object player)
{
    object monster;
 
    player->set_temp("block_command",0);
    write (
    "飞沙走石之後，你定神一看，原来大家口中的食金兽竟是一只...龙?!......\n\n"
    "你低头看著手中只剩木柄的铲子，惊愕地顺手丢掉......\n");
    monster= new( MOB"dragon" );
    monster->move( environment( this_player() ) );
    this_object()->remove();
    return 1;
}