/* Skillreader, urspruengliche Version von Paracelsus@MorgenGrauen
 * Fri Feb 25 14:30:55 2000, Samtpfote
 *
 * Mon May  8 17:33:04 2000, Samtpfote@Tamedhon
 * ins Tamedhon gewandert.
 * 
 * $Date: 2001/01/13 13:17:57 $
 * $Revision: 1.1 $
 * $Log: skr.c,v $
 * Revision 1.1  2001/01/13 13:17:57  Samtpfote
 * Initial revision
 *
 */



#include <properties.h>
#include <language.h>
#include <terminal.h>
#include <wizlevels.h>
#include <new_skills.h>

#define BS		break_string
#define TP		this_player()
#define TO		this_object()

#define LOGFILE		"/log/ARCH/skillreader.log"

inherit "/std/thing";

void create()
{   if (!clonep(TO)) return;
    ::create();

    AddId(({"skr", "skillreader", "skill-reader"}));
  
    SetProp(P_SHORT,"Ein Skill-Reader");
    SetProp(P_NAME,"Skill-Reader");
    SetProp(P_WEIGHT,1);
    SetProp(P_VALUE,0);
    SetProp(P_AUTOLOADOBJ,1);
    SetProp(P_NODROP,"Das geht nicht !\n");
    SetProp(P_LONG,BS(
        "Die ist ein Skill-Reader. Er liest die NEWSKILLS-Propertie "+
        "eines Spielers aus und gibt die Fähigkeiten in lesbarer (?) "+
        "Form auf dem Bildschirm aus. Die Syntax hierfür ist: "+
        "\"skread <spielername>\".",78) );
}

void init()
{   ::init();
    if (IS_QUESTWIZ(TP))
    {
        add_action("skr","skread");
    }
    else
        add_action("fake","skread");
}

int fake()
{   
    string str, logdate;

    logdate=dtime(time())[4..];

    write_file(LOGFILE, logdate+" "+this_player()->name()+" != QuestWiz\n");    
    write("Nur für Magier !!!\n");
    call_out("remove",1);
    return 1;
}

int skr(string wer)
{   object pl;
    mapping s;
    string *ind;
    mixed ein;
    int i;
    
    string str, logdate;

    notify_fail(BOLD+"Syntax: skread <spielername>\n"+NORMAL);
    if (!wer) return 0;
    notify_fail(BOLD+"Spieler nicht gefunden !\n"+NORMAL);
    if (!(pl=find_player(wer))) return 0;
    notify_fail(BOLD+"Datenfehler 1"+NORMAL);
    s = pl->_query_newskills();
    if (!s) return 0;
    ind = m_indices(s);
    notify_fail(BOLD+"Datenfehler 2"+NORMAL);
    if (!ind) return 0;
    for (i=sizeof(ind)-1;i>=0;i--)
    {   ein = s[ind[i]];

        if (intp(ein))
            write(BOLD+sprintf("%-20s",ind[i])+NORMAL+" : "+ein+"\n");
        else if (mappingp(ein))
            if (member(ein,"si_abil"))
                write(BOLD+sprintf("%-20s",ind[i])+NORMAL+" : "+sprintf("%-5i",ein["si_abil"])+"\n");
            else
                write(BOLD+sprintf("%-20s",ind[i])+" : KEIN \"si_abil\" IM MAPPING\n"+NORMAL);
        else write(BOLD+sprintf("%-20s",ind[i])+" : KEIN WERT VORHANDEN\n"+NORMAL);
    }
    
    logdate=dtime(time())[4..];
    write_file(LOGFILE, logdate+" "+this_player()->name()+" -> "+pl->name()+"\n");
    
    return 1;
}
