#include <ansi.h>
inherit ROOM; 
void create() 
{ 
        set("short", "始皇陵"); 
        set("long", @LONG 
    这是座落在官道以东的一个大丘陵，呈覆斗型。站在丘陵上极目远眺，不禁心旷神
怡。旁边有一座高大的石碑：
LONG); 
	set("long2","\n                   "REV HIY"       "NOR HBYEL HIY"`"NOR"
                   "REV HIY"   秦  "NOR REV YEL" "NOR"
                   "REV HIY"   始  "NOR REV YEL" "NOR"
                   "REV HIY"   皇  "NOR REV YEL" "NOR"
                   "REV HIY"   陵  "NOR REV YEL" "NOR"
                   "REV HIY"       "NOR HBYEL HIY"_"NOR"
                  "REV YEL"          "NOR"\n\n");
        set("virtual_room", 1); 
        set("no_magic",1);
        set("no_fight",1);    
        set("exits", ([
                "east" : __DIR__"maze/entry", 
                "west" : "/d/eastway/bingma",
        ])); 
        setup();
} 