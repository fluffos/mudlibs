//by name

#include <ansi.h>
inherit NPC;
string* names = ({
"ÕÔ","Ç®","Ëï","Àî","ÖÜ","Îâ","Ö£","Íõ","·ë","³Â","ñÒ","ÎÀ",
"½¯","Éò","º«","Ñî","Öì","ÇØ","ÓÈ","Ðí","ºÎ","ÂÀ","Ê©","ÕÅ",
"¿×","²Ü","ÑÏ","»ª","½ð","Îº","ÌÕ","½ª","ÆÝ","Ð»","×Þ","Ó÷",
"°Ø","Ë®","ñ¼","ÕÂ","ÔÆ","ËÕ","ÅË","¸ð","ÞÉ","·¶","Åí","ÀÉ",
"Â³","Î¤","²ý","Âí","Ãç","·ï","»¨","·½","Éµ","ÈÎ","Ô¬","Áø",
"µË","±«","Ê·","ÌÆ","·Ñ","Á®","á¯","Ñ¦","À×","ºØ","Äß","ÌÀ",
"ÌÙ","Òó","ÂÞ","»ª","ºÂ","Úù","°²","³£","ÀÖ","´ô","Ê±","¸¶",
"Æ¤","±å","Æë","¿µ","Îé","Óà","Ôª","²·","¹Ë","Ó¯","Æ½","»Æ",
"ºÍ","ÄÂ","Ð¤","Òü","Ò¦","ÉÛ","Õ¿","Íô","Æî","Ã«","Óí","µÒ",
"Ã×","±´","Ã÷","²Ø","¼Æ","·ü","³É","´÷","Ì¸","ËÎ","Ã©","ÅÓ",
"ÐÜ","¼Í","Êæ","Çü","Ïî","×£","¶­","Áº","·®","ºú","Áè","»ô",
"ÓÝ","Íò","Ö§","¿Â","êÃ","¹Ü","Â¬","Ó¢","³ð","ºò","ÔÀ","Ë§",
"Ë¾Âí","ÉÏ¹Ù","Å·Ñô","ÏÄºò","Öî¸ð","ÎÅÈË","¶«·½","ºÕÁ¬","»Ê¸¦",
"Î¾³Ù","¹«Ñò","å£Ì¨","¹«ÖÎ","×ÚÕþ","å§Ñô","´¾ÓÚ","µ¥ÓÚ","Ì«Êå",
"ÉêÍÀ","¹«Ëï","ÖÙËï","Ô¯Ðù","Áîºü","ÖÓÀë","ÓîÎÄ","³¤Ëï","Ä»ÈÝ",
"Ë¾Í½","Ê¦¿Õ","ò§¿×","¶ËÄ¾","Î×Âí","¹«Î÷","Æáµñ","ÀÖÕý","ÈÀæá",
"¹«Á¼","ÍØÖº","¼Ð¹È","Ô×¸¸","¹ÈÁº","³þ½ú","ÑÖ·¨","ÈêÛ³","Í¿ÇÕ",
"¶ÎÇ§","°ÙÀï","¶«¹ù","ÄÏ¹ù","ºôÑÓ","¹éº£","ÑòÉà","Î¢Éú","ÁºÇð",
"×óÇð","¶«ÃÅ","Î÷ÃÅ","°ÛÉÍ","ÄÏ¹Ù",

"çÃ","¿º","¿ö","ºó","ÓÐ","ÇÙ","ÉÌ","Ä²","ÙÜ","¶ú","Ä«","¹þ",
"ÚÛ","Äê","°®","Ñô","Ù¡","µÚ","Îå","ÑÔ","¸£","Øá","ÖÓ","×Ú",
"ÁÖ","Ê¯",
});

string* nm2 = ({
"ÖÒ","Ð¢","Àñ","Òå","ÖÇ","ÓÂ","ÈÊ","¿ï","ÏÜ","Áî","¸£","Â»","´ó","Ð¡","Ïþ",
"¸ß","¿É","°¢","½ð","ÊÀ","¿Ë","Êå","Ö®","¹«","·ò","Ê±","Èô","Çì","ÎÄ","Îä",
"¶à","²Å","³¤","×Ó","ÓÀ","ÓÑ","×Ô","ÈË","Îª","Ìú","","","","","","","","",
"","","","","","","","","","","","","","",
});

