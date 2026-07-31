#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIY"神雕侠侣"NOR, ({ "sdxl" }) );
            set("no_put", 1);
            set("value", 0);
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	      
            set("unit", "本");
            set("material", "paper");
            set("long", "神书之一,若是能找齐射雕英雄传和倚天屠龙记就能(combine)。\n");
          }

    setup();
}
void init()
{
    add_action("do_combine","combine");
}
int do_combine()
{
	object me,newbook,*inv,ob;
	int sizeinv;
	me = this_player();
	newbook =new(__DIR__"3book");
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("你先把身上的人放下吧!!\n");
       		
		}
// if (!present("yttlj", me)||!present("sdyxz",me))
    if (!(ob = present("yttlj", me)) ||
        !(ob = present("sdyxz", me)))	
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

       message_vision("$N把从怀中翻出的射雕英雄传和倚天屠龙记两本神书，和手中的神雕侠侣合并成了一本。\n", me);
	newbook->move(me);
	destruct(present("yttlj",me));
	destruct(present("sdyxz",me));
	destruct(this_object());}
return 1;
}