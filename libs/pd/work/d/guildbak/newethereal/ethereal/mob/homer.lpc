#include <std.h>
#include <guild.h>
#include <ether.h>
inherit VENDOR;
create() {
    ::create();
    set_name("Homer Simpson");
    set_id( ({ "homer", "homer simpson" }) );
set_short("%^YELLOW%^H%^RESET%^%^ORANGE%^o%^YELLOW%^m%^RESET%^%^ORANGE%^e%^YELLOW%^r%^RESET%^%^ORANGE%^ S%^YELLOW%^i%^RESET%^%^ORANGE%^m%^YELLOW%^p%^RESET%^%^ORANGE%^s%^YELLOW%^o%^RESET%^%^ORANGE%^n%^RESET%^");
    set_level(45);
    set_long("This is Homer the shopkeep of Ethereal. "
      "You might remember him from such shows as \"The "
      "Simpsons\". He loves donuts, so maybe if you "
      "give him one, he will give you things for free! "
     "%^RESET%^Look at the sign for help.%^RESET%^"
);
    set_gender("male");
    set_alignment(-420);
    set("race", "idiot");
    add_money("gold", random(60));
    set_body_type("human");
    set_currency("gold");
    set_storage_room(STORAGE"other");
    set_skill("bargaining", 1);
    set_property("no bump", 1);
    set_property("no attack", 1);
}
void init() {
    ::init();
    add_action("purchase", "purchase");
}

int purchase(string str) {  
    int num;
    object oil;
    if (!str) {
        this_object()->force_me("say Purchase what?");
        return 1;
    }
    if (str != "arctic" && "inferno" && "inferno" && "arctic")
    {
        if (sscanf(str, "%d %s", num, str) != 2) {
            this_object()->force_me("say I don't have that for sale.");
            return 1;
        }
    }
    switch(str)
    {
    case "inferno": 
    case "infernos": 
        if(this_player()->query_money("gold") < 20) {
            this_object()->force_me("say You don't have that much money!");
            return 1;
        } 
        if (num) {
            if (num < 1 || num > 1000) return 0;
            if (this_player()->query_money("gold") < 20*num) {
                this_object()->force_me("say You don't have that much money!");
                return 1;
            }
            this_player()->add_money("gold", -20*num);
            write("Strongbad hands you "+(string)num+" inferno orbs.");
            while (num > 0) {
                oil = new(OBJ"iorb");
                if (num >= 15) 
                    oil->set_uses(15);
                else 
                    oil->set_uses(num);
                num -= 15;
                oil->move(this_player());
            }
            return 1;
        }
        this_player()->add_money("gold", -20);
        write("Strongbad hands you an inferno orb.");
        new(OBJ"iorb")->move(this_player());
        return 1;
        break; 
    case "arctic":
    case "arctics":
        if(this_player()->query_money("gold") < 30 ) {
            this_object()->force_me("say You don't have that much money!");
            return 1;
        }
        if(num) {
            if(num < 1 || num > 1000) return 0;
            if(this_player()->query_money("gold") < 30*num ) {
                this_object()->force_me("say You don't have that much money!");
                return 1;
            }
            this_player()->add_money("gold", -30*num);
            write("Strongbad hands you "+(string)num+" arctic orbs.");
            while(num--)
                new(OBJ"orb")->move(this_player());
            return 1;
        }
        this_player()->add_money("gold", -30);
        write("Strongbad hands you an arctic orb."); 
        new(OBJ"orb")->move(this_player());
        return 1;
    }
}
