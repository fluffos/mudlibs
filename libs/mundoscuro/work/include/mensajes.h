
#ifndef MENSAJES_H
#define MENSAJES_H

class mensaje {
    int tipo_dano;
    int gravedad;
    string texto_yo;
    string texto_el;
    string texto_otros;
}

#define MENSAJE(t,u,x,y,z) mensaje(t,u,x,y,z)

#endif /* MENSAJES_H */

