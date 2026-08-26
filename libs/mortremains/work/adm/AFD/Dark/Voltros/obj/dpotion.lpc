#define HEALING 5

inherit OBJECT ;

void create() {
        set ("short", "A dark potion") ;
        set ("long", "This is a dark-colored, viscious potion.
\n") ;
        set ("id", ({ "potion"}) ) ;
        set ("mass", 10) ;
        set ("bulk", 5) ;
  set_value(0);


}

void init() {
        add_action ("drink", "drink") ;
}

int eat (string str) {


        if (!str || !id(str)) {
                notify_fail ("Drink what?\n") ;
                return 0 ;
        }
        write ("You drink the potion and feel slightly lightheaded.\n") ;
   TP->receive_healing(HEALING);
        remove() ;
        return 1 ;
}