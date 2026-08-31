

mixed query_hit_msg(int dam,string name,object att,object def) 
{
    string how1,how2;
    string tpp;

    tpp = this_player()->query_possessive();

    switch(random(6)) 
    {
      case 0:
	      how1=" with "+tpp+" right shoulder";
	      how2=" with your right shoulder";
	   break;
      case 1:
      	how1=" with "+tpp+" left shoulder";
	      how2=" with your left shoulder";
    	break;
      case 2:
	      how1=" with "+tpp+" right knee";
	      how2=" with your right knee";
	   break;
      case 3:
	     how1=" with "+tpp+" left knee";
	     how2=" with your left knee";
	   break;
      case 4:
        how1=" with "+tpp+" right elbow";
	     how2=" with your right elbow";
	   break;
      case 5:
	     how1=" with "+tpp+" left elbow";
	     how2=" with your left elbow";
	   break;
      default:
	    how1="error";
	    how2="error";
	   break;
	  return 1;
  }


   switch(dam)
   {
     case 0:
       return 
       ({
	     "miss "+name+how2+".",
	     "misses you"+how1+".",
	     "misses "+name+how1+"." 
       });
     case 1..3:
       return 
       ({
	    "tickle "+name+" in the stomach"+how2+".",
	    "tickes you in the stomach"+how1+".",
	    "tickles "+name+" in the stomach"+how1+"." 
       });
     case 4..5: 
       return 
       ({
	     "graze "+name+how2+".",
	     "grazes you"+how1+".",
	     "grazes "+name+how1+"." 
       });
     case 6..7: 
       return 
       ({
	     "hit "+name+how2+".",
	     "hits you"+how1+".",
	     "hits "+name+how1+"." 
       });
     case 8..9: 
       return 
       ({
	     "hit "+name+" hard"+how2+".",
	     "hits you hard"+how1+".",
	     "hits "+name+" hard"+how1+"." 
       });
     case 10: 
       return 
       ({
	     "hit "+name+" pretty hard"+how2+".",
	     "hits you pretty hard"+how1+".",
	     "hits "+name+" pretty hard"+how1+"." 
       });
     case 11: 
       return 
       ({
	     "hit "+name+" very hard"+how2+".",
	     "hits you very hard"+how1+".",
	     "hits "+name+" very hard"+how1+"." 
       });
      case 12: 
        return 
        ({
	     "hit "+name+" extremely hard"+how2+".",
	     "hits you extremely hard"+how1+".",
	     "hits "+name+" extremely hard"+how1+"." 
        });
     case 13..14: 
       return 
       ({
	     "smash "+name+how2+".",
	     "smashes you"+how1+".",
	     "smashes "+name+how1+"." 
       });
     case 15..16: 
       return 
       ({
	     "smash "+name+" with a bonecrushing sound"+how2+".",
	     "smashes you with a bonecrushing sound"+how1+".",
	     "smashes "+name+" with a bonecrushing sound"+how1+"." 
       });
     case 17..22: 
       return 
       ({
	     "massacre "+name+how2+".",
	     "massacres you"+how1+".",
	     "massacres "+name+how1+"." 
       });
     case 23..30: 
       return 
       ({
	     "massacre "+name+" to small fragments"+how2+".",
	     "massacres you to small fragments"+how1+".",
	     "massacres "+name+" to small fragments"+how1+"." 
       });
     case 31..35: 
       return 
       ({
	     "hit "+name+how2+" ,so hard that it just hurts to see it !",
	     "hits you"+how1+" ,so hard that it just hurts to see it !",
	     "hits "+name+how1+" so hard that it just hurts to see it !" 
       });
     default:  
       return 
       ({
	     "give a devastating blow to "+name+how2+".",
	     "gives you a devastating blow"+how1+".",
	     "gives "+name+" a devastating blow"+how1+"." 
      });
	}
}