string* nm3 = ({
"°Ô","°×","°à","±ó","±ö","²ý","³¬","³Ï","´¨","¶¦","¶¨","¶·",
"·¨","·É","·ç","·æ","¸Ö","î¸","¹á","¹â","º£","»¢","»ª",
"ºÆ","ºê","¼Ã","¼á","½¡","½£","½­","½ø","½Ü","¿¡","¿µ",
"Á¼","÷ë","Ãñ","Ã÷","Ãù","Äþ","Åà","Æô","Ç¿","ÈÙ","É½",
"Ì©","ÌÎ","Í¦","Î°","Îõ","Ïé","ÐÛ","Ðñ",
"Òã","è¤","Óð","Óî","ÔÀ","ÖÛ",
});


void create()
{

   int i = random(sizeof(names));
   set_name(names[i]+nm2[random(sizeof(nm2))]+nm3[random(sizeof(nm3))], ({ "man" }));
   set("title", HIC"ÍöÃüÍ½"NOR);
   set("gender", "ÄÐÐÔ" );
   set("long","ÅÐÀëÊ¦ÃÅ£¬ÍöÃü½­ºþµÄ·ËÍ½¡£\n");
   set("attitude", "aggressive");
  set("force_factor",50+random(200));
  set("max_qi",1500+random(1500));
  set("max_jing",1500+random(1500));
  set("max_sen",1500+random(1500));
  set("max_neili",1500+random(1500));
  set("max_mana",1500+random(1500));
  set("eff_neili",1500+random(1500));
  set("neili",2000+random(1500));
        set("per", 1);
        set("age", 22);
        set("jiali" , 50);
        set("shen", -5000);
        set("intellgent",1);
     	set("pursuer",1);
        set("combat_exp", 1000000+random(250000));
set_skill("unarmed", 250+random(50));
set_skill("hunyuan-zhang", 250+random(50));
set_skill("force", 250+random(50));
set_skill("sword", 250+random(50));
set_skill("parry", 250+random(50));
set_skill("dodge", 250+random(50));
set_skill("huashan-sword", 250+random(50));
set_skill("feiyan-huixiang", 250+random(50));
set_skill("zixia-shengong", 250+random(50));
map_skill("sword", "huashan-sword");
map_skill("parry", "huashan-sword");
map_skill("force", "zixia-shengong");
map_skill("dodge", "feiyan-huixiang");
map_skill("unarmed"  , "hunyuan-zhang");
prepare_skill("unarmed", "hunyuan-zhang");
set("chat_chance_combat", 80);
set("chat_msg_combat", ({
   (: perform_action, "sword.jianzhang" :),
   //(: exert_function, "recover" :),
}));
     set_temp("apply/attack", 100);
     set_temp("apply/defense", 100);
     set_temp("apply/armor", 100);
     set_temp("apply/damage", 100);
     set("chat_chance", 50);
     set("chat_msg", ({
		(: command("get silver") :),
		(: command("get gold") :),
		(: command("get coin") :),
                (: random_move :),
      }));
      setup();
   carry_object("/d/migong/obj/cloth")->wear();
   carry_object("/d/migong/obj/sword")->wield();
}

void init()
{	
	object ob; 

	ob = this_player();
	::init();
	if (interactive(ob) && ! is_fighting()){
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
		kill_ob(ob);
}

void die()
{
        object ob, me;
        ob = this_object();
        me=  this_object()->query_last_damage_from();
        if (!me) 
        return;            
        message_vision(WHT"$N¿ÚÖÐÏÊÑª¿ñÅç,µ¹µØ¶øÍö¡£\n"NOR,ob,me);
        if((int)me->query("combat_exp") > 500000)   {
        message("vision", me->name() + "Îª½­ºþ³ýº¦,Ôö¼ÓÁË500ÐÞÎªºÍ500Ç±ÄÜ¡£\n", me);
        me->add("combat_exp",500);
        me->add("potential",500);
        }

        ::die();
}
