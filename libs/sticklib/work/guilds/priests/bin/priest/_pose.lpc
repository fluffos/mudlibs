#include "../../priest.h"
#define NUMBER_OF_POSES 7
#define TH(x) environment(who)->tell_here(x,0,0,0,who,0,0)
status
pose_cmd(object who, object sym, string str) {
    object ob;
    switch(random(NUMBER_OF_POSES)) {
    case 0:
	TH(":%<me.capname>% yell%<me.ending_s>%: Tithe to the Church, \
support thy God!");
	break;
    case 1:
	TH(":%<me.capname>% smile%<me.ending_s>% and say%<me.ending_s>%: \
Dost thou take Boccob as thy personal saviour?");
	break;
    case 2:
	TH(":%<me.capname>% yell%<me.ending_s>%: Repent! Repent! The day \
of the Lord cometh!");
	break;
    case 3:
	TH(":%<me.capname>% point%<me.ending_s>% at everyone and yell\
%<me.ending_s>%: SINNERS!");
	break;
    case 4:
	TH(":%<me.capname>% flip%<me.ending_s>% through the bible, \
looking for a certain passage.");
	break;
    case 5:
	TH(":%<me.capname>% pull%<me.ending_s>% out some prayer beads \
and utter%<me.ending_s>% prayers to Boccob.");
	break;
    case 6:
	TH(":%<me.capname>% gaze%<me.ending_s>% at the heavens and \
say%<me.ending_s>%:\n'Boccob will return to lead us! Praise \
Boccob!'");
	break;
    }
    return 1;
}

