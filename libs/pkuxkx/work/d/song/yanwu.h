void init()
{
	if (!wizardp(this_player()))
		return;
	add_action("do_open","open");
}
int notice(object me)
{
	if (!me)
	message( "channel:" + "baowei",HIR + "【大宋演武场】听说大宋演武场开启，各路豪杰可以前去比武了。\n"NOR,users());
	else
	message( "channel:" + "baowei",HIR + "【大宋演武场】听说" + me->query("name")+HIR+"开启了大宋演武场，各路豪杰可以前去比武了。\n"NOR,users());
}
int do_open()
{
	object me=this_player();
	if (query("OPEN_TO_YANWU")||query("exits/"+query("yanwu_dir")))
	return notify_fail("演武厅已经被开启了。\n");
	set("no_clean_up", 1);
	set("no_reset", 1);
	set("exits/"+query("yanwu_dir"),query("yanwu_room"));
	set("OPEN_TO_YANWU",1);
	tell_object(me,"你开启了演武场。\n");
	call_out("notice",1+random(2),me);
	return 1;
}