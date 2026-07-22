#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(YEL"香帅传奇"NOR, ({ "xscq" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	        
            set("unit", "本");
            set("material", "paper");
            set("long", "神书之一,若是能找齐陆小风和卜鹰传奇就能(zhuang)成传奇系列。\n");
          }

    setup();
}
void init()
{
    add_action("do_zhuang","zhuang");
}
int do_zhuang()
{
	object me,newbook;
	me = this_player();
	newbook =new(__DIR__"chuanqi");
 if (!present("bycq", me)||!present("luxf",me))
	tell_object(me,"书好象没齐.\n");
 else {      message_vision("$N把从怀中翻出的陆小风和卜鹰传奇，和手中的香帅传奇合并成了一本。\n", me);
	newbook->move(me);
	destruct(present("bycq",me));
	destruct(present("luxf",me));
	destruct(this_object());}
return 1;
}
