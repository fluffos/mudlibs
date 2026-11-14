//
// def.h
// some definitions
/*
 * $Id$
 *
 * $Log$
 *
 */

#define DEBUG(x,y) if (find_player("creative")) tell_object(find_player("creative"), "|**"+x+"**| "+y+"\n")

#define PATH "/p/service/creative/bank/"
#define ROOM(x) PATH+"room/"+x
#define OBJ(x) PATH+"obj/"+x
#define NPC(x) PATH+"npc/"+x
#define LOG(x) PATH+"log/"+x
#define SAVE_DIR(x) PATH+"save/"+x

#define TO this_object()
#define TP this_player()
#define PO previous_object()
#define TPN TP->QueryProp(P_NAME)
#define TI this_interactive()
#define BS(x) break_string(x, 78)
#define ENV environment
#define TIPO TI||PO

