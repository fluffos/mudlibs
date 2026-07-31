#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIR"武动仙途"NOR, ({ "xajh" }) );
    set_weight(1);
            //set("no_put", 1);
            set("value", 100000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	        
            set("dynamic_quest",1);
            set("unit", "本");
            set("material", "paper");
            set("long", "神书之一。\n");
          }

    setup();
}

void init()
{
    add_action("do_zhuang","he");
}
int do_zhuang(string arg)
{
	object me,newbook,ob;
	object *inv;
	int sizeinv;

	me = this_player();


 	if (arg!="jinbooka")
	return notify_fail("你要合并什么？\n");
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("你先把身上的人放下吧!!\n");
       		
		}
	newbook =new(__DIR__"jbook1");

    if (!(ob = present("sjec", me)) ||
        !(ob = present("sdxl", me)) ||
!(ob = present("xkx", me)) ||
!(ob = present("yttlj", me)) ||
!(ob = present("bxsword", me)) ||
!(ob = present("yyblade", me)) 
        )
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
        message_vision("$N把从怀中翻出的笑书神侠倚碧鸳七本书，并成了一本。\n", me);
	newbook->move(me);
	destruct(present("sjec",me));
	destruct(present("sdxl",me));
	destruct(present("xkx",me));
	destruct(present("bxsword",me));
	destruct(present("yttlj",me));
	destruct(present("yyblade",me));

	destruct(this_object());}
return 1;
}
