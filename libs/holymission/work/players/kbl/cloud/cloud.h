/* Cloud City Cell Mapping header file */

#define CHACEL "/players/kbl/cloud/rooms/chaos"
#define ALLCEL "/players/kbl/cloud/rooms/cells"

#define CELL "/players/kbl/cloud/cloud_cell"

#define HEAL_OBJ "/players/kbl/cloud/heals"      /* CCC Club */ 
#define SHOP_OBJ "/players/kbl/cloud/shop"       /* CCC Shop */
#define GUAR_OBJ "/players/kbl/cloud/secur"      /* A cell monitor */
#define GUHQ_OBJ "/players/kbl/cloud/guardhq"    /* Guard HQ object */
#define GUCH_OBJ "/players/kbl/cloud/guardch"    /* Chief of Guards */
#define PDEL_OBJ "/players/kbl/cloud/palcel"     /* CC Palace Decell */
#define CDEL_OBJ "/players/kbl/cloud/coucel"     /* CC Court Yard Decell */
#define CCPB_OBJ "/players/kbl/cloud/palbb"      /* Palace Entrance CCBB */
#define CCCY_OBJ "/players/kbl/cloud/coubb"      /* Court Yard Entrance CCBB */

#define CCPB_BRD "/players/kbl/cloud/bb/pal.o"
#define CCCY_BRD "/players/kbl/cloud/bb/cou.o"
#define PALA_ENT "/players/kbl/cloud/pal_ent"
#define COUR_ENT "/players/kbl/cloud/cou_ent"

#define QIMM query_cloud_main_map()
#define QIOL query_cloud_overlay()
#define QCT  query_cell_total()

#define CO(x) clone_object(x)
#define MCO(ob,loc) move_object(clone_object(ob),loc)
#define MO(ob,dest) move_object(ob,dest)

#define RCO(ob) "/players/kbl/cloud/obj_gen"->gen(ob)
#define TDS(n)  "/players/kbl/cloud/tds"->query_descrips()[n]
#define TAC(n)  "/players/kbl/cloud/tac"->query_accden(n)
#define TYP(n)  "/players/kbl/cloud/typ"->query_types(n)
#define CXMAP   "/players/kbl/cloud/clmap"
#define CXMAPM  "/players/kbl/cloud/clmap"->query_cloud_main_map()
#define CXMAPO  "/players/kbl/cloud/clmap"->query_cloud_overlay()

#define ROW_MAX   17
#define CEL_RANGE 1
