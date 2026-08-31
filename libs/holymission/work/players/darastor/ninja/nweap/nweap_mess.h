#ifndef __weap_mess__
#define __weap_mess__

query_hit_msg(dam,name,att,def)
{
   if(dam<1) return ({
      "miss "+name+".",
      "misses you.",
      "misses "+name+"." });
   else if (dam<2) return ({
      "tickle "+name+" in the stomach.",
      "tickes you in the stomach.",
      "tickles "+name+" in the stomach." });
   else if (dam<3) return ({
      "strike "+name+" weakly.",
      "strikes you weakly.",
      "strikes "+name+" weakly." });
   else if (dam<4) return ({
      "strike "+name+".",
      "strikes you.",
      "strikes "+name+"." });
   else if (dam<5) return ({
      "hit "+name+".",
      "hits you.",
      "hits "+name+"." });
   else if (dam<6) return ({
      "hit "+name+" hard.",
      "hits you hard.",
      "hits "+name+" hard." });
   else if (dam<8) return ({
      "hit "+name+" pretty hard.",
      "hits you pretty hard.",
      "hits "+name+" pretty hard." });
   else if (dam<10) return ({
      "hit "+name+" very hard.",
      "hits you very hard.",
      "hits "+name+" very hard." });
   else if (dam<12) return ({
      "hit "+name+" extremly hard.",
      "hits you extremly hard.",
      "hits "+name+" extremly hard." });
   else if (dam<14) return ({
      "do an awful damage at "+name+".",
      "does an awful damage at you.",
      "does an awful damage at "+name+"." });
   else if (dam<16) return ({
      "smash "+name+".",
      "smashes you.",
      "smashes "+name+"." });
   else if (dam<18) return ({
      "smash "+name+" with a bonecrushing sound.",
      "smashes you with a bonecrushing sound.",
      "smashes "+name+" with a bonecrushing sound." });
   else if (dam<20) return ({
      "hit "+name+" like a maverick.",
      "hits you like a maverick.",
      "hits "+name+" like a maverick." });
   else if (dam<30) return ({
      "massacre "+name+".",
      "massacres you.",
      "massacres "+name+"." });
   else if (dam<40) return ({
      "massacre "+name+" to small fragments.",
      "massacres you to small fragments.",
      "massacres "+name+" to small fragments." });
   else if (dam<50) return ({
      "hit "+name+" so hard that it just hurts to see it.",
      "hits you so hard that it just hurts to see it.",
      "hits "+name+" so hard that it just hurts to see it." });
   else if (dam<80) return ({
      "pound "+name+".",
      "pounds you.",
      "pounds "+name+"." });
   else if (dam<120) return ({
      "pound "+name+" in a puddle of bloody bodyparts.",
      "pounds you in a puddle of bloody bodyparts.",
      "hits "+name+" so hard that it just hurts to see it." });
   else return ({
      "do INSANE amount of damage to "+name+".",
      "does INSANE amount of damage to you.",
      "does INSANE amount of damage to "+name+"." });
}

#endif /*__weap_mess__*/
