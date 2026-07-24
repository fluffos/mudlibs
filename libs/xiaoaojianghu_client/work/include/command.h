// command.h
// NOTE (WASM-enablement pass, 2026-07-24): BOS/ADM/ARC/ANG/WIZ/APR/GEN/IMM_PATH
// shipped as `({})` in the raw archive -- this lib never included any actual
// wizard-only command directory. Combined with commandd.lpc's
// `find_command()` (`if (!pointerp(path)) return 0;` -- note `({})` IS a
// pointer, so this isn't even that guard, it's simply an empty search list),
// any account promoted to (admin)/(wizard)/(immortal) status via wizlist got
// set_path()'d to an EMPTY command path in feature/command.lpc's
// enable_player(), silently breaking EVERY command for that account,
// including basic ones like `look`/`quit` -- a genuine pre-existing bug, not
// a conversion artifact (confirmed identical in the raw archive). Since no
// wizard-specific command files exist anywhere in this lib to populate these
// with, aliased them to the same directories as PLR_PATH so promoted
// accounts keep normal command access instead of being completely locked
// out.
#define BOS_PATH ({"/cmds/std/", "/cmds/usr/", "/cmds/skill/"})
#define ADM_PATH ({"/cmds/std/", "/cmds/usr/", "/cmds/skill/"})
#define ARC_PATH ({"/cmds/std/", "/cmds/usr/", "/cmds/skill/"})
#define ANG_PATH ({"/cmds/std/", "/cmds/usr/", "/cmds/skill/"})
#define WIZ_PATH ({"/cmds/std/", "/cmds/usr/", "/cmds/skill/"})
#define APR_PATH ({"/cmds/std/", "/cmds/usr/", "/cmds/skill/"})
#define GEN_PATH ({"/cmds/std/", "/cmds/usr/", "/cmds/skill/"})
#define IMM_PATH ({"/cmds/std/", "/cmds/usr/", "/cmds/skill/"})
#define PLR_PATH ({"/cmds/std/", "/cmds/usr/", "/cmds/skill/"})
#define UNR_PATH ({"/cmds/usr/", "/cmds/std/", "/cmds/skill/"})
#define NPC_PATH ({"/cmds/usr/", "/cmds/std/", "/cmds/skill/"})
#define COMA_PATH ({"/cmds/usr/"})
// These are command objects that will also be called in those
// non-player objects.
#define DROP_CMD        "/cmds/std/drop"
#define GET_CMD         "/cmds/std/get"
#define GO_CMD          "/cmds/std/go"
#define TELL_CMD        "/cmds/usr/tell"
#define UPTIME_CMD      "/cmds/usr/uptime"
#define WHO_CMD         "/cmds/usr/who"
#define WEAR_CMD         "/cmds/std/wear"
