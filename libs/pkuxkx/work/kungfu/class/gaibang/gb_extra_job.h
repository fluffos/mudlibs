int extra_job(object me,int flag)
{
    int i,pin=1+random(10000);
    object target,where;
    string name;
    object ob=this_object();
    while (!objectp(where) || 
         !where->isroom()||
         TASK_D->place_belong(where)=="不明区域"||
         TASK_D->place_belong(where)=="未知区域"||
         base_name(where) == "/adm/daemons/taskd")
    {
        where = TASK_D->random_place();
    }
    target=new(__DIR__"jietou");
    name=target->query("name");
    target->move(where);
    for (i=0;i<1+random(3);i++)
    {
        target->random_move();
    }
    if (flag==0)
    {
        if (!target)
        {
            command("say 暂时没什么事，你等会再来吧。");
            return 1;
        }
        command("say 我帮素来以侠义著称，你去"+TASK_D->place_belong(where)+"的"+where->query("short")+"找到一个叫"+name+"的人，和他接头(jietou)。\n");
        me->set_temp("gbnewbiejob/extra",1);
    }
    if (flag==1)
    {
        if (!target)
        {
            message_vision("$N握住了$n的手：“可算找到组织了。”\n",ob,me);
            message_vision("$N一闪身，向黑暗中消失了。\n",ob);
            bonus(me);
            return 1;
        }
        command("say 你快去把情报送给"+TASK_D->place_belong(where)+"的"+where->query("short")+"的"+name+"吧。\n");
        me->set_temp("gbnewbiejob/extra",2);
    }
    me->set_temp("gbnewbiejob/pin",pin);
    target->set_temp("gbnewbiejob/pin",pin);
    me->set("gbnewbiejob/start","extra");
    me->set("gbnewbiejob/lasttime",time());
    me->set_temp("gbnewbiejob/target",target);
    return 1;
}
