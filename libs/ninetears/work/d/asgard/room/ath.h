#define ROOMVSAT "/d/asgard/room/valle_sombrio/alrededores_del_templo/"
#define ROOMVSRT "/d/asgard/room/valle_sombrio/ruinas_del_templo/"
#define ROOMVSTA "/d/asgard/room/valle_sombrio/templo_abandonado/"
#define ROOMVSZB "/d/asgard/room/valle_sombrio/zona_basta/"
#define ROOMVSZC "/d/asgard/room/valle_sombrio/zona_clara/"
#define ROOMVSZD "/d/asgard/room/valle_sombrio/zona_densa/"
#define ROOMVSZO "/d/asgard/room/valle_sombrio/zona_oscura/"
#define NPC "/d/asgard/npcs/"
#define BICHOS_HANDLER "/d/asgard/handlers/bichos_handlers.lpc"

void poner_bichos(string zona,object donde,int numero) {
    BICHOS_HANDLER->poner_bichos(zona,donde,numero);
    }