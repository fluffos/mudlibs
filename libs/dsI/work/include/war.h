#ifndef s_war_h
#define s_war_h

class team {
    string name;
    string leader;
    int points;
    int war_chest;
    string *members;
}
    
class war {
    int start;
    string reason;
    class team aggressor; /* FluffOS PORT NOTE: was "agressor" (missing
                           * a 'g') -- every real usage in daemon/war.lpc
                           * spells it "aggressor"; fixed here to match. */
    class team enemy;
    string *neutrals;
}
