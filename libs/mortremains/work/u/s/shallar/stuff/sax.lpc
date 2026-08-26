/*
** File: sax.c
**Created by Shallar
*/

inherit OBJECT;

void create() {
    set("author","shallar");
    set("long", wrap(
	"This is an alto saxaphone. It is in great shape, with a brand \n"+
	"new reed in it. You can try to blow in it, jam, or play it. \n"));
    set("short","a saxaphone");
    set("id",({"sax", "saxaphone", "instrument"}));
    set("value", 250);
    set("mass",1);
}

void init() {
    add_action ("play","play");
add_action ("blow","blow");
    add_action("jam","jam");
}
int play (string str){
    write(wrap(
"You play the saxaphone like a professional. You play music by the \n"+
"great John Coltrane to entertain your friends. \n"));
    say(wrap(TPN+" picks up the saxaphone and amazes you with "+
	possessive(TP->query("gender"))+
	" skill. You are treated to the sounds of Coltrane.\n"));
    return 1;
}
int blow (string str){
write(wrap(
"You blow into the saxaphone and make a horrible screeching sound!\n"));
say(wrap(TPN+" blows into the intrument and hurts your ears with the noise it makes. \n"));
return 1;
}

int jam (string str){
write(wrap(
"You jam on the saxaphone like a jazz master! \n"));
say(wrap(TPN+" jams on the saxaphone causing lusty thoughs though out \n" +
"the audience. It must be those strong lips... \n"));
return 1;
}
/* End of file */
