#include <std.h>
#include <lodos.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("lord");
   set_short("lord of the tower");
   set_long(@END
           _,--*dSS|""I$$$SS%cccc,_  
         <$$$b |$$$l  j$$$$$$$$$$$$$Sbp
          ?$$$b|$$$$  d$$$$$$$$$$$$$$P
           ?$$$$$$$$; $$$$$$$$$$$$$$P
            ?$$$$$$$| $$$$$$$$$$$$$P
             )$$$$$$$_$SSSSS$$$$$$(
             Y"'               """P 
             (                    )
     _.,cccccd%S$$$$$$$$$$$$$$$SS%dcccc,._
   ($$$$$$$$$$SSSSSSSSSSSSSSS$$$$$$$$$$$$$$$)
     `"""""Y"'      ____        `"$$$$$$$P"'
           8P    ,o88o  `\        )
         ,-'  \o888888)   )  .^^^^^^\
      .-'   ..  \ """'    )_ \   _   )
     (___.--.;   "---...-'~  /  / )  )
      )      __..._      __/'  / )) /
     (`.__.-)_)_)_))  {~'     .\_/_/
    .'   `-.) ) ) ))   `.__.-'   \
   /        `~----'        _/'    \.
 .'                 _...../        )`-----...____
( ,          _.-~~~'       ......-'
 `\______,.-~     Allen Mullen
END);
   set_gender("male");
   set_race("human");
   set_body_type("human");
   set_id(({ "lord" }));
   add_money("gold", random(25));
   make(ARM"hat");
   command("wear hat");
}
