smell_it(str) {
  if(!nodanger) {
    write("That isn't wise here!\n");
    return 1;
  }
  return ::smell_it(str);
}
