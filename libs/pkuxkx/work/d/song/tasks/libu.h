//兵部任务 Zine 

#include <ansi.h>
#include "pre&post_task.h"
#define DEPART "libu"
mapping *tasks=({
		(["name":"任用贤能","comment":"你找到的贤士真的很不错，将来可能成为国之栋梁，今次你为大宋立下了举荐之功呀。\n","reward":8+random(2),"range":"8-9",]),
		(["name":"处理部务","comment":"呵呵，还不错嘛，这么快就干完了。\n","reward":3+random(2),"range":"3-4",]),
		(["name":"勋爵赏赐","comment":"岁赐勋爵的任务简单吧？还落个人情。\n","reward":1+random(4),"range":"1-4",]),
		(["name":"考功","comment":"完成了，下去吧，你的功劳我们不会抹煞的。\n","reward":2+random(3),"range":"2-4",]),
	});
int ask_finish()
{
    object me=this_player();
	return is_finish(me,DEPART,tasks);
}

int ask_task()
{
    object me=this_player();
    object ob=this_object(),*all,theone;
    if (pre_assign(me,DEPART,tasks)==0)
    return 1;
    else
    {
		if (me->query_temp("songtasks/"+DEPART+"/task")==1)
        {
            all = filter_array(children(USER_OB), (: userp :));
            all = filter_array(all, (: environment :));
            all = filter_array(all, (: !$1->query("song/pro") :) );
			all = filter_array(all, (: $1->query("antirobot/deactivity")<$2 :), 3);
            theone=all[random(sizeof(all))];
			if (DASONG_D->get_my_pin(me)==1)
			message_vision("$N看着$n，道：贤士在野，宰相之过。听说"+theone->query("name")+"("+theone->query("id")+")素有贤名，我就去试试把他请(yaoqing)来吧。\n",me,ob);
			else if (DASONG_D->get_my_pin(me)<5)
			command("say 听说"+theone->query("name")+"("+theone->query("id")+")素有贤名，有劳大人去试试能不能把他请(yaoqing)来吧。");
			else
			{
				message_vision("$N看着$n，道：贤士在野，宰相之过。听说"+theone->query("name")+"("+theone->query("id")+")素有贤名，你去把他请(yaoqing)来吧。\n",ob,me);
				message("chat",HIR"【大宋】吏部行文："+me->query("name")+HIW+"奉命找寻贤士"+theone->query("name")+"("+theone->query("id")+")到临安府吏部问策！\n"NOR,users());
			}
			me->set_temp("songtasks/libu/targetname",theone->query("name"));
            me->set_temp("songtasks/libu/target",theone->query("id"));
        }
        if (me->query_temp("songtasks/"+DEPART+"/task")==2)
        {
			if (DASONG_D->get_my_pin(me)==1)
			message_vision("$N看着$n，道：现在吏部部务繁重，我就去司封司帮助你们归档(guidang)宗卷吧。\n",me,ob);
			else if (DASONG_D->get_my_pin(me)<5)
			command("say 现在部务繁重，大人可否前去司封司帮助归档(guidang)宗卷？");
			else
			{
				message_vision("$N看着$n，道：现在部务繁重，你去司封司帮助归档(guidang)宗卷吧。\n",ob,me);
				command("whisper "+me->query("id")+" 其中很多涉及我大宋的机密，切勿外泄。");
			}
        }
		if (me->query_temp("songtasks/"+DEPART+"/task")==3)
        {
			if (DASONG_D->get_my_pin(me)==1)
			message_vision("$N看着$n，道：又到了每年朝廷赏赐勋爵的时候了，我马上去司勋司衙门查出(chaxun)待赏名单，把岁赐发(fa)下去吧。\n",me,ob);
			else if (DASONG_D->get_my_pin(me)<5)
			command("say 又到了每年朝廷赏赐勋爵的时候了，大人去司勋司衙门查出(chaxun)待赏名单，把岁赐发(fa)下去吧。");
			else
			message_vision("$N看着$n，道：又到了每年朝廷赏赐勋爵的时候了，你去司勋司衙门查出(chaxun)待赏名单，把岁赐发(fa)下去吧。\n",ob,me);
        }
		if (me->query_temp("songtasks/"+DEPART+"/task")==4)
        {
			if (DASONG_D->get_my_pin(me)==1)
			message_vision("$N看着$n，道：我就去考功司衙门调出(diao)人事宗卷，看看谁这段时间功勋积攒最多。\n",me,ob);
			else if (DASONG_D->get_my_pin(me)<5)
			command("say 现在部务繁重，大人可否前去考功司衙门调出(diao)人事宗卷，看看谁这段时间功勋积攒最多？");
			else
			{
				message_vision("$N看着$n，道：你且去考功司衙门调出(diao)人事宗卷，看看谁这段时间功勋积攒最多。\n",ob,me);
				command("whisper "+me->query("id")+" 其中很多涉及我大宋的机密，切勿外泄。");
			}
        }
        pre_1pin(me,DEPART,tasks);
        return 1;
    }
}



