inherit "/obj/monster";

void setup(){
set_name("guardian");
set_short("Guardian de %^BOLD%^%^GREEN%^Drakzten%^RESET%^");
set_long(query_short()+"\nEs un guardian corpulento y aguil, puedes notar en sus ojos una bondad pura por dentro y por fuera una gran fiereza, dicen que estos Guardianes fueron elegidos personalmente por el gran Drakzten para proteger su humilde casa, parece muy peligroso en combate.\n\n");
set_main_plural("Guardianes de %^BOLD%^%^GREEN%^Drakzten%^RESET%^");
add_alias("elfo");
add_plural("elfos");
add_plural("guardianes");
add_known_command("cazar");
set_gender(1);
set_habilidad("doble arma",100);
set_habilidad("cazar",100);
set_level(45+random(5));
set_random_stats(19, 20);
set_wis(10);
set_dex(25);
set_wimpy(0);
set_max_hp(query_level() * 450);
set_hp(query_max_hp());
set_max_gp(query_level() * 130);
set_gp(query_max_gp());
set_max_ep(query_level() * 200);
set_gp(query_max_gp());
load_chat(30,({
1, "'No no, nada de eso te estoy vigilando.",
2, ":toma una posicion extranya, parece que esta vigilando.",
3, "'Estoy orgulloso de proteger la casa del gran Drakzten.",
4, "'Sabias que a mi me eligio personalmente el gran Drakzten! a mi!!.",
5, ":afila su espectacular espada.",}));
load_a_chat(100,({
3, "'Uis eso me dolio xD.",
3, ":comienza a silvar inocentemente.",
3, "'Lalalala...",
3, ":bosteza.",
1, "'Weno ya me aburri, tendre que matarte en nombre del gran Darkzten!.",}));
add_clone("/w/drakzten/espada_animal",2);
add_clone("/w/drakzten/cota_salvaje",1);
add_clone("/w/drakzten/botas_de_tronco_amarillo",1);
add_clone("/w/drakzten/cinturon_de_hierba",1);
add_clone("/w/drakzten/cinta_de_hojas",1);
add_clone("/w/drakzten/capa_matorral",1);

init_equip();
adjust_money(50,"platino");
}