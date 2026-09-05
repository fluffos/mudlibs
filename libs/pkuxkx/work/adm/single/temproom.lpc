// This is a room made by roommaker.

inherit ROOM;

void destroy()
{
	destruct(this_object());
}

void create()
{
        set("short","");
        set("long","");
	setup();
//	replace_program(ROOM);
	//temproom很多地方用到，全都是把东西临时搬来再搬走，避免add_action bug，但又都new出来不释放，故加上1分钟后自动释放的功能
	call_out("destroy",60);
}
