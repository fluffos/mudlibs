// By Leviathan 2002


// Trampa de vapor -> trampa_de_vapor

int trampa_de_vapor()
{
int telokomes;
/*
dex: 18  -->>> 40/180 -> 22% de posibilidades de comerlo
dex: 17  -->>> 40/170 -> 23%
dex: 16  -->>> 40/160 -> 25%
dex: 15  -->>> 40/150 -> 26%
...
dex: 10  -->>> 40/100 -> 40%
...
dex: 4   -->>> 40/40  -> 99%
*/
telokomes=random((this_player()->query_dex())*10);
if (telokomes<40)
{
        tell_object(TP, "Al avanzar por la gruta una nube de vapor surge repentinamente de \n"+
                        "una grieta en la roca quemandote la cara y produciendo un dolor \n"+
                        "indescriptible...\n");
        tell_room(ENV(TP), TP->QCN+"Un chorro de vapor surge de la roca vaporizando la cara de "+
                                this_player()->_query_cap_name()+" y dejandole unas muy feas "+
                                "quemaduras.\n",TP);
	// Danyo minimo 10 pvs, maximo 20 pvs.. me parece razonable, ya que no lo comes siempre.
        this_player()->adjust_hp(-(random(10)+10));
        return 1;
}
else
{
	// Te libraste... no pasa nada.. nadie sabe que hay trampa hasta que le da en los morros
        return 1;
}
}

