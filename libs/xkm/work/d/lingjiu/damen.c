//ROOM damen.c

#include <ansi.h> 
inherit ROOM;

void create()
{
	set("short", "¶À×ğÌü´óÃÅ");
        set("long",@LONG
Õâ¾ÍÊÇÍ¨Ïò¡ºÁéğÕ¹¬¡»¶À×ğÌüµÄ´óÃÅ¡£´óÃÅ×óÓÒ¸÷ÓĞÒ»Í·Ê¯µñµÄÃÍğÕ
£¬¸ß´ïÈıÕÉÓĞÓà£¬¼âà¹¾Ş×¦£¬Éñ¿¥·Ç·²£¬èòèòÈçÉú£¬ËÆºõËæÊ±ÒªÌÚ¿Õ¶øÈ¥¡£
LONG
	);
        set("outdoors", "lingjiu");
        set("exits", ([
		"north" : __DIR__"dating",
		"south" : __DIR__"dadao2",
        ]));

  set("objects",([ /* sizeof() == 1 */ 
//º                "/clone/obj/car" : 2,
		CLASS_D("lingjiu") + "/meijian" : 1,
		CLASS_D("lingjiu") + "/lanjian" : 1,
	]));
	set("cost", 1);
	setup();
}

int valid_leave(object me, string dir)
{
        object ob;  // program add
	if ( me->query("job_status")==1) 	
	return notify_fail
                ("ÄãÏÖÔÚÉí¸ºÊØÎÀÒªÈÎ£¬²»ÄÜÉÃÀëÖ°ÊØ£¡\n");

	if (  (dir == "north")
           && ((string)me->query("family/family_name") != "ÁéğÕ¹¬")
	   && ( objectp(present("meijian", environment(me)))
	   ||   objectp(present("lanjian", environment(me))) ) )

	 return notify_fail
		("Ã·À¼Ë«æ­ÉìÊÖÀ¹×¡Äã£¬ËµµÀ£º¡°·ÇÁéğÕ¹¬µÜ×ÓÇë»Ø£¡¡±\n");
	return ::valid_leave(me, dir);
}
void init()
{
        add_action("do_kill","kill");
        add_action("do_exercise", "exercise");
        add_action("do_exercise", "dazuo");
        add_action("do_exercise", "respirate");
        add_action("do_exercise", "tuna");
        add_action("do_exercise", "lian");
        add_action("do_exercise", "practice");
        add_action("do_exercise", "study");
        add_action("do_exercise", "du");
        add_action("do_exercise", "sleep");
}

int do_kill(string arg)
{
        object ob, ob1, ob2, me = this_player();

        if ( !arg || arg == "") return 0;

        if ( !ob=present(arg, environment(me)) ) return 0;
        if ( ob->query("family/family_name") == "ÁéğÕ¹¬" && me->query("family/family_name") != "ÁéğÕ¹¬" ) {
           message_vision("$n¶ÔÖø$NºÈµÀ£º¡¸"+RANK_D->query_rude(ob)+"£¡½ñÈÕ²»ÊÇÄãËÀ¾ÍÊÇÎÒ»î¡£\n", ob, me);

           if ( ob1=present("mei jian", environment(me)) ) {
                message_vision("$NÒ»ÉùÀäĞ¦£º´óµ¨¿ñÍ½£¡¾¹¸ÒÔÚÁéğÕ¹¬ĞĞĞ×É±ÈË£¬µ±ÎÒÁéğÕ¹¬ºÃÆÛ¸ºÃ´£¿\n", ob1);
                ob1->kill_ob(me);
           }
           if ( ob2=present("lan jian", environment(me)) ) {
                message_vision("$NÒ»ÉùÀäĞ¦£º´óµ¨¿ñÍ½£¡¾¹¸ÒÔÚÁéğÕ¹¬ĞĞĞ×É±ÈË£¬µ±ÎÒÁéğÕ¹¬ºÃÆÛ¸ºÃ´£¿\n", ob1);
                ob2->kill_ob(me);
           }
           if ( !ob1 ) return 0;
           if ( !ob2 ) return 0;
           return 1;
	} 
}

int do_exercise(string arg)
{
        object me = this_player();

	if ( me->query("job_status")==1)
        {
                tell_object(me, "Äã»¹ÊÇ×¨ĞÄÊØÃÅ°É£¡\n");
                return 1;
        }
        
        return 0;
}
