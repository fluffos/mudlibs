//熊心bearheart
//by steel
#include "ansi.h"

inherit ITEM;

void create()
{
    set_name("熊心",({"bearheart"}));
    set_weight(10);
    if( clonep() )
		set_default_object(__FILE__);
    else
  {
    set("unit","个");
    set("long","这是一个新鲜的熊心,上面还带着血丝.\n");
    set("value","1000");
    set("material","fesh"); 
  }    
 setup();
}
