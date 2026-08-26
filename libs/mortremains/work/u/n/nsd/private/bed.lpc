/*
** File: bed.c
** Author: Lady Nsd
*/

inherit OBJECT;

void create() {
    set("author", "nsd");
    set ("id", ({ "bed" }) ) ;
    set ("short", "a king size bed");
    set("long", @EndLong
A kingsize pillar bed covered with velvet blankets and a
damask quilt. Seems comfortable enough to rest on it.
To learn how to use it, type 'bedhelp'.
EndLong);
    set ("mass", 1000);
    set ("bulk", 1000);
}
void init() {
    add_action("rest_on_bed", "rest");
    add_action("lay", "lay");
    add_action("inchkiss", "inchkiss");
    add_action("broll", "broll");
    add_action("bcover", "bcover");
    add_action("warm", "warm");
    add_action("bremove", "bremove");
    add_action("embrace", "embrace");
    add_action("ob", "ob");
    add_action("ahh", "ahh");
    add_action("fsuck", "fsuck");
    add_action("jump_on_bed", "jump");
    add_action("bedhelp", "bedhelp");
}
int rest_on_bed (string str) {
    say(TPN+" gets on bed and rests a little...\n");
    write(wrap(
	"The mattress adjusts to your anatomy as you lay down.\n"+
	"You can hardly keep awake, for you are really comfortable...\n"));
    return 1;
}
int lay (string name) {
    object target;
    target = present(name, environment(this_player() ));
    if (!target) {
	notify_fail ("You're strange, thou.\n");
	return 0;
    }
    if(!living(target) ) {
	notify_fail("Funny how you want to lay that.\n");
	return 0;
    }
    say(
      target->query("cap_name")+" is being laid by "+
      TPN+" in a tender way.\n"+
      "Are they in love? - you wonder...\n", ({ target }) );
    write(wrap(
	"You carry "+capitalize(name)+" to bed, and get "+
	objective(target->query("gender"))+" laid in a\n"+
	"tender way. "+capitalize(name)+" looks so beautiful you're afraid\n"+
	"to spoil "+objective(target->query("gender"))+
	"... You're in love... \n"));
    tell_object(target, wrap(
	TPN+" carries you to bed and lays you down in a tender way.\n"+
	"You notice "+TPN+" is in love with you by the way "+
	subjective(TP->query("gender") )+" stares\n"+
	"at your eyes. But still "+TPN+" haven't touch you, for "+
	subjective(TP->query("gender") )+"'s\n"+
	"afraid of spoiling you...\n"));
    return 1;
}
int inchkiss (string name) {
    object target;
    target = present(name, environment(this_player() ));
    if (!target) {
	notify_fail ("Your beloved is not in the room.\n");
	return 0;
    }
    if(!living(target) ) {
	notify_fail("That player is not here\n");
	return 0;
    }
    write(wrap(
	"You kiss every inch of "+capitalize(name)+
	"'s body in a sensual way.\n"+
	capitalize(name)+" bites "+possessive(target->query("gender"))+
	" lower"+ " lip to avoid gasping...\n"));
    tell_object(target, wrap(
	TPN+" kisses every inch of your body in a sensual way.\n"+
	"You bite your lower lip to avoid gasping...\n"));
    say(
      TPN+" kisses every inch of "+capitalize(name)+
      "'s body in a sensual way.\n"+
      capitalize(name)+" bites "+possessive(target->query("gender"))+
      " lower"+ " lip to avoid gasping...\n", ({target}) );
    return 1;
}
int broll (string name) {
    object target;
    target = present(name, environment(this_player() ));
    if (!target) {
	notify_fail ("That player is not here.\n");
	return 0;
    }
    if(!living(target)) {
	notify_fail ("There's no one logged in by that name.\n");
	return 0;
    }
    tell_object(target, wrap(
	TPN+" rolls under the blankets with you, while\n"+
	"french kissing you deeply and sweetly...\n"));
    write(wrap(
	"You roll under the blankets with "+capitalize(name)+" while"+
	" frenching\n"+objective(target->query("gender"))+" deeply "+
	"and sweetly...\n"));
    say(
      TPN+" rolls under the blankets with "+capitalize(name)+"\n"+
      "while french kissing "+objective(target->query("gender"))+
      " deeply and sweetly...\n", ({target}) );
    return 1;
}
int bcover (string str) {
    write("You cover your naked body with the blanket.\n");
    say(TPN+" covers "+POSS+" naked body with the blanket.\n");
    return 1;
}
int warm (string name) {
    object target;
    target = present(name, environment(this_player() ));
    if(!target) {
	notify_fail("There's no player named "+capitalize(name)+" here!\n");
	return 0;
    }
    if(!living(target)) {
	notify_fail ("That person is not here.\n");
	return 0;
    }
    write(wrap(
	"You lay on top of "+capitalize(name)+"'s naked body to keep\n"+
	objective(target->query("gender"))+" warm. "+
	capitalize(name)+"'s temperature rises, making "+
	objective(target->query("gender"))+" hot\n"+
	"of desire...\n"));
    tell_object(target, wrap(
	TPN+" lays on top of your naked body to keep you warm.\n"+
	"Your temperature rises and you get hot of desire...\n"));
    say(
      TPN+" lays on top of "+capitalize(name)+"'s naked body "+
      "to keep "+objective(target->query("gender"))+" warm.\n"+
      capitalize(name)+" gets hot of desire...\n", ({target}) );
    return 1;
}
int bremove (string name) {
    object target;
    target = present(name, environment(this_player() ));
    if(!target) {
	notify_fail("There's no one named "+capitalize(name)+" here!\n");
	return 0;
    }
    if(!living(target)) {
	notify_fail ("That person is not here.\n");
	return 0;
    }
    write(wrap(
	"You remove the blanket from "+capitalize(name)+
	" in order to see\n"+
	"the whole magnificence of "+possessive(target->query("gender"))+
	" naked silhouete.\n"+
	"You eye "+objective(target->query("gender"))+" from head to toe,"+
	" and get excited\n"+ "with what you see.\n"));
    tell_object(target, wrap(
	TPN+" removes your blanket in order to see the whole\n"+
	"magnificence of your naked silhouete. \n"+
	TPN+" eyes you from head to toe, and gets excited...\n"));
    say(
      TPN+" removes the blanket from "+capitalize(name)+
      " in order to see\n"+
      possessive(target->query("gender"))+
      " naked silhouete.\n", ({target}) );
    return 1;
}
int embrace (string name) {
    object ob;
    ob = present(name, environment(this_player() ));
    if(!ob) {
	notify_fail("There's no one named "+capitalize(name)+" here!\n");
	return 0;
    }
    if(!living(ob)) {
	notify_fail ("That person is not here.\n");
	return 0;
    }
    write(wrap(
	"You embrace your lover "+capitalize(name)+" tenderly and "+
	"tightly,\n"+ "not wanting to let go of "+
	objective(ob->query("gender"))+".\n"));
    tell_object(ob, wrap(
	TPN+" embraces you tenderly and tightly, not wanting to\n"+
	"let go of you.\n"));
    say(
      TPN+" embraces "+capitalize(name)+" tenderly and tightly, "+
      "not wanting to let go of "+objective(ob->query("gender"))+
      ".\n", ({ob}) );
    return 1;
}
int ob (string str) {
    write("You whisper with excitement: Oh....baby.....!\n");
    say(TPN+" whispers with excitement: Oh....baby.....!\n");
    return 1;
}
int ahh (string str) {
    write("You let out a pleasing Ahhhhhhh.....!\n");
    say(TPN+" lets out a pleasing Ahhhhhhh.....!\n");
    return 1;
}
int fsuck (string str) {
    write(
      "You suck your index finger in a teasing way...\n");
    say(TPN+" sucks "+POSS+" index finger in a teasing way...\n");
    return 1;
}
int jump_on_bed (string str) {
    write(wrap(
	"You jump on the bed like a brat kid. You deserve to be spanked!\n"));
    say(wrap(
	TPN+" jumps on the bed like a brat kid. You may want to\n"+
	"spank "+objective(TP->query("gender"))+"!\n"));
    return 1;
}
int bedhelp (string str) {
    write(@EndText
^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^
|                                                 |
|                SELF EMOTES:                     |
|                                                 |
|       *rest on bed*  *bcover*  *ob* *ahh*       |
|       *fsuck* *jump on bed*                     |
|                                                 |
|              SHARED EMOTES:                     |
|                                                 |
|      *lay <partner>*  *inchkiss <partner>*      |
|      *broll <partner>*  *warm <partner>*        |
|      *bremove <partner>* *embrace <partner>*    |
|                                                 |
^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^
EndText);
    return 1;
}
/* EOF */
