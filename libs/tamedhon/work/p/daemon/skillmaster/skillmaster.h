// Tamedhon MUDlib
//
// skillmaster.h
//
// Serii@Tamedhon

#ifndef __SKILLMASTER_H__
#define __SKILLMASTER_H__

//#include "/p/obj/xlogins/xlogin.h"

#define SKILLMASTER "/p/daemon/skillmaster/skillmaster"

// elements of P_EXTRA_SKILLS
#define ES_MAX_ABILITY	"extra_skills_max_ability"
#define ES_ABILITY	"extra_skills_ability"
#define ES_USED_LAST	"extra_skills_used_last"
#define ES_LEARNED_LAST	"extra_skills_learned_last"
#define ES_NR_USED_SUCC "extra_skills_used_success"
#define ES_NR_USED	"extra_skills_used"



#undef ODB
#define ODB(x)\
   if(find_player("serii"))\
   tell_object(find_player("serii"), sprintf("\e[31m[\e[0m%s\e[31m]\e[0m %O\n",\
     explode(object_name(this_object()),"/")\
       [sizeof(explode(object_name(this_object()),"/"))-1],x))
#undef DB
#define DB(d)if(!sizeof(filter(users(7),lambda(({'u,'x}),\
        ({#'?,({#'==,({#'call_other,'u,"QueryProp",P_XPO_NAME}),"serii"}),\
        ({#'call_other,'u,"DebugOut",'x}),0})),d)))ODB(d)

#endif
