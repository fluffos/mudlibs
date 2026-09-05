inherit ROOM;
int not_room()
{
	return 1;
}
int valid_leave(object me,string dir)
{
    object ob=this_object();
    object migong=load_object(ob->query("migong"));
    string msg=ob->query("enter_refuse_msg");
    if (dir==ob->query("entry_direction")&&!migong->query("fully_generated"))
    {
        if (!migong->query("generating"))
        {
            migong->start();
        }
        return notify_fail(msg);
    }
    return ::valid_leave(me,dir);
}
