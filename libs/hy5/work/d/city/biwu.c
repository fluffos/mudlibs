#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "º£ÌìÒ»Ïß");
        set("long", @LONG
º£ÑóÖÐµÄÒ»¿éÊ¥µØ¡£ÎäÁÖÈËÊ¿Í¨³£¶¼À´´Ë´¦½øÐÐÇÐ´è±ÈÎä£¬Ñ°ÕÒÖª¼º¡£
Ö»¼ûÉÏÊ×ÓÐÐ©Ê«¾ä£¬Ò²²»ÖªÊÇÄÄÎ»ÈËÎïÁôÏÂµÄÊÖ±Ê¡£ÔÚ°ø±ßÓÐÒ»¿éÊ¯
Í·£¬ÉÏ¿Ì£º
[34m
                       Ð¦ÎÊÒ¶Âä¿´·çÔÆ£¬
                       »ØÊ×»¯ÔÂÍûÇïË®¡£
                                       
[37m
Äã¿ÉÒÔÊÔÊÔÔÚÕâ¸öÓÐÁéÆøµÄµØ·½ÌáÉý(levelup)ÎäÆ÷µÄµÈ¼¶¡£
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "out" : __DIR__"wudao4",
]));
       
  set("objects", ([ /* sizeof() == 4 */
  "/d/city/npc/xunbu" : 1,
  "/clone/npc/testnpc" : 1,
  "/d/migong/obj/testnpc2" : 1,
]));
	set("citybiwu",1);
	set("no_death_penalty",1);
	set("no_dazuo",1);
	       
	setup();
}
void init()
{
	//add_action("do_levelup","levelup");
        add_action("do_quit","exercise");
        add_action("do_quit","get");
        add_action("do_quit2","quit");
        add_action("do_quit2","exit");
        add_action("do_quit2","exercise");
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
	object gold;
	int cost = 1;
	int i,j,base,current;
	string id,name ;	
	string file,newfile,filestring;
	me = this_player();
	id = me->query("id");
        if( !arg ) return notify_fail("ÄãÒªÌáÉýÊ²÷áÎäÆ÷£¿\n");
        gold = present("gold_money", this_player());
        if( !gold) return notify_fail("ÄãÉíÉÏÃ»ÓÐ½ð×Ó¡£\n");
        if( !objectp(ob = present(arg, me)) )
        return notify_fail("ÄãÉíÉÏÃ»ÓÐÕâÑù¶«Î÷¡£\n");
        if(me->is_busy())
        return notify_fail("ÄãÉÏÒ»¸ö¶¯×÷»¹Ã»ÓÐÍê³É¡£\n");
        if( ob->query("equipped") )
        return notify_fail("Äã²»¿É¼À×°±¸ÖøÁËµÄÎäÆ÷¡£\n");
        if( !ob->query("ownmake") )
        return notify_fail("ÄãÖ»¿É¼À×Ô¼º´òÔìµÄÎäÆ÷¡£\n");
        if( ob->query("armor_type"))
        return notify_fail("ÌáÉý¿ø¼×ÇëÈ¥±ðµÄµØ·½ÓÃjijiaÀ´×ö¡£\n");

	if( (int)me->query("qi") < 150 )
		return notify_fail("ÄãµÄÆø²»¹»£¬ÎÞ·¨¶ÍÁ¶±øÆ÷£¡\n");

	if( (int)me->query("eff_qi") < 30 )
		return notify_fail("ÄãÏÖÔÚµÄÌåÁ¦Ì«Èõ£¬ÎÞ·¨¶ÍÁ¶±øÆ÷£¡\n");

	if( (int)me->query("eff_jing") < 10 )
		return notify_fail("ÄãÏÖÔÚµÄ¾«Á¦ÎÞ·¨¼¯ÖÐ£¬²»ÄÜ¶ÍÁ¶±øÆ÷£¡\n");
	if( (int)me->query("score") < 100 )
		return notify_fail("ÄãÏÖÔÚµÄ½­ºþÔÄÀú²»¹»£¬²»ÄÜ¶ÍÁ¶±øÆ÷£¡\n");

	if( ((int)me->query("potential") - (int)me->query("learned_points"))< 20 )
		return notify_fail("ÄãµÄÇ±ÄÜ²»¹»£¬ÎÞ·¨¶ÍÁ¶±øÆ÷£¡\n");
	j = (int)me->query("weapon/lv");

	if(j<6) cost = 20*j;
	else if(j<11) cost = 30*j;
	else if(j<16) cost = 40*j;
	else if(j>500) cost = 200*j;
	else cost = 60*j;
        if((int) gold->query_amount() < 100)
        return notify_fail("ÄãÉíÉÏÃ»´ø¹»100Á½½ð×Ó¡£\n");

        if((int) gold->query_amount() < cost)
        return notify_fail("ÄãÉíÉÏÃ»´ø¹»" + sprintf("%d",cost)+ "Á½½ð×Ó¡£\n");
        gold->add_amount(-cost);
        me->start_busy(2);
	me->add("bellicosity",cost);
	seteuid(ROOT_UID);
	me->add("qi",-150);
	me->add("eff_qi",-30);
	me->add("jing",-30);
	me->add("eff_jing",-30);
	me->add("score",-100);
	me->add("learned_points", 20);
	me->set("weapon/lv", j+1);
	me->save();
	reload_object(ob);
	message_vision(HIY "±ÞÉíºöµÄÒ»ÁÁ£¬Ò»µÀ½ð¹âÒþÈë$NµÄ"+ob->name()+HIY"£¬²»¼ûÁË£¡\n" NOR,me);
	message_vision(HIG "$NµÄ"+ob->name()+HIG"µÄµÈ¼¶Ìá¸ßÁË£¡\n" NOR, me);
        seteuid(getuid());
	return 1;
}

int do_quit(string arg)
{
	if(arg=="all") {
        write(this_player()->query("name")+"£¬°²ÐÄµÄ±ÈÎä°É£¡\n");
        return 1;
	}
	if(arg=="corpse") {
        write(this_player()->query("name")+"£¬°²ÐÄµÄ±ÈÎä°É£¡\n");
        return 1;
}  
}
int do_quit2(string arg)
{
        write(this_player()->query("name")+"£¬°²ÐÄµÄ±ÈÎä°É£¡\n");
        return 1;
}
