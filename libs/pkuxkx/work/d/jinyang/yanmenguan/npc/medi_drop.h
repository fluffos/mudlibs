void die()
{
    object ob=this_object();
    object ctrl=load_object("/d/jinyang/yanmenguan/yanmenguan");
    object xiao=ctrl->query("yanmen/xiao");
    object env=environment(ob);
    object obj,boss;
    object *all=all_inventory(env);
    int i,count=2+random(3);
    int count_killer=0;
    for (i=0;i<sizeof(all);i++)
    {
        if (all[i]->query("yanmenkiller"))
        {
            count_killer=1;
        }
    }
    if (count_killer==0&&env&&env->query("road_no")==7)//几个关卡出boss
    {
        boss=new(__DIR__"boss1");
        boss->do_copy(xiao);
        boss->move(env);
        message_vision(HIB+BLINK+"$N突然杀入了战场，形势立刻逆转。\n"+NOR,boss);
    }
    if (count_killer==0&&env&&env->query("road_no")==14)//几个关卡出boss
    {
        boss=new(__DIR__"boss2");
        boss->do_copy(xiao);
        boss->move(env);
        message_vision(HIB+BLINK+"$N突然杀入了战场，形势立刻逆转。\n"+NOR,boss);
    }
    for (i=0;i<count;i++)
    {
        switch(random(3))
        {
            case 0:
                obj=new("/d/jinyang/yanmenguan/obj/dan");
            break;
            case 1:
                obj=new("/d/jinyang/yanmenguan/obj/wan");
            break;
            case 2:
                obj=new("/d/jinyang/yanmenguan/obj/wan2");
            break;
        }
        obj->set("yanmen_item",1);
        obj->move(env);
    }
    message_vision("$N苦战多时，真力耗尽，气绝身亡。\n",ob);
    message_vision("$N身上掉下了一些药物。\n",ob);
    ::die();
}