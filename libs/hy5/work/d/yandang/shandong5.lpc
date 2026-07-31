// Room: /d/yandang/shandong5
#include <ansi.h>
inherit ROOM;

void create()
{
  set ("short", "好运洞");
  set ("long", @LONG
洞中一无所有,但却十分光亮,也不知光线从何传来,整个洞窟是由
一种说不出名的白色晶石组成,很是坚硬.在洞顶,赫然刻着几句词'好运
不好运,自有天注定',下面落款是广成子.洞的正中有一个石香炉(lu).
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"shandong4",
  "northup" : __DIR__"shandong6",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "lu" : "一个巨大的香炉,你在观音洞求来的签可以在这烧(born)一下看看.
也许会出现奇迹耶.
",
]));
  setup();
}
void init()
{
	add_action("do_born", "born");
}
int do_born(string arg)
{
		object me,ob;
		me=this_player();
             ob=present("qian",me);
             if (!ob) return notify_fail("你身上没有灵签!\n");

	    if( (arg!="qian")&&(arg!="灵签") ) return notify_fail("你要烧什么?\n");
	    	message_vision("$N把灵签投入香炉中,一股绿色火苗涌上来,把签吞没了。\n", this_player());
		switch( random(3) ) 
		{
			case 0:
                    message_vision(HIC"一行字迹在火光中隐约闪现:心有灵犀,天佑善人.\n"NOR,me);
                    tell_object(me,"你心神一颤,灵台清朗,你的经验增加了!\n");
                    me->set("combat_exp",(me->query("combat_exp"))+150);				
                    break;
			case 1:
                    message_vision(HIC"一行字迹在火光中隐约闪现:前世因是今世果,今世因是来世果.\n"NOR,me);
                    tell_object(me,"洞顶隐隐传来佛呐梵唱,你心中一片平和!\n");
		       break;
			case 2:
                    message_vision(HIC"一行字迹在火光中隐约闪现:前途暗淡,回头是岸!\n"NOR,me);
                    tell_object(me,"你心中一阵迷茫,六神不定,你的经验下降了!\n");
                    me->set("combat_exp",(me->query("combat_exp"))-150);				
				break;
		}
          destruct(ob);
		return 1;
}
