// minju.c

inherit ROOM;
void create()
{
        set("short","民居");
        set("long",@LONG                                   
这是一个很普通的北方民房，一个小小的院落。院子里面堆
着不少原木，一个木架子上挂着刨子、木据之类的木匠工具，看
样子这里的主人是个木匠。
LONG
        ); 



        set("exits",([
               "south":__DIR__"xiaolu4",
		"northwest" : __DIR__"minju1",
		"northeast" : __DIR__"minju2",
        ]) );

	set("objects",([
	__DIR__"npc/laozhao" : 1,
]));
        setup();
}

int valid_leave(object me, string dir)
{
	object room;

	if(wizardp(me))
		return 1;

	if( (dir != "northwest") && (dir != "northeast") )
		return 1;

	if(!me->query_temp("valid_enter_drying_room"))
		return notify_fail("老赵拦住你说道：那里是木材烘干房，没事您就别进去了。\n");

	if(!objectp(room = find_object(query("exits/"+dir))))
		return 1;

	if(sizeof(filter_array(all_inventory(room),(: userp :))))
		return notify_fail("老赵拦住你说道：那间房子里游人在干活呢，您等会儿再进去吧。\n");
	return 1;
}
