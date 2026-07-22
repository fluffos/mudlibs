#include <ansi.h>

string heart_str()
{
    string str;

    str = HIC"                ☆☆ ☆☆  ☆☆ ☆☆\n";
    str += HIW"               ★★      ★      ★★\n";
    str += HIM"              ☆☆    我的茫然    ☆☆\n";
    str += HIC"               ★★              ★★\n";
    str += HIM"                ☆☆            ☆☆\n";
    str += HIW"                  ★★        ★★\n";
    str += HIM"                    ☆☆    ☆☆\n";
    str += HIC"                       ★★★\n";
    str += HIW BLINK"                         ★\n"NOR;
    return str;
}


