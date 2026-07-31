#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIG"闯荡江湖"NOR, ({ "cdjh" }) );
            set("no_put", 1);
            set("value", 0);
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	         
            set("unit", "本");
            set("material", "paper");
            set("long", "神书之一,若是能找齐神州无敌，寂寞高手，天下有雪就能(redo)。\n");
          }

    setup();
}
void init()
{
    add_action("do_redo","redo");
}
int do_redo()
{
	object me,newbook,ob;
	object *inv;
	int sizeinv;
	me = this_player();
	newbook =new(__DIR__"xia");
// if (!present("szwudi", me)
// ||!present("jmgaoshou",me)
// ||!present("txsnow",me))
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("你先把身上的人放下吧!!\n");
       		
		}
    if (!(ob = present("szwudi", me)) ||
        !(ob = present("jmgaoshou", me)) ||
        !(ob = present("txsnow", me)))	
	tell_object(me,"书好象没齐.\n");
     else{
        if( ob->query("ownmake"))
	return notify_fail("这里面有假货吧。\n");
        if(userp(ob))
	return notify_fail("这里面有假货吧。\n");
        if( ob->is_character() || ob->is_corpse() )
	return notify_fail("这里面有假货吧。\n");
    if(!ob->query("dynamic_quest"))
	return notify_fail("这里面有假货吧。\n");
       message_vision("$N把从怀中翻出的神州无敌，寂寞高手，天下有雪，和手中的闯荡江湖合并成了一本。\n", me);
	newbook->move(me);
	destruct(present("szwudi",me));
	destruct(present("jmgaoshou",me));
	destruct(present("txsnow",me));
	destruct(this_object());}
return 1;
}
