#include <std.h>

inherit ROOM;

string *auth_pass = ({ "nightshade" });

void create()
{
 object board;

 ::create();
 set_name("vip hall");
 set_short("The V.I.P. Hall");
 set_long("This is the VIP hall where special people, like you, come to "
          "talk about their new accomplishments for beta 2. If you need "
          "any help at all with your area or your contribution to beta 2 "
          "contact any immortal that is on at the moment, or leave a message "
          "on the board. You may get a new vip pass by typing \"renew vip pass\"");
 set_property( "no attack", 1);
     board = new("std/bboard");
    board->set_name("board");
    board->set_id( ({ "board", "vip board" }) );
    board->set_max_posts(80);
    board->set_location("d/standard/viphall");
    board->set("short", "VIP board");
    board->set("long", "This board is for the VIPS of beta 2.\n");
    board->set_board_id("vip");

}

void init()
{
 ::init();
 add_action("f_renew", "renew");
}

int f_renew(string str)
{
 if (member_array(this_player()->query_name(), auth_pass)==-1)
   {write("You are not authorized to get a pass.");return 1;}
 if (str!="vip pass") { write("renew what?");return 1;}
 if (present("pass", this_player()))
   { write("You already have one."); return 1; }
 new("/wizards/seeker/vip")->move(this_player());
 this_player()->setenv("start", "/d/standard/viphall");
 write("You renew your vip pass.");
 return 1;
}
