// /d/gaoli/fenghuotai
// Room in 山海关
// rich 99/04/05
inherit ROOM;
void create()
{
	set("short", "烽火台");
	set("long", @LONG
这里是长城的烽火台，古代以烽火报信，每当有敌军来侵犯的时候
就点燃起烽火向附近的军队报信，这个烽火台因为战乱以经荒废了。
LONG
	);
set("outdoors", "mayi");
set("valid_startroom", 1);
set("exits", ([
            	"northeast" : __DIR__"changcheng18",
            	"southup" : __DIR__"changcheng16",
	]));
       setup();
	replace_program(ROOM);
}
