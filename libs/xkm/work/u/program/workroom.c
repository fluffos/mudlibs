#include <ansi.h>
#include <room.h>
 inherit ROOM;

void create()

{
      set("short",HIB"浪子轩"NOR);
      set("long",WHT
"你发现里边凌乱不堪，显然这个人没有女朋友,自己也不知道收拾,
破旧的天花板上,一个破灯泡在空中晃来晃去，西边靠窗的地方一张桌子，
乱七八糟的放着些书.
偶尔有风吹过，门发出吱吱嘎嘎的声音，
唯一让人感到温暖的是：
夕阳！！！就像情人的手，抚摸着这个小屋。
主人不知道哪里云游去了,留在这里的，却是他心中的归宿！\n"NOR
);
        set("exits",([
          "wc" : "/u/program/wc",
        "wz":"/d/wizard/meeting_room",
         "cs":"/d/city/guangchang",
                ]));
        set("objects", ([ 
        "/u/program/npc/langzi.c" : 1,
         ]) );

        set("cost", 1);
//      set("no_fight",1);
      set("sleep_room",1);
   setup();;  "/clone/board/program_b"->foo();
//     replace_program(ROOM);
}
