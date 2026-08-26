
#include <mudlib.h>


inherit OBJECT ;

void create() {
    seteuid( getuid() );
    set("author" , "Herself");
    set("id" , ({"teddy" , "bear" , "teddy bear"}) );
    set("short" , "a teddy bear");
    set("long", @EndLong
This is Herself's lovable teddy bear.
He is brown with a tan belly and feet.
His fur is super soft, and a little
bit ragged from being so loved. 
EndLong
    );
    set("mass" , 2);
}
void init() {
    add_action ("hug_bear" , "hug");
    add_action ("love_bear" , "love");
    add_action ("hit_bear" , "hit");
    add_action ("poke_bear" , "poke");
}
int hug_bear(string str) {
    string name;
    object target;
    if(!str) {
	write ("hug what?\n");
	return 1;
    }
    if(str! = "teddy" && str!="bear") {
	return 1;
    }
    write(wrap(
	"You wrap your arms around teddy and squeeze him tightly\n") );
    say(wrap(
	TPN+" feels a little sad, so "+subjective(TP->query("gender"))+
	" wraps "+possessive(TP->query("gender"))+" arms around teddy "+
	"and squeezes him tightly! \n") );
    return 1;
}
