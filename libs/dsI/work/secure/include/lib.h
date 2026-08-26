#ifndef s_lib_h
#define s_lib_h

#include "dirs.h"

#include "comp.h"
#include "events.h"
#include "lvs.h"
#include "props.h"
#include "std.h"
#include "user.h"

#define LIB_AUTH           DIR_SECURE_LIB "/auth"
#define LIB_BODY           DIR_LIB        "/body"
#define LIB_BURN           DIR_LIB        "/burn"
#define LIB_CAPTURE        DIR_LIB        "/capture"
#define LIB_CHAPEL         DIR_LIB        "/chapel"
#define LIB_CHAT           DIR_LIB        "/chat"
#define LIB_CLASSES        DIR_LIB        "/classes"
#define LIB_CLIENT         DIR_SECURE_LIB "/net/client"
/* FluffOS PORT NOTE: LIB_FTP_CLIENT was missing from this header --
 * secure/lib/net/ftp_client.lpc exists and secure/lib/net/ftp.lpc
 * references it. Same class of gap as LIB_GERM/LIB_VIRT_LAND above.
 */
#define LIB_FTP_CLIENT     DIR_SECURE_LIB "/net/ftp_client"
#define LIB_COMBAT         DIR_LIB        "/combat"
#define LIB_COMBATMSG      DIR_LIB        "/combatmsg"
#define LIB_COMMAND        DIR_LIB        "/command"
#define LIB_CONNECT        DIR_SECURE_LIB "/connect"
#define LIB_CREATOR        DIR_LIB        "/creator"
#define LIB_CURRENCY       DIR_LIB        "/currency"
#define LIB_DETECT         DIR_LIB        "/detect"
#define LIB_DIGGING        DIR_LIB        "/digging"
#define LIB_DISASTER       DIR_LIB        "/disaster"
#define LIB_DONATE	   DIR_LIB        "/donate"
#define LIB_DOOR           DIR_LIB        "/door"
#define LIB_EDITOR         DIR_LIB        "/editor"
#define LIB_ENTER          DIR_LIB        "/enter"
#define LIB_EXITS          DIR_LIB        "/exits"
#define LIB_FILE           DIR_SECURE_LIB "/file"
#define LIB_FILES          DIR_LIB        "/files"
#define LIB_FISH           DIR_LIB        "/fish"
#define LIB_FISHING        DIR_LIB        "/fishing"
#define LIB_FOLLOW         DIR_LIB        "/follow"
#define LIB_FUEL           DIR_LIB        "/fuel"
#define LIB_GENETICS       DIR_LIB        "/genetics"
/* FluffOS PORT NOTE: LIB_GERM was missing from this header entirely
 * (unlike LIB_UNDEAD's broken #ifdef guard elsewhere in this file,
 * this one was simply never defined) -- lib/std/germ.lpc exists and
 * `inherit LIB_GERM;` is used by 3 files (domains/Ylsrim/broken/
 * {cold,flu,jar}.lpc, a disease-item example). Added to match the
 * existing DIR_LIB "/<name>" convention every sibling macro uses.
 */
#define LIB_GERM           DIR_STD        "/germ"
#define LIB_GUILD          DIR_LIB        "/guild"
#define LIB_HELP           DIR_LIB        "/help"
#define LIB_HISTORY        DIR_LIB        "/history"
#define LIB_INTERACTIVE    DIR_LIB "/interactive"
#define LIB_INTERFACE      DIR_LIB "/interface"
#define LIB_LAMP           DIR_LIB "/lamp"
#define LIB_LANGUAGE       DIR_LIB "/language"
#define LIB_LEAD           DIR_LIB "/lead"
#define LIB_LEADER         DIR_LIB "/leader"
#define LIB_LIGHT          DIR_LIB "/light"
#define LIB_LIMB           DIR_LIB "/limb"
#define LIB_LIVING         DIR_LIB "/living"
#define LIB_LOGIN          DIR_SECURE_LIB "/login"
#define LIB_MAGIC          DIR_LIB        "/magic"
#define LIB_MATCH          DIR_LIB        "/match"
#define LIB_MEAL           DIR_LIB        "/meal"
#define LIB_MESSAGES       DIR_LIB        "/messages"
#define LIB_MONEY          DIR_LIB        "/money"
#define LIB_NMSH           DIR_LIB        "/nmsh"
#define LIB_NPC            DIR_LIB        "/npc"
#define LIB_PAGER          DIR_LIB        "/pager"
#define LIB_PERSIST        DIR_LIB        "/persist"
#define LIB_PILE           DIR_LIB        "/pile"
#define LIB_PLAYER         DIR_LIB        "/player"
#define LIB_POLE           DIR_LIB        "/pole"
#define LIB_POST_OFFICE    DIR_LIB        "/post_office"
#define LIB_RACE           DIR_LIB        "/race"
#define LIB_REMOTE         DIR_LIB        "/remote"
#define LIB_SCROLL         DIR_LIB        "/scroll"
#define LIB_SENTIENT       DIR_LIB        "/sentient"
#define LIB_SERVER         DIR_SECURE_LIB "/net/server"
#define LIB_SOCKET         DIR_SECURE_LIB "/net/socket"
#define LIB_SPELL          DIR_LIB        "/spell"
#define LIB_STEAL          DIR_LIB        "/steal"
#define LIB_TALK           DIR_LIB        "/talk"
#define LIB_TELLER         DIR_LIB        "/teller"
#define LIB_TORCH          DIR_LIB        "/torch"
#define LIB_TRAINER        DIR_LIB        "/trainer"
/* FluffOS PORT NOTE: this was `#ifdef Dead SoulsLPMud` in the original
 * archive -- a garbled #ifdef guard (not a real, definable macro name;
 * "Dead" is never #defined anywhere in this codebase) that silently
 * left LIB_UNDEAD undefined, breaking `inherit LIB_UNDEAD;` (a syntax
 * error: the driver's preprocessor left the bare identifier
 * unexpanded) in every file that inherits it -- lib/body.lpc and, via
 * body -> race -> living -> npc/sentient, effectively the entire
 * living-creature class hierarchy this whole game rests on. Every
 * sibling LIB_* macro in this header is defined unconditionally;
 * there's no evidence LIB_UNDEAD was ever meant to be conditional
 * (nothing else in the archive references a "Dead SoulsLPMud" guard
 * macro), so defined unconditionally to match.
 */
#define LIB_UNDEAD         DIR_LIB        "/undead"
#define LIB_VEHICLE        DIR_LIB        "/vehicle"
#define LIB_VERB           DIR_LIB        "/verb"
#define LIB_VIRTUAL        DIR_LIB        "/virtual"
/* FluffOS PORT NOTE: LIB_VIRT_LAND was missing from this header --
 * lib/virtual/virt_land.lpc exists and lib/virtual/virt_sky.lpc
 * inherits it. Same class of gap as LIB_GERM above.
 */
#define LIB_VIRT_LAND      DIR_LIB        "/virtual/virt_land"

#endif /* s_lib_h */
