#include "/players/maledicta/ansi.h"
#define USER player
#define GOB gob
#define USERN USER->query_name()
#define USERRN USER->query_real_name()
#define POW main(str, TO, USER)
#define POS query_possessive()   /*  his her  */
#define PRO query_pronoun()    /*  he she  */
#define OBJ query_objective()    /*  him her  */
#define UPOS USER->POS
#define UPRO USER->PRO
#define UOBJ USER->OBJ
#define STR USER->query_attrib("str")
#define UP USER->POS
#define UPR USER->PRO
#define UO USER->OBJ
#define ATT USER->query_attack()
#define ATTN ATT->query_name()
#define GLVL GOB->query_glvl()
#define DELAY GOB->query_spell_delay()
#define WEP USER->query_weapon()
#define WEPN WEP->query_name()
#define WEPSH WEP->short()

process_short(ob){
string one,two;
if(sscanf(ob->short(), "%s (wielded)", one) == 1){
   return one;
   }
else if(sscanf(ob->short(), "%s (wielded) %s", one, two) == 2){
   return two;
   }
else return ob->query_name();
}
