// Chernobog (3/15/22)
// Interior Yniam Road

#include <std.h>
#include "../defs.h"
inherit INH"road2";

void create(){
    ::create();
    set_long(::query_long()+"\n%^RESET%^%^CRST%^%^C101%^A small %^C097%^cafe %^RESET%^%^C101%^rests at the side of the road. It features a shallow porch with an odd collection of chairs set out at inconsistent intervals. Several large windows break up the monotony of the storefront and allow a view of %^C161%^m%^C166%^y%^C178%^r%^C190%^i%^C154%^a%^C120%^d %^C041%^c%^C031%^o%^C033%^l%^C098%^o%^C108%^r%^C118%^s %^RESET%^%^C101%^and %^C059%^p%^C254%^a%^C059%^t%^C254%^t%^C097%^e%^C091%^r%^C092%^n%^C098%^s %^RESET%^%^C101%^within. Over a set of glass doors, it proclaims itself %^C082%^\"T%^C072%^he %^C082%^S%^C072%^erene %^C082%^T%^C072%^ea %^C082%^H%^C072%^ouse%^C082%^\"%^RESET%^%^C101%^, with a smaller %^C100%^sign %^RESET%^%^C101%^set off to the side.%^CRST%^\n");
    add_item("chairs", "%^RESET%^%^CRST%^%^C101%^No two chairs are alike. Some are %^C144%^w%^C253%^i%^C144%^c%^C253%^k%^C144%^e%^C253%^r%^RESET%^%^C101%^, others have been shaped from %^C130%^cedar %^C101%^or %^C136%^oak%^RESET%^%^C101%^, and painted in a series of %^C084%^pa%^C099%^st%^C051%^el%^C228%^s%^RESET%^%^C101%^.%^CRST%^");
    add_item("sign", "%^RESET%^%^CRST%^%^C244%^A small sign next to the front doors proclaims in simple script: %^C255%^\"No monsters\"%^C244%^.%^CRST%^");
    set_exits(([
        "southwest" : "/d/dagger/tonovi/1path1",
        "northeast" : ROOMS"road2",
        "cafe" : "/d/player_houses/branwen/tea_shop/room/teashop",
        ]));
}

void reset(){
    ::reset();
    
    if(!present("ambiance device")) new(OBJ"ambiance")->move(this_object());
}

