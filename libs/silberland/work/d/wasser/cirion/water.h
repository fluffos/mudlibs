/////////////////////////////////////////////////
//  Header-File fuer alle Unterwassergebiete
//  
//  01/99
//
//  Cirion@Silberland
//
//  V1.0
//
/////////////////////////////////////////////////

#include <defines.h>
#include <moredef.h>
#include <properties.h>
#include <combat.h>
#include <moving.h>
#include <new_skills.h>
#include <wizlevels.h>
#include <language.h>
#include <ansi.h>

#define EAROST_RACE "Wassermenschen"
// Diese Rasse koennen unter Wasser sprechen.
#define WSPEAKING_RACES ({EAROST_RACE})

#ifdef DBME
#undef DBME
#endif
#define DBME(x) if (find_player("cirion")) tell_object(find_player("cirion"),(x))

#define SERVICE "/players/cirion/service"

#define WHOME "/d/wasser/cirion"

#define WROOM WHOME+"/room"
#define WOBJ WHOME+"/obj"

#ifndef P_OBEN
#define P_OBEN ("oben")
#endif

#ifndef P_UNTEN
#define P_UNTEN ("unten")
#endif

#ifndef P_WEXIT_CMD
#define P_WEXIT_CMD "wexit_cmd"
#endif
#ifndef P_WEXIT_DEST
#define P_WEXIT_DEST "wexit_dest"
#endif
#ifndef P_WEXIT_MSG
#define P_WEXIT_MSG "wexit_msg"
#endif
#ifndef P_WEXIT_HIDDEN
#define P_WEXIT_HIDDEN "wexits_hidden"
#endif
#ifndef P_DEXIT_DIR
#define P_DEXIT_DIR "dexit_dir"
#endif
#ifndef P_DEXIT_DEST
#define P_DEXIT_DEST "dexit_dest"
#endif
