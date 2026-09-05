//吏部侍郎

#include <ansi.h>
#include <title.h>
#include "/d/yingtianfu/neicheng/npc/promote.h"
#include "/d/yingtianfu/neicheng/npc/daming_npc_officer.h"
int askforhelp()
{
    if (random(100)>95)
    {
        command("daming 大明三品以下官员如需工作调动，可以来吏部。\n");
    }
    if (random(100)>95)
    {
        command("daming 洪武门附近的武将节堂，文臣值房已经交付大半，大明官员可以去看看。\n");
    }
        
}
int ask_finish()
{
    object me=this_player();
    object ob=this_object();
	int n,*rewards=({8+random(2),3+random(2),1+random(4),2+random(3),});
	string *finish_comments=({"你找到的贤士真的很不错，将来可能成为国之栋梁，今次你为大明立下了举荐之功呀。\n","呵呵，还不错嘛，这么快就干完了。\n",
		"岁赐勋爵的任务简单吧？还落个人情。\n","完成了，下去吧，你的功劳我们不会抹煞的。\n",});
    if (!me->query_temp("mingtasks/libu/start")&&me->query("mingpin")!=1)
    {
        command("say 你有在这里要过任务吗？\n");
        return 1;
    }
    if (me->query_temp("mingtasks/libu/task1finish")==1)
    {
        command("say 你找到了哪位贤士，真的很不错，虽然他没有来。\n");
        me->add("ming/credit",2+random(2));
        me->delete_temp("mingtasks");
        return 1;
    }
    if (me->query_temp("mingtasks/libu/task1finish")==2)
    {
        task_finish(me,rewards[0],finish_comments[0]);
        return 1;
    }
	if (me->query_temp("mingtasks/libu/task2finish"))
    {
        task_finish(me,rewards[1],finish_comments[1]);
        return 1;
    }
	if (me->query_temp("mingtasks/libu/task3finish"))
    {
        task_finish(me,rewards[2],finish_comments[2]);
        return 1;
    }
	if (me->query_temp("mingtasks/libu/task4finish"))
    {
        task_finish(me,rewards[3],finish_comments[3]);
        return 1;
    }
    else
    {
        task_pending(me,ob);
        return 1;
    }
}

