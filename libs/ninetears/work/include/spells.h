#ifndef _SPELLS_H_
#define _SPELLS_H_

#define SP_NO_RNDS      0
#define SP_OBJECT       1
#define SP_FUNC         2
#define SP_PARAM        3

#define S_OBJECT        0
#define S_FUNC          1

#define RANGE_HANDLER   "/obj/handlers/range"

#define MIN_RES_OBJETO  -15
#define MAX_RES_OBJETO   30
#define MIN_RES_NATURAL -22
#define MAX_RES_NATURAL  45
#define MIN_RES_SPELL   -30
#define MAX_RES_SPELL    60
#define MIN_RES_TOTAL   -35
#define MAX_RES_TOTAL    70

#define SPELL_ROOT      "/d/gremios/hechizos/"
#define BARD_ROOT       SPELL_ROOT+"bardo/"
#define CLERIC_ROOT     SPELL_ROOT+"clerigos/"
#define DRUID_ROOT      CLERIC_ROOT
#define MAGE_ROOT       SPELL_ROOT+"mago/"
#define RANGER_ROOT     DRUID_ROOT

#define BASES           SPELL_ROOT+"bases/"
#define BASE_SPELL      BASES+"spell"
#define SHADOWS         SPELL_ROOT+"shadows/"
#define OBJETOS         SPELL_ROOT+"objetos/"
#define BARDO           ESCUELAS+"bardo/"
#define WIZWAR          ESCUELAS+"wizwar/"

#define ANTIPALADIN     SPELL_ROOT+"antipaladin/"
#define DRUIDA          SPELL_ROOT+"druida/"
#define PALADIN         SPELL_ROOT+"paladin/"
#define MAGODROW        SPELL_ROOT+"mago-drow/"
#define MG              SPELL_ROOT+"mago-guerrero/"
#define CLERIGODUERGAR  SPELL_ROOT+"clerigo-duergar/"
#define CLERIGODROW     SPELL_ROOT+"clerigo-drow/"
#define CHAMAN          SPELL_ROOT+"chaman/"
#define YVENDUR         SPELL_ROOT+"clerigos/yvendur/"
#define TEMPUS          SPELL_ROOT+"clerigos/tempus/"





#define DEBUG(ob)       ( ob->query_creator() || ob->QP("TEST") )
#define MAX(a,b)        ( a>b?a:b )
#define MIN(a,b)      ( a<b?a:b )
//#define POWER           caster->query_sphere(query_sphere())
// solucion temporal, las esferas sux por ahora
#define POWER           ((caster->query_guild_name() == "paladin")?1:3)

#define ETP             ENV(TP)
#define AP              add_property
#define AOP             add_old_property
#define ATP             add_timed_property
#define ASP             add_static_property
#define RP              remove_property
#define ROP             remove_old_property
#define RTP             remove_timed_property
#define RSP             remove_static_property
#define QP              query_property
#define QOP             query_old_property
#define QTP             query_timed_property
#define QSP             query_static_property
#define QPE             query_property_exists
#define QOPE            query_old_property_exists
#define QTPE            query_timed_property_exists
#define QSPE            query_static_property_exists

#define QL              query_level()
#define QN              query_name()
//#define QCN             query_cap_name() viene en standard.h

#define MSG_NO_TARGET   "El hechizo falla, no parece haber nadie aqui con ese nombre.\n"
#define MSG_AFECTADO    target->QCN+" ya esta afectado por el hechizo "+NOMBRE+".\n"
#define MSG_SUIC_R      caster->QCN+" para de formular un hechizo.\n"
#define MSG_SUIC_C      "No querras suicidarte?\n"
#define MSG_CAN_R       caster->QCN+" pronuncia el cantico "+CANCION+".\n"
#define MSG_CAN_C       "Pronuncias el cantico "+CANCION+".\n"
#define MSG_NO_PUEDO    "No puedes formular este hechizo ahora.\n"

#define INAUDIBLE       "inaudible"
#define STILLCASTING    "stillcasting"
#define EXTRA_D         0
#define EXTRA_ROLL      0
#define EXTRA_RES       0
#define IMMORTLOCK      1

#endif _SPELLS_H_
