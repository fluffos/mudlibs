private mapping bbs;

void create() {
  seteuid(getuid(this_object()));
  if (!restore_object("/secure/ARCH/bbmaster"))
    bbs=([]);
}

int query_bb() {
  if (object_name(previous_object())[0..11]!="/std/shells/" &&
      !interactive(previous_object()))
    return 0;
  if (!mappingp(bbs))
    return 0;
  return bbs[geteuid(previous_object())];
}

void set_bb(string who, int x) {
  if (!x) bbs=m_delete(bbs, who);
  else bbs[who]=x;
  save_object("/secure/ARCH/bbmaster");
}
