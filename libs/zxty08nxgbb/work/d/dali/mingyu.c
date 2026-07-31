// Room: /d/dali/mingyu.c
// Data: ¹şµÏË¹(hades)
// Time: ¹«Ôª£º1999Äê4ÔÂ19ÈÕ£¬±±¾©Ê±¼ä£º21Ê±18·Ö3Ãë¡£

inherit ROOM;

void create()
{
	set("short", "ÃùÓñ·»Íâ");
	set("long", @LONG
´ËÂ¥Ëä²»ÔÚ¾©¶¼£¬µ«È´ÊÇ´óÀí×îÓĞÃûµÄÇàÂ¥¡£ÕâÀïÓĞ×î¹óµÄ¾Æ£¬Ò²ÊÇ×îºÃµÄ¾Æ£»
ÕâÀïÓĞ×î¹óµÄÅ®ÈË£¬Ò²ÊÇ×îÓĞÎ¶¶ùµÄÅ®ÈË£»ÕâÀïÓĞ×î¹óµÄ·şÎñ£¬Ò²ÊÇ×îºÃµÄ·şÎñ¡£
Öìºì´óÃÅÉÏÅÆ£¨£ó£é£ç£î£©Ò»¿é£¬ÓÖ¸ßĞüÒ»¿éÓù´Í½ğØÒ£º
[1;35m
			´ºÉ«ÎŞ±ß
[2;37;0m
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "ÃùÓñ·»·»¹æ£º
£±£®²»¿É¼Ğ´øÈÎºÎ±øÆ÷ÈëÂ¥¡£
£²£®ÒÔ·ÀÄú±»ÃùÓñ·»Ğ¡½ãÎóÈÏÎªÃ»ÓĞÏû·ÑÄÜÁ¦£¬
¡¡¡¡²»¿É¼Ğ´øÈÎºÎÊ³Îï£¬¾ÆË®ÈëÂ¥¡£
£³£®´ó¼Ò³öÃÅÔÚÍâÊÇÅóÓÑ£¬Ïà»¥¸øµãÃæ×Ó£¬
¡¡¡¡´ò¼Ü£¬ÄÖÊÂÕßÂ¥¹æ´¦ÖÃ¡£
£´£®£¢ÉÍÍ·£¢¸øµÃÔ½¶à£¬ÄúÊÜµÄËÅºîÔ½ºÃ¡£
",
]));
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"xidajie2",
  "south" : __DIR__"pingfeng",
]));

	set("objects", ([ /* sizeof() == 2 */
         __DIR__"npc/guinu" : 2,
]));

	setup();
}

int valid_leave(object me, string dir)
{
        object ob;
	object *inv;
	int i;
        if( dir == "south" &&  ob = present("guinu",this_object()))
        {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
                        if(inv[i]->query("weapon_prop") && (inv[i]->query("equipped")))
			return notify_fail(ob->name()+"ÏòÄãĞ¦µÀ£ºÃùÓñ·»ÓĞÃùÓñ·»µÄ¹æ¾Ø£¬ÄúÇë¿´ÅÆ£®\n");
			if((int)inv[i]->query("food_remaining") != 0)
			return notify_fail(ob->name()+"ÏòÄãĞ¦µÀ£ºÃùÓñ·»ÓĞÃùÓñ·»µÄ¹æ¾Ø£¬ÄúÇë¿´ÅÆ£®\n");
			if((int)inv[i]->query("liquid/remaining") !=0)
			return notify_fail(ob->name()+"ÏòÄãĞ¦µÀ£ºÃùÓñ·»ÓĞÃùÓñ·»µÄ¹æ¾Ø£¬ÄúÇë¿´ÅÆ£®\n");
			if((int)inv[i]->is_container()) 
//			if(check_container(inv[i]))
			return notify_fail(ob->name()+"ÏòÄãĞ¦µÀ£ºÃùÓñ·»ÓĞÃùÓñ·»µÄ¹æ¾Ø£¬ÄúÇë¿´ÅÆ£®\n");
		}
        me->set("food",0);
        me->set("water",0);
        }
	return 1;
}

int check_container(object ob)
{
object *inv;
int i;
inv = all_inventory(ob);
 for(i=0; i<sizeof(inv); i++)
 {
                        if(inv[i]->query("weapon_prop"))
                        return 1;
                        if(inv[i]->query("food_remaining") != 0)
                        return 1;
                        if(inv[i]->query("liquid/remaining") !=0)
                        return 1;
                        if(inv[i]->is_container()) 
                        if(check_container(inv[i]))
                        return 1;
 }
return 0;
}
