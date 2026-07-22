// migong lev10  ”Ò≈ÆΩ£∑® √¿≈Æ»≠

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
 
set("title", YEL"–∞µ¿∏ﬂ ÷"NOR);
   set("gender", "ƒ––‘" );
 set("long",
"Œﬁ∂Ò≤ª◊ˆµƒΩ≠∫˛∞‹¿‡°£\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
	  set("force_factor",100+random(200));
  set("max_qi",2500+random(2000));
  set("max_jing",2500+random(2000));
  set("max_sen",2500+random(2000));
  set("max_neili",2500+random(2000));
  set("max_mana",2500+random(2000));
  set("eff_neili",2500+random(2000));
  set("neili",2500+random(2000));
        set("per", 1);
        set("age", 32);

       set("jiali" , 100);
        set("shen", -10000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 4000000+random(2000000));
                 set_skill("unarmed", 360+random(60));

set_skill("yunv-jian", 360+random(60));

set_skill("yunv-xinfa", 360+random(60));

set_skill("force", 360+random(60));
set_skill("sword", 360+random(60));

set_skill("parry", 360+random(60));

set_skill("dodge", 360+random(60));

set_skill("yunv-shenfa", 360+random(60));

set_skill("meinv-quan", 360+random(60));

  
        map_skill("sword", "yunv-jian");
  
      map_skill("parry", "yunv-jian");

 map_skill("force", "yunv-xinfa");

 map_skill("dodge", "yunv-shenfa");
 
map_skill("unarmed"  , "meinv-quan");
prepare_skill("unarmed", "meinv-quan");
set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "sword.he" :),
	
      (: perform_action, "sword.suxin" :),
	
       (: perform_action, "sword.hubo" :),
	
      (: perform_action, "unarmed.you" :),
	
     (: exert_function, "recover" :),
    (: exert_function, "powerup" :),
 }) );
            set_temp("apply/attack", 150);
        set_temp("apply/defense", 150);
 
          set_temp("apply/armor", 150);
        set_temp("apply/damage", 150);


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
        
        message_vision(WHT"$Nø⁄÷–œ —™øÒ≈Á,µπµÿ∂¯Õˆ°£\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
        if((int)me->query("combat_exp") < 5000000)   {
        message("vision", me->name() + "Œ™Ω≠∫˛≥˝∫¶,‘ˆº”¡À300æ≠—È∫Õ100«±ƒ‹°£\n", me);
        me->add("combat_exp",300);
        me->add("potential",100);
        destruct(ob);
        }
             me->add("score",1);
        me->add("shen",10);
        destruct(ob);
        return;
}
