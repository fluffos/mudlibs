#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(CYN"鹿鼎记"NOR, ({ "ldji" }) );
            set("no_put", 1);
            set("value", 0);
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	         
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
	
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("你先把身上的人放下吧!!\n");
       		
		}

 	if (arg!="jinbookb")
	return notify_fail("你要合并什么？\n");

	newbook =new(__DIR__"jbook2");

    if (!(ob = present("fhwz", me)) ||
        !(ob = present("xsfh", me)) ||
!(ob = present("lcjue", me)) ||
!(ob = present("tlbb", me)) ||
!(ob = present("sdyxz", me)) ||
!(ob = present("bmxxfeng", me)) 
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
        message_vision("$N把从怀中翻出的飞雪连天射白鹿七本书，并成了一本。\n", me);
	newbook->move(me);
	destruct(present("fhwz",me));
	destruct(present("xsfh",me));
	destruct(present("lcjue",me));
	destruct(present("tlbb",me));
	destruct(present("sdyxz",me));
	destruct(present("bmxxfeng",me));

	destruct(this_object());}
return 1;
}
