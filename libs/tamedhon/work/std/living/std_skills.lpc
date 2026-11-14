// SilberLand MUDlib
//
// std/living/std_skills.c -- einige vordefinierte Skills
//
// $Date: 1997/06/25 11:56:34 $
/* $Revision: 3.1 $
 * $Log: std_skills.c,v $
 * Revision 3.1  1997/06/25 11:56:34  Woody
 * ueberall ein object me als ersten Parameter *ARGL*
 *
 * Revision 3.0  1997/03/13 01:02:58  Woody
 * prepared for revision control
 *
 */

#define NEED_PROTOTYPES

#include <thing/properties.h>
#include <properties.h>
#include <attributes.h>
#include <new_skills.h>

#define SIG(x) (x?(x>0?1:-1):0)

<float|int> StdSkill_Nightvision(object me, string sname, mixed sinfo) {
  <float|int> abil,llt,dt,res,light;

  if (!sinfo || !environment()) return 0;
  if (intp(sinfo)) sinfo=([SI_SKILLABILITY:sinfo]);
  if (!mappingp(sinfo)) return 0;
  if ((light=set_light(0))>0) {
    ModifySkill(sname,([SI_LASTLIGHT:time()]));
    return light;
  }
  abil=sinfo[SI_SKILLABILITY];
  if (!(llt=sinfo[SI_LASTLIGHT])) {
    ModifySkill(sname,([SI_LASTLIGHT:time()]));
    dt=0;
  } else {
    dt=time()-llt;
    if (dt<0) dt=0;
    if (dt>86400) dt=86400;
  }

  res=(abil*dt)/(20*MAX_ABILITY)+light;
  if (res<=0) {
    res--; // Wert muss !=0 sein
    if (res<-MAX_ABILITY) res=-MAX_ABILITY;
  } else {
    if (res>MAX_ABILITY) res=MAX_ABILITY;
  }
  return res;
}

mapping StdSkill_Bihand(object me, string sname, mapping sinfo) {
  int abil,val;

  // printf("Bihand: %O\n",sinfo);
  if (!sinfo) return 0;
  abil=sinfo[SI_SKILLABILITY];
  val=(abil*(QueryAttribute(A_STR)+33))/MAX_ABILITY;
  val=(val*QuerySkillAttribute(SA_DAMAGE))/100;
  sinfo[SI_SKILLDAMAGE]+=val;
  // + max. 53
  return sinfo;
}

mapping StdSkill_Fight_sword(object me, string sname, mapping sinfo) {
  int abil,asig,val;

  abil=sinfo[SI_SKILLABILITY];asig=SIG(abil);
  val=(abil*(QueryAttribute(A_STR) +
             QueryAttribute(A_DEX)*asig +
             33))/MAX_ABILITY;
  val=(val*QuerySkillAttribute(SA_DAMAGE))/100;
  sinfo[SI_SKILLDAMAGE]+=val;
  // + max. 73
  return sinfo;
}

mapping StdSkill_Fight_hands(object me, string sname, mapping sinfo) {
  int abil,asig,val;

  if (!sinfo) return 0;
  abil=sinfo[SI_SKILLABILITY];asig=SIG(abil);
  val=(abil*(QueryAttribute(A_STR) +
             QueryAttribute(A_DEX)*3*asig +
             100))/MAX_ABILITY;
  val=(val*QuerySkillAttribute(SA_DAMAGE))/100;
  sinfo[SI_SKILLDAMAGE]+=val;
  // + max. 180
  return sinfo;
}

int StdSkill_Booze(object me, string sname, mapping sinfo) {
  int abil,val;

  val=0;
  if (!sinfo || (val=sinfo[SI_SKILLARG])<=0)
    return val;
  abil=sinfo[SI_SKILLABILITY];
  val-=(val*abil)/(MAX_ABILITY+2500); // Bis zu 80% Abzug bei Alkoholikern.
  if (val<=0) val=1;
  return val;
}
