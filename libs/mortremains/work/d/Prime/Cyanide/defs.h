#include "cy.h"

#define A_BASE "/d/Prime/Cyanide/"
#define BASE A_BASE + "anthill/"

#define ROOMS(x) BASE + "x"

#ifdef MON
#undef MON
#define MON(x) ROCK_BASE + "monsters/"+ "x"
#endif
