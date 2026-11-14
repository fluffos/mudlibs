/**
 **  secure/net/www.c
 **
 **  WWW World Wide Web server
 **
 **  (C) Copyright 1993 Nightfall, OneStepBeyond
 **
 **  creation: Deepthought@Nightfall, 26-Jan-93
 **  updated   Tune@OSB, 06-jun-97
 **
 **  This object may be used with or without modifications as long
 **  as credit to its origin is given.
 ** 
 **/

#define NOPROMPT set_prompt("")
#define NAMEANDPORT ("osb.lpmud.com:"+query_mud_port())
#define ADDRESS "<HR><ADDRESS>osb@lpmud.com (the OSB Games Manager)"

#define HEAD1  "<HTML><HEAD><TITLE>\n"
#define HEAD2  "</TITLE></HEAD>\n"
#define BGC    "BGCOLOR=\"#000000\""
#define LNK    "LINK=\"#FFFFFF\""
#define VLNK   "VLINK=\"#82a0ff\""
#define TXT    "TEXT=\"#FFFFFF\""
#define BODY1  "<BODY "+BGC+ " " +LNK+ " " +VLNK+" "+TXT+">\n"
#define BAN1   "<IMG SRC=\"http:/" "/www.actwin.com/guests/dana/pics/osb.gif\""
#define BAN2   " ALT=\"OneStepBeyond\">\n" 
#define BODY2  "</BODY></HTML>\n"

QueryPresay() { return "One Step Beyond"; }
QueryName() { return "WWW"; }
QueryTitle() { return "Services Daemon (deaf)"; }
QueryShort() { return (QueryPresay()+" "+QueryName()+" "+QueryTitle()); }
QueryRealName() { return "gopher"; }
QueryPlayer() { return 1; }
IsServiceDemon() { return 1; }

query_prevent_shadow() { return 1; }

string getstring;
string *addstrings;
string html;   // body text
string title = "OneStepBeyond";  // title of our page
int extra;

#define TZSECS (-60*60)
string gmtime(int tim)
{
  string ctim;
  string gmtim;

  ctim = ctime(tim+TZSECS);
  switch (ctim[0..2]) {
    case "Mon":
      gmtim = "Monday";
      break;
    case "Tue":
      gmtim = "Tuesday";
      break;
    case "Wed":
      gmtim = "Wednesday";
      break;
    case "Thu":
      gmtim = "Thursday";
      break;
    case "Fri":
      gmtim = "Friday";
      break;
    case "Sat":
      gmtim = "Saturday";
      break;
    case "Sun":
      gmtim = "Sunday";
      break;
  }
  return gmtim + ", "+ctim[8..9]+"-"+ctim[4..6]+"-"+ctim[22..23]+" "+
    ctim[11..18]+" GMT";
}

void send_html(string ht)
{
  string ht2;

  ht2 = HEAD1 + title + HEAD2 + BODY1 +"<CENTER>"+ BAN1 BAN2 +"</CENTER><HR>"
        + ht + BODY2;

  if (extra) 
  {
    write("HTTP/1.0 200 OK\n"+
    "Date: "+gmtime(time())+"\n"+
    "Server: OSB/1.01\n"+
    "MIME-version: 1.0\n"+
    "Content-type: text/html\n"+
    "Last-modified: "+gmtime(time())+"\n"+
    "Expires: "+gmtime(time()+10)+"\n"+
    "Content-length: "+strlen(ht2)+"\n"+
    "\n");
  }
  write(ht2);
}

void destruct_me()
{
  destruct(this_object());
}

int get_input(string str)
{
  log_file("www.ext","-->"+str+"<---\n");
  return 1;
}

/*-------------------------------------------------------------------
 * This is the function that gets called by /secure/login after name and
 * password is verified and this object is loaded.
 */

