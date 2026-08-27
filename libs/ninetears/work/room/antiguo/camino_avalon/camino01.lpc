inherit "/room/camino_avalon/camino_avalon";

void setup()
{
	do_desc(1);
add_exit("noreste","/room/camino_avalon/camino00","road");
add_exit("sudoeste","/room/camino_avalon/camino02","road");
//modify_exit("sudoeste",({"function","trampa_de_vapor"}));
}


int trampa_de_vapor()
{

int tokado;

tokado=random((this_player()->query_dex())*10);
if (tokado<100)
{
        tell_object(TP, "Al avanzar por la zona una nube de vapor surge repentinamente de \n"+
                        "una grieta en el suelo quemandote la cara y produciendo un dolor \n"+
                        "indescriptible...\n");
        tell_room(ENV(TP), TP->QCN+"Un chorro de vapor surge del suelo vaporizando a "+
                                this_player()->_query_cap_name()+" y dejandole unas muy feas "+
                                "quemaduras.\n",TP);
        this_player()->adjust_hp(-(random(50)+20));
        return 1;
}
else
{
        return 1;
}
}

