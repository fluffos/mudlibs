#include "/d/parties/public/access.h"
#define REMOVE_COST 50
int do_zhai()
{
    object ct,me=this_player();
    int num;
	if (!ct=load_object(__DIR__"biguanchu"))
    {
        write("摘匾失败，请联系ZINE解决！\n");
		return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢！\n");
        return 1;
    }
    if (!ct->owner_access(me)&&me->query("id")!="zine")
    {
        tell_object(me,"你不是此间的主人，乱摘什么呀？\n");
        return 1;
    }
    if (GUIDER_D->guider_score(me->query("id"))<REMOVE_COST)
	return notify_fail("你的导师积分低于"+REMOVE_COST+"点，无法进行此项操作。\n");
    if (!me->query_temp("remove_bian_notice"))
    {
        me->set_temp("remove_bian_notice",1);
        write("改变口令需要消耗"+REMOVE_COST+"点导师积分！如果确认请再次输入zhai。\n");
        return 1;
    }
    num=this_object()->query("room_number");
    if (!ct->query("new_names/"+num))
    {
        write("这里并没有挂上任何牌匾。\n");
    }
    else
    {
        GUIDER_D->finish(me,REMOVE_COST);
        this_object()->set("short","空房间");
        message_vision("$N把房屋上的牌匾给摘了下来。\n",me);
        this_object()->delete("realmap");
        ct->delete("new_names/"+num);
        ct->save();
    }
    return 1;
}
int do_gua()
{
    object ct,bian,me=this_player();
    int num;
	if (!ct=load_object(__DIR__"biguanchu"))
    {
        write("保存失败！！！\n");
		return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢！\n");
        return 1;
    }
    if (!bian=present("pai bian",me))
    {
        tell_object(me,"你身上没有一块牌匾，挂什么？\n");
        return 1;
    }
    if (!bian->query("is_bian"))
    {
        tell_object(me,"你身上没有一块牌匾，挂什么？\n");
        return 1;
    }
    if (!bian->query("input_word"))
    {
        tell_object(me,"这块牌匾上没有字呀？\n");
        return 1;
    }
    if (!ct->owner_access(me)&&me->query("id")!="zine")
    {
        tell_object(me,"你不是此间的主人，乱挂什么呀？\n");
        return 1;
    }
    num=this_object()->query("room_number");
    if (ct->query("new_names/"+num)&&bian->query("bian_lv")<=3)
    {
        write("这里已经挂上了一块牌匾了，只有摘下来才能挂新的牌匾。\n");
        return 1;
    }
    else
    {
        if (bian->query("bian_lv")>3)
        {
            message_vision("$N把"+bian->query("name")+"毕恭毕敬地挂在了"+this_object()->query("short")+"的最上方！\n",me);
			if (ct->query("new_longs"+this_object()->query("room_number")))
			this_object()->set("long",ct->query("new_longs"+this_object()->query("room_number"))+"\t"+bian->query("input_word"));
			else
            this_object()->set("long",this_object()->query("long")+"\n"+bian->query("input_word"));
            ct->set("new_longs"+this_object()->query("room_number"),this_object()->query("long"));
            ct->save();
            ct->get_lv();
            destruct(bian);
            return 1;
        }
        this_object()->set("short",bian->query("input_word"));
        message_vision("$N把"+bian->query("name")+"端端正正地挂上了"+this_object()->query("short")+"的正中央！\n",me);
        ct->set("new_names/"+this_object()->query("room_number"),this_object()->query("short"));
        ct->save();
        ct->get_lv();
        destruct(bian);
    }
    return 1;
    
}