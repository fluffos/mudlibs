inherit "/obj/monster";
int cry;

void setup()
{
    set_name("old woman");
    set_short("Old woman");
    add_alias("woman");
    add_alias("trish");
    set_gender(2);
    set_level(8+random(4));
    set_random_stats(8,4);
    set_wis(22);
    set_max_gp(100);
   set_gp(100);
   set_al(-400);
    set_long("A wrinkled old crone who lives in the village here. "
    "She's quietly looked after you for quite a while, tended your wounds "
    "when you've come in crying and just smiled when she's heard how "
    "you got those wounds. "
    "\n");
    load_chat(20, ({
        1,({
        "'You be careful out there $lcname$ \nI haven't spent all this time looking after you to have you up and die.",
        ":smiles"
        }),
        1,({
        "'You stay away from old Dan on dock beach, he'll fill your head with silly ideas and you'll get hurt.",
        "'He's not a bad soul really, but he's never settled down here. ",
        "'Treat him with respect mind, he were a great fighter in his day.",
        "'You remind me of Dan when he was young, always crawling into town with his guts hanging out. ",
        "'Sometimes I think he did it deliberate so I'd come tend him. ",
      ":smiles",
        }),
        1,({
        "'When my powers started to fade like the sun going down I decided to come home to retire.",
        "'Those were the days of power though, Taniwha ruled the realms in daytime. ",
        "'Thorn hedge then falling stars took care of most things. ",
      ":grins wickedly",
        "'Got Kel with thorn hedge once then emoted the stars. ",
        "'The silly fool wet himself.",
        "'Serves him right from stealing from a Taniwha. "
        }),
        1,({
        "'Hoerk is a strange place, the town are safe enough, daytimes anyways.",
        "'That desert though. ",
        ":shudders",
        "'The further you get in the worse it gets, crawls with undead and worse. ",
        }),
        1,({
        "'If you are around, you could split some more wood for the fire. ",
        "'Gets cold these days. ",
        ":smiles"
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
    add_action("do_cry","cry");
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
        write("The old woman smiles at you as she chants.\n");
      this_player()->adjust_hp(3);
   }
    return 0;
}

