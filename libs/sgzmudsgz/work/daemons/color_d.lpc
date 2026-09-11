//color_d.c by fire on September 14, 1999
#include <ansi.h>
inherit M_ANSI;
string spc="                                                                  ";
// dir = 0 left
// dir = 1 right
// dir = 2 center
string color_string(string inp,int len,int dir) {
	string ret;
	int m_len,l_len,r_len;
	ret=inp;
	m_len=colour_strlen(ret);
	if(m_len>=len) return ret;
	switch(dir) {
		case 0:
			ret+=spc[0..(len-m_len-1)];
			break;
		case 1:
			ret=spc[0..(len-m_len-1)]+ret;
			break;
		default:
			l_len=len-m_len;
			l_len/=2;
			r_len=len-m_len-l_len;
			if(l_len)
			   ret=spc[0..(l_len-1)]+ret;
			if(r_len)
			   ret+=spc[0..(r_len-1)];
	}
	return ret;
}

string center_string(string inp,int len) {
	return color_string(inp,len,2);
}
string left_string(string inp,int len) {
	return color_string(inp,len,0);
}
string right_string(string inp,int len) {
	return color_string(inp,len,1);
}