//===========================================================================
//
// Dhrystone-2.1 Benchmark for LPC  (Part II)
//
// Don't take this too serious :-)                               Sven C. Dack
//===========================================================================

inherit "/players/hyp/dhry1";

#define Ident_1    0
#define Ident_2    1
#define Ident_3    2
#define Ident_4    3
#define Ident_5    4

#define Enum_Comp  0
#define Int_Comp   1
#define Str_Comp   2

void Proc_6(int Enum_Val_Par, int Enum_Ref_Par) {
  Enum_Ref_Par = Enum_Val_Par;
  if (!Func_3(Enum_Val_Par))
    Enum_Ref_Par = Ident_4;
  switch (Enum_Val_Par) {
  case Ident_1:
    Enum_Ref_Par = Ident_1;
    break;
  case Ident_2:
    if (Int_Glob > 100)
      Enum_Ref_Par = Ident_1;
    else
      Enum_Ref_Par = Ident_4;
    break;
  case Ident_3:
    Enum_Ref_Par = Ident_2;
    break;
  case Ident_4:
    break;
  case Ident_5:
    Enum_Ref_Par = Ident_3;
    break;
  }
}

void Proc_7(int Int_1_Par_Val, int Int_2_Par_Val, int Int_Par_Ref) {
  int Int_Loc;

  Int_Loc = Int_1_Par_Val + 2;
  Int_Par_Ref = Int_2_Par_Val + Int_Loc;
}

Proc_8 (mixed *Arr_1_Par_Ref, mixed *Arr_2_Par_Ref,
        int Int_1_Par_Val, int Int_2_Par_Val) {
  int Int_Index, Int_Loc;

  Int_Loc = Int_1_Par_Val + 5;
  Arr_1_Par_Ref[Int_Loc]      = Int_2_Par_Val;
  Arr_1_Par_Ref[Int_Loc + 1]  = Arr_1_Par_Ref[Int_Loc];
  Arr_1_Par_Ref[Int_Loc + 30] = Int_Loc;
  for (Int_Index = Int_Loc; Int_Index <= Int_Loc + 1; ++Int_Index)
    Arr_2_Par_Ref[Int_Loc][Int_Index]  = Int_Loc;
  Arr_2_Par_Ref[Int_Loc][Int_Loc - 1] += 1;
  Arr_2_Par_Ref[Int_Loc + 20][Int_Loc] = Arr_1_Par_Ref[Int_Loc];
  Int_Glob = 5;
}

int Func_1(int Ch_1_Par_Val, int Ch_2_Par_Val) {
  int Ch_1_Loc, Ch_2_Loc;

  Ch_1_Loc = Ch_1_Par_Val;
  Ch_2_Loc = Ch_1_Loc;
  if (Ch_2_Loc != Ch_2_Par_Val)
    return Ident_1;
  else {
    Ch_1_Glob = Ch_1_Loc;
    return Ident_2;
  }
}

int Func_2(string Str_1_Par_Ref, string Str_2_Par_Ref) {
  int Int_Loc, Ch_Loc;

  Int_Loc = 2;
  while (Int_Loc <= 2)
    if (Func_1(Str_1_Par_Ref[Int_Loc], Str_2_Par_Ref[Int_Loc + 1]) == Ident_1) {
      Ch_Loc = 'A';
      Int_Loc += 1;
    }
  if (Ch_Loc >= 'W' && Ch_Loc < 'Z')
    Int_Loc = 7;
  if (Ch_Loc == 'R')
    return 1;
  else {
    if (Str_1_Par_Ref > Str_2_Par_Ref) {
      Int_Loc += 7;
      Int_Glob = Int_Loc;
      return 1;
    } else
      return 0;
  }
}

int Func_3(int Enum_Par_Val) {
  int Enum_Loc;

  Enum_Loc = Enum_Par_Val;
  if (Enum_Loc == Ident_3)
    return 1;
  else
    return 0;
}
