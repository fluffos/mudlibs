// migong lev12  »ªÉ½½£·¨ »ìÔª ÆÆÓñ

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
 ({ "mo tou" , "tou" }));
 
set("title", RED"´óÄ§Í·"NOR);
   set("gender", "ÄÐÐÔ" );
 set("long",
"Îä¹¦¸ßÇ¿£¬ÐÄºÝÊÖÀ±µÄÎäÁÖ°ÜÀà¡£\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
	  set("force_factor",100+random(200));
  set("max_qi",3000+random(3000));
  set("max_jing",3000+random(3000));
  set("max_sen",3000+random(3000));
  set("max_neili",3000+random(3000));
  set("max_mana",3000+random(3000));
  set("eff_neili",3000+random(3000));
  set("neili",3000+random(3000));
        set("per", 1);
        set("age", 52);

       set("jiali" , 100);
        set("shen", -10000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 6000000+random(2000000));
                 set_skill("unarmed", 400+random(60));

set_skill("huashan-neigong", 400+random(60));

set_skill("zixia-shengong", 400+random(60));

set_skill("force", 400+random(60));
set_skill("sword", 400+random(60));

set_skill("parry", 400+random(60));

set_skill("dodge", 400+random(60));

set_skill("hunyuan-zhang", 400+random(60));

set_skill("huashan-sword", 400+random(60));

set_skill("cuff", 400+random(60));

set_skill("poyu-quan", 400+random(60));

set_skill("feiyan-huixiang", 400+random(60));

  
        map_skill("sword", "huashan-sword");
  
      map_skill("parry", "huashan-sword");

 map_skill("force", "zixia-shengong");

 map_skill("dodge", "feiyan-huixiang");
 
map_skill("unarmed"  , "hunyuan-zhang");
map_skill("cuff"  , "poyu-quan");
prepare_skill("unarmed", "hunyuan-zhang");
prepare_skill("cuff", "poyu-quan");
set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
               
      (:     perform_action, "sword.jm" :),
	
      (: perform_action, "sword.feilong" :),
	
       (: perform_action, "unarmed.wuji" :),
	
     (: perform_action, "cuff.leidong" :),
	
         (: exert_function, "recover" :),
    (:     perform_action, "sword.jm" :),
	
 }) );
            set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
 
          set_temp("apply/armor", 200);
        set_temp("apply/damage", 200);


        setup();

        carry_object("/d/migong/obj/cloth")->wear();
    
   carry_object("/d/migong/obj/sword")->wield();
	
add_money("gold", random(3));
	

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
        if((int)me->query("combat_exp") < 7000000)   {
        message("vision", me->name() + "Îª½­ºþ³ýº¦,Ôö¼ÓÁË300¾­ÑéºÍ100Ç±ÄÜ¡£\n", me);
        me->add("combat_exp",300);
        me->add("potential",100);
        destruct(ob);
        }
             me->add("score",1);
        me->add("shen",10);
        destruct(ob);
        return;
}
