#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIR"剑气长江"NOR, ({ "jqcjiang" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	       
            set("unit", "本");
            set("material", "paper");
            set("long", "神书之一,若是能找齐两广豪杰，英雄好汉，江山如画就能(hebing)。\n");
          }

    setup();
}
void init()
{
    add_action("do_hebing","hebing");
}
int do_hebing()
{
	object me,newbook;
	me = this_player();
	newbook =new(__DIR__"shang");
 if (!present("lghjie", me)||!present("heros",me)||!present("jsruhua",me))
	tell_object(me,"书好象没齐.\n");
  else{     message_vision("$N把从怀中翻出的两广豪杰,英雄好汉，江山如画,和手中的剑气长江合并成了一本。\n", me);
	newbook->move(me);
	destruct(present("lghjie",me));
	destruct(present("heros",me));
	destruct(present("jsruhua",me));
	destruct(this_object());}
return 1;
}
