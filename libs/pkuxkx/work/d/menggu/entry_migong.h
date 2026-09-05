#include <ansi.h>

int do_look(string arg)
{
    object ob=this_object();
    object me=this_player();
    object migong=load_object(ob->query("migong"));
    string msg=ob->query("look_refuse_msg");
    if (arg==ob->query("entry_direction")&&!migong->query("fully_generated"))
    {
        tell_object(me,msg);
        if (!migong->query("generating"))
        migong->start();
        return 1;
    }
    return 0;
}

int valid_leave(object me,string dir)
{
    object ob=this_object();
    object migong=load_object(ob->query("migong"));
    string msg=ob->query("enter_refuse_msg");
    if (dir==ob->query("entry_direction")&&!migong->query("fully_generated"))
    {
        if (!migong->query("generating"))
        migong->start();
        return notify_fail(msg);
    }
	if (stringp(migong->welcome_msg(me))&&strwidth(migong->welcome_msg(me))>0&&dir==ob->query("entry_direction"))
	tell_object(me,migong->welcome_msg(me));
	if (stringp(migong->goodbye_msg(me))&&strwidth(migong->goodbye_msg(me))>0&&dir!=ob->query("entry_direction"))
	tell_object(me,migong->goodbye_msg(me));
    return ::valid_leave(me,dir);
}