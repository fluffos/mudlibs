// migong lev5 ŒÂª¢∂œ√≈µ∂ ∫Ô»≠

#include <ansi.h>

inherit NPC;


string* names = ({
"’‘","«Æ","ÀÔ","¿Ó","÷‹","Œ‚","÷£","Õı","∑Î","≥¬","Ò“","Œ¿",
"ΩØ","…Ú","∫´","—Ó","÷Ï","«ÿ","”»","–Ì","∫Œ","¬¿"," ©","’≈",
"ø◊","≤‹","—œ","ª™","Ω","Œ∫","Ã’","Ω™","∆›","–ª","◊ﬁ","”˜",
"∞ÿ","ÀÆ","Òº","’¬","‘∆","À’","≈À","∏","ﬁ…","∑∂","≈Ì","¿…",
"¬≥","Œ§","≤˝","¬Ì","√Á","∑Ô","ª®","∑Ω","…µ","»Œ","‘¨","¡¯",
"µÀ","±´"," ∑","Ã∆","∑—","¡Æ","·Ø","—¶","¿◊","∫ÿ","ƒﬂ","Ã¿",
"ÃŸ","“Û","¬ﬁ","ª™","∫¬","⁄˘","∞≤","≥£","¿÷","¥Ù"," ±","∏∂",
"∆§","±Â","∆Î","øµ","ŒÈ","”‡","‘™","≤∑","πÀ","”Ø","∆Ω","ª∆",
"∫Õ","ƒ¬","–§","“¸","“¶","…€","’ø","ÕÙ","∆Ó","√´","”Ì","µ“",
"√◊","±¥","√˜","≤ÿ","º∆","∑¸","≥…","¥˜","Ã∏","ÀŒ","√©","≈”",
"–‹","ºÕ"," Ê","«¸","œÓ","◊£","∂≠","¡∫","∑Æ","∫˙","¡Ë","ªÙ",
"”›","ÕÚ","÷ß","ø¬","Í√","π‹","¬¨","”¢","≥","∫Ú","‘¿","Àß",
"Àæ¬Ì","…œπŸ","≈∑—Ù","œƒ∫Ú","÷Ó∏","Œ≈»À","∂´∑Ω","∫’¡¨","ª ∏¶",
"Œæ≥Ÿ","π´—Ú","Â£Ã®","π´÷Œ","◊⁄’˛","Âß—Ù","¥æ”⁄","µ•”⁄","Ã´ Â",
"…ÍÕ¿","π´ÀÔ","÷ŸÀÔ","‘Ø–˘","¡Ó∫¸","÷”¿Î","”ÓŒƒ","≥§ÀÔ","ƒª»›",
"ÀæÕΩ"," ¶ø’","Úßø◊","∂Àƒæ","Œ◊¬Ì","π´Œ˜","∆·µÒ","¿÷’˝","»¿Ê·",
"π´¡º","Õÿ÷∫","º–π»","‘◊∏∏","π»¡∫","≥˛Ω˙","—÷∑®","»Í€≥","Õø«’",
"∂Œ«ß","∞Ÿ¿Ô","∂´π˘","ƒœπ˘","∫Ù—”","πÈ∫£","—Ú…‡","Œ¢…˙","¡∫«",
"◊Û«","∂´√≈","Œ˜√≈","∞€…Õ","ƒœπŸ",

"Á√","ø∫","øˆ","∫Û","”–","«Ÿ","…Ã","ƒ≤","Ÿ‹","∂˙","ƒ´","π˛",
"⁄€","ƒÍ","∞Æ","—Ù","Ÿ°","µ⁄","ŒÂ","—‘","∏£","ÿ·","÷”","◊⁄",
"¡÷"," Ø",
});

string* nm2 = ({
"÷“","–¢","¿Ò","“Â","÷«","”¬","» ","øÔ","œ‹","¡Ó","∏£","¬ª","¥Û","–°","œ˛",
"∏ﬂ","ø…","∞¢","Ω"," ¿","øÀ"," Â","÷Æ","π´","∑Ú"," ±","»Ù","«Ï","Œƒ","Œ‰",
"∂‡","≤≈","≥§","◊”","”¿","”—","◊‘","»À","Œ™","Ã˙","","","","","","","","",
"","","","","","","","","","","","","","",
});

string* nm3 = ({
"∞‘","∞◊","∞‡","±Û","±ˆ","≤˝","≥¨","≥œ","¥®","∂¶","∂®","∂∑",
"∑®","∑…","∑Á","∑Ê","∏÷","Ó∏","π·","π‚","∫£","ª¢","ª™",
"∫∆","∫Í","º√","º·","Ω°","Ω£","Ω≠","Ω¯","Ω‹","ø°","øµ",
"¡º","˜Î","√Ò","√˜","√˘","ƒ˛","≈‡","∆Ù","«ø","»Ÿ","…Ω",
"Ã©","ÃŒ","Õ¶","Œ∞","Œı","œÈ","–€","–Ò",
"“„","Ë§","”","”Ó","‘¿","÷€",
});


void create()
{
  
       int i = random(sizeof(names));
   set_name(names[i]+nm2[random(sizeof(nm2))]+nm3[random(sizeof(nm3))], 
 ({ "man" }));
 
set("title", HIC"Õˆ√¸ÕΩ"NOR);
   set("gender", "ƒ––‘" );
 set("long",
"≈–¿Î ¶√≈£¨Õˆ√¸Ω≠∫˛µƒ∑ÀÕΩ°£\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
	  set("force_factor",30+random(200));
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
                 set_skill("unarmed", 190+random(30));

set_skill("yunlong-shengong", 190+random(30));

set_skill("force", 190+random(30));
set_skill("blade", 190+random(30));

set_skill("parry", 190+random(30));

set_skill("dodge", 190+random(30));

set_skill("wuhu-duanmendao", 190+random(30));

set_skill("yunlong-shenfa", 190+random(30));

set_skill("houquan", 190+random(30));

  
        map_skill("blade", "wuhu-duanmendao");
  
      map_skill("parry", "wuhu-duanmendao");

 map_skill("force", "yunlong-shengong");

 map_skill("dodge", "yunlong-shenfa");
 
map_skill("unarmed"  , "houquan");
prepare_skill("unarmed", "houquan");
set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
               
   (: perform_action, "unarmed.pofuchenzhou" :),
	
(: perform_action, "unarmed.zhen" :),

(: perform_action, "blade.duan" :),

      (: exert_function, "recover" :),
       }) );
     set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/armor", 100);
        set_temp("apply/damage", 100);


        setup();

        carry_object("/d/migong/obj/cloth")->wear();
    
   carry_object("/d/migong/obj/blade")->wield();
		

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
        
        message_vision(WHT"$Nø⁄÷–œ —™øÒ≈Á,µπµÿ∂¯Õˆ°£\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
        if((int)me->query("combat_exp") < 1000000)   {
        message("vision", me->name() + "Œ™Ω≠∫˛≥˝∫¶,‘ˆº”¡À100æ≠—È∫Õ50«±ƒ‹°£\n", me);
        me->add("combat_exp",100);
        me->add("potential",50);
        destruct(ob);
        }
             me->add("score",1);
        me->add("shen",10);
        destruct(ob);
        return;
}
