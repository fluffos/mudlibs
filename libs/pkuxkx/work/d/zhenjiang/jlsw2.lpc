//Zine 
#include <ansi.h>
inherit ROOM;
#include "/d/menggu/entry_migong.h"
void create()
{
        set("short", "隐蔽小路");
        set("long", @LONG
这是一条小路，不仔细看根本发现不了，东面进入深山，西面通往建康府。
LONG
        );
        set("exits", ([
               //"southwest" : __DIR__"guandaosd2",
               "west" : "/d/yingtiansouth/tulue2",
               //"southeast" : __DIR__"tulue3",
               //"northeast" : __DIR__"tulune1",
               "eastup" : __DIR__"jlsw1",
        ]));
		set("no_task",1);
        set("outdoors", "yingtianfu");
		set("entry_direction","eastup");
		set("migong","/d/zhenjiang/jilong");
		set("migong_posi","west");
		set("look_refuse_msg","鸡笼山被官府征用，此刻平民禁入。\n");
		set("enter_refuse_msg","鸡笼山被官府征用，此刻平民禁入。\n");
        setup();
        
}

