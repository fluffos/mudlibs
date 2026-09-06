#include <const.h>

#define INTERMUD3       "/secure/sockets/i3/intermud3"

// Trying to simplify things to avoid too-long-evals
//string colour(int x, int y) {
//   string buf = (y?" ":"\n");
//   if (x)
//      buf += (y%2?"~[140":"~[060");
//   else
//      buf += (y%2?"~[030":"~[070");
//   return buf;
//}

#define colour( x, y ) ((y)&1?"~[140":"~[060")

int main(string arg)
{
    mixed *info;
    mapping muds;
    string *names, *mudlist, it, buf;
    string color1, color2;
    int i, x, width;
    if (arg)
    {
        it = INTERMUD3->get_mud_name(arg);
        if (!it) {
           msg("Unknown mud: ~CBRT"+arg+"~CDEF");
           return 1;
        }
        info = INTERMUD3 -> query_mud_info(it);

        buf = "~CTIT"+it+"\n";
        buf += "~[030Mud type: ~CDEF"+pad(info[8],10,0);
        buf += " ~[030Driver: ~CDEF"+pad(info[7],20,0);
        buf += " ~[030Mudlib: ~CDEF"+info[5]+"\n";
        buf += "~[030Status: ~CDEF"+info[9]+"\n";
        buf += "~[030Services: ~CDEF" + implode(m_indices(info[11]), " ") + "\n";
        buf += "~[030Address: ~CDEF" + info[1] + " " + info[2];

        msg(buf);
        return 1;
    }
    names = m_indices(muds = INTERMUD3 -> query_muds());
    buf = "";
    info = m_values(muds);
    width = this_player()->query_term_width() - 1;
    mudlist = ({ });
    // When dealing with huge numbers of color codes, this
    // is a far more efficient way to deal with them.
    color1 = process_ansi("~[060", this_player());
    color2 = process_ansi("~[140", this_player());
    while (i < sizeof(names))
    {
        if (info[i][0]) {
            mudlist += ({
                   color1+pad(names[i],width * 21 / 80, JUST_LEFT) +
                   color2+pad(info[i][8],width * 6 / 80, JUST_LEFT) +
                   color1+pad(info[i][7],width * 14 / 80, JUST_LEFT) +
                   color2+pad(info[i][5],width * 14 / 80, JUST_LEFT) +
                   color1+pad(info[i][1],width * 16 / 80, JUST_LEFT) +
                   color2+info[i][2] });
        }
        ++i;
    }
    buf = implode(sort_array(mudlist,"sort_order"),"\n");
    msg("~CTITIntermud-3 Mudlist~CDEF");
    write(buf);
    msg("~CDEF");
    return 1;
}

int sort_order(string a, string b) {
    if( strlen(a) < 5 || strlen(b) < 5 ) return 0;
    return a[5] > b[5];
}
