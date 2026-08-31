#define TO this_object()
#define TP this_player()
#define ENV environment
#define CAP capitalize
#define AA add_action
#define CO call_out
#define RCO remove_call_out
#define FCO find_call_out
#define TLRM tell_room
#define RAN random
#define HERE present
#define ME write
#define LC lower_case
#define WF write_file
#define CD "sys/chatd"
#define GM "guild/master"
#define WC weapon_class()
#define DD dest_dir

#define QATT query_attack()
#define QLVL query_level()
#define QLLVL query_legend_level()
#define QWIZ query_immortal()
#define QNAME query_name()
#define QRNAM query_real_name()
#define QOBJ query_objective()
#define QPOSS query_possessive()
#define QPRO query_pronoun()
#define QGUILD query_guild()
#define QSEX query_gender()
#define QRACE query_race()
#define QSTR query_str()
#define QDEX query_dex()
#define QCON query_con()
#define QINT query_int()
#define QWIS query_wis()
#define QCHR query_chr()
#define QHP query_hp()
#define QSP query_sp()
#define QMHP query_max_hp()
#define QMSP query_max_sp()
#define QINV query_invis()
#define QGH query_ghost()
#define QGOD query_religion()
#define QSZ query_size()
#define QRACE query_race()
#define QWGT query_weight()
#define QNPC query_npc()
#define QWIELD query_wielded()
#define QWEP query_weapon()
#define QINFO query_info()
#define QWC query_wc()
#define QAC query_ac()
#define Q2HND query_two_handed()
#define QSH query_short()
#define QAGR query_aggressive()
#define QVAL query_value()
#define QGP query_money()
#define QPSN query_poisoned()
#define QXP query_exp
#define QEL query_earmuff_level()
#define QAL query_alignment()

#define CLONE clone_object
#define TELL tell_object
#define MOVE move_object
#define FIND find_object
#define DEST destruct

#define INVF first_inventory
#define INVN next_inventory
#define INVALL all_inventory

#define XP add_exp
#define GP add_money
#define MP move_player

#define RSP restore_spell_points
#define RHP restore_hit_points
#define HEAL heal_self
#define REDHP reduce_hit_points
#define HIT hit_player

#define ATTBY attacked_by
#define STPWD stop_wielding
#define CALM stop_fight()
#define STOP stop_hunter(1)
#define RUN run_away()

#define XX "/players/exos"
#define XARE XX+"/areas"
#define XMNT XARE+"/mountain"
#define XKEN XARE+"/kender"
#define XMON XX+"/monsters"
#define XWEP XX+"/weapons"
#define XARM XX+"/armour"
#define XGLD XX+"/guild"
#define XOBJ XX+"/objects"
#define XDOC XGLD+"/docs"
#define XSNG XGLD+"/songs"
#define BIN XGLD+"/bin/"
#define SPELL XGLD+"/spells/"
#define OBJ XGLD+"/obj/"
#define LOG XGLD+"/log/"
#define HQ XGLD+"/room"
#include "/players/dragonn/ansi.h"

#define TPN TP->QNAME
#define TPRN TP->QRNAM
#define TPRO TP->QPRO
#define TPSEX TP->QSEX
#define TPOSS TP->QPOSS
#define TPOBJ TP->QOBJ
#define TPWIZ TP->QWIZ
#define TPL TP->QLVL
#define TPLL TP->QLLVL
#define TPS TP->QSTR
#define TPC TP->QCON
#define TPI TP->QINT
#define TPW TP->QWIS
#define TPD TP->QDEX
#define TPCHR TP->QCHR
#define TPSP TP->QSP
#define TPMSP TP->QMSP
#define TPHP TP->QHP
#define TPMHP TP->QMHP
#define TPRSP TP->RSP
#define TPATT TP->QATT
#define TPMV TP->MP
#define TPINV TP->QINV

#define OTHERS say
