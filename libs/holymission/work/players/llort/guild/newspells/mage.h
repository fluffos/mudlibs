/* ################################################################
   #								  #
   #    	Mage guild soul defines                           #
   #                                          		          #
   ###############################################(C) Llort######## */

int i001;         
object inv001;
mixed loop001;

#define TO	this_object()
#define TP	this_player()
#define TPN	TP->query_name()
#define TPR	TP->query_real_name()
#define TPS	TP->query_short_name()
#define TPL	TP->query_level()
#define TPST	TP->query_str()
#define TPDX	TP->query_dex()
#define TPIN    TP->query_int()
#define TPWI    TP->query_wis()
#define TPCO    TP->query_con()
#define TPCH    TP->query_chr()
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
if ((TP->query_attack()) && present(TP->query_attack(),E(TP))) {\
ME("You are much too busy to do that.\n");\
return 1;\
}

#define CHK_SP(x);\
if (TP->query_spell_points()<x) {\
ME("You cannot summon enough energy!\n");\
return 1;\
}

#define CHK_GHOST();\
if(TP->query_ghost()) {\
ME("You can't form the words to cast the spell in your actual state.\n");\
return 1;\
}

#define CHK_SKILL();\
if(!skill[0]) {\
notify_fail("Argle Bargle Blof!\n");\
return;\
}

#define CHK_FAIL(c,sp);\
if(random(100) >= skill[0]) {\
  write("You lost your concentration!\n");\
  ADDSP(-c/2);\
  if(skill[0]<(55+TPIN) && (random(100)<((100-skill[0])/(skill[0]/25+4))) &&\
     skill[0]<95)\
  { TP->change_spell(sp,skill[0]+1,100,1);\
    write("You learn from your mistake!\n");\
  };\
  return 1;\
};

#define GET_ENEMY(a,msg);\
enemy = 0;\
if(!a) enemy=TP->query_attack();\
else enemy=present(a,E(TP));\
if(!enemy) { write(msg); return 1; };

#define GET_TARGET(a,msg);\
target = 0;\
if(!a) target=TP;\
else target=present(a,E(TP));\
if(!target) { write(msg); return 1; };

#define CHK_LIGHT()	if(TP->test_dark()) return 1;

#define CHK_FIZ(x)	if(MS->chk_fiz(x,pl)) return 1;

#define PRISON		"/players/llort/guild/prison/prison"

#define HDIR		"/players/llort/guild/newspells/help_text/"
#define HDIRA		"/spells/aggr/"
#define HDIRN		"/spells/non_aggr/"
#define HDIRO		"/spells/no_combat/"
#define ODIR		"/players/llort/guild/obj/"
#define SDIR		"/obj/shadows/"

#define ROLL(A,B,C) evaluate(loop001,A,B,C)

int HITPL(object x,int dam,int kind,int *typ)
{
   int res;

   res=x->hit_player(dam,kind,typ);
   if(TPR=="llort") {
       write("  __..++'' "+dam+"("+kind+") --> "+ res+" ''++..__\n");
   }
   return res;
}

reset(a)
{
   if(a) return;
   loop001=lambda( ({'a, 'b, 'c }), ({ #'while, 'a, 'c, 
                ({#',, ({ #'=, 'a, ({ #'-, 'a, 1 }) }),
                ({#'=, 'c, ({ #'+, 'c, ({ #'+, ({ (: random :), 'b }), 1 }) }) })
                }) }) );
}

abort_spell(pl)
{
   pl->abort_spell();
   pl->uncheck_input();
   write("You aborted your spell\n");
//   pl->restore_spell_points(-cost()/4);
}
