#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(CYN"浣花洗剑录"NOR, ({ "swordlu" }) );
    set_weight(1);
            set("no_put", 1);
            set("value", 0);

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

 	if (arg!="gulongbookb")
	return notify_fail("你要合并什么？\n");

	newbook =new(__DIR__"gbook2");

    if (!(ob = present("fyblade", me)) ||
        !(ob = present("tiger", me)) ||
!(ob = present("skyblade", me)) ||
!(ob = present("bclangzi", me)) ||
!(ob = present("fengling", me)) ||
!(ob = present("xiesword", me)) 
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
        message_vision("$N把从怀中翻出七本古龙大侠写的神书，并成了一本。\n", me);
	newbook->move(me);
	destruct(present("fyblade",me));
	destruct(present("tiger",me));
	destruct(present("skyblade",me));
	destruct(present("bclangzi",me));
	destruct(present("fengling",me));
	destruct(present("xiesword",me));

	destruct(this_object());}
return 1;
}
