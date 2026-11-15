#define OUTROOM "/d/heimuya/shimen"

int is_jjroom() { return 1; }

int valid_leave(object me, string dir)
{
	if(random(2))
	{
		tell_object(me,"匆忙中，你一不小心跌了一跤！\n");
		me->start_busy(2);
		return 1;
	}
	return ::valid_leave(me, dir);
}
