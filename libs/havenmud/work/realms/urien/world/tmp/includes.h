string GetRandomGender() {
  string gender = "female";
  if (random(2)) {
    gender = "male";
  }
  return gender;
}