int ask_task()
{
    object me=this_player();
    object ob=this_object();
    object *all;
    object theone;
	//string *taskname=({"任用贤能",});
    string *taskname=({"任用贤能","处理部务","勋爵赏赐","考功"}),msg;
    int n;
    if (me->query("mingjiaonewbiejob/damingstart")&& me->query_temp("mingtasks/libu/start"))
    {
        tell_object(me,"今天真是你的幸运日，"+this_object()->name()+"什么也没要你做就让你回明教复命了。\n");
        tell_object(me,"完成了大明任务，你可以回杨逍处复命了。\n");
        me->delete("mingjiaonewbiejob");
        me->set("mingjiaonewbiejob/lucky",1);
        me->set("mingjiaonewbiejob/damingfinish",1);
        return 1;
    }
    if (if_give_task(me)!="approve")
	{
		msg=if_give_task(me);
		write(msg);
		return 1;
	}
    else
    {
        n=random(sizeof(taskname));
		me->set_temp("mingtasks/libu/task",n+1);
        if (n==0)
        {
            all = filter_array(children(USER_OB), (: userp :));
            all = filter_array(all, (: environment :));
            all = filter_array(all, (: !$1->query("mingpin") && !$1->query("ming/tj/pin") :) );
            theone=all[random(sizeof(all))];
			if (me->query("mingpin")==1)
			{
				message_vision("$N看着$n，道：贤士在野，宰相之过。听说"+theone->query("name")+"("+theone->query("id")+")素有贤名，我就去试试把他请(yaoqing)来吧。\n",me,ob);
			}
			else if (me->query("mingpin")<4)
			{
				command("say 听说"+theone->query("name")+"("+theone->query("id")+")素有贤名，有劳大人去试试能不能把他请(yaoqing)来吧。");
			}
			else
			{
				message_vision("$N看着$n，道：贤士在野，宰相之过。听说"+theone->query("name")+"("+theone->query("id")+")素有贤名，你去把他请(yaoqing)来吧。\n",ob,me);
				message("chat",HIW"【大明】吏部侍郎："+me->query("name")+HIW+"奉命找寻贤士"+theone->query("name")+"("+theone->query("id")+")到应天府吏部问策！\n"NOR,users());
				tell_object(me,"但是外人不得进应天府的规矩不得废，你且引他从正阳门进来。\n");
			}
			me->set_temp("mingtasks/libu/targetname",theone->query("name"));
            me->set_temp("mingtasks/libu/target",theone->query("id"));
        }
        if (n==1)
        {
			if (me->query("mingpin")==1)
			message_vision("$N看着$n，道：现在吏部部务繁重，我就去吏部大厅帮助你们归档(guidang)宗卷吧。\n",me,ob);
			else if (me->query("mingpin")<4)
			command("say 现在部务繁重，大人可否前去吏部大厅帮助归档(guidang)宗卷？");
			else
			{
				message_vision("$N看着$n，道：现在部务繁重，光靠我俩和尚书是铁定忙不过来的，你去吏部大厅帮助归档(guidang)宗卷吧。\n",ob,me);
				command("whisper "+me->query("id")+" 其中很多涉及我大明的机密，切勿外泄。");
			}
        }
		if (n==2)
        {
			if (me->query("mingpin")==1)
			message_vision("$N看着$n，道：又到了每年朝廷赏赐勋爵的时候了，我马上去吏部大厅查出(chaxun)待赏名单，把岁赐发(fa)下去吧。\n",me,ob);
			else if (me->query("mingpin")<4)
			command("say 又到了每年朝廷赏赐勋爵的时候了，大人去吏部大厅查出(chaxun)待赏名单，把岁赐发(fa)下去吧。");
			else
			message_vision("$N看着$n，道：又到了每年朝廷赏赐勋爵的时候了，你去吏部大厅查出(chaxun)待赏名单，把岁赐发(fa)下去吧。\n",ob,me);
        }
		if (n==3)
        {
			if (me->query("mingpin")==1)
			message_vision("$N看着$n，道：我就去吏部大厅调出(diao)人事宗卷，看看谁这段时间功勋积攒最多。\n",me,ob);
			else if (me->query("mingpin")<4)
			command("say 现在部务繁重，大人可否前去吏部大厅调出(diao)人事宗卷，看看谁这段时间功勋积攒最多？");
			else
			{
				message_vision("$N看着$n，道：你且去吏部大厅调出(diao)人事宗卷，看看谁这段时间功勋积攒最多。\n",ob,me);
				command("whisper "+me->query("id")+" 其中很多涉及我大明的机密，切勿外泄。");
			}
        }
		if (me->query("mingpin")==1)
        pre_1pin(me);
        return 1;
    }
}

int ask_change_title()
{
    object me=this_player();
	int n;
    if (!me->query("mingpin"))
    {
        tell_object(me,"你不是大明官员，谈何调动？\n");
        return 1;
    }
    if (me->query("mingpin")<=3)
    {
        tell_object(me,"三品以上朝廷大员，可不是吏部能随意调动的。\n");
        return 1;
    }
    if (me->query("gender")!="男性")
    {
        tell_object(me,"……\n");
        return 1;
    }
    if (time()-me->query("ming/change_position")<60*60*4)
    {
        tell_object(me,"频繁调动可不好啊……\n");
        return 1;
    }
    if (!me->query_temp("调动"))
    {
        tell_object(me,"调动工作可能要扣掉一定的大明功勋度，假如你真的愿意就<ask shilang about 调动>吧。\n");
        me->set_temp("调动",1);
        return 1;
    }
	me->set_temp("ming/hor_promote",2);
    position_me(me);
    n=random(7)+2;
    me->add("ming/credit",-n);
    tell_object(me,"因为要求调动工作，你被扣去了"+chinese_number(n)+"点大明功勋。\n");
    me->set("ming/change_position",time());
    return 1;
}

