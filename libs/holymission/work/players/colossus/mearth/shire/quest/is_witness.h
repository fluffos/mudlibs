/* 060993 Galadriel: is_witness for Colossus */
int is_witness(object ob) {
  return ((ob->id("WITNESS_HOBBIT1")) ||
          (ob->id("WITNESS_HOBBIT2")) ||
          (ob->id("WITNESS_ANOTHER")) ||
          (ob->id("WITNESS_WHATEVER")));
}
