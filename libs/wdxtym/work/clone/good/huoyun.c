// chuji_box.c
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIC"限定火云套装"NOR,({"huoyun"}));
	set_weight(1);

	if( clonep() )
		set_default_object(__FILE__);
	else
       {
	    set("long",
		"打开可获得2022火云系列套装！\n"ZJURL("cmds:openbox huoyun")ZJSIZE(15)"打开看看"NOR"\n");
	    set("unit","个");
	    set("win_box",1);
		set("credit",300);
		set("no_drop", 1);
		set("no_put", 1);

	}
}
void init()
{
    if (environment()==this_player())
    add_action("do_openbox","openbox huoyun",1);
}
//打开宝箱的函数
int do_openbox()
{
   int i;
   int num=1;
   string obj="";
   object ob;


	object me = this_player();
	if (me->is_busy())
	{ write("你上一个动作未完成！\n"); return 1;}
	if( me->is_fighting() )
	{ write("先干完这场架再打开。\n"); return 1;}


	ob = new("clone/good/huoyun/bg1");
	ob->move(me);
	ob = new("clone/good/huoyun/bg2");
	ob->move(me);
//	ob = new("clone/good/huoyun/bg3");
//	ob->move(me);
	ob = new("clone/good/huoyun/bg4");
	ob->move(me);
	ob = new("clone/good/huoyun/bg5");
	ob->move(me);
	ob = new("clone/good/huoyun/bg6");
	ob->move(me);
	ob = new("clone/good/huoyun/bg7");
	ob->move(me);
	ob = new("clone/good/huoyun/bg8");
	ob->move(me);
	ob = new("clone/good/huoyun/bg9");
	ob->move(me);
//	ob = new("clone/good/huoyun/bg10");
//	ob->move(me);
	ob = new("clone/good/huoyun/bg11");
	ob->move(me);
	ob = new("clone/good/huoyun/bg12");
	ob->move(me);

        tell_object(me,HIW"你获得了：\n" +
        1 + "件火云甲\n" +
        1 + "件火云戒\n" +
        1 + "件火云手\n" +
        1 + "件火云盔\n" +
        1 + "件火云链\n" +
        1 + "件火云腿\n" +
        1 + "件火云靴\n" +
 //       1 + "件白骨衣\n" +
//        1 + "件白骨披\n" +
        1 + "件火云盾\n" +
        1 + "件火云腰\n" +
        1 + "件火云腕\n" +
		
        NOR);

    destruct(this_object());
	return 1;
}
int query_autoload()
{
	return 1;
}