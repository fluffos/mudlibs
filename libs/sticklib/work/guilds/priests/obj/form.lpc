/*
 * Joining form
 * 
 * This object will be given to players willing to join the priest guild.
 * After one of the priest officers (rank >= 2) has signed it, player
 * can do the actual joining.
 */

#include <treasure.h>
#include <macros.h>
#include <guild.h>

status signed;
object applicant;
string applicant_name, signer_name;


string form_long() {
    string str;

    str = sprintf("%s's application form for priest guild membership. ",
      applicant_name);
    if(signed) str += sprintf("It has been signed by %s.", signer_name);
    return str;
}


create_treasure() {
    set_name("application form");
    set_id( ({"form", "_priest_application_form"}) );
    set_long(#'form_long);
    applicant_name = "BUG";
    set_weight(0);
}


init_treasure() {
    add_action("sign", "sign");
}


status query_signed() { return signed; }
object query_applicant() { return applicant; }
string query_signer() { return signer_name; }

void set_applicant(object x) {
    signed = 0;
    applicant = x;
    applicant_name = capitalize(x->query_real_name());
}


status sign(string str) {
    object sym;

    if(!id(str)) return 0;

    if(TP == applicant)
	return notify_fail("Did you really think you could sign your own \
application form??\n"),0;

    notify_fail("Only priest officers can sign this form.\n");
    if(TP->query_guild() != GN_PRIEST) {
	return 0;
    }
    sym = TP->query_guild_object();
    if (!sym)
	return 0;
    if (sym->query_rank() < 7 && !this_player()->query_coder_level())
	return 0;

    signed = 1;
    signer_name = capitalize(TP->query_real_name());
    TP->tell_me(":You sign %<me.gen_possessive>% application form for \
the priest guild membership.",0,0,applicant,0,0);
    return 1;
} 
