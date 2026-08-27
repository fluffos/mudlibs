// Valar 23/11/02

 inherit "/obj/monster";

void setup() {

 set_name("gulimico");
 set_short("gulimico");

set_long("Te encuentras ante un alma condenada a comer sin parar hasta el fin de los dias, "
 "Sus ojos llorosos no hacen mas que mirarte y su mirada se queda clavada en ti. Es una imagen"
" que tardaras tiempo en olvidar. Podrias ser tu el que estuviera en su lugar.\n");

set_main_plural("gulimicos");

set_gender(0);
set_level(10+random(5));
set_random_stats(18, 20);

     load_chat(30,({
             1, "'Grump, Amp, am.",
             1, ":Te mira fijamente.",
             1, "'Socoghhhdo.",
             2, ":se atraganta con una albondiga.",

}));

     load_a_chat(100,({
                     1, "'Ayudame con este plato!",
                     1, ":te mira con ojos llorosos.",
                     1, ":comienza a incharse y grita de dolor. Seguidamente explota!!",
     				}));
}