start_player(str) 
{
  object p;
  string file;
  string str1, str2;
  string *strs;
  int *sizes;
  int i;

  NOPROMPT;
  add_action("get_input", "", 1);

  extra = 0;
  if (sscanf(str, "%s %s", str1, str2) == 2) {
    str = str1;
    extra = 1;
  }
  html = "";

  switch (str) 
  {
      case "/":
        str = "/index.html";
        break;
      case "/who":
        who_list();
        html += ADDRESS;
        send_html(html);
        call_out("destruct_me", 5);
        return 1;
	/* Commented out for now [tune] 06-jun-97
      case "/tree":
        list_tree();
        html+= ADDRESS;
        send_html(html);
        call_out("destruct_me", 5);
        return 1;
	*/
      case "/races":
        title = "Races in OSB";
        html += ("<H1>Races in OSB</H1>\n");
        html += ("<H2>The following races exist in OSB</H2><p>\n");
        strs = (string *) RACEMASTER->AllRaceNames() - 
          ({"visitor","vampire","slave"});
        html += ("<DL>");
        for (i = 0; i < sizeof(strs); i++) 
        {
          html += ("<DT><A NAME=\""+strs[i]+"\"><b>"
            +capitalize(strs[i])+"</b></A>");
          html += ("<DD>"+RACEMASTER->RaceDescr(strs[i])+"<p>\n");
        }
        html +=  ("</DL>\n");
        html += (ADDRESS);
        send_html(html);
        call_out("destruct_me", 5);
        return 1;
      case "/domains":
        title = "The Domains of OSB";
        html += ("<H1>The Domains of OSB</H1>\n");
        html += ("<UL>");
        strs = get_dir("/d/???*");
        for (i = 0; i < sizeof(strs); i++) {
          if (file_size("/d/"+strs[i]) == -2) 
          {
            html += ("<LI><A HREF=\"d/"+strs[i]+"/\"><b>" 
                +capitalize(strs[i])+"</b></A>\n");
          }
        }
        html += ("</UL>");
        html += (ADDRESS);
        send_html(html);
        call_out("destruct_me", 5);
        return 1;
      default:
        sscanf(str,"%s=%s",str1,str2);
        if (str1 && str1 == "/plook?charname") {
          if (str2) {
            str = "/w/"+str2+"/";
          }
          else {
            call_out("destruct_me", 5);
            return 1;
          }
        }
        break;
  }
  strs = explode(str,"/");
  switch (strs[1]) 
  {
    case "w":
      if (sizeof(strs) < 4) 
      {
        call_out("destruct_me", 5);
        return 1;
      }
      if (strs[3] == "") 
      {
        finger_info(lower_case(strs[2]));
        str = "/players/"+lower_case(strs[2])+"/www/index.html";
      }
      else 
      {
        str = "/players/"+lower_case(strs[2])
          +"/www"+MASTER->full_path(implode(strs[3..],"/"),0);
      }
      break;
    case "d":
      if (sizeof(strs) < 4) {
        call_out("destruct_me", 5);
        return 1;
      }
      if (strs[3] == "") {
        domain_info(strs[2]);
        str = "/d/"+strs[2]+"/www/index.html";
      }
      else {
        str = "/d/"+strs[2]+"/www"+MASTER->full_path(implode(strs[3..],"/"),0);
      }
      break;
    case "news":
      str = "currently unavailable";
      //catch(str = "/secure/net/wwwnews"->show(strs));
      html += (str);
      send_html(html);
      call_out("destruct_me", 5);
      return 1;
    case "guide":
      catch(str="/p/www/guide/wwwguide"->show(strs));
      html += (str);
      send_html(html);
      call_out("destruct_me", 5);
      return 1;
    case "doc":
      catch(str="/p/www/doc/WWW/wwwdoc"->show(strs));
      html += (str);
      send_html(html);
      call_out("destruct_me", 5);
      return 1;
    default:
      str = "/www"+MASTER->full_path(str,0);
      break;
  }

  catfile(str);
  send_html(html);
  call_out("destruct_me", 5);
  return 1;
}

