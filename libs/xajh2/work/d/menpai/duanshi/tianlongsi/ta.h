// ta.h writen by cry 9.18.98

int valid_leave(object me, string dir)
{
	object obj;

	if(dir=="up"&&objectp(obj=present("huta seng",this_object()))){
		return notify_fail("护塔僧说道：此塔仍本寺禁地，请施主留步！\n");
	}
	return 1;
}
