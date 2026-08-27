driver:
20.xx (was 0.9.20.xx) - newest patch level is 16.
more strict type checking (ie, old driver allows type int function
to return string.. etc) runs faster, better optimization, better
crash handling (annihilator mentioned that ES hardly crash because
of driver error), new efuns.
0.9.19.xx (where xx is the patch level) - stable (0.9.19.4 is the
most stable driver that go with TMI-2 1.1.1 mudlib), slower, might
have bug. (read the ChangLog on the newer driver, it'll list all
bugs..)
things needed to make ES lib runs under 20.xx driver: modify all
type definitions in mudlib code (a lot).
0.9.19 driver is stable with ES lib, since we dont have any serious
problem with it previously.
to modify the driver to pass 8bit (Chinese) code: edit comm.c, ed.c
and file.c to change the bitwise information (exact function name 
need check.. )
mudlib:
ES Lib 1.0 is based on TMI-2 1.0.1 mudlib, the newest TMI-2 mudlib
is 1.1.1, and the one that runs at TMI-2 now is a modified/updated
version of TMI 1.1.1 mudlib.

/adm/daemons/network/* is updated by Annihilator already (in order
to make Intermud works) and /adm/obj/mailer.c and related files too
(to make netmail working). channels.c is updated too.
driver/mudlib ftp site:
actlab.rtf.utexas.edu  /MUD/LPMud/MudOS (?)
      drivers, mudlib, documentations.. etc (all kinds of mud)
tmi.ccs.neu.edu 5555, TMI-2, lots of useful info there. bug fixes,
      discussions.. etc. autowiz on login.
      TMI-2 has a ftp server at port 5554, login as your char in TMI-2
ftp.ccs.neu.edu, general FTP site for MudOS and mudlib stuff.
