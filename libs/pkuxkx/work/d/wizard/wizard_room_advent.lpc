// Room: /d/wizard/wizard_room.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", MAG"行云工作室"NOR);
        set("long", HIW @LONG
这里就是行云的工作室了。作为一个工作狂人，他的办公室你可以想象是多么的乱糟糟。
中间还有一块白板（board），估计是给小弟们做persentation用的。
LONG NOR);

	set("exits", ([ /* sizeof() == 1 */
        "north" : "/u/advent/workroom" ,
        "dls" : "/d/dalunsi/guangchang",
         "hz":"/d/hangzhou/zhongxin",
        "xs" : "/d/lingxiao/chengmen",
        "south":"/d/wizard/wizard_room_whuan",
  	]));

	set("valid_startroom", 1);
	set("no_clean_up", 0);
	setup();
  "/clone/board/advent_b"->foo();

 //   call_other("/clone/board/plan_b", "???");
//	call_other("/clone/board/wiz_b", "???");
}
/*
void init()
{
        object me = this_player();
        add_action("do_search","search");
        if(me->query("id") != "pal" && !wizardp(me))
        {
                me->move("/d/city/guangchang");
                me->delete("env/immortal");
                me->delete("invisibility");
                me->delete("last_damage_from");
                me->die();
//                message("channel:rumor",HIM"【谣言】听说"+me->query("name")+HIM"从"HIY"香蕉树"HIM"上掉到中央广场摔死了！\n"NOR,users());
        }
        return;
}

*/
