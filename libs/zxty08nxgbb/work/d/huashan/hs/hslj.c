#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIG"»ªÉ½Ö®µß"NOR);
        set("long", @LONG
   ÎäÁÖÖÐµÄÒ»¿éÊ¥µØ¡£µ±ÄêÖÐÔ­Îå¾øÔÚ´Ë´¦±ÈÎä¶¨Î»ÒÔ¾ö¶¨ÌìÏÂµÚÒ»,
ÏÖÔÚÃ¿¸ôÒ»¶ÎÊ±¼ä£¬ÔÚ´Ë¾Í»á¾ÙÐÐÒ»´Î»ªÉ½ÂÛ½££¬ÒÔ¿¼Ñé½­ºþÐÂÐãµÄÄÜÁ¦
¡£ÔÚ°ø±ßÓÐÒ»¿éÊ¯Í·£¬ÉÏÃæ¿ÌÓÐÒ»Ð©ÈËµÄÃû×Ö£º
[33m
                       ¶«Ð° Î÷¶¾£¬
                       ÄÏµÛ ±±Ø¤¡£
                        ÖÐÉñÍ¨              
[36m
              Äã¿ÉÒÔÌôÕ½ÖÐÔ­Îå¾ø½øÐÐ»ªÉ½ÂÛ½£¡£(lunjian)
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "down" : "/d/huashan/lianhua",
]));
       
	set("citybiwu",1);
	set("no_death_penalty",1);
	set("no_get",1);
	set("no_dazuo",1);
	       
	setup();
}
void init()
{
	add_action("do_levelup","lunjian");
        add_action("do_quit","exert");
        add_action("do_quit","exercise");
        add_action("do_quit","get");
        add_action("do_quit2","quit");
        add_action("do_quit2","exit");
        add_action("do_quit2","exercise");
        add_action("do_quit2","halt");
        add_action("do_quit2","dazuo");
        add_action("do_quit2","learn"); 
        add_action("do_quit2","xue");
        add_action("do_quit2","respirate");
        add_action("do_quit2","tuna"); 
        add_action("do_quit2","persuade");
        add_action("do_quit2","practice");
        add_action("do_quit2","lian"); 
        add_action("do_quit2","study");
        add_action("do_quit2","du");
        add_action("do_quit2","teach");
        add_action("do_quit2","jiao");
}
int  do_levelup(string arg)
{
	object me, ob;
	object fight;
	int cost = 1;
	int i,j,base,current;
	string id,name ;	
	string file,newfile,filestring;
	me = this_player();
	id = me->query("id");
        if (me->is_fighting()) 
        return notify_fail("ÄãÕýÔÚ»ªÉ½ÂÛ½£ÄØ!\n");
	if( me->is_busy() )
		return notify_fail("ÄãÕýÃ¦×ÅÄØ! \n");
        if (!wizardp(me) && !me->query("guard/flag"))
	return notify_fail("ÄãµÄ½­ºþ¾­Ñé»¹²»¹»£¬Ã»ÓÐ×Ê¸ñ»ªÉ½ÂÛ½££¡\n");
        if (!wizardp(me) && me->query("combat_exp")< 5000000)
	return notify_fail("ÄãµÄÄÜÁ¦»¹²»¹»£¬Ã»ÓÐ×Ê¸ñ»ªÉ½ÂÛ½££¡\n");
	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
	return notify_fail("ÄãµÄÔÓÑ§Ì«¶à£¬»ªÉ½ÂÛ½£Ö»ÔÊÐíÄÜ´ú±íÒ»·½ÃÅÅÉµÄÐÂÐã²Î¼Ó£¡\n");
	if(!wizardp(me) && me->query("guard/ok"))
	return notify_fail("ÄãÒÑ¾­Í¨¹ýÁË»ªÉ½ÂÛ½£ÁË£¡\n");

	if(environment(me)->query("alrd")
	 && !me->query_temp("hslj/1"))
	return notify_fail("ÏÖÔÚ»¹²»µ½»ªÉ½ÂÛ½£µÄÊ±¼ä£¬»òÒÑ¾­¿ªÊ¼ÁË£¡\n");
environment(me)->set("alrd",1);
if (!me->query_temp("hsljn"))
{
environment(me)->set("alrd",1);
message("channel:chat", HIG"¡¾»ªÉ½ÂÛ½£¡¿ÌýËµ"+me->name() + "ÔÚ»ªÉ½Ö®µßÌôÕ½ÖÐÔ­Îå¾ø!"NOR"\n", users());
me->set_temp("hsljn",1);
}
me->start_busy(2);

if (!me->query_temp("hslj"))
{
fight=new(__DIR__"huang");
fight->move(environment(me));
if (fight->query("combat_exp") < me->query("combat_exp"))
fight->set("combat_exp",me->query("combat_exp"));
fight->kill_ob(me);
message("channel:chat", CYN"¡¾»ªÉ½ÂÛ½£¡¿ÌýËµ"+me->name() + "ÔÚ»ªÉ½Ö®µßÌôÕ½¶«Ð°»ÆÒ©Ê¦!"NOR"\n", users());
}
else
if (me->query_temp("hslj/1")
&& !me->query_temp("hslj/2")
&& !me->query_temp("hslj/3")
&& !me->query_temp("hslj/4")
&& !me->query_temp("hslj/5"))
{
fight=new(__DIR__"hong");
fight->move(environment(me));
fight->kill_ob(me);
if (fight->query("combat_exp") < me->query("combat_exp"))
fight->set("combat_exp",me->query("combat_exp"));
message("channel:chat", YEL"¡¾»ªÉ½ÂÛ½£¡¿ÌýËµ"+me->name() + "ÔÚ»ªÉ½Ö®µßÌôÕ½±±Ø¤ºéÆß¹«!"NOR"\n", users());
}
else
if (me->query_temp("hslj/2")
&& !me->query_temp("hslj/3")
&& !me->query_temp("hslj/4")
&& !me->query_temp("hslj/5"))
{

fight=new(__DIR__"yideng");
fight->move(environment(me));
fight->kill_ob(me);
if (fight->query("combat_exp") < me->query("combat_exp"))
fight->set("combat_exp",me->query("combat_exp"));
message("channel:chat", HIY"¡¾»ªÉ½ÂÛ½£¡¿ÌýËµ"+me->name() + "ÔÚ»ªÉ½Ö®µßÌôÕ½ÄÏµÛÒ»µÆ!"NOR"\n", users());
}
else
if (me->query_temp("hslj/3")
&& !me->query_temp("hslj/4")
&& !me->query_temp("hslj/5")
)
{
fight=new(__DIR__"ouyangfeng");
fight->move(environment(me));
fight->kill_ob(me);
if (fight->query("combat_exp") < me->query("combat_exp"))
fight->set("combat_exp",me->query("combat_exp"));
message("channel:chat", HIR"¡¾»ªÉ½ÂÛ½£¡¿ÌýËµ"+me->name() + "ÔÚ»ªÉ½Ö®µßÌôÕ½Î÷¶¾Å·Ñô·æ!"NOR"\n", users());
}
else
if (!me->query_temp("hslj/5"))
{
fight=new(__DIR__"wang");
fight->move(environment(me));
fight->kill_ob(me);
if (fight->query("combat_exp") < me->query("combat_exp"))
fight->set("combat_exp",me->query("combat_exp"));
message("channel:chat", HIB"¡¾»ªÉ½ÂÛ½£¡¿ÌýËµ"+me->name() + "ÔÚ»ªÉ½Ö®µßÌôÕ½ÖÐÉñÍ¨ÍõÖØÑô!"NOR"\n", users());
}
else 
{
me->set("guard/ok",1);
me->save();
message("channel:chat", HIW"¡¾»ªÉ½ÂÛ½£¡¿ÌýËµ"+me->name() + "ÔÚ»ªÉ½Ö®µßÍ¨¹ýÁËÖÐÔ­Îå¾øµÄ¿¼Ñé!"NOR"\n", users());
}
return 1;
}

int do_quit(string arg)
{
	if(arg=="roar") {
        write(this_player()->query("name")+"£¬°²ÐÄµÄ»ªÉ½ÂÛ½£°É£¡\n");
        return 1;
	}

	if(arg=="all") {
        write(this_player()->query("name")+"£¬°²ÐÄµÄ»ªÉ½ÂÛ½£°É£¡\n");
        return 1;
	}
	if(arg=="corpse") {
        write(this_player()->query("name")+"£¬°²ÐÄµÄ»ªÉ½ÂÛ½£°É£¡\n");
        return 1;
}  
}
int do_quit2(string arg)
{
        write(this_player()->query("name")+"£¬°²ÐÄµÄ»ªÉ½ÂÛ½£°É£¡\n");
        return 1;
}

int valid_leave(object me, string dir)
{
	object *inv,kicker;
	int sizeinv,n,tt;
       if (  me->is_fighting() )
        return notify_fail("Äã²»ÕýÔÚ±ÈÎäÂð£¡\n");
	
        me->delete_temp("hsljn");
	return ::valid_leave(me, dir);

}

