//liwu  元宵节礼物盒(随机北侠套装)
//Made By westernd
//2015-03
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("礼物盒",({"liwu he","box"}));
        set("long","这个是庆祝元宵节的礼物盒(open)?\n");
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
    me = this_player();
    if (!arg)  return notify_fail("你打开什么？\n");
    if((arg=="liwu he") || (arg=="box")) 
    {
		int m = random(9);
		if (m=0) {p=new("obj/taozhuang/nanxia/nxdanshan");}
		if (m=1) {p=new("obj/taozhuang/nanxia/nxsuixin");}
		if (m=2) {p=new("obj/taozhuang/nanxia/nxjingtian");}
		if (m=3) {p=new("obj/taozhuang/nanxia/nxwulei");}
		if (m=4) {p=new("obj/taozhuang/nanxia/nxkaitian");}
		if (m=5) {p=new("obj/taozhuang/nanxia/nxtianxia");}
		if (m=6) {p=new("obj/taozhuang/nanxia/nxbaolie");}
		if (m=7) {p=new("obj/taozhuang/nanxia/nxniannu");}
		if (m=8) {p=new("obj/taozhuang/nanxia/nxluanshi");}
		if (m=9) {p=new("obj/taozhuang/nanxia/nxbingjie");}
		
   		p->move(me);
        tell_object(me, "你发现了一件北侠神兵。\n");
        destruct(this_object());
     }
     return 1;
}
