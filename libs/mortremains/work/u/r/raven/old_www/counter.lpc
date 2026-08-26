/*
 *    /www/counter.c
 *
 *    An example of embedding HTML and maintaining a page access counter.
 */

#include <mudlib.h>
#include <config.h>
#include <daemons.h>
#include <commands.h>
#include <net/http.h>

inherit SERVER;

string startdate;
int counter;
string *numbers = ({
        "<IMG SRC=\"images/0.gif\" ALT=\"\">",
        "<IMG SRC=\"images/1.gif\" ALT=\"\">",
        "<IMG SRC=\"images/2.gif\" ALT=\"\">",
        "<IMG SRC=\"images/3.gif\" ALT=\"\">",
        "<IMG SRC=\"images/4.gif\" ALT=\"\">",
        "<IMG SRC=\"images/5.gif\" ALT=\"\">",
        "<IMG SRC=\"images/6.gif\" ALT=\"\">",
        "<IMG SRC=\"images/7.gif\" ALT=\"\">",
        "<IMG SRC=\"images/8.gif\" ALT=\"\">",
        "<IMG SRC=\"images/9.gif\" ALT=\"\">"
    });

void create() {
    /*
     * you might want to use restore_object()/save_object()
     */

    startdate = ctime(time());
    startdate = startdate[4..9] + "," + startdate[<5..<1];
    counter = 0;
}

string makecounter(int counter) {
    int n = counter;
    string res;

    res = "";
    while (n) {
        res = numbers[n % 10] + res;
        n /= 10;
    }
    return replace_string(res, "\"\"", sprintf("\"%d\"", counter), 1);
}

string gateway() {
    counter++;

    return sprintf(@ENDTEXT
<HTML>
<HEAD>
<TITLE>TMI MUD COUNTER</TITLE>
</HEAD>
<BODY>
<H1>A Counter</H1>

This web page is dynamically generated using an HTTP daemon written
entirely in LPC.  Click <A HREF="counter_src.html">here</A> to see the source.

<HR>

This page has been accessed %s %s since it was loaded %s.

</BODY>
</HTML>
ENDTEXT
, makecounter(counter), counter == 1 ? "time" : "times", startdate);
}
