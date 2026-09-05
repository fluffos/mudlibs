#ifndef __EDEFS__
#define __EDEFS__
#include "/players/eurale/closed/ansi.h"

/* player information */
#define ETP environment(this_player())
#define TP this_player()
#define TPN this_player()->query_name()
#define TPRN this_player()->query_real_name()
#define TPPOS this_player()->query_possessive()  /*  his/her  */
#define TPPRO this_player()->query_pronoun()     /*  he/she   */
#define TPOBJ this_player()->query_objective()   /*  him/her  */
#define TPL this_player()->query_level()
#define TPXL  this_player()->query_extra_level()
#define TPTL this_player()->query_total_level()
#define TPAC this_player()->query_ac()
#define TPWC this_player()->query_wc()
#define TPHP this_player()->query_hp()
#define TPSP this_player()->query_spell_point()
#define TPSTR this_player()->query_attrib("str")
#define TPSTA this_player()->query_attrib("sta")
#define TPWIL this_player()->query_attrib("wil")
#define TPMAG this_player()->query_attrib("mag")
#define TPPIE this_player()->query_attrib("pie")
#define TPSTE this_player()->query_attrib("ste")
#define TPLUC this_player()->query_attrib("luc")
#define TPINT this_player()->query_attrib("int")
#define TPGEXP this_player()->query_guild_exp()

/* object information */
#define ETO environment(this_object())
#define TO this_object()
#define ROOM environment(this_player())

/* Vampire information */
#define TPBPTS PFANGS->query_BLOODPTS()
#define BASE "/players/eurale/VAMPIRES/vampbase.lpc"
#define BITE "/players/eurale/VAMPIRES/OBJ/vampire_bite.lpc"
#define FANGS "/players/eurale/VAMPIRES/vampob.lpc"
#define PFANGS present("vampire fangs",TP)
#define FORM "/players/eurale/VAMPIRES/NPC/guild_form.lpc"
#define MEMBER "/players/nooneelse/black/guild_members_room.lpc"
#define VMEMBER "players/eurale/VAMPIRES/members/"
#define TRAITOR "/players/nooneelse/black/guild_prohibit.lpc"
#define MASTER "Master"
#define ASSISTANT "Vampire Underlord"
#define LIEUTENANT "Lieutenant"
#define TOP_FLOOR "/players/nooneelse/black/guild_office_floor_top.lpc"
#define SANCTUARY_ROOM "/players/eurale/VAMPIRES/RMS/vguild_hall.lpc"
#define COFFIN_ROOM "/players/nooneelse/black/guild_coffin_room"
#define COFFIN "/players/nooneelse/black/guild_coffin"
#define TRIAL_ROOM "/players/eurale/VAMPIRES/RMS/trial_room.lpc"
#define VAMP_WOLF "/players/eurale/VAMPIRES/NPC/vamp_wolf.lpc"
#define SUMMONS "/players/eurale/VAMPIRES/OBJ/summons.lpc"

#endif
