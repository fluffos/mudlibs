/* ################################################################
   #								  #
   #    	Mage guild soul defines                           #
   #                                          		          #
   ###############################################(C) Llort######## */

nosave int i001;         
nosave object *inv001;
nosave object robe001;

#define MS	"players/llort/guild/magemaster"
#define SOUL	robe001
#define MED_TITLE " is sitting in the lotus position"
#define TO	this_object()
#define TP	pl
#define TPN	TP->query_name()
#define TPR	TP->query_real_name()
#define TPS	TP->query_short_name()
#define TPL	TP->query_level()
#define TPDX	TP->query_dex()
#define TPIN    TP->query_int()
#define TPWI    TP->query_wis()
#define TPPOS   TP->query_possessive()
#define E	environment
#define ME(x)	tell_object(TP,x)
#define YOU     tell_object
#define SAY(x)  tell_room(E(TP),x)
#define ADDSP(x) TP->restore_spell_points(x)

#define OTHERS(x,t); \
{\
  inv001=all_inventory(E(TP));\
  for(i001=0;i001<sizeof(inv001);i001++) {\
    if(living(inv001[i001]) && member_array(inv001[i001],x)==-1)\
      YOU(inv001[i001],t);\
  }\
}

#define CHK_ATT(); \
if ((att=TP->query_attack()) && present(att,E(TP))) {\
ME("You are much too busy to do that.\n");\
return 1;\
}

#define CHK_SP(x);\
if (TP->query_spell_points()<x) {\
ME("You are to low on mental energy !\n");\
return 1;\
}

#define CHK_GHOST();\
if(TP->query_ghost()) {\
ME("You can't form the words to cast the spell in your actual state.\n");\
return 1;\
}

#define CHK_LIGHT()	if(TP->test_dark()) return 1;

#define CHK_FIZ(x)	if(MS->chk_fiz(x,pl)) return 1;

#define SPCOST(x)	MS->spell_info(x,2) 
#define SPLVL(x)	MS->spell_info(x,3) 

#define PRISON		"/players/llort/guild/prison/prison"

set_robe(r) { robe001=r; }
