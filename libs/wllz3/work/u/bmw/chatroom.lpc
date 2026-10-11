//逍遥聊天房间

#include <ansi.h>;

inherit ROOM;

void create()
{
        set("short","$HIR$【商议室】$NOR$");
        set("long", @LONG
 $CYN$     _.------.__
      /'           ``~\_ 
   /~'   //             `\
  /     (   _ //\// _  )  ) 
 (     /  /' `    /' `  //   
 (    )`(/  $HIC$ o$NOR$$CYN$)  (   $HIC$o$NOR$$CYN$)\/$HIM$
 \ (  -'        /)     )    
 \ \ (         '~      ) 
  \  (      /__.-.-._, /
   ) \`-)   `\ $HIR$~~~$HIM$,/  /'
  `\_.-~ \    `$HIR$~~~$HIM$   /
     /    `\._     /'
    /        /`--~'
   `-.__    /
        `~~'  $NOR$     
LONG
);

        set("exits", ([
                "out" : "/u/bmw/shuifang",
                "enter" : "/u/bmw/room",
        ]));
        setup();
        replace_program(ROOM);
}