// huoji. Ò©ÆÌ»ï¼Æ
#include <ansi.h>
#include <medical.h>
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("±±Ò©ÆÌ»ï¼Æ", ({ "yaopu huoji", "huoji" }));
	set("str", 20);
	set("gender", "ÄÐÐÔ");
	set("age", 18);
	set("long", "ËûÊÇÆ½ÉñÒ½´ÓÏçÏÂÕÐÀ´°ïÃ¦µÄ¡£\n");
	set("combat_exp", 250);
	set("attitude", "friendly");
	set("vendor_goods", ({
		  HERB("xiefen"),	 // Ð«·Û
		HERB("xijiao"),	 // Ï¬½Ç
		HERB("xiongdan"),       // ÐÜµ¨
		HERB("xionghuang"),     // ÐÛ»Æ
		HERB("xuejie"),	 // Ñª½ß
		HERB("xuelian"),	// Ñ©Á«
		HERB("yanwo"),	  // ÑàÎÑ
		HERB("yjhua"),	  // Ñó½ð»¨
		HERB("yuanzhi"),	// Ô¶Ö¾
		HERB("zihua"),	  // ×Ï»¨
		HERB("zzfen"),	  // ÕäÖé·Û
		HERB("shedan"),	  // Éßµ¨
	}));
set("icon","00973");
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
