#define SWAP_X_TOP   10

#define SUITLIST     ({ "heart", "diamond", "club", "spade" })
#define RANKLIST     ({ "2", "3", "4", "5", "6", "7", "8", \
                        "9", "10", "J", "Q", "K", "A" })
#define RANKNAMES    ({ "two", "three", "four", "five", "six", \
                        "seven", "eight", "nine", "ten", "jack", \
                        "queen", "king", "ace" })

#define RANK(xxx)    (member_array(xxx, RANKLIST) + 2)
#define SUIT(xxx)    member_array(xxx, SUITLIST)
