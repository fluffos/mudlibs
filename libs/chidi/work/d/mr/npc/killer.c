
#include <ansi.h>
inherit BHNPC;
string* nm1 = ({
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
"×óÇð","¶«ÃÅ","Î÷ÃÅ","°ÛÉÍ","ÄÏ¹Ù","çÃ","¿º","¿ö","ºó","ÓÐ",
"ÇÙ","ÉÌ","Ä²","ÙÜ","¶ú","Ä«","¹þ","ÚÛ","Äê","°®","Ñô","Ù¡",
"µÚ","Îå","ÑÔ","¸£","Øá","ÖÓ","×Ú","ÁÖ","Ê¯",
});

string* nm2 = ({
"ÖÒ","Ð¢","Àñ","Òå","ÖÇ","ÓÂ","ÈÊ","¿ï","ÏÜ","Áî","¸£","Â»",
"´ó","Ð¡","Ïþ","¸ß","¿É","°¢","½ð","ÊÀ","¿Ë","Êå","Ö®","¹«",
"·ò","Ê±","Èô","Çì","ÎÄ","Îä","¶à","²Å","³¤","×Ó","ÓÀ","ÓÑ",
"×Ô","ÈË","Îª","Ìú","","","","","","","","","","","","","",
"","","","","","","","","",
});

string* nm3 = ({
"°Ô","°×","°à","±ó","±ö","²ý","³¬","³Ï","´¨","¶¦","¶¨","¶·",
"·¨","·É","·ç","·æ","¸Ö","î¸","¹á","¹â","º£","»¢","»ª","ºÆ",
"ºê","¼Ã","¼á","½¡","½£","½­","½ø","½Ü","¿¡","¿µ","Á¼","÷ë",
"Ãñ","Ã÷","Ãù","Äþ","Åà","Æô","Ç¿","ÈÙ","É½","Ì©","ÌÎ","Í¦",
"Î°","Îõ","Ïé","ÐÛ","Ðñ","Òã","è¤","Óð","Óî","ÔÀ","ÖÛ",
});
int do_copy(object me,int flag);
int do_back(object me);

void create()
{       string name,weapon;
        int i;
        i = random(sizeof(nm1));
        name =nm1[i]+nm2[random(sizeof(nm2))]+nm3[random(sizeof(nm3))];                set_name(name,({"robber"}));
        set("title",HIY"Ä½ÈÝÅÑÍ½"NOR);   
        set("gender", "ÄÐÐÔ" );
  
        set("age", random(20) + 25);
        set("str", 23);
        set("con", 26);
        set("int", 20);
        set("dex", 23);
        set("long", "Ò»¸ö´©×ÅºÚÉ«Ò¹ÐÐÒÂµÄÈË¡£\n");
        set("combat_exp", 80000 + random(40000)); 
        set("attitude", "friendly");
        set_skill("force", 50);
        set_skill("sword", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("finger", 50);
        set_skill("blade", 50);
        set_skill("canhe-zhi", 50);
       set_skill("yanling-shenfa",50);
       set_skill("shenyuan-gong",50);
        set_skill("murong-jianfa", 50); 
        map_skill("dodge", "yanlin-shenfa");
        map_skill("force","shenyuan-gong");
        map_skill("sword", "murong-jianfa");
        map_skill("parry", "murong-jianfa");
        map_skill("finger", "canhe-zhi");
        prepare_skill("finger", "canhe-zhi");   
   set("chat_chance_combat",random(70));
        set("chat_msg_combat", ({
          (: perform_action, "sword.kuangjian" :)
}));      
        set("max_qi", 2450); 
        set("eff_jingli", 400); 
        set("neili", 1700); 
        set("max_neili", 1700);
        set("jiali", 30);
        weapon ="/clone/weapon/gangjian";
        setup();
        carry_object(weapon)->wield();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/d/mr/obj/xi");
}

int do_copy(object me,int flag)
{
        int i,j;
        object ob;
        ob = this_object();

        i = me->query_skill("dodge",1);
        j = me->query_skill("force",1);
        i = i>j?i:j;
		if(flag==0)
		i = i - random(20);
		else 
                i = i*6/5;
        if( i < 60) i = 60;
        
        ob->set("combat_exp", (me->query("combat_exp")+random(me->query("combat_exp")))*3/4);
        ob->set_skill("force", i);
        ob->set_skill("sword", i);
        ob->set_skill("finger", i);
          ob->set_skill("shenyuan-gong", i);
        ob->set_skill("dodge", i);
          ob->set_skill("yanling-shenfa", i);
        ob->set_skill("parry", i);
        ob->set_skill("murong-jianfa", i);       
        ob->set_skill("canhe-zhi", i); 
       set("chat_msg_combat", ({
          (: perform_action, "sword.kuangjian" :)
}));
        ob->set("max_qi",     ob->query_skill("force",1)*10); 
        ob->set("eff_jingli", me->query("eff_jingli")*2/3); 
        ob->set("jiali", ob->query_skill("force",1)/6);
        ob->reincarnate(); 
        ob->set("qi",ob->query_skill("force",1)*10);
          ob->set("eff_qi",ob->query_skill("force",1)*10);
		call_out("do_back", 350,  ob);  
        return 1;
}
int do_back(object me)
{                       
  tell_room(environment(me), me->query("name")+"´Ò´ÒÃ¦Ã¦µÄÀë¿ªÁË¡£\n", ({me}));	
  destruct(me); 
  return 1;
}
void die()
{
	object corpse;
	mixed killer;
	if( !living(this_object()) ) revive(1);
	else delete_temp("faint_by");
	COMBAT_D->announce(this_object(), "dead");
	if( !(killer = query_temp("last_damage_from")) )
	killer = "ÄªÃûÆäÃîµØ";
	if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
	corpse->move(environment());
	set_temp("last_damage_from", "ÄªÃûÆäÃîµØ");
    corpse->set_temp("must_killby",this_object()->query_temp("must_killby"));
	this_object()->remove_all_killer();
	all_inventory(environment())->remove_killer(this_object());
    destruct(this_object());
}
