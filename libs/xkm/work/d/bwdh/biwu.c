#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "º£ÌìÒ»Ïß");
        set("long", @LONG
ÕâÊ±Ò»¿éÊ¥µØ¡£ÎäÁÖÈËÊ¿Í¨³£¶¼À´´Ë´¦½øĞĞÇĞ´è±ÈÎä£¬Ñ°ÕÒÖª¼º¡£
Ö»¼ûÉÏÊ×ÓĞĞ©Ê«¾ä£¬Ò²²»ÖªÊÇÄÄÎ»ÈËÎïÁôÏÂµÄÊÖ±Ê¡£ÔÚ°ø±ßÓĞÒ»¿éÊ¯
Í·£¬ÉÏ¿Ì£º
[34m
                       Ğ¦ÎÊÒ¶Âä¿´·çÔÆ£¬
                       »ØÊ×»¯ÔÂÍûÇïË®¡£
                                       
[37m
Äã¿ÉÒÔÊÔÊÔÔÚÕâ¸öÓĞÁéÆøµÄµØ·½ÌáÉı(levelup)ÎäÆ÷µÄµÈ¼¶¡£
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "out" : __DIR__"square",
]));
       
	set("no_death_penalty",1);
	set("no_dazuo",1);
	       
	setup();
}
void init()
{
	add_action("do_levelup","levelup");
        add_action("do_quit","exercise");
        add_action("do_quit","get");
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
        if( !arg ) return notify_fail("ÄãÒªÌáÉıÊ²÷áÎäÆ÷£¿\n");
        gold = present("gold_money", this_player());
        if( !gold) return notify_fail("ÄãÉíÉÏÃ»ÓĞ½ğ×Ó¡£\n");
        if( !objectp(ob = present(arg, me)) )
        return notify_fail("ÄãÉíÉÏÃ»ÓĞÕâÑù¶«Î÷¡£\n");
        if(me->is_busy())
        return notify_fail("ÄãÉÏÒ»¸ö¶¯×÷»¹Ã»ÓĞÍê³É¡£\n");
        if( ob->query("equipped") )
        return notify_fail("Äã²»¿É¼À×°±¸ÖøÁËµÄÎäÆ÷¡£\n");
        if( !ob->query("ownmake") )
        return notify_fail("ÄãÖ»¿É¼À×Ô¼º´òÔìµÄÎäÆ÷¡£\n");
	if( (int)me->query("qi") < 150 )
		return notify_fail("ÄãµÄÆø²»¹»£¬ÎŞ·¨¶ÍÁ¶±øÆ÷£¡\n");

	if( (int)me->query("eff_qi") < 30 )
		return notify_fail("ÄãÏÖÔÚµÄÌåÁ¦Ì«Èõ£¬ÎŞ·¨¶ÍÁ¶±øÆ÷£¡\n");

	if( (int)me->query("eff_jing") < 10 )
		return notify_fail("ÄãÏÖÔÚµÄ¾«Á¦ÎŞ·¨¼¯ÖĞ£¬²»ÄÜ¶ÍÁ¶±øÆ÷£¡\n");
	if( (int)me->query("meng/pts") < 5 )
		return notify_fail("ÄãÏÖÔÚÃ»ÓĞÎªÃÎ×öÊ²Ã´¹±Ï×£¬²»ÄÜÔÚÕâ¶ÍÁ¶±øÆ÷£¡\n");

	if( (int)me->query("potential") < 120 )
		return notify_fail("ÄãµÄÇ±ÄÜ²»¹»£¬ÎŞ·¨¶ÍÁ¶±øÆ÷£¡\n");
	
	if(arg!="armor"&&"jia") 
	{j = (int)me->query("myweapon/lv");
	if(j>39) return notify_fail("ÄãµÄ±øÆ÷ÒÑ¾­µ½¼«ÏŞÁË£¬²»ÄÜÔÙÉı¼¶ÁË£¡\n");
	if(j<6) cost = 5*j;
	else if(j<11) cost = 10*j;
	else if(j<16) cost = 20*j;
	else if(j>30) cost = 100*j;
	else cost = 50*j;
        if((int) gold->query_amount() < cost)
        return notify_fail("ÄãÉíÉÏÃ»´ø¹»" + sprintf("%d",cost)+ "Á½½ğ×Ó¡£\n");
        gold->add_amount(-cost);
        me->start_busy(2);
	me->add("bellicosity",cost);
	seteuid(ROOT_UID);
	me->add("qi",-150);
	me->add("eff_qi",-30);
	me->add("jing",-30);
	me->add("eff_jing",-30);
	me->add("potential", -120);
	me->add("meng/pts",-j+5);
	me->set("myweapon/lv", j+1);
	me->save();
	reload_object(ob);
	message_vision(HIY "±ŞÉíºöµÄÒ»ÁÁ£¬Ò»µÀ½ğ¹âÒşÈë$NµÄ"+ob->name()+HIY"£¬²»¼ûÁË£¡\n" NOR,me);
	message_vision(HIG "$NµÄ"+ob->name()+HIG"µÄµÈ¼¶Ìá¸ßÁË£¡\n" NOR, me);
        seteuid(getuid());
	return 1;}
	else
	{j = (int)me->query("jia/lv");
	 if(j>39) return notify_fail("ÄãµÄ»¤¼×ÒÑ¾­µ½¼«ÏŞÁË£¬²»ÄÜÔÙÉı¼¶ÁË£¡\n");

	if(j<6) cost = 15*j;
	else if(j<11) cost = 10*j;
	else if(j<16) cost = 20*j;
	else if(j>30) cost = 100*j;
	else cost = 50*j;
        if((int) gold->query_amount() < cost)
        return notify_fail("ÄãÉíÉÏÃ»´ø¹»" + sprintf("%d",cost)+ "Á½½ğ×Ó¡£\n");
        gold->add_amount(-cost);
        me->start_busy(2);
	me->add("bellicosity",cost);
	seteuid(ROOT_UID);
	me->add("qi",-150);
	me->add("eff_qi",-30);
	me->add("jing",-30);
	me->add("eff_jing",-30);
	me->add("potential", -120);
	me->add("meng/pts",-j+5);
	me->set("jia/lv", j+1);
	me->save();
	reload_object(ob);
	message_vision(HIY "¼×ÉíºöµÄÒ»ÁÁ£¬Ò»µÀ½ğ¹âÒşÈë$NµÄ"+ob->name()+HIY"£¬²»¼ûÁË£¡\n" NOR,me);
	message_vision(HIG "$NµÄ"+ob->name()+HIG"µÄµÈ¼¶Ìá¸ßÁË£¡\n" NOR, me);
        seteuid(getuid());
	return 1;
	}
}

int do_quit(string arg)
{
	if(arg=="all") {
        write(this_player()->query("name")+"£¬°²ĞÄµÄ±ÈÎä°É£¡\n");
        return 1;
	}
	if(arg=="corpse") {
        write(this_player()->query("name")+"£¬°²ĞÄµÄ±ÈÎä°É£¡\n");
        return 1;
}  
}
