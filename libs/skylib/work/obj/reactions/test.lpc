void junk() {
  string *f;
  f = ({"junk", "base.hdr"});
  f += get_dir("/obj/reactions/*.rcn");
  for (int i=0; i<sizeof(f); i++) {
    f[i] = "/obj/reactions/"+f[i];
  }
  "/handlers/data_TEST"->compile_data(f);
}
