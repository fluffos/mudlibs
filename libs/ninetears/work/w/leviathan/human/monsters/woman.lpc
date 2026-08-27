inherit "/obj/monster";
int cry;

void setup()
{
    set_name("anciana");
    set_short("Anciana");
    add_alias("vieja");
    add_alias("trish");
    set_gender(2);
    set_level(8+random(4));
    set_random_stats(8,4);
    set_wis(22);
    set_max_gp(100);
   set_gp(100);
   set_al(-400);
    set_long("Una mujer anciana y arrugada que vive en el poblado. "
    "Ella mira quietamente por encima tuyo por un momento, cura tus heridas "
    "cuando te acercas llorando y sonrie cuando escucha como te "
    "te has lastimado. "
    "\n");
    load_chat(20, ({
        1,({
        "'Debes tener cuidado $lcname$ \nNo quisiera haber gastado mis energias para que acabes muerto.",
        ":sonrie"
        }),
        1,({
        "'Mantente lejos del viejo Dan en la playa, te llenara la cabeza de ideas tontas y acabaras lastimado.",
        "'El no tiene un mal alma realmente, pero nunca se ha sentido agusto aqui. ",
        "'Tratale con respeto, el fue un gran guerrero en su epoca.",
        "'Tu me recuerdas a Dan cuando era joven,siempre arrastrandose hasta aqui con las tripas colgando. ",
        "'A veces creo que lo hacia a posta para que yo le atendiera. ",
      ":sonrie",
        }),
        1,({
        "'Cuando mis poderes comenzaron a decaer como el sol al anochecer, decidi volver a casa y retirarme.",
        "'Aquellos eran dias de poder , Taniwha regia los reinos por entonces. ",
        "'Entonces la oscuridad se extendio por gran parte de los reinos. ",
      ":hace una mueca amarga",
        "'Kel se dejo embaucar por promesas de grandes tesoros y poder. ",
        "'El muy tonto tardo un tiempo en reaccionar.",
        "'Pero al fin se arrepintio de su traicion y volvio con nosotros. "
        }),
        1,({
        "'Hoerk es un sitio estranyo, aunque el poblado es bastante seguro, o lo era al menos.",
        "'No obstante el desierto... ",
        ":se estremece",
        "'El mejor futuro que te espera es arrastrarte entre zombies y cosas peores. ",
        }),
        1,({
        "'Si deambulas por ahi fuera, puedes cortar algo de lenya para el fuego. ",
        "'Hace frio algunas noches. ",
        ":sonrie"
        }),
    }),
    );
    new("/baseobs/armours/cloak")->move(this_object());
    new("/baseobs/armours/cowl")->move(this_object());
    new("/baseobs/weapons/knife")->move(this_object());
    adjust_money(5+random(15),"silver");
    init_equip();
}
void init()
{
    add_action("do_cry","llorar");
    add_attack_spell(20,"cure light",({ "/std/spells/cleric/cure_lt","cast_spell",3}));
    ::init();
}
void reset()
{
    adjust_gp(100);
    cry = 0;
}
int do_cry()
{
    if(cry < 3)
    {
        cry++;
        write("La anciana te sonrie y canta mientras tu lloras...\n");
      this_player()->adjust_hp(3);
   }
    return 0;
}

