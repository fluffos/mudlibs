// migong lev8 ÔÆÁú±Ş ºïÈ­

#include <ansi.h>

inherit NPC;


string* names = ({
"ÕÔ","Ç®","Ëï","Àî","ÖÜ","Îâ","Ö£","Íõ","·ë","³Â","ñÒ","ÎÀ",
"½¯","Éò","º«","Ñî","Öì","ÇØ","ÓÈ","Ğí","ºÎ","ÂÀ","Ê©","ÕÅ",
"¿×","²Ü","ÑÏ","»ª","½ğ","Îº","ÌÕ","½ª","Æİ","Ğ»","×Ş","Ó÷",
"°Ø","Ë®","ñ¼","ÕÂ","ÔÆ","ËÕ","ÅË","¸ğ","ŞÉ","·¶","Åí","ÀÉ",
"Â³","Î¤","²ı","Âí","Ãç","·ï","»¨","·½","Éµ","ÈÎ","Ô¬","Áø",
"µË","±«","Ê·","ÌÆ","·Ñ","Á®","á¯","Ñ¦","À×","ºØ","Äß","ÌÀ",
"ÌÙ","Òó","ÂŞ","»ª","ºÂ","Úù","°²","³£","ÀÖ","´ô","Ê±","¸¶",
"Æ¤","±å","Æë","¿µ","Îé","Óà","Ôª","²·","¹Ë","Ó¯","Æ½","»Æ",
"ºÍ","ÄÂ","Ğ¤","Òü","Ò¦","ÉÛ","Õ¿","Íô","Æî","Ã«","Óí","µÒ",
"Ã×","±´","Ã÷","²Ø","¼Æ","·ü","³É","´÷","Ì¸","ËÎ","Ã©","ÅÓ",
"ĞÜ","¼Í","Êæ","Çü","Ïî","×£","¶­","Áº","·®","ºú","Áè","»ô",
"Óİ","Íò","Ö§","¿Â","êÃ","¹Ü","Â¬","Ó¢","³ğ","ºò","ÔÀ","Ë§",
"Ë¾Âí","ÉÏ¹Ù","Å·Ñô","ÏÄºò","Öî¸ğ","ÎÅÈË","¶«·½","ºÕÁ¬","»Ê¸¦",
"Î¾³Ù","¹«Ñò","å£Ì¨","¹«ÖÎ","×ÚÕş","å§Ñô","´¾ÓÚ","µ¥ÓÚ","Ì«Êå",
"ÉêÍÀ","¹«Ëï","ÖÙËï","Ô¯Ğù","Áîºü","ÖÓÀë","ÓîÎÄ","³¤Ëï","Ä»Èİ",
"Ë¾Í½","Ê¦¿Õ","ò§¿×","¶ËÄ¾","Î×Âí","¹«Î÷","Æáµñ","ÀÖÕı","ÈÀæá",
"¹«Á¼","ÍØÖº","¼Ğ¹È","Ô×¸¸","¹ÈÁº","³ş½ú","ÑÖ·¨","ÈêÛ³","Í¿ÇÕ",
"¶ÎÇ§","°ÙÀï","¶«¹ù","ÄÏ¹ù","ºôÑÓ","¹éº£","ÑòÉà","Î¢Éú","ÁºÇğ",
"×óÇğ","¶«ÃÅ","Î÷ÃÅ","°ÛÉÍ","ÄÏ¹Ù",

"çÃ","¿º","¿ö","ºó","ÓĞ","ÇÙ","ÉÌ","Ä²","ÙÜ","¶ú","Ä«","¹ş",
"ÚÛ","Äê","°®","Ñô","Ù¡","µÚ","Îå","ÑÔ","¸£","Øá","ÖÓ","×Ú",
"ÁÖ","Ê¯",
});

