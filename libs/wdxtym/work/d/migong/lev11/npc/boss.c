// migong lev11  huoyan-dao

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
 ({ "sha shou" , "shou" }));

set("title", HIR"É±ÊÖÖ®Íõ"NOR);
   set("gender", "ÄÐÐÔ" );
 set("long",
"ÌìÏÂÉ±ÊÖµÄ×ÜÍ·Ä¿£¬Ò»Ö±ÔÚ°µÖÐ»î¶¯×Å¡£\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
	  set("force_factor",100+random(200));
  set("max_qi",39000+random(2500));
  set("max_jing",39000+random(2500));
  set("max_sen",390000+random(2500));
  set("max_neili",19000+random(2500));
  set("max_mana",9000+random(2500));
  set("eff_neili",19000+random(2500));
  set("neili",19000+random(5000));
        set("per", 1);
        set("age", 50);
set("no_get",1);
       set("jiali" , 50);
        set("shen", -10000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 6000000+random(2000000));
                 set_skill("strike", 360+random(60));

set_skill("longxiang", 360+random(60));

set_skill("xiaowuxiang", 360+random(60));

set_skill("force", 360+random(60));
set_skill("huoyan-dao", 360+random(60));
set_skill("parry", 360+random(60));

set_skill("dodge", 360+random(60));

set_skill("lamaism", 360+random(60));

set_skill("shenkong-xing", 360+random(60));

         map_skill("parry", "huoyan-dao");

 map_skill("force", "xiaowuxiang");

 map_skill("dodge", "shenkong-xing");

map_skill("strike"  , "huoyan-dao");
prepare_skill("strike", "huoyan-dao");
set("chat_chance_combat", 90);
        set("chat_msg_combat", ({

   (: perform_action, "strike.fen" :),

     (: perform_action, "strike.xiuluo" :),

    (: perform_action, "strike.honglian" :),

     (: perform_action, "strike.fen" :),

     //(: exert_function, "recover" :),
       (: perform_action, "dodge.tianmaxingkong" :),

     (: exert_function, "shield" :),
     }) );
            set_temp("apply/attack", 250);
        set_temp("apply/defense", 250);

          set_temp("apply/armor", 250);
        set_temp("apply/damage", 250);


        setup();

        carry_object("/d/migong/obj/cloth")->wear();

add_money("gold", 2);


}

void init( )
{
	object ob;
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
        ob->start_busy(3);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight"))
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
if (me->query("migong/lev11"))
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
if (!me->query("migong/lev11"))
{
me->set("migong/lev11",1);
message("channel:chat", HIM"¡¾½­ºþÒ¥ÑÔ¡¿ÌýËµ"+me->name() + "Íê³ÉÁËÃÔ¹¬µÚÊ®Ò»²ã!"NOR"¡£\n", users());
exp = 400000+random(25000);
pot = exp/2;
score = random(300)+550;
             me->add("combat_exp",exp);
             me->add("potential",pot);
             me->add("score",score);
tell_object(me,HIW"Äã±»½±ÀøÁË£º\n" +
             chinese_number(exp) + "µãÊµÕ½ÐÞÎª\n"+
             chinese_number(pot) + "µãÇ±ÄÜ\n" +
            chinese_number(score)+"µã½­ºþÔÄÀú\n"NOR);

}
        if((int)me->query("combat_exp") < 900000)   {


        message("vision", me->name() + "Îª½­ºþ³ýº¦,Ôö¼ÓÁË10000ÐÞÎªºÍ5000Ç±ÄÜ¡£\n", me);
        me->add("combat_exp",10000);
        me->add("potential",5000);
        destruct(ob);
        }
        destruct(ob);
        return;
}
