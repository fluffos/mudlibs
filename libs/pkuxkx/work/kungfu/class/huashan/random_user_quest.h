// By Zine for hs Newbie
#include <ansi.h>
int lookingforplayer(object me)
{
    object *all;
    object *theone=({}),*one=({});
    object ob=this_object();
    int i;
    string msg="";
    object li=new("/d/huashan/obj/li");
    if (me->query_temp("hsnewbiejob/target"))
    {
        message_vision("$N看着$n，道：你快去吧。\n",ob,me);
        return 1;
    }
    all = filter_array(children(USER_OB), (: userp :));
    all = filter_array(all, (: environment :));
    for (i=0;i<3+random(3);i++)
    {
        theone+=({all[random(sizeof(all))]});
    }
    for (i=0;i<sizeof(theone);i++)
    {
        if (theone[i]==me)
        {
            continue;
        }
		if (wizardp(theone[i]))
		{
			continue;
		}
        if (member_array(theone[i],one)==-1)
        {
            one+=({theone[i]});
            //one+=theone[i];
            msg+=theone[i]->query("name")+"("+theone[i]->query("id")+") ";
        }
        
    }
    
    msg+="这些人了，";
    message_vision("$N看着$n，道：好久没有见过"+msg+"你在江湖中，如果遇到这些前辈中的一个，代我向他问个好(wenhao)吧，并把礼品带给他。\n",ob,me);
    tell_object(me,HIW+BLINK+"任务完成后直接在"+ob->query("name")+"面前输入finish，如果无法完成，请输入fail。\n"NOR);
    li->set("owner",me->query("id"));
    li->move(me);
    tell_object(me,ob->name()+"给了你一包礼物。\n");
    me->set("hsnewbiejob/start",1);
    me->set("hsnewbiejob/lasttime",time());
    me->set("hsnewbiejob/user",1);
    me->set_temp("hsnewbiejob/target",one);
    return 1;
}

void init()
{
    add_action("do_finish","finish");
    add_action("do_fail","fail");
    add_action("do_leave",  "leave");
}

int do_finish()
{
    object me=this_player();
    if (me->query("family/family_name")!="华山派")
    {
        return 0;
    }
    if (!me->query_temp("hsnewbiejob/target"))
    {
        return 0;
    }
    if (!me->query_temp("hsnewbiejob/wenhaofinish"))
    {
        tell_object(me,"你还没有向前辈问好呢。\n");
        return 1;
    }
    
    me->delete("hsnewbiejob/user");
    bonus(me);
    return 1;
}

int do_fail()
{
    object me=this_player();
    object gift;
    if (me->query("family/family_name")!="华山派")
    {
        return 0;
    }
    if (!me->query("hsnewbiejob/user"))
    {
        return 0;
    }
    if (me->query_temp("hsnewbiejob/wenhaofinish"))
    {
        tell_object(me,"你不是完成了吗？finish吧。\n");
        return 1;
    }
    if (present("li wu",me))
    {
        gift=present("li wu",me);
    }
    if (gift&&gift->query("is_liwu"))
    {
        destruct(gift);
    }
    me->delete("hsnewbiejob/start");
    me->delete_temp("hsnewbiejob");
    message_vision("$N放弃了华山派的送礼任务。\n",me);
    return 1;
}
