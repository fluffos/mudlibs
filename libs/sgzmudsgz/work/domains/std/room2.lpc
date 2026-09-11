// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// Beek - a simple room to demonstrate relationships and some toys

#include <mudlib.h>

inherit ROOM;

void setup() {
  set_area("wiz_area");
    
    set_brief("Relations and Toys");
    set_long("这又是一间测试房。北面是第一间测试房，南面是一个阴森森"
	     "的洞穴。东面嘛，好象天气常在改变。");
    set_exits( ([ "north" : "example_room1", "east" : "room4" ]) );
    set_objects( ([
		   "/domains/std/harry" : 1
		   ]) );
}

