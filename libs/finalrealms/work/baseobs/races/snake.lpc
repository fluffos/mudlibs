inherit "/std/races/standard";

string *inedible;
void setup()
{

    set_name("snake");
    set_long("Looks like a snake, no legs, slithers, scales, fangs and it just hissed.\n");
    /* throw away human bits and replace totally */
    bits = ({ 
      "head", 0, ({ 0, 2, 0, "left eye", "right eye",  "skull","fangs" }),
      "left eye", "eye", ({ "head", 1, 0 }),
      "right eye", "eye", ({ "head", 1, 0 }),
      "skull", 0, ({ "head", 1, 0 }),
      "fangs",0,({"head",1,0}),
      "tail","body",({0,400,0,"heart","liver","left kidney","right kidney",
	"lungs","spleen","gut"})
    });
   set_race_size(1);
}

string query_desc(object ob) {
    return "Your basic snake, fast and nasty\n";
}

int query_eat(string type) {
    return (member_array(type, inedible) == -1);
}
string *valid_attacks()
{
    return ({
      "$att_name$ bites $def_name$ on the $def_part$",
      "You bite $def_name$ on the $def_part$",
      "$att_name$ bites you on the $def_part$",

      "$att_name$ throws a coil round $def_name$ and sqeezes",
      "You try to constrict $def_name$",
      "$att_name$ tries to tangle you in it's snakey coils",

      "$att_name$ sinks it's fangs into $def_name$'s $def_part$",
      "You sink your fangs into $def_name$'s $def_part$",
      "$att_name$ sinks it's fangs into your $def_part$",

      "$att_name$ headbuts $def_part$'s $def_part$",
      "You headbut $def_name$ in the $def_part$",
      "$att_name$ headbutts you in the $def_part$"

    });
}

