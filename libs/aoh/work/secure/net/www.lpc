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

#include <daemons.h>

#define NOPROMPT set_prompt("")
#define NAMEANDPORT ("aoh.zitz.dk:" + query_mud_port())
#define ADDRESS "<HR><ADDRESS>rz@zitz.dk (AoH Games Manager)</ADDRESS>"

#define HEAD1  "<HTML><HEAD><TITLE>\n"
#define HEAD2  "</TITLE></HEAD>\n"
#define BGC    "BGCOLOR=\"#000000\""
#define LNK    "LINK=\"#FFFFFF\""
#define VLNK   "VLINK=\"#82a0ff\""
#define TXT    "TEXT=\"#FFFFFF\""
#define BODY1  "<BODY "+BGC+ " " +LNK+ " " +VLNK+" "+TXT+">\n"
#define BAN1   "<IMG SRC=\"http:/" "/aoh.zitz.dk:2350/pics/osb.gif\""
#define BAN2   " ALT=\"AgeOfHeroes\">\n"
#define BODY2  "</BODY></HTML>\n"

#define PLAYER_DUMMY "/obj/player_dummy"
int IsServiceDaemon() { return 1; }
string QueryPresay() { return "Age of Heroes"; }
string QueryName() { return "WWW"; }
string QueryTitle() { return "Services Daemon (deaf)"; }
string QueryShort() { return (QueryPresay()+" "+QueryName()+" "+QueryTitle()); }
string QueryRealName() { return "gopher"; }
int QueryPlayer() { return 1; }
int IsServiceDemon() { return 1; }
int query_prevent_shadow() { return 1; }
void catfile(string str);
int who_list();
int finger_info(string str);
void domain_info(string str);
void destruct_me();

string getstring;
string *addstrings;
string html;   // body text
string title = "AgeOfHeroes";  // title of our page
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

  ht2 = HEAD1 + title + HEAD2 + BODY1 +"<CENTER>"+ BAN1+ BAN2 +"</CENTER><HR>"
        + ht + BODY2;

  if (extra)
  {
    write("HTTP/1.0 200 OK\n"+
    "Date: "+gmtime(time())+"\n"+
    "Server: AOH/1.01\n"+
    "MIME-version: 1.0\n"+
    "Content-type: text/html\n"+
    "Last-modified: "+gmtime(time())+"\n"+
    "Expires: "+gmtime(time()+10)+"\n"+
    "Content-length: "+sizeof(ht2)+"\n"+
    "\n");
  }
  efun::write(ht2);
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

