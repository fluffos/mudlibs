/*
 * schrat.h -
 *
 * $Log$
 */

#ifndef _SCHRAT_H_
#define _SCHRAT_H_

#define SCHRAT  "/d/ebene/fidget/schrat/"
#define ROOM    SCHRAT "room/"
#define NPC     SCHRAT "npc/"
#define OBJ     SCHRAT "obj/"
#define WAEPON  SCHRAT "weapon/"
#define ARMOUR  SCHRAT "armour/"

#define QLOGFILE "/log/quests/schrat"
#define QUESTLOG(ob) write_file(QLOGFILE, sprintf("%s %s\n", \
      dtime(time())[5..], capitalize(geteuid(ob))))

#define DEBUG(str) if (find_player("fidget")) \
        tell_object(find_player("fidget"), break_string( \
        file_name(this_object())+"\n"+ (str)+"\n", 78, "##", 1))

#define BS(str) break_string((str), 78, "", 1)

#define AUSGANG "/d/ebene/Park/room/room_j16"  

#endif _SCHRAT_H_

