// Vilat 23.01.2002
// Handler de Rangos de Inmortales

// La seguridad no es lo mio pero esperemos que rule y nadie sea malo =)

#define SAVEOB file_name(TO),1

mapping dioses;
mapping semidioses;
mapping alquimistas;
mapping lords;
mapping thanes;
mapping patrones;
mapping regentes;

void create() {
    seteuid("root");
    dioses = ([]);
    semidioses = ([]);
    alquimistas = ([]);
    lords = ([]);
    thanes = ([]);
    patrones = ([]);
    regentes = ([]);
    restore_object(SAVEOB);
    }
    
void dest_me() {
    save_object(SAVEOB);
    destruct(TO);
    }
    
int regente(string name, string titulo, object cargo) {
    object pl=find_player(name);
    if(!pl) return 0;
    if(!cargo) return 0;
    if(!pl->query_creator()||pl->query_regente()||pl->query_patron()||pl->query_thane()||pl->query_lord()||pl->query_demi()||pl->query_alqui()||pl->query_god()) return 0;
    if(!cargo->query_thane()) return 0;
    if(cargo!=this_player(1)) return 0;
    if(!titulo) return 0;
    regentes[name]=titulo;
    tell_object(cargo,"Ok, "+pl->QCN+" asciende a Regente.\n");
    tell_object(pl,cargo->QCN+" te ha concedido un ascenso. Sal y entra de nuevo.\n");
    save_object(SAVEOB);
    return 1;
    }

string dame_regencia(string name) { return regentes[name]; }

int patron(string name, string titulo, object cargo) {
    object pl=find_player(name);
    if(!pl) return 0;
    if(!titulo) return 0;
    if(!cargo) return 0;
    if(!pl->query_creator()||pl->query_thane()||pl->query_patron()||pl->query_lord()||pl->query_alqui()||pl->query_demi()||pl->query_god()) return 0;
    if(!cargo->query_lord()) return 0;
    if(cargo!=this_player(1)) return 0;
    patrones[name]=titulo;
    tell_object(cargo,"Ok, "+pl->QCN+" asciende a Patron.\n");
    tell_object(pl,cargo->QCN+" te ha concedido un ascenso. Sal y entra de nuevo.\n");
    save_object(SAVEOB);
    return 1;
    }
    
string dame_patron(string name) { return patrones[name]; }

int thane(string name,string titulo, object cargo) {
    object pl=find_player(name);
    if(!pl) return 0;
    if(!titulo) return 0;
    if(!cargo) return 0;
    if(!pl->query_creator()||pl->query_thane()||pl->query_lord()||pl->query_alqui()||pl->query_demi()||pl->query_god()) return 0;
    if(!cargo->query_alqui()&&!cargo->query_demi()&&!cargo->query_god()) return 0;
    if(cargo!=this_player(1)) return 0;
    thanes[name]=titulo;
    tell_object(cargo,"Ok, "+pl->QCN+" asciende a Thane.\n");
    tell_object(pl,cargo->QCN+" te ha concedido un ascenso. Sal y entra de nuevo.\n");
    save_object(SAVEOB);
    return 1;
    }
    
string dame_thane(string name) { return thanes[name]; }

int lord(string name,string titulo, object cargo) {
    object pl=find_player(name);
    if(!pl) return 0;
    if(!titulo) return 0;
    if(!cargo) return 0;
    if(!pl->query_creator()||pl->query_lord()||pl->query_alqui()||pl->query_demi()||pl->query_god()) return 0;
    if(!cargo->query_demi()&&!cargo->query_god()) return 0;
    if(cargo!=this_player(1)) return 0;
    lords[name]=titulo;
    tell_object(cargo,"Ok, "+pl->QCN+" asciende a Lord/Lady.\n");
    tell_object(pl,cargo->QCN+" te ha concedido un ascenso. Sal y entra de nuevo.\n");
    save_object(SAVEOB);
    return 1;
    }
    
string dame_lord(string name) { return lords[name]; }

int alquimista(string name,string titulo, object cargo) {
    object pl=find_player(name);
    if(!pl) return 0;
    if(!titulo) return 0;
    if(!cargo) return 0;
    if(!pl->query_creator()||pl->query_alqui()||pl->query_demi()||pl->query_god()) return 0;
    if(!cargo->query_god()) return 0;
    if(cargo!=this_player(1)) return 0;
    alquimistas[name]=titulo;
    tell_object(cargo,"Ok, "+pl->QCN+" asciende a Alquimista.\n");
    tell_object(pl,cargo->QCN+" te ha concedido un ascenso. Sal y entra de nuevo.\n");
    save_object(SAVEOB);
    return 1;
    }
    
string dame_alquimista(string name) { return alquimistas[name]; }

int semidios(string name,string titulo, object cargo) {
    object pl=find_player(name);
    if(!pl) return 0;
    if(!titulo) return 0;
    if(!cargo) return 0;
    if(!pl->query_creator()||pl->query_demi()||pl->query_god()) return 0;
    if(!cargo->query_god()) return 0;
    if(cargo!=this_player(1)) return 0;
    semidioses[name]=titulo;
    tell_object(cargo,"Ok, "+pl->QCN+" asciende a Semidios.\n");
    tell_object(pl,cargo->QCN+" te ha concedido un ascenso. Sal y entra de nuevo.\n");
    save_object(SAVEOB);
    return 1;
    }
    
string dame_semidios(string name) { return semidioses[name]; }

int dios(string name,string titulo, object cargo) {
    object pl=find_player(name);
    if(!pl) return 0;
    if(!titulo) return 0;
    if(!cargo) return 0;
    if(!pl->query_creator()||pl->query_god()) return 0;
    if(!cargo->query_god()) return 0;
    if(cargo!=this_player(1)) return 0;
    dioses[name]=titulo;
    tell_object(cargo,"Ok, "+pl->QCN+" asciende a Dios.\n");
    tell_object(pl,cargo->QCN+" te ha concedido un ascenso. Sal y entra de nuevo.\n");
    save_object(SAVEOB);
    return 1;
    }
    
string dame_dios(string name) { return dioses[name]; }

