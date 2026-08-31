inherit MONSTER;

void create() {
string colour;
int rand;
::create();
        set_name("owlbear");
        set_id( ({"monster", "owlbear"}) );
        set_heart_beat(1);

        rand = random(2);
        if(rand == 0) colour = "%^RESET%^ORANGE%^Brown%^BOLD%^RED%^";
        if(rand == 1) colour = "%^BOLD%^BLACK%^Black%^RED%^";
        set_short("a "+colour+" owlbear");
        set_long("The owlbears are the creation of failed experiments to create an army of flying warriors. The creatures are born without arms but rather have claws half way along their wings.");
        set_race("owlbear");
        if (random(10) > 5)
           set_gender("female");
        else
           set_gender("male");
        set_body_type("fowl");
        set_level(36+random(3));
        set_alignment(-random(100)+random(100));
}
