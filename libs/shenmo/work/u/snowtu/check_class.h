int check_class(object me)
{
if ( wizardp(me) ) tell_object(me,query("class")+"\n");
if ( me->query("class")!=query("class") ) 
        return notify_fail(name()+CYN+"摇了摇头：你非"+to_chinese(query("class"))+"界中人。\n"NOR);
}