/*-------------------------------------------------------------
 * where() is a function which returns the physical country from
 * which the player is logged in. The simul-efun country() is
 * used to return a best guess of the country name from the
 * ip name (usually the top level domain is quite descriptive).
 */

where(ob) 
{ 
  return country(lower_case(query_ip_name(ob))); 
}

/*--------------------------------------------------------------
 * This function provides a list of players.
 */

who_list() 
{
    string a, b;
    int i, nu;
    string *lines;
    object *list;
    string presay, name, title;

    list = users() - ({ this_object() });
   
    title = 
     "Players currently enjoying OSB\n";
    html +=
     "<H2>The following players are currently in OSB</H2>\n<ul>";
    nu = 0;

    for (i = 0; i < sizeof(list); i++) 
    {
        string sh;
        sh = list[i]->QueryShort();
        if (sh && !list[i]->QueryInvis()) {
          presay = list[i]->QueryPresay();
          if (!presay)
            presay = "";
          name = list[i]->QueryName();
          if (!name)
            continue;
          title = list[i]->Query("MosaicTitle");
          if (!title) {
            title = list[i]->QueryTitle();
            if (!title)
              title = "";
          }
          html += ("<LI>"+presay+" <A HREF=\"w/"+lower_case(name)
           +"/\"><b>"+name+"</b></A> "+title+" [" +where(list[i])+"]\n");
          nu++;
        }
    }
    if (nu) 
        html += ("</UL><b>There are "+nu+" users connected.</b><p>\n");
    else
        html += ("<b>There are no users connected.</b><p>\n");
    return 1;
}

/*-----------------------------------------------------------------
 * This function generates a tree of wizard sponsorship by querying
 * a 'genealogy tree' object.
 */

/* Commented out for now [tune] 06-jun-97
list_tree() {
  string *tree;
  int i;
  html += ("<TITLE>Nightfall WWW Services</TITLE>");
  html += ("<H1>The Nightfall Genealogy Tree</H1><pre>");
  tree = explode("/players/suamor/mytree"->PrintTree("bigtree",({""}) ),"\n");
  for (i=0;i<sizeof(tree);i++) {
    html += (tree[i]+"<br>");
  }
  html += ("</pre>");
}
*/
  
#include <config.h>
#include <living.h>
#include <properties.h>
#include <secure/wizlevels.h>

#define HBINT         2   /* interval between two heart_beats in seconds    */
#define MINIDLE      60   /* minimum idle time in seconds to be stated idle */
#define LORDSTR(g)  (g==MALE ? "Lord" : "Lady") /* We HAVE female Lords !!! */

string dtime(int time);


/*
 * This function generates finger info for a specific player.
 */
