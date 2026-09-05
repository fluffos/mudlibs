// tufeicun.c 山寨
// seagate@pkuxkx 2010/10/30

inherit ROOM;

void create()
{
	set("short", "山寨");
	set("long", @LONG
树林深处不知道从啥时候开始出现了一座山寨，门口站着满脸横肉的土匪，
这里似乎附近土匪的老巢，不过土匪们都出去抢劫财物去了，山寨里只留下一
两个土匪看守着抢劫过来的财物和妇女。
LONG
	);
  set("outdoors", "wudang");

	set("exits", ([
		"eastup" : __DIR__"tufeiwo2",
		"west"  : __DIR__"zhulou"
	]));

  set("objects", ([
    __DIR__"npc/xiao_louluo" : 1,
    __DIR__"npc/xiao_tufei" : 1,
  ]));
  set("no_task",1);

	setup();
}

int valid_leave(object me,string dir)
{
    int i;
    object *ob;
    ob = all_inventory( environment( me ));
    for(i=0; i<sizeof(ob); i++) 
    {
        if( living(ob[i]) && (ob[i]->query("id") == "xiao tufei"||ob[i]->query("id") == "xiao louluo") )
            return notify_fail("土匪把路一挡，狞笑道：怎么，想溜，没那么容易！\n");
    }            
    return ::valid_leave(me, dir);
}