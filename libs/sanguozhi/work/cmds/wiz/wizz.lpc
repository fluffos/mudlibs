// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */
// product du Belboz/Rust
#include <mudlib.h>
#include <move.h>
inherit CMD;
string* MSGS;
create()
{
    MSGS =      ({
    "贼眉鼠眼阿拉丁神灯巨人",
    "黄巾力士",
    "阿帕齐战斗直升机",
    "国产长征三型火箭",
    "一辆深蓝色劳斯莱斯轿车",
    "长街虎虎生风的一巴掌",
    "云儿脉脉含情的一个吻",
    "烈火的火焰",
    "泰坦尼克号",
    "浪迹天涯的深情目光",
    "红鼻子列车",
    "奇奇号巡洋舰",
    "阿洛一个大脚",
    "玄冰的碎片",
    "贝克舒塔的五角飞碟",
   
  });
}
private void main( string arg )
{
    object      start_room;
    string      name;
    start_room = environment( this_body() );
    name        = this_body()->query_name();
    if( WIZ_ROOM == file_name(start_room))
    {
        this_body()->simple_action("$N感到有点头晕目眩。");
        return;
    }
    if(!arg)
        arg = MSGS[random(sizeof(MSGS))];
    if( this_body()->move( WIZ_ROOM ) != MOVE_OK)
    {
      out( "你压根没动耶。\n" );
        return;
    }
    this_body()->force_look();
    outf("你被%s送回到巫师大厅！\n", arg );
    if( name == "Someone" )
        return;
    tell_from_inside( start_room, sprintf( "%s被%s送走了！\n",
        name, arg ) );
    tell_environment( this_body(),
      sprintf( "%s被%s送了回来！\n", name, arg ), 0, ({this_body()}) );
    return;
}
