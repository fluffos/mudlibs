inherit "/obj/monster";
#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()

void setup()
{
        set_name("caballo");
        set_short("Caballo de Guerra");
        add_alias("caballo");
        set_long("Este fiero y enorme animal de pelo negro ha sido amaestrado "
        "y adiestrado como montura para los caballeros negros. Sus ojos rojos "
        "denotan una maldad sin igual y sus gigantescas patas.\n");
        set_main_plural("Caballos de Guerra");
        add_plural("caballos");
        set_str(25);
        set_con(20);
        set_int(16);
        set_dex(18);
        set_gender(1);
        set_guild_ob("/std/guilds/warriors/fighter");
        set_level(27);
        set_alignment(1200);
        set_al(1200);
}       

int unarmed_attack(object target,object me)
{
        object *att;
        att=(object *)me->query_attacker_list();
        monster::unarmed_attack(att[random(sizeof(att))],me);
        monster::unarmed_attack(att[random(sizeof(att))],me);
}

valid_attack() 
{
    return([
    "knee"  :({AN+" desgarra la carne de "+DN+" con sus afilados colmillos.\n",
                  "desgarras la carne a "+DN+" con tus afilados colmillos.\n",
               AN+" desgarra tu carne con sus afilados colmillos.\n"}),
    "kick"  :({AN+" carga salvajemente sobre "+DN+" mutilandolo.\n",
                  "cargas salvajemente sobre "+DN+" mutilandolo.\n",
               AN+" carga salvajemente sobre ti mutilandote.\n"})]);
}
