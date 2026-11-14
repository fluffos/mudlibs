// 
//	Header-File 
//	fuer den  
//	Kristallwald 
// 
//	date: 11-01-97 
//	Mit Anregungen von meiner Mami! 
// 
//	Re-Design am 25-01-87 
// 
 
#define GEBIET "dorf"
#define PFAD "/d/kristallwald/sargola/" 
#define WOHNORT "/players/sargola/"
 
#define ROOM_SEE PFAD+"see/room/" 
#define ROOM_WALD PFAD+"wald/room/" 
#define ROOM_GEBIRGE PFAD+"gebirte/room/" 
#define ROOM_DORF PFAD+"dorf/room/" 
#define ROOM_LICHTUNG PFAD+"lichtung/room/"
//#define ROOM_SEHER PFAD+"seher/room/"


#define NPC_SEE PFAD+"see/npc/" 
#define NPC_WALD PFAD+"wald/npc/" 
#define NPC_GEBIRGE PFAD+"gebirge/npc/" 
#define NPC_DORF PFAD+"dorf/npc/" 
#define NPC_LICHTUNG PFAD+"lichtung/npc/"
#define NPC_SEHER PFAD+"seher/npc/"
 
#define OBJ_SEE PFAD+"see/obj/" 
#define OBJ_WALD PFAD+"wald/obj/" 
#define OBJ_GEBIRGE PFAD+"gebirge/obj/" 
#define OBJ_DORF PFAD+"dorf/obj/" 
#define OBJ_LICHTUNG PFAD+"lichtung/obj/"
#define OBJ_SEHER PFAD+"seher/obj/"
 
#define LOG PFAD+"log/" 
 
#define MAGIERNAME "sargola" 
#define DB(x) if (find_player(MAGIERNAME)) tell_object(find_player(MAGIERNAME),(x)) 
 
#define BSS(s) break_string(s,65) 
#define bs(s) break_string(s) 

#include "./def.h"
