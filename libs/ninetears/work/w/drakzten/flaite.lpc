//By Drakzten, todos loz derechoz rezervadoz xD

inherit "/obj/monster";

void setup(){
set_name("flaite");
set_short("Flaite");
set_long(query_short()+"\n\nVes a un weon terrible cuma y algo sucio, anda con unos pantalones"
                            "muy anchos y abajos, tiene un aro totalmente cuma y unos visos en el"
                            "pelo y un gorro con cuero bien doblado puesto a lo flaite y con un"
                            "mechon pa' fuera, tiene puesta un camisa en la cual sale un dibujo"
                            "de un samurai de color amarilla y bien ancha y larga, y puedes notar"
                            "que lleba una filoza corta pluma en la mano. Cuidado con el que te puede"
                            "cocotear.\n\n");
add_alias("flaite");
add_plural("flaites");
set_main_plural("Flaites");
set_gender(1);
set_level(30+random(15));
set_random_stats(16, 18);
set_int(1);
set_wimpy(1);
load_chat(100,({
4, ":saca su corta pluma y trata de intimidarte.",
4, "'Que wea mirai chuchetumare!",
4, ":canta: chi chichichi chichichi chichichi chi chi CUMBIA NENA!! esto es... amar! aaaazuuuuuuuuuul!!!",
4, ":destapa una cerveza y se la bebe",
4, "'Compare, le gusta hierba brava?",}));
load_a_chat(100,({
4, "'Ya culiao!! tai cagao chuchetumare!!",
4, "'Te voy a sacarte la cresta culiao!!",
4, "'Cabross!!!",
4, "'POR EL PODER DE LA CUMBIA!! MUEREEEEE",
4, ":camienza a sentir la cumbia por las venas y hace una extranya danza.",
4, ":sintonisa la radio i le sube el volumen: Amistad Esteeereoooo!!",}));
add_clone("/w/drakzten/cosas/corta_pluma",1);
add_clone("/w/drakzten/cosas/camisa_flaite",1);
add_clone("/w/drakzten/cosas/zapatillaz_fila",1);
add_clone("/w/drakzten/cosas/cerveza",10);

init_equip();
adjust_money(3,"cobre");

}
