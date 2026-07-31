#include <ansi.h>
inherit NPC;
mapping *data=({
(["name":"´ïÂê",	"id":"xizang man",	"mw":1,	]),
(["name":"½ðÖé",	"id":"xizang man",	"mw":1,	]),
(["name":"µÂ¼ªÃ·¶ä",	"id":"xizang man",	"mw":1,	]),
(["name":"Ð³±¾ÆëÃÀ",	"id":"xizang man",	"mw":1,	]),
(["name":"´ïÍÞ",	"id":"xizang man",	"mw":1,	]),
(["name":"Ã·¶ä",	"id":"xizang man",	"mw":1,	]),				
(["name":"°×Âê´ïÍÞ",	"id":"xizang man",	"mw":1,	]),				
(["name":"×¿Âê",	"id":"xizang man",	"mw":1,	]),				
(["name":"À­Ä·",	"id":"xizang man",	"mw":1,	]),					
(["name":"¹±¸ÂÄþ²¼",	"id":"xizang man",	"mw":-1,	]),					
(["name":"Ë÷ÀÊ×ÎÄ¦",	"id":"xizang man",	"mw":-1,	]),					
(["name":"Ôú°Í¼áÔö",	"id":"xizang man",	"mw":-1,	]),					
(["name":"È¥µ¤¹±²¼",	"id":"xizang man",	"mw":-1,	]),					
(["name":"µ¤Ôö°à¾õ",	"id":"xizang man",	"mw":-1,	]),					
(["name":"´ÎÈÊÍú½Ü",	"id":"xizang man",	"mw":-1,	]),										
(["name":"´ÎÈÊÍú¶Ñ",	"id":"xizang man",	"mw":-1,	]),					
(["name":"¸ñÉ£Íú¶Ñ",	"id":"xizang man",	"mw":-1,	]),					
(["name":"µ¤°Í",	"id":"xizang man",	"mw":-1,	]),					
(["name":"´ï½Ü",	"id":"xizang man",	"mw":-1,	]),					
(["name":"½­Ñë",	"id":"xizang man",	"mw":-1,	]),					
(["name":"¶à¼ª",	"id":"xizang man",	"mw":-1,	]),										
(["name":"¸ñÁÐ",	"id":"xizang man",	"mw":-1,	]),					
(["name":"ÈºÅå",	"id":"xizang man",	"mw":-1,	]),					
(["name":"µ¤Ôö",	"id":"xizang man",	"mw":-1,	]),					
(["name":"ÀÊ¸Â",	"id":"xizang man",	"mw":-1,	]),					
(["name":"´ÎËÉ",	"id":"xizang man",	"mw":-1,	]),					
(["name":"´Î¼ª",	"id":"xizang man",	"mw":-1,	]),										
(["name":"Ã×Âê",	"id":"xizang man",	"mw":-1,	]),										
(["name":"ÆÕ²¼",	"id":"xizang man",	"mw":-1,	]),										
(["name":"À­°Í",	"id":"xizang man",	"mw":-1,	]),										
(["name":"´ëÄ·",	"id":"xizang man",	"mw":-1,	]),													
(["name":"ÂêÇí",	"id":"xizang man",	"mw":-1,	]),										
(["name":"ÄÇÉ­",	"id":"xizang man",	"mw":-1,	]),											
(["name":"°×°Í",	"id":"xizang man",	"mw":-1,	]),											
(["name":"¸ñÉ£Ë÷È´",	"id":"xizang man",	"mw":-1,	]),											
(["name":"ÔúÎ÷°ÍÔÓ",	"id":"xizang man",	"mw":-1,	]),													
(["name":"µ¤°Í¹úÇÕ",	"id":"xizang man",	"mw":-1,	]),											
(["name":"¶à¼ªÏ½¹ý",	"id":"xizang man",	"mw":-1,	]),											
(["name":"°ÍÉ£¼×Âí",	"id":"xizang man",	"mw":-1,	]),													
(["name":"ÍúÇÕµø²¼",	"id":"xizang man",	"mw":-1,	]),											
(["name":"´Îµ¤¶Ñ¹Å",	"id":"xizang man",	"mw":-1,	]),											
(["name":"ÂêÇÕ´Îµ©",	"id":"xizang man",	"mw":-1,	]),													
(["name":"ÐËË÷Ç¿°Í",	"id":"xizang man",	"mw":-1,	]),											
(["name":"°²Ä·¼ª¸ñÉ£",	"id":"xizang man",	"mw":-1,	]),													
(["name":"¹±²¼",	"id":"xizang man",	"mw":-1,	]),											
(["name":"ÅÁ×¿",	"id":"xizang man",	"mw":-1,	]),											
(["name":"¶ÙÖé",	"id":"xizang man",	"mw":-1,	]),													
(["name":"Öé½Ü½úÃÀ",	"id":"xizang man",	"mw":-1,	]),											
});


void create()
{
	mapping npc;
	string weapon;
	npc=data[random(sizeof(data))];
	weapon=npc["weapon"];

	set_name(npc["name"],({ npc["id"] }));
	set("age",20+random(30));
	set("combat_exp",300000);
	if( weapon)	set_skill("blade",20);
	set_skill("unarmed",20);

        set("dex",200);

	set_skill("blade",120);
	set_skill("sword",120);
	set_skill("club",120);
	set_skill("whip",120);
	set_skill("throwing",120);
	set_skill("parry",120);

set("per",16+random(20));
	set_skill("dodge",300);
	set("shen_type",npc["mw"]);
set("gender", "ÄÐÐÔ");
if (npc["mw"]==1) set("gender", "Å®ÐÔ");
else set("gender", "ÄÐÐÔ");
        set("chat_chance", 15);
        set("chat_msg", ({
                (: random_move :),
        }) );
	set("max_neili",500+random(8550));
	set("max_jing",500+random(8550));
		set("max_qi",500+random(8550));
	set_skill("unarmed",230);
	set_skill("parry",230);
	set_skill("dodge",230);
	set("age",20+random(30));
	set("combat_exp",55000+random(8555000));
	set_temp("apply/attack",120);
	set_temp("apply/defense",20);
	set_temp("apply/armor",120);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
           (: random_move :),
           (: random_move :),
           (: random_move :),
        }) );

        set_temp("apply/attack", 30+random(380));
        set_temp("apply/defense",30+random(380));
        set_temp("apply/armor", 30+random(380));
        set_temp("apply/damage", 30+random(380));
        setup();
        set("check_time", time());
	carry_object(__DIR__"obj/gangdao")->wield();
	carry_object(__DIR__"obj/cloth")->wear();
	add_money("silver",1+random(10));
}
       
