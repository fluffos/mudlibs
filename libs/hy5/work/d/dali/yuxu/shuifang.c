inherit ROOM;
string look_sign(object me);
void create()
{
set("short", "Ë¯·¿");
	set("long", @LONG
ÕâÀï¾ÍÊÇÓñÐé¹ÛÄÚµÄË¯·¿¡£¼¸ÕÅÐ¡´²£¬´²ÉÏ¹Ò×ÅÕÊ×Ó£¬·¿¼äºÜÊÇ¼òÆÓ£¬
Ã»ÓÐÊ²Ã´¶àµÄ¶«Î÷£¬·¿¼ä½ÇÂäÓÐÒ»¸ö¹ñ×Ó¡£¿¿Ç½¹ÒÁËÕÅºÜ´óµÄ»­.
Ð
LONG
	);
        set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 1 */
	    "west" : __DIR__"yuxuguan",

]));
set("item_desc", ([
		"image": (: look_sign :),
		"»­": (: look_sign :),
		
	]) );
       
	set("no_clean_up", 0);

	setup();
//	replace_program(ROOM);
}
string look_sign(object me)
{
	if(me->query_skill("whip",1)<30 ) {
    return " ÕâÊÇÒ»¸±¹Å»­,»­ÉÏÃè»æµÄÊÇÂåÉñ¸³ÖÐµÄ¹ÊÊÂ ¡£\n";
	} else {
	me->set_temp("yuxu_image",1);
	return "  ÕâÊÇÒ»¸±¹Å»­,»­ÉÏÃè»æµÄÊÇÂåÉñ¸³ÖÐµÄ¹ÊÊÂ,»­ÖÐÃÀÅ®»ÓÎè³¤Ðä,
ôæôæÆðÎè, ÉíÐÎÆ®Æ®,Äã¶¨ÁË¶¨Éñ£¬ÒþÔ¼¸Ð¾õ»­ÀïËÆºõÒþ²Ø×Å¼«Îª¸ßÃ÷µÄ±Þ·¨\n";
}
}

void init()
{
        add_action("do_huiwu", "huiwu");  
}

int do_huiwu(string arg)
{
	object me=this_player();
	object weapon = me->query_temp("weapon");

    if (!me->query_temp("yuxu_image", 1)) return 0;

    if( !arg || arg!="image" ) {
                write("ÄãÒª¸ù¾ÝÊ²Ã´»ÓÎè£¡\n");
                return 1;
        }
        if (!weapon || weapon->query("skill_type") != "whip" )
		return notify_fail("ÄãÊÖÖÐÎÞ±Þ£¬ÔõÃ´Áì»á£¿\n");

        if ((int)me->query_skill("whip", 1) >100 )
        return notify_fail("ÄãÒÑ¾­½ß¾¡È«Á¦È¥Ìå»á»­ÉÏ°µ²ØµÄ±Þ·¨¾«Òª£¬µ«ÊÇÎÞ·¨ÔÙÔö³¤ÄãµÄ»ù±¾±Þ·¨ÁË£¡\n");
    
	    me->receive_damage("jingli", 10+random(15));
	     me->receive_damage("jing",random(10));
        write("Äã¶ÔÕÕ×Å¹Å»­ÉÏ°µ²ØµÄ±Þ·¨¾«Òå£¬»ÓÎè×Å£¬½¥½¥µØÎò³öÁËÒ»Ð©ÓÐ¹Ø»ù±¾±Þ·¨µÄ¾«ÒªÖ®ËùÔÚ¡£\n");
         me->improve_skill("whip", me->query("int"));       
         return 1;
}                                     
int valid_leave(object me, string dir)
{
	me->set_temp("yuxu_image", 0);
       return 1;
	 
}
