// tufeiwo3.c 小路尽头
// by Cleansword 1996/2/2

inherit ROOM;

void create()
{
	set("short", "林中小路");
	set("long", @LONG
	你走在一条僻静的林中小路上，两旁是阴森森的树林。只见左右前后，到处
都是铺天盖地的松树林。几十丈高的大松树簇在一块，密实的枝叶象一蓬蓬巨伞
般伸向天空，把阳光遮得丝毫也无。据说这里经常有土匪出没，不可久留。
LONG
	);
        set("outdoors", "wudang");

	set("no_sleep_room",1);

	set("exits", ([
                  "enter" : __DIR__"tufeiwo4",
		"west" : __DIR__"tufeiwo2",
	]));

        set("objects", ([
                __DIR__"npc/tufei1" : 2 ,
                __DIR__"npc/tufeitou" : 1, 
        ]));

	setup();
//	replace_program(ROOM);
}
int valid_leave(object me,string dir)
{
    int i;
    object *ob;
    ob = all_inventory( environment( me ));
    for(i=0; i<sizeof(ob); i++) 
    {
        if( living(ob[i]) && (ob[i]->query("id") == "tufei" || ob[i]->query("id") == "tufei tou"))
            return notify_fail("土匪把路一挡，狞笑道：怎么，想溜，没那么容易！\n");
    }            
    return ::valid_leave(me, dir);
}	

