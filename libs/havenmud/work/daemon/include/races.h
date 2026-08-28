#ifndef l_races_h
#define l_races_h

class Stat {
  int Class;
  int Average;
}

class Race {
  mixed *Limbs;
  mapping Resistance;
  mapping Stats;
  mapping Fingers;
  int *Sensitivity;
  int Complete;
  int PlayerFlag;
  string Language;
  int Size;
}

int GetArmour(string str);
int GetResistance(string str);

#endif /* l_races_h */
