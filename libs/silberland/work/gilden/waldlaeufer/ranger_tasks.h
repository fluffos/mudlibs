// defines fuer gildenaufgaben

#ifndef _RANGER_TASKS_H_
#define _RANGER_TASKS_H_

#define RANGER_TASK_SCHUPPE "\nranger_task_schuppe"
#define RANGER_TASK_SCHUPPE2 "\nranger_task_schuppe_identified"
#define RANGER_TASK_WEAPON_GATHER "\nranger_task_gather_weapons"
#define RANGER_TASK_MAGIC_WEAPONS "\nranger_task_gather_magic_items"
#define RANGER_TASK_SCALE_GATHERER "\nranger_task_gather_scales_n_stuff"
#define RANGER_TASK_PALA_KILLER "\nranger_task_palakiller"
#define RANGER_TASK_SCHNITZELJAGD "\nranger_task_schnitzeljagd"
#define RANGER_TASK_COURIER "\nranger_task_courier"

#define RANGER_CHECK_TASK(x, l) (x->QueryProp(P_GUILD) == "waldlaeufer" && x->QueryProp(P_GUILD_LEVEL) >= l-1 && test_bit(call_other("/gilden/waldlaeufer/master/master", "GetTask", getuid(x)), l))
#define RANGER_SET_TASK(x, l) call_other("/gilden/waldlaeufer/master/master", "SetTask", getuid(x), l)

#endif