finger_info(str)
{
  string filename, *data;
  int    pos, char;
  object player;
  mixed  *userinfo;
  string ip, presay, name, title, race, guild, mailaddr;
  int    ipnum, idle, gender, age, ghost, wizlevel;

  if (!str || str == "") {
    html += ("<b>Nonexistant player!</b>\n");
    return;
  }
  title = "Information on " + capitalize(str);
  html += ("<H1>Information on "+capitalize(str)+":</H1>\n");

  /* switch to lower case */
  str=lower_case(str);
  
  /* does this player exist? */
  userinfo=MASTER->find_userinfo(str);
  filename="/save/"+str[0..0]+"/"+str+".o";
  if(!userinfo && file_size(filename)<0) {
    html += ("<b>This player does not exist in " MUDNAME ".</b>\n");
    return;
  }
  
  /* is it logged in? */
  player=find_player(str);
  if(player) {
    /* the player is logged in: query information directly */
    ipnum=query_ip_number(player);
    if(ipnum) {
      ip=query_ip_name(player);
      if((idle=query_idle(player))<MINIDLE)
        idle=0;
    } else {
      if(file_size(filename)<0) {
        html += ("<b>Sorry, can't find data for " + capitalize(str) + ".</b>\n");
        return 0;
      }
      data=explode(read_file(filename),"\n");
      ip=(regexp(data,"^called_from_ip")+({""}))[0][16..<2];
    }
    presay=player->QueryPresay();
    name=capitalize(player->QueryRealName());
    title=player->QueryTitle();
    race=player->QueryRace();
    guild=player->QueryGuild();
    mailaddr=player->QueryMailaddr();
    gender=player->QueryGender();
    age=HBINT*player->QueryAge();
    ghost=player->QueryGhost();
    if(!(wizlevel=query_user_level(player)))
      wizlevel=-player->QueryLevel();
  } else {
    /* the player is not logged in: query the information from the savefile */
    if(file_size(filename)<0) {
      notify_fail("<b>Sorry, can't find data for " + capitalize(str) + ".</b>\n");
      return 0;
    }
    data=explode(read_file(filename),"\n");
    idle=file_date(filename);
    ip=(regexp(data,"^called_from_ip")+({""}))[0][16..<2];
    presay=(regexp(data,"^presay")+({""}))[0][8..<2];
    name=capitalize(str);
    title=(regexp(data,"^title")+({""}))[0][7..<2];
    race=(regexp(data,"^race")+({""}))[0][6..<2];
    guild=(regexp(data,"^guild")+({""}))[0][7..<2];
    mailaddr=(regexp(data,"^mailaddr")+({""}))[0][10..<2];
    gender=to_int((regexp(data,"^gender")+({""}))[0][7..]);
    age=HBINT*to_int((regexp(data,"^age")+({""}))[0][4..]);
    ghost=to_int((regexp(data,"^ghost")+({""}))[0][6..]);
    if(!(wizlevel=query_user_level(str)))
      wizlevel=-to_int((regexp(data,"^level")+({""}))[0][6..]);
  }
  
  /* format some strings */
  if(!race || race=="") race="none";
  if(!guild || guild=="") guild="none";
  if(gender<0 || gender>3) gender=3;
  if(!mailaddr || mailaddr=="") mailaddr="none";
  
  /* output routine for learners and wizards */
  html += ("<H2>"+presay+name+" "+title+"</H2><p>\n");
  html += ("<UL>");
//  if(player) {
//    if(ipnum) {
//      html += ("<LI>"+capitalize(str)+" is from "+country(ip)+".\n");
//      if(idle)
//      html += ("<LI>Idle time: "+dtime(idle)+"\n");
//      } else
//      html += ("<LI>"+capitalize(str)+" is netdead.\n");
//  } else {
//      html += ("<LI>"+capitalize(str)+" is not logged on.\n"+
//          "<LI>Last login was from "+country(ip)+".\n"+
//          "<LI>Last logout was on "+ctime(idle)+" ("+dtime(time()-idle)+")\n");
//  }
  if(ghost)
    html += ("<LI>This player is currently a ghost.\n");
  if (race == "none")
    html += ("<LI>Race: none ");
  else
    html += ("<LI>Race: <A HREF=\"http://"+NAMEANDPORT+"/races#"+lower_case(race)+"\"><b>"+race+"</b></A> ");
  html += ("Guild: "+guild+"   Gender: "+
          ({"neuter","male","female", "<illegal>"})[gender]+
          "<LI>Age: "+dtime(age)+
          (wizlevel>0?(wizlevel>=20?"   Wizard":"   Learner"):"   Playerlevel: "+(-wizlevel))+
//        "<LI>E-Mail address: "+mailaddr+
          "\n");
  data=userinfo[3];
  if(sizeof(data)) {
    html += ("<LI>Domains: ");
    for(pos=0; pos<sizeof(data); pos++) {
        if(pos)
          html += (", ");
        switch(data[pos][0]) {
        case '+': html += ("Vice ");
        case '*': html += (LORDSTR(gender)+" of <A HREF=\"http://"+NAMEANDPORT+"/d/"+data[pos][1..]+"/\"><b>"+capitalize(data[pos][1..])+"</b></A>");
          break;
        default: html += ("Member of <A HREF=\"http://"+NAMEANDPORT+"/d/"+data[pos]+"/\"><b>"+capitalize(data[pos])+"</b></A>");
        }
    }
    html += (".\n");
  }
  html += ("</UL>");
  filename="/players/"+str+"/.project";
  if(file_size(filename)>=0)
    html += ("<pre>Project:\n"+read_file(filename)+"</pre><p>\n");
  filename="/players/"+str+"/.plan";
/*
  if(file_size(filename)>=0)
    html += ("<pre>Plan:\n"+read_file(filename)+"</pre><p>\n");
  else
    html += ("No plan.<p>\n");
*/
  return 1;
}

