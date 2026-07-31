// chuji_box.c
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIW"木盒子"NOR,({"木盒子"}));
	set_weight(1);

	if( clonep() )
		set_default_object(__FILE__);
	else
       {
	    set("long",
		"这小木盒子满是灰尘，粘满了煤屑柴草，你似乎可以把它"ZJURL("cmds:打开 木盒子")ZJSIZE(15)"打开"NOR"看看!\n");
	    set("unit","盒");
	    set("win_box",1);
	}
}
void init()
{
    if (environment()==this_player())
    add_action("do_openbox","打开 木盒子",1);
}
//打开宝箱的函数
int do_openbox()
{
   object ob;

	object me = this_player();
	if (me->is_busy())
	      { write("你上一个动作未完成！\n"); return 1;}
	if( me->is_fighting() )
	      { write("先干掉敌人再开不迟。\n"); return 1;}

	message_vision(HIM"$N伸手打开["+this_object()->query("name")+"]，盒子里有一本书，上写《魔教医术》四字，用钳子揭开数页，见写满密密小字，又有许多图画，有的是地图，有的是药材图案。"NOR"\n",me);	
		ob = new("/clone/book/mojiao");
		ob->move(me);
		write(HIG"你得到了一本魔教医术。 "NOR"\n");
    destruct(this_object());
	return 1;
}
int query_autoload()
{
	return 1;
}