// written by Dwayne Fontenot (Jacques)
// last modified: 1992 October 19 (runs on the Basis mudlib)

// This object implements a telnet client (providing a subset of the telnet
// protocol) using STREAM mode of MudOS 0.9 LPC sockets.  See the init()
// function // to find out the commands this terminal understands.
// This object may be used from within a MudOS mud to connect to any
// networked server that understands the telnet protocol (including
// another LPmud).

#include <config.h>
#include <mudlib.h>
inherit OBJECT;

inherit "/std/socket/telnet";

#define DISCONNECTED "an internet terminal"
#define CONNECTED "an internet terminal (connected)"

void create()
{
set("short", "@@query_short");
set("long", "@@query_long");
set("id", ({"term", "terminal"}));
set("prevent_drop", "@@query_connected");
/*
  ob::create();
*/
  telnet::create();
  seteuid(geteuid(this_player()));
  init_tel_neg();
}

void init()
{
  add_action("connect",({"connect", "telnet"}));
  add_action("send","send");
  add_action("disconnect","disconnect");
  add_action("line","line");
  add_action("char","char");
}

string query_short() {
  if (query_connected()) return CONNECTED;
  return DISCONNECTED;
}

string query_long() {
  return (query_connected() ? CONNECTED : DISCONNECTED) + "\n";
}

int clean_up() {
    socket_shutdown();
    return 0;
}
