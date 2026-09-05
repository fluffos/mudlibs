	/* Inquisitor's Time gauntlet */
#include "/players/wren/ansi.h";
inherit "obj/weapon";

int W,B,dam;

reset(arg)  {
    ::reset();
    if(arg) return;

set_name("gauntlet");
set_alias("glove");
set_short("a powered gauntlet");
set_long("The Time Gauntlet of the Inquisitor. This simulant is said to have survived to the end \n"+
         "of time. He concluded that there was no god or afterlife. He built this time-gauntlet \n"+  
	 "and now goes through history removing those that did little with their lives and replacing\n"+
         "them with those that never got a chance. A potentially useful device if you can figure it out\n");

set_type("glove");   /*sword,knife,club,axe,bow,polearm */
set_class(12);
set_weight(4);
set_value(5000);
set_hit_func(this_object());

}

weapon_hit(attacker) {
W = random(5);
switch(W) {

    case 0:
        B=B+1;
            if (B<=9) {
            say(this_player()->query_name() +" scans "+this_player()->query_possessive()+ " target and removes them from the timeline. \n");
            write("You run the deletion program removing your target from history and prepare to delete them. \n");
            write(B);
            return 5;
            break;
                  }
       
         if (B>9)  {
            say("The Time Gauntlet "+HIR+"fires"+NORM+" a violent blast of pure"+HIB+" TIME"+NORM+" to eliminate its target from existence.\n");
            say(">"+HIB+">>>>>>>>>>>>>>>>>>>>>>>>>>ZZZZZZZZZZZZZZZAAAAAAAAAAAAAAAPPPPPPPPPPPPPP>>>>>>>>>>>>>>>>>"+NORM+">\n");
            write("The deletion program has finished. Eliminate the originals. \n");
            write("Your fingers "+RED+"glow "+NORM+".\n"); 
            write("   \n");                               
            write("<<"+HIB+"PURE TIME"+NORM+" buffets your foe.>>\n"); 
            write(">"+HIB+">>>>>>>>>>>>>>>>>>>>>>>>>>ZZZZZZZZZZZZZZZAAAAAAAAAAAAAAAPPPPPPPPPPPPPP>>>>>>>>>>>>>>>>>"+NORM+">\n");
            write(" \n");

            write(B);
            B=0;
            return 40;
            
            
            break; 
                   }         
         
    case 1:
       say(this_player()->query_name()+ " fires an "+HIY+"energy bolt"+NORM+" into opponent... \n");
       write("You blast opponent with an "+HIY+"energy bolt"+NORM+". \n");
       return 10;
       break;
  
    case 2:
       say(this_player()->query_name()+" fumbles with the guantlet as the eletronics freeze up. \n");
       write("The gauntlet's hardware has frozen up, it will take a moment to reset... \n");
       return -20;
       break;

    case 3:
       say(this_player()->query_name()+" damands you" +HIK+" Justify Your Existence" +NORM+".\n");
       write("You challenge them to"+HIK+" Justify Their Existence" +NORM+".\n");
       return 10;
       break;

    case 4:
       say(this_player()->query_name()+" screams as the gauntlet's field inverts upon them.\n");
       write("You are "+HIY+"electrocuted"+NORM+". Someone must have reversed the controls.\n");
       dam=random(20);
       attacker->heal_self(-dam);
       break;
   }
return;
}
