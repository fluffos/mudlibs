int check()
{
    object ob=this_object();
    object me;
    if (!ob->query("owner"))
    {
        destruct(ob);
        return 1;
    }
    me=ob->query("owner");
    if (!me)
    {
        destruct(ob);
        return 1;
    }
    call_out("check",5);
    return 1;
}