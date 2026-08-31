#include <std.h>
#include <vampq.h>
#include <mjungle.h>
#include <gcity.h>

inherit OBJECT;

void init()
{
    ::init();
    add_action("cmd_cut", "cut");
}

void create()  {
    ::create();
    set_name("Ruby Key");
    set("id", ({"key"}) );
    set_short("%^RESET%^%^RED%^Ruby%^RESET%^ Key");
    set_long("%^RESET%^A key made entirely of %^RED%^ruby%^RESET%^. This once was in possession of Shallzaea, the Merkkirri Queen. The %^RED%^ruby%^RESET%^ has been shaped into a sharp object that looks like it easily cut you.");
    set_weight(1);
}
int query_auto_load() {
    if (this_player()->query_level() >=30)
	return 1;
}
int cmd_cut(string str) {
    if (str!="hand") {
	notify_fail("Cut what?.\n");
	return 0;
    }
    write("%^RESET%^You %^RED%^dig%^RESET%^ the key into your hand %^RED%^cutting%^RESET%^ it %^RED%^deeply%^RESET%^.\nThe %^BOLD%^%^RED%^blood%^RESET%^ seeping from your hand is absorbed by the %^RED%^ruby%^RESET%^.\nThe %^RED%^ruby%^RESET%^ emits a %^BOLD%^%^ORANGE%^bright glow%^RESET%^, changing it's appearance.\n");
    this_player()->add_hp(-350);
    new(VO"blood_key")->move(environment(this_object()));
    remove()->this_object();
    return 1;
}
