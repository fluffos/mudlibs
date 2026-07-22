#include <under.h>
inherit ROOM;
int gold = 1;
int wood = 1;
int water = 1;
int fire = 1;
int soil = 1;
 
void create()
{
        ::create();
  set_short("参军寝室");
  set_long( @CLong
你走进了将军寝室，这儿乱得让人吃惊。虽然只有木床和一张小木桌(desk)，但
你眼光所及之处，都堆满了各种书籍、竹简和文具。三面墙上分别贴著东方大陆的地
图、地道施工计画图和一张星象图，上面还画著不少难以看懂的线条和记号。你觉得
这儿的主人应该是个学问渊博而不修边幅的人。
CLong
);
set("light",1);
set("c_item_desc",([ "desk":"@@to_desk" ]) );
set("search_desc",([ "desk":"@@search_desk" ]) );
set("exits",([
               "east": UNDER "room01"
             ]));
reset();
}
 
string to_desk()
{
    return "一张小木桌，上面堆满了书籍、纸张、竹简、设计图和文具。\n";
}
string search_desk()
{
        object obj;
        int r;
        if(this_player()->query_temp("under") < 2) return
          "这桌上乱七八糟的....你实在不知从何找起.....\n";
        if( gold==0 && wood==0 && water==0 && fire==0 && soil==0) return
          "你找遍了所有的东西, 却怎麽也找不到任何东西像是扬心说的法器。\n";
 
        r = random(5);
 
        if( r == 0 ) {
          if ( gold == 1 && !present("gold", this_object()) ) {
          obj = new( OBJS"symbol5" );
          obj->move( this_object() );
          gold = 0;
          return "\n你东翻西找..终於在一个写著『金』的匣子里找到了一张符纸。\n";
          }
          else {
          return "\n你找到一个上头写的『金』的木匣子，但是里面是空的。\n"; }
        }
 
        if( r == 1 ) {
          if ( wood == 1 && !present("wood", this_object()) ) {
          obj = new( OBJS"symbol4" );
          obj->move( this_object() );
          wood = 0;
          return "\n你东翻西找..终於在一个写著『木』的匣子里找到了一张符纸。\n";
          }
          else {
          return "\n你找到一个上头写的『木』的木匣子，但是里面是空的。\n";}
        }
 
        if( r == 2 ) {
          if ( water == 1 && !present("water", this_object()) ) {
          obj = new( OBJS"symbol2" );
          obj->move( this_object() );
          water = 0;
          return "\n你东翻西找..终於在一个写著『水』的匣子里找到了一张符纸。\n";
          }
          else {
          return "\n你找到一个上头写的『水』的木匣子，但是里面是空的。\n";}
        }
 
        if( r == 3 ) {
          if ( fire == 1 && !present("fire", this_object()) ) {
          obj = new( OBJS"symbol1" );
          obj->move( this_object() );
          fire = 0;
          return "\n你东翻西找..终於在一个写著『火』的匣子里找到了一张符纸。\n";
          }
          else {
          return "\n你找到一个上头写的『火』的木匣子，但是里面是空的。\n";}
        }
 
        if( r == 4 ) {
          if ( soil == 1 && !present("soil", this_object()) ) {
          obj = new( OBJS"symbol3" );
          obj->move( this_object() );
          soil = 0;
          return "\n你东翻西找..终於在一个写著『土』的匣子里找到了一张符纸。\n";
          }
          else {
          return "\n你找到一个上头写的『土』的木匣子，但是里面是空的。\n";}
        }
}
