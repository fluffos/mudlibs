#include <std.h>
#include <purgatory.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("The elder caretaker");
   set_short("The elder caretaker");
   set_id(({"monster", "caretaker", "elder caretaker"}));
   set_long("This is an old man, bent with age, that has agreed to keep the graveyards up and running.");
    set_level(75+random(10));
   set("aggressive", 22);
   set_gender("male");
   set_race("human");
   set_class("fighter");
   set_subclass("warrior");
   set_body_type("human");
   set_emotes(2,({ "The caretaker mutters something about Death.", "The old mans back creaks as he stands up." }),0);

}

void catch_tell(string str) {
    object ob;
    string a, b;

    if(this_player() == (ob = this_object())) return;
    if(sscanf(str, "%suest%s", a, b) == 2) {
        this_object()->force_me("say Long ago, Death plagued this land like a pestilence. It moved like lightning and struck like a falling rock on all those who opposed it. It killed the whole royal family, and with its thirst for pain and suffering finally sated, it slinked away near here..");
        return;
    }
    if(sscanf(str, "%sdeath%s", a, b) == 2) {
        this_object()->force_me("say Death came to this place a long long time ago, when I was only a boy. It has terrorized this town and all who live in it since it arrived. It is rumored that he has holed up in the old building just east of here.");
        return;
    }
    if(sscanf(str, "%sbuilding%s", a, b) == 2) {
        this_object()->force_me("say Many people have gone after Death, only to die while trying to relieve us poor folk of his influence. If you wish to face Death, you must go quickly!");
        return;
    }
}

