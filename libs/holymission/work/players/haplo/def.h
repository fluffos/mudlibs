#define TO this_object()
#define TP this_player()
#define ENV environment
#define CAP capitalize
#define AA add_action
#define CO call_out
#define DD dest_dir
#define RCO remove_call_out
#define TLRM tell_room
#define RAN random
#define HERE present
#define ME write

#define QATT query_attack()
#define QLVL query_level()
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

#define CLONE clone_object
#define TELL tell_object
#define MOVE move_object
#define FIND find_object
#define DEST destruct

#define INVF first_inventory
#define INVN next_inventory
#define INVALL all_inventory

#define XP add_exp
#define WGT add_weight
#define GP add_money
#define PS add_poison
#define MP move_player

#define RSP restore_spell_points
#define RHP restore_hit_points
#define HEAL heal_self
#define REDHP reduce_hit_points
#define HIT hit_player
#define CHNGSKL change_skill

#define ATTBY attacked_by
#define STPWD stop_wielding
#define CALM stop_fight()
#define STOP stop_hunter(1)
#define RUN run_away()

#define XX "/players/exos"
#define XMON "/players/exos/monsters"
#define XWEP "/players/haplo/guild/weapons"
#define XARM "/players/haplo/guild/armours"
#define XGLD "/players/haplo/guild"
#define XRIF "/players/exos/rifts"
#define XQST "/players/exos/quest"
#define XOBJ "/players/haplo/guild/obj"
#define XMNT "/players/exos/mountain"
#define XSPL "/players/haplo/guild/spells"
#define XDOC "/players/haplo/guild/docs"
#define XHRM "/players/exos/harem"
#define XFRY "/players/exos/faerie"

#define TPN TP->QNAME
#define TPRN TP->QRNAM
#define TPRO TP->QPRO
#define TPLVL TP->QLVL
#define TPSEX TP->QSEX
#define TPOSS TP->QPOSS
#define TPOBJ TP->QOBJ
#define TPWIZ TP->QWIZ
#define TPL TP->QLVL
#define TPS TP->QSTR
#define TPC TP->QCON
#define TPI TP->QINT
#define TPW TP->QWIS
#define TPD TP->QDEX
#define TPCHR TP->QCHR
#define TPSP TP->QSP
#define TPSMX TP->QMSP
#define TPHP TP->QHP
#define TPMHP TP->QMHP
#define TPRSP TP->RSP
#define TPATT TP->QATT
#define TPMV TP->MP
#define TPINV TP->QINV
#define TPSKL TP->get_skill

OTHERS(string str, object ob1) {
   object old, new;

   old=INVF(ENV(ob1));
   if (!old) return;   
   while (old) {
      new=INVN(old);
      if (living(old) && old!=ob1 && old!=TP) TELL(old,str);
      old=new;
   }
   return;
}
