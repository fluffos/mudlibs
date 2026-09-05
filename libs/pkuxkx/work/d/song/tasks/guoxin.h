#include <ansi.h>
#include "pre&post_task.h"
#define DEPART "guoxin"
mapping *tasks=({
		(["name":"信件存档","comment":"誊写完成，你下去休息吧。\n","reward":8+random(5),"range":"8-12",]),
	});
int ask_finish()
{
    object me=this_player();
	return is_finish(me,DEPART,tasks);
}

int ask_task()
{
    object me=this_player();
    object ob=this_object(),gy,xin;
	if (pre_assign(me,DEPART,tasks)==0)
    return 1;
    else
    {
		gy=me->query_temp("song_identification");
		if (me->query_temp("songtasks/"+DEPART+"/task")==1)
		{
			command("say 这里有一封国信，需要存档，你读过(read)之后，在这里誊抄(teng)一下吧。");
			xin=new("/d/song/obj/xin");
			xin->move(ob);
			xin->set_long(me);
			command("give "+me->query("id")+" xin");
			tell_object(me,"誊抄只需正文即可，必须一字一字抄写，遇到换行输入teng 换行。\n");
		}
        return 1;
    }
}



