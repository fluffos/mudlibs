int valid_leave(object me,string dir)
{
    if (dir=="north")
    {
        return notify_fail("那里传说中住着妖怪，你还是不要过去了！\n");
    }
    return ::valid_leave(me,dir);
}