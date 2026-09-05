int verify(object me)
{
    object room=load_object(__DIR__"damen");
    string password=room->query("password");
    if (me->query("chaoting/qinwangfu/key")!=password)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
