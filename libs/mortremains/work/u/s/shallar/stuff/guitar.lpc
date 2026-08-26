/*
** File: guitar.c
**Created by Shallar
*/

inherit OBJECT;

void create() {
    set("author","shallar");
    set("long", wrap(
"This is a brand new electric guitar. It sounds like it's in tune! You \n" +
"can pluck, play, or improvise on it. \n"));
set("short","an electric guitar");
set("id",({
"guitar","instrument"}));
    set("value", 250);
    set("mass",1);
}

void init() {
    add_action ("play","play");
add_action("pluck","pluck");
add_action("improvise","improvise");
}
int play (string str){
    write(wrap(
"You strum the guitar for a moment and then break into a refrain \n"+
"of My Generation. \n"));
say(wrap(TPN+" puts the guitar over their shoulder and churns out "+
"a rendition of My Generation. You flick on a lighter. \n"));
    return 1;
}
int pluck (string str){
write(wrap(
"You tentatively pluck the string, causing one to pop in your face. \n"));
say(wrap(TPN+" plucks like an amateur, causing a string to break. \n"));
return 1;
}

int improvise (string str){
write(wrap(
"You improvise a new rift on the spot. Wow, that's cool!\n"));
say(wrap(TPN+" improvises with the guitar, making an amazing piece of " +
"music up on the spot." + subjective(TP->query("gender")) + " is da BOMB!\n"));
return 1;
}
/* End of file */
