#include <lib.h>
#include <std.h>
#include <domains.h>
#include <daemons.h>
#define OCEAN  INNERSEA_VIRTUAL "ocean/"
inherit LIB_FISHING;

int X, Y, counter, SailingDifficulty;

void createShipEncounter(int x, int y);
int *GetXY() { return ({ X, Y }); }
int GetSailingDifficulty() { return SailingDifficulty; }
int SetSailingDifficulty(int x) { return SailingDifficulty = x; }

static void create(int x, int y) {
  string n, s, e, w, ne, nw, se, sw;
  string long = "", short = "", smell = "", listen = "", climate = "";
  ::create();
  counter = 0;
  X = x;
  Y = y;
  SetProperty("ocean", 1);
  n  = OCEAN + (x) + "," + (y + 1);
  s  = OCEAN + (x) + "," + (y - 1); 
  e  = OCEAN + (x + 1) + "," + (y);
  w  = OCEAN + (x - 1) + "," + (y);
  ne = OCEAN + (x + 1) + "," + (y + 1);
  se = OCEAN + (x + 1) + "," + (y - 1);
  nw = OCEAN + (x - 1) + "," + (y + 1);
  sw = OCEAN + (x - 1) + "," + (y - 1);
  SetSpeed(5);
  SetMaxFishing(5);
  SetChance(10);
  SetFish( ([
    DIR_STD "fish/guppy" : 60,
    DIR_STD "fish/blackfin_tuna" :  40,
    DIR_STD "fish/bonnethead" :  30,
    DIR_STD "fish/mackerel" :  45,
    DIR_STD "fish/mako" :  25,
    DIR_STD "fish/marlin" :  20,
    DIR_STD "fish/seabass" :  50,
    DIR_STD "fish/shark" :  40,
    DIR_STD "fish/swordfish" :  20,
    DIR_STD "fish/yellowtail" :  25,
    DIR_STD "fish/trout" :  50,
    ]) );
   SetDomain("Innersea");
   SetSailingDifficulty(10);
    
  /* Basic Long Setup.  Defines Which ocean we're in */
  if (x > -180 && x < 100 && y < 51 && y > -50) {
    short = "the Ruined Sea";
    long = "The reddish waters of the Ruined Sea swirl around in chaotic fury, "
           "their motion that of waves on a mission. ";
    smell = "The air has a faint coppery smell.";
    listen = "The air is quiet with few birds even chirping.";       
    }
  if (y >= 51) {
    short = "the Northern Sea";
    long  = "The frigidly cold waters of the Northern Sea creak their waves "
            "across the area. Small mounds of ice bob up and down in the "
            "cold, chill waters. ";  
    climate = "arctic";
    smell = "The air has a chilled quality from icy flows and winds.";
    listen = "The crash of waves on ice and icebergs breaking up is loud.";
    }
  if (y <= -50) {
    short = "the Southern Sea";
    long  = "The warm, peaceful waters of the Southern Sea gently ripple "
            "into swirls of small currents. Light glistens off the waves "
            "in a reassuring manner. ";
    climate = "sub-tropical";
    smell = "A breeze of fresh air is carried from afar.";
    listen = "The soft ripple of the currents is quiet and friendly.";
   }
  if ( x > -180 && x <= -175 ) {
    short = "Perilously Close to the Endless Sea";
    long = "The hazardous waters of the endless sea churn not many leagues "
      "distant to the west, a graveyard to all but the most experienced of "
      "sailors. Fortunately, the dark waves here crash with only enough "
      "force to sicken, and not violently enough to shatter wooden hulls.";
    smell = "The churning air smells of rotten kelp.";
    listen = "Unquiet waters constantly churn and crash, promising "
      "violence to come.";
    SetSailingDifficulty(15);
  }
  if ( x < 100 && x >= 95 ) {
    short = "Perilously Close to the Endless Sea";
    long = "The hazardous waters of the endless sea churn not many leagues "
      "distant to the east, a graveyard to all but the most experienced of "
      "sailors. Fortunately, the dark waves here crash with only enough "
      "force to sicken, and not violently enough to shatter wooden hulls.";
    smell = "The churning air smells of rotten kelp.";
    listen = "Unquiet waters constantly churn and crash, promising "
      "violence to come.";
    SetSailingDifficulty(15);
  }
  if (x <= -180 || x >= 100) {
    short = "the Endless Sea";
    long  = "The waves of the Endless sea stretch out in all directions as "
            "far as the eye can sea. Clouds don't seem to make any impression "
            "on the water, and the sky seems lonely and forelorn. This far from shore, sailing "
            "in the deep ocean is surely going to be more difficult.";
    smell = "The air is breezy, but surprisingly devoid of smell.";
    listen = "The ocean is quiet and calm.";      
    SetSailingDifficulty(50);  
    }
 
  /* Voodoo mysticism for some exits.  Kids, don't try this at home. */
  
  if (y < 100 && y > 0 && x < 4 && x > -70)  
  		 ne = se = nw = n = sw = s = e = w = 0; 
  if (y < 92 && y > 0 && x < -90 && x > -155)
  		 ne = se = nw = n = sw = s = e = w = 0; 
  if (x >= -90 && x < -87 && y > 6 && y < 100)
  		 ne = se = nw = n = sw = s = e = w = 0; 
  if (x > -87 && x <= -70 && y > 3 && y < 100)
  		 ne = se = nw = n = sw = s = e = w = 0; 
  if (y >= 92 && y < 110 && x < -55 && x > -150)
  		 ne = se = nw = n = sw = s = e = w = 0; 
  if (y < 100 && y > 50 && x >= 4 && x < 55)
  	 	ne = se = nw = n = sw = s = e = w = 0;  
    /* Area is entirely within the island.  
     * If you're here, you're fucked. 
     */
  
  
  /* South Coast */
  
  if (y == 0 && x >= -25 && x <= 3) {
  	if (x != 3) ne = 0;
  	if (x != -12) nw = 0;
  	SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  	long += " The sea ends here along the southern shore of "
  	        "Kailie's northern continent. ";
  	if (x !=  -13) n = 0;
  	if (x <= -12 && x > -14) {
  		long += " A small cove can be seen north of here. ";
  	}
  }        
  
  
  /* Mark off the Penninsula - East Coast */
  if (x == -26 && y == -12) {
  	nw = 0; 
  	long += " The Ruined Sea washes against the Peninsula here, "
  	        "and off to the northwest the city of Sanctum can be seen.";
  	SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  }
  if (x == -26 && y <= 0 && y >= -11) {
  	nw = w = 0;
  	if (y != -11) sw = 0;
  	if (y == 0) n = ne = 0;
    if (y <= -4)
    	long += " The Ruined Sea washes against the Peninsula here, "
  	          "and off to the west the city of Sanctum can be seen.";
  	  else
  	  	long += " The Ruined Sea washes against the Peninsula here. ";
  	SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  }
  
  /* Mark off the Peninsula - South Coast */
  if (x >= -38 && x <= -27 && y == -12) {
  	n = 0;
  	if (x != -38) nw = 0;
  	if (x != -27) ne = 0;
        long += " The Ruined Sea washes against the Peninsula here, "
  	        "and off to the north the city of Sanctum can be seen.";
  	SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  }
  
  /* Mark off the Penninsula - West Coast */
  if (x == -39 && y == -12) {
  	ne = 0; 
  	long += " The Ruined Sea washes against the Peninsula here, "
  	        "and off to the northeast the city of Sanctum can be seen.";
  	SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  }
  if (x == -39 && y < -4 && y >= -11) {
  	e = ne = 0;
  	if (y != -11) se = 0;
    long += " The Ruined Sea washes against the Peninsula here, "
            "and off to the east the city of Sanctum can be seen.";
  	SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  }      
  
  
  
  /* After Peninsula - Rest of Southern Coast to Crystal Reaches */
  if (x < -38 && x >= -50 && y == -4) {
  	n = ne = 0;
  	if (x == -39) e = se = 0;
  	if (x != -50) nw = 0;
  	SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  	long += " The sea ends here along the southern shore of "
  	        "Kailie's northern continent. ";
  }
  
  /* So players cannot sail into or behind land */
  if ((x == -51 && y == -4) || (x == -52 && y == -3) ||
  	  (x == -70 && y == -2) || (x == -71 && y == -1) ||
  	  (x == -86 && y == 2) || (x == -87 && y == 3) ||
  	  (x == -101 && y == -2) || (x == -102 && y == -1)) {
  	ne = 0;
   }
  
  
  if ((x == -51 && y == -3) || (x == -70 && y == -1) ||
  	  (x == -86 && y == 3) || (x == -101 && y == -1)) {
  	ne  = n = e = 0;
  	SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  	long += " The sea ends here along the southern shore of "
  	        "Kailie's northern continent. ";
  }
  
  if (x <= -52 && x >= -69 && y == -2) {
  	ne = n = 0; 	
  	if (x == -52) e = 0;
  	if (x != -69) nw = 0;
  	SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  	long += " The sea ends here along the southern shore of "
  	        "Kailie's northern continent. ";
  }
  if (x == -71 && y >= 0 && y <= 2) {
  	e = ne = 0; 	
  	if (y != 0) se = 0;
  	if (y == 2) n = nw = 0;
  	SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  	long += " The sea ends here along the southern shore of "
  	        "Kailie's northern continent. ";
  }
  
  /* Lloryk Road Area*/
  if (x < -71 && x >= -85 && y == 2) {
  	ne = n = 0; 		
  	if (x != -85) nw = 0;
  	SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  	long += " The sea ends here along the southern shore of "
  	        "Kailie's northern continent. ";
  }
  
  if (x == -87 && y >= 4 && y <= 6) {
  	e = ne = 0; 	
  	if (y != 4) se = 0;
  	if (y == 6) n = nw = 0;
  	
  	SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  	long += " The sea ends here along the southern shore of "
  	        "Kailie's northern continent. ";
  }
  if (x == -88 && y == 6) {
  	nw = ne = 0;
    SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  	long += " The sea ends here along the southern shore of "
  	        "Kailie's northern continent. ";
  }
  if (x == -89 && y == 6) {
  	nw = w = ne = n = 0;
    SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  	long += " The sea ends here along the southern shore of "
  	        "Kailie's northern continent. ";
  }	
  if ((x == -89 && y == 5) || (x == -90 && y == -1) ||
  	  (x == -91 && y == -2)) nw = 0;    
    	
  if (x == -90 && y <= 5 && y >= 0) {
  	w = nw = 0;
  	if (y == 5) n = 0;
  	if (y != 0) sw = 0;
  	SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  	long += " The sea ends here along the southern shore of "
  	        "Kailie's northern continent. ";
  }	
  if (x == -91 && y == -1) {
  	n = nw = w = 0;
  	SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  	long += " The sea ends here along the southern shore of "
  	        "Kailie's northern continent. ";
  }	

  /* Around Gwonish Coast */
  if (x <= -92 && x >= -97 && y == -2) {
  	n = 0;
  	if (x != -92) ne = 0;
  	if (x != -97) nw = 0;
  	SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  	long += " The sea ends here along the southern shore of "
  	        "Kailie's northern continent. ";
  }	
  if (x == -98 && y >= -2 && y < 0) {
  	if (y == -2) ne = 0;
  	if (y == -1) {
  		SetProperty("shallows", 1);
  		RemoveProperty("ocean");
  		long += " The sea ends here along the southern shore of "
  	        "Kailie's northern continent. ";
  	  e = ne = nw = 0;
  		}
  	}
  if (x == -98 && y == 0) se = 0;
  if (y == 0 && x <= -98 & x >= -155) {
  	n = ne = 0;
  	if (x == -98) e = 0;
  	if (x != -155) nw = 0;
  	SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  	long += " The sea ends here along the southern shore of "
  	        "Kaiie's northern continent. ";
  }
  if (x == -156 && y == 0) {
  	ne = 0;
  	SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  	long += " The sea ends here along the southwestern shore of "
  	        "Kailie's northern continent. ";
  } 

  /* East Coast */
  
  if (x > 3 && x <= 6 && y >= 0 && y < 4) {
    int delta = (x - 3);
    if (y - delta >= -1) {
    	nw = 0;
    	if (y - delta >= 0) {
    		if ((x != 6 ) && (y != 3)) n = 0;
    		w = 0;
  			SetProperty("shallows", 1);
  			RemoveProperty("ocean");
  			long += " The sea ends here at the southeastern shore of "
  	    		    "Kailie's northern continent. ";
  			}
  		}
  	} 
  		  
  if (x == 6 && y >= 4 && y < 33) {
    w = nw = sw = 0;
    SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  	if (y >= 10) {
  		long += " The Ruined Sea washes against the HavenWood here, "
  	        "and off to the west nothing but trees can be seen.";
    }
  	else { long += " The sea ends here at the eastern shore of "
  	        "Kailie's northern continent. ";
  	}
  }   
   
  /* Mark off the HavenWood */
  if (y == 33 && x >= 6 && x <= 10) {
  	nw = n = 0;
    if (x != 10) ne = 0;
    if (x == 6) w = 0;
    long += " The Ruined Sea runs up and laps against the "
            "smooth and sandy beach to the north.";
    SetProperty("shallows", 1);
    RemoveProperty("ocean");
  }
  
  if ((x == 11 && y == 33) || (x == 12 && y == 34)) {
  	nw = 0;
  	long += " The Ruined Sea runs up and laps against the "
            "smooth and sandy beach to the northwest.";
    SetProperty("shallows", 1);
    RemoveProperty("ocean");
  }
  if (x == 11 && y == 34) {
  	n = nw = 0;
  	long += " The Ruined Sea runs up and laps against the "
            "smooth and sandy beach to the north and west.";
    SetProperty("shallows", 1);
    RemoveProperty("ocean");
  }
  if (x == 12 && y >= 35 && y < 38) {
  	w = nw = 0;
  	if (y != 35) sw = 0;
  	long += " The Ruined Sea runs up and laps against the "
            "smooth and sandy beach to the west.";
    SetProperty("shallows", 1);
    RemoveProperty("ocean");
  }
  
  if (y == 38 && x >= 12 && x < 25) {
  	n = nw = 0;
  	if (x == 12) sw = 0;
  	if (x != 24) ne = 0;
  	SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  	if (x != 12) {
  		long += " The Ruined Sea washes against the HavenWood here, "
  	          "and off to the north nothing but trees can be seen.";
  	  }
  		else {
  			long += " The Ruined Sea runs up and laps against the "
            "smooth and sandy beach to the west and nothing but "
            "trees can be seen to the north.";
      	}
  }  		
  
  /* Curve upward towards Parva (NE) and not letting anything get behind */  
  if (x >= 25 && y >= 38 && x <= 30 && y <= 44) {
  	int delta = (x - 25);
    if ((y - 39) - delta >= -1) {
    	nw = 0;
     	if ((y - 39) - delta >= 0){
    		w = 0;
    		if (x != 30 && y != 44) {
    			n = 0;
    			SetProperty("shallows", 1);
      		RemoveProperty("ocean");
    		  long += " The Ruined Sea runs up and laps the coast here, but to the "
                "north and west nothing can be seen but trees and dark woods.";
        }
        else {
        	SetProperty("shallows", 1);
      		RemoveProperty("ocean");
        	long += " The Ruined Sea runs up and laps the coast here, but to the "
                "west nothing can be seen but trees and dark woods."; 
        }
  		}
 		}
 	}
  /* End of curving */

  /* Parvan Coast */  		
 	if (x == 30 &&  y > 44 && y <= 50) {
  		w = nw = sw = 0;
  		SetProperty("shallows", 1);
      RemoveProperty("ocean");
  		if (y <= 47) {
  			long += " The Ruined Sea runs up and laps the coast here, battering "
      	   			"the port of Parva to the west.";
      	   		}
      	else if (y == 50) {
      		n = ne = 0;
      		long += " The Ruined Sea runs up and laps the coast here, but to "
      						"the north and west nothing can be seen but trees and "
      						"dark woods.";
      		}
      		else {
      			long += " The Ruined Sea runs up and laps the coast here, but to "
      			  			"the west nothing can be seen but trees and dark woods.";
      			}
      	}
    
    if (x > 30 &&  x < 55 && y == 50) {
    	n = nw = 0;
    	if (x != 54) ne = 0;
    	SetProperty("shallows", 1);
      RemoveProperty("ocean");
    	long += " The sea crashes up against the shore battering the Estergrym Mountains "
    	        "that are to the north. ";
   	}
		if (x == 55 && y == 50) {
			nw = 0;
			SetProperty("shallows", 1);
      RemoveProperty("ocean");
			long += " The sea crashes up against the shore battering the Estergrym Mountains "
    	        "that are to the northwest. ";
   	} 
    if (x == 55 && y > 50 && y < 110) {
    	if (y != 109) nw = 0;
    	sw = w = 0;
    	SetProperty("shallows", 1);
      RemoveProperty("ocean");
    	long += " The sea crashes up against the shore battering the Estergrym Mountains "
    	        "that are to the west. ";
   	} 
   	if (x == 55 && y == 110) {
   	  sw = 0;
   	  long += " The sea curves around the northeasten edge of Kailie's main continent here.";
   	}
  /* North Coast */

  if (y == 112 && x > -155 && x < -51) {
    se = s = sw = 0;
    long += " The waves crash against the northern shores of Kailie's main continent.";
  }
  if (y == 110 && x > -59 && x < 54) {
    se = sw = s = 0;
    long += " The waves crash against the northern shores of Kailie's main continent.";
  }
  if (y == 110 && x == 54) {
    s = sw = 0;
    long += " The ocean curves around the edge of Kailie's main continent here.";
  }
  
  /* West Coast */
  
  if (x == -156 && y > 1 && y < 111) {
    ne = se = e = 0;
    long += " The sea crashes against the western shores of Kailie's northern continent here.";
  }
  if (x == -156 && y == 1) {
    ne = e = 0;
    long += " The shore curves to the southeast around the edge of Kailie's main continent.";
  }
  if (x == -156 && y == 111) {
    se = e = 0;
    long += " The shore curves northeast around the edge of Kailie's main continent.";
  }
  
  /* Shallows */
  
  if (x >= -170 && x <= 35 && y >= -10 && y <= 120) {
  	if (GetProperty("ocean")) {
  		RemoveProperty("ocean");
  		SetProperty("shallows", 1);
  		long += " The water is a deep green here so close to land.  While "
  		        "deep enough to drown in, the water isn't too far from land.";
    }
  }
/* Tai-Ri */
  
  if (x >= 80 && x <= 220 && y <= -30 && y >= -160) {
    SetSailingDifficulty(10);
  	if (GetProperty("ocean")) {
  		RemoveProperty("ocean");
  		SetProperty("shallows", 1);
  		SetDomain("Tairi"); 		
      short = "the Seas of Tairi";
                long = "Near the far eastern lands of Tairi, the water is a deep green. Too "
  		        "deep for wading yet not so far from land to require an ocean "
  		        "vessel, the shallows make for excellent sport.";
  		}
   }
  if (x <= 185 && x >= 115 && y <= -50 && y >= -140) {
  	if (x ==  185) {
  		if (y < -50) nw = 0;
  	  if (y > -140) sw = 0;
  	  if (y != -140 && y != -50) { 
  	  	w = 0;
  		  long += " To the west lie the lands of Tairi.";
  		  }
  	}
  	if (x == 185 && y == -50) {
  		sw = 0;
  		long += " To the southwest lie the lands of Tairi.";
  	}	
  	if (x == 115 && y == -50) {
  		se = 0;
  		long += " To the southeast lie the lands of Tairi.";
  	}  	
  	if (x == 185 && y == -140) {
  		nw = 0;
  		long += " To the northwest lie the lands of Tairi.";
  	}
  	if (x == 115 && y == -140) {
      ne = 0;
  		long += " To the northeast lie the lands of Tairi.";
  	}
  	if (x == 115) {
  		if (y < -50) ne = 0; 
  	  if (y > -140) se = 0; 
  		if (y != -50 && y != -140) {
  			e = 0;
  			long += " To the east lie the lands of Tairi.";
  		}
  	}
  	if (y == -50) {
  		if (x < 185) se = 0;
  	  if (x > 115) sw = 0;
  		if (x != 115 && x != 185) { 
  		  s = 0;
  		  long += " To the south lie the lands of Tairi.";
  		}
  	}
  	if (y == -140) {
  		if (x < 185) ne = 0;
  	  if (x > 115) nw = 0;
  		if (x != 115 && x != 185) {
  			n = 0;
  		  long += " To the north lie the lands of Tairi.";
  		}
  	}
  }
/* Averath */

  if (x >= -15 && x <= 15 && y <= -90 && y >= -115) {
  	if (GetProperty("ocean")) {
  		RemoveProperty("ocean");
  		SetProperty("shallows", 1);
  		SetDomain("Averath");
  		long += " Near the Island of Averath, the water is a deep green.  Too "
  		        "deep for wading yet not so far from land to require an ocean "
  		        "vessel, the shallows make for excellent sport.";
  		}
   }
  if (x <= 10 && x >= -10 && y <= -100 && y >= -110) {
  	if (x ==  10) {
  		if (y < -100) nw = 0;
  	  if (y > -110) sw = 0;
  	  if (y != -110 && y != -100) { 
  	  	w = 0;
  		  long += " To the west lies Averath Island.";
  		  }
  	}
  	if (x == 10 && y == -100) {
  		sw = 0;
  		long += " To the southwest lies Averath Island.";
  	}	
  	if (x == -10 && y == -100) {
  		se = 0;
  		long += " To the southeast lies Averath Island.";
  	}  	
  	if (x == 10 && y == -110) {
  		nw = 0;
  		long += " To the northwest lies Averath Island.";
  	}
  	
  	if (x == -10 && y == -110) {
      ne = 0;
  		long += " To the northeast lies Averath Island.";
  	}
  	if (x == -10) {
  		if (y < -100) ne = 0; 
  	  if (y > -110) se = 0; 
  		if (y != -100 && y != -110) {
  			e = 0;
  			long += " To the east lies Averath Island.";
  		}
  	}
  	if (y == -100) {
  		if (x < 10) se = 0;
  	  if (x > -10) sw = 0;
  		if (x != 10 && x != -10) { 
  		  s = 0;
  		  long += " To the south lies Averath Island.";
  		}
  	}
  	if (y == -110) {
  		if (x < 10) ne = 0;
  	  if (x > -10) nw = 0;
  		if (x != 10 && x != -10) {
  			n = 0;
  		  long += " To the north lies Averath Island.";
  		}
  	}
  }

    /*  Namatar */

  if (x > -500 && x < -300 && y > -100 && y < 100) {
    RemoveProperty("ocean");
    SetProperty("shallows", 1);
    SetDomain("Namatar");
    short = "the Sea of Namatar";
    long += " The water is shallower here near the coast of a large island.";
  }
  if (x == -350 && y <= 50 && y >= -50) {
    if (y != 50 && y != -50) w = 0;
    if (y != -50) sw = 0;
    if (y != 50)  nw = 0;
    long += " The water abuts the shores of a large island here.";
  }
  if (x == -450 && y <= 50 && y >= -50) {
    if (y != 50 && y != -50) e = 0;
    if (y != -50) se = 0;
    if (y != 50)  ne = 0;
    long += " The water abuts the shores of a large island here.";
  }
  if (y == 50 && x <= -350 && x >= -450) {
    if (x != -350 && x != -450) s = 0;
    if (x != -350) se = 0;
    if (x != -450) sw = 0;
    long += " The water abuts the shores of a large island here.";      
  }
  if (y == -50 && x <= -350 && x >= -450) {
    if (x != -350 && x != -450) n = 0;
    if (x != -350) ne = 0;
    if (x != -450) nw = 0;
    long += " The water abuts the shores of a large island here.";      
  }
/* Specific Connections */

  if (x == -13 && y == 1) {
  	s  = OCEAN + -13 + "," + 0;
  	se = OCEAN + -12 + "," + 0;
  	ne = SOUTHERN_COAST_AREAS "acove/rooms/cove3";
  	SetProperty("coastal", 1);
  	RemoveProperty("ocean");
  	RemoveProperty("shallows");
  	long = "The sea ends here along a sandy white beach. A beached ship "
  	        "sits behind some sand dunes to the east. ";
  }
  if (x == -21 && y == 0) {
  	n = SOUTHERN_COAST_AREAS "meadow/rooms/meadow11";
  	long += " Directly to the north is Platypus Bay.";
  	}
  if (x == -20 && y == 0) {
  	n = SOUTHERN_COAST_AREAS "meadow/rooms/meadow12";
  	long += " Directly to the north is Platypus Bay.";
  	}
  if (x == -19 && y == 0) {
  	n = SOUTHERN_COAST_AREAS "meadow/rooms/meadow13";
  	long += " Directly to the north is Platypus Bay.";
  	}
  if (x == 0 && y == -100) {
  	s = AVERATH_TOWNS "averath/room/wharf";
  	long += " Directly to the south is the Wharf at Averath.";
  	}
  if (x == 1 && y == -100) {
    s = AVERATH_TOWNS "averath/room/charter";
    long += " Directly to the south is the Charter Ferry Wharf at Averath.";
  }
  if (x == -26 && y == -7) {
     w = PENINSULA_TOWNS "sanctum/room/rd05";
     }
  if (x == -32 && y == -12) {
     n = PENINSULA_TOWNS "sanctum/room/docks";
     long += " The docks of Sanctum lies to the north. ";
     }	
  if (x == 0 && y == 0) {
     n = SOUTHERN_COAST_TOWNS "haven/room/wharf";
     long = " The Ruined Sea stretches out to the horizon. To the north lies "
            "Haven Town. ";
     }
  if (x == 30 && y == 46) {
     w = HAVENWOOD_TOWNS "parva/room/docks1";
     long += " Directly to the west lie the Parva docks.";
     }
  if (x == 9 && y == 33) {
  	 n = HAVENWOOD_AREAS "wood/rooms/beach10";
  	}
  if (x == 10 && y == 33) {
  	 n = HAVENWOOD_AREAS "wood/rooms/beach11";
  	}
  if (x == 11 && y == 33) {
  	 nw = HAVENWOOD_AREAS "wood/rooms/beach11";
  	}
  if (x == 11 && y == 34) {
  	 w = HAVENWOOD_AREAS "wood/rooms/beach11";
  	 n = HAVENWOOD_AREAS "wood/rooms/beach12";
  	}
  if (x == 12 && y == 34) {
  	 nw = HAVENWOOD_AREAS "wood/rooms/beach12";
  	}	
  if (x == 12 && y == 35) {
  	 w = HAVENWOOD_AREAS "wood/rooms/beach12";
  	}
  if (x == 12 && y == 36) {
  	 w = HAVENWOOD_AREAS "wood/rooms/beach13";
  	}
  if (x == 12 && y == 37) {
  	 w = HAVENWOOD_AREAS "wood/rooms/beach14";
  	}
  if (x == 12 && y == 38) {
  	 w = HAVENWOOD_AREAS "wood/rooms/beach15";
  	}
  if (x == 150 && y == -50) {
     s = TAIRI_TOWNS "tairi/room/path11";
     long += " The village of Tairi lies to the south.";
     } 
  if (x == -88 && y == 6) {
  	 n = CRYSTAL_REACHES_TOWNS "lloryk/room/wharf";
  	 long += " The Shire lies to the north.";
  	 }
  if (x == -49 && y == 110) {
     w = GUROV_TOWNS "gurov/room/bay5";
     s = GUROV_TOWNS "gurov/room/bay7";
     se = sw = 0;
     long += " The Gurov Bay lies to the south and west.";
     }
  if (x == -50 && y == 111) {
     w = GUROV_TOWNS "gurov/room/bay3";
     s = GUROV_TOWNS "gurov/room/bay5";
     sw = 0;
     long += " The Gurov Bay lies to the south and west.";
     }
  if (x == -51 && y == 112) {
     s = GUROV_TOWNS "gurov/room/bay3";
     sw = 0;
     long += " The Gurov Bay lies to the south.";
     }
  if (x == -50 && y == 112) {
    sw = 0;
    long += " To the southwest lies Gurov Bay.";
  }
  if (x == -49 && y == 111) {
    sw = 0;
    long += " To the west and south lie Gurov Bay.";
  }
  if (x == -68 && y == -2) {
     n = CRYSTAL_REACHES_TOWNS "karak/room/rd7";
     long += " To the north lies the Orcish city of Karak.";
     }
  if (x == -97 && y == -2) {
     n = CRYSTAL_REACHES_AREAS "gwonish/room/swamp25";
     long += " To the north lies a few boulders.";
     }
  if (x == -93 && y == -2) {
     n = CRYSTAL_REACHES_TOWNS "gwonish/room/gw01";
     long += " To the north lies the Lizardman village of the Gwonish Swamp.";
     }
  if (x == -155 && y == 112) {
    s = FROSTMARCHES_TOWNS "keryth/room/wharf";
    se = 0;
    long += " To the south lies the home of the Goden, the city of Keryth.";
  }
  if (x == -156 && y == 111) {
    e = FROSTMARCHES_TOWNS "keryth/room/wharf";
    long += " To the east lies the home of the Goden, the city of Keryth.";
  }
  if (x == -156 && y == 112) {
    se = FROSTMARCHES_TOWNS "keryth/room/wharf";
    long += " To the southeast lies the home of the Goden, the city of Keryth.";
  }
  if (x == -150 && y == 0) {
    n = BARIA_TOWNS "baria/room/path12";
    long += " The village of Baria lies to the north.";
  }
  if (x == -350 && y < 50 && y > -50) {
    w = NAMATAR_VIRTUAL "namatar/" + -351 + "," + y;
  }
  if (x == -450 && y < 50 && y > -50) {
    e = NAMATAR_VIRTUAL "namatar/" + -449 + "," + y;
  }
  if (y == 50 && x < -350 && x > -450) {
    s = NAMATAR_VIRTUAL "namatar/" + x + "," + 49;
  }
  if (y == -50 && x < -350 && x > -450) {
    n = NAMATAR_VIRTUAL "namatar/" + x + "," + -49;
  }
  /* The End of the World As We Know It */
  
  if (x ==  500) { 
    e  = OCEAN + "-500," + y;
    se = OCEAN + "-500," + (y -1);
    ne = OCEAN + "-500," + (y +1);
  }
  if (x == -500) {
    w = OCEAN +  "500," + y;
    sw = OCEAN + "500," + (y -1);
    nw = OCEAN + "500," + (y +1);
  }
  if (y == 500) { 
  	n  = 0;
  	ne = 0;
  	nw = 0;
  	long += " To the north, ice makes the ocean completely impassable.";
  	RemoveProperty("ocean");
  	SetProperty("coastal", 1);
  }
  if (y == -500) {
  	if (x > 1 || x < -1) {
  	  s = XANDRIA_VIRTUAL "desert/" + x + ",0";
  	  sw = 0;
  	  se = 0;
  	  long += " To the south, the ocean ends along a desert coastline.";
    }
    else {
      s = XANDRIA_VIRTUAL "river/" + x + ",0";
      sw = 0;
      se = 0;
      long += " To the south lies the delta to a large and deep river.";
    }
  }
  if (climate != "") SetClimate(climate); 
  SetLong(long);
  SetShort(short);
  SetListen("default", listen);
  SetSmell("default", smell);
  if (n) AddExit("north", n);
  if (s) AddExit("south", s);
  if (e) AddExit("east", e);
  if (w) AddExit("west", w);
  if (nw) AddExit("northwest", nw);
  if (sw) AddExit("southwest", sw);
  if (se) AddExit("southeast", se);
  if (ne) AddExit("northeast", ne);
  
  if (ISLANDS_D->GetNearbyIsland(x, y)) ISLANDS_D->ProcessIsland(this_object(), x, y);

}



/*  This is to stop a massive issue. Massive. */

void heart_beat() {
	::heart_beat();
  foreach (object o in deep_inventory(this_object())) {
    if (userp(o)) return;
  }
  counter++;
  if (counter > 3)
    eventDestruct();
}
