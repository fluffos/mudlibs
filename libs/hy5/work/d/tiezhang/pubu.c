// Room: /u/zqb/tiezhang/pubu.c

inherit ROOM;
void init()
{
	add_action("lingwu","lingwu");
}
void create()
{
	set("short", "[32mÆÙ²¼[0;37;0m");
	set("long", @LONG
    É½Â·ÐÐµ½ÕâÀï£¬ºöÌýÔ¶´¦´«À´ÒþÒþË®Éù£¬×ª¹ýÒ»µÀÉ½Áº£¬Ö»¼ûÒ» 
µÀ°×ÁúËÆµÄ´óÆÙ²¼´Ó¶ÔÃæË«·åÖ®¼ä±¼ÌÚ¶øÏÂ£¬¿ÕÉ½¼Å¼Å£¬ÄÇË®ÉùÔÚÉ½¹ÈÖÐ¼¤ 
µ´»ØÏë£¬ÉùÊÆÉõÊÇ¾ªÈË¡£
LONG	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"xzfeng",
  "eastdown" : __DIR__"sblu-1",
]));
	set("no_clean_up", 0);

	setup();
}

int lingwu(string arg)
{
	object me=this_player();
	string special;
	int bl,sl;

	if (!living(me)) return 0;
	if (me->is_busy() || me->is_fighting()) return notify_fail("ÄãÕýÃ¦×ÅÄØ¡£\n");

	if(me->query("potential") < 100 ) 
         return notify_fail("ÄãµÄÇ±ÄÜÌ«ÉÙÁË!\n");	

	if(me->query("potential") < 0 ) 
         return notify_fail("ÄãµÄÇ±ÄÜÌ«ÉÙÁË!\n");	
	if((int)me->query("potential") - (int)me->query("learned_points") < 200 ) 
         return notify_fail("ÄãµÄÇ±ÄÜÌ«ÉÙÁË!\n");	
	

	//if (!me->query("luohan_winner")) return notify_fail("Äã¼¶±ð²»¹»£¬²»ÄÜÔÚ´ËÁìÎò¡£\n");
	if (!arg) return notify_fail("ÄãÒªÁìÎòÊ²Ã´£¿\n");
	if (!me->query_skill(arg,1))
		return notify_fail("Äã²»»áÕâÖÖ¼¼ÄÜ¡£\n");
	if (!(special=me->query_skill_mapped(arg)))
		return notify_fail("ÄãÖ»ÄÜ´ÓÌØÊâ¼¼ÄÜÖÐÁìÎò¡£\n");
	bl=me->query_skill(arg,1);
	if (bl > me->query("jing") || me->query("jing")*100/me->query("max_jing") < 20) {
		me->receive_damage("jing",bl/2);
		return notify_fail("ÄãÃ»°ì·¨¼¯ÖÐ¾«Éñ¡£\n");
	}
	if(me->query("potential") < 100 ) 
         return notify_fail("ÄãµÄÇ±ÄÜÌ«ÉÙÁË!\n");	

	sl=me->query_skill(special,1);
	if (bl > sl)
		return notify_fail("ÄãµÄ"+to_chinese(special)+"ÔìÒè²»¹»£¬ÎÞ·¨ÁìÎò¸üÉîÒ»²ãµÄ"+CHINESE_D->chinese(arg)+"¡£\n");
	write("Äãî¨Ë¼¿àÏë£¬¶Ô"+to_chinese(arg)+"µÄÌå»áÓÖÉîÁËÒ»²ã¡£\n");
	me->receive_damage("jing",bl/2);
//	if(me->query("combat_exp") > 1000000 ) {
//        me->add("potential", -random(3));
//        }
        if(me->query("combat_exp") < 2000000 )
         {
	me->improve_skill(arg,sl/5+1);
         }
else {
	me->improve_skill(arg,sl/10+1);
}
	return 1;
}
