inherit MONSTER;

void create() {
string colour;
int rand;
::create();
        set_name("panther");
        set_id( ({"monster", "panther"}) );
        set_heart_beat(1);

        rand = random(2);
        if(rand == 0) colour = "%^BOLD%^BLACK%^black%^RED%^";
        if(rand == 1) colour = "vicious";
        set_short("a "+colour+" panter");
        set_long("Panthers are vicious animals that are very agile and stealthy, often stalking their prey.");
        set_race("panther");
        if (random(10) > 5)
           set_gender("female");
        else
           set_gender("male");
        set_body_type("feline");
        set_level(37+random(3));
        set_alignment(-random(100));
}
