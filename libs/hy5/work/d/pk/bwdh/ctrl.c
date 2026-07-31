// 控制室 ctrl.c
// By River 99/04/15
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short",HIW"控制台"NOR);
        set("long", @LONG
这里是书剑组队比赛的巫师控制室，你能看见众多巫师急急忙忙地在干些
什么。正中央放着一张很大的控制台，上面标示着一排按钮，最为明显的是一
个红色的按钮（anniu)，不知道按下去是什么结果。
LONG
        );

        set("exits", ([
                "down" : "/d/wizard/wizard_meet",
        ]));

        set("no_fight",1);
        setup();
}

void init()
{
        add_action("do_push", "an");
}

void check_trigger()
{
       object room;
       object thisroom = this_object();
       if(!(room = find_object(__DIR__"xiuxishi2")))
             room = load_object(__DIR__"xiuxishi2");
       if( room = find_object(__DIR__"xiuxishi2")){
         if( !room->query("exits/enter")){
                 room->set("exits/enter", __DIR__"gate");                 
                 message("vision", HIR"只听见轰然一声，试剑山庄南休息室的大门被打开了。\n"NOR, thisroom);
                 message("vision", HIW"只听见咯吱一声，休息室的大门被打开了，外面就通向试剑山庄了。\n"NOR, room);
                 remove_call_out("close");
                 call_out("close", 100); 
                 }
                else message("vision", HIW"试剑山庄南休息室的大门已经被打开了，再按也没有用了。\n"NOR, thisroom);
           } 
          else message("vision", "ERROR: Room 2 not found\n", thisroom);          
}

void check_trigger1()
{
       object room1;
       object thisroom = this_object();
       if(!(room1 = find_object(__DIR__"xiuxishi1")))
             room1 = load_object(__DIR__"xiuxishi1");
       if( room1 = find_object(__DIR__"xiuxishi1")){
         if( !room1->query("exits/enter")){                 
                 room1->set("exits/enter",__DIR__"houting");
                 message("vision", HIR"只听见轰然一声，试剑山庄北休息室的大门被打开了。\n"NOR, thisroom);
                 message("vision", HIW"只听见咯吱一声，休息室的大门被打开了，外面就通向试剑山庄了。\n"NOR, room1);
                 remove_call_out("close1");
                 call_out("close1", 100); 
                 }
                else message("vision", HIW"试剑山庄北休息室的大门已经被打开了，再按也没有用了。\n"NOR, thisroom);
           } 
          else message("vision", "ERROR: Room 1 not found\n", thisroom);          
}

void close()
{
        object room;
        if( room = find_object(__DIR__"xiuxishi2"))
        room->delete("exits/enter");        
        message("vision", HIW"只听见咯吱一声，休息室的大门又被关上了。\n"NOR, room);
}

void close1()
{
        object room1;
        if( room1 = find_object(__DIR__"xiuxishi1"))
        room1->delete("exits/enter");
        message("vision", HIW"只听见咯吱一声，休息室的大门又被关上了。\n"NOR, room1);
}

int do_push(string arg)
{
       object me;
       me = this_player();       
       if (userp(me) && !wiz_level(me))
          return notify_fail("你不是巫师，不要随便乱动，坏了你可赔不起哦！\n");
       if (!arg || arg !="anniu")
          return notify_fail("你要按什么？\n");
       if (arg == "anniu"){
           message_vision(HIR"$N轻轻嘘了口气，提起食指慢慢地按动了按钮。\n"NOR, me);
           check_trigger();
           check_trigger1();
           return 1;
           } 
          return notify_fail("你要按什么？\n");
}
