#include <std.h>
inherit OBJECT;
void init() {
    ::init();
    add_action("get_paper", "take");
}
void create() {
 ::create();
   set_id(({ "pile" , "paper pile" , "pile of newspapers" , "newspapers"}));
   set_name("pile of newspapers");
   set_long("A pile of the most recent edition of the Tirun Times. <take paper> to get one.");
   set_short("a pile of newspapers");
   set_weight(1);
   set("value", 0);
set_prevent_get( "The pile it to heavy to lift, try taking one." );
}
int get_paper(string str) {
    if(!str) {
        notify_fail("Take what?\n");
        return 0;
    }
    if(str != "paper" && str != "times" && str != "newspaper") {
        notify_fail("Take what?\n");
        return 0;
    }
    new("/wizards/stormbringer/ttpaper/ttnews2")->move(this_player());
    write("Enjoy it!");
     return 1;
}
