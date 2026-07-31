// Room: /d/cangzhou/fuya.c

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "沧州府衙");
        set("long", @LONG
这里是衙门大门，两扇朱木大门紧紧关闭着。“肃静”“回避”的牌子分
放两头石狮子的旁边。前面有一个大鼓，显然是供小民鸣冤用的。几名衙役在
门前巡逻。
LONG );
        set("exits", ([
        	"east" : __DIR__"beijie2",
		"west" : __DIR__"zhenting",
	]));
        
	set("objects", ([
                __DIR__"npc/yayi.c" : 2,
      	]));
	setup();
}

int valid_leave(object me, string dir)
{
        if (!wizardp(me)
         && objectp(present("ya yi", environment(me)))
         && dir == "west")
           return notify_fail(CYN"衙役喝道：“你是谁？快快离开这里。”\n"NOR);
        return ::valid_leave(me, dir);
}
