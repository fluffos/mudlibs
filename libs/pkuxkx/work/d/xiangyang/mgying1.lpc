inherit ROOM;
void create()
{
	set("short", "蒙古营门");
set("outdoors","menggu");
	set("long", @LONG
 这里是蒙古大军的军营门，门口戒备森严，一名威风凛凛的大将带着
几个军兵在来回巡逻。此处乃是非之地不可久留，还是快走的好。
LONG
	);

	set("exits", ([
		"south" : __DIR__"mgbao2",
		"north" : __DIR__"mgying2",          
	]));

	set("objects", ([
		__DIR__"npc/mgjiang1" : 1,
	        __DIR__"npc/mgjun" : 4,
        ]));

	setup();
}

int valid_leave(object me, string dir)
{        
int i;
mapping armor;
string *pname;
armor=me->query_temp("armor");
if (!armor) return notify_fail("光溜溜的乱跑真不成体统！\n");
pname=keys(armor);
for(i=0;i<sizeof(armor);i++)
{
if ((armor[pname[i]])->query("id")=="menggu cloth" && me->query_temp("citan"))  return ::valid_leave(me, dir);
}
         if (!me->query_temp("请进")&&(dir == "north")&&!wizardp(me))
         {       me->set_temp("进门",1);
        return notify_fail("守将大声喝到:干什么的?(answer)\n");
         }
	return ::valid_leave(me, dir);
}

