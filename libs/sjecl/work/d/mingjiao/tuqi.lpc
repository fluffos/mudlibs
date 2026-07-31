// tuqi.c 厚土旗
// Modify By River@SJ 99.06
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short",YEL"厚土旗"NOR);
       set("long", @LONG
这里是厚土旗。这里有各种各样的窟土工具，旗中弟子一个个短小而精悍，
练就一身窟土功夫，他们在教中累立奇功。四周是明教其它四行旗，五旗互成
倚角之势。
LONG);    
	set("exits", ([
                "south" : __DIR__"zl6",
		"east" : __DIR__"longwang",
                "west" : __DIR__"didao/senlin-5",
	]));
	set("objects",([
		__DIR__"npc/dizi2" : 3,
                CLASS_D("mingjiao") + "/yan" : 1,
	]));
        set("outdoors", "明教光明顶");
        set("coor/x",-250);
  set("coor/y",260);
   set("coor/z",120);
   set("coor/x",-250);
 set("coor/y",260);
   set("coor/z",120);
   setup();
}
