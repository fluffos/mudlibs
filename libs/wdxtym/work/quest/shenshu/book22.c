#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(BLU"风云第一刀"NOR, ({ "fyblade" }) );
            set("no_put", 1);
            set("value", 0);
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	        
            set("unit", "本");
            set("material", "paper");
            set("long", "神书之一,若是能找齐风铃中的刀声，边城浪子和天涯明月刀就能重组(zu)。\n");
          }

    setup();
}
void init()
{
    add_action("do_zu","zu");
}
int do_zu()
{
	object me,newbook,ob;
	object *inv;
	int sizeinv;

	me = this_player();
	newbook =new(__DIR__"4book");
 //if (!present("fengling", me)
 //||!present("bclangzi",me)
 //||!present("skyblade",me))
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("你先把身上的人放下吧!!\n");
       		
		}
    if (!(ob = present("fengling", me)) ||
        !(ob = present("bclangzi", me)) ||
        !(ob = present("skyblade", me)))
	tell_object(me,"书好象没齐.\n");
else {
        if( ob->query("ownmake"))
	return notify_fail("这里面有假货吧。\n");
        if(userp(ob))
	return notify_fail("这里面有假货吧。\n");
        if( ob->is_character() || ob->is_corpse() )
	return notify_fail("这里面有假货吧。\n");

    if(!ob->query("dynamic_quest"))
	return notify_fail("这里面有假货吧。\n");
      message_vision("$N把从怀中翻出的边城浪子，风铃中的刀声，天涯明月刀，和手中的神雕侠侣合并成了一本。\n", me);
	newbook->move(me);
	destruct(present("fengling",me));
	destruct(present("bclangzi",me));
	destruct(present("skyblade",me));
	destruct(this_object());}
return 1;
}
