#define TP                   this_player()
#define TO                   this_object()
#define NAME                 QueryRealName()
#define GUILD                QueryGuild()
#define BG                   "/d/ireland/common/guild/guild"
#define BANISH               "/d/ireland/common/log/banish"
#define PROMOTE              "/d/ireland/common/log/promote"
#define FAIL(x) return (notify_fail(x) && 0)
#include <secure/wizlevels.h>
#include <properties.h>
#include <moving.h>
