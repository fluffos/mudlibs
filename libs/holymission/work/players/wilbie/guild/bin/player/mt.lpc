/* =============================================================== 
   Userdoc: mt                   /players/whisky/guild/skills/mt.c
   ---------------------------------------------------------------
   Art: Mindtransfer (psychonic feature)
   Damage || Heal: none
   Cost: 2
   Special: This is a feature, which makes the same as the tell
            command of the player. But is more natural. 
   =============================================================== */

#include <sys_defs.h>  

#define COST		2
#define IDLE_WARN	120

int main(string sStr) {
    string sWhom, sWhat, sIdle, sVerb;
    int    iIdle, iImm;
    object oOb;

    sVerb = query_verb();
    iImm = TP->IMM || TP->TESTP;
    notify_fail("Usage: "+(sVerb == "remt" ? "remt" : "mt <player>")
               +" <message>\n");

    if(!sStr ||
       (sVerb != "remt" && sscanf(sStr, "%s %s", sWhom, sWhat) != 2))
        return 0;
    else if(TP->query_sp() < COST && !iImm) {
        write("You are too low on power.\n");
        return 1;
    }
    else {
        if(sVerb == "remt") {
            sWhom = TP->queryenv("REPLY");
            if(!sWhom || sWhom == "") {
                write("No-one to 'remt' to.\n");
                return 1;
            }
            else
                sWhat = sStr;
        }
        else
            sWhom = LOW(sWhom);
        oOb = find_living(sWhom);
    }

    if(!objectp(oOb)) {
        printf("No player with that name (%s).\n",
               CAP(sWhom));
        return 1;
    }

    else if(query_once_interactive(oOb)) {
        if(oOb->query_linkdeath()) {
            printf("%s is currently linkdead. Message discarded.\n",
                   CAP(sWhom));
            return 1;   
        }
      
        else if(query_editing(oOb)) {
            printf("%s is using the editor right now. Message discarded.\n",
                   CAP(sWhom));
            return 1;
        }

        else if(oOb->query_earmuff_level() > TP->LEVEL) {
            printf("%s is busy right now. Message discarded.\n",
                   CAP(sWhom));
            return 1;
        }
        
        iIdle = query_idle(oOb);
        if(iIdle >= 3600)
            sIdle = sprintf(" (%dh)", iIdle/3600);
        else if(iIdle >= 60)
            sIdle = sprintf(" (%dm)", iIdle/60);
        else
            sIdle = sprintf(" (%ds)", iIdle);
            
        if(oOb->is_afk())
            printf("%s is afk%s. Message sent anyway.\n",
                   CAP(sWhom), iImm ? sIdle : "");
            
        else if(iIdle > IDLE_WARN)
            printf("%s is idle%s. Message sent anyway.\n",
                   CAP(sWhom), iImm ? sIdle : "");
    
        if(query_input_pending(oOb))
            printf("%s is writing something. Message sent anyway.\n",
                   CAP(sWhom));
    }

    if(!iImm && !oOb->IMM)
        TP->restore_spell_points(-COST);

    TP->setenv("RETELL",sWhom+" "+sWhat);
    oOb->setenv("REPLY",TP->RNAME);
    sWhat = ":*) "+sWhat+"\n";

    printf("You conzentrate on %s.\n",
           CAP(sWhom));
    ltell(oOb, "thinks:", sWhat, TP);
    return 1;
}
