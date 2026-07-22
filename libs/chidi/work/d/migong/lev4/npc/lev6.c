// migong lev4

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
   set_name(names[i]+nm2[random(sizeof(nm2))]+nm3[random(sizeof(nm3))], 
 ({ "man" }));
 
set("title", HIW"ËÀÇô"NOR);
   set("gender", "ÄÐÐÔ" );
 set("long",
"Ô½ÓüµÄËÀÐÌ·¸¡£\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
	  set("force_factor",30+random(200));
  set("max_qi",2000+random(1500));
  set("max_jing",2000+random(1500));
  set("max_sen",2000+random(1500));
  set("max_neili",2000+random(1500));
  set("max_mana",2000+random(1500));
  set("eff_neili",2000+random(1000));
  set("neili",2000+random(1000));
        set("per", 1);
        set("age", 22);
        set("shen", -5000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 1100000);
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
               	            (: random_move :),
        }) );
            
set_skill("force", 200);
set_skill("unarmed", 220);

set_skill("parry", 200);

set_skill("dodge", 210);

set_skill("changquan", 220);
        
        map_skill("unarmed", "changquan");
        map_skill("parry", "changquan");
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/armor", 100);
        set_temp("apply/damage", 100);


        setup();

                

}

void init( )
{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
        call_out("hunting",1);
        }
	if(!environment()->query("no_fight") && random(10) < 5)
        call_out("hunting",1);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}

void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
        
        message_vision(WHT"$N¿ÚÖÐÏÊÑª¿ñÅç,µ¹µØ¶øÍö¡£\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
        if((int)me->query("combat_exp") < 700000)   {
        message("vision", me->name() + "Îª½­ºþ³ýº¦,Ôö¼ÓÁË50¾­ÑéºÍ25Ç±ÄÜ¡£\n", me);
        me->add("combat_exp",50);
        me->add("potential",25);
        destruct(ob);
        }
             me->add("score",1);
        me->add("shen",10);
        destruct(ob);
        return;
}
