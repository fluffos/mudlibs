#include <mudlib.h>

inherit OBJECT;

void create(){
	set("invisible", 2);
set("id", ({"sticker", "neon sticker", "stupid"}));
set("prevent_drop", 1);
	set("long", @FOO
A small, barely noticible sticker that reads 'Sebastian is the greatest'
It's neon green and kinda neat lookin.
FOO
);
set("prevent_get", 1);
set("extra_look", "Has a 'Seb is great' sticker on.\n");
}
void init(){
	add_action("slap_sticker", "slap");
}
int slap_sticker(string str){
	string name;
	object target;
if (!str){
	write("Slap who with a sticker?\n");
	return 1;
	}
if (sscanf(str, "%s on %s", str, name) !=2){
write("Who do you want to slap a sticker on?\n");
 return 1;
}
   if (str!="sticker" && str!="neon sticker" && str!= "stupid"){
  return 0;
	}
  target = find_player(name);
    if (!target) {
	 write("There's no player named "+capitalize(name)+
         " on the mud!\n");
       return 1;
	}
    if(target->query("busy")) {
        write("That person is busy at the moment... \n");
       return 1;
	}
    write("You slap a sticker on "+target->query("cap_name")+"!\n");
    move( target );
    return 1;
}
