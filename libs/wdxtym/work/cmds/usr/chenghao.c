
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int min, hrs, day, mon, age;
		string sec;
        string out_str;
    	sec = sprintf(" 														 "HIY"°∫ ≥∆∫≈‰ﬂ °ª     "NOR"  \n");
	sec += sprintf(WHT""WHT""WHT""NOR"\n");

    	sec += sprintf(HIY"	" + ZJURL("cmds:chjl quxiao")ZJSIZE(25)"»°œ¬«∞◊∫≥∆∫≈"NOR" ")+sprintf(WHT"						" + ZJURL("cmds:chjl quxiao1")ZJSIZE(25)"»°œ¬≥…æÕ≥∆∫≈"NOR" \n");
//    	sec += sprintf(HIY"  °∫ ≥∆∫≈ °ª                    " + ZJURL("cmds:chjl quxiao1")ZJSIZE(25)"»°œ¬≥…æÕ≥∆∫≈"NOR" \n");
	sec += sprintf(WHT""WHT""WHT""NOR"\n");

if (me->query("chenghao/slr"))
        { 
        sec += sprintf(HIY"  …®µÿ…Æ																"  + ZJURL("cmds:chjl slr")ZJSIZE(25)"º§ªÓ≥∆∫≈"NOR" \n");
        sec += sprintf(HIW"  ∆’Õ®≥∆∫≈"NOR" \n");
    	}						
if (me->query("chenghao/zmjh"))
        { 
        sec += sprintf(HIY"   ÿ¡Í»À																"  + ZJURL("cmds:chjl zmjh")ZJSIZE(25)"º§ªÓ≥∆∫≈"NOR" \n");
        sec += sprintf(HIW"  ∆’Õ®≥∆∫≈"NOR" \n");
    	}    	
	
		sec = replace_string(sec,"\n",ZJBR)+"\n";
		write(ZJOBLONG+sec+"\n");
		
		
		
        return 1;
}


