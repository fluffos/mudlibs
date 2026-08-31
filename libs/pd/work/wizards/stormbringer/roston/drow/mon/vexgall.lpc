#include <std.h>
#include <roston.h>
inherit MONSTER;

int attacked=0;

create() {
    ::create();
    set_name("vexgall");
    set_id( ({ "vexgall", "vexgall the caged" }) );
    set_short("Vexgall the Caged");
    set_level(110);
    set_long("Vexgall the Caged was once a mighty ranger known as Zar Whisperwind who resided in Roston, selflessly righting wrongs and fighting alongside the defenders of Roston. However, the Dark Elves took exception to this and staged a trap- they kidnapped his wife, Arelle, but promised her safe release for ten years of service. Zar, without too much choice, agreed to their terms. Using relics the Dark Elves had crafted from the body of a great Red Dragon, they transformed him into a half-dragon, a horridly scarred fighting machine. It was a price he was prepared to pay for the release for his wife, however, he found out too late that they had used her to perfect the technique... Zar swore revenge, but was bound by the Dark Elven magic to complete his service. He changed his name to Vexgall the Caged, his situation frequently causing him to loosing himself to uncontrolable anger, a perk in the eyes of his Dark Elven masters.");
    set_gender("male");
    set_alignment(-1500);
    set("race", "half-dragon");
    set_max_hp(this_object()->query_max_hp()*5);
    set_hp(this_object()->query_max_hp());
    set_body_type("half-dragon");
    set_class("fighter");
    set_subclass("berserker");
    set_skill("rage",400);
    set_skill("ferocity",400);
    call_out("wear_eq",1);
}

int is_invincible() {

    if (attacked == 0)
    {
	this_object()->force_me("emote raises a scarred eyebrow curiously.");
	this_object()->force_me("say To attack me is folly, "+this_player()->query_race()+". Leave this place... leave me to my fate.");
	attacked++;
	return 1;
    }
    if (attacked == 1)
    {
	this_object()->force_me("emote snarls, gripping his axe tightly.");
	this_object()->force_me("say Back, I beg you! Too much blood is already upon my hands!");
	attacked++;
	return 1;
    }
    this_object()->force_me("emote roars!");
    this_object()->force_me("say SO BE IT! Slay me if you can!");
    this_object()->force_me("rage");
}


void wear_eq()

{
    new(DROWOBJ"undyingrage")->move(this_object());
    new(DROWOBJ"chainsofvexgall")->move(this_object());
    new(DROWOBJ"boots")->move(this_object());
    command("wield axe");
    command("wear all");
}
