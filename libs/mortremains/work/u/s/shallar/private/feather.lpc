/*
**Created by Shallar
*/

inherit OBJECT;

void create() {
    set("author","shallar");
    set("long", wrap(
"Here is a nice, soft feather. It is nice and long and can do interesting \n" +
"things to a person's body. You can glide it across someone, brush them, \n"
+ "and stroke it. \n"));
set("short","White Feather");
set("id",({"feather","white feather"}));
    set("mass",1);
}

void init() {
add_action ("glide_across","glide");
add_action("brush","brush");
add_action ("stroke_feather","stroke");
}
int brush (string str){
object victim;

if(!str) {
write ("Brush feather against who? \n");
}
victim= find_player(str);
if (!victim) {
write("Sorry, they ain't here!\n");
return 1;
}

tell_object(victim, this_player()->query("cap_name") +
" brushes the feather along your skin. You feel chills going up your back. \n");
write(wrap("You brush the feather across their skin causing them to tremble. \n"));
return 1;
}
int glide_across(string str){
write(wrap("You glide the feather across " + this_player()->query("cap_name")+"'s skin and watch \n" +
"them squirm in pleasure. \n"));
say(wrap(TPN+" gets an evil look on their face as they glide the feather across \n"+
"your skin. You feel your breath start to quicken. \n"));
return 1;
}
int stroke_feather(string str){
write(wrap(
"An evil smile creeps across your face as your stroke the feather with your hand. \n"));
say(wrap(TPN+" grins as they stroke the end of the feather with their \n" +
"hand. You are almost afraid of what's in their mind. \n"));
return 1;
}

