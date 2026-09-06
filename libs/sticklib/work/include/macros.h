#ifndef MACROS_H
#define MACROS_H

/* Useful macros and defines */
#define ENV environment()
#define TP this_player()
#define THIS_OBJ this_object()
#define TOBJ this_object()
#define SOURCE_OB(ob) (explode(object_name(ob)+"#","#")[0])
#define SOURCE SOURCE_OB(this_object())
#define IS_CLONE (object_name(this_object()) != SOURCE)
#define LCALL this_object()->
#define CALL_BY_CLONE (SOURCE == SOURCE_OB(previous_object()))
#define CALL_BY(file) (SOURCE_OB(previous_object()) == file)

#endif
