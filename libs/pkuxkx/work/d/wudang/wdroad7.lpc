// wdroad7.c 黄土路
// by Xiang
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "黄土路");
	set("long", @LONG
	你走在一条尘土飞扬的黄土路上，两旁是阴森森的树林。这里是湖北境界，
据说经常有土匪出没，不可久留。
LONG
	);
	set("no_sleep_room", 1);
	set("main_dir", __DIR__"");
	set("no_clean_up", 0);
	set("realmap", "                                               
                                    
                 黄土路----[1;32m黄土路[2;37;0m----黄土路    
                             ↓     
                          林中小路             
");
	set("exits", ([ /* sizeof() == 3 */
		  "east" : __DIR__"wdroad6",
		  "west" : __DIR__"wdroad8",
		  "southup" : __DIR__"tufeiwo1",
		]));
	set("outdoors", "wudang");
	setup();
//	replace_program(ROOM);
}
int valid_leave(object me,string dir)
{
	if (!wizardp(me) && objectp(present("tufei",environment(me))) && random(6)<5)
	return notify_fail("土匪把路一挡，狞笑道：怎么，想溜，没那么容易！\n");
	me->delete_temp("meeting");
	return ::valid_leave(me,dir);
}
