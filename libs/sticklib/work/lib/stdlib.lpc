/* standard library functions. never call these directly, include <std_lib> */
/* instead. see /include/std_lib.h for more details. */

/*
 * Function:    string secs2string (int secs)
 * Description: Convert seconds into a "X days X hours X minutes X seconds"
 *
 */

#define ADD_S(i) (i == 1 ? "" : "s")

string
_secs2string (int i)
{
    int t;
    string s;

    s = "";

    t = i % 60;
    i = i / 60;
    if (t) s = " " + t + " second" + ADD_S(t);
    t = i % 60;
    i = i / 60;
    if (t) s = " " + t + " minute" + ADD_S(t) + s;
    t = i % 24;
    i = i / 24;
    if (t) s = " " + t + " hour" + ADD_S(t) + s;
    if (i) s = " " + i + " day" + ADD_S(i) + s;
    if (s == "") return "0 seconds";
    return s[1..<1];
}

/* _secs2sstring:   int seconds to   "20h 30m 20s" etc */
string
_secs2sstring (int i)
{
    int t;
    string s;

    s = "";

    t = i % 60;
    i = i / 60;
    if (t) s = " " + t + "s";
    t = i % 60;
    i = i / 60;
    if (t) s = " " + t + "m" + s;
    t = i % 24;
    i = i / 24;
    if (t) s = " " + t + "h" + s;
    if (i) s = " " + i + "D" + s;
    if (s == "") return "0s";
    return s[1..<1];
}
