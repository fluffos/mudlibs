// 认亲，找一个npc做为自己的血亲 Zine
#include <ansi.h>
string * gifts=({"/d/luoyang/npc/obj/modaoshi3","/d/changjiang/obj/clue","/d/taohuadao/obj/shadan-san","/d/luoyang/obj/chater","/obj/gem/weapon","/obj/gem/gem"});
//亲戚的见面礼列表
int first_meet(object me,object target)
{
    object clue;
    string gift;
    if (me->query("relationship/first_meet"))
    {
        return 0;
    }
    gift=gifts[random(sizeof(gifts))];
    clue=new(gift);
    if (clue)
    {
        clue->set("owner",me->query("id"));
        message_vision("$N道：$n,我也没有什么东西好送你，这个"+clue->name()+"你就拿去吧。\n",target,me);
        tell_object(me,target->name()+"给你一个"+clue->name()+"。\n");
        clue->move(me);
    }
    if (target->query("family")&&target->query("family/family_name")!=me->query("family/family_name"))
    {
        message_vision("$N答应之后把$n介绍给自己的同门。\n",target,me);
        me->set("relationship/close_family",target->query("family/family_name"));
    }
    CHANNEL_D->do_channel(this_object(), "rw", HIW+me->query("name")+HIW+"历经多年，终于找到了自己失散多年的亲人——"+target->name()+"。", -1);
    me->set("relationship/first_meet",1);
    return 1;
}

int main(object me,string arg)
{
	object target,thing;
	int n;
	if(!arg||arg=="") 
		return notify_fail("你要跟谁认亲戚？\n");
	if(me->is_busy()) return notify_fail("你正忙着呢。\n");
    if (arg=="-c")
    {
        if (me->query("relationship/target_name"))
        {
            tell_object(me,"你一直失散的家人是"+me->query("relationship/target_name")+"("+me->query("relationship/target_id")+")。\n");
            return 1;
        }
        else
        {
            return notify_fail("你还没有找到自己失散的家人。\n");
        }
    }
	if(!objectp(target=present(arg,environment(me))))
		return notify_fail("这里没有这个人。\n");
    if (target->query("race")!="人类")
        return notify_fail("有意思啊，原来你一直以为你也是个"+target->query("name")+"呀。\n");
	if((target->query("name")==me->query("relationship/target_name")
        &&target->query("id")==me->query("relationship/target_id")
        &&target->query("combat_exp")==me->query("relationship/target_exp"))||base_name(target)==me->query("relationship/target_basename"))
	{
        if (!me->query("relationship/target_basename"))
        {
            me->set("relationship/target_basename",base_name(target));
        }
        if (me->query("relationship/renqined"))
        {
            if (me->query_temp("relative/wanted"))
            {
                //随机事件
				if (me->query_temp("relative/wanted")==1)
				{
                    if (random(100)>49)
                    {
                        thing=new("/d/guiyunzhuang/obj/guwan");
                    }
					else
                    {
                        thing=new("/d/guiyunzhuang/obj/zihua");
                    }
					me->delete_temp("relative/wanted");
					message_vision("$N拉住$n悄声道：我找到了件东西，应该是好东西，但我不知道这是什么，留着也没用，就交给你吧。\n",target,me);
					thing->move(me);
					tell_object(me,target->name()+"塞给你一包东西。\n");
					return 1;
				}
                if (me->query_temp("relative/wanted")==2)
				{
					n=random(4);
					if (n==0)
					{
						me->set_temp("extrajob/hyd",1);
						me->set_temp("extrajob/xf",1);
						me->set_temp("extrajob/hyw",1);
	
						message_vision("$N对$n大声道：我听说胡一刀大侠，萧峰大侠，韩员外大侠正在找人帮忙，这时候去帮助他们或许会有额外奖励。\n",target,me);
					}
					if (n==1)
					{
						me->set_temp("extrajob/hyd",1);
						me->set_temp("extrajob/xf",1);
						me->set_temp("extrajob/mr",1);
						message_vision("$N对$n大声道：我听说胡一刀大侠，萧峰大侠，慕容复大侠正在找人帮忙，这时候去帮助他们或许会有额外奖励。\n",target,me);
					}
					if (n==2)
					{
						me->set_temp("extrajob/hyd",1);
						me->set_temp("extrajob/hyw",1);
						me->set_temp("extrajob/mr",1);
						message_vision("$N对$n大声道：我听说胡一刀大侠，韩员外大侠，慕容复大侠正在找人帮忙，这时候去帮助他们或许会有额外奖励。\n",target,me);
					}
					if (n==3)
					{
						me->set_temp("extrajob/xf",1);
						me->set_temp("extrajob/hyw",1);
						me->set_temp("extrajob/mr",1);
						message_vision("$N对$n大声道：我听说萧峰大侠，韩员外大侠，慕容复大侠正在找人帮忙，这时候去帮助他们或许会有额外奖励。\n",target,me);
					}
					me->delete_temp("relative/wanted");
					return 1;
				}
				if (me->query_temp("relative/wanted")==3)
				{
					thing=new("/d/guiyunzhuang/obj/guwan");
					me->delete_temp("relative/wanted");
					message_vision("$N拉住$n悄声道：我找到了件东西，应该是好东西，但我不知道这是什么，留着也没用，就交给你吧。\n",target,me);
					thing->move(me);
					thing=new("/d/guiyunzhuang/obj/guwan");
					thing->move(me);
					tell_object(me,target->name()+"塞给你一包东西。\n");
					tell_object(me,"三级认亲任务暂不开放，用两包古董代替。\n");
					return 1;
				}
				if (me->query_temp("relative/wanted")>=4)
				{
					me->delete_temp("relative/wanted");
					message_vision("$N拉住$n悄声道：不是老哥不照拂你，这段时候去换特技，也许不会有任何损失。\n",target,me);
					me->set_temp("relative/changespecial",1);
					return 1;
				}
            }
            return notify_fail("以后你们就多亲近亲近吧。\n");
        }
        if (target->query("gender")=="男性")
        {
            message_vision("$N紧紧拉住$n的手：大哥，我终于找到你了。\n"+"$N哽咽道：这些年，我找你找得好苦啊！\n",me,target);
        }
        else if (target->query("gender")=="女性")
        {
            message_vision("$N紧紧拉住$n的手：妹子，我终于找到你了。\n"+"$N哽咽道：这些年，我找你找得好苦啊！\n",me,target);
        }
        else
        {
            message_vision("$N紧紧拉住$n的手：弟弟，我终于找到你了。\n"+"$N大惊道：你，你怎么变成太监了？？！！\n",me,target);
        }
        call_out("first_meet",1,me,target);
        me->set("relationship/renqined",1);
		
	}
	else
	{
		message_vision("$N看着$n欲言又止，$n暗地里翻了个白眼：这人好变态啊。\n",me,target);
	}
	me->start_busy(1);
	return 1;
}

int help (object me)
{
	write(@HELP
指令格式: renqin npc id
 
每个人在北侠都有一个血缘亲戚，找到他（她）也许会对你的成长有很大帮助。
renqin -c可以查询自己失散的亲人。
HELP
);
return 1;
}
