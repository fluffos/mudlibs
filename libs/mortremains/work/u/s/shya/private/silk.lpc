//Created by Shya July 10, 2000.\\

#include <mudlib.h>

inherit OBJECT;

void create() {
	set ("author", "Shya");
	set ("id", ({"silk", "scarf", "silk scarf"}) );
	set ("short", "A Silk Scarf");
	set ("long", @EndText
This silk scarf belongs to Shya, for her personal use.
It can be used as a blind fold or just to keep somoene's hands busy.
You can 'blindfold' someone or 'tie' them to the bed.
EndText
);
}
void init () {
		add_action("blindfold", "blindfold");
            add_action("tie", "tie");
            add_action("tease", "tease");
}

int blindfold (string str) {
	object victim;

	if (!str) {
		write ("Blindfold who?\n");
		return 1;
	}
	victim = find_player(str);
	if (!victim) {
		write("There's no player named "+capitalize(str)+
			" on the mud!\n");
		return 1;
	}
	tell_object (victim, this_player()->query("cap_name")+
		" slides a blindfold over your eyes turning everything black!\n");
	tell_object (victim, "You are now blinded but you feel the presense of "+
		this_player()->query("cap_name")+
		".\n");
      say (this_player()->query("cap_name")+
		" blindfolds "+
		victim->query("cap_name")+
		" and teases "+
		objective(victim->query("gender"))+
		" erotically.\n", victim);
	write ("You blindfold " +
		victim->query("cap_name")+
		" and tease "+
		objective(victim->query("gender"))+
		" erotically.\n");
return 1;
}

int tie (string str) {
	object victim;

	if (!str) {
		write ("Tie up who?\n");
		return 1;
	}
	victim = find_player(str);
	if (!victim) {
		write("There's no player named "+capitalize(str)+
			" on the mud!\n");
		return 1;
	}
	tell_object (victim, this_player()->query("cap_name")+
		" ties a silk scarf around your wrists tying you to the bed!\n");
	tell_object (victim, "You are now tied to "+this_player()->query("cap_name")+"'s bed.\n");
      say (this_player()->query("cap_name")+
		" ties "+
		victim->query("cap_name")+
		"to "+
		objective(victim->query("gender"))+
		" bed.\n", victim);
	write ("You tie " +
		victim->query("cap_name")+
		" to your bed turning "+
		objective(victim->query("gender"))+
		" on.\n");
return 1;




}
int tease (string str) {
	object victim;

	if (!str) {
		write ("Tease who?\n");
		return 1;
	}
	victim = find_player(str);
	if (!victim) {
		write("There's no player named "+capitalize(str)+
			" on the mud!\n");
		return 1;
	}
	tell_object (victim, this_player()->query("cap_name")+
		" teases your skin with a silk scarf!\n");	
      say (this_player()->query("cap_name")+
		" teases "+
		victim->query("cap_name")+
		" with a silk scarf, turning "+
		objective(victim->query("gender"))+
		" on.\n", victim);
	write ("You tease " +
		victim->query("cap_name")+
		" with a silk scarf turning "+
		objective(victim->query("gender"))+
		" on erotically.\n");
return 1;



}
