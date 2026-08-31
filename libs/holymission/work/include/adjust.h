/*
 * String adjust routines - implemented Moonchild 301092 (not original code)
 * 121297: Sauron" Rewritten.
 */

#ifndef __ADJUST_H__

#define __ADJUST_H__

#define ladjust(s, n)	sprintf("%-*s", n, s[0..(n-1)])
#define cadjust(s, n)	sprintf("%|*s", n, s[0..(n-1)])
#define radjust(s, n)	sprintf("%*s",  n, s[0..(n-1)])

#if 0
// Old code follows:
string ladjust(string str,int n) {
    return extract(str
+"                                                                           ",
0, n-1);
}

string radjust(string str,int n) { 
    string longstring;
    int len;

    longstring = "                                                           \
                    "+str;
    len = strlen(longstring);
    return extract(longstring, len-n, len);
}
#endif // 0

#endif // __ADJUST_H__
