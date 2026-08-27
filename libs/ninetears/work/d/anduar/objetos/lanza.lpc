inherit "/obj/weapon";

void setup()
{
    set_base_weapon("twohanded sword");
    set_name("Lanza de Caballeria");
    set_twohanded(0);

    add_alias("lanza");
    set_short("Lanza de Caballeria");
    add_alias("lanza de caballeria");
    set_long("Esta es un larga lanza con una punta de metal en forma de "
                "cono y un mango de madera. Tiene al menos 3 metros de "
                "longitud y es perfecta para ensartar enemigos como pinchos "
                "morunos.\n");
    set_main_plural("Lanzas de Caballeria");
    add_alias("lanzas");
    add_adjective("de caballeria");
}

int set_in_use(int i)
{
        if(interactive(ETO) && ETO->query_name() !="jinete")
        {
                write("Pero que haces tu con una Lanza que requiere montura"
                      " y no tienes montura con el que ir ?.\n");
                call_out("dest_me",0);
        }
        return ::set_in_use(i);
 }
