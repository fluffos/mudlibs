int valid_leave(object me,string dir)
{
    object room;
    if (room=load_object(this_object()->query("exits/"+dir)))
    {
        if (room->query("is_daze"))
        {
            return notify_fail("你以为自己是裘千仞吗？还想水上飘过去？\n");
        }
    }
    return ::valid_leave(me,dir);
}