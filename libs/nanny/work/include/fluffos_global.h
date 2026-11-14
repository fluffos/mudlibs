#ifndef _FLUFFOS_GLOBAL_H
#define _FLUFFOS_GLOBAL_H

/* FluffOS compatibility shims for LPMud 3.x / NannyMUD */
#ifndef SIMUL_EFUN_FILE
#define creator_of(ob) creator(ob)
#endif

#define mappingp(x) mapp(x)
#define copy_mapping(m) copy(m)
#define _query_ed_setup(x) ((int)(x)->query_ed_setup())
#define _query_ed(x) in_edit(x)
#define status int

void _fluffos_move_to(mixed dest) {
  efun::move_object(dest);
}

int _fluffos_cmd(string cmd) {
  return efun::command(cmd);
}

#endif
