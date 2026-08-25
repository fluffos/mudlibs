// to keep this file just for historical reason
// so dont add anything new in this file 
//*****************************************************************
// fire.h  by fire in Dec 1997
//*****************************************************************
#define FROOMPATH "/sgdomain/area/guan/huayin/"
#define FNPCPATH "/wiz/fire/npc/"
#define FOBJPATH "/wiz/fire/obj/"
#define TSETROOMPATH "/wiz/tset/"
#define STORE "/sgdomain/modules/m_store.lpc"
#define M_VALUE "/sgdomain/modules/m_value.lpc"
#define CHINESE_DA "/sgdomain/modules/chinese_da.lpc"
#define M_MONEY "/sgdomain/modules/m_money.lpc"
#define M_SGGIFT "/sgdomain/modules/m_sggift.lpc"
#define M_BANK "/sgdomain/modules/m_bank.lpc"
#define M_DANGPU "/sgdomain/modules/m_dangpu.lpc"
#define M_OUT "/sgdomain/modules/m_out.lpc"
#define M_ASK "/sgdomain/modules/m_ask.lpc"
#define M_ANSWER "/sgdomain/modules/m_answer.lpc"
#define M_AGE "/sgdomain/modules/m_age.lpc"
#define M_HORSE "/sgdomain/modules/m_horse.lpc"
#define M_TROOP "/sgdomain/modules/m_troop.lpc"
#define M_JOB "/sgdomain/modules/m_job.lpc"
#define TROOP "/sgdomain/modules/troop.lpc"
#define M_BOARD "/sgdomain/modules/m_board.lpc"
#define M_WEAPON "/sgdomain/modules/m_weapon.lpc"
#define M_CHAR "/sgdomain/modules/m_char.lpc"
#define WAR_GRID "/sgdomain/modules/war_grid.lpc"
#define SALERATE 0.9
#define BUYRATE 0.1
#define ARRANGE_MONEY "/sgdomain/modules/arrange_money.lpc"
#define M_GOLD "/sgdomain/obj/money/m_gold.lpc"
#define M_SILVER "/sgdomain/obj/money/m_silver.lpc"
#define M_COIN "/sgdomain/obj/money/m_coin.lpc"
#define M_STUDYABLE "/sgdomain/modules/m_studyable.lpc"
#define M_MERGEABLE "/sgdomain/modules/m_mergeable.lpc"
#define BANKINTEREST 0.9
#define SET_GIFT "/wiz/fire/cmds/set_gift.lpc"
#define s_notfinish "对不起，正在施工，不能通行。"
//************************************************************
#define HELP_GIFT "/wiz/fire/help/help_gift.txt"
// *************MESSAGE **************************************
#define CHENGHU_D "/daemons/chenghu_d.lpc"
//************* SKILLS****************************************
#define NORMAL_D "/daemons/normal_d.lpc"
#define SG_SKILL_D "/daemons/sg_skill_d.lpc"
#define LEARNCHECK_D "/daemons/sg_skilllearn_d.lpc"
#define CLASS_SG_SKILL "/std/classes/sg_skill_class"
#define M_SKILLS "/sgdomain/modules/m_skills"
#define SK_NOR 1    
#define SK_FIGHT 2 
#define SK_ZHENG  3 
#define SK_JI 4 
#define SK_WEAPON 5
#define TOO_DIFFICULT 10
#define LESS_GIFT 11
#define LESS_LITERATE 12
#define LESS_GIFT_ZHIMOU 7
#define LESS_GIFT_MEILI 6
#define LESS_GIFT_WULI 5
#define TOO_TIRED 4
#define TOO_EASY 3
#define LESS_EXP 2
#define CAN_LEARN 1
#define STH_WRONG 0
// path system
#define SGDOMAIN "/sgdomain/"
#define SGAREA "/sgdomain/area/"
// conflict with existing simul_efun
#define bmin(a,b)  (((a) > (b)) ? (b) : (a) )
#define bmax(a,b)  (((a) < (b)) ? (b) : (a) )
// SGSYS used for monitor import affair
#define SGSYS(a) "/daemons/chanlog_d"->sgsys(a)
#define HIS(a) "/daemons/history_d"->add_hisdata(a)
#define WIZ(a) "/daemons/history_d"->add_wizdata(a)
#define AREA(x) ("/a/"+x)
#define SETHERE( x , y ) "/a/area_server"->sethere( x , y )
#define GETHERE( x ) "/a/area_server"->gethere( x )
#define CHAR_SERVER "/sgdomain/modules/char_server/"
#define SGHOME( x ) load_object("/sgdomain/home/home_server/"+x+"/control")
//// for position check
#define CPA_ACCEPT 1
#define CPA_POORABILITY -1
#define CPA_POORLOYALTY -2
#define CPA_POORREPUTION -3
#define CPA_POORFINANCE -4
#define CPA_NOSETTLEYET -5
#define CPA_NOTSAMEAREA -6
#define CPA_NOVACANCY -7
#define CPA_NOTSAMECOUNTRY -8
#define CPA_OTHERLEADER -9
#define CPA_REALLEADER -10
#define CPA_FIRST_ACCEPT 2
#define CONDITION_D(x)	("/sgdomain/sg_conditions/" + x)//emperor add.
