// chuji_box.c
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIC"限定追月套装"NOR,({"zhuiyue"}));
	set_weight(1);

	if( clonep() )
		set_default_object(__FILE__);
	else
       {
	    set("long",
		"打开可获得2121追月系列套装！\n"ZJURL("cmds:openbox zhuiyue")ZJSIZE(15)"打开看看"NOR"\n");
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
    add_action("do_openbox","openbox zhuiyue",1);
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


	ob = new("clone/good/zhuiyue/bg1");
	ob->move(me);
	ob = new("clone/good/zhuiyue/bg2");
	ob->move(me);
//	ob = new("clone/good/zhuiyue/bg3");
//	ob->move(me);
	ob = new("clone/good/zhuiyue/bg4");
	ob->move(me);
	ob = new("clone/good/zhuiyue/bg5");
	ob->move(me);
	ob = new("clone/good/zhuiyue/bg6");
	ob->move(me);
	ob = new("clone/good/zhuiyue/bg7");
	ob->move(me);
	ob = new("clone/good/zhuiyue/bg8");
	ob->move(me);
	ob = new("clone/good/zhuiyue/bg9");
	ob->move(me);
//	ob = new("clone/good/zhuiyue/bg10");
//	ob->move(me);
	ob = new("clone/good/zhuiyue/bg11");
	ob->move(me);
	ob = new("clone/good/zhuiyue/bg12");
	ob->move(me);

        tell_object(me,HIW"你获得了：\n" +
        1 + "件雨中客 · 追月甲\n" +
        1 + "件雨中客 · 追月戒\n" +
        1 + "件雨中客 · 追月手\n" +
        1 + "件雨中客 · 追月盔\n" +
        1 + "件雨中客 · 追月链\n" +
        1 + "件雨中客 · 追月腿\n" +
        1 + "件雨中客 · 追月靴\n" +
 //       1 + "件白骨衣\n" +
//        1 + "件白骨披\n" +
        1 + "件雨中客 · 追月盾\n" +
        1 + "件雨中客 · 追月腰\n" +
        1 + "件雨中客 · 追月腕\n" +
		
        NOR);

    destruct(this_object());
	return 1;
}
int query_autoload()
{
	return 1;
}