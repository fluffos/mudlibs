#ifndef __SIGNAL_H__
#define __SIGNAL_H__

// These values are for slot registration
#define SIG_SLOT_OK                   1
#define SIG_SLOT_INVALID_CALLER       0
#define SIG_MISSING_SIGNAL           -1
#define SIG_MISSING_OBJECT           -2
#define SIG_MISSING_FUNCTION         -3
#define SIG_INVALID_FUNCTION         -4
#define SIG_INVALID_OBJECT           -5

// Standard system signals (string names, prefixed by SIG_SYS)
#define SIG_SYS                     "sys:"
#define SIG_SYS_BOOT                SIG_SYS "boot"
#define SIG_SYS_CRASH               SIG_SYS "crash"
#define SIG_SYS_SHUTTING_DOWN       SIG_SYS "shutting-down"
#define SIG_SYS_SHUTDOWN            SIG_SYS "shutdown"
#define SIG_SYS_SHUTDOWN_CANCEL     SIG_SYS "shutdown-cancel"
#define SIG_SYS_REBOOTING           SIG_SYS "rebooting"
#define SIG_SYS_REBOOT_CANCEL       SIG_SYS "reboot-cancel"
#define SIG_SYS_PERSIST             SIG_SYS "persist"
#define SIG_SYS_CRAWL_COMPLETE      SIG_SYS "crawl-complete"

// Standard user signals
#define SIG_USER                    "user:"
#define SIG_USER_LOGIN              SIG_USER "login"
#define SIG_USER_LOGOUT             SIG_USER "logout"
#define SIG_USER_LINKDEAD           SIG_USER "linkdead"
#define SIG_USER_LINK_RESTORE       SIG_USER "link-restore"

// Player signals (string names, prefixed by SIG_PLAYER)
#define SIG_PLAYER                  "player:"
#define SIG_PLAYER_DIED             SIG_PLAYER "died"
#define SIG_PLAYER_REVIVED          SIG_PLAYER "revived"
#define SIG_PLAYER_ADVANCED         SIG_PLAYER "advanced"
#define SIG_USER_ENV_CHANGED        SIG_PLAYER "env-changed"
#define SIG_USER_PREF_CHANGED       SIG_PLAYER "pref-changed"

// Game signals (string names, prefixed by SIG_GAME)
#define SIG_GAME                    "game:"
#define SIG_GAME_MIDNIGHT           SIG_GAME "midnight"

// Channel signals (string names, prefixed by SIG_CHANNEL)
#define SIG_CHANNEL                 "channel:"
#define SIG_CHANNEL_MESSAGE         SIG_CHANNEL "message"

#endif // __SIGNAL_H__
