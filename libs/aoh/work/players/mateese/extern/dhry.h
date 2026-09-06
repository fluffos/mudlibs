/*
 * Some global defines.
 */
#define Mic_secs_Per_Second 1000
#define Too_Small_Time      2

#define NUMBER_OF_RUNS 100

#define Ident_1 0
#define Ident_2 1
#define Ident_3 2
#define Ident_4 3
#define Ident_5 4

#define Null 0 

#define true  1
#define false 0

#define Arr_Size 50

/*
 * Simulate C datatypes with LPC datatypes
 */
#define One_Thirty       int
#define One_Fifty        int
#define Capital_Letter   int
#define Boolean          int
#define Enumeration      int
#define char             int

#define Str_30           string
Str_30 alloc_Str_30() {
   return "..............................";
}

#define Arr_1_Dim int *
Arr_1_Dim alloc_Arr_1_Dim() {
   return allocate(Arr_Size);
}

#define Arr_2_Dim mixed *
Arr_2_Dim alloc_Arr_2_Dim() {
   int i;
   mixed *arr;

   arr = allocate(Arr_Size);
   for (i = Arr_Size; i--;)
      arr[i] = allocate(Arr_Size);
   return arr;
}

#define record      mapping
#define Rec_Pointer mapping
Rec_Pointer alloc_record() {
   return ([ "Ptr_Comp" : 0,                           /* record pointer */
	     "Discr"    : 0,                           /* Enumeration */
	     "variant"  :                              /* union */
	     ([ "var_1" :                              /* struct */
		([ "Enum_Comp"  : 0,                   /* Enumeration */
		   "Int_Comp"   : 0,                   /* int */
		   "Str_Comp"   : 0 ]),                /* char[30] */
		"var_2" :                              /* struct */
		([ "E_Comp_2"   : 0,                   /* Enumeration */
		   "Str_2_Comp" : 0 ]),                /* char[30] */
		"var_3" :                              /* struct */
		([ "Ch_1_Comp" : 0,                    /* char */
		   "Ch_2_Comp" : 0 ]) ]) ]);           /* char */
}

#define structassign(a,b) a = copy(b)

int time() {
   int *ru;

   ru = rusage();
   return ru[0] + ru[1];
}

Enumeration Func_1(Capital_Letter Ch_1_Par_Val, Capital_Letter Ch_2_Par_Val);
Boolean Func_2(Str_30 Str_1_Par_Ref, Str_30 Str_2_Par_Ref);
Boolean Func_3(Enumeration Enum_Par_Val);

void Proc_1(Rec_Pointer Ptr_Val_Par);
void Proc_2(One_Fifty Int_Par_Ref);
void Proc_3(Rec_Pointer Ptr_Ref_Par);
void Proc_4();
void Proc_5();
void Proc_6(Enumeration Enum_Val_Par, Enumeration Enum_Ref_Par);
void Proc_7(One_Fifty Int_1_Par_Val,
	    One_Fifty Int_2_Par_Val,
	    One_Fifty Int_Par_Ref);
void Proc_8(Arr_1_Dim Arr_1_Par_Ref, Arr_2_Dim Arr_2_Par_Ref,
	    int Int_1_Par_Val, int Int_2_Par_Val);
