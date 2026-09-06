#include "/sys/object_info.h"

status
shadows_cmd(string arg, object me)
{
    object ob, orig;
    int i;

    if(!arg || arg=="")
    {
	this_player()->tell_me("usage:shadows <ob>\n");
	return 1;
    }
    ob = get_object(arg);
    if(!ob)
    {
	this_player()->tell_me(arg+" not found");
	return 1;
    }
    orig = ob;
    while(ob=object_info(ob, OI_SHADOW_PREV))
    {
	if (!i++) me->tell_me(sprintf("Objects shadowing object '%O' are:", orig));
	this_player()->tell_me(sprintf("%O",ob));
    }
    if (!i) me->tell_me(sprintf("No object(s) shadowing object '%O'", orig));
    return 1;
}
