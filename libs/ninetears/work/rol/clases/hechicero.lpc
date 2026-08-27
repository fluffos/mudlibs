// Vilat 30.01.2003
// Objeto de clase "Hechicero"

void start_player(object player) {

    // Poner aqui las cosas

    }
    
int query_thac0_step() { return 2; }

int query_ac(int nivel) { return -nivel/12; }

int query_hp_dice(object pl) { return 3; }
int query_hp_min(object pl) { return 5; }
int query_gp_dice(object pl) { return 5; }
int query_gp_min(object pl) { return 7; }
int query_ep_dice(object pl) { return 2; }
int query_ep_min(object pl) { return 4; }
int query_sp_dice(object pl) { return 4; }
int query_sp_min(object pl) { return 6; }

void equipame(object player) {
    clone_object("/baseobs/armas/baston")->move(player);
    clone_object("/baseobs/armaduras/capa")->move(player);
    }