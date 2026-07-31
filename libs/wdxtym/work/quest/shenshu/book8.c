#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(BLU"飞狐外传"NOR, ({ "fhwz" }) );
            set("no_put", 1);
            set("value", 0);

    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	         
           set("unit", "本");
            set("material", "paper");
                       set("long", "神书之一,若是能找另一本雪山飞狐就能拼成(ping)。\n");
          }

    setup();
}
void init()
{
    add_action("do_ping","ping");
}
int do_ping()
{
	object me,newbook,ob;
			object *inv;
	int sizeinv;
	me = this_player();
	newbook =new(__DIR__"2book");
 //if (!present("xsfh", me))
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("你先把身上的人放下吧!!\n");
       		
		}
    if (!(ob = present("xsfh", me)) )
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
       message_vision("$N把从怀中翻出的雪山飞狐，和手中的飞狐外传合并成了一本。\n", me);
	newbook->move(me);
	destruct(present("xsfh",me));
	destruct(this_object());}
return 1;
}
