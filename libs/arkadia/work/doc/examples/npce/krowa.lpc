/*
 * Przyklad napisany przez Zbojcerza Elvarona z Krainy Zgromadzenia.
 */

inherit "/std/creature";
inherit "/std/combat/unarmed";

inherit "/std/act/action";

#include <wa_types.h>
#include <ss_types.h>
#include <macros.h>
#include <filter_funs.h>
#include <stdproperties.h>

/*
 * Definiujemy to dla wlasnej wygody
 */
#define A_ROGI  0
#define A_LKOPYT 1
#define A_PKOPYT 2

#define H_GLOWA 0
#define H_TULOW 1

string *losowy_przym()
 {
 string *lp;
 string *lm;
 int i;
 lp=({ "laciaty"  ,"czarny"  ,"chudy"  ,"tlusty"  ,"cielny" ,
       "koscisty" ,"kulejacy"});
 lm=({ "laciaci"  ,"czarni"  ,"chudzi" ,"tlusci"  ,"cielni"  ,
       "koscisci" ,"kulejacy"});
 i=random(7);

 return ({ lp[i] , lm[i] });

 }



create_creature()
{
    string *przm = losowy_przym();
    
    ustaw_odmiane_rasy( ({"krowa","krowy","krowie","krowe","krowa","krowie"}),
       ({"krowy","krow","krowom","krowy","krowami","krowach"}), PL_ZENSKI); 
       
    add_prop(LIVE_I_NEVERKNOWN, 1);
    
    set_gender(G_FEMALE);

    dodaj_przym( przm[0], przm[1] );
    
    set_long("Zwykla krowa mleczna.\n");

    set_stats(({ 30, 5, 30, 5, 5, 20}));

    set_act_time(60);
    add_act("emote zuje.");
    add_act("emote ryczy muuuuu....");
    set_hp(query_max_hp());

    set_skill(SS_DEFENCE, 5);

    set_attack_unarmed(A_ROGI,   2,   5, W_IMPALE, 40, "rogami");
    set_attack_unarmed(A_LKOPYT, 15, 15, W_BLUDGEON,  30, "lewym kopytem");
    set_attack_unarmed(A_PKOPYT, 15, 15, W_BLUDGEON,  30, "prawym kopytem");
   
    set_hitloc_unarmed(H_GLOWA, ({ 10, 20, 15 }), 20, "glowe");
    set_hitloc_unarmed(H_TULOW, ({ 5,  10, 20 }), 80, "bok");
}
