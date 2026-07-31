//zongtai 总台

#include <ansi.h>
#include <room.h>

inherit ROOM;
void create()
{
        set("short",HIR"试剑山庄"NOR);
        set("long", @LONG
        /J_____________________L\                        
            /|||||||||||||||||||||||||\                      
        {\/LLLLLLLLLLLLLLLLLLLLLLLLLLLLLL\/}          
         ^^^^||^^^^ 【试剑山庄】 ^^^||^^^^   
          /|||||||||||||||||||||||||||||\
          ^^^||^^◎^^◎^^  ^^◎^^◎^||^^^
             ||       出场队伍      ||
             ||1.流氓四人组         ||  
             ||2.等我老公来取       ||
             ||3.神风特攻队         ||
   I-I-I-I-I-||_________||__________||-I-I-I-I-I
  /__|__|__|__|__|_______________|__|__|__|__|__\
 /__|__|__|__|__||_______________|_|__|__|__|__|_\
LONG
        );
        set("exits", ([        
        "1" : __DIR__"kantaie",
        "2" : __DIR__"kantaiw",
        "up" : "/d/city/guangchang",
        
        ]));
        
        set("no_fight", "1");
        set("no_sleep_room", 1);
        setup();
}

