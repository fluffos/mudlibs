#include <config.h>
#include <news.h>
#define MUDLOGO "http://aorta.tat.physik.uni-tuebingen.de/~gamesmgr/gfx/nflogosm.gif"

string show(mixed *strs)
{
  string retstr;
  mixed *names;
  int i;

  names = NEWSSERVER->GetNames();
  if (sizeof(strs) == 2) {
    /* return group names */

    retstr = "<TITLE>Nightfall Newsgroups</TITLE>";
    retstr += "<H1><IMG SRC=\""+MUDLOGO+"\" ALT=\"Nightfall\">Newsgroups</H1>";
    retstr += "<ul>";
    for (i = 0; i < sizeof(names); i++) {
      retstr += "<LI><A HREF=\"news/"+names[i]+"\"><b>"+names[i]+"</b></a>";
    }
    retstr += "</ul>";
    return retstr;
  }
  if (sizeof(strs) == 3) {
    /* return one group */
    string name;
    mixed gi;

    name = strs[2];
    gi = NEWSSERVER->GetGroup(name);
    retstr = "<TITLE>Nightfall Newsgroup: "+name+"</TITLE>";
    retstr += "<H1><IMG SRC=\""+MUDLOGO+"\" ALT=\"Nightfall\">Newsgroup: "+name+"</H1>";
    if (gi == NEWS_ILLGROUP) {
      retstr += "<H2>Illegal Group "+name+"</H2>";
    }
    else {
      mixed h;

      retstr += "Name: "+gi[G_NAME]+" Maxmsg: "+gi[G_MAXMSG]+" Logmode: "+gi[G_LOGMODE]+" Num: "+gi[G_ACTMSG]+" LastID: "+gi[G_LASTID]+"<p>";
      h = NEWSSERVER->GetHeaders(name,0);
      if (h == NEWS_NORIGHT) {
	retstr += "<H2>No rights to access group</H2>";
      }
      else if (intp(h)) {
	retstr += "<H2>Error code "+h+"</H2>";
      }
      else {
	retstr += "<H2>Message List:</H2><OL>";
	for (i = 0; i < sizeof(h); i++) {
	  string writer;
	  if (stringp(h[i][M_WRITER]))
	    writer = h[i][M_WRITER];
	  else
	    writer = "***";
	  if (intp(h[i][M_LEVEL]))
	    writer += "("+h[i][M_LEVEL]+")";
	  else if (pointerp(h[i][M_LEVEL]))
	    writer += "("+h[i][M_LEVEL][0]+"/"+h[i][M_LEVEL][1]+")";
	  retstr += "<LI><SAMP>"+(writer+".................")[0..17]+"</SAMP> ";
	  if (stringp(h[i][M_TITLE]) && h[i][M_TITLE] != "" && h[i][M_TITLE] != "<untitled>")
	    retstr += "<A HREF=\""+name+"/"+i+"\">"+h[i][M_TITLE]+"</A>";
	  else
	    retstr += "<A HREF=\""+name+"/"+i+"\">(untitled)</A>";
	}
	retstr += "</OL>";
      }
    }
    return retstr;
  }
  if (sizeof(strs) == 4) {
    /* return exactly ONE message */
    string gname;
    string subj;
    int num;
    mixed msg;

    gname = strs[2];
    num = to_int(strs[3]) + 1;
    msg = NEWSSERVER->GetNote(gname,num);

    if (msg == NEWS_ILLGROUP) {
      retstr = "<TITLE>Nightfall News</TITLE>";
      retstr += "<H1><IMG SRC=\""+MUDLOGO+"\" ALT=\"Nightfall\">News</H1>";
      retstr += "<H2>Illegal Group "+gname+"</H2>";
    }
    else if (msg == NEWS_NORIGHT) {
      retstr = "<TITLE>Nightfall News</TITLE>";
      retstr += "<H1><IMG SRC=\""+MUDLOGO+"\" ALT=\"Nightfall\">News</H1>";
      retstr += "<H2>No right to read group "+gname+"</H2>";
    }
    else {
      string mwriter;
      if (stringp(msg[M_WRITER]))
	mwriter = msg[M_WRITER];
      else
	mwriter = "***";
      if (intp(msg[M_LEVEL]))
	mwriter += "("+msg[M_LEVEL]+")";
      else if (pointerp(msg[M_LEVEL]))
	mwriter += "("+msg[M_LEVEL][0]+"/"+msg[M_LEVEL][1]+")";
      if (stringp(msg[M_TITLE]) && msg[M_TITLE] != "" && msg[M_TITLE] != "<untitled>")
	subj = msg[M_TITLE];
      else
	subj = "(untitled)";
      retstr = "<TITLE>"+mwriter+": "+subj+"</TITLE>";
      retstr += "<H2>"+mwriter+": "+subj+"</H2>";
      retstr += "--- Date: "+ctime(msg[M_TIME])+" --- MsgID: "+msg[M_ID]+" ---<p>";
      retstr += "<PRE>"+msg[M_TEXT]+"</PRE>";
    }
    return retstr+"\n";
  }
  return "<H1>"+implode(strs,"#")+"</H1>\n";
}
