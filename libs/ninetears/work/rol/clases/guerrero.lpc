// Vilat 30.01.2003
// Objeto de clase "Guerrero"

void start_player(object player) {

    // Poner aqui las cosas

    }
    
int query_thac0_step() { return 6; } // Por defecto para guerreros

int query_ac(int nivel) { return -nivel/5; } // 1 punto de AC cada 5 levels

int query_hp_dice(object pl) { return 5; }
int query_hp_min(object pl) { return 7; }
int query_gp_dice(object pl) { return 2; }
int query_gp_min(object pl) { return 4; }
int query_ep_dice(object pl) { return 3; }
int query_ep_min(object pl) { return 5; }
int query_sp_dice(object pl) { return 4; }
int query_sp_min(object pl) { return 6; }

void equipame(object player) {
    clone_object("/baseobs/armas/espada_larga")->move(player);
    clone_object("/baseobs/armaduras/cota")->move(player);
    }