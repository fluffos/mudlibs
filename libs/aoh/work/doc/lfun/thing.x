LFUN INDEX
  /std/thing.c

PUBLIC 
  -- /std/thing.c --
  void    create ()          (redefined)
  int     clean_up (int ref) (redefined)
  void    init()

  -- /std/thing/description --
  string * AddId (mixed str)
  string * AddClassId (mixed str)
  string * AddAdjective (mixed str)
  string * AddClassAdj (mixed str)

  string * RemoveId (mixed str)
  string * RemoveClassId (mixed str)
  string * RemoveAdjective (mixed str)
  string * RemoveClassAdj (mixed str)

  int      id (string str)
  int      class_id (string str)

  string * filterExtra (string prop)
  string   Long ( [string what] )
  string   ExaLong ( [string what] )
  string   Short ( [string what] )
  string   InvShort ( )
  string   Noise ( [string what] )
  string   Smell ( [string what] )

  int      CompareSize ( int|object with )

  void     SetExtra (mixed name, mixed data)
  mixed    QueryExtra (mixed name)
  void     RemoveExtra (mixed name)
  void     SetExtraEntry (mixed name, mixed prop, mixed data)
  mixed    QueryExtraEntry (mixed name, mixed prop)
  void     RemoveExtraEntry (mixed name, mixed prop)

   -- /std/thing/moving --
  object * AddFollower(object f)
  object * RemoveFollower(object f)
  int      move (string|object dest [, int method [, mixed extra]])
  void     follow (mixed dest, int method, mixed extra) {
  int      clean_up (int ref)


PROTECTED 
  -- /std/thing/description --
  mixed    _add_id (mixed *prop, mixed str)
  mixed    _del_id (mixed *prop, mixed str)
  int      _id (string str, string * ids, string * ads)

  -- /std/thing/restrictions.c --
  void emit_light (int l)


INHERITANCE TREE
  thing
    |-std/base
    |-std/thing/moving
    |-std/thing/properties
    `-std/thing/description
