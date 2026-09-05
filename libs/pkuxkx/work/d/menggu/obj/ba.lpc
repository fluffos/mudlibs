inherit ITEM;

void create()
{
    set_name("箭靶", ({ "jian ba","ba","target" }));
	set_weight(500000000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "座");
		set("long", "这是一座箭靶，经常有蒙古勇士在此练箭。\n");
		set("no_get", 1);
        set("is_arrow_target",1);
		set("material", "wood");
		set("shediao_quest_ba",1);
	}
	setup();
}

int shediao_quest(object me)
{
    object hua;
    if (!hua=find_object("/d/menggu/npc/huazheng"))
    {
        hua=new("/d/menggu/npc/huazheng");
    }
    if (!hua->query("quest_owner"))
    {
        hua->move(environment(this_object()));
        hua->greeting(me);
    }
    return 1;
}

int shediao_quest2(object me)
{
    object hua;
    if (!hua=find_object("/d/menggu/npc/huazheng"))
    {
        hua=new("/d/menggu/npc/huazheng");
    }
    me->delete_temp("shediaoquest_shediao_step2b");
    hua->move(environment(this_object()));
    hua->greeting2(me);
    return 1;
}

int shediao_nextquest(object me)
{
    object ob=this_object();
    if ((!random(20)||wizardp(me))&&(int)me->query("shediaoquest/zhebie")>=2&&!me->query("shediaoquest/shediao"))
    {
        if (time()-(int)ob->query("occupy")<1800)
        {
            return 1;
        }
        if ((int)me->query("level")<5)
        {
            return 1;
        }
        ob->set("occupy",time());
        shediao_quest(me);
        return 1;
    }
    if ((!random(8)||wizardp(me))&&me->query_temp("shediaoquest_shediao_step2b")&&!me->query("shediaoquest/shediao"))
    {
        shediao_quest2(me);
        return 1;
    }
    return 0;
}