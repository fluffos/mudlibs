#include <std.h>
#include <tirun.h>

inherit ROOM;

void create()
{
    ::create();
    set_short("The Elite Oil Shop");
    set_properties( ([ "no attack":1,
	"no bump":1,
	"light":2,
	"night light":2,
	"no magic":1 ]) );
    set_long("The shop is filled with an assortment of items for those "
      "powerful enough to use them.  Read the sign for instructions.");
    set_exits( ([ "north" : ROOMS "oil_shop" ]) );
}

void reset()
{
    ::reset();
  /*
    if (!present("jake")) 
	new("/wizards/daos/jake")->move(this_object());
  */
}