/*
 * This function provides a time span as days, hours, minutes and seconds.
 */
string dtime(int time)
{
  string ret;
  
  ret="";
  if(time>=86400) {
    ret+=time/86400+"d ";
    time%=86400;
  }
  if(time<36000) ret+="0";
  ret+=time/3600+":";
  time%=3600;
  if(time<600) ret+="0";
  ret+=time/60+":";
  time%=60;
  if(time<10) ret+="0";
  ret+=time+"";
  return ret;
}

#include <secure/domaininfo.h>

/*
 * This function shows a http page for a specific domain.
 */
domain_info(str)
{
  string rc, wname;
  mixed *ddata;
  int state, size, i, iv, what;
  string domainsubdir;

  if (!str || str == "") {
    html += ("<b>Nonexistant Domain!</b>\n");
    return;
  }
  html += ("<TITLE>Information on Domain "+capitalize(str)+"</TITLE>");
  html += ("<H1>Information on Domain "+capitalize(str)+":</H1>\n");

  /* switch to lower case */
  str=lower_case(str);

  domainsubdir = "/d/"+str;
  if (file_size(domainsubdir) != -2) {
    html += ("<b>There is no such domain!</b><p>\n");
    return;
  }

  state = (int) DOMAININFO->QueryState();
  rc = 0;
  if (state == DI_INITING)
    rc = "<H2>The memberlist is quite blurry and achanging.</H2>\n";
  if (state == DI_INITED)
    rc = "<H2>Members of "+capitalize(str)+" are:</H2>\n";
  if (!rc) {
    html += ("<H2>The memberlist didn't materialize yet.</H2>\n");
    return;
  }

  ddata = (mixed *) DOMAININFO->QueryDomain(str);
  if (!ddata || !sizeof(ddata)) {
    html += ("<b>No information available</b><p>\n");
    return;
  }
  ddata = ddata[DD_WIZ];

  if (!(size = sizeof(ddata[DW_NAME]))) {
    rc += "There are no Wizards responsible for this Domain!<p>\n";
    html += (rc);
    return;
  }

  rc += "<UL>";
  for (what = D_LORD; what >= D_MEMBER; what--) {
    for (i = 0; i < size; i++) {
      if (ddata[DW_DSTAT][i] != what) continue;
      switch (what) {
      case D_LORD  : rc += "<LI>Domain Lord "; break;
      case D_VICE  : rc += "<LI>Vice Lord   "; break;
      case D_MEMBER: rc += "<LI>Wizard      "; break;
      default      : rc += "<LI>Unknown     ";
      }
      rc += "<A HREF=\"http://"+NAMEANDPORT+"/w/"+ddata[DW_NAME][i]+"/\"><b>"+capitalize (ddata[DW_NAME][i])+"</b></A>\n";
    }
  }
  rc += "</UL>\n";
  html += (rc);
  return;
}

/*
 * type a file as it is, without reaching the maximum of read_file().
 */
catfile(str)
{
  int siz1,pos1;
  siz1 = file_size(str);
  if (siz1 > 0) {
    for (pos1 = 0; pos1 < siz1; pos1 += 200)
    {
      html += (read_bytes(str,pos1,200));
    }
  }
}
