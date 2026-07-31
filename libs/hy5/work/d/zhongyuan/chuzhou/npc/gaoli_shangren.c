// ¸ßÀöÉÌÈËå /d/city/chuzhou/npc/gaoli_shangren.c
// by lala, 1997-12-13

inherit NPC;

inherit F_VENDOR;

#include <ansi.h>

string *name = ({
"½ğÕıÎÄ", "ÆÓº£¾¸", "Â¬Ì«ÔÆ", "Àî¸üÏà", "´Ş³ÊºÆ",
});

void create()
{
    set_name( name[random(sizeof(name))], ({ "gaoli shangren", "shangren", "corean", }) );
    set( "title", RED"¸ßÀö"WHT"ÉÌÈË"NOR );
    set( "gender", "ÄĞĞÔ" );
    set( "age", 33 );
    set( "long", @LONG
Ò»¸ö¸ßÀöÉÌÈË£¬ÓĞ×ÅµäĞÍµÄ¸ßÀöÈËµÄÃæ¿×¡£Ëû³Ë´¬Àú¾¡Ç§ĞÁÍò¿à´©¹ıÈÕ±¾º£²ÅÀ´
µ½ÖĞ¹ú¡£²»¹ıºÃÔÚËû°²È«µÄµ½ÁË£¬ÏÈ²»¹ÜËûÊÇ·ñÄÜ°²È«µÄ»ØÈ¥¡ª¡ªËû×Ô¼ºÏÖÔÚºÃ
ÏóÒ²²¢²»¹ØĞÄÕâ¸ö¡ª¡ªËû¹ØĞÄµÄÊÇÔõÃ´ÄÜ°ÑËûĞÁĞÁ¿à¿à´øÀ´µÄ»õÎïÂò¸öºÃ¼ÛÇ®¡£
LONG
    );
    set( "attitude", "friendly" );


	set("vendor_goods", ({
		__DIR__"obj/gaoli_renshen",
		__DIR__"obj/gaoli_zhi",
		__DIR__"obj/gaoli_mo",
		__DIR__"obj/tigercloth",
		__DIR__"obj/riben_zheshan",
		__DIR__"obj/wodao",
	}));    
    set( "talk_msg",({
    }));
        set("qi",400);
        set("max_qi",400);
        set("eff_kee",400);
        set("sen",400);
        set("max_sen",400);
        set("eff_sen",400);

    set("combat_exp", 100000);
    set("social_exp", 100000);
    set("positive_score", 5000);
    set("negative_score", 1000);
    setup();
          
    carry_object( "/clone/misc/cloth")->wear();
    add_money( "silver", 10 + random(5) );
}          

void init()
{       
    ::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

