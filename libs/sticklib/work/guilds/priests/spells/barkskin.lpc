#include "priest_spell.h"
#include <attack.h>

#define MAX_AC 3 // not too strong

void begin_barkskin(object who, mixed data);
status do_barkskin(object who, status already_shielded);

void
create_spell() {
    spell_type = SP_DEFENSIVE;
    dif = -20;
    lvl = 3;
    cost = 20;
    skills_used = ({SK_SERENITY, SK_FORCES, SK_NATURE});
    skill_p = ({30,30,40});
    funs = ({ #'begin_barkskin, #'do_barkskin });
}

object check_target(object who, string str)
{
    object ob;

    if(str == "") return who;

    if(!who->query_can_see()) {
	who->tell_me("You can't see anything!");
	return 0;
    }
    ob = present(lower_case(str),HERE);
    if(!ob) {
	who->tell_me(sprintf("You can't see any %s here.",str));
	return 0;
    }

    if (!ob->query(LIV_IS_PLAYER)) {
	who->tell_me("You hear the voice of " GOD_NAME
	  " in your ears: Only players...");
	return 0;
    }

    if(EXCOM_D->excomed(ob->query_real_name())) {
	who->tell_me("That player is excommunicated and thus does \
not deserve to be protected.");
	return 0;
    }

    return ob;
}

void
begin_barkskin(object who, mixed target) {
    object ob;

    target = check_target(who, target);
    if(!target) return;

    if(ob = target->is_wearing("free magic")) {
	who->tell_me(":%<cap(him.gen_possessive)>% skin is already thicker!",
	  0,0,0,target,0);
	target = 0;
	return;
    }

    if(target != who) {
	who->tell_me(":You touch %<him.name>% and start praying..."
	  ,0,0,0,target,0);

	target->tell_me(({
	    ":%<me.capname>% touches you and mumbles a prayer.",
	    ":%<me.capname>% touches you.",
	  }), ({
	    LIV_CAN_HEAR | LIV_CAN_FEEL, LIV_CAN_FEEL 
	  }), 0, who, target, 0);

	ENV(who)->tell_here(({
	    ":%<me.capname>% touches %<him.name>% and mumbles a silent but \
fervent prayer.",
	    "You hear someone mumbling a prayer.",
	    ":%<me.capname>% touches %<him.name>% and seems to mumble something.",
	  }), ({
	    LIV_CAN_SEE | LIV_CAN_HEAR, LIV_CAN_HEAR, LIV_CAN_SEE
	  }),0,({who, target}),who,target,0); 
    }
    else {
	who->tell_me("You start praying...");
	ENV(who)->tell_here(({
	    ":%<me.capname>% mumbles a silent but fervent prayer.",
	    "You hear someone mumbling a prayer.",
	    ":%<me.capname>% seems to mumble something.",
	  }), ({
	    LIV_CAN_SEE | LIV_CAN_HEAR, LIV_CAN_HEAR, LIV_CAN_SEE
	  }),0,who,who,0,0);
    }
}


status
do_barkskin(object who, object target) {

    int dur, ac, skill;
    object sym, ob;

    sym = who->query_guild_object();
    skill = get_skill(sym);

    ac = 1 + skill * MAX_AC / 1001;
    dur = 30 + skill/5; //was 10 + skill/10
    dur -= random(dur/2);
    ob = clone_object(PRIEST_OBJ_DIR "barkskin_obj");
    if(!ob) {
	who->tell_me("*ERROR* Can't clone barkskin object.");
	return 0;
    }
    move_object(ob, target);
    ob->make_barkskin(target, dur, ac);

    who->add_sp(-cost);
    inc_skills(who,sym,100);
    return 1;
}

