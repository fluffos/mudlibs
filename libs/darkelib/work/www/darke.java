<HTML>
<script language="JavaScript">


<!-- Beginning of JavaScript Applet-------------

function scrollit_r21(seed)
{
        var m1 = "Welcome To DarkeMUD!";
        var m2 = "If you are new check out the newbie page!";
        var m3 = "If you want to add a link to your html mail Drizzt.";

        var msg=m1+m2+m3;
        var out = " ";
        var c = 1;

        if (seed > 100) {
                seed--;
                var cmd="scrollit_r21(" + seed + ")";
                timerTwo=window.setTimeout (cmd,100);
        }
        else if (seed <= 100 && seed > 0) {
                for (c=0 ; c < seed ; c++) {
                        out+=" ";
                }
                out+=msg;
                seed--;
                var cmd="scrollit_r21(" + seed +")";
                    window.status=out;
                timerTwo=window.setTimeout (cmd,100);
        }
        else if (seed <= 0) {
                if (-seed < msg.length) {
                        out+=msg.substring(-seed,msg.length);
                        seed--;
                        var cmd="scrollit_r21(" + seed + ")";
                        window.status=out;
                        timerTwo=window.setTimeout (cmd,100);
                }
                else {
                        window.status=" ";
                        timerTwo=window.setTimeout("scrollit_r21
(100)",75);
                }
        }
}
//--End of JavaScript code------------->

<TITLE>Darkemud Home Page</TITLE>
<BODY onLoad="timerONE=window.setTimeout
onLoad="timerONE=window.setTimeout"
BACKGROUND = "darke/images/grey.jpg" LINK = "#7000E0" TEXT = "#000000" 
VLINK = "#900000" ALINK = "#C000FF" >
<center>
<IMG SRC = "darke/images/darke1.jpg" alt = "Welcome to DarkeMUD!">
<H3>Welcome to DarkeMUD</H3>
<H5>Driver: MudOS v22b11 Mudlib: DarkeLIB 0.1</H5>
<H4>Admins: Diewarzau & Drizzt</H4>
</CENTER>
<HR>
<CENTER>
<H3><FONT COLOR = "#900000">DarkeMUD is OPEN AGAIN!!!</FONT></H3>
</CENTER>
<HR>
<BR>
<CENTER>
<TABLE BORDER>
<TR><TD><A HREF = "darke/news.html">DarkeMUD News</A></TD></TR>
<TR><TD><A HREF = "darke/changes.html">New Changes to DarkeMUD</A></TD></TR>
<TR><TD><A HREF = "wholist.html">Who is in DarkeMUD Now?</A></TD></TR>
</TABLE>
</CENTER>
<BR><HR>
     <B>DarkeMUD</B>, located at <A HREF = "telnet://199.1.96.66:5559/">darke.shadowlands.com port 5559</A>, is a 
fantasy / medieval game with many entertaining complexities.  It 
is centered around and chiefly governed by the <B>players</B>, 
rather than the administrators.  This opens the door to many 
interesting player/player interactions as well as a healthy dose 
of violence.<P>


     Note that DarkeMUD is intended for <B>advanced players</B>.  
If you have limited or no mudding experience, you can expect to 
die relatively often.  DarkeMUD is combat-oriented, and very 
difficult.  Because of the difficulty level, the penalties of 
death are not very severe.<P>
<HR>
<H4>Some features of DarkeMUD include:</H4>
<UL>
<LI>Extremely detailed <A HREF = "darke/combat.html">combat system.</A>
<LI>Intricate <A HREF = "darke/spellsys.html">spell system.</A>
<LI>Over 29 <A HREF="darke/newbie.html#Races">races.</A>
<LI>Huge selection of character <A HREF="darke/newbie.html#Guilds">classes.</A>
<LI>1600 room world controlled by a dynamic virtual object 
server.
<LI>INFINITE mortal levels.
<LI>A kewl <A HREF="darke/war.html">War System</A>
<LI><A HREF="darke/clans.html">Clan and Cross-Training System</A>
<LI>Player-governed <A HREF="darke/newbie.html#The LAW">law</A> and economy.
<A HREF="http://www.freebsd.org/handbook/handbook.html">
<IMG SRC="darke/images/powerlogo.gif" ALIGN=RIGHT BORDER=0>
</A>
<LI>DarkeMUD is run on a dedicated Cyrix 686/166 PC with 64 megs ram and a 1 gig HD.
</UL>

For more information, see the <A HREF = "darke/newbie.html"><B>DarkeMUD FAQ.</B></A><P>
<HR>
<CENTER><H3>More DarkeMUD Pages</H3></CENTER>
<UL>
<LI><A HREF = "darke/maps.html">Maps of DarkeMUD</A>
<LI><A HREF = "darke/wiz.html">DarkeMUD Wizard Page</A>
<LI><A HREF = "darke/history.html">History of DarkeMUD</A>
<LI><A HREF = "darke/newbie.html">Glorfindel's Newbie Handbook</A>
<LI><A HREF = "darke/player.html">Webpages of DarkeMUD players</A>
<LI><A HREF = "http://www.mudconnect.com/mud-bin/discuss/discuss.cgi">Mudconnector Hyperthread Discussions</A>
<LI><A HREF = "http://home1.gte.net/gakhan/start.html">Dalimar's DarkeMUD page</A>
</UL>

<HR>
<H2>Heard Enough?</H2>
<H3><A HREF = "telnet://199.1.96.66:5559/">Play DarkeMUD!</A></H3>
<H4><I>darke.shadowlands.com 5559</I></H4>
<H4><I>199.1.96.66 5559</I></H4>
<HR>
<CENTER>
<A HREF="http://home.netscape.com/comprod/mirror/client_download.html">
<IMG SRC="darke/images/netscape_now.gif" BORDER=0><BR>
<FONT SIZE = -1>This page best viewed with Netscape 2.0 or higher.</FONT></A><BR><BR>
<B>You are vistor</B><BR>
<IMG SRC = "/cgi-bin/Count.cgi?dd=C&ft=0&df=darke.dat">
<BR><font size=-1>Counter started 5/30/96
</CENTER>
<H4><A HREF = "mailto:ccrain@marlin.utmb.edu">Send email to Diewarzau</A><P></H4>
<H4><A HREF = "mailto:drizzt@shadowlands.com">Send email to Drizzt</A><P></H4>

<BR>
<A HREF = "http://www.shadowlands.com/webedge"><IMG SRC = "darke/images/sm_logo2.jpg" BORDER=0 ALIGN="LEFT">
Designed by Web Edge, Inc.</A>
<BR><BR><BR><BR>
<font size=-3><I>Last Updated 6/24/96 ++Drizzt@shadowlands.com</I>
</BODY>
</HTML>
