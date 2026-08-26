/*
** File: pizza.c
** Author: Lady Nsd
*/

inherit OBJECT;

void create() {
    set("author", "nsd");
    set("long", wrap(
	"A slice of pepperoni pan pizza. Looks delicious and juicy.\n"+
	"It has extra cheese, and stuffed crust. Eat it!\n"));
    set("short", "a slice of pizza");
    set("id", ({ "pizza", "slice", "slice of pizza" }) );
    set("value", 50);
    set("mass", 0);
}

void init() {
    add_action("eat", "eat");
}
int eat( string str ) {
    write(wrap(
	"You wolf your slice of pizza... The extra cheese stretches\n"+
	"as you bite on it. Yummy!!!\n"));
    say(wrap(TPN+" eats "+POSS+" slice of pizza.\n"));
    remove();
    return 1;
}
/* End of file */
