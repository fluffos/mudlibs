#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIB"圆月弯刀"NOR, ({ "wandao" }) );
            set("no_put", 1);
            set("value", 0);
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	        
            set("unit", "本");
            set("material", "paper");
            set("long", "神书之一,若是能找三少爷的剑就能(zhuangding)了。\n");
          }

    setup();
}
void init()
{
    add_action("do_zhuangding","zhuangding");
}
int do_zhuangding()
{
	object me,newbook,ob;
	me = this_player();
	newbook =new(__DIR__"xiebook");
// if (!present("xiesword",me))
    if (!(ob = present("xiesword",me)) )
	tell_object(me,"书好象没齐.\n");
else{
    if(!ob->query("dynamic_quest"))
	return notify_fail("这里面有假货吧。\n");
       message_vision("$N把从怀中翻出三少爷的剑，和手中的圆月晚刀合并成了一本。\n", me);
	newbook->move(me);
	destruct(present("xiesword",me));
	destruct(this_object());}
return 1;
}
