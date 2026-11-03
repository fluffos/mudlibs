#ifndef __SEC_MENU_H
#define __SEC_MENU_H

struct menu_item
{
    string    description;
    mixed     action;
    int       disabled;
    mixed     choice_name;        // should be a string if the user sets it.
    int       prompt_after_action;
    function  constraint;
    // A seperator is just a line of text, and not something that
    // can be chosen.  Therefore, action, choice_name, and
    // prompt_after_selection are meaningless if this is non-zero.
    int       seperator;
}

struct menu
{
    // Items should only ever be MENU_ITEM*'s or string*'s, and
    // should be of uniform type.  If this is of type string,
    // The menu won't display options.
    // And if items is a string*, you'd better have a no_match_function,
    // because there won't be any MENU_ITEMS to match against.
    mixed    *items;
    mixed     title;
    mixed     prompt;
    int       allow_enter;
    function  no_match_function;
    int       num_columns;
    int       dont_complete;
    string   *current_choices;
}

#define MENU		struct menu
#define MENU_ITEM	struct menu_item

#endif  // __SEC_MENU_H