int start_player(string str)
{
  string str1, str2;
  string *strs;
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
      case "/default.html":     /* fall through  */
      case "/index.html":
      case "/":
        str = "<!DOCTYPE html>"
              "<html>"
              "<body>"
              "<h1>My First Heading</h1>"
              "<p>My first paragraph.</p>"
              "</body>"
              "</html>";
#if 0
        str ="<HTML>"
        "<HEAD><META HTTP-EQUIV=\"Refresh\" Content=\"0;URL=http://aoh.zitz.dk:2350\"></HEAD>"
        "<BODY BGCOLOR=\"#000000\" TEXT=\"#FFFFFF\">"
        "You can find AOH at <A HREF=\"http://aoh.zitz.dk:2350\">aoh.zitz.dk</A>"
        "</BODY></HTML>";
#endif
        efun::write(
          "HTTP/1.0 200 OK\n"
          "Date: "+gmtime(time())+"\n"
          "Server: AOH/1.01\n"
          "MIME-version: 1.0\n"
          "Content-type: text/html\n"
          "Last-modified: "+gmtime(time())+"\n"
          "Content-length: " + sizeof(str)+ "\r\n\r\n" + str
          );
        call_out(#'destruct_me /*'*/, 1);
        return 1;

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
        title = "Races in AOH";
        html += ("<H1>Races in AOH</H1>\n");
        html += "We are currently working on many new flavorful " +
                "races for your playing enjoyment. Please check " +
                "back soon to see what we came up with.\n<P>";

	/*  While we work...
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
	*/

        html += (ADDRESS);
        send_html(html);
        call_out("destruct_me", 5);
        return 1;
      case "/domains":
        title = "The Domains of AoH";
        html += ("<H1>The Domains of AOH</H1>\n");
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
          +"/www"+({string})MASTER->full_path(implode(strs[3..],"/"),0);
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
        str = "/d/"+strs[2]+"/www"+({string})MASTER->full_path(implode(strs[3..],"/"),0);
      }
      break;
    case "news":
      str = "That feature is currently unavailable.";
      //catch(str = "/secure/net/wwwnews"->show(strs));
      html += (str);
      send_html(html);
      call_out("destruct_me", 5);
      return 1;
      /* -- we don't have any guide for now --
    case "guide":
      catch(str="/p/www/guide/wwwguide"->show(strs));
      html += (str);
      send_html(html);
      call_out("destruct_me", 5);
      return 1;
      */
    case "doc":
      catch(str=({string})"/p/www/doc/WWW/wwwdoc"->show(strs));
      html += (str);
      send_html(html);
      call_out("destruct_me", 5);
      return 1;
    default:
      str = "/www"+({string})MASTER->full_path(str,0);
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

string where(object ob)
{
  return ({string})COUNTRY_D->GetCountry(lower_case(query_ip_name(ob)), 0);
}

/*--------------------------------------------------------------
 * This function provides a list of players.
 */

int who_list()
{
    int i, nu;
    object *list;
    string presay, name, title;

    list = users() - ({ this_object() });

    title =
     "Players currently enjoying AoH\n";
    html +=
     "<H2>The following players are currently in AOH</H2>\n<ul>";
    nu = 0;

    for (i = 0; i < sizeof(list); i++)
    {
        string sh;
        sh = ({string})list[i]->QueryShort();
        if (sh && !({int})list[i]->QueryInvis()) {
          presay = ({string})list[i]->QueryPresay();
          if (!presay)
            presay = "";
          name = ({string})list[i]->QueryName();
          if (!name)
            continue;
          title = ({string})list[i]->Query("MosaicTitle");
          if (!title) {
            title = ({string})list[i]->QueryTitle();
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

string dtime(int time);


/* ----------------------------------------------------------------
 *  This function generates finger info for a specific player.
 * ----------------------------------------------------------------
 */


int finger_info(string str)
{
  string filename, gender, age;
  mixed  *userinfo;
  string presay, name, title, race, guild, pronoun, cappronoun;
  mapping props; // from the player_dummy

  if (!str || str == "")
  {
    html += ("<b>Nonexistant player!</b>\n");
    return 0;
  }

  html += ("<I>Information about "+capitalize(str)+" ~</I>\n");

  /* switch to lower case */
  str = lower_case(str);

  /* does this player exist? */
  userinfo = ({mixed *})MASTER->find_userinfo(str);
  filename="/save/"+str[0..0]+"/"+str+".o";
  if( !userinfo && (file_size(filename) < 0) )
  {
    html += ("<b>This player does not exist in Age of Heroes.</b>\n");
    return 0;
  }

  /* --  Get the basic info from the player dummy --  */

  props = ({mapping})(load_object(PLAYER_DUMMY)->QueryProperties( str ));

  pronoun = props["Pronoun"];
  cappronoun = capitalize(pronoun);

  race = props["Race"];
  title = props["Title"];
  presay = props["Presay"];
  name = capitalize(str);
  guild = props["Guild"];
  gender = ({"unsure","male","female","neuter"})[props["Gender"]];
  age = dtime(props["Age"] * HBINT );

  /* --  Set up our strings for the page --  */

  if(!race || race == "")
    race =  cappronoun + " has not yet selected a race.";
  else
    race = cappronoun + " belongs to the race of " +
           capitalize(({string})RACEMASTER->RacePlural(race)) + ".";

  if(!guild || guild == "")
      guild = cappronoun + " has not yet selected a guild.";
  else
      guild = cappronoun + " is a member of the guild of " +guild+ ".";

  html += ("<H2>"+presay+name+" "+title+"</H2><p>\n");
  html += ("<UL>");

  if(props["Ghost"] == 1)
    html += ("<LI>This player is currently a ghost.\n");

  html += "<LI>" + race + "\n";
  html += "<LI>" + cappronoun + " is of the " + gender + " gender.\n";
  html += "<LI>" + cappronoun + " is " + age + " old.\n";
  html += "<LI>" + guild + "\n";

  if(!find_player(str))    // are they logged in?
    html += "<LI>" + cappronoun + " was last online on " +
         ctime(props["LastLogin"]) + " CET.\n";
  else
    html += "<LI>" + cappronoun + " has been online since " +
         ctime(props["LastLogin"]) + " CET.\n";

  html += "</UL><HR>\n";

    //if(!(wizlevel = query_user_level(this_player())))
    //  wizlevel=-player->QueryLevel();


/* -- commented out for now -- Tune  28-Oct-97
      what a bleedin' mess!

 html += ("<LI>Race: <A HREF=\"http://"+NAMEANDPORT+"/races#"+lower_case(race)+"\"><b>"+race+"</b></A> ");
  html += (wizlevel>0?(wizlevel>=20?"   Wizard":"   Learner"):"   Playerlevel: "+(-wizlevel))+
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
  */

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
  if(time >= 86400)
  {
    ret += (time/86400) + "d ";
    time%=86400;
  }
  if(time < 36000) ret += "0";
  ret += time/3600 + ":";
  time %= 3600;
  if(time < 600) ret += "0";
  ret += time/60 + ":";
  time %= 60;
  if(time < 10) ret += "0";
  ret += time + "";
  return ret;
}

#include <secure/domaininfo.h>

/*
 * This function shows a http page for a specific domain.
 */
void domain_info(string str)
{
  string rc;
  mixed *ddata;
  int state, size, i, what;
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

  state = ({int})DOMAININFO->QueryState();
  rc = 0;
  if (state == DI_INITING)
    rc = "<H2>The memberlist is quite blurry and achanging.</H2>\n";
  if (state == DI_INITED)
    rc = "<H2>Members of "+capitalize(str)+" are:</H2>\n";
  if (!rc) {
    html += ("<H2>The memberlist didn't materialize yet.</H2>\n");
    return;
  }

  ddata = ({mixed *})DOMAININFO->QueryDomain(str);
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
void catfile(string str)
{
  int siz1,pos1;
  siz1 = file_size(str);
  if (siz1 > 0) {
    for (pos1 = 0; pos1 < siz1; pos1 += 200)
    {
      html += (read_file(str,pos1,200));
    }
  }
}
