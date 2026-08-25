// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// Written by Rust.
#include <mudlib.h>

inherit OBJ;
inherit M_READABLE;
inherit M_GETTABLE;


void setup(string text)
{
    if(!strlen(text))
    {
	text = "*** Recorder heard nothing but silence.\n";
    }
  
    set_id("transcript", "笔记本");
    set_unit("本");
    set_gettable(1);
    set_in_room_desc("地上放着一个笔记本。");
    set_long("它上面有些对话的记录。\n");
    set_text(text);
}
