/* Tamedhon MUDLIB
 * Samtpfote@tamedhon.at
 *
 * Zugriff auf das Repfile fuer 'inoffizielle' Mitarbeiter
 * (Seher, die proggen, aber nicht magier sind)
 */
#include <properties.h>
#include <wizlevels.h>

inherit "std/thing";

string	repfilename;

void reportfile_loeschen(string jn)
{
    if(jn == "J" || jn == "j" || jn == "ja")
    {
	write("*** Dein Reportfile wurde GELÖSCHT!!! ***\n");
	if(!rm(repfilename))
	{
	    write("Fehler beim Löschen von '"+repfilename+"'.\n");
	}
    }
    else
    {
	write("Ok, abgebrochen.\n");
    }
}

int wachstafel_cmds(string str)
{
    string	repfilename;

    notify_fail("Was möchtest Du mit der Wachstafel anstellen?\n");
    if(!str || (str == "")) return 0;
    
    repfilename = "/log/report/"+getuid(this_player())+".rep";
        
    if(str == "loeschen" || str == "löschen")
    {
	write("Willst Du WIRKLICH Dein Reportfile LÖSCHEN (j/n)?\n>");
	input_to("reportfile_loeschen");
	return 1;
    }
    
    if(str == "lesen")
    {
	write(" -- "+repfilename+" --\n");
	this_player()->More(read_file(repfilename));
	return 1;
    }
    
    return 0;
}

int wachstafel_lesen(string what)
{
    if(what == "wachstafel")
    {
	return wachstafel_cmds("lesen");
    }
 return 0;
}

void init()
{
    ::init();
    
    if(!IS_SEER(this_player())) return 0;
}

void create()
{
    if(!clonep(this_object())) return 0;
    ::create();
    
    AddAdjective("hölzerne");
    AddId(({"wachstafel", "tafel"})); 
    SetProp(P_GENDER, FEMALE);
    SetProp(P_NAME, "Wachstafel"); 
    SetProp(P_SHORT, "Eine hölzerne Wachstafel");
    SetProp(P_LONG, break_string(
	"Das ist eine kleine hölzerne Tafel aus Ulmenholz, "+
	"die bis auf einen schmalen Rand mit zähen, weißlichen "+
	"Wachs gefüllt wurde. Darin wurde etwas eingetragen."
	));
    SetProp(P_INFO, 
	"Mit dieser Tafel kannst Du auf dein Reportfile zugreifen. \n"+
	"\n"+
	"Befehle:\n"+
	"    - wachstafel lesen\n"+
	"    - wachstafel löschen\n"
	"\nWenn Bedarf an mehr Befehlen besteht, bitte bei einem \n"+
	"Magier melden.\n");
    SetProp(P_MATERIAL,
	([MAT_ELM_WOOD: 70, MAT_WAX: 95, MAT_MISC_MAGIC: 5]));
    SetProp(P_NODROP, "Die Wachstafel klebt irgendwie an Deinen Händen fest.\n");
    SetProp(P_AUTOLOADOBJ, 1);
    SetProp(P_VALUE, 0);
    SetProp(P_WEIGHT, 100);
    
    AddCmd("wachstafel", "wachstafel_cmds");
    AddCmd(({"les", "lese", "lies"}), "wachstafel_lesen");
}

