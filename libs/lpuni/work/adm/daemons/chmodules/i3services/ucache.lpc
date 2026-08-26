 /* ucache.c

 Tricky @ LPUniversity
 19-AUG-2006
 Intermud3 ucache service

 */

#include <mudlib.h>
#include <intermud3.h>

class userInfo
{
    string visname;
    int    gender;
}

staticv mapping ucache = ([ ]);

void addUserCache(string mudname, string username, string visname, int gender)
{
    class userInfo user;

    I3LOG("Notice [I3]: " + sprintf("Adding %s@%s (%s/%s)", username, mudname, visname, gender == 2 ? "other" : (gender ? "female" : "male")) + "\n");

    if(!ucache[mudname]) ucache[mudname] = ([ ]);

    user = new(class userInfo);
    user->visname = visname;
    user->gender = gender;
    ucache[mudname][username] = user;
}

mapping getUserCache() { return copy(ucache); }

string getVisname(string mudname, string username)
{
    class userInfo user;

    if(!ucache[mudname]) return 0;

    user = ucache[mudname][username];

    if(!user) return 0;

    return user->visname;
}

int getGender(string mudname, string username)
{
    class userInfo user;

    if(!ucache[mudname]) return -1;

    user = ucache[mudname][username];

    if(!user) return -1;

    return user->gender;
}

void rec_ucache_update(mixed *packet)
{
    addUserCache(packet[O_MUD], packet[6], packet[7], packet[8]);
}
