/*
 * String adjust routines - implemented Moonchild 301092 (not original code)
 */

#ifndef _str_adjust_
#define _str_adjust_

string ladjust (string str,int n) { return extract (str + "                                                                                ",0,n-1); }
string radjust (string str,int n) { 
    int len; string longstring;
    longstring="                                                                                "+str;
    len=strlen(longstring);
    return extract (longstring,len-n,len);
}

#endif