int ask_change_title2()
{
    object me=this_player();
    if (!me->query("mingpin"))
    {
        tell_object(me,"你不是大明官员，谈何调动？\n");
        return 1;
    }
    if (me->query("mingpin")<=2)
    {
        tell_object(me,"二品以上朝廷大员，可不是吏部能调动的。\n");
        return 1;
    }
    if (me->query("ming/title"))
    {
        if (me->query("ming/pro")=="文")
        {
            tell_object(me,"你的值房已经建好，就在洪武门东面。\n");
            return 1;
        }
        if (me->query("ming/pro")=="武")
        {
            tell_object(me,"你的节堂已经建好，就在洪武门西面。\n");
            return 1;
        }
        else
        {
            tell_object(me,"已经帮你挂名，等三品以后会有自己专用的办公场所，你先去洪武门附近挤挤吧。\n");
            return 1;
        }
    }
    if (me->query("gender")!="男性")
    {
        tell_object(me,"……\n");
        return 1;
    }
    
    position_me(me);
    return 1;
}


int ask_yin()
{
    object me=this_player();
    object* inv;    
    object guanyin;
    int i;
    inv = deep_inventory(me);
    if (!me->query("mingpin"))
    {
        command("say 老夫在朝二十余年，大明官员都见过，怎么不认识你？\n");
        return 1;
    }
    if (me->is_busy() || me->is_fighting())
    {
		return notify_fail("你正忙着哪！\n");
    }
    for(i=sizeof(inv)-1; i>=0; i--)
    {
        if((inv[i])->query("guanyin"))
        {
            command("say 你身上不是正有一具官印吗？\n");
            return 1;
        }
    }
    me->add_busy(1);
    guanyin=new("/d/yingtianfu/neicheng/obj/guanyin");
    guanyin->set("owner",me->query("id"));
    guanyin->move(me);
    message_vision("$N拿出一具官印，交给$n。\n",this_object(),me);
    return 1;
}



int dest(object ruyi)
{
	if(ruyi)
	destruct(ruyi);
	return 1;
}

int accept_object(object me, object ruyi)
{
    int n;
	if (ruyi->query("jade_ruyi")!=1)
	    return notify_fail("吏部侍郎不想要你的东西。\n");
    else
    {
        n=4+random(3);
        message_vision("吏部侍郎接过$N手里的嘉奖令，颤声道：皇上御赐的嘉奖令。\n",me);
        message_vision("吏部侍郎把嘉奖令封存起来，并仔细记下了$N的功绩。\n",me);
        me->add_busy(1);
        me->add("ming/credit",n);
        tell_object(me,"你偷偷瞄见，吏部侍郎在你名下功绩加了"+chinese_number(n)+"点。\n");
        call_out("dest",0,ruyi);
        return 1;
    }
    
}

int ask_convert()
{
    object me=this_player();
    int zs,getnum;
    if (!me->query("mingpin"))
    {
        tell_object(me,"吏部侍郎道：老夫在朝二十余年，大明官员都见过，怎么不认识你？\n");
        return 1;
    }
    if (me->query("mingpin")>4)
    {
        tell_object(me,"吏部侍郎道：只有四品以上官员可以兑换。\n");
        return 1;
    }
    if (me->is_busy() || me->is_fighting())
	{
		tell_object(me,"你正忙着哪！\n");
        return 1;
    }
    if (!me->query("zhusantimes"))
    {
        tell_object(me,"你好像没啥可以兑换的东西。\n");
        return 1;
    }
        getnum=(int)me->query("zhusantimes")*9/5+random(4);
        zs=(int)me->query("zhusantimes");
        me->set("zhusantimes",0);
        me->add("ming/credit",getnum);
        tell_object(me,HIC"你把之前帮助史可法转移难民的"+chinese_number(zs)+"点功绩转换成"+chinese_number(getnum)+"点大明功勋度。\n"NOR);
        return 1;
   
}