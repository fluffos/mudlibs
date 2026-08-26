

inherit OBJECT ;

void create() {
        set ("short", "a tidbit of food") ;
        set ("long", "This is a small tidbit of food, it might feel good on an 
empty stomach.\n") ;
        set ("id", ({ "morsel", "tidbit" }) ) ;
        set ("mass", 10) ;
        set ("bulk", 5) ;
  set_value(21);


}
void init() {
        add_action ("eat", "eat") ;
}
int eat (string str) {
  int vitals;
  int con;
  int spi;
  con = TP->query("stat/constitution");
  spi = TP->query("stat/spirit");
  vitals = (con + spi)/2;
        if (!str || !id(str)) {
                notify_fail ("Eat what?\n") ;
                return 0 ;
        }
        if((int)TP->query("stuffed") > vitals){
              write("You are too full to eat the morsel.\n");
              return 1;
         }
        write ("You eat the morsel and feel slightly better.\n") ;
             TP->receive_healing(random(7));
             TP->add("stuffed", 1);
        remove() ;
        return 1 ;
}