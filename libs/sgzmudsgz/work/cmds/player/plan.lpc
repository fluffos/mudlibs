// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// Command for generating templates for verbs by Rust.  8-95
//  This file is part of the Lima mudlib distribution.  
//  Don't remove this header.  See /USAGE for more info.

#include <mudlib.h>
#include <edit.h>

inherit CMD;

private nomask void set_plan(string * plan)
{
    if( !sizeof( plan ))
    {
        write( "你没有改变你的计划。\n");
        return;
    }
    write("你设定计划完成。\n");
    this_body()->set_plan(implode(plan,"\n"));
}

private void main()
{
#ifdef EVERYONE_HAS_A_PLAN

    out("输入你的计划吧：\n");
    new(EDIT_OB, EDIT_TEXT, 0, (: set_plan :));

#else
    out("对不起，没有这样功能。\n");
#endif
}
