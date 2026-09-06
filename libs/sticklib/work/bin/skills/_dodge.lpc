#include <cmd.h>
#include <skills_defs.h>
#include <conditions.h>
#include <auto_skills.h>

#define NO_DODGE_VAL	-1

nomask int
dodge_cmd(string str) {

    int i;

    if (!CHECK) return 0;

    if(to_int(this_player()->query_skill(SK_DODGE)) == 
      SKILL_NO_EXIST)
	return 0;
    switch(str) {
    case "on":
    case "On":
	if( i = this_player()->query_condition(C_NO_DODGE) ) {
	    if( i == NO_DODGE_VAL ) {
		this_player()->set_condition(C_NO_DODGE);
		this_player()->tell_me(
		  "You are now dodging attacks."
		);
		return 1;
	    }
	    else {
		this_player()->tell_me(
		  "You are currently unable to dodge attacks."
		);
		return 1;
	    }
	}
	else {
	    this_player()->tell_me(
	      "You are already dodging attacks."
	    );
	    return 1;
	}
	break;
    case "off":
    case "Off":
	if( i = this_player()->query_condition(C_NO_DODGE) ) {
	    this_player()->tell_me(
	      "You are not currently dodging attacks."
	    );
	    return 1;
	}
	else {
	    this_player()->set_condition(C_NO_DODGE,
	      NO_DODGE_VAL);
	    this_player()->tell_me(
	      "You are no longer dodging attacks."
	    );
	    return 1;
	}
    default:
	notify_fail("Dodge [on/off]\n");
	return 0;
	break;
    }
}
