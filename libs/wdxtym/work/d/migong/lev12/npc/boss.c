// migong lev12  xuantie-jian

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
 ({ "jian mo" , "mo" }));

set("title", HIG"½£Ä§"NOR);
   set("gender", "ÄÐÐÔ" );
 set("long",
"Òþ¾ÓÔÚ´ËÈýÊ®Äê£¬Ç±ÐÄÑÐ¾¿½£·¨¡£\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
	  set("force_factor",100+random(200));
  set("max_qi",39000+random(3000));
  set("max_jing",39000+random(3000));
  set("max_sen",4000+random(3000));
  set("max_neili",14000+random(3000));
  set("max_mana",4000+random(3000));
  set("eff_neili",14000+random(3000));
  set("neili",14000+random(4000));
        set("per", 1);
        set("age", 72);
set("no_get",1);
      set("int", 20);

       set("jiali" , 100);
        set("shen", -10000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 8000000+random(1000000));
                 set_skill("unarmed", 400+random(100));

set_skill("xuantie-sword", 400+random(100));

set_skill("yunv-shenfa", 400+random(100));

set_skill("force", 400+random(100));
set_skill("anranxiaohun-zhang", 400+random(100));
set_skill("sword", 400+random(100));

set_skill("parry", 400+random(100));

set_skill("hubo", 400+random(100));

set_skill("dodge", 400+random(100));

set_skill("xuantie-jianfa", 400+random(100));

set_skill("yunv-xinfa", 400+random(100));


        map_skill("sword", "xuantie-jianfa");

      map_skill("parry", "xuantie-jianfa");

 map_skill("force", "yunv-xinfa");

 map_skill("dodge", "yunv-shenfa");

map_skill("unarmed"  , "anranxiaohun-zhang");
prepare_skill("unarmed", "anranxiaohun-zhang");
set("chat_chance", 40);
        set("chat_msg", ({
                "½£Ä§ºÈµÀ£º¾¹¸ÒÀ´´ËÉ§ÈÅÎÒ£¬ÕÒËÀ£¡£¡\n",
                               }) );


set("chat_chance_combat", 90);
        set("chat_msg_combat", ({

      (:     perform_action, "sword.xunlei" :),

        (: command("hubo")  :),
         //(: exert_function, "recover" :),
      }) );
            set_temp("apply/attack", 300);
        set_temp("apply/defense", 300);

          set_temp("apply/armor", 300);
        set_temp("apply/damage", 300);


        setup();

        carry_object("/d/migong/obj/cloth")->wear();

   carry_object("/d/migong/obj/sword")->wield();

add_money("gold", random(10));


}

void init( )
{
	object ob;
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight") && random(10) < 5)
        call_out("hunting",0);
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

void unconcious()
{
    die();
}
void die()
{
        object ob, me, corpse,obj;
        int maxpot;
        int exp,pot,score,i;
        ob = this_object();
       // me = query_temp("last_damage_from");
        me=  this_object()->query_last_damage_from();
        if (!me) return;
             me->add("score",1);
        me->add("shen",10);

        message_vision(WHT"$N¿ÚÖÐÏÊÑª¿ñÅç,µ¹µØ¶øÍö¡£\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));me->add("combat_exp",random(12));me->add("potential",random(8));
if (me->query("migong/lev12"))
{
if( !environment(me)->query("no_fight")
&& random(4)==1)
{
obj=new("/d/migong/obj/npct");
maxpot=me->query_temp("maxpot")+10;
obj->do_copy(me,maxpot,2);
obj->set("usename",me->query("name"));
obj->move(environment(me));
message_vision(HIY"$N¿ñÐ¦µÀ£ºÈÃÄã¼ûÊ¶ÊÇÒ»ÏÂÎäÊõµÄÕæËè! !\n"NOR, obj);
me->start_busy(3);
me->kill_ob(obj);
obj->kill_ob(me);
}

}
if (!me->query("migong/lev12"))
{
me->set("migong/lev12",1);
message("channel:chat", HIM"¡¾½­ºþÒ¥ÑÔ¡¿ÌýËµ"+me->name() + "Íê³ÉÁËÃÔ¹¬µÚÊ®¶þ²ã!"NOR"¡£\n", users());
exp = 420000+random(25000);
pot = exp/2;
score = random(300)+650;
             me->add("combat_exp",exp);
             me->add("potential",pot);
             me->add("score",score);
tell_object(me,HIW"Äã±»½±ÀøÁË£º\n" +
             chinese_number(exp) + "µãÊµÕ½ÐÞÎª\n"+
             chinese_number(pot) + "µãÇ±ÄÜ\n" +
            chinese_number(score)+"µã½­ºþÔÄÀú\n"NOR);

}
        if((int)me->query("combat_exp") < 2000000)   {

        message("vision", me->name() + "Îª½­ºþ³ýº¦,Ôö¼ÓÁË10000ÐÞÎªºÍ5000Ç±ÄÜ¡£\n", me);
        me->add("combat_exp",10000);
        me->add("potential",5000);
        destruct(ob);
        }
        destruct(ob);
        return;
}
