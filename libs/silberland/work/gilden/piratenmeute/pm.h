//Definitionen fuer die Piratenmeute
//

//gilden/files.piratenmeute/pm.h

//Pfade
#define PMHOME "/gilden/files.piratenmeute/"
#define PMROOM(x) (PMHOME+"room/"+x)
#define PMNPC(x) (PMHOME+"npc/"+x)
#define PMOBJ(x) (PMHOME+"obj/"+x)
#define PMMASTER "/gilden/files.piratenmeute/obj/pmmaster"

//Player

#define TP this_player()
#define TPN capitalize(this_player()-name())
#define GIVE(x) {x->move(environment(TP)); x->move(TO);}


//Props aus der Bierschuettlergilde
/*
#define P_BS_NEBEL "bsg:nebelschadenstyp"
#define P_BS_NEBELZEIT "bsg:nebel"
#define P_BS_MASSAGE "bsg:massage"
#define P_BS_STARRE "bsg:starre"
#define P_BS_IGNORE "bsg:ignorieren"
#define P_BS_ERDBEBENSCHUTZ "bsg:erdbebenschutz"
*/

//LOGS
#define DO_LOG_EINAUS(x) log_file("yondala/pm_io.log",dtime(time())+" "+capitalize(getuid(TP))+" ist gerade "+x+"!\n")
#define DO_LOG_ADVANCE(x) log_file("yondala/pm_adv.log", dtime(time())+" "+capitalize(getuid(TP))+" hat gerade Stufe "+x+" erreicht!\n")
#define DO_LOG_PUB_TRY(x) log_file("yondala/pubtries/pubtries.log", dtime(time())+" "+capitalize(getuid(TP))+" "+x+"\n");

//SYS
#define UA this_interactive()->_unparsed_args()
#define DETAIL "d"
#define BIER "b"
#define DTYPE "t"

//STDGEIST
#define GHOST_FOLLOWTIME "ghost_followtime"
#define GHOST_OWNER "ghost_owner"
