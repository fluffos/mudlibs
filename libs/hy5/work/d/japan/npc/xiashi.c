//xiashi
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("ÏÀÊ¿", ({ "xiashi","man","xia"}));
	set("gender", "ÄÐÐÔ");
	set("age", 40);
	set("long", "Ò»¸ö³öÀ´´³µ´½­ºþµÄÏÀÊ¿£¬¿´ÉÏÈ¥ÒÑÊÇ±¥¾­·çËªµÄÀÏ½­ºþÁË\n");

 	set("str" ,40);
	set("combat_exp", 3000);
	set("mingwang",1);
	set("attitude", "peaceful");
	

        set("chat_chance", 10);
        set("chat_msg", ({
	HIR"[BÏÀÊ¿½£Ã¼Ò»Ñï£¬ËµµÀ£º½­ºþÉÏÐÐµÄ¾ÍÊÇÒ»¸öÒå×Ö¡£\n"NOR,
	HIY"ÏÀÊ¿¸§½£³¤Ì¾µÀ£ºËùÎ½ÈËÔÚ½­ºþ£¬Éí²»ÓÉ¼º°¡£¡\n"NOR,
	HIG"ÏÀÊ¿×ÔÑÔ×ÔÓï£º½­ºþÏÕ¶ñ£¬Ò»ÇÐ¶¼Òª×Ô¼º´¦´¦Ð¡ÐÄ \n"NOR,
	}));
	set_skill("literate" ,30);
	set_skill("parry" ,20);
	set_skill("unarmed", 20);
	set_skill("dodge", 30);
	set_temp("apply/attack", 15);
	set_temp("apply/defense",30);
	setup();
    carry_object("/clone/misc/cloth")->wear();
carry_object("/clone/weapon/gangjian")->wield();
        add_money("silver",20); 
}
