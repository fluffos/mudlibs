//liwu  元宵节礼物盒(随机北侠套装)
//Made By westernd
//2015-03
#include <ansi.h>

inherit ITEM;

string* weapon_ids = ({
"obj/taozhuang/nanxia/nxbingjie",
"obj/taozhuang/nanxia/nxsuixin",
"obj/taozhuang/nanxia/nxdanshan",
"obj/taozhuang/nanxia/nxkaitian",
"obj/taozhuang/nanxia/nxjingtian",
"obj/taozhuang/nanxia/nxwulei",
"obj/taozhuang/nanxia/nxniannu",
"obj/taozhuang/nanxia/nxtianxia",
"obj/taozhuang/nanxia/nxbaolie",
"obj/taozhuang/nanxia/nxluanshi",
});
void create()
{
        set_name("礼物盒",({"liwu he","box"}));
        set("long","这个是庆祝北侠成立的礼物盒(open)?\n");
        set("unit","个");
	    set("no_drop",1);
        set("no_get",1);
        set("value",0);
        set("no_store",1);
       setup();
}

void init()
{
    add_action("do_open","open");
}

int do_open(string arg)
{
    object me;
	object p;
	object q;
    me = this_player();
    if (!arg)  return notify_fail("你打开什么？\n");
    if((arg=="liwu he") || (arg=="box")) 
    {
	p=new(weapon_ids[random(9)]);
	q=new(weapon_ids[random(9)]);
   		p->move(me);
   		q->move(me);
        tell_object(me, "你发现了两件北侠神兵。\n");
        destruct(this_object());
     }
     return 1;
}
