inherit "/std/room";
#include "path.h"
#include "config.h"
object board;

void setup ()
{
set_short("%^GREEN%^Puertas de acceso a Casa del Inmortal Sharka%^RESET%^.");

set_long("%^GREEN%^Puertas de acceso a Casa del Inmortal Sharka%^RESET%^."
"\n\n Te sientes anonadado al descubrir la impenetrable fortaleza de Sharka, sin"
" dudas estas puertas dan acceso a su casa, para entrar solo tendras que abrirlas"
" ahora bien solo el sabe los peligros que dentro de ella te esperan; estas seguro "
" que deseas jugarte tu vida en tan gran hazanya ????\n\n");

set_light (70);

//add_exit("sur","/w/sharka/casa/montanya.c","door");
}

void init()
{
::init();
add_action("abrir","abrir");
add_action("cerrar","cerrar");
}

int abrir(string str)

{
if (str == "puerta")
  {
  write("Pulsas el timbre y deckard te abre la puerta de la Casa de Sharka.\n");
  add_exit("norte","/w/sharka/casa/hall.c","door");
  renew_exits();
  return 1;
  }
notify_fail("Abrir que??, que me estas contando xD\n");
return 0;
}

int cerrar(string str)

{
if (str == "puerta")
  {
  write("Deckard cierra la puerta de la Casa de Sharka.\n");
  renew_exits();
  return 1;
  }
notify_fail("Cerrar que??, que me estas contando xD\n");
return 0;
}