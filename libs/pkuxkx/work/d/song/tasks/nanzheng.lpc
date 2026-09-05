//大宋第一个集体任务，远征安南 Zine
//故事背景，安南勾结蒙古人，犯境昆明，大宋决定坚决反击。

#include <ansi.h>
void broadcast(int no);
void start()
{
	broadcast(0);
}

void broadcast(int no)
{
	int *delay=({4,});
	string *channels=({"jh","dasong"});
	string *msgs=({"大宋嘉熙二年，大宋帝国军队在襄阳附近和蒙古铁骑僵持之际，安南借机寇边，掠劫昆明一代……\n",
	"政事堂、枢密院决定紧急召集所有大宋官员至枢密院小官厅议事。\n"});
	CHANNEL_D->do_channel(this_object(), channels[no], HIR+"【大宋】"+msgs[no]+NOR, -1);
	if (no==1) "/d/song/shumicourt"->start();
	remove_call_out("broadcast");
	call_out("broadcast",delay[no-1],no+1);
}