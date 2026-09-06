// A new "absolve" spell. All it does is switch the 
// victims temp_luck a tad.... Mainly intended
// as a roleplay thing. Perhaps someone will pick up on it.

// Yeah, but this is not a catholic church. Why should priests of 
// Boccob be able to absolve your sins? hmm... - Chopin

// DO NOT TELL ANYONE WHAT THIS DOES!!!!!!!!

#include "../priest.h"

#define ABSOLVE_COST 10

status
absolve_cmd(object who, object sym, string me) {
    int luck;
    object pl;

    if(!(pl=find_player(me)))
	return notify_fail("No suchs player.\n"),0;

    if(environment(pl) != environment(who))   
	return notify_fail("But that player is not here!\n"),0;

    if(pl == who) {
	pl->tell_me(GOD_NAME+" frowns upon your pride.");
	return 1;
    }

    if(who->query_sp() < ABSOLVE_COST)
	return notify_fail("You can concentrate enough to do that.\n"),0; 
    who->add_sp(-ABSOLVE_COST);

    who->tell_me(":%<him.capname>% kneels before you. You solemnly \
place your hands on %<him.possessive>% head and beseech " GOD_NAME " to \
forgive %<him.gen_possessive>% sins. As you recite the ancient rite of \
absolution, a feeling of great peace envelops you.",0,0,who,pl,0);

    pl->tell_me(":You kneel before %<me.name>%, who places %<me.possessive>% \
hands on your head. As %<me.name>% recites the ancient rite of absolution, \
a feeling of cleanliness and peace descends upon you. Surely " GOD_NAME " \
is Great!",0,0,who,pl,0);

    environment(who)->tell_here(":%<him.capname>% kneels in front of \
%<me.name>% as if asking for forgiveness. %<me.capname>% places \
%<me.possessive>% hands on %<him.gen_possessive>% brow, reciting an ancient \
rite of absolution. Just witnessing this holy act makes you feel somehow \
better.",0,0,({pl, who}),who,pl,0);

    luck = pl->query_temp_luck();

    if(luck <= 0) luck += 4;
    if(luck > 0 && luck < 15) luck +=2;

    if(!random(2))
	pl->set_temp_luck(luck);

    return 1;
}

int
clean_up(int arg) {
    destruct(this_object());
    return 0;
}