string* nm2 = ({
"ÖÒ","Ğ¢","Àñ","Òå","ÖÇ","ÓÂ","ÈÊ","¿ï","ÏÜ","Áî","¸£","Â»","´ó","Ğ¡","Ïş",
"¸ß","¿É","°¢","½ğ","ÊÀ","¿Ë","Êå","Ö®","¹«","·ò","Ê±","Èô","Çì","ÎÄ","Îä",
"¶à","²Å","³¤","×Ó","ÓÀ","ÓÑ","×Ô","ÈË","Îª","Ìú","","","","","","","","",
"","","","","","","","","","","","","","",
});

string* nm3 = ({
"°Ô","°×","°à","±ó","±ö","²ı","³¬","³Ï","´¨","¶¦","¶¨","¶·",
"·¨","·É","·ç","·æ","¸Ö","î¸","¹á","¹â","º£","»¢","»ª",
"ºÆ","ºê","¼Ã","¼á","½¡","½£","½­","½ø","½Ü","¿¡","¿µ",
"Á¼","÷ë","Ãñ","Ã÷","Ãù","Äş","Åà","Æô","Ç¿","ÈÙ","É½",
"Ì©","ÌÎ","Í¦","Î°","Îõ","Ïé","ĞÛ","Ğñ",
"Òã","è¤","Óğ","Óî","ÔÀ","ÖÛ",
});


void create()
{
  
       int i = random(sizeof(names));
   set_name(names[i]+nm2[random(sizeof(nm2))]+nm3[random(sizeof(nm3))], 
 ({ "man" }));
 
set("title", YEL"ÎäÁÖ°ÜÀà"NOR);
   set("gender", "ÄĞĞÔ" );
 set("long",
"Îä¹¦¸ßÇ¿£¬ĞÄºİÊÖÀ±µÄÎäÁÖ°ÜÀà¡£\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
	  set("force_factor",100+random(200));
  set("max_qi",2000+random(2000));
  set("max_jing",2000+random(2000));
  set("max_sen",2000+random(2000));
  set("max_neili",2000+random(2000));
  set("max_mana",2000+random(2000));
  set("eff_neili",2000+random(2000));
  set("neili",2000+random(2000));
        set("per", 1);
        set("age", 33);

       set("jiali" , 100);
        set("shen", -10000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 2500000+random(800000));
                 set_skill("unarmed", 300+random(50));

set_skill("yunlong-shengong", 300+random(50));

set_skill("yunlong-xinfa", 300+random(50));

set_skill("force", 300+random(50));
set_skill("whip", 300+random(50));

set_skill("parry", 300+random(50));

set_skill("dodge", 300+random(50));

set_skill("houquan", 300+random(50));

set_skill("yunlong-bian", 300+random(50));

set_skill("yunlong-shenfa", 300+random(50));

  
        map_skill("whip", "yunlong-bian");
  
      map_skill("parry", "yunlong-bian");

 map_skill("force", "yunlong-shengong");

 map_skill("dodge", "yunlong-shenfa");
 
map_skill("unarmed"  , "houquan");
prepare_skill("unarmed", "houquan");
set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
             
  (:     perform_action, "whip.chan" :),
	
    (:     perform_action, "unarmed.zhen" :),
	
  (:     perform_action, "unarmed.pofuchenzhou" :),
	
     (:  command("wield bian")       :),
 (:  command("unwield bian")       :),
         (: exert_function, "powerup" :),
    (: exert_function, "recover" :),
    }) );
            set_temp("apply/attack", 150);
        set_temp("apply/defense", 150);
 
          set_temp("apply/armor", 150);
        set_temp("apply/damage", 150);


        setup();

        carry_object("/d/migong/obj/cloth")->wear();
    
   carry_object("/d/migong/obj/bian")->wield();
		add_money("gold", random(2));


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
        
        message_vision(WHT"$N¿ÚÖĞÏÊÑª¿ñÅç,µ¹µØ¶øÍö¡£\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
        if((int)me->query("combat_exp") < 3000000)   {
        message("vision", me->name() + "Îª½­ºş³ıº¦,Ôö¼ÓÁË250¾­ÑéºÍ75Ç±ÄÜ¡£\n", me);
        me->add("combat_exp",250);
        me->add("potential",75);
        destruct(ob);
        }
             me->add("score",1);
        me->add("shen",10);
        destruct(ob);
        return;
}
