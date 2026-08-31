 /*island defines */
#define ISLPATH "/players/haplo/island/"
#define INVF first_inventory
#define INVN next_inventory
#define TELL tell_object
#define ENV environment
#define TP this_player()
#define TO this_object()
#define TPN TP->query_name()
#define TPRN TP->query_real_name()
#define QMHP query_max_hp()
#define AA add_action
#define CO clone_object
#define QL query_level()
#define AM add_money
#define AE add_exp
#define QM query_money()
#define RNAME query_real_name()

#define PKPATH "/players/haplo/pk/

 OTHERS(string str, object ob1) {
    object old, new;
    old=INVF(ENV(ob1));
   if (!old) return;
    while (old) {
    new=INVN(old);
    if (living(old) && old!=ob1 = TP) TELL(old,str);
    old=new;
    }
    return;
    }
