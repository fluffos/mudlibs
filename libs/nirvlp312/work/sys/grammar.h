#ifndef _sys_grammar_h
#define _sys_grammar_h

#define G_OBJECT                    "<object>"
#define G_INDIRECT                  "<indirect>"
#define G_FAKEITEM                  "<fakeitem>"
#define G_LIVING                    "<living>"
#define G_CONTAINER                 "<container>"
#define G_BODYPART                  "<bodypart>"
#define G_ANY_LIVING                "<any_living>"
#define G_ANY_LIVINGS               "<any_livings>"
#define G_AMBIG_LIVINGS             "<ambig_livings>"
#define G_TEXT                      "<text>"
#define G_MONEY                     "<money>"
#define G_ANY_MONEY                 "<any_money>"
#define G_ALL                       "<all>"
#define G_ALL_OBJECT                "<all_object>"
#define G_ALL_INDIRECT              "<all_indirect>"
#define G_OBJECT_LIST               "<object_list>"
#define G_ALL_LIVINGS               "<all_livings>"
#define G_ALL_ITEMS                 "<all_items>"

#define G_IN_INVENTORY              "<in_inventory>"
#define G_IN_ENVIRONMENT            "<in_environment>"
#define G_ALL_IN_INVENTORY          "<all_in_inventory>"
#define G_ALL_IN_ENVIRONMENT        "<all_in_environment>"

#define G_ONLY_IN_INVENTORY         "<only_in_inventory>"
#define G_ONLY_IN_ENVIRONMENT       "<only_in_environment>"
#define G_ALL_ONLY_IN_INVENTORY     "<all_only_in_inventory>"
#define G_ALL_ONLY_IN_ENVIRONMENT   "<all_only_in_environment>"

/* These two are for compatibility reasons */
#define G_ALL_INVENTORY             "<all_inventory>"
#define G_ALL_ENVIRONMENT           "<all_environment>"

#define G_NUMBER                    "<number>"
#define G_ORDINAL                   "<ordinal>"
#define G_RANGE                     "<range>"
#define G_NUMBERS                   "<numbers>"
#define G_ME                        "<me>"
#define G_THIS_ME                   "<this_me>"
#define G_WORDS                     "<words>"
#define G_WORD                      "<word>"
#define G_TIME                      "<time>"
#define G_EXIT                      "<exit>"
#define G_VIEW                      "<view>"
#define G_SIDE                      "<side>"
#define G_TONGUE                    "<tongue>"
#define G_ADVERB                    "<adverb>"
#define G_ADVERBS                   "<adverbs>"
#define G_COLOUR                    "<colour>"
#define G_RACE                      "<race>"

#define G_REMOTE_RESOURCE           "<remote_resource>"
#define G_MUD_NAME                  "<mud_name>"

#define ITEM_ACTION_FAMILY  "item_action"  /* used by add_item_action() */

#endif  /* _sys_grammar_h */
